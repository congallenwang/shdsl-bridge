
#include "lib_sysdep.h"
#include "stm32f10x.h"
#include "drv_api.h"
#include "drv_pef24628e_interface.h"
#include "drv_pef24628e_api.h"
#include "stdio.h"
#include "string.h"
#include "sys_noOSLib.h"

#include "lib_soc4e_map.h"
#include "idc_onlinemessages.h"

#include "pef24628_drv.h"
#include "shdsl_board.h"
#include "finsh.h"

#include "rt_shdsl.h"
#include "configmanage.h"

#define IDC_FW_OFFSET 0x32000
#define IDC_FW_LEN 180308

#define DSL_FW_OFFSET 0x0
#define DSL_FW_LEN 196620

struct rt_pef24628 g_pef24628;
rt_device_t g_pefdrv;

struct rt_mutex g_sh_lock;

struct rt_mailbox g_mb;
static char mb_pool[128];


#define PRINTF rt_kprintf

//int g_test = 100;
BOARD_Configuration_t DeviceConfiguration =
{
   PEF24628E_IF_MPI,
   FALSE,
   4,
   PEF24628E_MAX_DEV_NUMBER,
   PEF24628E_MAX_LINE_NUMBER,   
};

LOCAL UINT8 irq[ PEF24628E_MAX_DEV_NUMBER ];
LOCAL UINT32 base_address[ PEF24628E_MAX_DEV_NUMBER ];
int evt_initializationcomplete[ PEF24628E_MAX_DEV_NUMBER ];

/** if set the SCI monitor is activ */
LOCAL BOOL sci_mon_state = FALSE;

unsigned char g_init_finished=0;

uint8_t g_rcmode = 1;//0 for CO mode;1 for CPE mode
uint8_t g_TCMode=1;//0 for atm mode;1 for EFM mode



unsigned int g_maxbaserate = 0x0056EA00;
unsigned int g_lineProbe = LP_ENABLE;
unsigned int g_configed = 0;
unsigned int g_PAM_Constellation = AUTO_PAM_SELECT;
unsigned int g_duplex=FULL_DUPLEX;
unsigned int g_speed=MII_100BT;

LINE_STATUS g_lineStatus;

//dump flag
unsigned int g_pefdump=0;



extern CONFIG_PARAM g_config;

void rt_CO_init(UINT8 device);
void rt_CPE_init(UINT8 device,UINT8 ch);
void rt_shdsl_apply_config();

VOID rt_sci_monitor_dump(const UINT8 *pData, UINT32 nLength)
{
    UINT32 j;
	
/*    rt_kprintf("\n\r");*/
/*    rt_kprintf("Offset  Data \n\r");*/
/*    rt_kprintf("======  ================================================= \n\r");*/
    for ( j = 0; j < nLength; j++ ) 
    {
        if ( j > 15 && j % 16 == 0 ) 
        {
            rt_kprintf("\n\r");
        } 
        else 
            if ( j > 7 && j % 8 == 0 ) 
            {
                rt_kprintf(": ");
            }
        if (j % 16 == 0) 
        {
            rt_kprintf("0x%04X  ", j);
        }
        rt_kprintf("%02X ", *pData++ );
    }
    rt_kprintf("\n\r");

}


BOOL rt_pef24628_poll( UINT8 device, UINT16 idc_msg_id_expected )
{
   UINT8 pBuf[PEF24628E_MSG_SIZE];
   UINT16 nBytes, m_id, idc_msg_id, len = 0;
   SDFE4_MessageHeader_t *pSDFE4_Header = (SDFE4_MessageHeader_t *)(pBuf + sizeof(IDC_MessageHeader_t));
   SDFE4_t *pSDFE4_Data = (SDFE4_t *)(pBuf + sizeof(IDC_MessageHeader_t) + sizeof(SDFE4_MessageHeader_t));  
   
   UINT32 retries = 100;
   UINT8 line = PEF24628E_MAX_LINES_PER_DEVICE * device;
   struct EVT_PMD_LinkState* p_Evt_pmd_linkstate;
   struct EVT_EOC_LinkState* p_Evt_eoc_linkstate;
   struct EVT_EOC_Message* p_Evt_eoc_Message;
   struct EOC_ReceiveMsg* p_Eoc_receivemsg;
   struct EVT_PMD_MPairStatus* p_Evt_pmd_mpairstatus;
   struct EVT_PMD_DelayCompState* p_Evt_pmd_delaycompstate;
   struct EVT_PMD_MultiWireMapping* p_Evt_pmd_multiwiremapping;
   struct ACK_Mdio_RegisterRead* p_ack_mdio_registerread;
   ACK_PMD_StatusGet_t* p_ack_pmd_status;
   ACK_PMD_PM_ParamGet_t* p_ack_pmd_pm_parameget;


   struct rt_msg* p_msg;
   
   if(g_pefdrv <= 0)
      return FALSE;
  
   while (--retries)
   {
      WAIT(5000);
      //if( ioctl( fd[ device ], FIO_PEF24628E_POLL_CHECK, 0 ) == 0)
      if( rt_device_control(g_pefdrv, FIO_PEF24628E_POLL_CHECK, 0 ) == 0)
      {
         //rt_kprintf("nothing polled\r\n");
         if(idc_msg_id_expected == 0)
         {
            /* ony serving notifications, not waiting for special message */
            return TRUE;         
         }      
         break;
      }

	  //rt_kprintf("try read\r\n");   	
      //nBytes = read( fd[ device ], (INT8*) &pBuf[0], PEF24628E_MSG_SIZE );
	  nBytes = rt_device_read(g_pefdrv,0,pBuf,PEF24628E_MSG_SIZE);
      /* check for minimum size */
      if ( nBytes < 3 ) 
      {
         PRINTF("SOC4E[%02d]: IDC: Message length failed %d\n\r", device, nBytes);
         /*return FALSE;*/
         break;
      }

      if ( pBuf[ nBytes - 1 ] == 0xA1 ) 
	  {
         PRINTF("SOC4E[%02d]: SCI MONITOR: Message length = %d\n\r", device, nBytes );
         rt_sci_monitor_dump( (UINT8 *)&pBuf[0], nBytes);
         continue;
      } 
	  else if ( pBuf[ nBytes - 1 ] == 0xA0 ) 
	  {
         PRINTF("SOC4E[%02d]: ORDINAL MESSAGE: Message length = %d\n\r", device, nBytes );
      } 
	  else if ( sci_mon_state == TRUE ) 
	  {
         PRINTF("SOC4E[%02d]: err: Message length = %d\n\r", device, nBytes );
         rt_sci_monitor_dump( (UINT8 *)&pBuf[0], nBytes);
      }

      idc_msg_id = ((pBuf[0] >> 5) & 0x07) | (pBuf[1] << 3);
      m_id = (pSDFE4_Header->header[1] << 8) | pSDFE4_Header->header[0];
      if(len > (sizeof(IDC_MessageHeader_t) + sizeof(SDFE4_MessageHeader_t) + 1))
         len = nBytes - 1 - sizeof(IDC_MessageHeader_t) - sizeof(SDFE4_MessageHeader_t); 
   
      /* ignore device address */
      switch ( idc_msg_id ) 
	  {      
         case NFC_TNL_PMD_0_MESSAGE:
            PRINTF("SOC4E[%02d]: NFC_TNL_PMD_0_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 0, m_id, pSDFE4_Data, len);
            break;
              
         case ACK_TNL_PMD_0_MESSAGE:
            PRINTF("SOC4E[%02d]: ACK_TNL_PMD_0_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 0, m_id, pSDFE4_Data, len);
            break;

         case NFC_TNL_PMD_1_MESSAGE:
            PRINTF("SOC4E[%02d]: NFC_TNL_PMD_1_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 1, m_id, pSDFE4_Data, len);
            break;

         case ACK_TNL_PMD_1_MESSAGE:
            PRINTF("SOC4E[%02d]: ACK_TNL_PMD_1_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 1, m_id, pSDFE4_Data, len);
            break;

         case NFC_TNL_PMD_2_MESSAGE:
            PRINTF("SOC4E[%02d]: NFC_TNL_PMD_2_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 2, m_id, pSDFE4_Data, len);
            break;

         case ACK_TNL_PMD_2_MESSAGE:
            PRINTF("SOC4E[%02d]: ACK_TNL_PMD_2_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 2, m_id, pSDFE4_Data, len);
            break;

         case NFC_TNL_PMD_3_MESSAGE:
            PRINTF("SOC4E[%02d]: NFC_TNL_PMD_3_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 3, m_id, pSDFE4_Data, len);
            break;

         case ACK_TNL_PMD_3_MESSAGE:
            PRINTF("SOC4E[%02d]: ACK_TNL_PMD_3_MESSAGE\n\r", device);
            //soc4e_decode_upstream( line + 3, m_id, pSDFE4_Data, len);
            break;

         case EVT_INITIALIZATIONCOMPLETE:
            PRINTF("SOC4E[%02d]: EVT_INITIALIZATIONCOMPLETE\n\r", device);
            evt_initializationcomplete[device] = 1;
            break;
         
         case ACK_MDIO_REGISTERMULTIPLEREAD:
            PRINTF("SOC4E[%02d]: ACK_MDIO_REGISTERMULTIPLEREAD\n\r", device);
            break;

         case ACK_INVENTORYREQUEST:
            PRINTF("SOC4E[%02d]: ACK_INVENTORYREQUEST\n\r", device);
            break;
/*
	  case ACK_MDIO_REGISTERREAD:
		PRINTF("SOC4E[%02d]: ACK_MDIO_REGISTERREAD\n\r", device);
		p_ack_mdio_registerread = (struct ACK_Mdio_RegisterRead*)(pBuf+4);
		g_ack_mdio_registerread.RegValue= p_ack_mdio_registerread->RegValue;
		PRINTF("SOC4E[%02d]: RegValue=0x%x\n\r", device,
							 			         g_ack_mdio_registerread.RegValue);	

		break;
*/	  	
	  case EVT_PMD_LINKSTATE:
	  	PRINTF("SOC4E[%02d]: EVT_PMD_LINKSTATE(%x)\n\r", device,EVT_PMD_LINKSTATE);
		p_Evt_pmd_linkstate = (struct EVT_PMD_LinkState*)(pBuf+4);
		PRINTF("SOC4E[%02d]: LinkNo=0x%x,State=0x%x,Condition=0x%x,Reason=0x%x\n\r", device,
																				     p_Evt_pmd_linkstate->LinkNo,	
																				     p_Evt_pmd_linkstate->State,
																				     p_Evt_pmd_linkstate->Condition,
																				     p_Evt_pmd_linkstate->Reason);
		if(g_init_finished)
		{
			p_msg = (struct rt_msg*)rt_malloc(sizeof(struct rt_msg));			
			if(p_msg != RT_NULL)
			{
				p_msg->msg_id = EVT_PMD_LINKSTATE;
				p_msg->linkno = p_Evt_pmd_linkstate->LinkNo;
				p_msg->state = p_Evt_pmd_linkstate->State;
				rt_mb_send(&g_mb,(rt_uint32_t)p_msg);
			}
			
		}
		break;

	  case ACK_PMD_STATUSGET:
	  	PRINTF("SOC4E[%02d]: ACK_PMD_STATUSGET(%x)\n\r", device,ACK_PMD_STATUSGET);
		p_ack_pmd_status = (ACK_PMD_StatusGet_t*)(pBuf+4);
		PRINTF("SOC4E[%02d]: LinkNo=0x%x,datarate=0x%x(%d)\n\r", device,p_ack_pmd_status->LinkNo,
																	p_ack_pmd_status->DataRate,
																	p_ack_pmd_status->DataRate);
              if(g_init_finished)
		{
			p_msg = (struct rt_msg*)rt_malloc(sizeof(struct rt_msg));			
			if(p_msg != RT_NULL)
			{
				p_msg->msg_id = ACK_PMD_STATUSGET;
				p_msg->linkno = p_ack_pmd_status->LinkNo;
				p_msg->datarate = p_ack_pmd_status->DataRate;
				rt_mb_send(&g_mb,(rt_uint32_t)p_msg);
			}			
		}
		break;

	  case ACK_PMD_PM_PARAMGET:
			PRINTF("SOC4E[%02d]: ACK_PMD_PM_PARAMGET(%x)\n\r", device,ACK_PMD_PM_PARAMGET);			
			p_ack_pmd_pm_parameget = (ACK_PMD_PM_ParamGet_t*)(pBuf+4);
			PRINTF("SOC4E[%02d]: LinkNo=0x%x,Unit_ID=0x%x,Status_CS=0x%x, Status_NS=0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n\r",
																	device,p_ack_pmd_pm_parameget->LinkNo,
																	p_ack_pmd_pm_parameget->Unit_ID,
																	p_ack_pmd_pm_parameget->Status_CS,
																	p_ack_pmd_pm_parameget->Status_NS,
																	p_ack_pmd_pm_parameget->Counter_0,
																	p_ack_pmd_pm_parameget->Counter_1,
																	p_ack_pmd_pm_parameget->Counter_2,
																	p_ack_pmd_pm_parameget->Counter_3,
																	p_ack_pmd_pm_parameget->Counter_4,
																	p_ack_pmd_pm_parameget->Counter_5,
																	p_ack_pmd_pm_parameget->Counter_6,
																	p_ack_pmd_pm_parameget->Counter_7);
																	
			PRINTF("SOC4E[%02d]:0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n\r",
										device,p_ack_pmd_pm_parameget->Counter_8,
										p_ack_pmd_pm_parameget->Counter_9,
										p_ack_pmd_pm_parameget->Counter_10,
										p_ack_pmd_pm_parameget->Counter_11,
										p_ack_pmd_pm_parameget->Counter_12,
										p_ack_pmd_pm_parameget->Counter_13,
										p_ack_pmd_pm_parameget->Counter_14,
										p_ack_pmd_pm_parameget->Counter_15,
										p_ack_pmd_pm_parameget->Counter_16,
										p_ack_pmd_pm_parameget->Counter_17);
                     if(g_init_finished)
        		{
        			p_msg = (struct rt_msg*)rt_malloc(sizeof(struct rt_msg));			
        			if(p_msg != RT_NULL)
        			{
        				p_msg->msg_id = ACK_PMD_PM_PARAMGET;
        				p_msg->linkno = p_ack_pmd_pm_parameget->LinkNo;
        				p_msg->snr_c= p_ack_pmd_pm_parameget->Counter_2;
                                   p_msg->snr_n = p_ack_pmd_pm_parameget->Counter_10;
        				rt_mb_send(&g_mb,(rt_uint32_t)p_msg);
        			}			
        		}
              break;

	  case EVT_EOC_LINKSTATE:
		PRINTF("SOC4E[%02d]: EVT_EOC_LINKSTATE(%x)\n\r", device,EVT_EOC_LINKSTATE);
		p_Evt_eoc_linkstate = (struct EVT_EOC_LinkState*)(pBuf+4);
		PRINTF("SOC4E[%02d]: LinkNo=0x%x,State=0x%x\n\r", device,p_Evt_eoc_linkstate->LinkNo,
																p_Evt_eoc_linkstate->State);
                if(g_init_finished)
                {
                    p_msg = (struct rt_msg*)rt_malloc(sizeof(struct rt_msg));			
                    if(p_msg != RT_NULL)
                    {
                        p_msg->msg_id = EVT_EOC_LINKSTATE;
                        p_msg->state= p_Evt_eoc_linkstate->State;
                        p_msg->linkno = p_Evt_eoc_linkstate->LinkNo;
                        rt_mb_send(&g_mb,(rt_uint32_t)p_msg);
                    }			
                }  
		break;

	case EVT_EOC_MESSAGE:
		PRINTF("SOC4E[%02d]: EVT_EOC_MESSAGE(%x)\n\r", device,EVT_EOC_MESSAGE);
		p_Evt_eoc_Message = (struct EVT_EOC_Message*)(pBuf+4) ;
		p_Eoc_receivemsg =(struct EOC_ReceiveMsg*)(p_Evt_eoc_Message->EocMessage);
		PRINTF("SOC4E[%02d]: LinkNo=0x%x,SrcDst=0x%x,Length=0x%x,fail=0x%x,rme=0x%x,Octet_4=0x%x,Octet_3=0x%x,Octet_2=0x%x,EOC_Id=0x%x\n\r", device,p_Evt_eoc_Message->LinkNo,
																						p_Eoc_receivemsg->SrcDst,
																						p_Eoc_receivemsg->Length,
																						p_Eoc_receivemsg->fail,
																						p_Eoc_receivemsg->rme,
																						p_Eoc_receivemsg->Octet_4,
																						p_Eoc_receivemsg->Octet_3,
																						p_Eoc_receivemsg->Octet_2,
																						p_Eoc_receivemsg->EOC_Id);
		break;

	case EVT_PMD_MPAIRSTATUS:		
		PRINTF("SOC4E[%02d]: EVT_PMD_MPAIRSTATUS(%x)\n\r", device,EVT_PMD_MPAIRSTATUS);
		p_Evt_pmd_mpairstatus = (struct EVT_PMD_MPairStatus*)(pBuf+4);
		PRINTF("SOC4E[%02d]: LinkNo=0x%x,State=0x%x\n\r", device,p_Evt_pmd_mpairstatus->LinkNo,
																						p_Evt_pmd_mpairstatus->State);
		break;
		
	case EVT_PMD_DELAYCOMPSTATE:		 
		PRINTF("SOC4E[%02d]: EVT_PMD_DELAYCOMPSTATE(%x)\n\r", device,EVT_PMD_DELAYCOMPSTATE);
		p_Evt_pmd_delaycompstate = (struct EVT_PMD_DelayCompState*)(pBuf+4);
		PRINTF("SOC4E[%02d]: MpairLinkNo=0x%x,Link_0_Delay=0x%x,Link_1_Delay=0x%x,Link_2_Delay=0x%x,Link_3_Delay=0x%x\n\r", device,p_Evt_pmd_delaycompstate->MpairLinkNo,
																						p_Evt_pmd_delaycompstate->Link_0_Delay,
																						p_Evt_pmd_delaycompstate->Link_1_Delay,
																						p_Evt_pmd_delaycompstate->Link_2_Delay,
																						p_Evt_pmd_delaycompstate->Link_3_Delay);
		break;

	case EVT_PMD_MULTIWIREMAPPING:
		PRINTF("SOC4E[%02d]: EVT_PMD_MULTIWIREMAPPING(%x)\n\r", device,EVT_PMD_MULTIWIREMAPPING);
		p_Evt_pmd_multiwiremapping = (struct EVT_PMD_MultiWireMapping*)(pBuf+4);
		PRINTF("SOC4E[%02d]: LinkNo=0x%x,Master_Prev=0x%x,Master_Crnt=0x%x,Slave_1=0x%x,Slave_2=0x%x,Slave_3=0x%x,InterleaveMaster=0x%x,InterleaveSlave1=0x%x,InterleaveSlave2=0x%x,InterleaveSlave3=0x%x\n\r", device,p_Evt_pmd_multiwiremapping->LinkNo,
															     p_Evt_pmd_multiwiremapping->Master_Prev,
															     p_Evt_pmd_multiwiremapping->Master_Crnt,
															     p_Evt_pmd_multiwiremapping->Slave_1,
															     p_Evt_pmd_multiwiremapping->Slave_2,
															     p_Evt_pmd_multiwiremapping->Slave_3,
															     p_Evt_pmd_multiwiremapping->InterleaveMaster,
															     p_Evt_pmd_multiwiremapping->InterleaveSlave1,
															     p_Evt_pmd_multiwiremapping->InterleaveSlave2,
															     p_Evt_pmd_multiwiremapping->InterleaveSlave3);
		break;

		
         default :
            PRINTF( "SOC4E[%02d]: received message id: %x, src:%02X, dest:%02X, len %04X bytes\n\r"
                  , device, idc_msg_id, pBuf[0], pBuf[1], nBytes );
			//allen
			//rt_sci_monitor_dump( (UINT8 *)&pBuf[0], nBytes);

            break;
      }
      
      if(idc_msg_id == (idc_msg_id_expected | 0x200))
      {
         return TRUE;         
      }

      if(idc_msg_id_expected == 0)
      {
         /* ony serving notifications, not waiting for special message */
         return TRUE;         
      }
   }
   
   PRINTF("SOC4E[%02d]: poll timeout: idc_msg_id_expected %04x\n\r", device, idc_msg_id_expected);
      
   return FALSE;
}

BOOL rt_pef24638_send_idc_msg(UINT8 device, UINT16 msg_id, VOID const * pSrc, UINT16 nLength)
{
   UINT8 msg[sizeof(SDFE4_t) + 4];
   UINT16 tc_id=0xFFFF;
   INT32 nBytes;
   
   if(g_pefdrv< 0)
   {
      PRINTF("SOC4E[%02d]: device not present\n\r", device);
      return FALSE;
   }
   
   /* prepare IDC header */
   
   /* the length should less or equal to 30 words */
   if ( nLength > 120 ) 
   {
      PRINTF("SOC4E[%02d]: IDC: invalid length: %d\n\r", device, nLength);
      return FALSE;
   }
   
   if(nLength & 0x0003)
   {
      PRINTF("SOC4E[%02d]: IDC: non aligned length: %d\n\r", device, nLength);
      return FALSE;
   }   
   
   *(msg + 0) =  ((nLength)/4) & 0x1F;  /* 0..4 Payload Length in 32bit words*/
   *(msg + 0) |= (msg_id & 0x07)<<5;    /* 5..15 MSGID */
   *(msg + 1) =  (msg_id >> 3) & 0xFF;
   *(msg + 2) =  tc_id & 0xFF;          /* 16..26 TCID */
   *(msg + 3) =  (tc_id>>8) & 0x07;
   *(msg + 3) |= (0x00 & 0x0F) << 3;    /* RC, usually 0 */    

   /* message params must be already in little endian, no conversion !!! */
   if(pSrc && nLength)
      memcpy(&msg[4], pSrc, nLength);

   nLength += 4; 
   /* write() should be used */
   //nBytes = write( fd[ device ], (INT8 *) &msg[0], nLength);
   nBytes = rt_device_write(g_pefdrv,0,msg,nLength);
   if ( nBytes != nLength )
   {
      PRINTF("SOC4E[%02d]: write of nBytes %d bytes failed, %d bytes written\n\r", 
               device, nLength + 4, nBytes);
      return FALSE;
   }
   
   if (rt_pef24628_poll(device, msg_id) == TRUE) 
   {
      return TRUE;
   }

   /* message not acknowledged */
   return FALSE;
} 


BOOL rt_shdsl_poll( UINT8 device, UINT16 idc_msg_id_expected )
{
	rt_err_t result;
	BOOL ret;
	
	result = rt_mutex_take(&g_sh_lock, RT_WAITING_FOREVER);
	if(result != RT_EOK)
	{
	    return 0;
	}
	
	ret=rt_pef24628_poll(device,idc_msg_id_expected);

	/* release lock */
	rt_mutex_release(&g_sh_lock);

	return ret;
}

BOOL rt_shdsl_send_idc_msg(UINT8 device, UINT16 msg_id, VOID const * pSrc, UINT16 nLength)
{
	rt_err_t result;
	BOOL ret;
	
	result = rt_mutex_take(&g_sh_lock, RT_WAITING_FOREVER);
	if(result != RT_EOK)
	{
	    return 0;
	}
	
	ret=rt_pef24638_send_idc_msg(device,msg_id,pSrc,nLength);

	/* release lock */
	rt_mutex_release(&g_sh_lock);

	return ret;
}


long rt_set_loopback(unsigned int mode)
{
    struct CMD_SystemInterfaceLoopControl cmd_loopcontrol;

    cmd_loopcontrol.LinkNo = 0;
    cmd_loopcontrol.LoopMode = mode;

    if (rt_shdsl_send_idc_msg(0, CMD_SYSTEMINTERFACELOOPCONTROL, &cmd_loopcontrol, sizeof(cmd_loopcontrol)) == FALSE)
    {
    		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("cmd_loopcontrol() failed ...reset \n\r"));
    }
    else
    	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SYSTEMINTERFACELOOPCONTROL send ok******************** \n\r\r\n"));

    return;
}
FINSH_FUNCTION_EXPORT(rt_set_loopback, shdsl set loopback);

long rt_shdsl_cmd(unsigned int cmd)
{
	rt_err_t result;
	BOOL ret;
	CMD_PMD_StatusGet_t cmd_pmd_statusget;
	CMD_PMD_PM_ParamGet_t cmd_pmd_pm_parameterget;
	struct CMD_LinkControl cmd_linkcontrol;
	struct CMD_PMD_Control cmd_pmd_control;
	struct CMD_PMD_Reset cmd_pmd_reset;

#if 0	
	result = rt_mutex_take(&g_sh_lock, RT_WAITING_FOREVER);
	if(result != RT_EOK)
	{
	    return 0;
	}
#endif
	switch(cmd)
	{	
		//check data rate
		case 1:		
			cmd_pmd_statusget.LinkNo = 0;
			if (rt_shdsl_send_idc_msg(0, CMD_PMD_STATUSGET, &cmd_pmd_statusget, sizeof(cmd_pmd_statusget)) == FALSE)
		      {
		      		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
			}
			else
			 	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_STATUSGET send ok******************** \n\r\r\n"));
		break;

		//check snr margin
		case 2:
			cmd_pmd_pm_parameterget.LinkNo = 0;
			if(g_rcmode)
				cmd_pmd_pm_parameterget.Unit_ID = STU_R_UNIT;
			else
				cmd_pmd_pm_parameterget.Unit_ID = STU_C_UNIT;	
			if (rt_shdsl_send_idc_msg(0, CMD_PMD_PM_PARAMGET, &cmd_pmd_pm_parameterget, sizeof(cmd_pmd_pm_parameterget)) == FALSE)
		      {
		      		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
			}
			else
			 	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_PM_PARAMGET send ok******************** \n\r\r\n"));
		break;

		//reinit in co side
		case 3:
			if(g_rcmode == 0)
				rt_CO_init(0);
			else
				rt_CPE_init(0,0);
            

		default:
			break;
	}
#if 0
	/* release lock */
	rt_mutex_release(&g_sh_lock);
#endif
	return 0;
}
FINSH_FUNCTION_EXPORT(rt_shdsl_cmd, shdsl cli);

long rt_set_baserate(unsigned int rate)
{
	g_maxbaserate = rate;
		rt_kprintf("g_maxbaserate set to %d\r\n",g_maxbaserate);

	return 0;
}
FINSH_FUNCTION_EXPORT(rt_set_baserate, shdsl set baserate);


long rt_set_lp(unsigned int value)
{
	g_lineProbe = value;
		rt_kprintf("g_lineProbe set to %d\r\n",g_lineProbe);

	return 0;
}
FINSH_FUNCTION_EXPORT(rt_set_lp, shdsl set lineprobe);

long rt_set_pam(unsigned int value)
{
	g_PAM_Constellation = value;
		rt_kprintf("g_lineProbe set to %d\r\n",g_PAM_Constellation);

	return 0;
}
FINSH_FUNCTION_EXPORT(rt_set_pam, shdsl set pam);


long rt_set_dump(unsigned int value)
{
	g_pefdump = value;
		rt_kprintf("g_lineProbe set to %d\r\n",g_pefdump);

	return 0;
}
FINSH_FUNCTION_EXPORT(rt_set_dump, shdsl set pef driver dump);


long rt_set_mii(unsigned int duplex,unsigned int speed)
{
	g_duplex= duplex;
       g_speed=speed;
	rt_kprintf("g_duplex %d, g_speed %d\r\n",g_duplex,g_speed);

	return 0;
}
FINSH_FUNCTION_EXPORT(rt_set_mii, shdsl set pef driver mii config);

long rt_get_config(void)
{
	rt_kprintf("g_rcmode : %d\r\n",g_rcmode);
	rt_kprintf("g_TCMode : %d\r\n",g_TCMode);
	rt_kprintf("g_lineProbe : %d\r\n",g_lineProbe);
	rt_kprintf("g_maxbaserate : %d\r\n",g_maxbaserate);
	rt_kprintf("g_configed : %d\r\n",g_configed);
       rt_kprintf("g_pefdump : %d\r\n",g_pefdump);     
       rt_kprintf("g_PAM_Constellation : %d\r\n",g_PAM_Constellation);   
       rt_kprintf("g_duplex %d, g_speed %d\r\n",g_duplex,g_speed);
	return 0;
}
FINSH_FUNCTION_EXPORT(rt_get_config, shdsl get config);

void rt_shdsl_register()
{
	rt_kprintf("register pef driver\r\n");
	
	memset ( ( char * ) &(g_pef24628.data), 0, sizeof ( PEF24628E_DEV_t ) );

	//basic config
	g_pef24628.data.uc_index = 0;
	g_pef24628.data.SciRxState = SCI_RX_IDLE;

	pef24628_drv_init(&g_pef24628,"sh0");

	/* initialize mutex lock */
	if(RT_EOK!=rt_mutex_init(&g_sh_lock, "shm", RT_IPC_FLAG_PRIO))
	{
		rt_kprintf("sh mutex init failed\r\n");
	}

	/* init mailbox */
	rt_mb_init(&g_mb,"shm",mb_pool,128/4,RT_IPC_FLAG_FIFO);

}
void rt_CO_ATM_init(UINT8 device)
{
       unsigned char ret;

    	struct CMD_ATM_TC_LinkModify cmd_atm_tc_linkmodify;
      	struct CMD_SegmentationReassemblyConfig cmd_segmentationreassemblyconfig;
	struct CMD_Segmentation_VCC_Config cmd_segmentation_vcc_config;
	struct CMD_SegmentationClassFilterConfig cmd_segmentationclassfilterconfig;
	struct CMD_ReassemblyClassFilterConfig cmd_reassemblyclassfilterconfig; 

       cmd_atm_tc_linkmodify.LinkNo = 0x00000000;					//only confiugre the master channel.
	cmd_atm_tc_linkmodify.IMA_Mode = 0x00000000;
	cmd_atm_tc_linkmodify.RX_HEC_Ow = 0x00000000;
	cmd_atm_tc_linkmodify.RX_HEC_Byte = 0x00000000;
	cmd_atm_tc_linkmodify.CellDelinMode = 0x00000000;
	cmd_atm_tc_linkmodify.CRD_AtmHdr = 0x00000001;
	cmd_atm_tc_linkmodify.CRD_AtmPL = 0x0000006A;
	cmd_atm_tc_linkmodify.RX_Alpha = 0x00000006;
	cmd_atm_tc_linkmodify.RX_Delta = 0x00000007;
	cmd_atm_tc_linkmodify.RX_descrambling = 0x00000001;
	cmd_atm_tc_linkmodify.TX_scrambling = 0x00000001;

	cmd_atm_tc_linkmodify.LI_M_PairPorts = 0x00000000;		   //here configure the bonding group, or in case single pair then = 0.
#if 0
	if(g_button & 0x4)
		cmd_atm_tc_linkmodify.LI_M_PairPorts = 0x00000100;		   //here configure the bonding group, or in case single pair then = 0.
	if(g_button & 0x8)
		cmd_atm_tc_linkmodify.LI_M_PairPorts = 0x00020100;		   //here configure the bonding group, or in case single pair then = 0.
	if(g_button & 0x10)
		cmd_atm_tc_linkmodify.LI_M_PairPorts = 0x03020100;		   //here configure the bonding group, or in case single pair then = 0.	
#endif
	//rt_kprintf("**********************CMD_ATM_TC_LINKMODIFY********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_ATM_TC_LINKMODIFY, &cmd_atm_tc_linkmodify, sizeof(cmd_atm_tc_linkmodify)) == FALSE)
	{
		ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
		//TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_ATM_TC_LINKMODIFY send ok******************** \n\r\r\n"));
	//WAIT(5000);
	cmd_segmentationreassemblyconfig.LinkNo = 0x00000000; 
	cmd_segmentationreassemblyconfig.CPCS_Protocol = 0x00000001; 
	cmd_segmentationreassemblyconfig.FCS_Present = 0x00000000; 
	cmd_segmentationreassemblyconfig.SegClassFilter = 0x00000000; 
	cmd_segmentationreassemblyconfig.SegDefAction = 0x00000001; 
	cmd_segmentationreassemblyconfig.SegDef_VPI = 0x00000000; 
	cmd_segmentationreassemblyconfig.SegDef_VCI = 0x00000020; 
	cmd_segmentationreassemblyconfig.ReaAddDefClassFilter = 0x00000000; 
	cmd_segmentationreassemblyconfig.CustomFilterOffset = 0x00000000; 
	cmd_segmentationreassemblyconfig.CustomFilterMask_1 = 0x00000000; 
	cmd_segmentationreassemblyconfig.CustomFilterMask_2 = 0x00000000; 
	//rt_kprintf("**********************CMD_SEGMENTATIONREASSEMBLYCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_SEGMENTATIONREASSEMBLYCONFIG, &cmd_segmentationreassemblyconfig, sizeof(cmd_segmentationreassemblyconfig)) == FALSE)
	{
		ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
		//TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SEGMENTATIONREASSEMBLYCONFIG send ok******************** \n\r\r\n"));
	//WAIT(5000);
	

	cmd_segmentation_vcc_config.LinkNo = 0x00000000; 
	cmd_segmentation_vcc_config.VCC_id = 0x00000000; 
	cmd_segmentation_vcc_config.VPI = 0x00000000; 
	cmd_segmentation_vcc_config.VCI = 0x00000020; 
	//rt_kprintf("**********************CMD_SEGMENTATION_VCC_CONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_SEGMENTATION_VCC_CONFIG, &cmd_segmentation_vcc_config, sizeof(cmd_segmentation_vcc_config)) == FALSE)
	{
		ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
		//TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SEGMENTATION_VCC_CONFIG send ok******************** \n\r\r\n"));
	//WAIT(5000);

	cmd_segmentationclassfilterconfig.LinkNo = 0x00000000; 
	cmd_segmentationclassfilterconfig.MAC_Address_1 = 0x00000000; 
	cmd_segmentationclassfilterconfig.MAC_Address_2 = 0x00000001; 
	cmd_segmentationclassfilterconfig.VLAN_id = 0x00000000; 
	cmd_segmentationclassfilterconfig.VLAN_prio = 0x00000000; 
	cmd_segmentationclassfilterconfig.VCC_id = 0x00000000; 
	cmd_segmentationclassfilterconfig.CustomFilter_1 = 0x00000000; 
	cmd_segmentationclassfilterconfig.CustomFilter_2 = 0x00000000; 
	//rt_kprintf("**********************CMD_SEGMENTATIONCLASSFILTERCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_SEGMENTATIONCLASSFILTERCONFIG, &cmd_segmentationclassfilterconfig, sizeof(cmd_segmentationclassfilterconfig)) == FALSE)
	{
	       ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SEGMENTATIONCLASSFILTERCONFIG send ok******************** \n\r\r\n"));
	//WAIT(5000);


	cmd_reassemblyclassfilterconfig.LinkNo = 0x00000000; 
	cmd_reassemblyclassfilterconfig.VPI = 0x00000000; 
	cmd_reassemblyclassfilterconfig.VCI = 0x00000020; 
	//rt_kprintf("**********************CMD_REASSEMBLYCLASSFILTERCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_REASSEMBLYCLASSFILTERCONFIG, &cmd_reassemblyclassfilterconfig, sizeof(cmd_reassemblyclassfilterconfig)) == FALSE)
	{
	       ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_REASSEMBLYCLASSFILTERCONFIG send ok******************** \n\r\r\n"));
	//WAIT(5000);

    //AAL5 config finished
}


void rt_CO_init(UINT8 device)
{
	struct CMD_TC_FlowModify cmd_tc_flowmodify;
	struct CMD_PMD_Reset cmd_pmd_reset;

	struct CMD_PMD_SpanProfileGroupConfig cmd_pmd_spanprofilegroupconfig;
	struct CMD_IOP_Mode cmd_iop_mode;
	struct CMD_PMD_SM_Control cmd_pmd_sm_control;
	struct CMD_PMD_AlarmControl cmd_pmd_alarmcontrol;	
	struct CMD_EOC_StatusRequestControl cmd_eoc_statusrequestcontrol;
	struct CMD_LinkControl cmd_linkcontrol;
	struct CMD_PMD_Control cmd_pmd_control;
	struct CMD_EOC_Control cmd_eoc_control;
	struct CMD_PMD_EndpointAlarmConfig cmd_pmd_endpointalarmconfig;
	struct CMD_PMD_StatusGet cmd_pmd_statusget;
	struct CMD_PMD_PM_ParamGet cmd_pmd_pm_paramget;
	struct CMD_PMD_CO_PortSubTypeSelect cmd_pmd_co_portsubtypeselect;

	struct CMD_xMII_Modify cmd_xmiimodify;
	struct CMD_StatusPinsConfig cmd_statuspinconfig;
	unsigned char ret = 0;
	g_configed = 0;
       g_init_finished=0;
	
       rt_kprintf("call CO_init\r\n");

	//config LED
	cmd_statuspinconfig.Mode=STU_C_UNIT;
	rt_kprintf("**********************CMD_STATUSPINSCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_STATUSPINSCONFIG, &cmd_statuspinconfig, sizeof(cmd_statuspinconfig)) == FALSE)
    {
    	ret = 1;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	 	//TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_STATUSPINSCONFIG send ok******************** \n\r\r\n"));
    //WAIT(5000);
	
	//=================================================
	//Configure xMII interface, only need do one time after fw download. CMD_xMII_Modify.
	cmd_xmiimodify.LinkNo = 0x0;   
	cmd_xmiimodify.Speed = 0x01;//MII_100BT
	cmd_xmiimodify.Duplex = 0x01;//FULL_DUPLEX
	cmd_xmiimodify.SMII_SyncMode = 0x0;//NORMAL
	cmd_xmiimodify.AltCollision = 0x1;//enable
	cmd_xmiimodify.RxDuringTx = 0x1;//enable
	cmd_xmiimodify.CollisionType = 0x0;//COL_TYPE
	cmd_xmiimodify.DiBitMode = 0x0;//DIBIT_POS_1
	rt_kprintf("**********************CMD_XMII_MODIFY********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_XMII_MODIFY, &cmd_xmiimodify, sizeof(cmd_xmiimodify)) == FALSE)
    {
    	ret = 1;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	 	//TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_XMII_MODIFY send ok******************** \n\r\r\n"));
    //WAIT(5000);

       if(g_TCMode ==0)
       {
		cmd_tc_flowmodify.Link0_TC = 0x03; //only configure the target channel(or channels in bonding group) to ATM TC, other channels left to be SAME_TC_LAYER.
		cmd_tc_flowmodify.Link1_TC = 0x03;
		cmd_tc_flowmodify.Link2_TC = 0x03;
		cmd_tc_flowmodify.Link3_TC = 0x03;

	}
	else
	{
		cmd_tc_flowmodify.Link0_TC = 0x01; //ÿefm mode
		cmd_tc_flowmodify.Link1_TC = 0x01;
		cmd_tc_flowmodify.Link2_TC = 0x01;
		cmd_tc_flowmodify.Link3_TC = 0x01;

	}
	//cmd_tc_flowmodify.Link2_TC = 0x07;
	//cmd_tc_flowmodify.Link3_TC = 0x07;

	rt_kprintf("**********************CMD_TC_FlowModify********************\r\n");
     if (rt_shdsl_send_idc_msg(device, CMD_TC_FLOWMODIFY, &cmd_tc_flowmodify, sizeof(cmd_tc_flowmodify)) == FALSE)
    {
    	ret = 1;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
    }
	//else
	 // 	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_TC_FlowModify  send ok******************** \n\r\r\n"));
    //WAIT(5000);

	
	cmd_pmd_reset.LinkNo = 0x00000000;      //do this to all channels in a bonding group. Now all the channels are not bonded.	
	rt_kprintf("**********************CMD_PMD_RESET********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_RESET, &cmd_pmd_reset, sizeof(cmd_pmd_reset)) == FALSE)
    {
    	ret = 1;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	  	//TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_RESET send ok******************** \n\r\r\n"));
    //WAIT(5000);

      if(g_TCMode ==0)
      {
            rt_CO_ATM_init(device);	
      }

	cmd_pmd_co_portsubtypeselect.LinkNo = 0x00000000;		//only do this to master channel	
	rt_kprintf("**********************CMD_PMD_CO_PORTSUBTYPESELECT********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_CO_PORTSUBTYPESELECT, &cmd_pmd_co_portsubtypeselect, sizeof(cmd_pmd_co_portsubtypeselect)) == FALSE)
	{
	       ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_CO_PORTSUBTYPESELECT send ok******************** \n\r\r\n"));
	//WAIT(5000);
	
	cmd_pmd_spanprofilegroupconfig.LinkNo = 0x00000000; 					//only do this to master channel
	cmd_pmd_spanprofilegroupconfig.WireInterface = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.MinLineRate = 0x0002EE00;
	cmd_pmd_spanprofilegroupconfig.MaxLineRate = g_maxbaserate;
	cmd_pmd_spanprofilegroupconfig.MinLineSubRate = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.MaxLineSubRate = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.PSD = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.TransMode = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.RemoteEnabled = 0x00000001;
	cmd_pmd_spanprofilegroupconfig.PowerFeeding = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.CC_TargetMarginDown = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.WC_TargetMarginDown = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.CC_TargetMarginUp = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.WC_TargetMarginUp = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.UsedTargetMargins = 0x00000005;
	cmd_pmd_spanprofilegroupconfig.RefClock = 0x00000004;
	//disable line probe
	cmd_pmd_spanprofilegroupconfig.LineProbe = g_lineProbe;
	//cmd_pmd_spanprofilegroupconfig.LineProbe = 0x00000002;
	cmd_pmd_spanprofilegroupconfig.PAM_Constellation = g_PAM_Constellation;
	cmd_pmd_spanprofilegroupconfig.CapListStyle = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.PBO_Mode = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.EPL_Mode = 0x00000008;
	cmd_pmd_spanprofilegroupconfig.PBO_Value = 0x00000000;
       cmd_pmd_spanprofilegroupconfig.PBO_Offset = 0x00000000;
       cmd_pmd_spanprofilegroupconfig.MaxBaudRate = 0x00000000;
    	rt_kprintf("**********************CMD_PMD_SPANPROFILEGROUPCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_SPANPROFILEGROUPCONFIG, &cmd_pmd_spanprofilegroupconfig, sizeof(cmd_pmd_spanprofilegroupconfig)) == FALSE)
	{
	ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_SPANPROFILEGROUPCONFIG send ok******************** \n\r\r\n"));
	//WAIT(5000);
	//rt_kprintf("CMD_PMD_SpanProfileGroupConfig\n");	

 
	cmd_iop_mode.LinkNo = 0x00000000;					//send to all channels in a bonding group
	cmd_iop_mode.pmms_iop_mode = 0x00000001;
	cmd_iop_mode.vendor_spec_octets = 0x35300100;
	cmd_iop_mode.PHY_IOP_Mode = 0x00000000;
	cmd_iop_mode.PHY_Res_1 = 0x00000000;
	cmd_iop_mode.IDC_IOP_Mode = 0x00000000;
	cmd_iop_mode.IDC_Res_1 = 0x00000000;    
	rt_kprintf("**********************CMD_IOP_MODE********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_IOP_MODE, &cmd_iop_mode, sizeof(cmd_iop_mode)) == FALSE)
	{
	ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_IOP_MODE send ok******************** \n\r\r\n"));
	//WAIT(5000);

	
	cmd_pmd_sm_control.LinkNo = 0x00000000; 			   //send to master channel
	cmd_pmd_sm_control.Control = 0x00000001;
	cmd_pmd_sm_control.NFC_Forwarding = 0x00000000;
	cmd_pmd_sm_control.ForceTraining = 0x00000001;
    	rt_kprintf("**********************CMD_PMD_SM_CONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_SM_CONTROL, &cmd_pmd_sm_control, sizeof(cmd_pmd_sm_control)) == FALSE)
	{
	ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_SM_CONTROL send ok******************** \n\r\r\n"));
	//WAIT(5000);

	
	cmd_pmd_alarmcontrol.LinkNo = 0x00000000;			  //send to all channels in a bonding group
	cmd_pmd_alarmcontrol.Mask = 0x000000FE;
   	rt_kprintf("**********************CMD_PMD_ALARMCONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_ALARMCONTROL, &cmd_pmd_alarmcontrol, sizeof(cmd_pmd_alarmcontrol)) == FALSE)
	{
	ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_ALARMCONTROL send ok******************** \n\r\r\n"));
	//WAIT(5000);

	
	cmd_eoc_statusrequestcontrol.LinkNo = 0x00000000;					//send to all channels in a bonding group
	cmd_eoc_statusrequestcontrol.StatusPeriod = 0x00000014;
	cmd_eoc_statusrequestcontrol.ATM_StatusPeriod = 0x00000064;
    	rt_kprintf("**********************CMD_EOC_STATUSREQUESTCONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_EOC_STATUSREQUESTCONTROL, &cmd_eoc_statusrequestcontrol, sizeof(cmd_eoc_statusrequestcontrol)) == FALSE)
	{
	ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_EOC_STATUSREQUESTCONTROL send ok******************** \n\r\r\n"));
	//WAIT(5000);


	
	cmd_linkcontrol.LinkNo = 0x00000000;					   //send to only master channel
	cmd_linkcontrol.TX_Mode = 0x00000001;
	cmd_linkcontrol.RX_Mode = 0x00000001;
   	rt_kprintf("**********************CMD_LINKCONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_LINKCONTROL, &cmd_linkcontrol, sizeof(cmd_linkcontrol)) == FALSE)
	{
	ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_LINKCONTROL send ok******************** \n\r\r\n"));
	//WAIT(5000);

	
	cmd_pmd_control.LinkNo = 0x00000000;			  //only do this to master channel
	cmd_pmd_control.LinkControl = 0x00000001;
	cmd_pmd_control.ActivationState = START_AFTER_INIT;
	rt_kprintf("**********************CMD_PMD_CONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_CONTROL, &cmd_pmd_control, sizeof(cmd_pmd_control)) == FALSE)
	{
		ret = 1;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_CONTROL send ok******************** \n\r\r\n"));
	//WAIT(5000);


       //init line status
       g_lineStatus.linkStatus = NOT_READY;
       g_lineStatus.dateRate = 0;
       g_lineStatus.snr_c = 0;
       g_lineStatus.snr_n = 0;
       
       g_init_finished=1; 

       g_configed = 1-ret;
	if(g_configed)
		rt_kprintf("CO config success\r\n");
	return;
}

void rt_CPE_init(UINT8 device,UINT8 ch)
{
	struct CMD_TC_FlowModify cmd_tc_flowmodify;
	struct CMD_PMD_Reset cmd_pmd_reset;
	struct CMD_ATM_TC_LinkModify cmd_atm_tc_linkmodify;
	struct CMD_PMD_SpanProfileGroupConfig cmd_pmd_spanprofilegroupconfig;
	struct CMD_IOP_Mode cmd_iop_mode;
	struct CMD_PMD_SM_Control cmd_pmd_sm_control;
	struct CMD_PMD_AlarmControl cmd_pmd_alarmcontrol;	
	struct CMD_EOC_StatusRequestControl cmd_eoc_statusrequestcontrol;
	struct CMD_LinkControl cmd_linkcontrol;
	struct CMD_PMD_Control cmd_pmd_control;
	struct CMD_EOC_Control cmd_eoc_control;
	struct CMD_PMD_EndpointAlarmConfig cmd_pmd_endpointalarmconfig;
	struct CMD_PMD_StatusGet cmd_pmd_statusget;
	struct CMD_PMD_PM_ParamGet cmd_pmd_pm_paramget;
	struct CMD_SegmentationReassemblyConfig cmd_segmentationreassemblyconfig;
	struct CMD_Segmentation_VCC_Config cmd_segmentation_vcc_config;
	struct CMD_SegmentationClassFilterConfig cmd_segmentationclassfilterconfig;
	struct CMD_ReassemblyClassFilterConfig cmd_reassemblyclassfilterconfig;
	struct CMD_xMII_Modify cmd_xmiimodify;
	struct CMD_StatusPinsConfig cmd_statuspinconfig;
	unsigned ret=0;
	g_configed = 1;

    g_init_finished=0;
	
       rt_kprintf("call CPE_init\r\n");

	//config LED
	cmd_statuspinconfig.Mode=STU_R_UNIT;
	//rt_kprintf("**********************CMD_STATUSPINSCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_STATUSPINSCONFIG, &cmd_statuspinconfig, sizeof(cmd_statuspinconfig)) == FALSE)
      {
      	g_configed = 0;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	// 	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_STATUSPINSCONFIG send ok******************** \n\r\r\n"));
      //WAIT(1);

	//=================================================
	//Configure xMII interface, only need do one time after fw download. CMD_xMII_Modify.
	cmd_xmiimodify.LinkNo = ch;   
	cmd_xmiimodify.Speed = g_speed;//MII_100BT
	cmd_xmiimodify.Duplex = g_duplex;//FULL_DUPLEX
	cmd_xmiimodify.SMII_SyncMode = 0x0;//NORMAL
	cmd_xmiimodify.AltCollision = 0x1;//enable
	cmd_xmiimodify.RxDuringTx = 0x1;//enable
	cmd_xmiimodify.CollisionType = 0x0;//COL_TYPE
	cmd_xmiimodify.DiBitMode = 0x0;//DIBIT_POS_1
	//rt_kprintf("**********************CMD_XMII_MODIFY********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_XMII_MODIFY, &cmd_xmiimodify, sizeof(cmd_xmiimodify)) == FALSE)
    {g_configed = 0;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	 //	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_XMII_MODIFY send ok******************** \n\r\r\n"));
       //WAIT(1);

	 if(g_TCMode ==0)
       {
		cmd_tc_flowmodify.Link0_TC = 0x03; //only configure the target channel(or channels in bonding group) to ATM TC, other channels left to be SAME_TC_LAYER.
		cmd_tc_flowmodify.Link1_TC = 0x03;
		cmd_tc_flowmodify.Link2_TC = 0x03;
		cmd_tc_flowmodify.Link3_TC = 0x03;
       }
	else
	{
		cmd_tc_flowmodify.Link0_TC = 0x01; //ÿefm mode
		cmd_tc_flowmodify.Link1_TC = 0x01;
		cmd_tc_flowmodify.Link2_TC = 0x01;
		cmd_tc_flowmodify.Link3_TC = 0x01;
	}


	//rt_kprintf("**********************CMD_TC_FlowModify********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_TC_FLOWMODIFY, &cmd_tc_flowmodify, sizeof(cmd_tc_flowmodify)) == FALSE)
    {g_configed = 0;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//  	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_TC_FlowModify  send ok******************** \n\r\r\n"));
    //WAIT(1);

	
	cmd_pmd_reset.LinkNo = ch;      //do this to all channels in a bonding group. Now all the channels are not bonded.	
	//rt_kprintf("**********************CMD_PMD_RESET********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_RESET, &cmd_pmd_reset, sizeof(cmd_pmd_reset)) == FALSE)
    {g_configed = 0;
      	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//  	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_RESET send ok******************** \n\r\r\n"));
    //WAIT(1);

 if(g_TCMode ==0)
       {    
	cmd_atm_tc_linkmodify.LinkNo = ch;					//only confiugre the master channel.
	cmd_atm_tc_linkmodify.IMA_Mode = 0x00000000;
	cmd_atm_tc_linkmodify.RX_HEC_Ow = 0x00000000;
	cmd_atm_tc_linkmodify.RX_HEC_Byte = 0x00000000;
	cmd_atm_tc_linkmodify.CellDelinMode = 0x00000000;
	cmd_atm_tc_linkmodify.CRD_AtmHdr = 0x00000001;
	cmd_atm_tc_linkmodify.CRD_AtmPL = 0x0000006A;
	cmd_atm_tc_linkmodify.RX_Alpha = 0x00000006;
	cmd_atm_tc_linkmodify.RX_Delta = 0x00000007;
	cmd_atm_tc_linkmodify.RX_descrambling = 0x00000001;
	cmd_atm_tc_linkmodify.TX_scrambling = 0x00000001;
	cmd_atm_tc_linkmodify.LI_M_PairPorts = 0x03020100;		   //here configure the bonding group, or in case single pair then = 0.
	//rt_kprintf("**********************CMD_ATM_TC_LINKMODIFY********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_ATM_TC_LINKMODIFY, &cmd_atm_tc_linkmodify, sizeof(cmd_atm_tc_linkmodify)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_ATM_TC_LINKMODIFY send ok******************** \n\r\r\n"));
	//WAIT(1);
 	}

    /* FIX ME
    	Configure SAR/AAL5 here,
	CMD_SegmentationReassemblyConfig
	CMD_Segmentation_VCC_Config
	CMD_SegmentationClassFilterConfig
	CMD_ReassemblyClassFilterConfig
       */
      if(g_TCMode ==0)
      {
	// SAR AAL5 configuration , interworking EFM <---> Utopia
	cmd_segmentationreassemblyconfig.LinkNo = ch; 
	cmd_segmentationreassemblyconfig.CPCS_Protocol = 0x00000001; 
	cmd_segmentationreassemblyconfig.FCS_Present = 0x00000000; 
	cmd_segmentationreassemblyconfig.SegClassFilter = 0x00000000; 
	cmd_segmentationreassemblyconfig.SegDefAction = 0x00000001; 
	cmd_segmentationreassemblyconfig.SegDef_VPI = 0x00000000; 
	cmd_segmentationreassemblyconfig.SegDef_VCI = 0x00000020; 
	cmd_segmentationreassemblyconfig.ReaAddDefClassFilter = 0x00000000; 
	cmd_segmentationreassemblyconfig.CustomFilterOffset = 0x00000000; 
	cmd_segmentationreassemblyconfig.CustomFilterMask_1 = 0x00000000; 
	cmd_segmentationreassemblyconfig.CustomFilterMask_2 = 0x00000000; 
	//rt_kprintf("**********************CMD_SEGMENTATIONREASSEMBLYCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_SEGMENTATIONREASSEMBLYCONFIG, &cmd_segmentationreassemblyconfig, sizeof(cmd_segmentationreassemblyconfig)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SEGMENTATIONREASSEMBLYCONFIG send ok******************** \n\r\r\n"));
	//WAIT(1);
	

	cmd_segmentation_vcc_config.LinkNo = ch; 
	cmd_segmentation_vcc_config.VCC_id = 0x00000000; 
	cmd_segmentation_vcc_config.VPI = 0x00000000; 
	cmd_segmentation_vcc_config.VCI = 0x00000020; 
	//rt_kprintf("**********************CMD_SEGMENTATION_VCC_CONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_SEGMENTATION_VCC_CONFIG, &cmd_segmentation_vcc_config, sizeof(cmd_segmentation_vcc_config)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SEGMENTATION_VCC_CONFIG send ok******************** \n\r\r\n"));
	//WAIT(1);
	 

	cmd_segmentationclassfilterconfig.LinkNo = ch; 
	cmd_segmentationclassfilterconfig.MAC_Address_1 = 0x00000000; 
	cmd_segmentationclassfilterconfig.MAC_Address_2 = 0x00000001; 
	cmd_segmentationclassfilterconfig.VLAN_id = 0x00000000; 
	cmd_segmentationclassfilterconfig.VLAN_prio = 0x00000000; 
	cmd_segmentationclassfilterconfig.VCC_id = 0x00000000; 
	cmd_segmentationclassfilterconfig.CustomFilter_1 = 0x00000000; 
	cmd_segmentationclassfilterconfig.CustomFilter_2 = 0x00000000; 
	//rt_kprintf("**********************CMD_SEGMENTATIONCLASSFILTERCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_SEGMENTATIONCLASSFILTERCONFIG, &cmd_segmentationclassfilterconfig, sizeof(cmd_segmentationclassfilterconfig)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_SEGMENTATIONCLASSFILTERCONFIG send ok******************** \n\r\r\n"));
	//WAIT(1);


	cmd_reassemblyclassfilterconfig.LinkNo = ch; 
	cmd_reassemblyclassfilterconfig.VPI = 0x00000000; 
	cmd_reassemblyclassfilterconfig.VCI = 0x00000020; 
	//rt_kprintf("**********************CMD_REASSEMBLYCLASSFILTERCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_REASSEMBLYCLASSFILTERCONFIG, &cmd_reassemblyclassfilterconfig, sizeof(cmd_reassemblyclassfilterconfig)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_REASSEMBLYCLASSFILTERCONFIG send ok******************** \n\r\r\n"));
	//WAIT(1);

    //AAL5 config finished
      	}
	cmd_pmd_spanprofilegroupconfig.LinkNo = ch; 					//only do this to master channel
	cmd_pmd_spanprofilegroupconfig.WireInterface = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.MinLineRate = 0x0002EE00;
	cmd_pmd_spanprofilegroupconfig.MaxLineRate = g_maxbaserate;
	cmd_pmd_spanprofilegroupconfig.MinLineSubRate = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.MaxLineSubRate = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.PSD = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.TransMode = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.RemoteEnabled = 0x00000001;
	cmd_pmd_spanprofilegroupconfig.PowerFeeding = 0x00000000;
#if 1
	cmd_pmd_spanprofilegroupconfig.CC_TargetMarginDown = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.WC_TargetMarginDown = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.CC_TargetMarginUp = 0x00000006;
	cmd_pmd_spanprofilegroupconfig.WC_TargetMarginUp = 0x00000006;
       cmd_pmd_spanprofilegroupconfig.UsedTargetMargins = 0x00000005;
#else
       cmd_pmd_spanprofilegroupconfig.CC_TargetMarginDown = 0x00000001;
	cmd_pmd_spanprofilegroupconfig.WC_TargetMarginDown = 0x00000001;
	cmd_pmd_spanprofilegroupconfig.CC_TargetMarginUp = 0x00000001;
	cmd_pmd_spanprofilegroupconfig.WC_TargetMarginUp = 0x00000001;
       cmd_pmd_spanprofilegroupconfig.UsedTargetMargins = 0x00000000;
#endif
	cmd_pmd_spanprofilegroupconfig.RefClock = 0x00000004;
	//disable line probe
	//cmd_pmd_spanprofilegroupconfig.LineProbe = 0x00000002;
	cmd_pmd_spanprofilegroupconfig.LineProbe = g_lineProbe;
	cmd_pmd_spanprofilegroupconfig.PAM_Constellation = g_PAM_Constellation;
	cmd_pmd_spanprofilegroupconfig.CapListStyle = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.PBO_Mode = 0x00000000;
	cmd_pmd_spanprofilegroupconfig.EPL_Mode = 0x00000008;
	cmd_pmd_spanprofilegroupconfig.PBO_Value = 0x00000000;
       cmd_pmd_spanprofilegroupconfig.PBO_Offset = 0x00000000;
       cmd_pmd_spanprofilegroupconfig.MaxBaudRate = 0x00000000;
    //rt_kprintf("**********************CMD_PMD_SPANPROFILEGROUPCONFIG********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_SPANPROFILEGROUPCONFIG, &cmd_pmd_spanprofilegroupconfig, sizeof(cmd_pmd_spanprofilegroupconfig)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_SPANPROFILEGROUPCONFIG send ok******************** \n\r\r\n"));
	//WAIT(1);
	//rt_kprintf("CMD_PMD_SpanProfileGroupConfig\n");
	

 
	cmd_iop_mode.LinkNo = ch;					//send to all channels in a bonding group
	cmd_iop_mode.pmms_iop_mode = 0x00000001;
	cmd_iop_mode.vendor_spec_octets = 0x35300100;
	cmd_iop_mode.PHY_IOP_Mode = 0x00000000;
	cmd_iop_mode.PHY_Res_1 = 0x00000000;
	cmd_iop_mode.IDC_IOP_Mode = 0x00000000;
	cmd_iop_mode.IDC_Res_1 = 0x00000000;    
	//rt_kprintf("**********************CMD_IOP_MODE********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_IOP_MODE, &cmd_iop_mode, sizeof(cmd_iop_mode)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_IOP_MODE send ok******************** \n\r\r\n"));
	//WAIT(1);

	
	cmd_pmd_sm_control.LinkNo = ch; 			   //send to master channel
	cmd_pmd_sm_control.Control = 0x00000001;
	cmd_pmd_sm_control.NFC_Forwarding = 0x00000000;
	cmd_pmd_sm_control.ForceTraining = 0x00000000;
    //rt_kprintf("**********************CMD_PMD_SM_CONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_SM_CONTROL, &cmd_pmd_sm_control, sizeof(cmd_pmd_sm_control)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_SM_CONTROL send ok******************** \n\r\r\n"));
	//WAIT(1);

	
	
	cmd_eoc_control.LinkNo = ch;		//only send to master channel
	cmd_eoc_control.Control = 0x00000001;
	cmd_eoc_control.Mode = 0x00000000;
	cmd_eoc_control.PerfStatusMode = 0x00000000;
	cmd_eoc_control.ForcePerfStatusMarker = 0x00000000;
	//rt_kprintf("**********************CMD_EOC_CONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_EOC_CONTROL, &cmd_eoc_control, sizeof(cmd_eoc_control)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_EOC_CONTROL send ok******************** \n\r\r\n"));
	//WAIT(1);


	cmd_linkcontrol.LinkNo = ch;			   //only send to master channel
	cmd_linkcontrol.TX_Mode = 0x00000001;
	cmd_linkcontrol.RX_Mode = 0x00000001;	
	//rt_kprintf("**********************CMD_LINKCONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_LINKCONTROL, &cmd_linkcontrol, sizeof(cmd_linkcontrol)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_LINKCONTROL send ok******************** \n\r\r\n"));
	//WAIT(1);

    cmd_pmd_control.LinkNo = ch;				 //only send to master channel
	cmd_pmd_control.LinkControl = 0x00000000;  //cpe set to 0(linkdown)
	cmd_pmd_control.ActivationState = START_AFTER_INIT;
	//rt_kprintf("**********************CMD_PMD_CONTROL********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_CONTROL, &cmd_pmd_control, sizeof(cmd_pmd_control)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_CONTROL send ok******************** \n\r\r\n"));
	//WAIT(1);
	

	//===================================================================
	//Use these 2 message to get PMD status and performance data.
	cmd_pmd_statusget.LinkNo = ch;		 //only to master channel is OK. because slave channels will be same with master channel.
	//rt_kprintf("**********************CMD_PMD_STATUSGET********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_STATUSGET, &cmd_pmd_statusget, sizeof(cmd_pmd_statusget)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_STATUSGET send ok******************** \n\r\r\n"));
	//WAIT(1);



	cmd_pmd_pm_paramget.LinkNo = ch;			  //send to all channels in a bonding group. And need read CO and CPE performance data for every channel. If need to manage SRUs, also need request SRU performance data. But for SRU, after link up, need disovery SRUs on the span, please check in G.991.2 how to do it.
	cmd_pmd_pm_paramget.Unit_ID = 0x00000002;
	//rt_kprintf("**********************CMD_PMD_PM_PARAMGET********************\r\n");
	if (rt_shdsl_send_idc_msg(device, CMD_PMD_PM_PARAMGET, &cmd_pmd_pm_paramget, sizeof(cmd_pmd_pm_paramget)) == FALSE)
	{g_configed = 0;
		TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("rt_shdsl_send_idc_msg() failed ...reset \n\r"));
	}
	//else
	//	TRACE(PEF24624_LIB,DBG_LEVEL_HIGH,("*********************CMD_PMD_PM_PARAMGET send ok******************** \n\r\r\n"));
	//WAIT(1);

       //init line status
       g_lineStatus.linkStatus = NOT_READY;
       g_lineStatus.dateRate = 0;
       g_lineStatus.snr_c = 0;
       g_lineStatus.snr_n = 0;

        g_init_finished=1;
    
	if(g_configed)
		rt_kprintf("CPE config success\r\n");

EXIT:
	return;
}


rt_err_t rt_shdsl_init()
{
	unsigned char device;
	PEF24628E_DEV_INIT_t    init;  
	PEF24628E_IF_t nInterfaceMode = (PEF24628E_IF_t)DeviceConfiguration.nInterfaceMode;
	PEF24628E_DOWNLOAD_FW_t idc_fw;
       PEF24628E_DOWNLOAD_FW_t sdfe4_fw;
	int i;

	device = 0;

      nInterfaceMode = DeviceConfiguration.nInterfaceMode = PEF24628E_IF_MPI;
      DeviceConfiguration.nSciClock = 4;
      DeviceConfiguration.bPollingMode=FALSE;
      DeviceConfiguration.nMaxDevNumber=PEF24628E_MAX_DEV_NUMBER;
      DeviceConfiguration.nMaxLineNumber=PEF24628E_MAX_LINE_NUMBER,   
  
/*
	rt_kprintf("try init shdsl device %d,%d,%d,%d,%d\r\n",DeviceConfiguration.nInterfaceMode,DeviceConfiguration.nSciClock,
                                                                         DeviceConfiguration.bPollingMode,
                                                                         DeviceConfiguration.nMaxDevNumber,
                                                                         DeviceConfiguration.nMaxLineNumber);
*/
	g_pefdrv = rt_device_find("sh0");

	if(g_pefdrv == RT_NULL)
	{
		PRINTF("SOC4E[%02d]: find device failed\n\r", 0);	
		return RT_ERROR;
	}

	if (rt_device_open(g_pefdrv, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
	{
		PRINTF("SOC4E[%02d]: open device failed\n\r", 0);	
		return RT_ERROR;
	}

/******************************basic bus config********************************************/
	PRINTF("SOC4E[%02d]: Select interface %d\n\r", device, nInterfaceMode);
	/* Select interface */
	if( rt_device_control(g_pefdrv, FIO_PEF24628E_SET_IF, (void*)nInterfaceMode ) )
	{
		 PRINTF("SOC4E[%02d]: Interface selection has failed\n\r", device);
		 return RT_ERROR;
	}

	init.irq_vector = 0;    
	init.reg_offset = 0;
	init.sci_clock = DeviceConfiguration.nSciClock;

	if (nInterfaceMode == PEF24628E_IF_MPI) 
	{

		if(!DeviceConfiguration.bPollingMode)
		{
			init.irq_vector = irq[ device ];
		}  

		//allen
		base_address[ device ] = 0x60000000;		 
		init.reg_offset = base_address[ device ];
	}

	PRINTF("SOC4E[%02d]: Init device driver, base 0x%x, irq %d\n\r", 
	   device, init.reg_offset, init.irq_vector);

	if( rt_device_control(g_pefdrv, FIO_PEF24628E_DEV_INIT, (void*)&init ) )
	{
		PRINTF("SOC4E[%02d]: Device init failed\n\r", device);
		return RT_ERROR;
	}

/***********************************Firmware download******************************************************/
	rt_kprintf("try load firmware\r\n");
	{
		sdfe4_fw.core = PEF24628E_DSL;	
		sdfe4_fw.pFwImage = (UINT8 HUGE *)(DSL_FW_OFFSET);
		sdfe4_fw.size_byte = DSL_FW_LEN;
		PRINTF("SOC4E: DSL firmware download from flash: %d bytes, flash address 0x%08x\n\r", 
												  sdfe4_fw.size_byte, 
												  (UINT8 HUGE *)(sdfe4_fw.pFwImage));
	}
	{
		/* Load firmware */   
		idc_fw.core = PEF24628E_IDC;
		idc_fw.pFwImage = (UINT8 HUGE *)(IDC_FW_OFFSET);
		idc_fw.size_byte = IDC_FW_LEN;

		PRINTF("SOC4E: IDC firmware download from flash: %d bytes, flash address 0x%08x\n\r", 
													  idc_fw.size_byte, idc_fw.pFwImage);
	}													   

	if ( rt_device_control( g_pefdrv, FIO_PEF24628E_DOWNLOAD_FW, (void*)&sdfe4_fw ) )
	{
		PRINTF("SOC4E[%02d]: DSL download failed\n\r", device);
		return RT_ERROR;
	}

	if ( rt_device_control(g_pefdrv, FIO_PEF24628E_DOWNLOAD_FW, (void*)&idc_fw ) )
	{
		PRINTF("SOC4E[%02d]: IDC download failed\n\r", device);
		return RT_ERROR;
	}

/*******************************check for firmware ok message**********************************************************/
    WAIT(30);
	rt_kprintf("**********1***********************wait for firmware bring up**************************\r\n");

	for(i=0;i<50;i++)
	{
		for (device=0; device<DeviceConfiguration.nMaxDevNumber; device++)
		{
			rt_shdsl_poll(device, 0);
		}
		for (device=0; device<DeviceConfiguration.nMaxDevNumber; device++)
		{
			if(evt_initializationcomplete[device] == 0)
			{
				break;
			}
		}
		if(device == DeviceConfiguration.nMaxDevNumber)
		{
		   break;
		}

		WAIT(10);      
	}		  

	//g_init_finished = 1;
       rt_kprintf("i=%d\r\n",i);
	if(i<50)
		return RT_EOK;
	else
		return RT_ERROR;
}

//polling thread
void rt_shp_thread_entry(void* parameter)
{
	unsigned char device=0;

	PRINTF("SOC4E[%02d]: try get inventory information\n\r", device);   	

       rt_shdsl_send_idc_msg(device, CMD_INVENTORYREQUEST, NULL, 0);
   	
	while(1)
	{
		for (device=0; device<DeviceConfiguration.nMaxDevNumber; device++)
		{
			rt_shdsl_poll(device, 0);
		}		
		rt_thread_sleep(50);	
		//delay(10);
	}

	//never reach here
	rt_kprintf("quit shp thread\r\n");
}

rt_timer_t gt;
struct rt_msg gmsg;

void rt_sendmb(unsigned int id)
{
        gmsg.msg_id = id;
        rt_mb_send(&g_mb,(rt_uint32_t)&gmsg);
}

void rt_checkSNR()
{

#if 1
        CMD_PMD_PM_ParamGet_t cmd_pmd_pm_parameterget;
        cmd_pmd_pm_parameterget.LinkNo = 0;
        if(g_rcmode)
            cmd_pmd_pm_parameterget.Unit_ID = STU_R_UNIT;
        else
            cmd_pmd_pm_parameterget.Unit_ID = STU_C_UNIT;	
        rt_shdsl_send_idc_msg(0, CMD_PMD_PM_PARAMGET, &cmd_pmd_pm_parameterget, sizeof(cmd_pmd_pm_parameterget));
#else
        rt_kprintf("rt_checksnr\r\n");
        gmsg.msg_id = 100;
        rt_mb_send(&g_mb,(rt_uint32_t)&gmsg);
#endif
 }

uint32_t ETH_WritePHYRegister(uint16_t PHYAddress, uint16_t PHYReg, uint16_t PHYValue);
void rt_msgdispatch(struct rt_msg* pmsg)
{
    CMD_PMD_StatusGet_t cmd_pmd_statusget;
    CMD_PMD_PM_ParamGet_t cmd_pmd_pm_parameterget;
    
    if(NULL == pmsg)
        return;

    switch(pmsg->msg_id)
    {
        //reinit
        case 100:    
#if 0            
            cmd_pmd_pm_parameterget.LinkNo = 0;
            if(g_rcmode)
                cmd_pmd_pm_parameterget.Unit_ID = STU_R_UNIT;
            else
                cmd_pmd_pm_parameterget.Unit_ID = STU_C_UNIT;	
            rt_shdsl_send_idc_msg(0, CMD_PMD_PM_PARAMGET, &cmd_pmd_pm_parameterget, sizeof(cmd_pmd_pm_parameterget));
            rt_timer_delete(gt);
#else
   	     rt_thread_sleep(500);
            rt_shdsl_apply_config();
#endif
            break;

        case EVT_PMD_LINKSTATE:
            rt_kprintf("Event: id:0x%x,linkno:%d,state:%d\r\n",pmsg->msg_id,pmsg->linkno,pmsg->state);
            //reach link status, check link speed
#if 0
            if(UP_DATA_MODE==pmsg->state)
            {
              	cmd_pmd_statusget.LinkNo = 0;
			rt_shdsl_send_idc_msg(0, CMD_PMD_STATUSGET, &cmd_pmd_statusget, sizeof(cmd_pmd_statusget));
            }                    
            else
            {
                //update line status   
                g_lineStatus.dateRate= 0;
                g_lineStatus.linkStatus = 0;
                g_lineStatus.snr_c = 0;
                g_lineStatus.snr_n = 0;
            }
#endif
            //link is down, reinit if in CO mode
            if(DOWN_NOT_READY == pmsg->state)
            {
                if(0 == g_rcmode)
                {
                    rt_kprintf("re init CO mode");
                    rt_CO_init(0);
                }
            }
            break;

        case ACK_PMD_STATUSGET:
            rt_kprintf("Event: id:0x%x,linkno:%d,datarate:%d\r\n",pmsg->msg_id,pmsg->linkno,pmsg->datarate);
            if(pmsg->datarate != 0 && pmsg->datarate<6000)
            {
                //update link rate:
                g_lineStatus.dateRate=pmsg->datarate;
                //g_lineStatus.linkStatus = UP_DATA_MODE;
                
                //update SNR margin timer
                //gt=rt_timer_create("t1",rt_checkSNR,RT_NULL,500,RT_TIMER_FLAG_ONE_SHOT);
                //rt_timer_start(gt);
            }
            break;

        //snr margin
    	 case ACK_PMD_PM_PARAMGET:     
             rt_kprintf("Event: id:0x%x,linkno:%d,snr_c:%d,snr_n:%d\r\n",pmsg->msg_id,pmsg->linkno,
                                                                                                            pmsg->snr_c,
                                                                                                            pmsg->snr_n); 
             //update line status:
             g_lineStatus.snr_c = pmsg->snr_c;
             g_lineStatus.snr_n = pmsg->snr_n;
             break;

        //EVT_EOC_LINKSTATE,link ready
        case EVT_EOC_LINKSTATE:
            rt_kprintf("Event: id:0x%x,linkno:%d,state:%d\r\n",pmsg->msg_id,pmsg->linkno,
                                                                                                           pmsg->state); 
            //link state change
            //NOT_READY;READY
            g_lineStatus.linkStatus = pmsg->state;

            //if linkup, check the link speed
            if(READY==pmsg->state)
            {
              	cmd_pmd_statusget.LinkNo = 0;
			rt_shdsl_send_idc_msg(0, CMD_PMD_STATUSGET, &cmd_pmd_statusget, sizeof(cmd_pmd_statusget));
                     //force phy6 to link
                     ETH_WritePHYRegister(6,22,0x873f);
            }            
            else
            {
                    //clear the snr reading
                     g_lineStatus.dateRate=0;
                     g_lineStatus.snr_c = 0;
                     g_lineStatus.snr_n = 0;
                     //clear phy6 link bit
                     ETH_WritePHYRegister(6,22,0x073f);
            }


            break;

        default:
            rt_kprintf("unknow msg ID\r\n",pmsg->msg_id);
            break;
    }
}

//state matchine
void rt_shs_thread_entry(void* parameter)
{
	struct rt_msg* p_msg;

	//check button for mode selection
	g_rcmode = ReadButton() & 0x01;

       //init config after checking the button 
     	initconfig(); 
	
	rt_kprintf("basic config first\r\n");	
	if(g_rcmode)
		rt_CPE_init(0,0);
	else
		rt_CO_init(0);
	
	while(1)
	{
		if(rt_mb_recv(&g_mb,(rt_uint32_t*)&p_msg,RT_WAITING_FOREVER) == RT_EOK)
		{
	              rt_msgdispatch(p_msg);		
                     //wait for change 
                     if(p_msg->msg_id!=100)
                         rt_free(p_msg);
		}
		rt_thread_sleep(10);
		//delay(20);
	}

	//never reach here
	rt_kprintf("quit shs thread\r\n");
}

int rt_shdsl_thread_init(void)
{
	rt_thread_t tid;

	//shdsl polling thread
	rt_kprintf("try shp thread\r\n");
	tid = rt_thread_create("shp",rt_shp_thread_entry, RT_NULL, 2048, RT_THREAD_PRIORITY_MAX/3, 20);
	if (tid != RT_NULL) 
		rt_thread_startup(tid);
	else
		rt_kprintf("shp ok\r\n");

	//shdsl state machine thread
	rt_kprintf("try shs thread\r\n");
	tid = rt_thread_create("shs",rt_shs_thread_entry, RT_NULL, 2048, RT_THREAD_PRIORITY_MAX/3+1, 20);
	if (tid != RT_NULL) 
		rt_thread_startup(tid);
	else
		rt_kprintf("shs ok\r\n");

	return 0;
}

//call from web config
void rt_shdsl_apply_config()
{
        unsigned char flag=0;
        unsigned int maxrate;
        
        rt_kprintf("dealy sconfig change, re init");    

        maxrate = g_config.maxrate * 64 * 1000;
        if(g_maxbaserate != maxrate)
        {
            g_maxbaserate = maxrate;
            flag = 1;
        }

        if(g_lineProbe != g_config.lineprobe+1)
        {
            g_lineProbe = g_config.lineprobe+1;
            flag = 1;
                
        }

        if((0==g_rcmode && 1==g_config.dslService) || 
            (1==g_rcmode && 2==g_config.dslService))
        {
            g_rcmode = 1-g_rcmode;
            flag = 1;                
        }

        if(flag)
            rt_shdsl_cmd(3);
            
}
