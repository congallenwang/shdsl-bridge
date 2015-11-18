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
   Configuration of the SOC4E library.
*/

#ifndef _prj_config_h
#define _prj_config_h

//#include "drv_easy24644_cs.h" /* base address, IRQ number */

/**
   Maximum number of devices supported.
*/
#ifndef PEF24628E_MAX_DEV_NUMBER
#define PEF24628E_MAX_DEV_NUMBER       1
#endif

/**
   Maximum number of lines per device
*/
#ifndef PEF24628E_MAX_LINES_PER_DEVICE
#define PEF24628E_MAX_LINES_PER_DEVICE 4
#endif

/**
   Maximum of DSL lines.
*/
#define PEF24628E_MAX_LINE_NUMBER      (PEF24628E_MAX_LINES_PER_DEVICE*PEF24628E_MAX_DEV_NUMBER)

/**
   Interrupt numbers. If set to zero the device is in polling mode
*/
#if PEF24628E_MAX_DEV_NUMBER == 1
#define IRQ_INIT  {SOC4E_0_IRQ}
#define BASE_ADDRESS_INIT  {SOC4E_0_BASE_ADR_PHY}
#endif

#if PEF24628E_MAX_DEV_NUMBER == 2
#define IRQ_INIT  { SOC4E_1_IRQ, SOC4E_0_IRQ}
#define BASE_ADDRESS_INIT  {SOC4E_1_BASE_ADR_PHY, SOC4E_0_BASE_ADR_PHY}
#endif

/**
   Include terminal configurations.
   This option also controls the inclusion of code only necessary for
   terminals.
*/
#ifndef INCLUDE_TERMINAL
#define INCLUDE_TERMINAL               1
#endif


/**
   Include regenerator configurations.
   This option also controls the inclusion of code only necessary for
   repeater (e.g. EOC forwarding).
*/
#ifndef INCLUDE_REPEATER
#define INCLUDE_REPEATER               1
#endif


/**
   Include EOC handling for non regenerator configurations.
   This option must be activated if an EOC handler should be added to
   this software.
   It might be necessary to add additional code to the provided sources
   to get necessary information like line state or performance values.
   This EOC handler is not included in this software package!
*/
#ifndef INCLUDE_EOC_HANDLING
#define INCLUDE_EOC_HANDLING           0
#endif


/**
   To include MWire suppport set to 1
*/
#ifndef INCLUDE_MWIRE
#define INCLUDE_MWIRE                  0
#endif


/**
   Use of VT100 control sequences.
   This option controls how the highlighting for the menu title should be done.
   For examples look at the beginning of the file "lib_menu.c".
*/
#ifndef USE_VT100
#if defined(KEIL) && defined(NO_HARDWARE)
#define USE_VT100                      0
#else
#define USE_VT100                      3
#endif
#endif /* USE_VT100 */


#endif /* _prj_config_h */

