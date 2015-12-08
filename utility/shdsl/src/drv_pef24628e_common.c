/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/** \addgroup DRV_PEF24628E_IMPLEMENTATION Device Driver Implementation */
/*@{*/
/**
   \file 
   Common functions for the device driver driver
*/

/* ============================= */
/* Includes                      */
/* ============================= */
#include "stm32f10x.h"
#include "lib_sysdep.h"

#include "drv_api.h"
#include "drv_pef24628e_interface.h"
#include "drv_pef24628e_api.h"
#include "stdio.h"
//allen
#undef INCLUDE_SCC_HDLC

#ifdef INCLUDE_SCC_HDLC
#include "drv_scc_hdlc_interface.h"
#endif

#undef LOCAL
#define LOCAL

/* ============================= */
/* Local Macros & Definitions    */
/* ============================= */
/*#define DRV_SOC4E_QUEUES_LOG*/

/* ============================= */
/* Global variable definition    */
/* ============================= */

#ifdef INCLUDE_SCC_HDLC
#define SCC_HDLC_MAX_CHANNELS	 4
static IFX_void_t *pSciHdlcDev[SCC_HDLC_MAX_CHANNELS];
static IFX_uint8_t SciHdlcDevCount[SCC_HDLC_MAX_CHANNELS];
extern IFX_void_t *Scc_Hdlc_Open_Kernel ( int num );
extern IFX_int32_t Scc_Hdlc_Close_Kernel ( IFX_void_t * pDev );
extern IFX_int32_t Scc_Hdlc_Send_Frame ( IFX_void_t * pDev, IFX_uint8_t * pSrc, IFX_int32_t nLength );
extern IFX_int32_t Scc_Hdlc_Get_Frame ( IFX_void_t * pDev, IFX_uint8_t * pDst, IFX_int32_t nLength );
extern IFX_boolean_t Scc_Hdlc_Filtered_Poll_Check(IFX_void_t *pDev, IFX_uint8_t address);
extern IFX_void_t Scc_Hdlc_Install_Callback(IFX_void_t *pDev, IFX_void_t * pCallback);
extern IFX_uint32_t Scc_Hdlc_Clock_Init ( IFX_void_t * pDev, IFX_uint32_t clk_cfg );
extern IFX_uint32_t Scc_Hdlc_Set_Baudrate ( IFX_void_t * pDev, IFX_uint32_t new_baud );
extern IFX_void_t Scc_Hdlc_Set_Config ( IFX_void_t * pDev, IFX_void_t * Config );
extern IFX_void_t Scc_Hdlc_Get_Config ( IFX_void_t * pDev, IFX_void_t * Config );
extern IFX_uint32_t Scc_Hdlc_Set_Address_Filter ( IFX_void_t * pDev, IFX_uint16_t mask, IFX_uint16_t addr );

LOCAL IFX_int32_t Pef24628e_Get_SCC_Msg ( PEF24628E_DEV_t * pDev, IFX_void_t * pSCC_HDLC_Dev );
LOCAL IFX_int32_t Pef24628e_Send_SCC_Msg ( PEF24628E_DEV_t * pDev, IFX_void_t * pSCC_HDLC_Dev, IFX_uint8_t * pBuf, IFX_int32_t nLength );
IFX_void_t Pef24628e_CB_SCC_Msg ( IFX_void_t );

#endif /* INCLUDE_SCC_HDLC */

/** what string support, driver version string */
const char PEF24628E_WHATVERSION[] = DRV_PEF24628E_WHAT_STR;

/* pointer to device structures, not corresponding to used FPGA instance!! */
PEF24628E_DEV_t *Pef24628e_Devices[PEF24628E_MAX_DEV_NUMBER] = { NULL };

/** trace group implementation */
CREATE_TRACE_GROUP ( PEF24628E_DRV );
/** log group implementation */
CREATE_LOG_GROUP ( PEF24628E_DRV );

/* ============================= */
/* Local function declaration    */
/* ============================= */
LOCAL IFX_void_t Pef24628e_Sci_RpfInt ( PEF24628E_DEV_t * pDev );
LOCAL IFX_void_t Pef24628e_Sci_RmeInt ( PEF24628E_DEV_t * pDev );
LOCAL IFX_void_t Pef24628e_Sci_XprInt ( PEF24628E_DEV_t * pDev );
LOCAL IFX_void_t Pef24628e_Sci_IntHandler ( PEF24628E_DEV_t * pDev );
LOCAL IFX_void_t Pef24628e_Mpi_IntHandler ( PEF24628E_DEV_t * pDev );
LOCAL IFX_void_t Pef24628e_Mpi_Tx ( PEF24628E_DEV_t * pDev );
LOCAL IFX_void_t Pef24628e_Mpi_RxInt ( PEF24628E_DEV_t * pDev );
LOCAL IFX_boolean_t Pef24628e_Sci_Process_Frame ( PEF24628E_DEV_t * pDev );
/*
LOCAL IFX_boolean_t Pef24628e_Send_RS_Msg ( PEF24628E_DEV_t * pDev,
                                             IFX_uint8_t opcd,
                                             IFX_uint32_t param,
                                             IFX_uint8_t * pSrc, IFX_uint16_t nLength );
LOCAL IFX_boolean_t Pef24628e_Send_IDC_RS_Msg ( PEF24628E_DEV_t * pDev,
                                                 IFX_uint8_t opcd,
                                                 IFX_uint32_t param,
                                                 IFX_uint8_t * pSrc, IFX_uint16_t nLength );

LOCAL IFX_boolean_t Pef24628e_Send_Aux_Msg(PEF24628E_DEV_t * pDev, 
                                                IFX_uint8_t reg, 
                                                IFX_uint8_t param);
                                                */
LOCAL IFX_boolean_t Pef24628e_Send_TP_Ack ( PEF24628E_DEV_t * pDev,
                                             IFX_uint8_t Odd, IFX_boolean_t nak );

LOCAL IFX_boolean_t Pef24628e_Sci_Tx_Polling ( PEF24628E_DEV_t * pDev );

/* ============================= */
/* Local variable definition     */
/* ============================= */

/* ============================= */
/* Local function definition     */
/* ============================= */

#ifdef INCLUDE_MPI
//no debug print for default
uint8_t g_debug = 0;

/**   
   Handles the MPI and SCI interrupts from the device.

\param pDev    device structure

\remark called on interrupt level

*/
IFX_void_t Pef24628e_IntHandler ( PEF24628E_DEV_t * pDev )
{

   IFX_uint8_t ista;

   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_IntHandler failed\n\r" ) );
      return;
   }

   /* handle pending events */
   ista = ( REG_GET ( pDev->uc_reg->MPI_EINT ) & REG_GET ( pDev->uc_reg->MPI_EINT_EN ) );

   if ( ista == 0 )
      /* no more interrupts pending */
      return;

   if ( ista & MPI_MPINT_INTSCI )
   {
      if(g_debug)
	  	rt_kprintf("\r\nvvvvvv Pef24628e_Sci_IntHandler vvvvvv\r\n");
      Pef24628e_Sci_IntHandler ( pDev );
	  if(g_debug)
	  	rt_kprintf("^^^^^^ Pef24628e_Sci_IntHandler ^^^^^^\r\n\r\n");
   }

   /* Rx Interrupt on MPI */
   if ( ista & MPI_MPINT_INTIDC )
   {
      //if(g_debug)
	//  	rt_kprintf("\r\nvvvvvv Pef24628e_Mpi_RxInt vvvvvv\r\n");
      Pef24628e_Mpi_RxInt ( pDev );	  
	  //if(g_debug)
	  //	rt_kprintf("^^^^^^ Pef24628e_Mpi_RxInt ^^^^^^\r\n\r\n");
   }

   /* clear bits by writing 1! */
   REG_SET ( pDev->uc_reg->MPI_EINT, ista );
}

/**   
   Handles the interrupts for the SCI interface.

\param pDev    device structure

\remark called on interrupt level

*/
IFX_void_t Pef24628e_Sci_IntHandler ( PEF24628E_DEV_t * pDev )
{
   IFX_uint8_t ista;

   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_Sci_IntHandler failed\n\r" ) );
      return;
   }

   /* Acknowledge pending events, clear on read */
   ista = ( REG_GET ( pDev->uc_reg->SCI_INT ) & REG_GET ( pDev->uc_reg->SCI_INTEN ) );
   //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Pef24628e_Sci_IntHandler: ista = %02X\n", ista ) );

   if ( ista == 0 )
      /* no more interrupts pending */
      return;

   if ( ista & SCI_INTERRUPT_XDU )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "HDLC XDU: SCI Transmit Data Underrun\n\r" ) );
      /* give a TX reset, next XPR will cause the wakeup event */
      REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_XRES );
      pDev->TxFifo.nBytes = 0;
      pDev->TxFifo.nSent = 0;

      pDev->uStatistics |= 0x80000000;
      
      REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_XDU );
   }

   if ( ista & SCI_INTERRUPT_XPR )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "HDLC XPR\n\r" ) );
      Pef24628e_Sci_XprInt ( pDev );
      REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_XPR );
   }

   if ( ista & SCI_INTERRUPT_RPF )
   {
      //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "HDLC RPF\n\r" ) );
      /* received a part of the message */
      Pef24628e_Sci_RpfInt ( pDev );
   }

   if ( ista & SCI_INTERRUPT_RME )
   {
      //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "HDLC RME\n\r" ) );
      /* received an end of the message */
      Pef24628e_Sci_RmeInt ( pDev );
	  //if(g_debug)
	  //	rt_kprintf("Pef24628e_Sci_RmeInt out\r\n");
   }

   if ( ista & SCI_INTERRUPT_RFO )
   {
      //ALLEN
      //LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "HDLC RFO\n\r" ) );
      REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_RRES );
      pDev->pRxFifoWrite->nBytes = 0;
      REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_RFO );
   }

   if ( ista & SCI_INTERRUPT_XDOV )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "HDLC XDOV: Ingress FIFO overflow.\n\r" ) );
      /* give a TX reset, next XPR will cause the wakeup event */
      REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_XRES );
      pDev->TxFifo.nBytes = 0;
      pDev->TxFifo.nSent = 0;
      REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_XDOV );
   }
}

/**   
   Handles the receive frame interrupts of the SCI interface.

\param pDev    device structure

\remark called on interrupt level

*/
LOCAL IFX_void_t Pef24628e_Sci_RpfInt ( PEF24628E_DEV_t * pDev )
{
   IFX_int32_t i, len;
   IFX_uint8_t *pData;
/*
   len = ( ( ( IFX_uint16_t ) ( REG_GET ( pDev->uc_reg->SCI_REPORT_H ) & 0x0F ) ) << 8 ) |
      ( IFX_uint16_t ) ( REG_GET ( pDev->uc_reg->SCI_REPORT_L ) );
*/
   /* if RPF interrupt is set, then read always 64 bytes */
   len = PEF24628E_SCI_FIFO_SIZE;

   pData = pDev->pRxFifoWrite->pData + pDev->pRxFifoWrite->nBytes;

   /* we received a part of the message 
      check for free space and put it into the current Rx FIFO buffer */
   if ( ( pDev->pRxFifoWrite->nBytes + 1 ) + PEF24628E_SCI_FIFO_SIZE < PEF24628E_MSG_SIZE )
   {
      pDev->SciRxState = SCI_RX_ACTIVE;

      pDev->pRxFifoWrite->bSendIdcViaSciBridge = IFX_TRUE;

  //ALLEN
/*
      LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "RPF: DUMP (%d), nBytes = %d, len = %d\n\r",
                                            PEF24628E_SCI_FIFO_SIZE, pDev->pRxFifoWrite->nBytes,
                                            (int)len ) );
*/
      for ( i = 0; i < len; i++ )
      {
         /* copy to fifo */
         *( pData + i ) = REG_GET ( pDev->uc_reg->SCI_EGRESS );
      }

      /* update length */
      pDev->pRxFifoWrite->nBytes += ( IFX_uint16_t ) len;
   }
   else
   {
      pDev->SciRxState = SCI_RX_ERROR;
      pDev->pRxFifoWrite->nBytes = 0;
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
            ( ERR_PREFIX "RX Error 1, message too long for buffer\n\r" ) );
   }

   /* ack interrupt */
   REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_RPF );

   /* indicate that all bytes are read out of the FIFO */
   REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_RMC );
}

/**   
   Handles the receive frame end interrupts of teh SCI interface.

\param pDev    device structure

\remark called on interrupt level

*/
LOCAL IFX_void_t Pef24628e_Sci_RmeInt ( PEF24628E_DEV_t * pDev )
{
   int len, i;
   IFX_boolean_t WakeUp = IFX_FALSE;
   IFX_uint8_t *pData;

   len = ( ( ( IFX_uint16_t ) ( REG_GET ( pDev->uc_reg->SCI_REPORT_H ) & 0x0F ) ) << 8 ) |
      ( IFX_uint16_t ) ( REG_GET ( pDev->uc_reg->SCI_REPORT_L ) );

   pData = pDev->pRxFifoWrite->pData + pDev->pRxFifoWrite->nBytes;

   if(g_debug)
   LOG ( PEF24628E_DRV, DBG_LEVEL_LOW,
         ( PREFIX "RME: total length = %d, nBytes %d :", len, pDev->pRxFifoWrite->nBytes ) );

   if ( ( len >= PEF24628E_SCI_FIFO_SIZE ) && ( ( len % PEF24628E_SCI_FIFO_SIZE ) == 0 ) )
   {
      len = PEF24628E_SCI_FIFO_SIZE;
   }
   else
   {
      len %= PEF24628E_SCI_FIFO_SIZE;
   }

   if ( len == 0 )
   {
      //allen
      //LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "RX Error, message with length 0\n\r" ) );
   }

   if ( ( pDev->pRxFifoWrite->nBytes + 1 ) + len < PEF24628E_MSG_SIZE )
   {
      pDev->SciRxState = SCI_RX_ACTIVE;

      pDev->pRxFifoWrite->bSendIdcViaSciBridge = IFX_TRUE;

      for ( i = 0; i < len; i++ )
      {
         /* copy to fifo */
         *( pData + i ) = REG_GET ( pDev->uc_reg->SCI_EGRESS );
		 if(g_debug)
		 LOG ( PEF24628E_DRV, DBG_LEVEL_LOW,( PREFIX "%02X ", *( pData + i )));
      }
     if(g_debug)
	 LOG ( PEF24628E_DRV, DBG_LEVEL_LOW,( PREFIX "\r\n"));

      /* update length */
      pDev->pRxFifoWrite->nBytes += ( IFX_uint16_t ) len;

      if ( Pef24628e_Sci_Process_Frame ( pDev ) == IFX_TRUE )
      {
         /* Data frame -> store it in the FIFO and notify upper layer */
         WakeUp = IFX_TRUE;

#ifdef PEF24628E_USE_SCI_MONITOR
         /* check if the SCI monitor is in active state */
         if ( pDev->bSCIMonitor )
         {
            /* add 1 byte = PEF24628E_ORDINAL_DATA at the end of the frame */
            ( pDev->pRxFifoWrite->nBytes )++;
            *( pData + len ) = PEF24628E_ORDINAL_DATA;
         }
#endif
         /* no errors -> switch to the next Rx FIFO block */
         pDev->pRxFifoWrite++;

         /* check for space in fifo */
         if ( pDev->pRxFifoWrite >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
            pDev->pRxFifoWrite = &pDev->RxFifo[0];

         if ( pDev->pRxFifoWrite == pDev->pRxFifoRead )
         {
            pDev->bRxFifoFull = IFX_TRUE;
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "RME: RxRead Fifo full\n\r" ) );
            /* prevent overflow by disabling Rx interrupts */
            BFLD ( pDev->uc_reg->SCI_INTEN, SCI_INTERRUPT_RPF | SCI_INTERRUPT_RME, 0x00 );
         }
         else
            pDev->bRxFifoFull = IFX_FALSE;

#ifdef PEF24628E_USE_SCI_MONITOR
         /* check if the SCI monitor is in active state */
         if ( pDev->bSCIMonitor )
         {

            /* add 1 byte = PEF24628E_SCI_MONITOR_DATA at the end of the frame */
            memcpy ( pDev->pRxFifoWrite->pData, pData, len );

            pData = pDev->pRxFifoWrite->pData + pDev->pRxFifoWrite->nBytes;
            pDev->pRxFifoWrite->nBytes += ( IFX_uint16_t ) ( len + 1 );
            *( pData + len ) = PEF24628E_SCI_MONITOR_DATA;

            /* no errors -> switch to the next Rx FIFO block */
            pDev->pRxFifoWrite++;

            /* check for space in fifo */
            if ( pDev->pRxFifoWrite >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
               pDev->pRxFifoWrite = &pDev->RxFifo[0];

            if ( pDev->pRxFifoWrite == pDev->pRxFifoRead )
            {
               pDev->bRxFifoFull = IFX_TRUE;
               /* prevent overflow by disabling Rx interrupts */
               BFLD ( pDev->uc_reg->SCI_INTEN, SCI_INTERRUPT_RPF | SCI_INTERRUPT_RME, 0x00 );
            }
            else
               pDev->bRxFifoFull = IFX_FALSE;
         }
#endif
      }
      else
      {
#ifdef PEF24628E_USE_SCI_MONITOR
         WakeUp = IFX_TRUE;

         /* check if the SCI monitor is in active state */
         if ( pDev->bSCIMonitor )
         {
            /* add 1 byte = PEF24628E_SCI_MONITOR_DATA at the end of the frame */
            ( pDev->pRxFifoWrite->nBytes )++;
            *( pData + len ) = PEF24628E_SCI_MONITOR_DATA;

            /* no errors -> switch to the next Rx FIFO block */
            pDev->pRxFifoWrite++;

            /* check for space in fifo */
            if ( pDev->pRxFifoWrite >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
               pDev->pRxFifoWrite = &pDev->RxFifo[0];

            if ( pDev->pRxFifoWrite == pDev->pRxFifoRead )
            {
               pDev->bRxFifoFull = IFX_TRUE;
               /* prevent overflow by disabling Rx interrupts */
               BFLD ( pDev->uc_reg->SCI_INTEN, SCI_INTERRUPT_RPF | SCI_INTERRUPT_RME, 0x00 );
            }
            else
               pDev->bRxFifoFull = IFX_FALSE;
         }
#endif
         pDev->pRxFifoWrite->nBytes = 0;
      }

      if ( pDev->irq_vector )
      {
         /* Ack received -> wake up TX thread */
         //len = IFXOS_WakeUpEvent ( pDev->wqTxAck );     /* 'len = ' - to shut up the compiller */
      }
   }
   else
   {
      /* discard messages exceeding the buffer size */
      pDev->SciRxState = SCI_RX_ERROR;
      pDev->pRxFifoWrite->nBytes = 0;
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
            ( ERR_PREFIX "RME: RX Error 1, message too long for buffer\n\r" ) );
   }

   /* ack interrupt */
   REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_RME );

   /* indicate that all bytes are read out of the FIFO */
   REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_RMC );

   /* if there was an error, give a reset */
   if ( pDev->SciRxState == SCI_RX_ERROR )
      REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_RRES );

   if ( ( WakeUp == IFX_TRUE ) && ( pDev->bNeedWakeUp == IFX_TRUE ) )
   {
#ifndef NO_OS
     // IFXOS_WakeUp ( ( pDev->WakeupList ), 0 /*SELREAD*/ );
#endif /*NO_OS */
      pDev->bNeedWakeUp = IFX_FALSE;
   }

   pDev->SciRxState = SCI_RX_IDLE;
}

/**   
   Sends an HDLC frame via the SCI interface. The maximum size
   of transmitted data will be determined by the \ref PEF24628E_SCI_FIFO_SIZE .
   If the frame is longer than PEF24628E_SCI_FIFO_SIZE the rest
   of the frame will be transmitted within the subsequent interrupt.

\param pDev    device structure

\remark called on interrupt level

*/
LOCAL IFX_void_t Pef24628e_Sci_XprInt ( PEF24628E_DEV_t * pDev )
{
   IFX_uint16_t len, i = 3000;
   volatile IFX_uint8_t *pData;

   pData = &pDev->TxFifo.pData[pDev->TxFifo.nSent];

   len =
      ( pDev->TxFifo.nBytes >
        ( IFX_uint16_t ) PEF24628E_SCI_FIFO_SIZE ) ? PEF24628E_SCI_FIFO_SIZE : pDev->TxFifo.nBytes;

   if ( len == 0 )
   {
      return;
   }

   //tx dump on rs msg
/*   
   if(g_debug==1)
   {
	   rt_kprintf("xprInt tx: ");
	   for(i=0;i<len;i++)
	   {
		   rt_kprintf("0x%02X ", *(pData + i));
	       if(i%16 == 15)
	       {
	         rt_kprintf("\n\r");
	       }
	   }
	   rt_kprintf("\r\n");
   }
*/
   for ( i = 0; i < len; i++ )
   {
      REG_SET ( pDev->uc_reg->SCI_INGRESS, *( pData + i ) );
   }

   pDev->TxFifo.nSent += len;
   pDev->TxFifo.nBytes -= len;

   if ( pDev->TxFifo.nBytes )
   {
      /* not all sent yet */
      REG_SET ( pDev->uc_reg->SCI_CTRL_H, SCI_CTRL_HIGH_XTF );
   }
   else
   {
      /* all in buffer was sent */
      REG_SET ( pDev->uc_reg->SCI_CTRL_H, ( SCI_CTRL_HIGH_XTF | SCI_CTRL_HIGH_XME ) );
   }
}

/**
   Transmit a frame via the SCI interface in polling mode.

\param pDev    device structure

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
LOCAL IFX_boolean_t Pef24628e_Sci_Tx_Polling ( PEF24628E_DEV_t * pDev )
{
   int counter;

   /* Wait for ack */
   pDev->bTxAckReceived = IFX_FALSE;
   pDev->uStatistics &=~ 0x80000000;

   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "Pef24628e_Sci_Tx_Polling failed\n\r" ) );
      return IFX_FALSE;
   }

   /* Send whole frame */
   do
   {
#if (SCI_TX_POLLING_DELAY > 0)
      counter = 5000000/(SCI_TX_POLLING_DELAY);
#else
      counter = 5000000;
#endif

      Pef24628e_Sci_XprInt ( pDev );

      while ( ( ( REG_GET ( pDev->uc_reg->SCI_INT ) & SCI_INTERRUPT_XPR ) != SCI_INTERRUPT_XPR )
              && --counter )
      {
#if (SCI_TX_POLLING_DELAY > 0)
         IFXOS_DELAYUS ( SCI_TX_POLLING_DELAY );
#endif
      }

      /* Acknowledge interrupt */
      REG_SET ( pDev->uc_reg->SCI_INT, SCI_INTERRUPT_XPR );

      if ( counter == 0 )
      {
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
               ( ERR_PREFIX "Pef24628e_Sci_Tx_Polling: SCI_INTERRUPT_XPR missing\n\r" ) );
         return IFX_FALSE;
      }

   } while ( pDev->TxFifo.nBytes );

#if (SCI_TX_POLLING_DELAY > 0)
   counter = 5000000/(SCI_TX_POLLING_DELAY);
#else
   counter = 5000000;
#endif
   
   for (;(counter > 0) && (!pDev->bTxAckReceived); --counter)
   {
      Pef24628e_IntHandler ( pDev );
      if ( pDev->uStatistics & 0x80000000 ) 
      {
         pDev->uStatistics &=~ 0x80000000;
         break;
      }
#if (SCI_TX_POLLING_DELAY > 0)
      IFXOS_DELAYUS ( SCI_TX_POLLING_DELAY );
#endif
   }

   if ( counter == 0 )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Pef24628e_Sci_Tx_Polling: ACK missing\n\r" ) );
   }

   return ( !pDev->txErr ? IFX_TRUE : IFX_FALSE );
}


/**
   Transmit of message through MPI mailbox in blocking mode.
   
\param pDev       device structure

\remark called on interrupt level

*/
LOCAL IFX_void_t Pef24628e_Mpi_Tx ( PEF24628E_DEV_t * pDev )
{
   IFX_uint16_t i = 10;
   volatile IFX_uint8_t *pData;
#ifdef DRV_SOC4E_QUEUES_LOG
   char pLogMsg[1024];
   unsigned long nCharsWrtn = 0, nLen = 0;
#endif

   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_Mpi_Tx failed\n\r" ) );
      return;
   }

#ifndef DRV_SOC4E_QUEUES_LOG
	//allen
	//LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "MPI_INGRESS(%d): ", pDev->TxFifo.nBytes ) );
#else
   if( (18+pDev->TxFifo.nBytes*3+2+1) > sizeof(pLogMsg) )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "too big message for loging MPI_INGRESS(%d): ", pDev->TxFifo.nBytes ) );      
   }
   else
   {
      nLen = sprintf(pLogMsg, "MPI_INGRESS(%d):", pDev->TxFifo.nBytes);
      if( nLen < 0 )
      {
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "failed to compose log message for MPI_INGRESS(%d): ", pDev->TxFifo.nBytes ) );
      }
      else
      {
         nCharsWrtn += nLen;
      }
   }
#endif
   /* check if the last frame transmitted */
   while ( ( REG_GET ( pDev->uc_reg->MPI_IINT ) & MPI_INTERRUPT_R ) && --i )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( _LOGGING_PREFIX "*" ) );
      IFXOS_Wait ( 10 );
   }

   if ( i == 0 )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "MPI message sending failed.\n\r" ) );
      return;
   }

   pData = &pDev->TxFifo.pData[0];

   if ( pDev->TxFifo.nBytes == 0 )
   {
 
     LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "MPI message sending failed, %d bytes\n", pDev->TxFifo.nBytes ) );
    
		 return;
   }

   for ( i = 0; i < pDev->TxFifo.nBytes; i++ )
   {
      REG_SET ( pDev->uc_reg->MPI_INGRESS, *( pData + i ) );
#ifndef DRV_SOC4E_QUEUES_LOG
      //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "0x%02X ", *( pData + i ) ) );
#else
      nLen = sprintf(&pLogMsg[nCharsWrtn], " 0x%02X", *(pData + i));
      if( nLen < 0 )
      {
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "failed to compose log message for MPI_INGRESS(%d): ", pDev->TxFifo.nBytes ) );
      }
      else
      {
         nCharsWrtn += nLen;
      }
#endif
   }
   
   if (pDev->bFwDownloaded == IFX_TRUE )
   {
      pDev->uLastCmdId = (((IFX_uint16_t)pData[1]) << 3) | ((pData[0] & 0xE0) >> 5);
      pDev->uLastCmdTcId = (((IFX_uint16_t)(pData[3] & 0x07)) << 8) | pData[2];

      pDev->uStatistics |= (1 << 0);
   }

#ifndef DRV_SOC4E_QUEUES_LOG
   LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\n\r" ) );
#else
   nLen = sprintf(&pLogMsg[nCharsWrtn], "\n\r");
   if( nLen < 0 )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "failed to compose log message for MPI_INGRESS(%d): ", pDev->TxFifo.nBytes ) );
   }
   else
   {
      nCharsWrtn += nLen;
      //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( "%s", pLogMsg ) );
   }
#endif
   pDev->TxFifo.nSent = pDev->TxFifo.nBytes;
   pDev->TxFifo.nBytes = 0;

   //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "MPI message sent.\n\r" ) );

   pDev->txErr = IFX_FALSE;

   /* give send command */
   REG_SET ( pDev->uc_reg->MPI_IINT, MPI_INTERRUPT_R );
}

/**   
   Handles the receive interrupt of the MPI interface.

\param pDev       device structure

\remarks:
   This routine is called from Interrupt.

*/
LOCAL IFX_void_t Pef24628e_Mpi_RxInt ( PEF24628E_DEV_t * pDev )
{
   IFX_uint8_t *pData;
   IFX_int32_t len, i;
   IFX_uint8_t dummy;
   
#ifdef DRV_SOC4E_QUEUES_LOG
   char pLogMsg[1024];
   unsigned long nCharsWrtn = 0, nLen = 0;
#endif
   IFX_uint16_t nMsgId, nTcId;

   //if(g_debug)
   //	rt_kprintf("Pef24628e_Mpi_RxInt in\r\n");
   
   /* check how many bytes are in the fifo */
   len = 4 * ( REG_GET ( pDev->uc_reg->MPI_EFSTAT ) & 0x3F );

   pData = pDev->pRxFifoWrite->pData + pDev->pRxFifoWrite->nBytes;

   if ( len == 0 )
   {
      //ALLEN
      /*
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
            ( PREFIX "Pef24628e_Mpi_RxInt: RX Error, message with length 0\n\r" ) );
            */
      return;
   }
   
   if ( (pDev->pRxFifoWrite->nBytes + len > PEF24628E_MSG_SIZE) )
   {
       LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
             ( PREFIX "Pef24628e_Mpi_RxInt: RX Error 1, message (%d bytes) too long for buffer --> Limit Message, loose msg-tail\n\r",(int)len ) );
       len = PEF24628E_MSG_SIZE - pDev->pRxFifoWrite->nBytes;      
   }   

   if ( pDev->pRxFifoWrite->nBytes + len <= PEF24628E_MSG_SIZE )
   {
      pDev->pRxFifoWrite->bSendIdcViaSciBridge = IFX_FALSE;

      #ifndef DRV_SOC4E_QUEUES_LOG
      //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "MPI_EGRESS(%d): ", (int)len ) );
      #else
      if( (17+len*3+2+1) > sizeof(pLogMsg) )
      {
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "too big message for loging MPI_EGRESS(%d): ", (int)len ) );      
      }
      else
      {
         nLen = sprintf(pLogMsg, "MPI_EGRESS(%d):", (int)len);
         if( nLen < 0 )
         {
            /*IFXOS_FREE(pLogMsg);
            pLogMsg = NULL;*/
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "failed to compose log message for MPI_EGRESS(%d): ", (int)len ) );
         }
         else
         {
            nCharsWrtn += nLen;
         }
      }
      #endif

      for ( i = 0; i < len; i++ )
      {
         /* copy from fifo */
         *( pData + i ) = REG_GET ( pDev->uc_reg->MPI_EGRESS );
         #ifndef DRV_SOC4E_QUEUES_LOG
         //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "0x%02X ", *( pData + i ) ) );
         #else
         nLen = sprintf(&pLogMsg[nCharsWrtn], " 0x%02X", *(pData + i));
         if( nLen < 0 )
         {
            /*IFXOS_FREE(pLogMsg);
            pLogMsg = NULL;*/
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "failed to compose log message for MPI_EGRESS(%d): ", (int)len ) );
         }
         else
         {
            nCharsWrtn += nLen;
         }
         #endif
      }

      if (pDev->bFwDownloaded == IFX_TRUE )
      {
         nMsgId = (((IFX_uint16_t)pData[1]) << 3) | ((pData[0] & 0xE0) >> 5);
         nTcId  = (((IFX_uint16_t)(pData[3] & 0x07)) << 8) | pData[2];

         /* check if this is an acknowledge message */
         if (((nMsgId & ~0x0600) == pDev->uLastCmdId ) && (nMsgId < 0x500))
         {
            /* check if we have correct tcid */
            if (nTcId != pDev->uLastCmdTcId)
            {
               pDev->uStatistics |= (1 << 2);
            }
            else
            {
               if (( pDev->uStatistics & (1 << 0) ) == 0x0)
               {
                  /* we have an extra ackmowledge */
                  pDev->uStatistics |= (1 << 1);
               }
               else
               {
                  /* we have an ackmowledge in time */
                  pDev->uStatistics &= ~(1 << 0);
               }
            }         
            pDev->uLastAckId = nMsgId;
         }
      }
      
      #ifndef DRV_SOC4E_QUEUES_LOG
      LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\n\r" ) );
      #else
      nLen = sprintf(&pLogMsg[nCharsWrtn], "\n\r");
      if( nLen < 0 )
      {
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "failed to compose log message for MPI_EGRESS(%d): ", (int)len ) );
      }
      else
      {
         nCharsWrtn += nLen;
         LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( "%s", pLogMsg ) );
      }
      #endif
      /* update length */
      pDev->pRxFifoWrite->nBytes += ( IFX_uint16_t ) len;

      #ifdef PEF24628E_USE_SCI_MONITOR
      /* check if the SCI monitor is in active state */
      if ( pDev->bSCIMonitor )
      {
         /* add 1 byte = PEF24628E_ORDINAL_DATA at the end of the frame */
         ( pDev->pRxFifoWrite->nBytes )++;
         *( pData + len ) = PEF24628E_ORDINAL_DATA;
      }
      #endif

   }
   else
   {
      /* this branch will never been taken due to len-limitation further-up */
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
           ( PREFIX "Pef24628e_Mpi_RxInt: RX Error 1, message (%d bytes) too long for buffer\n\r",(int)len ) );
      /* discard messages exceeding the buffer size */
      pDev->pRxFifoWrite->nBytes = 0;
      /* and clear buffer */
      for ( i = 0; i < PEF24628E_MSG_SIZE; i++ )
      {
         /* read fifo to dummy */
         dummy = REG_GET ( pDev->uc_reg->MPI_EGRESS );
      }
      return;
   }

   //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Pef24628e_Mpi_RxInt: Frame received.\n\r" ) );

   /* switch to the next Rx FIFO block */
   pDev->pRxFifoWrite++;

   /* check for space in fifo */
   if ( pDev->pRxFifoWrite >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
      pDev->pRxFifoWrite = &pDev->RxFifo[0];

   if ( pDev->pRxFifoWrite == pDev->pRxFifoRead )
   {
      pDev->bRxFifoFull = IFX_TRUE;
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_Mpi_RxInt: RxRead Fifo full\n\r" ) );
      /* prevent overflow by disabling Rx interrupts */
      BFLD ( pDev->uc_reg->MPI_EINT_EN, MPI_MPINT_INTIDC, 0x00 );
   }
   else
      pDev->bRxFifoFull = IFX_FALSE;

   if ( pDev->bNeedWakeUp == IFX_TRUE )
   {
#ifndef NO_OS
//      IFXOS_WakeUp ( ( pDev->WakeupList ), SELREAD );
#endif /*NO_OS */
      pDev->bNeedWakeUp = IFX_FALSE;
   }

   //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Pef24628e_Mpi_RxInt: Frame received.\n\r" ) );

}


/* ============================= */
/* Global function definition    */
/* ============================= */


/**
   Write to device register file.

\param pDev          device structure
\param regadr        register offset
\param val           new register address 

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
IFX_uint32_t Pef24628e_Set_Register ( PEF24628E_DEV_t * pDev,
                                      IFX_uint32_t regadr, IFX_uint32_t val )
{
/*
   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
           ( PREFIX "register[0x%08x + 0x%0x] = 0x%02x.\n\r",
             ( unsigned int ) pDev->uc_reg, ( unsigned int ) regadr, ( unsigned int ) val ) );
*/
   ( *( volatile IFX_uint8_t * )
     ( ( IFX_uint8_t * ) pDev->uc_reg + ( regadr & ( MPI_REG_SIZE - 1 ) ) ) ) = ( IFX_uint8_t ) val;

   return IFX_TRUE;
}

/**
   Read from device register file.

\param pDev       private device data
\param regadr     register offset
\param val        register value

\retval IFX_TRUE  Success
\retval IFX_FALSE in case of error

*/
IFX_uint32_t Pef24628e_Get_Register ( PEF24628E_DEV_t * pDev,
                                      IFX_uint32_t regadr, IFX_uint32_t * val )
{
   *val =
      ( *( volatile IFX_uint8_t * )
        ( ( IFX_uint8_t * ) pDev->uc_reg + ( regadr & ( MPI_REG_SIZE - 1 ) ) ) ) & 0xFF;

   TRACE ( 1, DBG_LEVEL_HIGH,
           (  "register [0x%08x + 0x%0x] = 0x%02x.\n\r",
             ( unsigned int ) pDev->uc_reg, ( unsigned int ) regadr, ( unsigned int ) *val ) );

   return IFX_TRUE;
}

/**   
   Initializes the MPI interface of the specified device and 
   setup the buffer handling.

\param pDev          device structure
\param pDevCfg       configuration for the specified device

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/

IFX_uint8_t g_FifoBuffer[PEF24628E_REC_FIFO_BLK_NUM * PEF24628E_MSG_SIZE];
uint8_t  Tx_Buffer[256];
uint8_t  Rx_Buffer[256];


IFX_uint32_t Pef24628e_MPI_Init ( PEF24628E_DEV_t * pDev, PEF24628E_DEV_INIT_t * pDevCfg )
{
   IFX_uint8_t *ptr;
   IFX_uint32_t i;

   pDev->uc_reg = ( PEF24628E_MPI_REG_t * ) pDevCfg->reg_offset;

   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_MPI_Init failed\n\r" ) );
      return IFX_FALSE;
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Init()\n\r" ) );
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW,
           ( PREFIX "uc_reg 0x%08X\r\n", ( unsigned int ) pDev->uc_reg ) );

   /* Initialize the Receive Fifo */
//   pDev->FifoBuffer =
//      ( IFX_uint8_t * ) IFXOS_MALLOC ( ( PEF24628E_REC_FIFO_BLK_NUM * PEF24628E_MSG_SIZE ) );
   pDev->FifoBuffer = (IFX_uint8_t *)&g_FifoBuffer;
   if ( !pDev->FifoBuffer )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "no memory for RX fifo\n\r" ) );
      return ( IFX_FALSE );
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Initialize the Receive Fifo\n\r" ) );
   ptr = ( IFX_uint8_t * ) pDev->FifoBuffer;

   for ( i = 0; i < PEF24628E_REC_FIFO_BLK_NUM; i++ )
   {
      pDev->RxFifo[i].pData = ptr;
      ptr += PEF24628E_MSG_SIZE;
   }
   pDev->pRxFifoWrite = &pDev->RxFifo[0];
   pDev->pRxFifoRead = &pDev->RxFifo[0];
   pDev->bRxFifoFull = IFX_FALSE;

   /* Initialize the Transmit Fifo */
   pDev->TxFifo.pData =   ( IFX_uint8_t * ) malloc( PEF24628E_MSG_SIZE );
   if ( !pDev->TxFifo.pData )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "no memory for TX fifo\n\r" ) );

      //IFXOS_FREE ( pDev->FifoBuffer );
      return ( IFX_FALSE );
   }

   pDev->TxFifo.nBytes = 0;
   pDev->TxFifo.nSent = 0;

   pDev->TranspData.TxOddEven = 0;
   pDev->TranspData.RxOddEven = -1;

   /********************************************************/
   /* Default Register settings */
   /*******************************************/
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Default Register settings\n\r" ) );

   /* SCI_CFG */
   /* SCI_CFG_H: 0x44 */
   REG_SET ( pDev->uc_reg->SCI_CFG_H, 0x00 | SCI_CFG_H_XCRC | SCI_CFG_H_RAC | SCI_CFG_H_SRA );

   /* SCI_CFG_L: 0x08 */
   REG_SET ( pDev->uc_reg->SCI_CFG_L, 0/*SCI_CFG_L_CLKGAT | SCI_CFG_L_DUPLEX */);

   /* Configure the SCI address */
   /* ACFG0: 0xFF */
   REG_SET ( pDev->uc_reg->SCI_ACFG_0, 0xFF );
   /* ACFG1: 0xFF */
   REG_SET ( pDev->uc_reg->SCI_ACFG_1, 0xFF );
   /* ACFG2: 0xF3 */
   REG_SET ( pDev->uc_reg->SCI_ACFG_2, 0xF3 );
   /* ACFG3: 0x00 */
   REG_SET ( pDev->uc_reg->SCI_ACFG_3, 0x00 );
   
   switch(pDevCfg->sci_clock)
   {
      /*case SCI_CLK_1_4:*/
      case SCI_CLK_1_8:
      case SCI_CLK_1_16:
      case SCI_CLK_1_32:
      case SCI_CLK_1_64:
      /** enable internal SCI clock */
      REG_SET (  pDev->uc_reg->SCI_CLKCFG, SCI_CLK_ENABLE | pDevCfg->sci_clock);      
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Set SCI clock to %d\n\r", pDevCfg->sci_clock) );
      break;
      
      default:
      REG_SET (  pDev->uc_reg->SCI_CLKCFG, SCI_CLK_ENABLE | SCI_CLK_1_64);      
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Set SCI clock to default %d\n\r", SCI_CLK_1_64) );
      break;
   }
   
#ifdef PEF24628E_USE_SCI_MONITOR
   pDev->bSCIMonitor = IFX_FALSE;
#endif

#if 0
   //allen: test for bus
   for(i=0;i<10;i++)
   {
    /* */
      rt_kprintf("try write a5\r\n");
      REG_SET (  pDev->uc_reg->SCI_CLKCFG, 0xA5);
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "read SCI_CLKCFG: %2x\n\r", REG_GET(pDev->uc_reg->SCI_CLKCFG)) );	  
      Delay_100us(2000);
      rt_kprintf("try write 5a\r\n");
      REG_SET (  pDev->uc_reg->SCI_CLKCFG, 0x5A);
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "read SCI_CLKCFG: %2x\n\r", REG_GET(pDev->uc_reg->SCI_CLKCFG)) );	  
      Delay_100us(2000);	  		  
      
      rt_kprintf("try write ff\r\n");
      REG_SET (  pDev->uc_reg->SCI_CLKCFG, 0xff);
	  Delay_100us(100);	  		  
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "read SCI_CLKCFG: %2x\n\r", REG_GET(pDev->uc_reg->SCI_CLKCFG)) );	  
      Delay_100us(2000);	  		  
    /* */
	  rt_kprintf("try write 0\r\n");
      REG_SET (  pDev->uc_reg->SCI_CLKCFG, 0x0);
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "read SCI_CLKCFG: %2x\n\r", REG_GET(pDev->uc_reg->SCI_CLKCFG)) );	  
      Delay_100us(2000);	  	
      
   }
#endif
   /***************************************************/
   /* Default Configuration */
   /***************************************************/

   pDev->bInit = IFX_TRUE;

   pDev->bSendIdcViaSciBridge = IFX_TRUE;

#ifndef NO_OS
//   IFXOS_Init_WakeList ( ( pDev->WakeupList ) );
#endif /*NO_OS */
   pDev->bNeedWakeUp = IFX_TRUE;

//   IFXOS_InitEvent ( pDev->wqTxAck );

   /* Enable SCI interrupts */
   REG_SET ( pDev->uc_reg->MPI_EINT_EN,
             MPI_MPINTEN_SCIEN | MPI_MPINTEN_IDCEN | MPI_MPINTEN_MPILEV );
   REG_SET ( pDev->uc_reg->SCI_INTEN, SCI_INTERRUPT_ALL );
   /* Enable MPI interrupts */

   REG_SET ( pDev->uc_reg->MPI_IINT_EN, MPI_INTERRUPT_ALL );

   /* reset the SCI control */
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "reset the SCI control\n\r" ) );
   REG_SET ( pDev->uc_reg->SCI_CTRL_L, SCI_CTRL_RRES | SCI_CTRL_XRES );

   return ( IFX_TRUE );
}

/**   
   Deinitializes the MPI interface of the specified device and 
   removes the buffer handling.

\param pDev          device structure
\param pDevCfg       configuration for the specified device

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
IFX_uint32_t Pef24628e_MPI_Shutdown ( PEF24628E_DEV_t * pDev )
{
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Shutdown()\n\r" ) );

   /* disable SCI interrupts */
   REG_SET ( pDev->uc_reg->MPI_EINT_EN, 0 );
   REG_SET ( pDev->uc_reg->SCI_INTEN, 0 );

   /* disable MPI interrupts */
   REG_SET ( pDev->uc_reg->MPI_IINT_EN, 0 );

   pDev->bInit = IFX_FALSE;

   /* delete the Receive Fifo */
   if ( pDev->FifoBuffer )
   {
      //IFXOS_FREE ( pDev->FifoBuffer );
   }
   
   /* delete the Transmit Fifo */
   if ( pDev->TxFifo.pData )
   {
      //IFXOS_FREE ( pDev->TxFifo.pData );
   }

   return ( IFX_TRUE );
}

/**   
   Enables address recognition for HDLC frames.

\param pDev          device structure
\param mask          the bits to compare, 0 to switch off
\param addr          value to compare with

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
IFX_boolean_t Pef24628e_Set_Address_Filter ( PEF24628E_DEV_t * pDev, IFX_uint16_t mask,
                                            IFX_uint16_t addr )
{

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW,
           ( _LOGGING_PREFIX "PEF24628E_DEV: Set_Address_Filter Mask = %04X, Addr = %04X\n", mask, addr ) );

   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_Set_Address_Filter failed\n\r" ) );
      return IFX_FALSE;
   }

   /* enables adress recognition */
   REG_SET ( pDev->uc_reg->SCI_ACFG_3, ( mask & 0xFF00 ) >> 8 );
   BFLD ( pDev->uc_reg->SCI_ACFG_1, 0xFC, ( mask & 0x00FF ) );

   REG_SET ( pDev->uc_reg->SCI_ACFG_2, ( addr & 0xFF00 ) >> 8 );
   BFLD ( pDev->uc_reg->SCI_ACFG_0, 0xFC, ( addr & 0x00FF ) );

   return ( IFX_TRUE );
}


/**   
   Get settings of address recognition.

\param pDev          device structure
\param mask          the bits to compare, 0 to switch off
\param addr          value to compare with

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
IFX_boolean_t Pef24628e_Get_Address_Filter ( PEF24628E_DEV_t * pDev, IFX_uint16_t * mask,
                                            IFX_uint16_t * addr )
{
   if ( pDev->uc_reg == IFX_NULL )
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Pef24628e_Get_Address_Filter failed\n\r" ) );
      return IFX_FALSE;
   }

   /* read current address settings from hardware */
   /* mask is used */
   *mask =
      ( ( IFX_uint16_t ) REG_GET ( pDev->uc_reg->SCI_ACFG_3 ) << 8 ) |
      ( REG_GET ( pDev->uc_reg->SCI_ACFG_1 ) & 0xFC );
   *addr =
      ( ( IFX_uint16_t ) REG_GET ( pDev->uc_reg->SCI_ACFG_2 ) << 8 ) |
      ( REG_GET ( pDev->uc_reg->SCI_ACFG_0 ) & 0xFC );

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW,
           ( PREFIX "PEF24628E_DEV: Get_Address_Filter Mask = %04X, Addr = %04X\n", *mask,
             *addr ) );
   return ( IFX_TRUE );
}

#endif /* INCLUDE_MPI */


/**
   Analysis of received SCI frame.
   
\param pDev       device structure

\retval IFX_TRUE  Frame should be processed by upper layer.
\retval IFX_FALSE frame already processed and should be ignored by upper layer.

\remark called on interrupt level

*/
LOCAL IFX_boolean_t Pef24628e_Sci_Process_Frame ( PEF24628E_DEV_t * pDev )
{
   /* process last received message */
   IFX_uint8_t *pData = pDev->pRxFifoWrite->pData;
   IFX_boolean_t bResult = IFX_FALSE;
   IFX_uint8_t code;
   
   /* check destination address */
   if ( pData[1] != PEF24628E_ADR_HOST && pData[1] != 0xFF )
   {
      /* wrong address skip this frame */
	  /*
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( PREFIX "RME: Wrong Host Address: %02X\n\r", pData[1] ) );
              */
      return IFX_FALSE;
   }

   /* check the source address */
   switch ( pData[0] & 0xF )
   {
   case PEF24628E_ADR_PAMDSL_0:
   case PEF24628E_ADR_PAMDSL_1:
   case PEF24628E_ADR_PAMDSL_2:
   case PEF24628E_ADR_PAMDSL_3:
      /* do not accept messages received from the PAMDSL */
      break;

   case PEF24628E_ADR_RAMSHELL:
   case PEF24628E_ADR_AUX:
   case PEF24628E_ADR_IDC_RAMSHELL:
      /* Process RS and AUX acks */
      if ( ( pData[2] & 0xF0 ) != PEF24628E_VALID_RSTA )
      {
         pDev->txErr = IFX_TRUE;
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "RME: AUX/RAMSHELL ACK - FAILED (err = %02x)\n\r", (pData[2] & 0xF0) ) );
      }
      else
      {
         pDev->txErr = IFX_FALSE;

         if ( ( pData[0] & 0xF ) == PEF24628E_ADR_AUX )
         {
            if ( pDev->pRxFifoWrite->nBytes >= 4 )
               pDev->last_aux_value = pData[3] & 0x000000FF;
            else
               pDev->last_aux_value = 0;
         }

         if ( pDev->pRxFifoWrite->nBytes > 6 )
         {
            /* store CRC */
            /* get from little endian to host */
            pDev->last_rs_value = pData[3]
               | ( pData[4] << 8 ) | ( pData[5] << 16 ) | ( pData[6] << 24 );
			//ALLEN
			/*
			LOG ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
                    ( PREFIX "RME: CRC = %08X\r\n", ( unsigned int ) pDev->last_rs_value ) );
                    */
         }

         //LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "RME: AUX/RAMSHELL ACK - OK, length = %u\n\r", pDev->pRxFifoWrite->nBytes ) );
      }
      pDev->bTxAckReceived = IFX_TRUE;
      break;

   case PEF24628E_ADR_IDC_CTRLR:
      /* process low level protocol */
      LOG ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
              ( PREFIX "TP HEADER: %02X\n\r", PEF24628E_TP_GET_HEADER ( pData[2], pData[3] ) ) );
      LOG ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
              ( PREFIX "TP LEN: %d\n\r", pDev->pRxFifoWrite->nBytes ) );

      code = pData[3];

      switch ( PEF24628E_TP_GET_HEADER ( pData[2], ( pData[3] & ~0x0F ) ) )
      {
      case PEF24628E_TP_ACK_MSG:
      case PEF24628E_TP_NFC_MSG:
         /* send TP ACK to the Soc-4e */
         /* if (nLength<=8) ACK msg have a length of 8 bytes --> allow 8 */
         if ( pDev->pRxFifoWrite->nBytes < 8 )
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( PREFIX "RME: Send TP NAK - msg too short (<8)\n\r" ) );

            /* send "Not Acknowledge" */
#ifdef INCLUDE_SCC_HDLC
            if (( pDev->bFwStarted == IFX_TRUE ) && (pDev->ActiveIf == PEF24628E_IF_SCI)) {
               pDev->bSendTpAck = IFX_TRUE;
               pDev->TpAckNak   = IFX_TRUE;
               pDev->TpAckOdd   = (pData[2] & 0x01 );
            } else {
#endif
            /* don't care about bResult here, becasue it's anyway IFX_FALSE */
            Pef24628e_Send_TP_Ack ( pDev, ( pData[2] & 0x01 ), IFX_TRUE );
#ifdef INCLUDE_SCC_HDLC
            }
#endif
         }
         else
         {
#ifdef INCLUDE_SCC_HDLC
            if (( pDev->bFwStarted == IFX_TRUE ) && (pDev->ActiveIf == PEF24628E_IF_SCI)) {
               pDev->bSendTpAck = IFX_TRUE;
               pDev->TpAckNak   = IFX_FALSE;
               pDev->TpAckOdd   = (pData[2] & 0x01 );
               /* don't forward to upper layer if same even-odd bit is received*/
               if ( pDev->TranspData.RxOddEven != pDev->TpAckOdd ) {              
               bResult = IFX_TRUE;
               }
            } else {
#endif
            bResult = Pef24628e_Send_TP_Ack ( pDev, ( pData[2] & 0x01 ), IFX_FALSE );
#ifdef INCLUDE_SCC_HDLC
            }
#endif
         }
         break;

      case PEF24628E_TP_POS_ACK:
         /* we sent command successfuly */
         /* stop retransmission */
         LOG ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "RME: TP ACK - POS\n\r" ) );
         pDev->txErr = IFX_FALSE;
         pDev->bTxAckReceived = IFX_TRUE;
         pDev->TranspData.TxLastAckOddEven = ( pData[2] & 0x01 );
         break;

      case PEF24628E_TP_NEG_ACK:
         /* check the reason  */
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "RME: TP ACK - NEG\n\r" ) );

         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "RME:%02x %02x\n", pData[0], pData[1] ) );
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "RME:%02x %02x\n", pData[2], pData[3] ) );

         if ( ( code & 0x0F ) == 0x01 )
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "1byte message\n\r" ) );
         if ( ( code & 0x0F ) == 0x02 )
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( PREFIX "Not a message header (bit 31 set)\n\r" ) );
         if ( ( code & 0x0F ) == 0x03 )
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Invalid payload length \n\r" ) );
         if ( ( code & 0x0F ) == 0x04 )
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Error status %x \n", code & 0xF0 ) );

         /* retransmit last frame */
         pDev->txErr = IFX_TRUE;
         pDev->bTxAckReceived = IFX_TRUE;
         break;

      case PEF24628E_TP_RES_ACK:
         /* reset TP */
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "RME: TP - RESET\n\r" ) );
         pDev->TranspData.TxOddEven = 0;
         pDev->TranspData.RxOddEven = -1;
         break;

      default:
         /* unknown TP header */
         /* skip it */
         LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "RME: TP - Unknown header\n\r" ) );
         break;
      }
      break;

   default:
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( PREFIX "RME: Unknown HDLC source: %02X\n", pData[0] & 0xF ) );
   }

   return bResult;
}

/**
   Set the interface mode of the device.

\param pDev       private device data
\param new_if     Interface to use

\retval IFX_TRUE  Success
\retval IFX_FALSE in case of error

*/
IFX_uint32_t Pef24628e_Set_If ( PEF24628E_DEV_t * pDev, PEF24628E_IF_t new_if )
{
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Set_If %02x.\n\r", ( unsigned int ) new_if ) );

   if ( new_if < PEF24628E_IF_LAST )
   {
      pDev->ActiveIf = new_if;
   }
   else
   {

      return IFX_FALSE;
   }

   /* disable interrupts for the unused interface */
   switch ( new_if )
   {
   case PEF24628E_IF_MPI:
      /*BFLD(pDev->uc_reg->MPI_EINT_EN, MPI_MPINTEN_SCIEN|MPI_MPINTEN_IDCEN, MPI_MPINTEN_IDCEN); */
      break;
   case PEF24628E_IF_SCI:
      /*BFLD(pDev->uc_reg->MPI_EINT_EN, MPI_MPINTEN_SCIEN|MPI_MPINTEN_IDCEN, MPI_MPINTEN_SCIEN); */
      break;
   default:
      break;
   }

   return IFX_TRUE;
}

/**
   Report the currently used interface to the IDC.

\param pDev          private device data
\param current_if    pointer to Interface in use

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
IFX_uint32_t Pef24628e_Get_If ( PEF24628E_DEV_t * pDev, PEF24628E_IF_t * current_if )
{
   //TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Get_If %02x.\n\r", pDev->ActiveIf ) );

   if ( current_if != NULL )
      *current_if = pDev->ActiveIf;
   else
      return IFX_FALSE;

   return IFX_TRUE;
}


#ifdef INCLUDE_SCC_HDLC
/**   
   Initializes the SCC interface of the specified device and 
   setup the buffer handling.

\param pDev          device structure
\param pDevCfg       configuration for the specified device

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

\remark
   Not available for NO_OS.

*/
IFX_uint32_t Pef24628e_SCC_Init ( PEF24628E_DEV_t * pDev, PEF24628E_DEV_INIT_t * pDevCfg )
{
#ifndef NO_OS
   IFX_uint8_t *ptr;
   IFX_uint32_t i;
   IFX_uint8_t hdlc_cfg[6];

   if ( pDev->bInit )
      return ( IFX_FALSE );

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Init()\n\r" ) );

   IFXOS_Init_WakeList ( ( pDev->WakeupList ) );
   pDev->bNeedWakeUp = IFX_TRUE;

   IFXOS_InitEvent ( pDev->wqTxAck );

   /* open hdlc device if needed */
   if(pSciHdlcDev[pDev->nSciHdlcDev] == IFX_NULL)
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "initialize HDLC channel %d\n\r", pDev->nSciHdlcDev ) );
      pSciHdlcDev[pDev->nSciHdlcDev] = Scc_Hdlc_Open_Kernel ( pDev->nSciHdlcDev );
	
   	if(pSciHdlcDev[pDev->nSciHdlcDev] == IFX_NULL)
   	{
	      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "cannot access HDLC channel %d\n\r", pDev->nSciHdlcDev ) );
			return ( IFX_FALSE );
		}

      /* Init clock and set baudrate */
      Scc_Hdlc_Clock_Init ( pSciHdlcDev[pDev->nSciHdlcDev], 2 );
      Scc_Hdlc_Set_Baudrate ( pSciHdlcDev[pDev->nSciHdlcDev], pDevCfg->sci_clock );

      /* install callback */
      Scc_Hdlc_Install_Callback( pSciHdlcDev[pDev->nSciHdlcDev], (IFX_void_t *)Pef24628e_CB_SCC_Msg );
   
      hdlc_cfg[0] = 0;     /* tci */
      hdlc_cfg[1] = 1;     /* rte */ /* TOM: changed from 0 */
      hdlc_cfg[2] = 0;     /* drt */
      hdlc_cfg[3] = 1;     /* bus */ /* TOM: changed from 0 */
      hdlc_cfg[4] = 0;     /* open_drain */
      hdlc_cfg[5] = 1;     /* crc */

      Scc_Hdlc_Set_Config ( pSciHdlcDev[pDev->nSciHdlcDev], ( IFX_void_t * ) & hdlc_cfg[0] );
      Scc_Hdlc_Set_Address_Filter ( pSciHdlcDev[pDev->nSciHdlcDev], 0xFF << 8, PEF24628E_ADR_HOST << 8 );
   }
   else
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "HDLC channel %d already intialized\n\r", pDev->nSciHdlcDev ) );
   }
   
   if ( pSciHdlcDev[pDev->nSciHdlcDev] == IFX_NULL )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Scc_Hdlc_Open_Kernel failed\n\r" ) );
      return IFX_FALSE;
   }

   pDev->bFwStarted = IFX_FALSE;
   
   SciHdlcDevCount[pDev->nSciHdlcDev]++;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "scc_fd %d\n\r", ( int ) pDev->scc_fd ) );

   /* Initialize the Receive Fifo */
   pDev->FifoBuffer =
      ( IFX_uint8_t * ) IFXOS_MALLOC ( ( PEF24628E_REC_FIFO_BLK_NUM * PEF24628E_MSG_SIZE ) );
   if ( !pDev->FifoBuffer )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "no memory for RX fifo\n\r" ) );
      return ( IFX_FALSE );
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Initialize the Receive Fifo\n\r" ) );
   ptr = ( IFX_uint8_t * ) pDev->FifoBuffer;

   for ( i = 0; i < PEF24628E_REC_FIFO_BLK_NUM; i++ )
   {
      pDev->RxFifo[i].pData = ptr;
      pDev->RxFifo[i].nIndex = i;
      ptr += PEF24628E_MSG_SIZE;
   }
   pDev->pRxFifoWrite = &pDev->RxFifo[0];
   pDev->pRxFifoRead = &pDev->RxFifo[0];
   pDev->bRxFifoFull = IFX_FALSE;

   /* Initialize the Transmit Fifo */
   pDev->TxFifo.pData =
      ( IFX_uint8_t * ) IFXOS_MALLOC ( PEF24628E_MSG_SIZE );
   if ( !pDev->TxFifo.pData )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "no memory for TX fifo\n\r" ) );

      //IFXOS_FREE ( pDev->FifoBuffer );
      return ( IFX_FALSE );
   }

   pDev->TxFifo.nBytes = 0;
   pDev->TxFifo.nSent = 0;

   pDev->TranspData.TxOddEven = 0;
   pDev->TranspData.RxOddEven = -1;

   pDev->bInit = IFX_TRUE;
   pDev->bSendIdcViaSciBridge = IFX_TRUE;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Initialization complete.\n\r" ) );
#endif

   return ( IFX_TRUE );
}
#endif /* INCLUDE_SCC_HDLC */

/**   
   Initializes the active interface and setup the buffer handling
   of the specified device.

\param pDev          device structure
\param pDevCfg       configuration for the specified device

\retval IFX_TRUE     Success
\retval IFX_FALSE    In case of error.

*/
IFX_boolean_t Pef24628e_Init ( PEF24628E_DEV_t * pDev, PEF24628E_DEV_INIT_t * pDevCfg )
{
   IFX_uint32_t ret = IFX_FALSE;

   if ( pDev->ActiveIf >= PEF24628E_IF_LAST )
      return ( IFX_FALSE );

   pDev->bRxFifoFull   = IFX_FALSE;
   pDev->uStatistics   = 0;
   pDev->uLastCmdId    = 0;
   pDev->uLastAckId    = 0;

   pDev->bFwDownloaded = IFX_FALSE;

#ifdef INCLUDE_SCC_HDLC
   if ((pDev->uc_index + 1) > SCC_HDLC_MAX_CHANNELS )
   {
	   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "Scc hdlc channed %u not supported\n\r", (pDev->uc_index + 1)  ) );
      return (IFX_FALSE);
   }
   
   pDev->nSciHdlcDev = 1;
#endif

   switch ( pDev->ActiveIf )
   {
   case PEF24628E_IF_MPI:
#ifdef INCLUDE_MPI
      pDev->nDevAddress = 0x0F;
      ret = Pef24628e_MPI_Init ( pDev, pDevCfg );
#else      
	   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "MPI interface not supported\n\r" ) );
#endif
      break;

   case PEF24628E_IF_SCI:
#ifdef INCLUDE_SCC_HDLC
		pDev->nDevAddress = pDevCfg->sci_device_address;
      ret = Pef24628e_SCC_Init ( pDev, pDevCfg );
#else
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "SCI interface not supported\n\r" ) );
#endif
      break;

   default:
	   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "unknown interface not supported\n\r" ) );
       break;
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "exit initialization\n\r" ) );

   return ( ret ? IFX_TRUE : IFX_FALSE );
}

#ifdef INCLUDE_SCC_HDLC
IFX_boolean_t Pef24628e_SCC_Shutdown ( PEF24628E_DEV_t * pDev )
{
   if ( pSciHdlcDev[pDev->nSciHdlcDev] )
   {
      SciHdlcDevCount[pDev->nSciHdlcDev]--;
      if(SciHdlcDevCount[pDev->nSciHdlcDev] == 0)
      {
         Scc_Hdlc_Close_Kernel ( pSciHdlcDev[pDev->nSciHdlcDev] );
         pSciHdlcDev[pDev->nSciHdlcDev] = IFX_NULL;
      }
   }
   return IFX_TRUE;
}
#endif /* INCLUDE_SCC_HDLC */

/**   
   Shutdown device

\param pDev    device structure

\retval IFX_TRUE     Success
\retval IFX_FALSE    In case of error.

*/
IFX_boolean_t Pef24628e_Shutdown ( PEF24628E_DEV_t * pDev )
{
   IFX_boolean_t ret = IFX_FALSE;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "device shutdown\n\r" ) );
   if ( pDev->ActiveIf >= PEF24628E_IF_LAST )
      return ( IFX_FALSE );

   switch ( pDev->ActiveIf )
   {
#ifdef INCLUDE_MPI
   case PEF24628E_IF_MPI:
      ret = Pef24628e_MPI_Shutdown( pDev );
      break;
#endif

#ifdef INCLUDE_SCC_HDLC
   case PEF24628E_IF_SCI:
      ret = Pef24628e_SCC_Shutdown ( pDev );
      break;
#endif

   default:
      ret = IFX_FALSE;
      break;
   }

   return ( ret );
}

#ifdef INCLUDE_SCC_HDLC
/**   
   Sends a frame to SCI interface (\ref Scc_Hdlc_Send_Frame). 

\param pDev       device structure
\param pSrc       pointer to frame
\param nLength    size of frame

\retval -1        in case of error  
\retval >=0       number of bytes transmitted

*/
LOCAL IFX_int32_t Pef24628e_Send_SCC_Msg ( PEF24628E_DEV_t * pDev, IFX_void_t * pSCC_HDLC_Dev, IFX_uint8_t * pBuf,
                                     IFX_int32_t nLength )
{
   IFX_int32_t len = 0, counter;

   pDev->txErr = IFX_TRUE;
   pDev->bTxAckReceived = IFX_FALSE;
   /* write message */
   len = Scc_Hdlc_Send_Frame ( pSCC_HDLC_Dev, pBuf, nLength );
   if ( len != nLength )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
            ( PREFIX "Unable to write IDC message (%d)\n\r", ( int ) len ) );
      return ( -1 );
   }

   for (counter = 10000; (counter > 0) && ( !pDev->bTxAckReceived ); --counter)
   {
      IFXOS_DELAYUS ( 100 );
      Pef24628e_Get_SCC_Msg( pDev, pSCC_HDLC_Dev );
   }

   if ( counter == 0 )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Pef24628e_Send_SCC_Msg: ACK missing\n\r" ) );
      return -1;
   }

   return len;
}

LOCAL IFX_int32_t Pef24628e_Get_SCC_Msg ( PEF24628E_DEV_t * pDev, IFX_void_t * pSCC_HDLC_Dev )
{
   IFX_int32_t len = 0;
   IFX_uint8_t *pData;
   IFX_uint8_t nIndex;

   while ( Scc_Hdlc_Filtered_Poll_Check ( pSCC_HDLC_Dev, pDev->nDevAddress ) == IFX_TRUE )
   {
      pData = pDev->pRxFifoWrite->pData + pDev->pRxFifoWrite->nBytes;

      nIndex = pDev->pRxFifoWrite->nIndex;

      TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "SCC[%02d]: frame available\n\r", nIndex ) );

      /* read acknowledge, return immediately if returned length is <=0 */
      if ( ( len = Scc_Hdlc_Get_Frame ( pSCC_HDLC_Dev, pData, PEF24628E_MSG_SIZE ) ) <= 0 )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "SCC[%02d]: Unable to read SCC HDLC acknowledge (%d)\n\r", 
                     nIndex, ( int ) len ) );
         return ( -1 );
      }

      pDev->pRxFifoWrite->bSendIdcViaSciBridge = IFX_TRUE;

      pDev->pRxFifoWrite->nBytes += ( IFX_uint16_t ) len;

      TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
              ( PREFIX "SCC[%02d]: total length = %d, nBytes %d\n\r", nIndex, ( int ) len,
                pDev->pRxFifoWrite->nBytes ) );

      /* Analyze acknowledge */
      if ( Pef24628e_Sci_Process_Frame ( pDev ) == IFX_TRUE )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW,
             ( PREFIX "SCC[%02d]: frame should be processed by upper layer, %d bytes\n\r", 
                        nIndex, pDev->pRxFifoWrite->nBytes) );

         /* no errors -> switch to the next Rx FIFO block */
         pDev->pRxFifoWrite++;

         /* check for space in fifo */
         if ( pDev->pRxFifoWrite >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
            pDev->pRxFifoWrite = &pDev->RxFifo[0];

         pDev->SciRxState = SCI_RX_IDLE;

         /* Data frame -> store it in the FIFO and notify upper layer */
         pDev->pRxFifoWrite->nBytes = 0;

         TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "SCC[%02d]: next buffer\n\r", 
               pDev->pRxFifoWrite->nIndex) );
      }
      else
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, 
            ( PREFIX "SCC[%02d]: frame already processed, should be ignored by upper layers\n\r", nIndex) );
         pDev->pRxFifoWrite->nBytes = 0;
      }
   }

   return len;
}

#endif /* INCLUDE_SCC_HDLC*/

/**   
   Sends a frame to currenty active interface, MPI or SCI.

\param pDev       device structure
\param pSrc       pointer to frame
\param nLength    size of frame

\retval -1        in case of error  
\retval >=0       number of bytes transmitted

\remarks
   Main Transmission is done in Pef24628e_Sci_XprInt routine.
*/
void dump_reg(PEF24628E_DEV_t * pDev);

extern unsigned int g_pefdump;

IFX_int32_t Pef24628e_Send_IDC_Msg ( PEF24628E_DEV_t * pDev, const IFX_uint8_t * pSrc,
                                     IFX_int32_t nLength )
{
   int repetitions = 0;
#ifdef INCLUDE_MPI
   IFX_int32_t i,j;
#endif
#if 1
   //char msg_dump_buf[PEF24628E_MSG_SIZE*3 + 1];
   char msg_dump_buf[5];
#endif
   if ( nLength == 0 )
      return ( -1 );

   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
      return ( -1 );

#if 0
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW,
           ( PREFIX "Pef24628e_Send_IDC_Msg(%d)\n\r", ( int ) nLength ) );
#endif

   /* message must fit completly into the buffer */
   if ( nLength > PEF24628E_MSG_SIZE )
      return ( -1 );

   if ( pDev->bSendIdcViaSciBridge )
   {
      /* copy message and leave some room for the header and transport layer protocol */
      memcpy ( ( void * ) ( pDev->TxFifo.pData + 4 ), ( void * ) pSrc, ( IFX_uint32_t ) nLength );

      /* set some fixed values of message header */
      *( pDev->TxFifo.pData + 0 ) = PEF24628E_ADR_HOST;
      *( pDev->TxFifo.pData + 1 ) = PEF24628E_ADR_DEVICE(pDev->nDevAddress) | PEF24628E_ADR_IDC_CTRLR;
      /* add transport layer protocol header */
      *( pDev->TxFifo.pData + 2 ) = 0x08 | pDev->TranspData.TxOddEven;
      *( pDev->TxFifo.pData + 3 ) = 0;
      nLength += 4;

      pDev->TranspData.TxLastAckOddEven = -1;
   }
   else
   {
      memcpy ( ( void * ) pDev->TxFifo.pData, ( void * ) pSrc, ( IFX_uint32_t ) nLength );
   }

#if 1
if(g_pefdump)
{
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW,
           ( PREFIX "Pef24628e_Send_IDC_Msg(%d): \n\r", ( int ) nLength ) );
   /* Dump IDC message */
#if 0
   for ( i = 0; i < nLength; i++ )
   {
      sprintf(&msg_dump_buf[i*3], "%02X ", pDev->TxFifo.pData[i]);
   }
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "%s\n\r", msg_dump_buf) );
#else
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "[00]:") );   
   for ( i = 0; i < nLength; i++ )
   {
      sprintf(&msg_dump_buf[0], "%02X ", pDev->TxFifo.pData[i]);
      msg_dump_buf[4]=0x0;
      TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "%s", msg_dump_buf) );
      if(i%16==15)
      {
        TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\r\n") );  
        if(i<nLength-1)
            TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "[%02X]:",16*(i/16+1)) );   
      }
   }
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\r\n") );  
#endif
}
#endif

#ifdef INCLUDE_SCC_HDLC
   if ( pDev->ActiveIf == PEF24628E_IF_SCI )
   {  
      /* state maschine of transport layer */
      for ( repetitions = 0; repetitions < SEND_MSG_MAX_REP_NUMBER; ++repetitions)
      {
         IFXOS_ClearEvent ( pDev->wqTxAck );

         pDev->TxFifo.nBytes = nLength;
         pDev->TxFifo.nSent = 0;
         pDev->txErr = IFX_TRUE;

         if ( Scc_Hdlc_Send_Frame ( pSciHdlcDev[pDev->nSciHdlcDev], 
                        ( IFX_uint8_t * ) ( pDev->TxFifo.pData ),
                        ( IFX_int32_t ) nLength ) != nLength )
         {
            TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "Unable to write IDC message\n\r" ) );
            continue;
         }
         
         /* block the caller until ack is received */
         if ( IFXOS_WaitEvent_timeout ( pDev->wqTxAck, 5000 ) == IFX_ERROR )
         {
            TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( ERR_PREFIX "Pef24628e_Send_IDC_Msg timed out\n\r" ) );
         }

         if (( pDev->txErr == IFX_FALSE ) &&
             ( pDev->TranspData.TxLastAckOddEven == pDev->TranspData.TxOddEven ))
         {
            break;
         }
      }

      /* toggle OddEven flag for next message*/
      pDev->TranspData.TxOddEven ^= 1;

      if ( repetitions == SEND_MSG_MAX_REP_NUMBER )
      {
          TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Unable to send IDC message %d bytes\n\r", ( int ) nLength ) );
              return IFX_FALSE;
      }
      else
      {
          return ( nLength - 4 );
      }
   }
#endif /* INCLUDE_SCC_HDLC */

#ifdef INCLUDE_MPI
   repetitions = 0;

   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      do
      {
         //IFXOS_ClearEvent ( pDev->wqTxAck );

         pDev->TxFifo.nBytes = nLength;
         pDev->TxFifo.nSent = 0;
         pDev->txErr = IFX_TRUE;

         if ( pDev->bSendIdcViaSciBridge )
         {
            if ( repetitions )
            {
               TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "retry = %d\n\r", repetitions ) );
            }

            if ( pDev->irq_vector == 0 )
            {
               /* polling mode */
               Pef24628e_Sci_Tx_Polling ( pDev );
            }
            else
            {
               Pef24628e_Sci_XprInt ( pDev );
#if 0
               /* block the caller until ack is received */
               if ( IFXOS_WaitEvent_timeout ( pDev->wqTxAck, 1000 ) == IFX_ERROR )
               {
                  TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                          ( ERR_PREFIX "Pef24628e_Send_IDC_Msg timed out\n\r" ) );
               }
#endif							 
            }

            if ( pDev->txErr )
            {
      
							TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                       ( ERR_PREFIX "Message sent, errors = %d\n\r", pDev->txErr ) );							
               /* the transmission failed and has to be repeated */
               repetitions++;
               if ( repetitions > SEND_MSG_MAX_REP_NUMBER )
               {
                  TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                          ( ERR_PREFIX "Too many repetitions, sending IDC message discarded.\n\r" ) );
                  /* Dump IDC message */
				  #if 0
				  for ( i = 0; i < nLength; i++ )
                  {
                     TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( _LOGGING_PREFIX "%02X ", pDev->TxFifo.pData[i] ) );
                  }
                  TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( _LOGGING_PREFIX "\n\r" ) );
				  #endif
				  break;
               }
            }

            if ( pDev->TranspData.TxLastAckOddEven == pDev->TranspData.TxOddEven )
            {
               /* Pos. Ack. with same Odd/Even bit was received! */
               /* toggle odd/even bit */
               pDev->TranspData.TxOddEven ^= 1;
               /*break; */
            }
         }
         else
         {
            Pef24628e_Mpi_Tx ( pDev );
            if ( pDev->txErr )
            {
               repetitions++;
               if (repetitions >= SEND_MSG_MAX_REP_NUMBER)
               {
                  if ( ( REG_GET ( pDev->uc_reg->MPI_IINT_EN ) == 0 ))
                  {
                     TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "FW not loaded, driver not initialzed after reset\n\r" ) );
                  }
                  else
                  {
                     TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "FW not responding\n\r" ) );
                  }
                  return IFX_FALSE;
               }
            }

         }

      } while ( pDev->txErr );

	  //allen
      //TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,( PREFIX "Pef24628e_Send_IDC_Msg: sent %d bytes\n\r", ( int ) nLength ) );

      if ( pDev->bSendIdcViaSciBridge )
      {
         return (nLength - 4);
      }
      else
      {
         return nLength;
      }
   }
#endif /* INCLUDE_MPI */

   return 0;      
}

/**   
   Reads frame from receive FIFO. This might be a frame received via SCI or MPI.

\param pDev       device structure
\param pDst       pointer to frame buffer
\param nLength    maximal buffer size

\retval -1        in case of error  
\retval >=0       number of bytes transmitted

\remarks
   If frame is bigger than buffer, the rest discarded.
*/
IFX_int32_t Pef24628e_Get_IDC_Msg ( PEF24628E_DEV_t * pDev, IFX_uint8_t * pDst,
                                    IFX_int32_t nLength )
{
   IFX_uint16_t nBytes = 0;
#if 1
   IFX_uint16_t i;
   //char msg_dump_buf[PEF24628E_MSG_SIZE*3 + 1];
   char msg_dump_buf[5];
#endif

   //rt_kprintf("try read2\r\n");	
   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
      return ( -1 );

   //TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "Pef24628e_Get_IDC_Msg: Retreiving frame\n\r" ) );

   //allen
   //dump_reg(pDev);
   
   if ( (pDev->pRxFifoWrite != pDev->pRxFifoRead) ||
        (pDev->bRxFifoFull == IFX_TRUE) )
   {
      nBytes = pDev->pRxFifoRead->nBytes;
//allen
#if 1
if(g_pefdump)
{
      TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, 
         ( PREFIX "Pef24628e_Get_IDC_Msg[%02d] %d bytes: ", pDev->pRxFifoRead->nIndex, nBytes ) );
#if 0
      for ( i = 0; i < nBytes; i++ )
         sprintf (&msg_dump_buf[i*3], "%02X ", pDev->pRxFifoRead->pData[i] ) ;
      TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "%s\n\r", msg_dump_buf ) );
#else
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\r\n[00]:") );   
   for ( i = 0; i < nBytes; i++ )
   {
      sprintf(&msg_dump_buf[0], "%02X ", pDev->pRxFifoRead->pData[i]);
      msg_dump_buf[4]=0x0;
      TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "%s", msg_dump_buf) );
      if(i%16==15)
      {
        TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\r\n") );  
        if(i<nBytes-1)
            TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "[%02X]:",16*(i/16+1)) );   
      }
   }
   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "\r\n") );  
#endif
}
#endif

      /* Definition of read policy: If frame is bigger than buffer, discard the 
         rest of it! */
      if ( nBytes > nLength )
         nBytes = nLength;

#if defined (INCLUDE_MPI) && defined(PEF24628E_USE_SCI_MONITOR)
      if ( pDev->bSCIMonitor )
      {

         if ( nBytes > 4 )
         {

            if ( ( *( pDev->pRxFifoRead->pData + nBytes - 1 ) == PEF24628E_SCI_MONITOR_DATA ) ||
                 ( !( pDev->pRxFifoRead->bSendIdcViaSciBridge ) ) )
            {
               /* Copy whole frame */
               memcpy ( ( void * ) pDst, ( void * ) ( pDev->pRxFifoRead->pData ),
                        ( IFX_uint32_t ) nBytes );
            }
            else
            {
               if ( nBytes > 4 )
               {
                  /* Skip HDLC addresses and Transport protocol */
                  nBytes -= 4;
                  memcpy ( ( void * ) pDst, ( void * ) ( pDev->pRxFifoRead->pData + 4 ),
                           ( IFX_uint32_t ) nBytes );
               }
            }

         }      /* nBytes > 4 */

      }
      else      /* SCI Monitor */
#endif /* INCLUDE_MPI && PEF24628E_USE_SCI_MONITOR */

      if ( pDev->pRxFifoRead->bSendIdcViaSciBridge )
      {

         if ( nBytes > 4 )
         {
            /* Skip HDLC addresses and Transport protocol */
            nBytes -= 4;
            memcpy ( ( void * ) pDst, ( void * ) ( pDev->pRxFifoRead->pData + 4 ),
                     ( IFX_uint32_t ) nBytes );
         }
      }
      else
      {
         memcpy ( ( void * ) pDst, ( void * ) ( pDev->pRxFifoRead->pData ),
                  ( IFX_uint32_t ) nBytes );
      }

      pDev->pRxFifoRead->nBytes = 0;

      pDev->pRxFifoRead++;

      if ( pDev->pRxFifoRead >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
         pDev->pRxFifoRead = &pDev->RxFifo[0];
   }

#ifdef INCLUDE_MPI
   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      if ( pDev->bSendIdcViaSciBridge )
         /* make sure that interrupts are enabled! */
         BFLD ( pDev->uc_reg->SCI_INTEN, SCI_INTERRUPT_RPF | SCI_INTERRUPT_RME,
                SCI_INTERRUPT_RPF | SCI_INTERRUPT_RME );
      else
      {
         if( (REG_GET(pDev->uc_reg->MPI_EINT_EN) & MPI_INTERRUPT_R) == 0x00 )
         {
            /* FIXME: MPI_IINT_EN is changed to MPI_EINT_EN,
               because EGRESS interrupts should be enabled for message reception instead of INGRESS. */
           BFLD ( pDev->uc_reg->MPI_EINT_EN/*MPI_IINT_EN*/, MPI_INTERRUPT_R, MPI_INTERRUPT_R );
         }
      }
   }
#endif /* INCLUDE_MPI */

#if 0
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
           ( PREFIX "Pef24628e_Get_IDC_Msg: received %d bytes\n\r", nBytes ) );
#endif
   return nBytes;
}

/**   
   Check receive FIFO for available data.
   In case of in MPI interface mode ussage the interrupt 
   handler Pef24628e_IntHandler will be called if the 
   device is in polling mode.

\param pDev          device structure

\retval IFX_FALSE    if upstream FIFO is empty
\retval IFX_TRUE     if upstream FIFO has data

*/
IFX_boolean_t Pef24628e_Poll_Check ( PEF24628E_DEV_t * pDev )
{
   IFX_boolean_t ret = IFX_FALSE;

   //if(g_debug)
   //		rt_kprintf("\r\n vvvvvv Pef24628e_Poll_Check vvvvvv\r\n");
   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
      return ( IFX_FALSE );

   switch ( pDev->ActiveIf )
   {
      case PEF24628E_IF_SCI:
#ifdef INCLUDE_SCC_HDLC
      if ( pDev->bSendTpAck == IFX_TRUE ) {
         if ( Pef24628e_Send_TP_Ack ( pDev,pDev->TpAckOdd, pDev->TpAckNak ) == IFX_FALSE )
         {
            return IFX_FALSE;
         }
         
         pDev->bSendTpAck = IFX_FALSE;
         pDev->TpAckNak   = IFX_FALSE;
         pDev->TpAckOdd   = 0;
      }
      if ( pDev->bFwStarted == IFX_FALSE ) return IFX_FALSE;
      
      Pef24628e_Get_SCC_Msg( pDev, pSciHdlcDev[pDev->nSciHdlcDev] );
      
      break;
#else
   	LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
           ( ERR_PREFIX "SCI interface not supported\n\r" ) );
		return IFX_FALSE;      
#endif /* INCLUDE_SCC_HDLC */

      case PEF24628E_IF_MPI:
#ifdef INCLUDE_MPI
      if ( pDev->irq_vector == 0 )
      {
         //if(g_debug)
		 //	dump_reg(pDev);
         Pef24628e_IntHandler ( pDev );
      }
      break;      
#else
   	LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
           ( ERR_PREFIX "MPI interface not supported\n\r" ) );
		return IFX_FALSE;      
#endif /* INCLUDE_MPI */

        default:
        break;
   }
   
   if( (pDev->pRxFifoRead != pDev->pRxFifoWrite) ||
       (pDev->bRxFifoFull == IFX_TRUE) )
      ret = IFX_TRUE;
   else
      ret = IFX_FALSE;

   if ( ret == IFX_FALSE )
      pDev->bNeedWakeUp = IFX_TRUE;

   //if(g_debug)
   // 	rt_kprintf("^^^^^^ Pef24628e_Poll_Check ^^^^^^\r\n\r\n");
   return ret;
}


/**   
   Set configuration.

\param pDev       device structure
\param pConfig    pointer to configuration structure

*/
IFX_void_t Pef24628e_Set_Config ( PEF24628E_DEV_t * pDev, PEF24628E_CONFIG_t * pConfig )
{
   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
      return;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "SetConfig()\n\r" ) );
}

/**   
   Retrieve configuration.

\param pDev          device structure
\param pConfig       pointer to configuration structure

*/
IFX_void_t Pef24628e_Get_Config ( PEF24628E_DEV_t * pDev, PEF24628E_CONFIG_t * pConfig )
{
   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
      return;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "GetConfig()\n\r" ) );
}

/**
   Creates a RAMSHELL message from parameters and sends it to SCI.
   Only used for firmware download.

\param pDev          device structure
\param opcd          operation code of ramshell message
\param param         ramshell parameter
\param pSrc          pointer to additional data
\param nLength       length of additional data

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

\remarks
   Checking for ack will discard all unknown messages.
   This is only useful during startup/before active firmware.
*/
LOCAL IFX_boolean_t Pef24628e_Send_RS_Msg ( PEF24628E_DEV_t * pDev,
                                             IFX_uint8_t opcd,
                                             IFX_uint32_t param,
                                             IFX_uint8_t * pSrc, IFX_uint16_t nLength )
{
#if PEF24628E_FW_IS_BE == 1
   IFX_int16_t i;
   IFX_uint8_t *pSrc8 = pSrc; 
#endif

#ifdef INCLUDE_SCC_HDLC
   IFX_int32_t len = 0;
#endif /* INCLUDE_SCC_HDLC */

   IFX_int32_t retry = 3;

   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
      return IFX_FALSE;

/*   TRACE (PEF24628E_DRV, DBG_LEVEL_HIGH,
          (PREFIX "Pef24628e_Send_RS_Msg(msg:0x%02X param:0x%08X len:%d)\n\r", opcd, (unsigned int)param, (int) nLength));*/
   if ( nLength > DL_BLK_SIZE )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Pef24628e_Send_RS_Msg wrong length\n\r" ) );
      return IFX_FALSE;
   }

   /* copy message and leave some room for the header */
#if PEF24628E_FW_IS_BE == 1
   for ( i = 0; i < nLength; i += 4 )
   {
      pDev->TxFifo.pData[8 + i + 3] = *( pSrc8++ );
      pDev->TxFifo.pData[8 + i + 2] = *( pSrc8++ );
      pDev->TxFifo.pData[8 + i + 1] = *( pSrc8++ );
      pDev->TxFifo.pData[8 + i + 0] = *( pSrc8++ );
   }
#else
   /* assume that data is already in little endian (and we can use memcpy) */
   memcpy ( ( void * ) ( pDev->TxFifo.pData + 8 ), ( void * ) pSrc, ( IFX_uint32_t ) nLength );
#endif

   /* prepare parameters of message */
   /* (send without transport protocol) */
   *( pDev->TxFifo.pData + 0 ) = PEF24628E_ADR_HOST;
   *( pDev->TxFifo.pData + 1 ) = PEF24628E_ADR_DEVICE(pDev->nDevAddress) | PEF24628E_ADR_RAMSHELL;
   *( pDev->TxFifo.pData + 2 ) = 0;
   *( pDev->TxFifo.pData + 3 ) = opcd;

   /* insert 32bit param in little endian format */
   *( pDev->TxFifo.pData + 4 ) = param & 0xFF;
   *( pDev->TxFifo.pData + 5 ) = ( param >> 8 ) & 0xFF;
   *( pDev->TxFifo.pData + 6 ) = ( param >> 16 ) & 0xFF;
   *( pDev->TxFifo.pData + 7 ) = ( param >> 24 ) & 0xFF;

   nLength += 8;        /* add message header */

   pDev->TxFifo.nBytes = nLength;
   pDev->TxFifo.nSent = 0;
   pDev->txErr = IFX_TRUE;
//   IFXOS_ClearEvent ( pDev->wqTxAck );

#ifdef INCLUDE_SCC_HDLC
   if ( pDev->ActiveIf == PEF24628E_IF_SCI )
   {
      /* write IDC message */
      while ( retry-- )
      {
         if ( ( len =
                Pef24628e_Send_SCC_Msg ( pDev, pSciHdlcDev[pDev->nSciHdlcDev], 
                                         ( IFX_uint8_t * ) ( pDev->TxFifo.pData ),
                                         ( IFX_int32_t ) nLength ) ) >= 0 )
         {
            return IFX_TRUE;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Unable to send RS message, %d bytes. Try to resent.\n\r", ( int ) len ) );
         pDev->TxFifo.nBytes = nLength;
         pDev->TxFifo.nSent = 0;
      }
      
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Failed to send RS message, %d bytes\n\r", ( int ) len ) );
      return IFX_FALSE;
   }
#endif /* INCLUDE_SCC_HDLC */

#ifdef INCLUDE_MPI
   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      if ( pDev->irq_vector == 0 )
      {
         /* polling mode */
         while ( retry-- )
         {
            if ( Pef24628e_Sci_Tx_Polling ( pDev ) == IFX_TRUE )
            {
               return IFX_TRUE;
            }
            TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( ERR_PREFIX "Unable to send RS message. Try to resent.\n\r" ) );
            pDev->TxFifo.nBytes = nLength;
            pDev->TxFifo.nSent = 0;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Failed to send RS message\n\r" ) );
         return IFX_FALSE;
      }

      /* interrupt mode -> init transmission */
      Pef24628e_Sci_XprInt ( pDev );

#if 0  
			/* wait for event */
      if ( IFXOS_WaitEvent_timeout ( pDev->wqTxAck, 5000 ) == IFX_ERROR )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "Pef24628e_Send_RS_Msg timed out\n\r" ) );
      }
#endif
      return ( !pDev->txErr ? IFX_TRUE : IFX_FALSE );
   }
#endif /* INCLUDE_MPI */

   return IFX_FALSE;
}

/**
   Creates a IDC RAMSHELL message from parameters and sends it to SCI.
   Only used for firmware download.

\param pDev          device structure
\param opcd          operation code of ramshell message
\param param         ramshell parameter
\param pSrc          pointer to additional data
\param nLength       length of additional data

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

\remarks
   Checking for ack will discard all unknown messages.
   This is only useful during startup/before active firmware.

*/
LOCAL IFX_boolean_t Pef24628e_Send_IDC_RS_Msg ( PEF24628E_DEV_t * pDev,
                                                 IFX_uint8_t opcd,
                                                 IFX_uint32_t param,
                                                 IFX_uint8_t * pSrc, IFX_uint16_t nLength )
{
#if PEF24628E_FW_IS_BE == 1
   IFX_int16_t i;
   IFX_uint8_t *pSrc8 = pSrc;
#endif

#ifdef INCLUDE_SCC_HDLC
   IFX_int32_t len = 0;
#endif /* NO_OS */

   IFX_int32_t retry = 3;

   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
   {
/*
		 TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX
                "IDC RS send message not possible, if not initialized. msg:0x%02X param:0x%08X len:%d\n\r",
                opcd, ( unsigned int ) param, ( int ) nLength ) );
*/  
		 return IFX_FALSE;
   }

/*   TRACE (PEF24628E_DRV, DBG_LEVEL_HIGH,
          (PREFIX "Pef24628e_Send_IDC_RS_Msg(msg:0x%02X param:0x%08X len:%d)\n\r", opcd, (unsigned int)param, (int) nLength));*/
   if ( nLength > DL_BLK_SIZE )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Pef24628e_Send_IDC_RS_Msg wrong length\n\r" ) );
      return IFX_FALSE;
   }

   /* prepare parameters of message */
   /* copy message and leave some room for the header */
#if PEF24628E_FW_IS_BE == 1
   for ( i = 0; i < nLength; i += 4 )
   {
      pDev->TxFifo.pData[8 + i + 3] = *( pSrc8++ );
      pDev->TxFifo.pData[8 + i + 2] = *( pSrc8++ );
      pDev->TxFifo.pData[8 + i + 1] = *( pSrc8++ );
      pDev->TxFifo.pData[8 + i + 0] = *( pSrc8++ );
   }
#else
   /* assume that data is already in little endian (and we can use memcpy) */
   memcpy ( ( void * ) ( pDev->TxFifo.pData + 8 ), ( void * ) pSrc, ( IFX_uint32_t ) nLength );
#endif

   /* prepare parameters of message */
   /* (send without transport protocol) */
   *( pDev->TxFifo.pData + 0 ) = PEF24628E_ADR_HOST;
   *( pDev->TxFifo.pData + 1 ) = PEF24628E_ADR_DEVICE(pDev->nDevAddress) | PEF24628E_ADR_IDC_RAMSHELL;
   *( pDev->TxFifo.pData + 2 ) = 0;
   *( pDev->TxFifo.pData + 3 ) = opcd;

   /* insert 32bit param in little endian format */
   *( pDev->TxFifo.pData + 4 ) = param & 0xFF;
   *( pDev->TxFifo.pData + 5 ) = ( param >> 8 ) & 0xFF;
   *( pDev->TxFifo.pData + 6 ) = ( param >> 16 ) & 0xFF;
   *( pDev->TxFifo.pData + 7 ) = ( param >> 24 ) & 0xFF;

   nLength += 8;        /* add message header */

   pDev->TxFifo.nBytes = nLength;
   pDev->TxFifo.nSent = 0;
   pDev->txErr = IFX_TRUE;
//   IFXOS_ClearEvent ( pDev->wqTxAck );

#ifdef INCLUDE_SCC_HDLC
   if ( pDev->ActiveIf == PEF24628E_IF_SCI )
   {
      /* write IDC message */
      while ( retry-- )
      {
         if ( ( len =
                Pef24628e_Send_SCC_Msg ( pDev, pSciHdlcDev[pDev->nSciHdlcDev], 
                                         ( IFX_uint8_t * ) ( pDev->TxFifo.pData ),
                                         ( IFX_int32_t ) nLength ) ) >= 0 )
         {
            return IFX_TRUE;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Unable to send IDC RS message, %d bytes. Try to resent.\n\r", ( int ) len ) );
         pDev->TxFifo.nBytes = nLength;
         pDev->TxFifo.nSent = 0;
      }
      
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Failed to send IDC RS message, %d bytes\n\r", ( int ) len ) );
      return IFX_FALSE;
   }
#endif /* INCLUDE_SCC_HDLC */

#ifdef INCLUDE_MPI
   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      if ( pDev->irq_vector == 0 )
      {
         /* polling mode */
         while ( retry-- )
         {
            if ( Pef24628e_Sci_Tx_Polling ( pDev ) == IFX_TRUE )
            {
               return IFX_TRUE;
            }
            TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( ERR_PREFIX "Unable to send IDC RS message. Try to resent.\n\r" ) );
            pDev->TxFifo.nBytes = nLength;
            pDev->TxFifo.nSent = 0;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Failed to send IDC RS message\n\r" ) );
         return IFX_FALSE;
      }

      Pef24628e_Sci_XprInt ( pDev );

#if 0			
      /* wait for event */
      if ( IFXOS_WaitEvent_timeout ( pDev->wqTxAck, 5000 ) == IFX_ERROR )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Pef24628e_Send_IDC_RS_Msg timed out\n\r" ) );
      }
#endif
      return ( !pDev->txErr ? IFX_TRUE: IFX_FALSE );
   }
#endif /* INCLUDE_MPI */

   return IFX_FALSE;
}


IFX_boolean_t Pef24628e_Send_Any_Msg ( PEF24628E_DEV_t * pDev)
{
   IFX_int32_t retry = 3;
#ifdef INCLUDE_SCC_HDLC
   IFX_int32_t len = 0;
#endif /* INCLUDE_SCC_HDLC */


   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
   {
       return IFX_FALSE;
   }

   /* prepare parameters of message */
   /* (send without transport protocol) */
   *( pDev->TxFifo.pData + 0 ) = 0xF3;
   *( pDev->TxFifo.pData + 1 ) = 0xF2;//PEF24628E_ADR_DEVICE(pDev->nDevAddress) | PEF24628E_ADR_AUX;
   *( pDev->TxFifo.pData + 2 ) = 0x08;//reg;
   *( pDev->TxFifo.pData + 3 ) = 0x0F;//param;
   *( pDev->TxFifo.pData + 4 ) = 0x00;//param;
   *( pDev->TxFifo.pData + 5 ) = 0x00;//param;
   *( pDev->TxFifo.pData + 6 ) = 0x00;//reg;
   *( pDev->TxFifo.pData + 7 ) = 0x00;//param;

   pDev->TxFifo.nBytes = 6;
   pDev->TxFifo.nSent = 0;
   pDev->txErr = IFX_TRUE;
//   IFXOS_ClearEvent ( pDev->wqTxAck );


#ifdef INCLUDE_MPI
   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      if ( pDev->irq_vector == 0 )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( PREFIX "Pef24628e_Send_Aux_Msg: polling mode\n\r" ) );
         /* polling mode */
         while ( retry-- )
         {
            if ( Pef24628e_Sci_Tx_Polling ( pDev ) == IFX_TRUE )
            {
               TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
                       ( PREFIX "LAST_AUX_VALUE = 0x%08X\n\r", ( unsigned int ) pDev->last_aux_value ) );
               return IFX_TRUE;
            }
            TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( ERR_PREFIX "Unable to send AUX message. Try to resent.\n\r" ) );
            pDev->TxFifo.nBytes = 4;
            pDev->TxFifo.nSent = 0;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Failed to send AUX message\n\r" ) );
         return IFX_FALSE;
      }

      Pef24628e_Sci_XprInt ( pDev );

#if 0			
      /* wait for event */
      if ( IFXOS_WaitEvent_timeout ( pDev->wqTxAck, 10000 ) == IFX_ERROR )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Pef24628e_Send_AUX_Msg timed out\n\r" ) );
      }
#endif
      return ( (IFX_boolean_t)(!pDev->txErr) );
    }
#endif /* INCLUDE_MPI */

   return IFX_FALSE; 
}


/**
   Creates an AUX message from parameters and sends it to SCI.

\param pDev          device structure
\param reg           register address in AUX
\param param         value

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

\remarks
   The return value will be stored within last_aux_value variable
   of the device context.

*/
IFX_boolean_t Pef24628e_Send_Aux_Msg ( PEF24628E_DEV_t * pDev, IFX_uint8_t reg, IFX_uint8_t param )
{
   IFX_int32_t retry = 3;
#ifdef INCLUDE_SCC_HDLC
   IFX_int32_t len = 0;
#endif /* INCLUDE_SCC_HDLC */


   /* Not possible, if not initialized! */
   if ( !pDev->bInit )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "not initialized - Pef24628e_Send_Aux_Msg(reg:0x%04X param:0x%04X)\n\r",
                reg, param ) );
      return IFX_FALSE;
   }

/*   TRACE (PEF24628E_DRV, DBG_LEVEL_NORMAL,
          (PREFIX "Pef24628e_Send_Aux_Msg(reg:0x%04X param:0x%04X)\n\r", reg, param));*/

   /* prepare parameters of message */
   /* (send without transport protocol) */
   *( pDev->TxFifo.pData + 0 ) = PEF24628E_ADR_HOST;
   *( pDev->TxFifo.pData + 1 ) = PEF24628E_ADR_DEVICE(pDev->nDevAddress) | PEF24628E_ADR_AUX;
   *( pDev->TxFifo.pData + 2 ) = reg;
   *( pDev->TxFifo.pData + 3 ) = param;

   pDev->TxFifo.nBytes = 4;
   pDev->TxFifo.nSent = 0;
   pDev->txErr = IFX_TRUE;
//   IFXOS_ClearEvent ( pDev->wqTxAck );

#ifdef INCLUDE_SCC_HDLC
   if ( pDev->ActiveIf == PEF24628E_IF_SCI )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
              ( PREFIX "Pef24628e_Send_Aux_Msg(%d) using SCC\n\r", ( int ) pDev->TxFifo.nBytes ) );

      /* write AUX message */
      while ( retry-- )
      {
         if ( (len = Pef24628e_Send_SCC_Msg ( pDev, pSciHdlcDev[pDev->nSciHdlcDev], 
                      ( IFX_uint8_t * ) ( pDev->TxFifo.pData ),
                      ( IFX_int32_t ) ( pDev->TxFifo.nBytes ) )) >= 0 )
         {
            return IFX_TRUE;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Unable to send AUX message, %d bytes. Try to resent.\n\r", ( int ) len ) );
         pDev->TxFifo.nBytes = 4;
         pDev->TxFifo.nSent = 0;
      }
      
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "Failed to send AUX message, %d bytes\n\r", ( int ) len ) );
      return IFX_FALSE;
   }
#endif /* INCLUDE_SCC_HDLC */

#ifdef INCLUDE_MPI
   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      if ( pDev->irq_vector == 0 )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( PREFIX "Pef24628e_Send_Aux_Msg: polling mode\n\r" ) );
         /* polling mode */
         while ( retry-- )
         {
            if ( Pef24628e_Sci_Tx_Polling ( pDev ) == IFX_TRUE )
            {
               TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
                       ( PREFIX "LAST_AUX_VALUE = 0x%08X\n\r", ( unsigned int ) pDev->last_aux_value ) );
               return IFX_TRUE;
            }
            TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( ERR_PREFIX "Unable to send AUX message. Try to resent.\n\r" ) );
            pDev->TxFifo.nBytes = 4;
            pDev->TxFifo.nSent = 0;
         }
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Failed to send AUX message\n\r" ) );
         return IFX_FALSE;
      }

      Pef24628e_Sci_XprInt ( pDev );

#if 0			
      /* wait for event */
      if ( IFXOS_WaitEvent_timeout ( pDev->wqTxAck, 10000 ) == IFX_ERROR )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                 ( ERR_PREFIX "Pef24628e_Send_AUX_Msg timed out\n\r" ) );
      }
#endif
      return ( (IFX_boolean_t)(!pDev->txErr) );
    }
#endif /* INCLUDE_MPI */

   return IFX_FALSE; 
}

/**
   Send the acknowledge of the transport protocol.
   
\param pDev          device structure
\param Odd           odd / even flag
\param nak           NAK flag

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
LOCAL IFX_boolean_t Pef24628e_Send_TP_Ack ( PEF24628E_DEV_t * pDev,
                                             IFX_uint8_t Odd, IFX_boolean_t nak )
{
#ifdef INCLUDE_SCC_HDLC
   IFX_int32_t len = 0;
#endif /* INCLUDE_SCC_HDLC */

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "TX TP ACK Odd %d, nak %d\n\r", Odd, nak ) );

   /* prepare parameters of message */
   /* (send without transport protocol) */
   *( pDev->TxFifo.pData + 0 ) = PEF24628E_ADR_HOST;
   *( pDev->TxFifo.pData + 1 ) = PEF24628E_ADR_DEVICE(pDev->nDevAddress) | PEF24628E_ADR_IDC_CTRLR;

   /* check of odd/even only if necessary */
   if ( pDev->TranspData.RxOddEven == Odd )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_LOW, ( _LOGGING_PREFIX "PEF24624_TP: Double msg?? Same odd/even bit\n\r" ) );
     /* return IFX_FALSE;*/
   }

   if ( nak )
   {
      *( pDev->TxFifo.pData + 2 ) = 0x8E | Odd; /* Nack */
   }
   else
   {
      *( pDev->TxFifo.pData + 2 ) = 0x88 | Odd; /* Ack */
   }

   *( pDev->TxFifo.pData + 3 ) = 0x00;

   pDev->TxFifo.nBytes = 4;
   pDev->TxFifo.nSent = 0;

#ifdef INCLUDE_SCC_HDLC
   if ( pDev->ActiveIf == PEF24628E_IF_SCI )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
              ( PREFIX "Pef24628e_Send_TP_Ack(%d) using SCC\n\r", ( int ) pDev->TxFifo.nBytes ) );

      len = Scc_Hdlc_Send_Frame ( pSciHdlcDev[pDev->nSciHdlcDev], 
                               ( IFX_uint8_t * ) ( pDev->TxFifo.pData ),
                               ( IFX_uint32_t ) ( pDev->TxFifo.nBytes ) );
      if ( !nak )
      {
         pDev->TranspData.RxOddEven = Odd;
      }

      if ( len < 0 )
      {
         TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
                 ( PREFIX "Unable to write TP ACK message (%d)\n\r", ( int ) len ) );
         return IFX_FALSE;
      }

      return IFX_TRUE;
   }
#endif /* INCLUDE_SCC_HDLC */

#ifdef INCLUDE_MPI
   if ( pDev->ActiveIf == PEF24628E_IF_MPI )
   {
      Pef24628e_Sci_XprInt ( pDev );

      if ( !nak )
      {
         pDev->TranspData.RxOddEven = Odd;
      }
      return IFX_TRUE;
   }
#endif /* INCLUDE_MPI */

   return IFX_FALSE;
}

/**
   Download of the SDFE firmware. The PAMDSL devices wil be started
   by the IDC controller.
   
\param pDev          device structure
\param pImage        pointer to the firmware image
\param nLength       length of teh firmware image

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
IFX_boolean_t Pef24628e_DSL_Download ( PEF24628E_DEV_t * pDev,
                                       IFX_uint8_t * pImage, IFX_uint32_t nLength )
{
   IFX_uint32_t adr, fwdtpnt, img_crc, counter;
   IFX_uint8_t *pData;
   uint32_t offset = 0;

   //allen
   pImage = Rx_Buffer;
   
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
           ( PREFIX "SDFE-4 image address 0x%08X, size %d bytes\n\r", ( unsigned int ) pImage,
             ( int ) nLength ) );

   /* stop all PAMDSLs */
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "SDFE-4 stop all PAMDSLs\n\r" ) );
   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWSTART, 0, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   /* FWCTRL.valid=0, FWCTRL.chk=0, FWCTRL.switch=0 */
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
           ( PREFIX "SDFE-4 FWCTRL.valid=0, FWCTRL.chk=0, FWCTRL.switch=0\n\r" ) );
   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, 0, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   /* write code RAM */
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "SDFE-4 write code RAM\n\r" ) );


   //pData = pImage + DL_OFFSET_CODE;   
   pData = pImage;
   offset = DL_OFFSET_CODE;

   for ( adr = 0; adr < ( DL_CODE_SIZE / 4 ); adr += ( DL_BLK_SIZE / 4 ) )
   {
      
	  //read data out from spi flash
      dsl_fw_read(offset, DL_BLK_SIZE);	  
      
	  rt_kprintf("#");//,offset/DL_BLK_SIZE); 
      if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_RAM_RS, adr, pData, DL_BLK_SIZE ) )
         goto PEF24628E_DL_ERROR;

      //pData += DL_BLK_SIZE;
      offset += DL_BLK_SIZE;      
	  //rt_kprintf("\r\n\r\n");
      
   }

   rt_kprintf("\r\n");
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
           ( PREFIX "SDFE-4 start CRC check - code section\n\r" ) );
   pDev->last_rs_value = 0xDEADBEEF;

   
   //read crc from spi flash
   //img_crc = GET_UINT32_FROM_IMAGE ( pImage + DL_OFFSET_CODE_CRC );
   dsl_fw_read(DL_OFFSET_CODE_CRC,4);
   img_crc = GET_UINT32_FROM_IMAGE(Rx_Buffer);

   /* check CRC */
   /* FWCTRL.chk=1 */
   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_CHK, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   counter = 10;
   while ( ( --counter ) && ( img_crc != pDev->last_rs_value ) )
   {
      IFXOS_Wait ( 100 );
#ifdef INCLUDE_SCC_HDLC
      if ( pDev->ActiveIf == PEF24628E_IF_SCI ) {
         Pef24628e_Get_SCC_Msg( pDev, pSciHdlcDev[pDev->nSciHdlcDev] );
      } 
      else 
      {
#endif
      Pef24628e_Poll_Check ( pDev );
#ifdef INCLUDE_SCC_HDLC
      }
#endif
   }
   if ( counter == 0 )
   {
   	  TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "expected CRC = %X\n\r",img_crc) );
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "DSL code CRC waiting timeout\n\r" ) );
      goto PEF24628E_DL_ERROR;
   }
   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "SDFE-4 CRC check - code section\n\r" ) );
   if ( img_crc != pDev->last_rs_value )
   {

		 TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "SDFE-4: CRC error in code ram, expected %08X, received %08X\n\r",
                ( unsigned int ) img_crc, ( unsigned int ) pDev->last_rs_value ) );

		 goto PEF24628E_DL_ERROR;
   }

   /* FWCTRL.switch=1 */
   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_SWITCH, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   /* write data RAM */
   //pData = pImage + DL_OFFSET_DATA;   
   pData = pImage;// + DL_OFFSET_DATA;
   offset = DL_OFFSET_DATA;
   
   for ( adr = 0; adr < DL_DATA_SIZE / 4; adr += DL_BLK_SIZE / 4 )
   {	   
	   //read data out from spi flash
	   dsl_fw_read(offset, DL_BLK_SIZE);   
	   
	   rt_kprintf("*"); 
	   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_RAM_RS, adr, pData, DL_BLK_SIZE ) )
	   {
		  goto PEF24628E_DL_ERROR;
	   }
	   
	   //pData += DL_BLK_SIZE;
	   offset+=DL_BLK_SIZE;   
   }
   TRACE (PEF24628E_DRV, DBG_LEVEL_NORMAL, ("\n\r")); 

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
           ( PREFIX "SDFE-4 start CRC check - data section\n\r" ) );

   pDev->last_rs_value = 0xDEADBEEF;
   //img_crc = GET_UINT32_FROM_IMAGE ( pImage + DL_OFFSET_DATA_CRC );
   dsl_fw_read(DL_OFFSET_DATA_CRC,4);
   img_crc = GET_UINT32_FROM_IMAGE(Rx_Buffer);


   /* check CRC */
   /* FWCTRL.chk=1, FWCTRL.switch=1 */
   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_CHK | FWCTRL_SWITCH, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   counter = 10;
   while ( ( --counter ) && ( img_crc != pDev->last_rs_value ) )
   {
      IFXOS_Wait ( 100 );
#ifdef INCLUDE_SCC_HDLC
      if ( pDev->ActiveIf == PEF24628E_IF_SCI ) {
         Pef24628e_Get_SCC_Msg( pDev, pSciHdlcDev[pDev->nSciHdlcDev] );
      } 
      else 
      {
#endif
      Pef24628e_Poll_Check ( pDev );
#ifdef INCLUDE_SCC_HDLC
      }
#endif
   }

   if ( counter == 0 )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "DSL data CRC waiting timeout\n\r" ) );
      goto PEF24628E_DL_ERROR;
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "SDFE-4 CRC check - data section\n\r" ) );

   if ( img_crc != pDev->last_rs_value )
   {
/*
		 TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "SDFE-4: CRC error in data ram, expected %08X rceived %08X CRC\n\r",
                ( unsigned int ) img_crc, ( unsigned int ) pDev->last_rs_value ) );
*/  
		 goto PEF24628E_DL_ERROR;
   }

   /* set FWDTPNT */
   //fwdtpnt = GET_UINT32_FROM_IMAGE ( pImage + DL_OFFSET_DTPNT );
   dsl_fw_read(DL_OFFSET_DTPNT,4);
   fwdtpnt = GET_UINT32_FROM_IMAGE(Rx_Buffer);

   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWDTPNT, fwdtpnt, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   /* if device address is not default: */
/*#if PEF24628E_ADR_DEV != 0xF0*/
   {
      IFX_uint8_t devadr[4] = { 0, 0, 0, 0 };
#ifdef INCLUDE_SCC_HDLC

#if PEF24628E_FW_IS_BE == 0
      /* data in memory must be big endian: */
      devadr[3] = PEF24628E_ADR_DEVICE(pDev->nDevAddress);
#else
      /* data in memory must be little endian: */
      devadr[0] = PEF24628E_ADR_DEVICE(pDev->nDevAddress);
#endif /* endif PEF24628E_FW_IS_BE*/

#else /* INCLUDE_SCC_HDLC */

#if PEF24628E_FW_IS_BE == 1
      /* data in memory must be big endian: */
      devadr[3] = PEF24628E_ADR_DEVICE(pDev->nDevAddress);
#else
      /* data in memory must be little endian: */
      devadr[0] = PEF24628E_ADR_DEVICE(pDev->nDevAddress);
#endif/* endif PEF24628E_FW_IS_BE*/

#endif /* endif INCLUDE_SCC_HDLC*/

      /* write device address to firmware memory (after BIST!!!) */
      /* first switch to data ram */
      if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_SWITCH, NULL, 0 ) )
         goto PEF24628E_DL_ERROR;

      /* then write value to ram (adr 0) */
      if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_RAM_RS, 0, &devadr[0], sizeof ( UINT32 ) ) )
         goto PEF24628E_DL_ERROR;
   }
/*#endif*/ /* PEF24628E_ADR_DEV != 0xF0 */

   /* FWCTRL.valid=1, FWCTRL.protect=1  */
   if ( !Pef24628e_Send_RS_Msg
        ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_PROTECT | FWCTRL_VALID, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;

   /* start all PAMDSLs */
#if 0   /* done by IDC */
   if ( !Pef24628e_Send_RS_Msg ( pDev, CMD_WR_REG_RS_FWSTART, FWSTART_STARTALL, NULL, 0 ) )
      goto PEF24628E_DL_ERROR;
#endif

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "SDFE-4 Firmware download complete\n\r" ) );

   return IFX_TRUE;

 PEF24628E_DL_ERROR:

   return IFX_FALSE;
}

/**
   Set the IDC start bit.

\param pDev          handle to device data

\retval IFX_TRUE     after successful message sending
\retval IFX_FALSE    on error

*/
IFX_boolean_t Pef24628e_IDC_Start ( PEF24628E_DEV_t * pDev )
{
   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "IDC FW Load: Setting Ram Loaded bit...\n\r" ) );
   /* set Ramloaded and remove the lock of the IDC
      CMD_WR_REG_IDC_RS_FWGP1.ramloaded=1, CMD_WR_REG_IDC_RS_FWGP1.mwait=0, 
      CMD_WR_REG_IDC_RS_FWGP1.ifetch=0 */
   g_debug=1;
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_IDC_RS_FWGP1, FWGP1_RAMLOADED, NULL, 0 ) )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC Firmware not started\n\r" ) );
      return IFX_FALSE;
   }
   else
   {   
#ifdef INCLUDE_SCC_HDLC
      pDev->bFwStarted = IFX_TRUE;
#endif      
      if(pDev->ActiveIf == PEF24628E_IF_MPI)
      {
         TRACE (PEF24628E_DRV, DBG_LEVEL_HIGH,(PREFIX "switching to MPI interface\n\r"));
         pDev->bSendIdcViaSciBridge = IFX_FALSE;
      }   
   
      pDev->bFwDownloaded = IFX_TRUE;

      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "IDC Firmware started\n\r" ) );
      
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, 
            ( PREFIX "MCR_0 = 0x%02X, MCR_1 = 0x%02X, MCR_2 = 0x%02X, MCR_3 = 0x%02X\n\r", 
               pDev->uc_reg->MCR_0, 
               pDev->uc_reg->MCR_1, 
               pDev->uc_reg->MCR_2, 
               pDev->uc_reg->MCR_3 ) );

      return IFX_TRUE;
   }
}

/**
   Download of the IDC firmware. 
      
\param pDev          device structure
\param pImage        pointer to the firmware image
\param nLength       length of teh firmware image

\retval IFX_TRUE     Success
\retval IFX_FALSE    in case of error

*/
//#define IDC_FW_LEN 180308
IFX_boolean_t Pef24628e_IDC_Download ( PEF24628E_DEV_t * pDev,
                                       IFX_uint8_t * pImage, IFX_uint32_t nLength )
{
   IFX_uint32_t adr, img_crc, end, counter;
   IFX_uint8_t *pData;
   PEF24628E_IDC_FwInfo_t idcFwInfo;

   uint32_t offset;
   
   //allen
   pImage = Rx_Buffer;	

   idcFwInfo.pImage = pImage;
   idcFwInfo.image_size = nLength;

   if ( idcFwInfo.image_size < 24 )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC image size is invalid\n\r" ) );
      return IFX_FALSE;
   }

   //idc_fw_read((IDC_FW_LEN/256)*256,256);
   
   /* Calculate Code and Data part sizes and offsets from the last two values 
      FW is in Byte
      X           Boot + Code
      Y           Code
      Z           Data
      4           Boot-CRC (not used)
      4           Code-CRC
      4           Data-CRC
      4           Code Start Address 
      4           Data Start Address */

   end = idcFwInfo.image_size + ( IFX_uint32_t ) idcFwInfo.pImage;

   /* Last five 32 bit values are CRCs and Start addresses */
   idcFwInfo.offset_data_start = idcFwInfo.image_size - 4;
   idcFwInfo.offset_code_start = idcFwInfo.image_size - 8;
   idcFwInfo.offset_data_crc = idcFwInfo.image_size - 12;
   idcFwInfo.offset_code_crc = idcFwInfo.image_size - 16;
   idcFwInfo.offset_boot_crc = idcFwInfo.image_size - 20;
   
   //idcFwInfo.offset_code = GET_UINT32_FROM_IMAGE( idcFwInfo.pImage + idcFwInfo.offset_code_start );
   offset = idcFwInfo.offset_code_start;    
   idc_fw_read(offset,4);
   idcFwInfo.offset_code = GET_UINT32_FROM_IMAGE(Rx_Buffer);

   //idcFwInfo.offset_data = GET_UINT32_FROM_IMAGE( idcFwInfo.pImage + idcFwInfo.offset_data_start );
   offset = idcFwInfo.offset_data_start;    
   idc_fw_read(offset,4);
   idcFwInfo.offset_data = GET_UINT32_FROM_IMAGE(Rx_Buffer);
   
   idcFwInfo.boot_size = idcFwInfo.offset_code;
   idcFwInfo.code_size = idcFwInfo.offset_data - idcFwInfo.offset_code;
   idcFwInfo.data_size = idcFwInfo.offset_boot_crc - idcFwInfo.offset_data;

   rt_kprintf("IDC FW Load: image size        %08x\n\r",( unsigned int ) idcFwInfo.image_size ) ;
   rt_kprintf("IDC FW Load: image start       %08x\n\r",( unsigned int ) idcFwInfo.pImage );
   rt_kprintf("IDC FW Load: image end         %08x\n\r",( unsigned int ) end );
   rt_kprintf("IDC FW Load: offset data start %08x\n\r",( unsigned int ) idcFwInfo.offset_data_start );
   rt_kprintf("IDC FW Load: offset code start %08x\n\r",( unsigned int ) idcFwInfo.offset_code_start );
   rt_kprintf("IDC FW Load: offset data crc   %08x\n\r",( unsigned int ) idcFwInfo.offset_data_crc );
   rt_kprintf("IDC FW Load: offset code crc   %08x\n\r",( unsigned int ) idcFwInfo.offset_code_crc );
   rt_kprintf("IDC FW Load: offset boot crc   %08x\n\r",( unsigned int ) idcFwInfo.offset_boot_crc );
   rt_kprintf("IDC FW Load: offset code       %08x\n\r",( unsigned int ) idcFwInfo.offset_code );
   rt_kprintf("IDC FW Load: offset boot       %08x\n\r",( unsigned int ) idcFwInfo.offset_data );
   rt_kprintf("IDC FW Load: boot size         %08x\n\r",( unsigned int ) idcFwInfo.boot_size );
   rt_kprintf("IDC FW Load: code size         %08x\n\r",( unsigned int ) idcFwInfo.code_size );
   rt_kprintf("IDC FW Load: data size         %08x\n\r",( unsigned int ) idcFwInfo.data_size );


   if ( idcFwInfo.offset_data_start > idcFwInfo.image_size )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "PEF24624_DRV: IDC image invalid (offset data start)\n\r" ) );
      return IFX_FALSE;
   }
   if ( idcFwInfo.offset_code_start > idcFwInfo.image_size )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "IDC image invalid (offset code start)\n\r" ) );
      return IFX_FALSE;
   }
   if ( idcFwInfo.offset_code > end )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC image invalid (offset code)\n\r" ) );
      return IFX_FALSE;
   }
   if ( idcFwInfo.offset_data > end )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC image invalid (offset data)\n\r" ) );
      return IFX_FALSE;
   }
   if ( idcFwInfo.code_size > idcFwInfo.image_size )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC image invalid (code size)\n\r" ) );
      return IFX_FALSE;
   }
   if ( idcFwInfo.data_size > idcFwInfo.image_size )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC image invalid (data size)\n\r" ) );
      return IFX_FALSE;
   }

   /* make sure IDC does not access the Memory
      CMD_WR_REG_IDC_RS_FWGP1.mwait=1, CMD_WR_REG_IDC_RS_FWGP1.ifetch=1 */
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_IDC_RS_FWGP1,
                                     FWGP1_IFETCH | FWGP1_MWAIT, NULL, 0 ) )
      goto PEF24628E_IDC_DL_ERROR;

   /* begin download of Code memory
      CMD_WR_REG_IDC_RS_FWCTRL.valid=0, CMD_WR_REG_IDC_RS_FWCTRL.chk=0, 
      CMD_WR_REG_IDC_RS_FWCTRL.switch=0 */
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_IDC_RS_FWCTRL, 0, NULL, 0 ) )
      goto PEF24628E_IDC_DL_ERROR;

   /* write boot 
      boot code is only needed when IDC boots from RAM instead of ROM,
      but can be sent in each case because it is dropped if not used */
   pData = idcFwInfo.pImage;
   offset = DL_OFFSET_CODE;	
   
   for ( adr = 0; adr < ( idcFwInfo.boot_size ); adr += DL_BLK_SIZE )
   {
      rt_kprintf("#");//,offset/DL_BLK_SIZE); 

	  //read fw from spi flash
	  idc_fw_read(offset,DL_BLK_SIZE);  
	  
      if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_RAM_RS, adr / 4, pData, DL_BLK_SIZE ) )
         goto PEF24628E_IDC_DL_ERROR;

	  //pData += DL_BLK_SIZE;
	  offset+=DL_BLK_SIZE;
   }
   TRACE (PEF24628E_DRV, DBG_LEVEL_NORMAL, ("\n\r")); 

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: Sending Code...\n\r" ) );

   /* write code RAM */
   //pData = idcFwInfo.pImage + idcFwInfo.offset_code;
   //pData = idcFwInfo.pImage;// + idcFwInfo.offset_code;
   offset = idcFwInfo.offset_code;
   
   for ( adr = CODE_RAM_OFFSET; adr < ( CODE_RAM_OFFSET + idcFwInfo.code_size );
         adr += DL_BLK_SIZE )
   {
      rt_kprintf("*");//,(offset-idcFwInfo.offset_code)/DL_BLK_SIZE); 
	  //read fw from spi flash
	  idc_fw_read(offset,DL_BLK_SIZE);  
	  
      if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_RAM_RS, adr / 4, pData, DL_BLK_SIZE ) )
         goto PEF24628E_IDC_DL_ERROR;

      //pData += DL_BLK_SIZE;
	  offset+=DL_BLK_SIZE;
   }
   TRACE (PEF24628E_DRV, DBG_LEVEL_NORMAL, ("\n\r")); 

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: Starting Code BIST...\n\r" ) );

   pDev->last_rs_value = 0xDEADBEEF;
   //img_crc = GET_UINT32_FROM_IMAGE ( idcFwInfo.pImage + idcFwInfo.offset_code_crc );
  offset = idcFwInfo.offset_code_crc;  
  idc_fw_read(offset,4);
  img_crc = GET_UINT32_FROM_IMAGE(Rx_Buffer);



   /* start the check of CRC, bit is cleared automatically
      CMD_WR_REG_IDC_RS_FWCTRL.chk=1 */
   /* the CRC routine in hardware is only checking the Code or Data RAM, 
      never the boot RAM. Therefore a Boot code CRC cannot be checked. */
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_CHK, NULL, 0 ) )
      goto PEF24628E_IDC_DL_ERROR;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: Waiting for Code CRC...\n\r" ) );

   counter = 100;
   while ( ( --counter ) && ( img_crc != pDev->last_rs_value ) )
   {
      IFXOS_Wait ( 100 );
#ifdef INCLUDE_SCC_HDLC
      if ( pDev->ActiveIf == PEF24628E_IF_SCI ) {
         Pef24628e_Get_SCC_Msg( pDev, pSciHdlcDev[pDev->nSciHdlcDev] );
      } 
      else 
      {
#endif
      Pef24628e_Poll_Check ( pDev );
#ifdef INCLUDE_SCC_HDLC
      }
#endif
   }
   if ( counter == 0 )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC code CRC waiting timeout\n\r" ) );
      goto PEF24628E_IDC_DL_ERROR;
   }

   if ( img_crc != pDev->last_rs_value )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX
                "IDC FW Load: CRC error in code ram, expected %08X received %08X CRC\n\r",
                ( unsigned int ) img_crc, ( unsigned int ) pDev->last_rs_value ) );
      goto PEF24628E_IDC_DL_ERROR;
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL,
           ( PREFIX "IDC FW Load: Switching to Data Section...\n\r" ) );

   /* start download of Data Memory
      CMD_WR_REG_IDC_RS_FWCTRL.switch=1 */
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_SWITCH, NULL, 0 ) )
      goto PEF24628E_IDC_DL_ERROR;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: Sending Data...\n\r" ) );

   /* write data RAM */
   pData = idcFwInfo.pImage;// + idcFwInfo.offset_data;
   offset = idcFwInfo.offset_data;
	  

   for ( adr = 0; adr < idcFwInfo.data_size; adr += DL_BLK_SIZE )
   {
     //read fw from spi flash
	  idc_fw_read(offset,DL_BLK_SIZE); 	
   
      rt_kprintf("#"); 
      if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_RAM_RS, adr / 4, pData, DL_BLK_SIZE ) )
         goto PEF24628E_IDC_DL_ERROR;

      //pData += DL_BLK_SIZE;
      offset += DL_BLK_SIZE;
   }
   TRACE (PEF24628E_DRV, DBG_LEVEL_NORMAL, ("\n\r")); 

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: Starting Data BIST...\n\r" ) );

   pDev->last_rs_value = 0xDEADBEEF;
   //img_crc = GET_UINT32_FROM_IMAGE ( idcFwInfo.pImage + idcFwInfo.offset_data_crc );
  offset = idcFwInfo.offset_data_crc;  
  idc_fw_read(offset,4);
  img_crc = GET_UINT32_FROM_IMAGE(Rx_Buffer);


   /* check CRC, check bit is cleared automatically    
      CMD_WR_REG_IDC_RS_FWCTRL.chk=1, CMD_WR_REG_IDC_RS_FWCTRL.switch=1 */
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL,
                                     FWCTRL_CHK | FWCTRL_SWITCH, NULL, 0 ) )
      goto PEF24628E_IDC_DL_ERROR;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: Waiting for Data CRC...\n\r" ) );

   counter = 100;
   while ( ( --counter ) && ( img_crc != pDev->last_rs_value ) )
   {
      IFXOS_Wait ( 100 );
#ifdef INCLUDE_SCC_HDLC
      if ( pDev->ActiveIf == PEF24628E_IF_SCI ) {
         Pef24628e_Get_SCC_Msg( pDev, pSciHdlcDev[pDev->nSciHdlcDev] );
      } 
      else 
      {
#endif
      Pef24628e_Poll_Check ( pDev );
#ifdef INCLUDE_SCC_HDLC
      }
#endif
   }
   if ( counter == 0 )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "IDC data CRC waiting timeout\n\r" ) );
      goto PEF24628E_IDC_DL_ERROR;
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW Load: counter = %u\n\r", counter ) );

   if ( img_crc != pDev->last_rs_value )
   {
      TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH,
              ( ERR_PREFIX "CRC error in data ram, expected %08X received %08X\n\r",
                ( unsigned int ) img_crc, ( unsigned int ) pDev->last_rs_value ) );

      goto PEF24628E_IDC_DL_ERROR;
   }

   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "IDC FW Load: Setting Valid bit...\n\r" ) );

   /* grant the RAM access to IDC
      CMD_WR_REG_IDC_RS_FWCTRL.valid=1 */
   if ( !Pef24628e_Send_IDC_RS_Msg ( pDev, CMD_WR_REG_RS_FWCTRL, FWCTRL_VALID, NULL, 0 ) )
      goto PEF24628E_IDC_DL_ERROR;

   TRACE ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "IDC FW download finished.\n\r" ) );

   return IFX_TRUE;

PEF24628E_IDC_DL_ERROR:

   TRACE ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "IDC FW download finished with error\n\r" ) );

   return IFX_FALSE;
}

#ifdef INCLUDE_SCC_HDLC
/**
   Callback on frame available in the HDLC device. 
   If a frame is available it will be processed by 
   \ref Pef24628e_Sci_Process_Frame.

\param none

*/
IFX_void_t Pef24628e_CB_SCC_Msg ( IFX_void_t )
{
   PEF24628E_DEV_t * pDev = IFX_NULL;
   IFX_int32_t       i, len = 0;
   IFX_boolean_t     flag = IFX_FALSE;
   IFX_uint8_t     * pData;
   IFX_uint8_t       nIndex;

   for ( i = 0; i < PEF24628E_MAX_DEV_NUMBER; i++ ) 
   {
      pDev = Pef24628e_Devices[i];
      if ( pDev == IFX_NULL ) continue;
      
      /* should not be used while fw downloading ! */
      if ( pDev->bFwStarted == IFX_FALSE ) return;
      
      while ( Scc_Hdlc_Filtered_Poll_Check ( pSciHdlcDev[pDev->nSciHdlcDev], pDev->nDevAddress ) == IFX_TRUE ) 
      {
         flag = IFX_TRUE;
         
         pData = pDev->pRxFifoWrite->pData + pDev->pRxFifoWrite->nBytes;
         nIndex = pDev->pRxFifoWrite->nIndex;

         /* read data from hdlc driver */
         if ( ( len = Scc_Hdlc_Get_Frame ( pSciHdlcDev[pDev->nSciHdlcDev], pData, PEF24628E_MSG_SIZE ) ) < 0 )
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH,
                    ( ERR_PREFIX "CB_SCC[%02d]: Unable to read SCC HDLC data (%d)\n\r", nIndex, ( int ) len ) );
            return;
         }
   
         LOG ( PEF24628E_DRV, DBG_LEVEL_NORMAL, ( PREFIX "CB_SCC: -->Hdlc_Get_Frame(%d)\n\r", len ) );

         if (len == 0)
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "CB_SCC: -->Hdlc_Get_Frame\n\r" ) );
         }

         pDev->pRxFifoWrite->bSendIdcViaSciBridge = IFX_TRUE;

         pDev->pRxFifoWrite->nBytes += ( IFX_uint16_t ) len;

         /* Analyze acknowledge */
         if ( Pef24628e_Sci_Process_Frame ( pDev ) == IFX_TRUE )
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_LOW,
                ( PREFIX "CB_SCC[%02d]: frame should be processed by upper layer, %d bytes\n\r", nIndex, pDev->pRxFifoWrite->nBytes) );

            /* no errors -> switch to the next Rx FIFO block */
            pDev->pRxFifoWrite++;

            /* check for space in fifo */
            if ( pDev->pRxFifoWrite >= &pDev->RxFifo[PEF24628E_REC_FIFO_BLK_NUM] )
               pDev->pRxFifoWrite = &pDev->RxFifo[0];

            if ( pDev->pRxFifoWrite == pDev->pRxFifoRead )
            {
               pDev->bRxFifoFull = IFX_TRUE;
               LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( ERR_PREFIX "CB_SCC: RxRead Fifo full\n\r" ) );
            }
            else
            {
               pDev->bRxFifoFull = IFX_FALSE;
            }

            LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "CB_SCC: wakeup %s\n\r", ((pDev->bNeedWakeUp)?"TRUE":"FALSE")) );
            if ( pDev->bNeedWakeUp == IFX_TRUE )
            {
               LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "CB_SCC[%02d]: wakeup\n\r", nIndex) );

      #ifndef NO_OS
               IFXOS_WakeUp ( ( pDev->WakeupList ), 0 /*SELREAD*/ );
      #endif /*NO_OS */
               pDev->bNeedWakeUp = IFX_FALSE;
            }

            LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "CB_SCC[%02d]: next buffer\n\r", pDev->pRxFifoWrite->nIndex) );
         }
         else
         {
            LOG ( PEF24628E_DRV, DBG_LEVEL_LOW, ( PREFIX "CB_SCC[%02d]: frame already processed, should be ignored by upper layers\n\r", nIndex) );
            pDev->pRxFifoWrite->nBytes = 0;
         }
         
            IFXOS_WakeUpEvent ( pDev->wqTxAck );
         }
      }   
   
   if ( flag == IFX_FALSE ) 
   {
      LOG ( PEF24628E_DRV, DBG_LEVEL_HIGH, ( PREFIX "CB_SCC: unable to find destination soc4e device\n\r" ) );
   }
}
#endif /* INCLUDE_SCC_HDLC*/

/*@}*/
