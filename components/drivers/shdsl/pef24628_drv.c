#include "lib_sysdep.h"
#include "stm32f10x.h"
#include "drv_api.h"
#include "drv_pef24628e_interface.h"
#include "drv_pef24628e_api.h"
#include "stdio.h"
#include "string.h"
#include "sys_noOSLib.h"

#include "pef24628_drv.h"
#include "shdsl_board.h"

typedef VOID(*IntHandler_t)(INT);

#define Bank1_PEF_D    ((unsigned int)0x61000000)    
#define Bank1_PEF_C    ((unsigned int)0x60000000)	 


#include "stm32f10x.h"


void pef24628_GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  /* Set PD.00(D2), PD.01(D3), PD.08(D13), PD.09(D14), PD.10(D15), PD.14(D0), PD.15(D1),
     PE.14(D11), PE.15(D12) as alternate function push pull */
  /* GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
                                GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | 
                                GPIO_Pin_15;                        */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 | GPIO_Pin_15;                                                             
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* Set PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
     PE.14(D11), PE.15(D12) as alternate function push pull */
  /*GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
                                GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
                                GPIO_Pin_15;*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;                                                                
  GPIO_Init(GPIOE, &GPIO_InitStructure); 

  /* PD.07(NE1)configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  
  /*!< NOE and NWE configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_Init(GPIOD, &GPIO_InitStructure);


  /*!< Configure PD6 for NOR memory Ready/Busy signal */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOD, &GPIO_InitStructure);


  /* test for gpio button 1,2,3,4*/  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;//管脚位置定义
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//输出速度2MHz  
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//浮空输入 IN_FLOATING  
  GPIO_Init(GPIOC,&GPIO_InitStructure); //C组GPIO初始化
  /* test for gpio button 5*/  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;//管脚位置定义
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//输出速度2MHz  
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//浮空输入 IN_FLOATING  
  GPIO_Init(GPIOD,&GPIO_InitStructure); //C组GPIO初始化
  /* test for gpio button 6,7,8*/
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;//管脚位置定义
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;//输出速度2MHz  
  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//浮空输入 IN_FLOATING  
  GPIO_Init(GPIOA,&GPIO_InitStructure); //C组GPIO初始化

  /* ETHERNET pins configuration */
  /* AF Output Push Pull:
   - ETH_MII_MDC / ETH_RMII_MDC: PC1
  - ETH_MII_MDIO / ETH_RMII_MDIO: PA2
  */
   /* Configure PA2 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure PC1 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  /* PE.02(RS)-A23 configuration,1:R/W data, 0:R/W Command*/
  //GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
  //GPIO_Init(GPIOE, &GPIO_InitStructure); 
}

void pef24628_Bus_Init(void)
{
  FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;

  FSMC_NORSRAMTimingInitTypeDef  p;

/*-- FSMC Configuration ------------------------------------------------------*/
/*----------------------- SRAM Bank 1 ----------------------------------------*/
  /* FSMC_Bank1_NORSRAM1 configuration */
  p.FSMC_AddressSetupTime = 2;
  p.FSMC_AddressHoldTime = 0;
  p.FSMC_DataSetupTime = 5;
  p.FSMC_BusTurnAroundDuration = 0;
  p.FSMC_CLKDivision = 0;
  p.FSMC_DataLatency = 0;
  p.FSMC_AccessMode = FSMC_AccessMode_B;

  /* Color LCD configuration ------------------------------------
     LCD configured as follow:
        - Data/Address MUX = Disable									 
        - Memory Type = SRAM
        - Data Width = 16bit
        - Write Operation = Enable												
        - Extended Mode = Enable													
        - Asynchronous Wait = Disable */
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
  //allen
  //FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);  

  /* BANK 1 (of NOR/SRAM Bank 1~4) is enabled */
  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
}

void MPI_WriteReg(unsigned int Reg,unsigned char RegValue)
{
  	unsigned int addr;
  	addr = (unsigned int)Reg << 16;
  	addr += Bank1_PEF_C;
  	//rt_kprintf("wr addr=0x%x\r\n",addr);
  
	*(__IO unsigned char*) (addr)= RegValue;	
}

unsigned char MPI_ReadReg(unsigned int Reg)
{
  unsigned char data;
  unsigned int addr;
  addr = (unsigned int)Reg << 16;
  addr += Bank1_PEF_C;

  //rt_kprintf("rd addr=0x%x\r\n",addr);
  data = *(__IO unsigned char*) (addr); 
  return  data;
}


#define IDC_FW_OFFSET 0x32000
#define IDC_FW_LEN 180308


#define DSL_FW_OFFSET 0x0
#define DSL_FW_LEN 196620

#define RX_BUFFER_SIZE 256*7

extern unsigned char  Tx_Buffer[];
extern unsigned char  Rx_Buffer[];
extern rt_device_t g_spi;


void idc_fw_read(unsigned int offset,unsigned short len)
{
	rt_device_read(g_spi,IDC_FW_OFFSET+offset,Rx_Buffer,len);
#if 0
    rt_kprintf("offset=%d\r\n",offset);
	for(i=0; i<len; i++)    //将Rx_Buffer中的数据通过串口打印
     {	
       rt_kprintf("0x%02X ", Rx_Buffer[i]);
       if(i%16 == 15)
       {
         rt_kprintf("\n\r");
       }
     }
 	rt_kprintf("\n\r");
 	*/
#endif
}

//len must less then page size 256
void dsl_fw_read(unsigned int offset,unsigned short len)
{	
	rt_device_read(g_spi,DSL_FW_OFFSET+offset,Rx_Buffer,len);
#if 0
	for(i=0; i<len; i++)    //将Rx_Buffer中的数据通过串口打印
     {	
       rt_kprintf("0x%02X ", Rx_Buffer[i]);
       if(i%16 == 15)
       {
         rt_kprintf("\n\r");
       }
     }
	rt_kprintf("\n\r");
#endif
}



LOCAL void Pef24628e_Int ( PEF24628E_DEV_t * pDev )
{
   Pef24628e_IntHandler ( pDev );
}

static rt_err_t pef24628_init(rt_device_t dev)
{
    return RT_EOK;
}

static rt_err_t pef24628_open(rt_device_t dev, rt_uint16_t oflag)
{


    return RT_EOK;
}

static rt_err_t pef24628_close(rt_device_t dev)
{
    return RT_EOK;
}

static rt_err_t pef24628_control(rt_device_t dev, rt_uint8_t cmd, void *args)
{
   IFX_int32_t ret=RT_EOK;
   PEF24628E_REG_IO_t *pReg_Io;
   PEF24628E_DOWNLOAD_FW_t *pFWDownload;
   PEF24628E_DEV_INIT_t *pDevCfg;
   PEF24628E_DEV_t* pDev;	

   RT_ASSERT(dev != RT_NULL);	
   //set the private data
   pDev = (PEF24628E_DEV_t*)(dev->user_data);
   
   switch ( cmd )
   {
   case FIO_PEF24628E_GET_VERSION:
      strncpy ( ( char * )args, DRV_PEF24628E_VER_STR, 80 );
      break;

   case FIO_PEF24628E_SET_CONFIG:
      Pef24628e_Set_Config ( pDev, ( PEF24628E_CONFIG_t * ) args );
      break;

   case FIO_PEF24628E_GET_CONFIG:
      Pef24628e_Get_Config ( pDev, ( PEF24628E_CONFIG_t * ) args );
      break;

   case FIO_PEF24628E_SET_IF:
      Pef24628e_Set_If ( pDev, ( PEF24628E_IF_t ) args );
      break;

   case FIO_PEF24628E_GET_IF:
      Pef24628e_Get_If ( pDev, ( PEF24628E_IF_t * ) args );
      break;

   case FIO_PEF24628E_SET_REG:
      pReg_Io = ( PEF24628E_REG_IO_t * ) args;
      if ( !Pef24628e_Set_Register ( pDev, pReg_Io->addr, pReg_Io->value ) )
         ret = RT_ERROR;
      break;

   case FIO_PEF24628E_GET_REG:
      pReg_Io = ( PEF24628E_REG_IO_t * ) args;
      if ( !Pef24628e_Get_Register ( pDev, pReg_Io->addr, ( IFX_uint32_t * ) & pReg_Io->value ) )
         ret = RT_ERROR;
      break;

   case FIO_PEF24628E_DOWNLOAD_FW:
      pFWDownload = ( PEF24628E_DOWNLOAD_FW_t * ) args;
      switch ( pFWDownload->core )
      {
      case PEF24628E_IDC:
         if ( !Pef24628e_IDC_Download ( pDev, pFWDownload->pFwImage, pFWDownload->size_byte ) )
            ret = RT_ERROR;
         if ( !Pef24628e_IDC_Start ( pDev ) )
            ret = RT_ERROR;
         break;

      case PEF24628E_DSL:
         if ( !Pef24628e_DSL_Download ( pDev, pFWDownload->pFwImage, pFWDownload->size_byte ) )
            ret = RT_ERROR;
         break;

      default:
         break;
      }
      break;

   case FIO_PEF24628E_DEV_INIT:
      if ( !pDev->bInit )
      {
         rt_kprintf("try io ctl FIO_PEF24628E_DEV_INIT\r\n");
         pDevCfg = ( PEF24628E_DEV_INIT_t * ) args;
         pDev->irq_vector = pDevCfg->irq_vector;

/*
         if ( pDevCfg->irq_vector && No_OS_InstallIntHandler ( pDevCfg->irq_vector,
                                                               ( IntHandler_t )Pef24628e_Int,
                                                               ( int ) pDev ) == ERROR )
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "cannot connect interrupt.\n\r" ) );
            return ( RT_ERROR );
         }
*/
         if ( Pef24628e_Init ( pDev, pDevCfg ) == IFX_FALSE )
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                  ( ERR_PREFIX "unable to initialize device.\n\r" ) );
            return ( RT_ERROR );
         }
/*
         if ( pDevCfg->irq_vector )
         {
            No_OS_IntEnable ( pDevCfg->irq_vector );
         }
*/     
         /* set SCI interface to half duplex (for a working collision detection) */
         Pef24628e_Send_Aux_Msg ( pDev, CMD_WR_REG_AUX_SCI_IF_MODE, 0x0A /*0x0A*/ );
                  
      }
      break;

   case FIO_PEF24628E_POLL_CHECK:
      ret = Pef24628e_Poll_Check ( pDev );
      break;

   case FIO_PEF24628E_WRITE_AUX:
      if ( !pDev->bInit )
      {
         pReg_Io = ( PEF24628E_REG_IO_t * ) args;
         if ( !Pef24628e_Send_Aux_Msg
              ( pDev, ( IFX_int8_t ) ( pReg_Io->addr ), ( IFX_int8_t ) ( pReg_Io->value ) ) )
            ret = RT_ERROR;
      }
      break;

   case FIO_PEF24628E_READ_AUX:
      pReg_Io = ( PEF24628E_REG_IO_t * ) args;
      if ( !Pef24628e_Send_Aux_Msg
           ( pDev, ( IFX_int8_t ) ( pReg_Io->addr ), ( IFX_int8_t ) ( pReg_Io->value ) ) )
         ret = RT_ERROR;
      pReg_Io->value = pDev->last_aux_value;
      break;

   case FIO_PEF24628E_DEV_ANY:
   	  Pef24628e_Send_Any_Msg(pDev);
	  break;
#if PEF24628E_USE_SCI_MONITOR == 1
   case FIO_PEF24628E_SCI_MONITOR:
      {
         if ( args )
         {
            /* Set SCI monitor to promiscious mode */
            /* bit positions of addr are not compared, if they are set to '1' in mask */
            pDev->bSCIMonitor = Pef24628e_Set_Address_Filter ( pDev, 0xFFFF, 0xFFFF );
         }
         else
         {
            /* Set normal mode */
            Pef24628e_Set_Address_Filter ( pDev, 0x00FF, 0xF3FF );
            pDev->bSCIMonitor = IFX_FALSE;
         }
      }
      break;
#endif

   default:
      rt_kprintf("Unknown IoCtl (0x%08X).\n", ( unsigned int ) cmd );
      ret = RT_ERROR;
   	}

    return ret;
}

static rt_size_t pef24628_read(rt_device_t dev,
                                   rt_off_t pos,
                                   void* buffer,
                                   rt_size_t size)
{
   IFX_int32_t nBytes = 0;
   PEF24628E_DEV_t* pDev;	
   
   pDev = (PEF24628E_DEV_t*)(dev->user_data);
   
   nBytes = Pef24628e_Get_IDC_Msg ( pDev, (IFX_uint8_t *)buffer, size );

   if ( nBytes < 0 )
   {
      return ERROR;
   }

   return nBytes;
}

static rt_size_t pef24628_write(rt_device_t dev,
                                    rt_off_t pos,
                                    const void* buffer,
                                    rt_size_t size)
{
    IFX_int32_t nBytes = 0;	
    PEF24628E_DEV_t* pDev;	
   
    pDev = (PEF24628E_DEV_t*)(dev->user_data);

    nBytes = Pef24628e_Send_IDC_Msg ( pDev, buffer, size );	
	
    return nBytes;
}


rt_err_t pef24628_drv_init(struct rt_pef24628* dev,const char * device_name)
{

/*
	g_pef24628.parent.init = pef24628_init;
	g_pef24628.parent.open = pef24628_open;
	g_pef24628.parent.close = pef24628_close;
	g_pef24628.parent.read = pef24628_read;
	g_pef24628.parent.write = pef24628_write;
	g_pef24628.parent.control = pef24628_control;
	
       rt_device_register(&g_pef24628.parent, device_name, RT_DEVICE_FLAG_RDWR);
*/
	dev->parent.init = pef24628_init;
	dev->parent.open = pef24628_open;
	dev->parent.close = pef24628_close;
	dev->parent.read = pef24628_read;
	dev->parent.write = pef24628_write;
	dev->parent.control = pef24628_control;	

	//private data
	dev->parent.user_data=(void*)&(dev->data);

    rt_device_register(&(dev->parent), device_name, RT_DEVICE_FLAG_RDWR);
	return RT_ERROR;
}
