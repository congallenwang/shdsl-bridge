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
   Common definitions for all boards.
*/

#ifndef _board_h
#define _board_h

/** supported target boards */
#define BOARD_SOC4E_EB     1
#define BOARD_SOC4E_166    2
#define BOARD_USER1        3
#define BOARD_USER2        4

#ifndef BOARD_TYPE
//#warning Please define your board type! Assuming BOARD_SOC4E_EB
#define BOARD_TYPE         BOARD_SOC4E_EB
#endif

#if BOARD_TYPE == BOARD_SOC4E_EB
#include "board_soc4e_eb.h"
#elif BOARD_TYPE == BOARD_SOC4E_166
#include "board_soc4e_166.h"
#elif BOARD_TYPE == BOARD_USER1
#include "board_user1.h"
#elif BOARD_TYPE == BOARD_USER2
#include "board_user2.h"
#endif


/** Board Register modification entry */
typedef struct board_reg_cfg_entry board_reg_cfg_entry_t;
struct board_reg_cfg_entry
{
   E_CFG_BOARD_REGISTER_DEST dest;
   UINT32 address;
   UINT16 value;
   UINT16 mask;
};

typedef struct
{
   /** device interface should be used */
   UINT32 nInterfaceMode;
   /** if set the polling mode instead of the interrupt mode is used */
   UINT32  bPollingMode;
   /** clock of the SCI interface, used for the HDLC driver */
   UINT32 nSciClock;
   /** maximum number of devices should be accessed */
   UINT32 nMaxDevNumber;
   /** maximum lines of devices should be accessed */
   UINT32 nMaxLineNumber;
} BOARD_Configuration_t;

//#include "cfg_board.h"
typedef enum
{
   BOARD_CONFIG_LIST
} E_BOARD_CFG_TYPE;

#define VOID void

extern BOOL board_hardware_init(const BOARD_Configuration_t *pDeviceConfiguration);
extern BOOL board_hardware_exit(VOID);
extern BOOL board_hardware_poll(VOID);
extern BOOL board_set_channel_led(UINT8 ch, UINT8 state);
#if INCLUDE_REPEATER == 1
extern BOOL board_set_external_loop(UINT8 ch1, UINT8 ch2, BOOL enable);
#endif /* INCLUDE_REPEATER == 1 */
extern BOOL board_set_config(E_BOARD_CFG_TYPE new_config);
extern BOOL board_mwire_delaymeasurement_start(UINT8 channel_mask, UINT8 risingEdge);
extern BOOL board_mwire_delaymeasurement_result(UINT8 channel_mask, INT8 *pFrameShifts);

#endif /* _board_h */

