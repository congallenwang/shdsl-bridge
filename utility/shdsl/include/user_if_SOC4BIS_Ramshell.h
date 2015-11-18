/******************************************************************************

                               Copyright (c) 2005
                            Infineon Technologies AG
                  St. Martin Strasse 53; 81669 Munich, Germany

  THE DELIVERY OF THIS SOFTWARE AS WELL AS THE HEREBY GRANTED NON-EXCLUSIVE, 
  WORLDWIDE LICENSE TO USE, COPY, MODIFY, DISTRIBUTE AND SUBLICENSE THIS 
  SOFTWARE IS FREE OF CHARGE.

  THE LICENSED SOFTWARE IS PROVIDED "AS IS" AND INFINEON EXPRESSLY DISCLAIMS 
  ALL REPRESENTATIONS AND WARRANTIES, WHETHER EXPRESS OR IMPLIED, INCLUDING 
  WITHOUT LIMITATION, WARRANTIES OR REPRESENTATIONS OF WORKMANSHIP, 
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, DURABILITY, THAT THE 
  OPERATING OF THE LICENSED SOFTWARE WILL BE ERROR FREE OR FREE OF ANY THIRD 
  PARTY CLAIMS, INCLUDING WITHOUT LIMITATION CLAIMS OF THIRD PARTY INTELLECTUAL 
  PROPERTY INFRINGEMENT. 

  EXCEPT FOR ANY LIABILITY DUE TO WILLFUL ACTS OR GROSS NEGLIGENCE AND EXCEPT 
  FOR ANY PERSONAL INJURY INFINEON SHALL IN NO EVENT BE LIABLE FOR ANY CLAIM 
  OR DAMAGES OF ANY KIND, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
  DEALINGS IN THE SOFTWARE.

******************************************************************************/

#ifndef _SDFE4_RAMSHELL_129_H
#define _SDFE4_RAMSHELL_129_H

#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#define __PACKED__ __attribute__ ((packed))
#elif !defined (__PACKED__)
#define __PACKED__ /* nothing */
#endif



/** \addtogroup SDFE4_RAMSHELL SDFE4_RAMSHELL */

/*@{*/


/* constant defines */


 #define  RSTA_TA  0x01 
 #define  RSTA_CR  0x02 
 #define  RSTA_SA0  0x04 
 #define  RSTA_SA1  0x08 
 #define  RSTA_RAB  0x10 
 #define  RSTA_CRC  0x20 
 #define  RSTA_RDO  0x40 
 #define  RSTA_VFR  0x80 


/** \addtogroup SDFE4_RAMSHELL_Common_Messages Common Messages */

/*@{*/


/* message identifiers */


 #define  ACK_RD_REG_RS  0x0001 
 #define  ACK_WR_REG_RS  0x0002 
 #define  CMD_WR_REG_RS_FWCTRL  0x0001 
 #define  CMD_RD_REG_RS_FWCTRL  0x0000 
 #define  CMD_RD_REG_RS_FWCRC  0x0020 
 #define  CMD_WR_REG_RS_FWDTPNT  0x0041 
 #define  CMD_RD_REG_RS_FWDTPNT  0x0040 
 #define  CMD_WR_REG_RS_FWSTART  0x0061 
 #define  CMD_RD_REG_RS_FWSTART  0x0060 
 #define  CMD_WR_RAM_RS  0x0003 
 #define  CMD_RD_RAM_RS  0x0002 
 #define  ACK_RD_REG_RS_S  "ACK_RD_REG_RS" 
 #define  ACK_WR_REG_RS_S  "ACK_WR_REG_RS" 
 #define  CMD_WR_REG_RS_FWCTRL_S  "CMD_WR_REG_RS_FWCTRL" 
 #define  CMD_RD_REG_RS_FWCTRL_S  "CMD_RD_REG_RS_FWCTRL" 
 #define  CMD_RD_REG_RS_FWCRC_S  "CMD_RD_REG_RS_FWCRC" 
 #define  CMD_WR_REG_RS_FWDTPNT_S  "CMD_WR_REG_RS_FWDTPNT" 
 #define  CMD_RD_REG_RS_FWDTPNT_S  "CMD_RD_REG_RS_FWDTPNT" 
 #define  CMD_WR_REG_RS_FWSTART_S  "CMD_WR_REG_RS_FWSTART" 
 #define  CMD_RD_REG_RS_FWSTART_S  "CMD_RD_REG_RS_FWSTART" 
 #define  CMD_WR_RAM_RS_S  "CMD_WR_RAM_RS" 
 #define  CMD_RD_RAM_RS_S  "CMD_RD_RAM_RS" 



/* message elements: ACK_RD_REG_RS */


 #define  ACK_RD_REG_RS_rsta_S  L"rsta" 
 #define  ACK_RD_REG_RS_value_S  L"value" 



/* message elements: ACK_WR_REG_RS */


 #define  ACK_WR_REG_RS_rsta_S  L"rsta" 



/* message elements: CMD_WR_REG_RS_FWCTRL */


 #define  CMD_WR_REG_RS_FWCTRL_fwctrl_S  L"fwctrl" 



/* message elements: CMD_WR_REG_RS_FWDTPNT */


 #define  CMD_WR_REG_RS_FWDTPNT_fwdtpnt_S  L"fwdtpnt" 



/* message elements: CMD_WR_REG_RS_FWSTART */


 #define  CMD_WR_REG_RS_FWSTART_fwstart_S  L"fwstart" 



/* message elements: CMD_WR_RAM_RS */


 #define  CMD_WR_RAM_RS_addr_S  L"addr" 
 #define  CMD_WR_RAM_RS_data0_S  L"data0" 
 #define  CMD_WR_RAM_RS_data1_S  L"data1" 



/* message elements: CMD_RD_RAM_RS */


 #define  CMD_RD_RAM_RS_addr_S  L"addr" 



/* message definitions */

/** message: ACK_RD_REG_RS */

typedef struct ack_rd_reg_rs_s 
{ 
  /** Receive Status */ 
  UINT8  rsta; 
  /** Value */ 
  UINT32  value; 
} __PACKED__ ack_rd_reg_rs_t; 


/** message: ACK_WR_REG_RS */

typedef struct ack_wr_reg_rs_s 
{ 
  /** Receive Status */ 
  UINT8  rsta; 
} __PACKED__ ack_wr_reg_rs_t; 


/** message: CMD_WR_REG_RS_FWCTRL */

typedef struct cmd_wr_reg_rs_fwctrl_s 
{ 
  /** FWCTRL */ 
  UINT32  fwctrl; 
} __PACKED__ cmd_wr_reg_rs_fwctrl_t; 


/** message: CMD_WR_REG_RS_FWDTPNT */

typedef struct cmd_wr_reg_rs_fwdtpnt_s 
{ 
  /** FWDTPNT */ 
  UINT32  fwdtpnt; 
} __PACKED__ cmd_wr_reg_rs_fwdtpnt_t; 


/** message: CMD_WR_REG_RS_FWSTART */

typedef struct cmd_wr_reg_rs_fwstart_s 
{ 
  /** FWSTART */ 
  UINT32  fwstart; 
} __PACKED__ cmd_wr_reg_rs_fwstart_t; 


/** message: CMD_WR_RAM_RS */

typedef struct cmd_wr_ram_rs_s 
{ 
  /** ADDR */ 
  UINT32  addr; 
  /** DATA0 */ 
  UINT32  data0; 
  /** DATA1 */ 
  UINT32  data1; 
} __PACKED__ cmd_wr_ram_rs_t; 


/** message: CMD_RD_RAM_RS */

typedef struct cmd_rd_ram_rs_s 
{ 
  /** ADDR */ 
  UINT32  addr; 
} __PACKED__ cmd_rd_ram_rs_t; 

/*@}*/ /* Common Messages */

typedef union SDFE4_RAMSHELL_u
{

 /** message: ACK_RD_REG_RS */ 
 ack_rd_reg_rs_t  ack_rd_reg_rs_m;

 /** message: ACK_WR_REG_RS */ 
 ack_wr_reg_rs_t  ack_wr_reg_rs_m;

 /** message: CMD_WR_REG_RS_FWCTRL */ 
 cmd_wr_reg_rs_fwctrl_t  cmd_wr_reg_rs_fwctrl_m;

 /** message: CMD_WR_REG_RS_FWDTPNT */ 
 cmd_wr_reg_rs_fwdtpnt_t  cmd_wr_reg_rs_fwdtpnt_m;

 /** message: CMD_WR_REG_RS_FWSTART */ 
 cmd_wr_reg_rs_fwstart_t  cmd_wr_reg_rs_fwstart_m;

 /** message: CMD_WR_RAM_RS */ 
 cmd_wr_ram_rs_t  cmd_wr_ram_rs_m;

 /** message: CMD_RD_RAM_RS */ 
 cmd_rd_ram_rs_t  cmd_rd_ram_rs_m;
} __PACKED__ SDFE4_RAMSHELL_t; 
#endif

/*@}*/ /* SDFE4_RAMSHELL */

