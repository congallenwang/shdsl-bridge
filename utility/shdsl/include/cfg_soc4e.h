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
   Definitions for the SOC-4E library.
*/

#ifndef _cfg_soc4e_h
#define _cfg_soc4e_h

/** interface and types from the upper layer interfaces. */
#include "user_if_SOC4BIS.h"
#include "user_if_SOC4BIS_AUX.h"

/* create prefixed name for config headers SOC4E_CFG_PREFIXED_NAME */
#define SOC4E_CFG_PREFIXED_NAME0(x,y)     x ## y
#define SOC4E_CFG_PREFIXED_NAME1(x,y)     SOC4E_CFG_PREFIXED_NAME0(x,y)
#define SOC4E_CFG_PREFIXED_NAME(name)     SOC4E_CFG_PREFIXED_NAME1(SOC4E_CFG_NAME,name)

#ifndef CFG_INCLUDE
#define CFG_INCLUDE 0
#endif

#if (CFG_INCLUDE==1)

/* Include configuration files */

#if INCLUDE_TERMINAL == 1
#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_default_
#include "cfg_default.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_2wire_CCRR_
#include "SOC4E_2wire_CCRR.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_4wire_CRRC_
#include "SOC4E_4wire_CRRC.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_4wire_RCCR_
#include "SOC4E_4wire_RCCR.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_3pair_CCCC_
#include "SOC4E_3pair_CCCC.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_3pair_RRRR_
#include "SOC4E_3pair_RRRR.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_4pair_CCCC_
#include "SOC4E_4pair_CCCC.h"

#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_4pair_RRRR_
#include "SOC4E_4pair_RRRR.h"

#if 1
#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_simple_
#include "cfg_simple.h"
#endif

#endif /* INCLUDE_TERMINAL == 1 */

#if INCLUDE_REPEATER == 1
#undef SOC4E_CFG_NAME
#define SOC4E_CFG_NAME  cfg_rep1_
#include "cfg_rep1.h"

   #endif /* INCLUDE_REPEATER == 1 */

#endif /* (CFG_INCLUDE==1) */

/* macro table for list of configurations */
/* IMPORTANT: This list should match the cfg_*.h files included above! */
/* format: enum, name string, element prefix, related board config */

#define e_CFG_DEFAULT   e_CFG_SIMPLE

#if INCLUDE_TERMINAL == 1
#define SOC4E_TERMINAL_CFG     \
   gen_cfg_list_entry(e_CFG_2WIRE_CCRR,   \
      "2-wire CCRR E1", cfg_2wire_CCRR_, e_BOARD_CFG_E1_PCM8_2,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_2WIRE_CCRR_T1,   \
      "2-wire CCRR T1", cfg_2wire_CCRR_, e_BOARD_CFG_T1_PCM1,     SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_4WIRE_CRRC,   \
      "4-wire CRRC E1", cfg_4wire_CRRC_, e_BOARD_CFG_E1_PCM8_2,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_4WIRE_RCCR,   \
      "4-wire RCCR E1", cfg_4wire_RCCR_, e_BOARD_CFG_E1_PCM8_2,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_4WIRE_CRRC_T1,   \
      "4-wire CRRC T1", cfg_4wire_CRRC_, e_BOARD_CFG_T1_PCM1,     SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_3PAIR_CCCC,   \
      "3-pair CCCC E1", cfg_3pair_CCCC_, e_BOARD_CFG_E1_PCM8_1,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_3PAIR_RRRR,   \
      "3-pair RRRR E1", cfg_3pair_RRRR_, e_BOARD_CFG_E1_PCM8_1,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_4PAIR_CCCC,   \
      "4-pair CCCC E1", cfg_4pair_CCCC_, e_BOARD_CFG_E1_PCM8_2,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_4PAIR_RRRR,   \
      "4-pair RRRR E1", cfg_4pair_RRRR_, e_BOARD_CFG_E1_PCM8_2,   SEPARATOR)  \
   gen_cfg_list_entry(e_CFG_SIMPLE,    \
      "Simple Config (Only 0, STU-R)", cfg_simple_, e_BOARD_CFG_DEFAULT,   SEPARATOR) \
   /* define end */

#else /* INCLUDE_TERMINAL == 1 */
#define SOC4E_TERMINAL_CFG    /* empty */
#endif /* INCLUDE_TERMINAL == 1 */


#if INCLUDE_REPEATER == 1
#define SOC4E_REPEATER_CFG    \
   gen_cfg_list_entry(e_CFG_REP1,   "Dual Repeater   CCRR (0-3/1-2)",  cfg_rep1_, e_BOARD_CFG_REPEATER, SEPARATOR)  \
   /* define end */

#else /* INCLUDE_REPEATER == 1 */
#define SOC4E_REPEATER_CFG    /* empty */
#endif /* INCLUDE_REPEATER == 1 */

/* macro table for list of configurations */
#define SOC4E_CONFIG_LIST  \
   SOC4E_TERMINAL_CFG      \
   SOC4E_REPEATER_CFG      \
   gen_cfg_list_entry(e_CFG_LAST, NULL, cfg_last_, e_BOARD_CFG_DEFAULT, NO_SEPARATOR)


/* prepare the macro table expansion for typedef enum */
#undef gen_cfg_list_entry
#define gen_cfg_list_entry(x,y,z,b,sep) x sep
/* separator for typedef enum is ',' */
#undef  SEPARATOR
#define SEPARATOR ,
/* specify no separator for the last table entry */
#undef  NO_SEPARATOR
#define NO_SEPARATOR

typedef enum
{
   SOC4E_CONFIG_LIST
} E_CFG_TYPE;


#endif /* _cfg_soc4e_h */

