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
   Common definitions for the SOC4E EvalBoard.
*/

#ifndef _board_soc4e_eb_h
#define _board_soc4e_eb_h

#include "drv_pef24628e_interface.h"
#define DRV_EASY24644_NAME       "/dev/easy24628"

/** FLASH - address range: base address */
#define FLASH_BASE_ADR_PHY       0xC0000000
/** FLASH - address range: available address range */
#define FLASH_ADR_RANGE          0x00100000
/** FLASH - address range: used address range */
#define FLASH_ADR_RANGE_SIZE     FLASH_ADR_RANGE

/** CPLD - address range: base address */
#define CPLD_BASE_ADR_PHY        0xC0100000
/** CPLD - address range: available address range */
#define CPLD_ADR_RANGE           0x00100000
/** CPLD - address range: used address range */
#define CPLD_ADR_RANGE_SIZE      CPLD_ADR_RANGE

/** ADD ON Extension - address range: base address */
#define ADDON_BASE_ADR_PHY       0xC0400000
/** ADD ON Extension - address range: available address range */
#define ADDON_ADR_RANGE          0x00100000
/** ADD ON Extension - address range: used address range */
#define ADDON_ADR_RANGE_SIZE     ADDON_ADR_RANGE

/** QFALC - address range: base address */
#define QFALC_BASE_ADR_PHY       0xC0000000
/** QFALC - address range: available address range */
#define QFALC_ADR_RANGE          0x00008000
/** QFALC - address range: used address range */
#define QFALC_ADR_RANGE_SIZE     QFALC_ADR_RANGE

/** FPGA - address range: base address */
#define FPGA_BASE_ADR_PHY        0xC0500000
/** FPGA - address range: available address range */
#define FPGA_ADR_RANGE           0x00100000
/** FPGA - address range: used address range */
#define FPGA_ADR_RANGE_SIZE      FPGA_ADR_RANGE

/** SOC4E - address range: base address */
#define SOC4E_BASE_ADR_PHY       0xC0200000
/** SOC4E - address range: available address range */
#define SOC4E_ADR_RANGE          0x00008000
/** SOC4E - address range: used address range */
#define SOC4E_ADR_RANGE_SIZE     SOC4E_ADR_RANGE

/* direct mapping of addresses */
#define FLASH_BASE_ADR           FLASH_BASE_ADR_PHY
#define CPLD_BASE_ADR            CPLD_BASE_ADR_PHY
#define ADDON_BASE_ADR           ADDON_BASE_ADR_PHY
#define FPGA_BASE_ADR            FPGA_BASE_ADR_PHY
#define QFALC_BASE_ADR           QFALC_BASE_ADR_PHY
#define SOC4E_BASE_ADR           SOC4E_BASE_ADR_PHY

/** CPLD register for FPGA programming */
#define CPLD_VERSION       (*(volatile UINT8*)((UINT8*)CPLD_BASE_ADR))
#define CPLD_FPGA_INIT     (*(volatile UINT8*)((UINT8*)CPLD_BASE_ADR+1))
#define CPLD_FPGA_STATUS   (*(volatile UINT8*)((UINT8*)CPLD_BASE_ADR+2))

/** FPGA: CPLD FPGA config register */
#define FPGA_CPLD_FPGA_CONF_FSEL_0       0x01
#define FPGA_CPLD_FPGA_CONF_FSEL_1       0x02
#define FPGA_CPLD_FPGA_CONF_RESRV        0x04
#define FPGA_CPLD_FPGA_CONF_RAM_ENA      0x08
#define FPGA_CPLD_FPGA_CONF_FLASH_ENA    0x10
#define FPGA_CPLD_FPGA_CONF_FP_RST       0x20
#define FPGA_CPLD_FPGA_CONF_FP_MODE      0x40
#define FPGA_CPLD_FPGA_CONF_CONFIG       0x80

#define FPGA_CPLD_FPGA_CONF_FSEL_ALL     (FPGA_CPLD_FPGA_CONF_FSEL_0 |\
                                          FPGA_CPLD_FPGA_CONF_FSEL_1)
/** FPGA: CPLD FPGA setup for flash programming */
#define FPGA_CPLD_FPGA_CONF_FLASH_PROG_MODE (FPGA_CPLD_FPGA_CONF_CONFIG | \
                                             FPGA_CPLD_FPGA_CONF_FP_MODE | \
                                             FPGA_CPLD_FPGA_CONF_FLASH_ENA)
/** FPGA: CPLD FPGA setup of reset value */
#define FPGA_CPLD_FPGA_CONF_RESET_MODE   (FPGA_CPLD_FPGA_CONF_CONFIG | \
                                          FPGA_CPLD_FPGA_CONF_FP_MODE | \
                                          FPGA_CPLD_FPGA_CONF_FLASH_ENA)

/** FPGA: CPLD FPGA status register */
#define FPGA_CPLD_FPGA_STAT_CONF_DONE  0x01
#define FPGA_CPLD_FPGA_STAT_INIT_DONE  0x02
#define FPGA_CPLD_FPGA_STAT_STATUS     0x04
#define FPGA_CPLD_FPGA_STAT_DIP_1      0x08
#define FPGA_CPLD_FPGA_STAT_DIP_2      0x10
#define FPGA_CPLD_FPGA_STAT_DIP_3      0x20
#define FPGA_CPLD_FPGA_STAT_DIP_4      0x40
#define FPGA_CPLD_FPGA_STAT_RESRV      0x80

#define FPGA_CPLD_FPGA_STAT_OKAY       (FPGA_CPLD_FPGA_STAT_CONF_DONE | \
                                        FPGA_CPLD_FPGA_STAT_INIT_DONE | \
                                        FPGA_CPLD_FPGA_STAT_STATUS)

#define FPGA_CPLD_FPGA_STAT_OKAY_SUB   (FPGA_CPLD_FPGA_STAT_CONF_DONE | \
                                        FPGA_CPLD_FPGA_STAT_STATUS)


#define FPGA_CPLD_FPGA_STAT_DIP_ALL    (FPGA_CPLD_FPGA_STAT_DIP_1 | \
                                        FPGA_CPLD_FPGA_STAT_DIP_2 | \
                                        FPGA_CPLD_FPGA_STAT_DIP_3 | \
                                        FPGA_CPLD_FPGA_STAT_DIP_4)

/*------------------------------------------*/
/* Definitions for the FPGA SOC4E Register */
/*------------------------------------------*/

/** FPGA: SOC4E Control register */
#define FPGA_SOC4E_CTRL_RESET          0x0001
#define FPGA_SOC4E_CTRL_ADDR_0         0x0002
#define FPGA_SOC4E_CTRL_ADDR_1         0x0004
#define FPGA_SOC4E_CTRL_ADDR_2         0x0008
#define FPGA_SOC4E_CTRL_ADDR_3         0x0010
#define FPGA_SOC4E_CTRL_TP1            0x0020
#define FPGA_SOC4E_CTRL_TP2            0x0040
#define FPGA_SOC4E_CTRL_OE_TP          0x0080
#define FPGA_SOC4E_CTRL_OE_JTAG        0x0100
#define FPGA_SOC4E_CTRL_AUX_MODE       0x0200

#define FPGA_SOC4E_CTRL_ADDR_ALL      (FPGA_SOC4E_CTRL_ADDR_0 |\
                                       FPGA_SOC4E_CTRL_ADDR_1 |\
                                       FPGA_SOC4E_CTRL_ADDR_2 |\
                                       FPGA_SOC4E_CTRL_ADDR_3)

/** FPGA: SOC4E Multimode control register */
#define FPGA_SOC4E_MULTI_RST_1         0x1000
#define FPGA_SOC4E_MULTI_RST_2         0x2000
#define FPGA_SOC4E_MULTI_RST_3         0x4000

/** FPGA: SOC4E QuadFALC multiplexer register */
#define FPGA_SOC4E_FALC_MUX_RESET      0x8000

/** FPGA SOC4E Control register group */
#define FPGA_SOC4E_S0_MUX_OFFSET       0xA0000
#define FPGA_SOC4E_S0_CTRL_OFFSET      0xA0002
#define FPGA_SOC4E_S0_CLKDIV_OFFSET    0xA0004
#define FPGA_SOC4E_S1_MUX_OFFSET       0xA0010
#define FPGA_SOC4E_S1_CTRL_OFFSET      0xA0012
#define FPGA_SOC4E_S1_CLKDIV_OFFSET    0xA0014
#define FPGA_SOC4E_S2_MUX_OFFSET       0xA0020
#define FPGA_SOC4E_S2_CTRL_OFFSET      0xA0022
#define FPGA_SOC4E_S2_CLKDIV_OFFSET    0xA0024
#define FPGA_SOC4E_S3_MUX_OFFSET       0xA0030
#define FPGA_SOC4E_S3_CTRL_OFFSET      0xA0032
#define FPGA_SOC4E_S3_CLKDIV_OFFSET    0xA0034
#define FPGA_SOC4E_CTRL_OFFSET         0xA0040
#define FPGA_SOC4E_MULTI_SOC4E_OFFSET  0xA0042
#define FPGA_SOC4E_FALC_MUX_OFFSET     0xA0052

#define FPGA_HDLC_CTRL_OFFSET          0xA00E0
#define FPGA_BRD_CTRL_OFFSET           0xA00F0

#define FPGA_SOC4E_VERSION_OFFSET      0xA00FE

/* simplify access to FPGA register */
#define FPGA_REG(ofs)                  (*(VUINT8*)(FPGA_BASE_ADR+(ofs)))

/* access several register */
#define FPGA_SOC4E_CTRL_REG            FPGA_REG(FPGA_SOC4E_CTRL_OFFSET)
#define FPGA_SOC4E_MULTI_SOC4E_REG     FPGA_REG(FPGA_SOC4E_MULTI_SOC4E_OFFSET)
#define FPGA_SOC4E_FALC_MUX_REG        FPGA_REG(FPGA_SOC4E_FALC_MUX_OFFSET)
#define FPGA_BRD_CTRL_REG              FPGA_REG(FPGA_BRD_CTRL_OFFSET)
#define FPGA_VERSION                   FPGA_REG(FPGA_SOC4E_VERSION_OFFSET)

/* simplify access to QFalc register */
#define QFALC_REG(ofs)                 (*(VUINT8*)(QFALC_BASE_ADR+(ofs)))

/** QuadFALC: version register */
#define QFALC_VERSION_OFFSET           0x4A

#define QFALC_VERSION_1_3  2
#define QFALC_VERSION_2_1  5


/** Optional DSL Firmware in Flash */
#define DSL_FIRMWARE_FLASH_ADDRESS      0x40080000
/** Optional IDC Firmware in Flash */
#define IDC_FIRMWARE_FLASH_ADDRESS      0x400c0000

/** Board Register Types */
typedef enum
{
   e_BOARD_FPGA,
   e_BOARD_FALC,
   e_LAST_BOARD_DESTINATION
} E_CFG_BOARD_REGISTER_DEST;

#endif /* _board_soc4e_eb_h */
