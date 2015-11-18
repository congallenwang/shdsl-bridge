/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _DRV_PEF24628E_API_H
#define _DRV_PEF24628E_API_H

#define INCLUDE_MPI

/** \defgroup DRV_PEF24628E_IMPLEMENTATION Driver Driver Internal API */
/*@{*/
/**
   \file 
   Internal functional API of the driver.
*/
#include "ifx_types.h"

#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#define __PACKED__ __attribute__ ((packed))
#elif !defined (__PACKED__)
#define __PACKED__      /* nothing */
#endif

/*
#define IFX_uint8_t uint8_t
#define IFX_uint16_t uint16_t
#define IFX_uint32_t uint32_t 
#define IFX_int8_t int8_t
#define IFX_int16_t int16_t
#define IFX_int32_t int32_t 
#define IFX_void_t void
typedef volatile uint32_t IFX_vuint32_t;
#define  IFX_NULL 0;
*/

/** A type for handling boolean issues. */
#if 0
typedef enum 
{   
	/** false */   IFX_FALSE = 0,   
	/** true */   IFX_TRUE = 1
} IFX_boolean_t;
#else
#define  IFX_FALSE  0
#define IFX_TRUE  1
#define IFX_boolean_t int
#endif


#ifndef DRV_PEF24628E_NAME
#   ifdef LINUX
/** device name */
#      define DRV_PEF24628E_NAME          "soc4e"
#   else
/** device name */
#      define DRV_PEF24628E_NAME          "/dev/soc4e"
#   endif
#else
#   error module name already specified
#endif

#if defined(GENERIC_OS) && !defined(DONT_USE_XAPI_TRACE) && !(defined(LINUX) && !defined(__KERNEL__))
    /** prefix for logging */
    #define _COMMON_PREFIX __FILE__, __LINE__,
    /** prefix for TRACE macros */
    #define _PREFIX "PEF24628E_DRV: "
    #define PREFIX 
    /** prefix for error messages */
    #define _ERR_PREFIX "PEF24628E_DRV: ERROR - "
    #define ERR_PREFIX _COMMON_PREFIX _ERR_PREFIX
#else
    /** prefix for logging */
    #define _COMMON_PREFIX
    /** prefix for TRACE macros */
    #define _PREFIX "PEF24628E_DRV: "
    #define PREFIX 
    /** prefix for error messages */
    #define ERR_PREFIX "PEF24628E_DRV: ERROR - "
#endif

#ifndef _MKSTR_1
#define _MKSTR_1(x)    #x
#define _MKSTR(x)      _MKSTR_1(x)
#endif

/** driver version, major number */
#define DRV_PEF24628E_VER_MAJOR     0
/** driver version, minor number */
#define DRV_PEF24628E_VER_MINOR        4
/** driver version, build number */
#define DRV_PEF24628E_VER_STEP            4
/** driver version, package type */
#define DRV_PEF24628E_VER_TYPE               0
/** driver version string */
#define DRV_PEF24628E_VER_STR       _MKSTR(DRV_PEF24628E_VER_MAJOR)"."_MKSTR(DRV_PEF24628E_VER_MINOR)"."_MKSTR(DRV_PEF24628E_VER_STEP)"."_MKSTR(DRV_PEF24628E_VER_TYPE)
/** driver what string */
#define DRV_PEF24628E_WHAT_STR      "@(#)PEF24628e Driver, Version " DRV_PEF24628E_VER_STR

#ifndef PEF24628E_FW_IS_BE
#define PEF24628E_FW_IS_BE          1
#endif

#ifdef INCLUDE_MPI
/*#define PEF24628E_USE_SCI_MONITOR*/
#endif /* INCLUDE_MPI */

#ifndef SCI_TX_POLLING_DELAY
#define SCI_TX_POLLING_DELAY        0
#endif

#define SEND_MSG_MAX_REP_NUMBER     2

/* RAMSHELL register bits */
#define FWCTRL_VALID                0x00000001
#define FWCTRL_CHK                  0x00000100
#define FWCTRL_SWITCH               0x00010000
#define FWCTRL_PROTECT              0x01000000

#define FWSTART_START0              0x00000001
#define FWSTART_START1              0x00000002
#define FWSTART_START2              0x00000004
#define FWSTART_START3              0x00000008
#define FWSTART_STARTALL            0x0000000F

/* size for download blocks */
#define DL_BLK_SIZE                 PEF24628E_FW_BLOCK_SIZE

/* size for firmware image */
#define DL_CODE_SIZE                (9*16384L)  /* 7 */
#define DL_DATA_SIZE                (3*16384L)  /* 2 */

/* offsets for firmware image */
#define DL_OFFSET_CODE              0L
#define DL_OFFSET_DATA              DL_CODE_SIZE
#define DL_OFFSET_CODE_CRC          (DL_OFFSET_DATA+DL_DATA_SIZE)
#define DL_OFFSET_DATA_CRC          (DL_OFFSET_CODE_CRC+4)
#define DL_OFFSET_DTPNT             (DL_OFFSET_DATA_CRC+4)

//allen
#if PEF24628E_FW_IS_BE == 1
#define GET_UINT32_FROM_IMAGE(p)    (*(((IFX_uint8_t *)p)+3) | \
                                    (*(((IFX_uint8_t *)p)+2)<<8) | \
                                    (*(((IFX_uint8_t *)p)+1)<<16) | \
                                    (*(((IFX_uint8_t *)p)+0)<<24))
#else
#define GET_UINT32_FROM_IMAGE(p)    (*(((IFX_uint8_t *)p)+0) | \
                                    (*(((IFX_uint8_t *)p)+1)<<8) | \
                                    (*(((IFX_uint8_t *)p)+2)<<16) | \
                                    (*(((IFX_uint8_t *)p)+3)<<24))
#endif

/** SCI host addresses */
#define PEF24628E_ADR_HOST          0xF3
//#define PEF24628E_ADR_HOST          0xF1

/* example for a device address different from the default (0xF) */
/*#define PEF24628E_ADR_DEV           PEF24628E_ADR_DEVICE(pDev->nDevAddress)*/
#define PEF24628E_ADR_DEVICE(dev)   ((dev<<4) & 0xF0)

#define PEF24628E_ADR_PAMDSL(Ch)    ((((Ch)<<2) | 0x02) & 0x0F)
#define PEF24628E_ADR_PAMDSL_0      0x02
#define PEF24628E_ADR_PAMDSL_1      0x06
#define PEF24628E_ADR_PAMDSL_2      0x0A
#define PEF24628E_ADR_PAMDSL_3      0x0E
#define PEF24628E_ADR_RAMSHELL      0x05
#define PEF24628E_ADR_AUX           0x09
#define PEF24628E_ADR_IDC_CTRLR     0x01
#define PEF24628E_ADR_IDC_RAMSHELL  0x08

#define PEF24628E_TP_GET_HEADER(H0,H1)      (((H0)>>1) | (((H1)&0x1)<<7))
#define PEF24628E_TP_CMD_MSG        0x04
#define PEF24628E_TP_ACK_MSG        0x04
#define PEF24628E_TP_NFC_MSG        0x84
#define PEF24628E_TP_POS_ACK        0x44
#define PEF24628E_TP_NEG_ACK        0x47
#define PEF24628E_TP_RES_ACK        0x03
/* RAMSHELL register offsets */
#define FWCTRL                      0
#define FWCRC                       1
#define FWGP1                       2
#define FWGP2                       3

/* RAMSHELL register bits */
#define FWCTRL_VALID                0x00000001
#define FWCTRL_CHK                  0x00000100
#define FWCTRL_SWITCH               0x00010000

#define FWGP1_RAMLOADED             0x00000001
#define FWGP1_IFETCH                0x00000002
#define FWGP1_MWAIT                 0x00000004
#define FWGP1_NOMUX                 0x00000008
#define FWGP2_SWRESET               0x00000001

/** Macro to extract the Message Length from the IDC Header */
#define GET_IDC_HEADER_LENGTH(pData)   ((*((IFX_uint8_t*)(pData)))&0x1F)
/** Macro to set the Message Length from the IDC Header */
#define SET_IDC_HEADER_LENGTH(pData, val)   *((IFX_uint8_t*)(pData))=((*((IFX_uint8_t*)(pData)))&~0x1F)|(val&0x1F)
/** Macro to extract the Message ID from the IDC Header */
#define GET_IDC_HEADER_ID(pData)    ((((*((IFX_uint8_t*)(pData)+1))&0x0F)<<3)|(((*((IFX_uint8_t*)(pData)))&0xE0)>>5))
/** Macro to extract the Complete Message ID including TYPE and CAT from the IDC Header */
#define GET_IDC_HEADER_MSGID(pData) (((*((IFX_uint8_t*)(pData)+1))<<3)|(((*((IFX_uint8_t*)(pData)))&0xE0)>>5))
/** Macro to extract the Message Category from the IDC Header */
#define GET_IDC_HEADER_CAT(pData)   (((*((IFX_uint8_t*)(pData)+1))&0x30)>>4)
/** Macro to extract the Message Type from the IDC Header */
#define GET_IDC_HEADER_TYPE(pData)  (((*((IFX_uint8_t*)(pData)+1))&0xC0)>>6)
/** Macro to extract the Transaction Correlation ID from the IDC Header */
#define GET_IDC_HEADER_TCID(pData)  ((((*((IFX_uint8_t*)(pData)+3))&0x07)<<8)|(*((IFX_uint8_t*)(pData)+2)))
/** Macro to extract the Message Return Code from the IDC Header */
#define GET_IDC_HEADER_RC(pData)    (((*((IFX_uint8_t*)(pData)+3))&0x78)>>3)
/** Macro to extract the Message Type ID from the IDC Header */
#define GET_IDC_HEADER_M(pData)     (((*((IFX_uint8_t*)(pData)+3))&0x80)>>7)

#define  RSTA_RAB  0x10
#define  RSTA_CRC  0x20
#define  RSTA_RDO  0x40
#define  RSTA_VFR  0x80

/** valid received message */
#define PEF24628E_VALID_RSTA   ((RSTA_CRC | RSTA_VFR) | \
                              !( RSTA_RAB | RSTA_RDO))

/** Block size for firmware download */
#define PEF24628E_FW_BLOCK_SIZE     56/*1024L*/

/** firmware image is coded in big endian (default) */
#define PEF246228E_FW_IS_BE         1

/* PAMDSL message identifiers */
#define ACK_RD_REG_RS               0x0001
#define ACK_WR_REG_RS               0x0002
#define CMD_WR_REG_RS_FWCTRL        0x0001
#define CMD_RD_REG_RS_FWCTRL        0x0000
#define CMD_RD_REG_RS_FWCRC         0x0020
#define CMD_WR_REG_RS_FWDTPNT       0x0041
#define CMD_RD_REG_RS_FWDTPNT       0x0040
#define CMD_WR_REG_RS_FWSTART       0x0061
#define CMD_RD_REG_RS_FWSTART       0x0060
#define CMD_WR_RAM_RS               0x0003
#define CMD_RD_RAM_RS               0x0002

#define CMD_WR_REG_AUX_SCI_IF_MODE  0x00A9

/* IDC message identifiers */
#define ACK_RD_REG_IDC_RS           0x0001
#define ACK_WR_REG_IDC_RS           0x0002
#define CMD_WR_REG_IDC_RS_FWCTRL    0x0001
#define CMD_RD_REG_IDC_RS_FWCTRL    0x0000
#define CMD_RD_REG_IDC_RS_FWCRC     0x0020
#define CMD_WR_REG_IDC_RS_FWGP1     0x0041
#define CMD_RD_REG_IDC_RS_FWGP1     0x0040
#define CMD_WR_REG_IDC_RS_FWGP2     0x0061
#define CMD_RD_REG_IDC_RS_FWGP2     0x0060

/* in the memory map the Code Ram starts not at Address 0x00,
   nor directly behind ROM Code */
#define CODE_RAM_OFFSET             0x8000

/** Size of Tx/Rx FIFO SCI block */
#define PEF24628E_SCI_FIFO_SIZE           64

/** Number of internal Receive buffers, each of length PEF24628E_MSG_SIZE */
#define PEF24628E_REC_FIFO_BLK_NUM        20

/** size of one Receive buffer, one message has to fit completely in */
#define PEF24628E_MSG_SIZE                132

/** serial comunication part */
#define SCC_HDLC_NAME                     "/dev/hdlc"

#ifdef INCLUDE_MPI

/** macro for bit manipulation of registers */
#define BFLD(reg, mask, val)  REG_SET(reg,(REG_GET(reg)&~(mask))|((val)&(mask)))

//#define REG_SET(reg,val)   (reg = (val)/*, printk("RS %p=%02x\n\r", &reg, val)*/)
//#define REG_SET(reg,val)	LCD_WriteReg((uint32_t)&(reg),val)
#define REG_SET(reg,val) MPI_WriteReg((uint32_t)&(reg),val)
//#define REG_GET(reg)       reg

//#define REG_GET(reg)       LCD_ReadReg((uint32_t)&(reg))
#define REG_GET(reg)       MPI_ReadReg((uint32_t)&(reg))



#ifdef LINUX
#define SOC4E_ADR_RANGE          0x00008000
#endif

/** MPI register bit definitions */
#define MPI_MPINT_INTIDC      0x01
#define MPI_MPINT_INTSCI      0x02

#define MPI_MPINTEN_IDCEN     0x01
#define MPI_MPINTEN_SCIEN     0x02
#define MPI_MPINTEN_MPILEV    0x04

/**
   MPI Receive message
*/
#define MPI_INTERRUPT_R       0x01
/**
   MPI Receive Underrun Error
*/
#define MPI_INTERRUPT_RUE     0x02
/**
   MPI Receive Overflow Error
*/
#define MPI_INTERRUPT_ROE     0x04
/**
   MPI Transmit Underrun Error
*/
#define MPI_INTERRUPT_TUE     0x08
/**
   MPI Receive Overflow Error
*/
#define MPI_INTERRUPT_TOE     0x10
#define MPI_INTERRUPT_ALL     0x1F

/* reverse to Design Spec! */
#define MPI_CON_TXFFLU        0x01
#define MPI_CON_RXFFLU        0x02
#define MPI_CON_TXMSB         0x04
#define MPI_CON_RXMSB         0x08

/* -------------------------------------------------------------------------- */
/* SCI register bits definitions */
/**
   SCI Overflow
   Idle Flag got lost
*/
#define SCI_INTERRUPT_OVFL    0x80
/**
   SCI Transmit Overflow
   Ingress FIFO overflow.
*/
#define SCI_INTERRUPT_XDOV    0x40
/**
   Interrupt Enable SCI Transmit Pool Ready
   Enable for interrupts sent from SCI to the external host.
*/
#define SCI_INTERRUPT_XPR     0x20
/**
   SCI Transmit Retransmit Message
   Request to re-transmit currently transmitted message (Ingress Direction)
*/
#define SCI_INTERRUPT_XMR     0x10
/**
   SCI Transmit Data Underrun
   Ingress (Transmit) Data Underrun.
*/
#define SCI_INTERRUPT_XDU     0x08
/**
   SCI Receive Pool Full
   Egress (Receive) pool full (with pre-defined number of bytes)
*/
#define SCI_INTERRUPT_RPF     0x04
/**
   SCI Receive Message End
   Egress (Receive) Message End
*/
#define SCI_INTERRUPT_RME     0x02
/**
   Interrupt Enable SCI Receive FIFO Overflow
   Egress (Receive) FIFO overflow
*/
#define SCI_INTERRUPT_RFO     0x01
#define SCI_INTERRUPT_ALL     0xFF

#define SCI_CTRL_RMC          0x10
#define SCI_CTRL_RRES         0x02
#define SCI_CTRL_XRES         0x01

#define SCI_CTRL_HIGH_XME     0x80
#define SCI_CTRL_HIGH_XTF     0x40

/** Receive Interrupt Level */
#define SCI_CFG_H_RIL         0xC0
/** Store Receive Address */
#define SCI_CFG_H_SRA         0x20
/** Receiver Active */
#define SCI_CFG_H_RAC         0x10
/** Receive CRC */
#define SCI_CFG_H_RCRC        0x08
/** Transmit CRC */
#define SCI_CFG_H_XCRC        0x04
/** Control Pad */
#define SCI_CFG_H_PAD         0x02
/** Clock Polarity */
#define SCI_CFG_H_CLKPOL      0x01

/** Write Byte Mode */
#define SCI_CFG_L_WBM         0xC0
/** Read Byte Mode */
#define SCI_CFG_L_RBM         0x30
/** Clock Gating Enable */
#define SCI_CFG_L_CLKGAT      0x08
/** Arbitration Switch */
#define SCI_CFG_L_ARBIT       0x04
/** Duplex Mode Switch */
#define SCI_CFG_L_DUPLEX      0x02
/** Loopback Enable */
#define SCI_CFG_L_LOOP        0x01

/** enable internal SCI clock */
#define SCI_CLK_ENABLE        0x80

/** 000 1/4 of system clock */
#define SCI_CLK_1_4           0x00
/** 1/8 of system clock */
#define SCI_CLK_1_8           0x01 
/** 1/16 of system clock */
#define SCI_CLK_1_16          0x02 
/** 1/32 of system clock */
#define SCI_CLK_1_32          0x03
/** 1/64 of system clock */
#define SCI_CLK_1_64          0x04

/** relevant address space for MPI registers */
#define MPI_REG_SIZE          0x00000020

/** FPGA register definitions */
typedef struct
{
   unsigned char MCR_0;             /* 0x00+MPI_REG_OFFSET */
   unsigned char MCR_1;
   unsigned char MCR_2;
   unsigned char MCR_3;
   unsigned char MAOR_0;            /* 0x04+MPI_REG_OFFSET */
   unsigned char MAOR_1;
   unsigned char MAOR_2;
   unsigned char MAOR_3;

   unsigned char MPI_CON;           /* 0x08 + MPI_REG_OFFSET */
   unsigned char MPI_EGRESS;        /* 0x09 + MPI_REG_OFFSET */
   unsigned char MPI_INGRESS;       /* 0x0a + MPI_REG_OFFSET */
   unsigned char MPI_EFSTAT;        /* 0x0b + MPI_REG_OFFSET */
   unsigned char MPI_EINT;          /* 0x0c + MPI_REG_OFFSET */
   unsigned char MPI_EINT_EN;       /* 0x0d + MPI_REG_OFFSET */
   unsigned char MPI_IINT_EN;       /* 0x0e + MPI_REG_OFFSET */
   unsigned char MPI_IINT;          /* 0x0f + MPI_REG_OFFSET */

   unsigned char SCI_INGRESS;       /* 0x10 + MPI_REG_OFFSET */
   unsigned char SCI_EGRESS;        /* 0x11 + MPI_REG_OFFSET */
   unsigned char SCI_CTRL_L;        /* 0x12 + MPI_REG_OFFSET */
   unsigned char SCI_CTRL_H;        /* 0x13 + MPI_REG_OFFSET */
   unsigned char SCI_CFG_L;         /* 0x14 + MPI_REG_OFFSET */
   unsigned char SCI_CFG_H;         /* 0x15 + MPI_REG_OFFSET */
   unsigned char SCI_REPORT_L;      /* 0x16 + MPI_REG_OFFSET */
   unsigned char SCI_REPORT_H;      /* 0x17 + MPI_REG_OFFSET */
   unsigned char SCI_ACFG_0;        /* 0x18 + MPI_REG_OFFSET */
   unsigned char SCI_ACFG_1;        /* 0x19 + MPI_REG_OFFSET */
   unsigned char SCI_ACFG_2;        /* 0x1a + MPI_REG_OFFSET */
   unsigned char SCI_ACFG_3;        /* 0x1b + MPI_REG_OFFSET */

   unsigned char SCI_1C_NOT_USED;   /* 0x1c + MPI_REG_OFFSET */

   unsigned char SCI_CLKCFG;        /* 0x1d + MPI_REG_OFFSET */
   unsigned char SCI_INTEN;         /* 0x1e + MPI_REG_OFFSET */
   unsigned char SCI_INT;           /* 0x1f + MPI_REG_OFFSET */

} __PACKED__ PEF24628E_MPI_REG_t;

#endif /* INCLUDE_MPI */

/* -------------------------------------------------------------------------- */

/** Rx FIFO entry */
typedef struct
{
   /** Pointer to data */
   IFX_uint8_t *pData;
   /** number of received bytes */
   IFX_uint16_t nBytes;
   /** contains the HDLC header */
   IFX_boolean_t bSendIdcViaSciBridge;
   /** index */
   IFX_uint8_t nIndex;
} PEF24628E_RX_FIFO_t;

/** Tx FIFO entry */
typedef struct
{
   /** Pointer to data */
   volatile IFX_uint8_t *pData;
   /** number of bytes to transmit */
   volatile IFX_uint16_t nBytes;
   /** number of transmitted bytes */
   volatile IFX_uint16_t nSent;
   /** index */
   IFX_uint8_t nIndex;
} PEF24628E_TX_FIFO_t;

/* -------------------------------------------------------------------------- */

/** States of the Receiver state machine */
typedef enum
{
   /** No frame receiving active */
   SCI_RX_IDLE,
   /** Part of frame received, no error */
   SCI_RX_ACTIVE,
   /** Part of frame received, error, discard until frame end */
   SCI_RX_ERROR
} SCI_RX_STATE_t;

/* -------------------------------------------------------------------------- */

/** IDC Download variables */
typedef struct
{
   /** pointer to the firmware imgae */
   IFX_uint8_t *pImage;
   /** current firmware image size */
   IFX_uint32_t image_size;
   /** firmware boot code  size */
   IFX_uint32_t boot_size;
   /** firmware code ram size */
   IFX_uint32_t code_size;
   /** firmware data ram size */
   IFX_uint32_t data_size;
   /** start point of code in the firmware image */
   IFX_uint32_t offset_code;
   /** start point of data in the firmware image */
   IFX_uint32_t offset_data;
   /** start point of boot CRC in the firmware image */
   IFX_uint32_t offset_boot_crc;
   /** start point of code CRC in the firmware image */
   IFX_uint32_t offset_code_crc;
   /** start point of data CRC in the firmware image */
   IFX_uint32_t offset_data_crc;
   /** start point of start address of Code part */
   IFX_uint32_t offset_code_start;
   /** start point of start address of Data part */
   IFX_uint32_t offset_data_start;
} PEF24628E_IDC_FwInfo_t;

/** data for the transport protocol between driver and device. */
typedef struct
{
   /** TX: current Odd/Even flag */
   IFX_int8_t TxOddEven;
   /** TX: last acknowledged Odd/Even flag */
   IFX_int8_t TxLastAckOddEven;
   /** RX: current Odd/Even flag */
   IFX_int8_t RxOddEven;
} PEF24628E_TRANSP_DATA_t;

/** device related data */
typedef struct
{
#ifdef VXWORKS
   /** driver specific parameter, must be first element in struct */
   DEV_HDR DevHdr;
#endif

   /** to see first open */
   IFX_boolean_t bNotFirst;

   /** number of uC instance */
   IFX_uint32_t uc_index;

   /** Hardware message Interface to use for transmit: SCI or MPI */
   PEF24628E_IF_t ActiveIf;

   /** successfully init */
   IFX_boolean_t bInit;

   /** exclusive open */
   IFX_boolean_t bOpen;

   /** data for upstream FIFO - write pointer */
   volatile PEF24628E_RX_FIFO_t *pRxFifoWrite;
   /** data for upstream FIFO - read pointer */
   volatile PEF24628E_RX_FIFO_t *pRxFifoRead;
   /** "RX FIFO is full" */
   IFX_boolean_t bRxFifoFull;
   /** upstream FIFO */
   PEF24628E_RX_FIFO_t RxFifo[PEF24628E_REC_FIFO_BLK_NUM];
   /** pointer to the FIFO buffer */
   IFX_uint8_t   *FifoBuffer;

   /** state of the upstream direction */
   SCI_RX_STATE_t SciRxState;

   /** data for transmit direction */
   PEF24628E_TX_FIFO_t TxFifo;
   /** transmit event */
   //SOC4E_event_t wqTxAck;

   /** transmit error */
   volatile IFX_boolean_t txErr;
   /** acknowledge received */
   volatile IFX_boolean_t bTxAckReceived;

   /** for wakeup of the application */
   //SOC4E_selectQueue_t WakeupList;

   /** to prevent multiple wakeups */
   volatile IFX_boolean_t bNeedWakeUp;
   /** to prevent multiple event wakeups */
   volatile IFX_boolean_t bNeedWakeUpEvent;
   /** data for low level transport protocol */
   PEF24628E_TRANSP_DATA_t TranspData;

   /** last rs answer */
   IFX_uint32_t  last_rs_value;

   /** last rs answer */
   IFX_uint32_t  last_aux_value;

   /** device address for SCI bus, in case of MPI it should be 0x0F */
   IFX_uint8_t   nDevAddress;

   /** If set the communication is done via the MPI-SCI bridge instead
       of using the MPI mailbox. This value is also set if the communication
       is done through SCI-HDLC interface .
       The interface mode should be set to MPI or SCI. */
   IFX_boolean_t bSendIdcViaSciBridge;

   /** SCI part */
      
#ifdef INCLUDE_SCC_HDLC
   /** index of the HDLC channel */
   IFX_uint8_t   nSciHdlcDev;
   
   /** cache of a system value */
   IFX_int32_t scc_fd;

   /** TP acknowledge flags */
   IFX_boolean_t bSendTpAck;
   IFX_boolean_t TpAckNak;
   IFX_uint8_t   TpAckOdd;
   
   IFX_boolean_t bFwStarted;
   
#endif

#ifdef INCLUDE_MPI
   /** IRQ number. If set to zero the polling mode is assumed. */
   IFX_int32_t irq_vector;

   /** pointer to fpga registers */
   volatile PEF24628E_MPI_REG_t *uc_reg;

#ifdef PEF24628E_USE_SCI_MONITOR
   IFX_boolean_t bSCIMonitor;
#endif

   /** number of interrupts occured */
   IFX_vuint32_t nIrqCount;
#endif /* INCLUDE_MPI */   

   /** number of open calls were performed */
   IFX_vuint32_t nOpenCount;

   /** cdm's/ack's flags */
   IFX_uint32_t uCmdAckMtCntr;
   
   /** last sent cmd message id */
   IFX_uint16_t uLastCmdId;

   /** interrupt failures flags */
   IFX_uint32_t uLastAckId;
   
   /** last sent cmd message tcid */
   IFX_uint16_t uLastCmdTcId;
   
   /** interrupt failures flags */
   IFX_uint32_t uStatistics;
   
   /** FW downloaded flag */
   IFX_boolean_t bFwDownloaded;
   
} PEF24628E_DEV_t;

/** devices */
extern PEF24628E_DEV_t *Pef24628e_Devices[PEF24628E_MAX_DEV_NUMBER];

/** what string */
extern const char PEF24628E_WHATVERSION[];

/** Declarations for debug interface, trace */
//SOC4E_PRN_USR_MODULE_DECL ( PEF24628E_DRV );
/** Declarations for debug interface, log - interrupt safe */
//SOC4E_PRN_INT_MODULE_DECL ( PEF24628E_DRV );

extern IFX_boolean_t Pef24628e_Init ( PEF24628E_DEV_t * pDev, PEF24628E_DEV_INIT_t * pDevCfg );

extern IFX_boolean_t Pef24628e_Shutdown ( PEF24628E_DEV_t * pDev );

extern IFX_uint32_t Pef24628e_Exit ( PEF24628E_DEV_t * pDev );

extern IFX_uint32_t Pef24628e_Set_Register
   ( PEF24628E_DEV_t * pDev, IFX_uint32_t regadr, IFX_uint32_t val );

extern IFX_uint32_t Pef24628e_Get_Register
   ( PEF24628E_DEV_t * pDev, IFX_uint32_t regadr, IFX_uint32_t * val );

extern IFX_int32_t Pef24628e_Send_IDC_Msg
   ( PEF24628E_DEV_t * pDev, const IFX_uint8_t * pSrc, IFX_int32_t nLength );

extern IFX_int32_t Pef24628e_Get_IDC_Msg
   ( PEF24628E_DEV_t * pDev, IFX_uint8_t * pDst, IFX_int32_t nLength );

extern IFX_boolean_t Pef24628e_Poll_Check ( PEF24628E_DEV_t * pDev );

extern IFX_boolean_t Pef24628e_DSL_Download
   ( PEF24628E_DEV_t * pDev, IFX_uint8_t * pImage, IFX_uint32_t nLength );

extern IFX_boolean_t Pef24628e_IDC_Download
   ( PEF24628E_DEV_t * pDev, IFX_uint8_t * pImage, IFX_uint32_t nLength );

extern IFX_boolean_t Pef24628e_IDC_Start ( PEF24628E_DEV_t * pDev );

extern IFX_void_t Pef24628e_IntHandler ( PEF24628E_DEV_t * pDev );

extern IFX_void_t Pef24628e_Set_Config ( PEF24628E_DEV_t * pDev, PEF24628E_CONFIG_t * Config );

extern IFX_void_t Pef24628e_Get_Config ( PEF24628E_DEV_t * pDev, PEF24628E_CONFIG_t * Config );

extern IFX_uint32_t Pef24628e_Set_If ( PEF24628E_DEV_t * pDev, PEF24628E_IF_t new_if );

extern IFX_uint32_t Pef24628e_Get_If ( PEF24628E_DEV_t * pDev, PEF24628E_IF_t * current_if );

extern IFX_boolean_t Pef24628e_Send_Aux_Msg
   ( PEF24628E_DEV_t * pDev, IFX_uint8_t reg, IFX_uint8_t param );

extern IFX_boolean_t Pef24628e_Set_Address_Filter
   ( PEF24628E_DEV_t * pDev, IFX_uint16_t mask, IFX_uint16_t addr );

extern IFX_boolean_t Pef24628e_Get_Address_Filter
   ( PEF24628E_DEV_t * pDev, IFX_uint16_t * mask, IFX_uint16_t * addr );

/*@}*/

#endif /* _DRV_PEF24628E_API_H */
