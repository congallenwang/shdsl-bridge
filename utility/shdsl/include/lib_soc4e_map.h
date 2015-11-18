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

/** \file
   Map the comapact package calls to the driver calls.
*/

#ifndef _lib_soc4e_map_h
#define _lib_soc4e_map_h

/* ============================= */
/* Includes                      */
/* ============================= */

#include "lib_sysdep.h"
#include "shdsl_board.h"
#include "lib_soc4e.h"

#include "user_if_SOC4BIS.h"
#include "user_if_SOC4BIS_AUX.h"
#include "user_if_SOC4BIS_Ramshell.h"

#include "drv_pef24628e_interface.h"

#define PEF24628E_NAME             "/dev/soc4e"
#define PEF24628E_MSG_SIZE          260

/** PAMDSL Tunnel Messages */
#define CMD_TNL_PAMDSL_0_MSG_ID     0x180
#define CMD_TNL_PAMDSL_MSG_ID(Ch)   (CMD_TNL_PAMDSL_0_MSG_ID | (Ch))

typedef struct
{
   /** current Odd/Even flag */
   UINT8 TxOddEven;        
   /** last acknowledged Odd/Even flag */
   UINT8 TxLastAckOddEven; 
   /** RX: current Odd/Even flag */
   UINT8 RxOddEven;        
   /** RX: own ack message (cached) */
   UINT8 AckMsg[4];        
} __attribute__ ((packed)) PEF24624_TRANSP_DATA;
 
typedef struct
{
   UINT8 header[4];
} SDFE4_MessageHeader_t; 

/* ============================= */
/* Global function definition    */
/* ============================= */

/*
   Initialize the required interfaces and starts the download of the firmware.
*/
BOOL soc4e_drv_init(const BOARD_Configuration_t *pDeviceConfiguration);

/*
   Initialize the required interfaces and starts the download of the firmware.
*/
BOOL soc4e_drv_exit(VOID);

/*
   Checks ack from AUX or RAMSHELL.
*/
BOOL soc4e_check_aux_rs_ack(VOID);

/*
   Creates an AUX message from parameters and sends it to SCI.
*/
BOOL soc4e_send_aux_msg(UINT8 device, UINT8 reg, UINT8 param, BOOL check);

/*
   Creates a RAMSHELL message from parameters and sends it to SCI.
   Only used for firmware download.
*/
BOOL soc4e_send_rs_msg(UINT8 device, UINT8 opcd, UINT32 param, UINT8 *pSrc, INT16 nLength, BOOL check);

/*
   Creates a PamDSL message from parameters and sends it to SCI.
*/
BOOL soc4e_send_pamdsl_msg(UINT8 ch, UINT16 msg_id, VOID const * pSrc, UINT16 nLength);

/*
   Poll for messages received from SOC-4E.
*/
BOOL soc4e_drv_poll( UINT8 device, UINT16 idc_msg_id_expected);

/*
   Creates a IDC message from parameters and sends it to SCI.
*/
BOOL soc4e_send_idc_msg(UINT8 device, UINT16 msg_id, VOID const * pSrc, UINT16 nLength);

/*
   Switch SCI monitor ON
*/
BOOL soc4e_sci_monitor_on( VOID );

/*
   Switch SCI monitor OFF
*/
BOOL soc4e_sci_monitor_off( VOID );

#endif /* _lib_soc4e_map_h */
