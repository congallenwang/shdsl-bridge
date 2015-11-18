/******************************************************************************

                               Copyright (c) 2010
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/


#ifndef _IDC_ONLINEMESSAGES_H_
#define _IDC_ONLINEMESSAGES_H_

/** \file
   This section describes the basic data types used for the IDC messages
*/

#ifndef __PACKED__
   #if defined (__GNUC__) || defined (__GNUG__)
      /* GNU C or C++ compiler */
      #define __PACKED__ __attribute__ ((packed))
   #else
      /* Byte alignment adjustment */
      #pragma pack(1)
      #define __PACKED__      /* nothing */
   #endif
   #define __PACKED_DEFINED__ 1
#endif


/** @defgroup _IDC_ONLINEMESSAGES_ Basic Data Types
 *  @{
 */

#ifdef __cplusplus
   extern "C" {
#endif

/* ----- Include section ----- */
/* ----- Include section (End) ----- */
/** This is an unsigned 32-bit data type */
#include "ifx_types.h"
//typedef unsigned int IFX_uint32_t;
//IFX_uint8_t

/* ----- Define section ----- */
/* ----- Define section (End) ----- */

/**
   IDC error codes ...
*/
/** Command processed without errors */
#define RC_POSITIVE 0
/** Something went wrong */
#define RC_NEGATIVE 1
/** Command not allowed */
#define RC_DENIED 2
/** Parameter out of range */
#define RC_PARAM_RANGE 3
/** Parameter not allowed for current configuration */
#define RC_PARAM_CONFIG 4
/** Invalid payload length */
#define RC_PAYLOAD_LEN 5
/** Resource occupied */
#define RC_RES_OCC 6
/** FW exception occurred */
#define RC_FW_ERROR 7
/** PMD Channel not responding */
#define RC_PMD_CH_DOWN 8
/** Resource level is low */
#define RC_RES_LOW 9
/** Invalid Embedded Command */
#define RC_INV_EMB_CMD 10


/**
   Common defines used in the messages
*/
/** Disable a state. */
#define IFX_DISABLE 0
/** Enable a state */
#define IFX_ENABLE 1
/** Odd parity */
#define ODD_PARITY 0
/** Even parity */
#define EVEN_PARITY 1
/** True value */
#define IFX_TRUE 1
/** True value */
#define IFX_FALSE 0
/** Counter status OK */
#define CNTR_OK 0
/** One or more counters have been reset */
#define CNTR_RESET 1
/** Overflow occurred for one or more counters */
#define CNTR_OVFL 2
/** One or more counters have been reset and overflow has occurred */
#define CNTR_RESET_OVFL 3
/** In working order */
#define READY 0
/** Out of working order */
#define NOT_READY 1
/** Option is not supported */
#define NOT_SUPPORTED 0
/** Option is supported */
#define SUPPORTED 1
/** Mode is passive */
#define PASSIVE 0
/** Mode is active */
#define ACTIVE 1
/** Internal mode is active */
#define INTERNAL 0
/** Transparent mode is active */
#define TRANSPARENT 1


/**
   Defines used in the general configuration messages
*/
/** HDLC-TC Layer */
#define HDLC_TC_LAYER 0
/** EFM-TC LayerDuring G.hs the IEEE tree will be used.Applicable for STU-C and
   STU-R.Default setting if EFM TC is selected by pin strapping and the flow is not
   modified via CMD_TC_FlowModify. It is used for legacy mode. */
#define EFM_TC_LAYER 1
/** ATM-TC Layer */
#define ATM_TC_LAYER 3
/** Set the TC layer to HDLC and enable the full capabilites */
#define HDLC_AUTO_TC_DETECT 0x10
/** Set the TC layer to EFM and enable the full capabilites. */
#define EFM_AUTO_TC_DETECT 0x11
/** Set the TC layer to ATM and enable the full capabilites. */
#define ATM_AUTO_TC_DETECT 0x13
/** Use the same TC Layer */
#define SAME_TC_LAYER 7
/** No TC Layer is used */
#define NO_TC_LAYER 8
/** Status pins not enabled (default) */
#define NOT_ENABLED 0
/** Cross talk canceller enable */
#define _XTALK 3
/** Forward error correction enable */
#define _FEC 5
/** The power source is taken from the span */
#define SPAN_POWERED 0
/** The power source is taken from local power supply */
#define LOCAL_POWERED 1
/** Standard compliant line probing */
#define IOP_PMMS_NORMAL 0
/** Line probing mode for interaction with Globespan 2.5.x and 3.0.x based transceivers */
#define IOP_PMMS_GSPN_25x_30x 1
/** Applicable for STU-R only.The PHY is configured that it selects the 4 wire procedure
   versus a GSPN based COT depending on the far end firmware version: If
   GSPN_Firmware_ID < R1.10 or 2.0 <= GSPN_Firmware_ID < 2.5 the proprietary so-called
   GSPN Enhanced 4 wire startup mode is selected, otherwise the standard protocol
   according to G.991.2. */
#define MW_VERSUS_GSPN_AUTO 0
/** Applicable for STU-R only.The PHY is configured that against GSPN based transceivers
   it executes the so-called GSPN Enhanced 4 wire startup protocol, which is GSPN
   proprietary and not standard conform. Versus other transceivers the standard conform
   protocol is used. */
#define MW_VERSUS_GSPN_PROP 1
/** For internal use only. */
#define MW_INTERNAL_ONLY 2
/** Applicable for STU-R only.The PHY is configured that it executes the 4 wire standard
   conform startup protocol also versus GSPN based transceivers. */
#define MW_ALWAYS_SHDSL_STD 3
/** PTM (64/65-octet-based) TC During G.hs only the ITU tree will be usedApplicable for
   STU-C and STU-R. */
#define PTM_6465o_TC_LAYER 0x21
/** EFM / PTM (64/65-octet-based) TC During G.hs the IEEE and ITU trees will be
   used.Applicable for STU-C and STU-R. */
#define EFM_6465o_TC_LAYER 0x61
/** Enable enhanced mode for setting and evaluating the TPS-TC parameters at STU-R and
   STU-C during handshake.For the ITU Annex A and B trees the corresponding bits for
   ATM, HDLC and 64/65-octed-based TC are set in the TPS-TC octets in packet mode. For
   pure TDM the corresponding TDM bits are selected.If
   GHS_DUAL_MODE_TPS_TC_PARAM_ENABLE is set the TPS-TC parameters are set to all 0. */
#define GHS_TPS_TC_PARAM_ENH_MODE 0x4
/** Enable sending and evaluating the dual mode TPS-TC parameters during
   handshake.Independent of GHS_TPS_TC_PARAM_ENH_MODE! */
#define GHS_DUAL_MODE_TPS_TC_PARAM_ENABLE 0x8
/** Used in ALM_PMD_TC_LayerMismatch to indicate that locally dual-mode is enabled but
   during handshake no dual-mode TPS-TC parameters were selected. */
#define NO_DUAL_MODE 0x80
/** Used in ALM_PMD_TC_LayerMismatch to indicate that no common TC layer was selected
   during handshake in the dual-mode TPS-TC parameters. I. e. the dual-mode TPS-TC
   parameter bits for type 2 TPS-TCb were all 0. */
#define NO_DUAL_MODE_TC_LAYER 0x88
/** Adapt the SDI line frequency in plesiochronous clock modes 1 and 2 (LOCAL_CLK and
   NETWORK_CLK).The adaptation will only be done in packet and MPair mode and the SDI
   frequency will be set dependent on the data rate.Applicable for STU-C and STU-R. */
#define SDI_FREQ_ADAPT_PLESIO_PACKET_MPAIR 0x10
/** IOP bit to enable the remote capability list evaluation in case of a
   NFC_CONNECT_CONDITION( GHS_NO_COMMON, ERR_NO_MODE ) for changing to an old style
   capability list. */
#define GHS_CAP_CHECK_NO_CO_MO 0x20
/** IOP bit for the STU-R to set the customer side SNR margin to 127 (not available) in
   EOC response with ID 139. */
#define SNR_MARGIN_CUST_SIDE_NOT_AVAIL 0x40


/**
   Defines used in the MDIO commands
*/
/** PMA/PMD device */
#define MMD_PMA_PMD 1
/** WIS device (not supported) */
#define MMD_WIS 2
/** PCS device */
#define MMD_PCS 3
/** PHY XS device (not supported) */
#define MMD_PHY_XS 4
/** DTE XS device (not supported) */
#define MMD_DTE_XS 5
/** TC device */
#define MMD_TC 6
/** Clause 22 extension */
#define MMD_CL22_EXT 29
/** Vendor specific 1 */
#define MMD_VS_1 30
/** Vendor specific 2 */
#define MMD_VS_2 31


/**
   Defines used in the HDLC commands
*/
/** Half duplex mode */
#define HALF_DUPLEX 0
/** Full duplex mode */
#define FULL_DUPLEX 1
/** Use internal generated sync signal */
#define NORMAL 0
/** Use external sync input */
#define CASCADING 1
/** MII uses COL to indicate collision */
#define COL_TYPE 0
/** MII uses TX_EN and CRS to infer a collision */
#define TX_EN_CRS_TYPE 0x1
/** Speed 10BT */
#define MII_10BT 0x0
/** Speed 100BT */
#define MII_100BT 0x1
/** Signal CRS_DV is low in di-bit position 1 */
#define DIBIT_POS_1 0x0
/** Signal CRS_DV is low in di-bit position 0 */
#define DIBIT_POS_0 0x1
/** Signal CRS_DV is low in di-bit postions 0 and 1 */
#define DIBIT_POS_0_1 0x2


/**
   Defines used in the HDLC commands
*/
/** Default interleaving mode */
#define IL_DEFAULT 0x00
/** Bit interleaving mode */
#define IL_CH_GR_BIT 0x80
/** Byte interleaving mode */
#define IL_CH_GR_BYTE 0x87
/** Payload interleaving mode */
#define IL_CH_GR_PAYLOAD 0x88
/** Fixed payload interleaving mode, all not used timeslots will carry idle data */
#define IL_CH_GR_FIX_PAYLOAD 0x8F
/** Trigger on falling edge for frame sync and multiframe sync pulse */
#define FALLING_EDGE_ 0x00
/** Trigger on rising edge for frame sync and multiframe sync pulse */
#define RISING_EDGE_ 0x01
/** Interface Mode: Bit serial */
#define BIT_SERIAL_ 0x00
/** Interface Mode: TDM with frame sync pulse */
#define TDM_SP_ 0x01
/** Interface Mode: TDM with Multiframe sync pulse */
#define TDM_MSP_ 0x02
/** Interface Mode: */
#define IOM2_ 0x03
/** Bit clock, SP and MSP derived from data stream */
#define DSL3_ 0x04
/** The system interface input clock is SDI_FREECLK */
#define FREE_RUNNING_ 0x05
/** Zbits octet aligned */
#define ZBIT_OCTET_ALIGN_ 0x00
/** Zbits non octet aligned */
#define ZBIT_NON_OCTET_ALIGN_ 0x01
/** Low polarity */
#define LOW_POL_ 0x00
/** High polarity */
#define HIGH_POL_ 0x01
/** Line interface Mode: TU-12 synchrone */
#define TU_12_A 0x00
/** Line interface Mode: TU-12 asynchrone */
#define TU_12_S 0x01
/** Line interface Mode: ISDN */
#define ISDN_ 0x02
/** Line interface Mode: TDM */
#define TDM_ 0x03
/** Line interface Mode: TDMSpecial setting for extended PAM mode.Precondition is that
   the host configures an identical line rate for all PAMDSLs. */
#define TDM_EXT_PAM_ 0x83
/** FSC Aligment Mode: No frame alignment */
#define NO_FRAME_ALIGNMENT_ 0x00
/** FSC Aligment Mode: Frame alignment */
#define FRAME_ALIGNMENT_ 0x01


/**
   Defines used in the HDLC commands
*/
/** SDI at system interface 2 side including xSlip buffer. */
#define SDI_SYSTEM 0
/** SDI at the line side */
#define SDI_LINE 1
/** The SDI is synchronized to the bit clock. SP and MSP are generated internally. */
#define SDI_TDMCLK_ 0x00
/** The SDI is synchronized to the bit clock and SP. MSP is generated internally. */
#define SDI_TDMCLK_TDMSP_ 0x01
/** The SDI is synchronized to the bit clock and MSP. SP is generated internally. */
#define SDI_TDMCLK_TDMMSP_ 0x02
/** The SDI is synchronized to the bit clock, SP and MSP. */
#define SDI_TDMCLK_TDMSP_TDMMSP_ 0x03
/** The bit clock, SP and MSP are derived from the data stream. */
#define SDI_DSL3_ 0x09
/** The SDI frame is generated without sync pulse. In the DSL3 frame, on the sync pulse
   position, an 11 sequence instead of the regular 01 sequence is generated. This
   option is needed if several channels are switched to a single SDI port, e.g. in a 4
   wire mode. In such a case, one of the participating SDIs is to be set to SDI_DSL3
   while the others are to be set to SDI_DSL3_NS. */
#define SDI_DSL3_NS_ 0x0D
/** The SDI is synchronized to the bit clock and SP. MSP is generated internally. The
   frame structure is IOM2 with 2 B-Channels and one D-Channel. The frequency should be
   at least twice the payload rate. */
#define SDI_IOM2_ 0x0E
/** The SDI is synchronized to the bit clock and MSP. SP is generated internally. The
   frame structure is equivalent to the SHDSL ISDN payload frame structure: D-Channel
   bits are summarized at the front of the frame and after this the B-Channels are
   transmitted. The payload rate should always be a multiple of 9. One additional bit
   to this payload is assumed as 'fast signaling channel' and directed to the HDLC
   (only in xSwitch mode!). */
#define SDI_ISDN_ 0x0F
/** The SDI is synchronized to the bit clock and MSP. SP is generated internally.
   Additional it is possible to serve the input MSP with a 2kHz signal instead of a
   166Hz signal. All time slots of a 36TS TU12 container are transferred. Additional
   bits to this payload are assumed as FW and forwarded to the HDLC (only in xSwitch
   mode!). */
#define SDI_TU12S_ 0x10
/** The SDI is synchronized to the bit clock and MSP. SP is generated internally.
   Additional it is possible to serve the input MSP with a 2kHz signal instead of a
   166Hz signal. The first and last 2 time slots of a 36TS TU12 container are dumped.
   The remaining 32TS of the container are transferred. Additional bits to this payload
   are assumed as FW and forwarded to the HDLC (only in xSwitch mode!). */
#define SDI_TU12A_ 0x11
/**  */
#define SDI_FREECLK_ 0x12
/**  */
#define SDI_FREECLK_TDMSP_ 0x13
/**  */
#define SDI_FREECLK_TDMMSP_ 0x14
/**  */
#define SDI_INCLK_TDMMSP_ 0x15
/** The SDI is synchronized to the bit clock of the input. SP and MSP are generated
   internally. */
#define SDI_INCLK_ 0x0A
/** The SDI is synchronized to the bit clock, SP and MSP of the input. */
#define SDI_INCLK_INSP_INMSP_ 0x04
/** The SDI is synchronized to the bit clock and SP of the input and to the MSP of the
   timing section. */
#define SDI_INCLK_INSP_TDMMSP_ 0x05
/** The SDI is synchronized to the bit clock of the input and to the SP and MSP of the
   timing section. */
#define SDI_INCLK_TDMSP_TDMMSP_ 0x06
/** The SDI is synchronized to the SP of the timing section. Bit clock and MSP are
   generated internally. */
#define SDI_TDMSP_ 0x07
/** The SDI is synchronized to the SP and MSP of the timing section. The bit clock is
   generated internally. */
#define SDI_TDMSP_TDMMSP_ 0x08
/** The whole SDIframe is set to 1. */
#define SDI_DO_NOTHING_ 0x0B
/** The whole SDI frame is set to high Z. */
#define SDI_HIGH_Z_ 0x0C
/** No SDI loop back is active */
#define SDI_NO_LOOP_ 0x00
/** The SDI remote loop back is active (output to input) for data. In STU_R mode clocks
   are also looped back. */
#define SDI_REMOTE_LOOP_ 0x01
/** The SDI remote loop back is active (output to input) for the clocks. No data loop
   back. */
#define SDI_REMOTE_CLK_ONLY_ 0x02
/** The SDI local loop back is active (input to output) for data and clocks. */
#define SDI_LOCAL_LOOP_ 0x03
/** The SDI combinational local loop back is active (input to output) for data and
   clocks. No storing elements like flip flops are between the input and output. */
#define SDI_COMB_LOOP_ 0x04
/** The SDI local loop back over the slip buffer is active (input to output) for data
   and clocks. */
#define SDI_LBUF_LOOP_ 0x05
/** The SDI remote loop back over the slip buffer is active (output to input) for data
   and clocks. Only in xSwitch environment used! */
#define SDI_RBUF_LOOP_ 0x06
/** No SDI-DPLL is active */
#define SDI_NODPLL_ 0x00
/** Input SDI-DPLL active */
#define SDI_DPLL4IN_ 0x01
/** Output SDI-DPLL active */
#define SDI_DPLL4OUT_ 0x02
/** Both Input and Output SDI-DPLL active */
#define SDI_DPLL4INOUT_ 0x03
/** Low active triggering */
#define SDI_LOW_ 0x00
/** High active triggering */
#define SDI_HIGH_ 0x01
/** Falling edge triggering */
#define SDI_FALLING_ 0x00
/** Rising edge triggering */
#define SDI_RISING_ 0x01
/** The latency of the transmit payload data is minimized. Thus, the data latency
   changes depending on the payload rate. Typically used in Socrates16 systems. */
#define SDI_NO_ 0x00
/** The transmit data latency is independent of the payload rate. Typically used in
   SDFE-4 standalone applications where the SDI is operated in TDM mode. */
#define SDI_YES_ 0x01
/** The SDI slip buffer is used as one buffer. Slip detection and resolution is
   deactivated. This mode is used for low latency and multi pair mode. */
#define SLIP_FAST_ 0x00
/** The SDI slip buffer is divided into 4 equal parts. Slip detection and resolution is
   activated. */
#define SLIP_NORMAL4_ 0x01
/** The SDI slip buffer is divided into 8 equal parts. Slip detection and resolution is
   activated. */
#define SLIP_NORMAL8_ 0x03
/** Standard Mode */
#define SDI_STD_MODE_ 0x00
/** Z bit aligned Mode */
#define SDI_ZB_ALIGN_ 0x01
/**  */
#define SDI_REF4SYM_ 0x02
/**  */
#define SDI_REF4SYM_YES_ 0x03


/**
   Defines used in the HDLC commands
*/
/** Byte stuffing */
#define BYTE_STUFFING 0
/** Bit stuffing */
#define BIT_STUFFING 1
/** Default interframe gap character */
#define HDLC_IF_CH_7EH 0x7E
/** Alternative interframe gap character */
#define HDLC_IF_CH_FFH 0xFF


/**
   Defines used in the ATM-TC configuration commands
*/
/** Cell Delineation Bit wise search mode */
#define CD_BIT_MODE 0
/** Cell Delineation Byte wise search mode */
#define CD_BYTE_MODE 1
/** The clock is generated internally */
#define NO_CLK 0
/** External bit clock */
#define EX_BIT_CLK 1
/** External 125us clock */
#define EX_125US_CLK 2
/** External 6ms clock */
#define EX_6MS_CLK 4
/** External 125us and bit clock */
#define EX_125US_BIT_CLK 3
/** External 6ms and bit clock */
#define EX_6MS_BIT_CLK 5


/**
   Defines for the SAR configuration
*/
/** LLC Encapsulation Bridged Protocol */
#define SAR_LLC_ENCAP_BP 3
/** VC Multiplexing Bridged Protocol */
#define SAR_VC_MUX_BP 1
/** Filter on Destination MAC address */
#define SAR_FILTER_MAC_ADDR 0
/** Filter on VLAN ID */
#define SAR_FILTER_VLAN_ID 1
/** Filter on VLAN Priority */
#define SAR_FILTER_VLAN_PRIO 2
/** Custom SAR filter */
#define SAR_FILTER_CUSTOM 3
/** Discard the packet on mismatch classification */
#define SAR_DISCARD_PACKET 0
/** Default VPI/VCI to be used for mismatch classifications */
#define SAR_DEF_VPI_VCI 1


/**
   Defines for the LCD and FSM
*/
/** Two wire mode */
#define TWO_WIRE 0
/** Four wire mode */
#define FOUR_WIRE 1
/** Symmetric transmission mode */
#define SYMETRIC 0
/** Asymmetric transmission mode */
#define ASYMETRIC 1
/** Regional annex A select */
#define ANNEX__A 0
/** Regional annex B select */
#define ANNEX__B 1
/** Remote (STU-R) EOC management enabled */
#define EOC_ENABLED 1
/** Remote (STU-R) EOC management disabled */
#define EOC_DISABLED 0
/** No power feeding */
#define NO_POWER 0
/** Power feeding */
#define POWER_FEED 1
/** Wetting current power feeding */
#define WETTING_CURRENT 2
/** Local clock - Mode-1 per G991.2 */
#define LOCAL_CLK 0x01
/** Network clock - Mode-2 per G991.2 */
#define NETWORK_CLK 0x02
/** Local clock - Mode-3a per G991.2 */
#define DATA_OR_NETWORK_CLK 0x04
/** Local clock - Mode-3a per G991.2, synchronized on CSP */
#define DATA_3A_CSP 0x14
/** Local clock - Mode-3a per G991.2, dummy CSP mode */
#define DATA_3A_CSP_GND 0x54
/** Local clock - Mode-3a per G991.2, synchronized on REFCLK */
#define DATA_3A_REFCLK 0x24
/** Local clock - Mode-3b per G991.2. This clock mode is not supported. */
#define DATA_CLK 8
/** Line probing disable */
#define LP_DISABLE 1
/** Line probing enable */
#define LP_ENABLE 2
/** The STU-R works as a standard conformed PMD link */
#define STANDARD_STU_R 0
/** The STU-R works as a none standard conformed PMD link (parameters ar writable) */
#define NON_STANDARD_STU_R 1
/** The support of complete caplist, code points for EFM and extended data rates will be
   exchanged */
#define NEW_STYLE_CAPLIST 0
/** The support of caplist according to G.shdsl (old SHDSL standard), codepoints up to
   2312 are only exchanged */
#define OLD_STYLE_CAPLIST 1
/** Automatic caplist detection */
#define AUTO_CAPLIST 2
/** Automatic TC detection, CPE only and the full capabilities will generated. */
#define AUTO_TC_DETECT 3
/** Full PAM selection and the appropriate will be handled automatically */
#define AUTO_PAM_SELECT 0
/** Only use 16 PAM constellation */
#define SELECT_16_PAM 1
/** Only use 32 PAM constellation */
#define SELECT_32_PAM 2
/** Regional annex A or F selected */
#define ANNEX__A_F 0
/** Regional annex B or G selected */
#define ANNEX__B_G 1
/** Power backoff normal mode */
#define PBO__NORMAL 0
/** Power backoff forced mode */
#define PBO__FORCED 4
/** Estimated power loss disabled */
#define EPL__DISABLED 0
/** Estimated power loss enabled */
#define EPL__ENABLED 8
/** 8kHz reference clock input */
#define REF_CLK_IN_8KHZ_ 0
/** 1536kHz reference clock input */
#define REF_CLK_IN_1536KHZ_ 1
/** 1544kHz reference clock input */
#define REF_CLK_IN_1544KHZ_ 2
/** 2048kHz reference clock input */
#define REF_CLK_IN_2048KHZ_ 3
/** 4096kHz reference clock input */
#define REF_CLK_IN_4096KHZ_ 4
/** 8192kHz reference clock input */
#define REF_CLK_IN_8192KHZ_ 5
/** 15360kHz reference clock input */
#define REF_CLK_IN_15360KHZ_ 6
/** 20480kHz reference clock input */
#define REF_CLK_IN_20480KHZ_ 7
/** 8kHz reference clock output derived from the received symbol clock */
#define REF_CLK_OUT_SYM_8KHZ_ 0
/** 8kHz reference clock output derived from the oscillator clock. */
#define REF_CLK_OUT_FREE_FSC_ 1
/** 8kHz reference clock output derived from the SDI symbol clock. */
#define REF_CLK_OUT_SYMBOL_REF_ 3
/** 8kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_8KHZ_ 0x10
/** 1536kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_1536KHZ_ 0x11
/** 1544kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_1544KHZ_ 0x12
/** 2048kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_2048KHZ_ 0x13
/** 4096kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_4096KHZ_ 0x14
/** 8192kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_8192KHZ_ 0x15
/** 15360kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_15360KHZ_ 0x16
/** 19440kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_19440KHZ_ 0x17
/** 20480kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_20480KHZ_ 0x18
/** 24576kHz reference clock output derived from the received SHDSL data stream. */
#define DATA_CLK_24576KHZ_ 0x19
/** Default clocking mode CO - Input, CPE - Output. */
#define DEFAULT_CLK_MODE 0x0
/** Input clocking mode for CO or CPE. */
#define INPUT_CLK_MODE 0x1
/** Output clocking mode CO or CPE. */
#define OUTPUT_CLK_MODE 0x2
/** Legacy and default mode for UAS counter update. The PAMDSL is updating the UAS
   counter only during data mode. */
#define UAS_COUNT_MODE_0 0x0
/** If enabled the UAS counter is updated when a link is down. Note that a delay line of
   10 seconds is maintained. The behaviour of the UAS counter in data mode is still
   according to standard. */
#define UAS_COUNT_MODE_1 0x1


/**
   Defines for the PAF configuration messages
*/
/** Do not change the setting (enable or disable).Appropriate for reading the current
   value. */
#define PAF_NO_CHANGE 0xFF
/** Enable a workaround. */
#define PAF_ENABLE 0x1
/** Disable a workaround. */
#define PAF_DISABLE 0x0
/** Use this value if expected sequence number threshold for the workaround shall not be
   changed. Appropriate for reading the current value. */
#define PAF_EXP_SEQ_NO_THRES_NO_CHANGE 0x4000
/** Use this value if the PAF link state guard time shall not be changed. Appropriate
   for reading the current value. */
#define PAF_GUARD_TIME_NO_CHANGE 0x80
/** Use this value if the PAF Q TX delay shall not be changed. Appropriate for reading
   the current value. */
#define PAF_Q_TX_DELAY_NO_CHANGE 0x1000


/**
   Defines used in the EFM-TC configuration commands.
*/
/** The EFM / 64/65-octed-based PTM TC uses a 32 bit CRC (default). */
#define EFM_6465o_TC_CRC_32 0x0
/** The EFM / 64/65-octed-based PTM TC uses a 16 bit CRC. */
#define EFM_6465o_TC_CRC_16 0x1


/**
   Defines used in the BACP configuration messages.
*/
/** BACP is disabled for the given link. */
#define BACP_DISABLE 0x0
/** The link is a BACP master, i. e. it can transfer data to the system interface and
   PMEs can be aggregated to it. */
#define BACP_MASTER 0x1
/** The link is a BACP slave, i. e. it either cannot transfer data to the system
   interface or there shall be no PMEs aggregated to it. */
#define BACP_SLAVE 0x2


/**
   Defines for the SAR configuration
*/
/** Disable Loop */
#define NO_LOOP 0
/** Ingress Loop Enable */
#define INGRESS_LOOP 1
/** Egress Loop Enable */
#define EGRESS_LOOP 2
/** Ingress Egress Loops Enable */
#define INGRESS_EGRESS_LOOP 3
/** Ingress Egress Loops Enable without SAR */
#define INGRESS_EGRESS_LOOP_WO_SAR 4


/**
   Defines for the chip level maintenance messages
*/
/** Hardware or Power-On reset */
#define HW_RESET 1
/** Watchdog reset */
#define WDT_RESET 2
/** Reset caused by setting MPI interface reset bit */
#define MPI_RESET 3
/** Reset caused by setting SCI interface reset bit */
#define SCI_RESET 4
/** Reset caused by setting MDIO interface reset bit */
#define MDIO_RESET 5
/** Unable to determine the last reset reason */
#define UNKNOWN_RESET 6
/** The IDC FW generated the reset due to buffer overflow */
#define IDC_RESET_1 16
/** Timeout period fro test FW has expired */
#define IDC_FW_TIMEOUT 255
/** Reset due to host command CMD_Reset */
#define HOST_CMD_RESET 0x8000
/** Write Access to the PMD AUX register failed */
#define PMD_AUX_ACCESS_ERROR 1
/** Write Access to the PMD Ram Shell register failed */
#define PMD_RS_ACCESS_ERROR 2
/** One or more of the PMD channels did not complete initialization */
#define PMD_INIT_INCOMPLETE 3
/** Host interface Intel demux */
#define HI_INTEL_DEMUX 0
/** Host interface motorola async */
#define HI_MOTOROLA_ASYNC 1
/** Host interface motorola sync */
#define HI_MOTOROLA_SYNC 2
/** Host interface RS232 (serial) */
#define HI_RS232 3
/** Host interface SCI */
#define HI_SCI 4
/** Host interface SCI */
#define HI_SCI_AXTALK 5
/** Host interface SCI */
#define HI_SCI_SDFE 7
/** System interface MII */
#define SI_MII 0
/** System interface RMII */
#define SI_RMII 1
/** System interface SMII typical */
#define SI_SMII_TYPICAL 2
/** System interface SMII synchronous */
#define SI_SMII_SYNC 3
/** System interface UTOPIA level 2 8bit */
#define SI_UTOPIA_L2_8BIT 4
/** System interface UTOPIA level 2 16bit */
#define SI_UTOPIA_L2_16BIT 5
/** System interface POS PHY Level 2 */
#define SI_POS_PHY_L2 6
/** System interface TDM */
#define SI_TDM 7
/** Boot from ROM mode */
#define ROM_BOOT 0
/** Boot from RAM mode */
#define RAM_BOOT 1
/** Device type PHY */
#define PHY_DEVICE 1
/** Device type MAC */
#define MAC_DEVICE 0
/** Power for the Link is DOWN */
#define POWER_DOWN 0
/** Power for the Link is UP */
#define POWER_UP 1
/** Configuration of SDFE device address failed */
#define SDFE_ADDRESS_ERROR 1
/** Configuration of UAUX I/F failed */
#define AUX_CONFIG_ERROR 2
/** Configuration of SCI I/F failed */
#define SCI_CONFIG_ERROR 3
/** Configuration of SDI register #0 failed */
#define SDI_ERROR_0 4
/** Configuration of SDI register #1 failed */
#define SDI_ERROR_1 5
/** Configuration of SDI register #2 failed */
#define SDI_ERROR_2 6
/** Configuration of SDI register #3 failed */
#define SDI_ERROR_3 7
/** Shutdown of SDFEÕs failed */
#define SDFE_STOP_ERROR 8
/** Switching access of SDFE RAM shell to SCI master failed */
#define SDFE_RS_GRANT_ACCESS_ERROR_0 9
/** Access of SDFE RAM shell failed */
#define SDFE_RS_ACCESS_ERROR 10
/** Switching access of SDFE RAM shell back to SDFE failed */
#define SDFE_RS_GRANT_ACCESS_ERROR_1 11
/** Startup of SDFEÕs failed */
#define SDFE_START_ERROR 13
/** Timeout while waiting for SDFE initialization */
#define SDFE_INIT_ERROR 14
/** The CSP is synchronized to an external signal */
#define LOCKED_TO_CSP_INPUT 1
/** No external signal or not synchrone */
#define FREE_RUNNING 0
/** No delay compensation */
#define NOT_ACTIVE_DC 0
/** RSFSC Align in progress */
#define RSFSC_ALIGN_DC 1
/** Reset the Delay */
#define RESET_DELAY_DC 2
/** Measure the delay */
#define MEASURE_DELAY_DC 3
/** Read the delay results */
#define READ_RESULT_DC 4
/** Reset TX framer after an error occured */
#define RESET_TX_FRAMER_DC 5
/** Reset RX framer */
#define RESET_RX_FRAMER_DC 6
/** Normalize the delay (last step of delay compensation) */
#define NORMALIZE_DC 7
/** Compensate a delay */
#define COMPENSATE_DC 8
/** Stop TX framer */
#define STOP_TX_FRAMER_DC 9
/** Delay compensation debug event. */
#define DC_DBG_DELAY_COMP 0
/** Miscellaneous event. */
#define DC_DBG_MISC 1
/** Write if_sel_x. */
#define DC_DBG_IF_SEL 2
/** Write mux4/if_sel_out. */
#define DC_DBG_MUX4_IF_SEL_OUT 3
/** Restart framer job. */
#define DC_DBG_FRAMER_RESTART 4
/** Notification timeout. */
#define DC_DBG_NFC_TIMEOUT 5
/** AUX/RS acknowledgment. */
#define DC_DBG_AUX_RS_ACK 6
/** Info at core activation state. */
#define DC_DBG_CORE_ACT 7
/** Info from DPLL sync / slip detected handler. */
#define DC_DBG_SYNC_SLIP 8
/** Delay measurement read result counter exceeded maximum. */
#define DC_DBG_DELAY_READ_RESULT_MAX 9
/** Delay compensation read error. */
#define DC_DBG_DC_ERROR_READ 10


/**
   Defines for the LCD and FSM
*/
/** HDLC link synchronous */
#define HDLC_SYNC 0
/** HDLC link asynchronous */
#define HDLC_ASYNC 1


/**
   Defines for the LCD and FSM
*/
/** Declared after ATM TC receive path enable. */
#define ATM_TC_STATE_NCD_ANOMALY 0
/** Declared */
#define ATM_TC_STATE_WORKING 1
/** Declared when state FSM_STATUS_HUNT is reached. */
#define ATM_TC_STATE_OCD_ANOMALY 2
/** Declared after 50 ms in state ATM_TC_STATE_OCD_ANOMALY. */
#define ATM_TC_STATE_LCD_DEFECT 3
/** Declared after 100 ms in state ATM_TC_STATE_NCD_ANOMALY. */
#define ATM_TC_STATE_NCD_FAILURE 4
/** Declared after 100 ms in state ATM_TC_STATE_LCD_DEFECT. */
#define ATM_TC_STATE_LCD_FAILURE 5
/** Combination of ATM_TC_STATE_NCD_FAILURE and ATM_TC_STATE_LCD_FAILURE. */
#define ATM_TC_STATE_NCD_LCD_FAILURE 6
/** No failure in ATM TC state machine. */
#define ATM_TC_STATE_NO_FAILURE 0
/** Declared when RX_Alpha consecutive incorrect HECs are found in the cell delineation
   process. */
#define FSM_STATUS_HUNT 0
/** Declared when one correct HEC is found in the cell delineation process. */
#define FSM_STATUS_PRESYNC 1
/** Declared when RX_Delta consecutive correct HECs are found in the cell delineation
   process. */
#define FSM_STATUS_SYNC 2
/** Enable alarm message EVT_ATM_TC_LinkNcdLcdFailure for NCD failures. */
#define ENABLE_NCD_FAILURE 1
/** Enable alarm message EVT_ATM_TC_LinkNcdLcdFailure for LCD failures. */
#define ENABLE_LCD_FAILURE 2
/** Enable alarm message EVT_ATM_TC_LinkNcdLcdFailure for NCD and LCD failures. */
#define ENABLE_NCD_LCD_FAILURE 3


/**
   Defines for the LCD and FSM
*/
/** 16 PAM levels */
#define PMD_16_TCPAM 2
/** 32 PAM levels */
#define PMD_32_TCPAM 1
/** Link is down (not ready) */
#define DOWN_NOT_READY 0
/** Link is down (ready) */
#define DOWN_READY 4
/** Link is down (ready) */
#define STOP_DOWN_READY 0x14
/** Link is initializing */
#define INITIALIZING 1
/** Link is up, 2BASE-TL (data mode) */
#define UP_DATA_MODE 3
/** Noise environment - current condition */
#define CURRENT_CONDITION 1
/** Noise environment - worst case */
#define WORST_CASE 0
/** STU-C unit (central office) */
#define STU_C_UNIT 1
/** STU-R unit (remote terminal) */
#define STU_R_UNIT 2
/** SRU-1 unit (repeater #1) */
#define SRU_1_UNIT 3
/** SRU-2 unit (repeater #2) */
#define SRU_2_UNIT 4
/** SRU-3 unit (repeater #3) */
#define SRU_3_UNIT 5
/** SRU-4 unit (repeater #4) */
#define SRU_4_UNIT 6
/** SRU-5 unit (repeater #5) */
#define SRU_5_UNIT 7
/** SRU-6 unit (repeater #6) */
#define SRU_6_UNIT 8
/** SRU-7 unit (repeater #7) */
#define SRU_7_UNIT 9
/** SRU-8 unit (repeater #8) */
#define SRU_8_UNIT 10
/** Indicates that parameter ÕConditionÕ is not used. */
#define NO_COND_ 0
/** Indication that the GHS_STARTUP procedure was successful and that G.994.1 messages
   are received and transmitted. Parameter 'Reason' is don't care. */
#define GHS_TRANSFER_ 1
/** Indication that line probing (PMMS) is started. Parameter 'Reason' is don't care. */
#define LP_START_ 2
/** Indication that the current G.994.1 session is finished but no common mode is
   possible. Check parameter 'Reason' for more details. */
#define GHS_NO_COMMON_ 3
/** Indication that an exception has occurred. Check parameter 'Reason' for more
   details. */
#define EXCEPTION_ 4
/** Indication that a 4-wire mode will be performed but the counter part supports only
   single pair mode. Parameter 'Reason' is don't care. */
#define SINGLE_PAIR_DET_ 5
/** Indication that the G.994.1 startup procedure is performed and that tones of the
   counter part are successfully detected. Parameter 'Reason' is don't care. */
#define GHS_STARTUP_ 6
/** Indication that the STU is sent into SILENCE. This happens if the STU is connected
   versus a SRU and receives a MS with the RSP-bit set. Parameter 'Reason' is don't
   care. */
#define GHS_SILENCE_ 7
/** Indication that the STU is sent into SILENCE for 5 consecutive times. Parameter
   'Reason' is don't care. */
#define GHS_RSP_FAILURE_ 8
/** Indication that the SRU-R/C is in IDLE state and that the SRU is waiting for a
   g.994.1 startup request. Parameter 'Reason' is don't care. */
#define GHS_IDLE_ 9
/** Indication that a link initiation propagates from STU-C towards direction STU-R. The
   SRU-R/C is in state GHS_WAIT_STU_R. This means that the SRU is waiting that the
   capabilities propagates from STU-R towards direction STU-C. Parameter 'Reason' is
   don't care. */
#define GHS_WAIT_STU_R_ 10
/** Indication that the capabilities propagates from STU-R towards direction STU-C. The
   SRU-R/C is in state GHS_WAIT_STU_C. This means that the SRU is waiting that the
   SHDSL activation propagates from STU-C towards direction STU-R. Parameter 'Reason'
   is don't care. */
#define GHS_WAIT_STU_C_ 11
/** Indication that a link initiation request is detected at the SRU-C. Parameter
   'Reason' is don't care. */
#define GHS_LINK_INITIATION_ 12
/** Indication that the capabilities of the segments in direction STU-R are available at
   the SRU-R. Parameter 'Reason' is don't care. */
#define GHS_CAP_AVAILABLE_ 13
/** Indication that the G.994.1 startup procedure at a SRU-C is not finished during 30s.
   Thus the link initiation request cannot propagate towards direction STU-R. Parameter
   'Reason' is don't care. */
#define GHS_30SEC_TIMEOUT_ 14
/** Indication that a 2wire mode will be performed but the counter part tries four wire
   mode. Parameter 'Reason' gives the M-pair count of the farend transceiver. */
#define FOUR_WIRE_DET_ 15
/** Indication that an exception is occurred during line probing (PMMS). Parameter
   'Reason' describes this condition more detailed. */
#define LP_EXCEPTION_ 16
/** Indication that the counter part performs a M-pair mode and the mismatch could not
   be resolved before g.hs has finished. A mode mismatch is autonomously resolved if
   the number of used wire pairs is the same. Parameter 'Reason' is don't care. */
#define M_PAIR_DET_ 17
/** Indication that both sides perform M-pair mode but there is a mismatch in pair
   count. Parameter 'Reason' gives the M-pair count of the farend transceiver. */
#define M_PAIR_COUNT_MIS_ 18
/** Relevant for SRU only. Indication that the host has uploaded the mode select or the
   merged capability list to the SRU using CMD_CFG_CAPLIST in a state where the SRU
   cannot handle the message correctly. The content is ignored. The CMD_CFG_CAPLIST is
   handled correctly if the SRU has left a critical internal state (e.g. handshake
   message exchange). */
#define SRU_CFG_CL_REJ_ 19
/** Relevant for SRU only. Indication that the host has uploaded the mode select or the
   merged capability list to the SRU using CMD_CFG_CAPLIST in a state where the SRU
   handles the message correctly. The content is stored. */
#define SRU_CFG_CL_DONE_ 20
/** Indicates that parameter ÕReasonÕ is don't care. */
#define ERR_UNUSED_ 0x0
/** The devices cannot find a common mode of operation because both devices are not
   capable to support the same annex. */
#define ERR_ANNEX_MIS_ 0x1
/** The devices cannot find a common mode of operation because at least one device has
   more than one mode selected (TRAINING, PMMS, RSP). */
#define ERR_MODE_MIS_ 0x2
/** The devices cannot find a common mode of operation because there is a lack of SPar2
   information to select a common mode. */
#define ERR_SPAR2_MIS_ 0x3
/** The devices cannot find a common mode of operation because both devices are not
   capable to support the same clock mode (clock mode 1, 2, 3a). */
#define ERR_TPS_TC_CLOCK_MIS_ 0x4
/** Not used anymore due to compatibility with other vendors. */
#define ERR_TPS_TC_CHANNEL_MIS_ 0x5
/** The devices cannot find a common mode of operation because both devices are not
   capable to support the same base rate. */
#define ERR_DATA_RATES_MIS_ 0x6
/** The devices cannot find a common mode of operation because both devices are not
   capable to support the same sub rate. */
#define ERR_SUB_RATES_MIS_ 0x7
/** The devices cannot find a common mode of operation because both devices are not
   capable to support the same DUAL TPS-TC. */
#define ERR_DUAL_TPSTC_MIS_ 0x8
/** Rate or sub rate of the dual mode TPS-TC parameters for bearer 'a' do not match. */
#define ERR_DUAL_RATE_MIS_ 0x9
/** The devices cannot find a common mode of operation because the received MS of the
   STU-R does not contain the PMMS downstream parameter originally requested by the
   STU-R or the STU-C is not capable to send the requested probes as requested by the
   STU-R. */
#define ERR_LP_PARA_DN_MIS_ 0x10
/** The devices cannot find a common mode of operation because the received MS of the
   STU-C does not contain the PMMS downstream parameter originally requested by the
   STU-C or the STU-R is not capable to send the requested probes as requested by the
   STU-C. */
#define ERR_LP_PARA_UP_MIS_ 0x20
/** Not used anymore. */
#define ERR_LP_TIME_MIS_ 0x30
/** The number of PMMS probes that are locally requested to be received is too high. The
   number of PMMS probes that can be received/requested is currently restricted to 10
   probes. */
#define LP_PRB_NUM_RX_NS_ 31
/** The number of PMMS probes that are requested by the remote terminal to be sent by
   the local terminal is too high. The number of PMMS probes that can be transmitted is
   currently restricted to 20 probes. */
#define LP_PRB_NUM_TX_NS_ 0x32
/** The devices cannot find a common mode of operation because the received MS of the
   STU-R does not contain the same PMMS parameter as requested in the MP message
   formerly sent by the STU-R. */
#define ERR_LP_ECHO_DN_MIS_ 0x40
/** The devices cannot find a common mode of operation because the MP/MS received by the
   STU does not contain valid PMMS DN parameter. */
#define ERR_LP_PARA_DN_LACK_ 0x50
/** The devices cannot find a common mode of operation because the MP/MS received by the
   STU does not contain valid PMMS UP parameter. */
#define ERR_LP_PARA_UP_LACK_ 0x60
/** The devices cannot find a common mode of operation because the received MS of the
   STU-R does not contain neither PMMS DN nor PMMS UP parameter in case of selected
   mode PMMS. */
#define ERR_LP_PARA_DNUP_LACK_ 0x70
/** The device has received a no common mode message. */
#define ERR_MS_NO_MODE_ 0xFF
/** A probe was not detected. */
#define PROBE_NOT_DETECTED_ 0x90
/** The end of a probe was not detected. */
#define PROBE_END_NOT_DETECTED_ 0x91
/** This reason is sent by the COT exclusively. Indicates that the SHDSL core activation
   sequence has timed out and the detection of the Cr signal at the beginning of the
   SHDSL core activation failed. */
#define CR_NOT_DETECTED_ 0xA3
/** This reason is sent by the COT exclusively. Indicates that the SHDSL core activation
   sequence has timed out and the COT receiver failed to train on the Sr signal sent by
   the RT. */
#define NOT_CONVERGED_ON_SR_ 0xA6
/** This reason is sent by the COT exclusively. Indicates that the SHDSL core activation
   sequence has timed out, the COT transceiver successfully trained on the Sr signal,
   is already sending the Tc signal but failed to detect the Tr signal. */
#define TR_NOT_DETECTED_ 0xA9
/** This reason is sent by both RT and COT. Indicates that the local receiver has
   successfully completed the SHDSL core activation sequence but failed to detect the
   SHDSL data mode frame. */
#define DSL_FRAMING_NOT_SYNCHRONIZED_ 0xAC
/** This reason is sent by the RT exclusively. Indicates that the SHDSL core activation
   sequence has timed out and the RT receiver failed to train on the Sc signal. */
#define NOT_CONVERGED_ON_SC_ 0xB3
/** This reason is sent by the RT exclusively. Indicates that the SHDSL core activation
   sequence has timed out, the RT receiver successfully trained on the Sc signal but
   failed to detect the Tc signal. */
#define TC_NOT_DETECTED_ 0xB6
/** This reason is sent by the RT exclusively. Indicates that the SHDSL Core Activation
   sequence has timed out, the RT transceiver successfully trained on the Sc signal, is
   already sending the Tr signal but failed to detect the Fc signal. */
#define FC_NOT_DETECTED_ 0xB9
/** This reason is sent by both COT and RT. Indicates that the SHDSL transceiver has
   changed from state DATA_MODE to state EXCEPTION. The condition for leaving data mode
   is not defined by the SHDSL standard. Please refer to the Programmer's reference for
   description of the implemented exception condition. */
#define DATA_EXCEPTION_ 0xC0
/** This reason is sent by both COT and RT. Indicates that the SHDSL transceiver has
   changed from state DATA_MODE to state EXCEPTION because for some reason there are no
   tx 6ms interrupts raised anymore. */
#define NO_TX_NFRAM_INTERRUPTS_ 0xC1
/** Customer side */
#define CUSTOMER 0
/** Network side */
#define NETWORK 1
/** Force the link down */
#define FORCE_LINK_DOWN 0
/** Enable the link */
#define ENABLE_LINK 1
/** Stop the link after initialization */
#define STOP_AFTER_INIT 2
/** Start the link after initialization */
#define START_AFTER_INIT 3
/** Start the link training */
#define START_TRAINING 4
/** M-pair link down */
#define MPAIR_DOWN 0
/** M-pair link up */
#define MPAIR_UP 1
/** Start a delay compensation for the given LinkMask and the master LinkNo. When
   finished perform delay measurements at regular intervals and if there is a delay
   start a compensation. */
#define DC_START 1


/**
   Defines for the ethernet OAM messages
*/
/** Information OAMPDU code */
#define INFORMATION 0x0
/** Event notification OAMPDU code */
#define EVENT_NOTIFICATION 0x1
/** Variable request OAMPDU code */
#define VARIABLE_REQUEST 0x2
/** Variable response OAMPDU code */
#define VARIABLE_RESPONSE 0x3
/** Loopback control OAMPDU code */
#define LOOPBACK_CONTROL 0x4
/** Organization specific OAMPDU code */
#define ORGANIZATION_SPECIFIC 0xFE
/** Only information OAMPDUs with the link fault critical link event set and without
   information TLVs are allowed to be transmitted; Only information OAMPDUs are allowed
   to be received */
#define LF_INFO 0x0
/** No OAMPDUs are allowed to be transmitted; only information OAMPDUs are allowed to be
   received */
#define RX_INFO 0x1
/** Only information OAMPDUs are allowed to be transmitted and received */
#define INFO 0x2
/** Any permissible OAMPDU is allowed to be transmitted and received */
#define ANY 0x3
/** Discovery State FAULT */
#define DIS_FAULT 0x0
/** Discovery State ACTIVE SEND LOCAL */
#define DIS_ACTIVE_SEND_LOCAL 0x1
/** Discovery State PASSIVE WAIT */
#define DIS_PASSIVE_WAIT 0x2
/** Discovery State SEND LOCAL REMOTE */
#define DIS_SEND_LOCAL_REMOTE 0x3
/** Discovery State SEND LOCAL REMOTE OK */
#define DIS_SEND_LOCAL_REMOTE_OK 0x4
/** Discovery State SEND ANY */
#define DIS_SEND_ANY 0x5
/** Transmit State RESET */
#define TRS_RESET 0x0
/** Transmit State WAIT FOR TX */
#define TRS_WAIT_FOR_TX 0x1
/** Transmit State DEC PDU CNT */
#define TRS_DEC_PDU_CNT 0x2
/** Transmit State TX OAMPDU */
#define TRS_TX_OAMPDU 0x3
/** Multiplexer State WAIT FOR TX */
#define MLX_WAIT_FOR_TX 0x0
/** Multiplexer State CHECK PHY + LINK */
#define MLX_CHECK_PHY_LINK 0x1
/** Multiplexer State TX FRAME */
#define MLX_TX_FRAME 0x2
/** No link fault condition */
#define LINK_OK 0x0
/** Link fault condition exists */
#define LINK_FAIL 0x1
/** Forward frames to sublayer */
#define FWD 0x0
/** Loopback frames */
#define LB 0x1
/** Discard frames */
#define DISCARD 0x2


/**
   Defines for the Ethernet Insert/Extract Messages
*/
/** Insert/Extract to from LIne side */
#define LINE_SIDE 1
/** Insert/Extract to from System side */
#define SYSTEM_SIDE 0
/** Insert/Extract to from both System and Line side */
#define LINE_SYSTEM_SIDE 2
/** Filter not enabled */
#define NO_FILTER 0
/** Filter on Destination MAC address */
#define FILTER_MAC_DST_ADDR 1
/** Filter on Source MAC address */
#define FILTER_MAC_SRC_ADDR 2
/** Filter on VLAN ID */
#define FILTER_VLAN_ID 3
/** Filter on VLAN Priority */
#define FILTER_VLAN_PRIO 4
/** Next fragment (112 octets) of an ethernet frame */
#define NEXT_FRAGMENT 0
/** Start fragment (112 octets) of an ethernet frame */
#define START_OF_FRAME 1
/** End fragment (<= 112 octets) of an ethernet frame */
#define END_OF_FRAME 2
/** Full Ethernet frame (60 - 112 octets) */
#define FULL_FRAME 3
/** Filter 1 (line/system) caused the extraction */
#define FILTER_1 0
/** Filter 2(line/system) caused the extraction */
#define FILTER_2 1


/**
   Defines for the EOC maintenance
*/
/** EOC performance status mode auto. */
#define EOC_PERF_STATUS_MODE_AUTO 0
/** EOC performance status mode 1. */
#define EOC_PERF_STATUS_MODE_1 1
/** EOC performance status mode 2. */
#define EOC_PERF_STATUS_MODE_2 2


/**
   Defines for the debug register access
*/
/** RS and AUX register read access */
#define READ_AC 0
/** RS and AUX register write access */
#define WRITE_AC 1
/** Delay configuration register */
#define DLY_CFG_AUX 1
/** Delay order register */
#define DLY_ORDER_AUX 3
/** Delay result 1 register */
#define DLY_RESULT1_AUX 5
/** Delay result 2 register */
#define DLY_RESULT2_AUX 7
/** Delay result 3 register */
#define DLY_RESULT3_AUX 9
/** Delay report register */
#define DLY_REPORT 0x0B
/** Mux 10 low selector */
#define MUX10_LOW_SEL 0x18
/** Mux 10 high selector */
#define MUX10_HIGH_SEL 0x1A
/** Mux 4 low selector */
#define MUX4_LOW_SEL 0x1C
/** Mux 4 high selector */
#define MUX4_HIGH_SEL 0x1E
/** AUX Interface mode register */
#define AUX_IF_MODE 0x20
/** SCI Interface select 0 register */
#define IF_SEL_0_SCI 0x22
/** SCI Interface select 1 register */
#define IF_SEL_1_SCI 0x24
/** SCI Interface select 2register */
#define IF_SEL_2_SCI 0x26
/** SCI Interface select 3register */
#define IF_SEL_3_SCI 0x28
/** SCI Interface mode register */
#define SCI_IF_MODE 0x2A
/** Device Address register */
#define DEV_ADDR 0x2E
/** FW Control RS register */
#define FWCTRL_RS 0x0
/** FW CRC RS register */
#define FWCRC_RS 0x1
/** FW Control RS register */
#define FWDTPNT_RS 0x2
/** FW Start RS register */
#define FWSTART_RS 0x3


/**
   Defines for the counter memory access
*/
/** MAC RX TX line side counters */
#define MAC_LINE_CNTS 0
/** MAC RX TX system side counters */
#define MAC_SYSTEM_CNTS 1
/** xMII counters */
#define XMII_COUNTERS 2
/** SAR segmentation counters */
#define SAR_SEG_CNTS 3
/** SAR reassembly counters block 1 */
#define SAR_REA1_CNTS 4
/** SAR reassembly counters block 2 */
#define SAR_REA2_CNTS 5
/** ATM_OAM counters */
#define ATM_OAM_CNTS 6
/** HDLC-TC counters */
#define HDLC_TC_COUNTERS 7
/** PAF Queue counters */
#define PAF_Q_COUNTERS 8
/** PAF counters */
#define PAF_COUNTERS 9
/** EFM-TC counters */
#define EFM_TC_COUNTERS 10


/**
   Defines for the PAF maintenance messages
*/
/** Read the interrupt service routine counters for the PAF module from the PAF master
   link. */
#define PAF_ISR_CNT 0x0
/** Read PAF receive state machine trace information from the PAF master link. */
#define PAF_RX_SM_TRACE 0x1
/** Read PAF transmit state machine trace information from the PAF master link. */
#define PAF_TX_SM_TRACE 0x2
/** Read the interrupt service routine counters for the PAF Q module. These counters can
   be read for all links in the PAF group. */
#define PAF_Q_ISR_CNT 0x3


/**
   Defines used in the BACP maintenance messages.
*/
/** BACP state. */
#define BACP_Undef 0x0
/** BACP state. */
#define BACP_Reset 0x1
/** BACP state. */
#define BACP_InitChangePme_2 0x2
/** BACP state. */
#define BACP_InitChangePme_1 0x3
/** BACP state. PME is waiting to be initialized.On COs the PME is switched when the
   current initialization is finished. Note that the master single PME PAF is
   initialized first.On RTs the PME to be initialized (BACP_Initialize state) is
   switched in a round robin way after a timeout (2.5 s). */
#define BACP_PmeWaitForInitialization 0x4
/** BACP state. PME is currently initializing.On COs the PME sends BACPDUs containing an
   assignment TLV with an interval of 1s and is waiting for a reply. When the current
   protocol initialization is finished the next single PME PAF waiting to be
   initialized is selected.RT single PME PAFs are waiting for the reception of valid
   BACPDUs. Only one link at a time is in BACP_Initialize state, but the link will be
   switched in a round robin way afer a timeout (2.5 s) if it did not change its
   state. */
#define BACP_Initialize 0x5
/** BACP state. */
#define BACP_WaitForInitConfirmation 0x6
/** BACP state. Final state of BACP initialization.BACP protocol is initialized for the
   single PME PAF and the PME can be transferred to another PAF within the bonding
   group. */
#define BACP_EligibleForAggregation 0x7
/** BACP state. */
#define BACP_PmeAssign 0x10
/** BACP state. */
#define BACP_EligibleToTransfer 0x11
/** BACP state. */
#define BACP_WaitForPmeDisconnectSingle 0x12
/** BACP state. */
#define BACP_PmeDisconnectSingle 0x13
/** BACP state. */
#define BACP_PmeDisconnectedSingle 0x14
/** BACP state. */
#define BACP_PmeRxConnect 0x15
/** BACP state. */
#define BACP_PmeRxConnected 0x16
/** BACP state. */
#define BACP_PmeTxConnect 0x17
/** BACP state. Final state of a PME transfer.The PME is connected to a multiple PME PAF
   and data can be transferred in TX and RX direction. */
#define BACP_PmeConnected 0x18
/** BACP state. */
#define BACP_PmeTxConnectError 0x19
/** BACP state. */
#define BACP_PmeConnectedError 0x1A
/** BACP state. */
#define BACP_WaitForPmeTxDisconnect 0x20
/** BACP state. */
#define BACP_PmeTxDisconnect 0x21
/** BACP state. */
#define BACP_PmeTxDisconnected 0x22
/** BACP state. */
#define BACP_PmeRxDisconnect 0x23
/** BACP state. Final state of a PME removal.Subsequently the PME will be connected to
   an empty PAF and will be reinitialized. */
#define BACP_PmeDisconnected 0x24
/** BACP PME status. */
#define BACP_Unknown 0x0
/** BACP PME status. */
#define BACP_Unassigned 0x1
/** BACP PME status. */
#define BACP_Assigned 0x2
/** BACP PME status. */
#define BACP_Moving 0x3
/** BACP PME status. */
#define BACP_RxOnly 0x4
/** BACP PME status. */
#define BACP_TxRx 0x5
/** Used together with BACP events (BACP_Evt_xxx) to indicate a successful action. */
#define BACP_Ok 0x0
/** Used together with BACP events (BACP_Evt_xxx) to indicate an erroneous action. */
#define BACP_Error 0x1
/** BACP enabled in mode select capability list of G.hs. */
#define BACP_Evt_EnableGhs 0x1
/** A PME was associated with an empty PAF. */
#define BACP_Evt_PmePafConnect 0x2
/** A PME exchange to establish a master to master PAF connection before BACP
   initialization is finished. */
#define BACP_Evt_PmeExchange 0x3
/** BACP initialization for the given single PME PAF is finished. */
#define BACP_Evt_Initialize 0x4
/** BACP PME transfer to the given PAF is finished. */
#define BACP_Evt_PmeTransfer 0x5
/** BACP PME removal from the given PAF is finished. */
#define BACP_Evt_PmeRemove 0x6
/** Overflow of internal BACP transmit queue occurred.This shall not happen and
   indicates an internal error. */
#define BACP_Evt_TxQueueOverflow 0x20
/** Maximum number (10) of BACPDUs per second is exceeded. During state machine
   transitions the retry mechanism should recover this issue. */
#define BACP_Evt_MaxPduPerSec 0x21
/** BACP debug event contains PME state machine information. */
#define BACP_DbgEvt_PmeStateMachine 0x1
/** BACP debug event to indicate a received BACPDU. */
#define BACP_DbgEvt_PduRx 0x2
/** BACP debug event to indicate a transmitted BACPDU. */
#define BACP_DbgEvt_PduTx 0x3
/** BACP debug event to indicate that initialization is started. */
#define BACP_DbgEvt_Init 0x4
/** BACP debug event to indicate that the requested BACPDU was sent. */
#define BACP_DbgEvt_PduSent 0x5
/** Internally generated BACPDU containing header and InfoTLVs which reflect the current
   status. */
#define BACP_DbgPdu_InfoTlv 0x0
/** Provided BACPDU payload automatically extended by the BACP header. */
#define BACP_DbgPdu_Custom 0x1


/**
   
*/
typedef struct IDC_MessageHeader IDC_MessageHeader_t;

/** Message ID for CMD_TC_FlowModify */
#define CMD_TC_FLOWMODIFY 0x8

/**
   
*/
typedef struct CMD_TC_FlowModify CMD_TC_FlowModify_t;

/** Message ID for ACK_TC_FlowModify */
#define ACK_TC_FLOWMODIFY 0x208

/**
   
*/
typedef struct ACK_TC_FlowModify ACK_TC_FlowModify_t;

/** Message ID for CMD_StatusPinsConfig */
#define CMD_STATUSPINSCONFIG 0x9

/**
   This command enables/disables the usage of the status group pins STA_3..0 and
   PS_3..0.
*/
typedef struct CMD_StatusPinsConfig CMD_StatusPinsConfig_t;

/** Message ID for ACK_StatusPinsConfig */
#define ACK_STATUSPINSCONFIG 0x209

/** Message ID for CMD_VendorInformationConfig */
#define CMD_VENDORINFORMATIONCONFIG 0xB

/**
   This command configures the vendor information for the device.
*/
typedef struct CMD_VendorInformationConfig CMD_VendorInformationConfig_t;

/** Message ID for ACK_VendorInformationConfig */
#define ACK_VENDORINFORMATIONCONFIG 0x20B

/**
   This data structure defines the vendor specific octets for G.Hs. This is needed for
   interoperability against specific non-Infineon implementations which reject data
   mode in case of  values 00 00, that the Socrates-4e sends by default.
*/
typedef struct VendorSpecOctets VendorSpecOctets_t;

/** Message ID for CMD_IOP_Mode */
#define CMD_IOP_MODE 0xC

/**
   This command configures the vendor information for the device and allows interop
   modes to be selected.
*/
typedef struct CMD_IOP_Mode CMD_IOP_Mode_t;

/** Message ID for ACK_IOP_Mode */
#define ACK_IOP_MODE 0x20C

/** Message ID for CMD_ResourceLevelConfig */
#define CMD_RESOURCELEVELCONFIG 0xE

/**
   This command configures the IDC resource level indications.
*/
typedef struct CMD_ResourceLevelConfig CMD_ResourceLevelConfig_t;

/** Message ID for ACK_ResourceLevelConfig */
#define ACK_RESOURCELEVELCONFIG 0x20E

/** Message ID for ALM_ResorceLevelCritical */
#define ALM_RESORCELEVELCRITICAL 0x605

/** Message ID for ALM_ResorceLevelNormal */
#define ALM_RESORCELEVELNORMAL 0x606

/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_Mdio_EfmPhy and ACK_Mdio_EfmPhy.
*/
typedef struct MdioFrame45 MdioFrame45_t;

/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_Mdio_ExtPhy and ACK_Mdio_ExtPhy.
*/
typedef struct MdioFrame22 MdioFrame22_t;

/** Message ID for CMD_Mdio_EfmPhy */
#define CMD_MDIO_EFMPHY 0x1

/**
   This message is used to send a batch of up to 31 MDIO register accesses, see Clause
   45 MDIO Register Access for MDIO register access.
*/
typedef struct CMD_Mdio_EfmPhy CMD_Mdio_EfmPhy_t;

/** Message ID for ACK_Mdio_EfmPhy */
#define ACK_MDIO_EFMPHY 0x201

/**
   
*/
typedef struct ACK_Mdio_EfmPhy ACK_Mdio_EfmPhy_t;

/** Message ID for CMD_Mdio_RegisterRead */
#define CMD_MDIO_REGISTERREAD 0x2

/**
   This command performs 2 MDIO operations, 1st an ADDRESS operation is performed by
   setting the specified MMD ADDRESS, and 2nd the register contents is read from the
   set ADDRESS, if the register address is invalid then 0 will be returned.
*/
typedef struct CMD_Mdio_RegisterRead CMD_Mdio_RegisterRead_t;

/** Message ID for ACK_Mdio_RegisterRead */
#define ACK_MDIO_REGISTERREAD 0x202

/**
   
*/
typedef struct ACK_Mdio_RegisterRead ACK_Mdio_RegisterRead_t;

/** Message ID for CMD_Mdio_RegisterWrite */
#define CMD_MDIO_REGISTERWRITE 0x3

/**
   This command performs 2 MDIO operations, 1st an ADDRESS operation is performed by
   setting the specified MMD ADDRESS, and 2nd the register contents is overwritten at
   the set ADDRESS, if the register address is invalid or the register is read only
   then no action will be performed.
*/
typedef struct CMD_Mdio_RegisterWrite CMD_Mdio_RegisterWrite_t;

/** Message ID for ACK_Mdio_RegisterWrite */
#define ACK_MDIO_REGISTERWRITE 0x203

/** Message ID for CMD_Mdio_RegisterMultipleRead */
#define CMD_MDIO_REGISTERMULTIPLEREAD 0x4

/**
   This command performs several MDIO operations, 1st an ADDRESS operation is performed
   by setting the specified MMD ADDRESS, and 2nd the register contents is read from the
   set ADDRESS and the ADDRESS is incremented (Post Read Increment Operation), the read
   operation will be performed for the requested number of reads, if the register
   address is invalid then 0 will be returned.
*/
typedef struct CMD_Mdio_RegisterMultipleRead CMD_Mdio_RegisterMultipleRead_t;

/** Message ID for ACK_Mdio_RegisterMultipleRead */
#define ACK_MDIO_REGISTERMULTIPLEREAD 0x204

/**
   
*/
typedef struct ACK_Mdio_RegisterMultipleRead ACK_Mdio_RegisterMultipleRead_t;

/** Message ID for CMD_Mdio_ExtPhy */
#define CMD_MDIO_EXTPHY 0x5

/**
   
*/
typedef struct CMD_Mdio_ExtPhy CMD_Mdio_ExtPhy_t;

/** Message ID for ACK_Mdio_ExtPhy */
#define ACK_MDIO_EXTPHY 0x205

/**
   
*/
typedef struct ACK_Mdio_ExtPhy ACK_Mdio_ExtPhy_t;

/** Message ID for CMD_UTOPIA_L2_Modify */
#define CMD_UTOPIA_L2_MODIFY 0x10

/**
   This command is used to modify the default settings of the UTOPIA interface.
*/
typedef struct CMD_UTOPIA_L2_Modify CMD_UTOPIA_L2_Modify_t;

/** Message ID for ACK_UTOPIA_L2_Modify */
#define ACK_UTOPIA_L2_MODIFY 0x210

/** Message ID for CMD_POSPHY_L2_Modify */
#define CMD_POSPHY_L2_MODIFY 0x18

/**
   This command is used to modify the default settings of the POS-PHY interface.
*/
typedef struct CMD_POSPHY_L2_Modify CMD_POSPHY_L2_Modify_t;

/** Message ID for ACK_POSPHY_L2_Modify */
#define ACK_POSPHY_L2_MODIFY 0x218

/** Message ID for CMD_xMII_Modify */
#define CMD_XMII_MODIFY 0x1A

/**
   This command is used to modify the default settings of the xMII interface per link.
*/
typedef struct CMD_xMII_Modify CMD_xMII_Modify_t;

/** Message ID for ACK_xMII_Modify */
#define ACK_XMII_MODIFY 0x21A

/** Message ID for CMD_MAC_Config */
#define CMD_MAC_CONFIG 0xA

/**
   This command configures the MAC address for the device and the maximum supported
   Ethernet frame size and support of external Ethernet OAM for the links.
*/
typedef struct CMD_MAC_Config CMD_MAC_Config_t;

/** Message ID for ACK_MAC_Config */
#define ACK_MAC_CONFIG 0x20A

/** Message ID for CMD_MAC_LinkConfig */
#define CMD_MAC_LINKCONFIG 0xD

/**
   This command configures the MAC functionality for a link.
*/
typedef struct CMD_MAC_LinkConfig CMD_MAC_LinkConfig_t;

/** Message ID for ACK_MAC_LinkConfig */
#define ACK_MAC_LINKCONFIG 0x20D

/** Message ID for CMD_TDM_SystemInterfaceConfig */
#define CMD_TDM_SYSTEMINTERFACECONFIG 0x70

/**
   
*/
typedef struct CMD_TDM_SystemInterfaceConfig CMD_TDM_SystemInterfaceConfig_t;

/** Message ID for ACK_TDM_SystemInterfaceConfig */
#define ACK_TDM_SYSTEMINTERFACECONFIG 0x270

/** Message ID for CMD_TDM_VirtualPortConfig */
#define CMD_TDM_VIRTUALPORTCONFIG 0x72

/**
   This command is used to configure virtual TDM ports at the line interface when
   configuring TDM applications
*/
typedef struct CMD_TDM_VirtualPortConfig CMD_TDM_VirtualPortConfig_t;

/** Message ID for ACK_TDM_VirtualPortConfig */
#define ACK_TDM_VIRTUALPORTCONFIG 0x272

/** Message ID for CMD_Dbg_SDI_Settings */
#define CMD_DBG_SDI_SETTINGS 0x75

/**
   
*/
typedef struct CMD_Dbg_SDI_Settings CMD_Dbg_SDI_Settings_t;

/** Message ID for ACK_Dbg_SDI_Settings */
#define ACK_DBG_SDI_SETTINGS 0x275

/** Message ID for CMD_Dbg_SDI_Tx */
#define CMD_DBG_SDI_TX 0x76

/**
   
*/
typedef struct CMD_Dbg_SDI_Tx CMD_Dbg_SDI_Tx_t;

/** Message ID for ACK_Dbg_SDI_Tx */
#define ACK_DBG_SDI_TX 0x276

/** Message ID for CMD_Dbg_SDI_Rx */
#define CMD_DBG_SDI_RX 0x77

/**
   
*/
typedef struct CMD_Dbg_SDI_Rx CMD_Dbg_SDI_Rx_t;

/** Message ID for ACK_Dbg_SDI_Rx */
#define ACK_DBG_SDI_RX 0x277

/** Message ID for CMD_Dbg_SDI_Dly */
#define CMD_DBG_SDI_DLY 0x78

/**
   
*/
typedef struct CMD_Dbg_SDI_Dly CMD_Dbg_SDI_Dly_t;

/** Message ID for ACK_Dbg_SDI_Dly */
#define ACK_DBG_SDI_DLY 0x278

/** Message ID for CMD_Dbg_SDI_IlChannelsTx */
#define CMD_DBG_SDI_ILCHANNELSTX 0x79

/**
   
*/
typedef struct CMD_Dbg_SDI_IlChannelsTx CMD_Dbg_SDI_IlChannelsTx_t;

/** Message ID for ACK_Dbg_SDI_IlChannelsTx */
#define ACK_DBG_SDI_ILCHANNELSTX 0x279

/** Message ID for CMD_Dbg_SDI_IlChannelsRx */
#define CMD_DBG_SDI_ILCHANNELSRX 0x7A

/**
   
*/
typedef struct CMD_Dbg_SDI_IlChannelsRx CMD_Dbg_SDI_IlChannelsRx_t;

/** Message ID for ACK_Dbg_SDI_IlChannelsRx */
#define ACK_DBG_SDI_ILCHANNELSRX 0x27A

/** Message ID for CMD_Dbg_SDI_FramerTx */
#define CMD_DBG_SDI_FRAMERTX 0x7B

/**
   
*/
typedef struct CMD_Dbg_SDI_FramerTx CMD_Dbg_SDI_FramerTx_t;

/** Message ID for ACK_Dbg_SDI_FramerTx */
#define ACK_DBG_SDI_FRAMERTX 0x27B

/** Message ID for CMD_Dbg_SDI_FramerRx */
#define CMD_DBG_SDI_FRAMERRX 0x7C

/**
   
*/
typedef struct CMD_Dbg_SDI_FramerRx CMD_Dbg_SDI_FramerRx_t;

/** Message ID for ACK_Dbg_SDI_FramerRx */
#define ACK_DBG_SDI_FRAMERRX 0x27C

/** Message ID for CMD_Dbg_MWM_ConfigGet */
#define CMD_DBG_MWM_CONFIGGET 0x7D

/** Message ID for ACK_Dbg_MWM_ConfigGet */
#define ACK_DBG_MWM_CONFIGGET 0x27D

/**
   
*/
typedef struct ACK_Dbg_MWM_ConfigGet ACK_Dbg_MWM_ConfigGet_t;

/** Message ID for CMD_Dbg_SDI_Loop */
#define CMD_DBG_SDI_LOOP 0x7E

/**
   
*/
typedef struct CMD_Dbg_SDI_Loop CMD_Dbg_SDI_Loop_t;

/** Message ID for ACK_Dbg_SDI_Loop */
#define ACK_DBG_SDI_LOOP 0x27E

/** Message ID for CMD_HDLC_TC_LinkModify */
#define CMD_HDLC_TC_LINKMODIFY 0x20

/**
   This command is used to modify an HDLC TC flow.
*/
typedef struct CMD_HDLC_TC_LinkModify CMD_HDLC_TC_LinkModify_t;

/** Message ID for ACK_HDLC_TC_LinkModify */
#define ACK_HDLC_TC_LINKMODIFY 0x220

/** Message ID for CMD_ATM_TC_LinkModify */
#define CMD_ATM_TC_LINKMODIFY 0x30

/**
   This command is used to modify an ATM-TC flow in the receive and transmit
   directions, the flow can be a single 1:1 flow or an M pair 1:N flow.
*/
typedef struct CMD_ATM_TC_LinkModify CMD_ATM_TC_LinkModify_t;

/** Message ID for ACK_ATM_TC_LinkModify */
#define ACK_ATM_TC_LINKMODIFY 0x230

/** Message ID for CMD_SegmentationReassemblyConfig */
#define CMD_SEGMENTATIONREASSEMBLYCONFIG 0x40

/**
   This command is used to configure the general settings for the SAR process.
*/
typedef struct CMD_SegmentationReassemblyConfig CMD_SegmentationReassemblyConfig_t;

/** Message ID for ACK_SegmentationReassemblyConfig */
#define ACK_SEGMENTATIONREASSEMBLYCONFIG 0x240

/** Message ID for CMD_Segmentation_VCC_Config */
#define CMD_SEGMENTATION_VCC_CONFIG 0x41

/**
   This command adds an entry into the ethernet forwarding table, up to 8 entries can
   be defined.
*/
typedef struct CMD_Segmentation_VCC_Config CMD_Segmentation_VCC_Config_t;

/** Message ID for ACK_Segmentation_VCC_Config */
#define ACK_SEGMENTATION_VCC_CONFIG 0x241

/** Message ID for CMD_SegmentationClassFilterConfig */
#define CMD_SEGMENTATIONCLASSFILTERCONFIG 0x42

/**
   This command adds a classification filter to the segmentation classification filter
   table, up to 16 entries can be defined.
*/
typedef struct CMD_SegmentationClassFilterConfig CMD_SegmentationClassFilterConfig_t;

/** Message ID for ACK_SegmentationClassFilterConfig */
#define ACK_SEGMENTATIONCLASSFILTERCONFIG 0x242

/** Message ID for CMD_ReassemblyClassFilterConfig */
#define CMD_REASSEMBLYCLASSFILTERCONFIG 0x43

/**
   This command adds a classification filter to the reassembly classification filter
   table, up to 8 entries can be defined.
*/
typedef struct CMD_ReassemblyClassFilterConfig CMD_ReassemblyClassFilterConfig_t;

/** Message ID for ACK_ReassemblyClassFilterConfig */
#define ACK_REASSEMBLYCLASSFILTERCONFIG 0x243

/** Message ID for CMD_Segmentation_VCC_Delete */
#define CMD_SEGMENTATION_VCC_DELETE 0x44

/**
   This command deletes an entry from the ethernet forwarding table that was previously
   configured.
*/
typedef struct CMD_Segmentation_VCC_Delete CMD_Segmentation_VCC_Delete_t;

/** Message ID for ACK_Segmentation_VCC_Delete */
#define ACK_SEGMENTATION_VCC_DELETE 0x244

/** Message ID for CMD_ReassemblyClassFilterDelete */
#define CMD_REASSEMBLYCLASSFILTERDELETE 0x45

/**
   This command deletes a classification filter in the reassembly classification filter
   table.
*/
typedef struct CMD_ReassemblyClassFilterDelete CMD_ReassemblyClassFilterDelete_t;

/** Message ID for ACK_ReassemblyClassFilterDelete */
#define ACK_REASSEMBLYCLASSFILTERDELETE 0x245

/** Message ID for CMD_Ethernet_OAM_Config */
#define CMD_ETHERNET_OAM_CONFIG 0x48

/**
   This command configures a link for Ethernet OAM functionality, the device must be in
   MAC mode and the TC layer must be EFM.
*/
typedef struct CMD_Ethernet_OAM_Config CMD_Ethernet_OAM_Config_t;

/** Message ID for ACK_Ethernet_OAM_Config */
#define ACK_ETHERNET_OAM_CONFIG 0x248

/** Message ID for CMD_EthernetExtractConfig */
#define CMD_ETHERNETEXTRACTCONFIG 0x4A

/**
   This command is used to setup the extract filters for both system side and line side
   extraction.
*/
typedef struct CMD_EthernetExtractConfig CMD_EthernetExtractConfig_t;

/** Message ID for ACK_EthernetExtractConfig */
#define ACK_ETHERNETEXTRACTCONFIG 0x24A

/** Message ID for CMD_PMD_CO_PortSubTypeSelect */
#define CMD_PMD_CO_PORTSUBTYPESELECT 0x60

/**
   This command changes the port sub-type from a -R subtype (default mode) to a -O
   subtype.
*/
typedef struct CMD_PMD_CO_PortSubTypeSelect CMD_PMD_CO_PortSubTypeSelect_t;

/** Message ID for ACK_PMD_CO_PortSubTypeSelect */
#define ACK_PMD_CO_PORTSUBTYPESELECT 0x260

/** Message ID for CMD_PMD_PortSubTypeSelect */
#define CMD_PMD_PORTSUBTYPESELECT 0x61

/**
   This command changes the port subtype.
*/
typedef struct CMD_PMD_PortSubTypeSelect CMD_PMD_PortSubTypeSelect_t;

/** Message ID for ACK_PMD_PortSubTypeSelect */
#define ACK_PMD_PORTSUBTYPESELECT 0x261

/** Message ID for CMD_PMD_EndpointAlarmConfig */
#define CMD_PMD_ENDPOINTALARMCONFIG 0x63

/**
   This command sets the line quality thresholds for the local PMD STU-C and the link
   partner PMD STU-R.
*/
typedef struct CMD_PMD_EndpointAlarmConfig CMD_PMD_EndpointAlarmConfig_t;

/** Message ID for ACK_PMD_EndpointAlarmConfig */
#define ACK_PMD_ENDPOINTALARMCONFIG 0x263

/** Message ID for CMD_PMD_SpanProfileGroupConfig */
#define CMD_PMD_SPANPROFILEGROUPCONFIG 0x64

/**
   This command configures SHDSL parameters for a span which are used to fill in the
   capability list for the handshake.
*/
typedef struct CMD_PMD_SpanProfileGroupConfig CMD_PMD_SpanProfileGroupConfig_t;

/** Message ID for ACK_PMD_SpanProfileGroupConfig */
#define ACK_PMD_SPANPROFILEGROUPCONFIG 0x264

/** Message ID for CMD_PMD_ExtendedRatesConfig */
#define CMD_PMD_EXTENDEDRATESCONFIG 0x65

/**
   This command is used to enable a proprietary G.hs mode, which allows to negotiate
   rates higher than the rates specified in the SHDSL.bis standard, as well as PAM
   constellations for 4, 8, 64, and 128 PAM.
*/
typedef struct CMD_PMD_ExtendedRatesConfig CMD_PMD_ExtendedRatesConfig_t;

/** Message ID for ACK_PMD_ExtendedRatesConfig */
#define ACK_PMD_EXTENDEDRATESCONFIG 0x265

/** Message ID for CMD_PMD_ReferenceClockConfig */
#define CMD_PMD_REFERENCECLOCKCONFIG 0x66

/**
   This command is used to reference clock frequency in the PMD, by default the input
   is set to REF_CLK_IN_8KHZ and the output is REF_CLK_OUT_SYM_8KHZ, the direction of
   the clock by default is dependent on the port sub-type, if CPE the output clock and
   CO input clock.
*/
typedef struct CMD_PMD_ReferenceClockConfig CMD_PMD_ReferenceClockConfig_t;

/** Message ID for ACK_PMD_ReferenceClockConfig */
#define ACK_PMD_REFERENCECLOCKCONFIG 0x266

/** Message ID for CMD_PMD_PerfCountConfig */
#define CMD_PMD_PERFCOUNTCONFIG 0x67

/**
   This command is used to select the mode for collecting the performance parameters
   which are provided locally and via EOC.
*/
typedef struct CMD_PMD_PerfCountConfig CMD_PMD_PerfCountConfig_t;

/** Message ID for ACK_PMD_PerfCountConfig */
#define ACK_PMD_PERFCOUNTCONFIG 0x267

/** Message ID for CMD_PMD_GhsConfig */
#define CMD_PMD_GHSCONFIG 0x68

/**
   This command is used to configure the G.hs operation of the PMD.
*/
typedef struct CMD_PMD_GhsConfig CMD_PMD_GhsConfig_t;

/** Message ID for ACK_PMD_GhsConfig */
#define ACK_PMD_GHSCONFIG 0x268

/** Message ID for CMD_PAF_SeqNoConfig */
#define CMD_PAF_SEQNOCONFIG 0x24

/**
   This command is used to configure the PAF expected sequence number adaptation and
   the discard loop reset.
*/
typedef struct CMD_PAF_SeqNoConfig CMD_PAF_SeqNoConfig_t;

/** Message ID for ACK_PAF_SeqNoConfig */
#define ACK_PAF_SEQNOCONFIG 0x224

/**
   
*/
typedef struct ACK_PAF_SeqNoConfig ACK_PAF_SeqNoConfig_t;

/** Message ID for CMD_PAF_SeqNoEvtConfig */
#define CMD_PAF_SEQNOEVTCONFIG 0x25

/**
   This command is used to configure the events for a manual adaptation of the PAF
   expected sequence number.
*/
typedef struct CMD_PAF_SeqNoEvtConfig CMD_PAF_SeqNoEvtConfig_t;

/** Message ID for ACK_PAF_SeqNoEvtConfig */
#define ACK_PAF_SEQNOEVTCONFIG 0x225

/**
   
*/
typedef struct ACK_PAF_SeqNoEvtConfig ACK_PAF_SeqNoEvtConfig_t;

/** Message ID for EVT_PAF_SeqNo */
#define EVT_PAF_SEQNO 0x69C

/**
   Indication that the PAF link state or the bad fragment counter has changed within
   the last guard time interval.
*/
typedef struct EVT_PAF_SeqNo EVT_PAF_SeqNo_t;

/** Message ID for CMD_PAF_Q_Config */
#define CMD_PAF_Q_CONFIG 0x26

/**
   This command is used to configure the PAF queue settings.
*/
typedef struct CMD_PAF_Q_Config CMD_PAF_Q_Config_t;

/** Message ID for ACK_PAF_Q_Config */
#define ACK_PAF_Q_CONFIG 0x226

/**
   
*/
typedef struct ACK_PAF_Q_Config ACK_PAF_Q_Config_t;

/** Message ID for CMD_EFM_6465o_TC_Modify */
#define CMD_EFM_6465O_TC_MODIFY 0x28

/**
   This command is used to modify EFM / PTM 64/65-octed-based TC settings.
*/
typedef struct CMD_EFM_6465o_TC_Modify CMD_EFM_6465o_TC_Modify_t;

/** Message ID for ACK_EFM_6465o_TC_Modify */
#define ACK_EFM_6465O_TC_MODIFY 0x228

/** Message ID for CMD_BACP_LinkConfig */
#define CMD_BACP_LINKCONFIG 0x38

/**
   This command is used to configure the Bonding Aggregation Control Protocol (BACP).
*/
typedef struct CMD_BACP_LinkConfig CMD_BACP_LinkConfig_t;

/** Message ID for ACK_BACP_LinkConfig */
#define ACK_BACP_LINKCONFIG 0x238

/** Message ID for CMD_LinkControl */
#define CMD_LINKCONTROL 0x80

/**
   This command is used to enable/disable the transmit and receive flow at the system
   interface.
*/
typedef struct CMD_LinkControl CMD_LinkControl_t;

/** Message ID for ACK_LinkControl */
#define ACK_LINKCONTROL 0x280

/** Message ID for CMD_SystemInterfaceLoopControl */
#define CMD_SYSTEMINTERFACELOOPCONTROL 0x90

/**
   This message is used to enable / disable the system interface loop depending on the
   flow type.
*/
typedef struct CMD_SystemInterfaceLoopControl CMD_SystemInterfaceLoopControl_t;

/** Message ID for ACK_SystemInterfaceLoopControl */
#define ACK_SYSTEMINTERFACELOOPCONTROL 0x290

/** Message ID for CMD_TC_LayerLoopControl */
#define CMD_TC_LAYERLOOPCONTROL 0x91

/**
   This message is used to enable / disable the TC Layer loop.
*/
typedef struct CMD_TC_LayerLoopControl CMD_TC_LayerLoopControl_t;

/** Message ID for ACK_TC_LayerLoopControl */
#define ACK_TC_LAYERLOOPCONTROL 0x291

/** Message ID for EVT_InitializationComplete */
#define EVT_INITIALIZATIONCOMPLETE 0x680

/**
   
*/
typedef struct EVT_InitializationComplete EVT_InitializationComplete_t;

/** Message ID for ALM_InitializationAborted */
#define ALM_INITIALIZATIONABORTED 0x600

/**
   This alarm is an indication that the initialization of the of the chip has failed.
*/
typedef struct ALM_InitializationAborted ALM_InitializationAborted_t;

/** Message ID for EVT_PMD_Channel_0_Down */
#define EVT_PMD_CHANNEL_0_DOWN 0x6C0

/**
   This event indicates that a PMD channel has gone down.
*/
typedef struct EVT_PMD_Channel_0_Down EVT_PMD_Channel_0_Down_t;

/** Message ID for EVT_PMD_Channel_1_Down */
#define EVT_PMD_CHANNEL_1_DOWN 0x6C1

/**
   This event indicates that a PMD channel has gone down.
*/
typedef struct EVT_PMD_Channel_1_Down EVT_PMD_Channel_1_Down_t;

/** Message ID for EVT_PMD_Channel_2_Down */
#define EVT_PMD_CHANNEL_2_DOWN 0x6C2

/**
   This event indicates that a PMD channel has gone down.
*/
typedef struct EVT_PMD_Channel_2_Down EVT_PMD_Channel_2_Down_t;

/** Message ID for EVT_PMD_Channel_3_Down */
#define EVT_PMD_CHANNEL_3_DOWN 0x6C3

/**
   This event indicates that a PMD channel has gone down.
*/
typedef struct EVT_PMD_Channel_3_Down EVT_PMD_Channel_3_Down_t;

/** Message ID for ALM_ProtocolViolation */
#define ALM_PROTOCOLVIOLATION 0x601

/** Message ID for ALM_InvalidMessageHeader */
#define ALM_INVALIDMESSAGEHEADER 0x602

/** Message ID for CMD_InventoryRequest */
#define CMD_INVENTORYREQUEST 0x110

/** Message ID for ACK_InventoryRequest */
#define ACK_INVENTORYREQUEST 0x310

/**
   
*/
typedef struct ACK_InventoryRequest ACK_InventoryRequest_t;

/** Message ID for CMD_TC_LayerReset */
#define CMD_TC_LAYERRESET 0x10F

/** Message ID for ACK_TC_LayerReset */
#define ACK_TC_LAYERRESET 0x30F

/** Message ID for CMD_Reset */
#define CMD_RESET 0x111

/**
   Reset of the IDC and PAMDSL firmware.
*/
typedef struct CMD_Reset CMD_Reset_t;

/** Message ID for CMD_LocalPowerStatus */
#define CMD_LOCALPOWERSTATUS 0x128

/**
   This command is used send the power status of all STU-R links when the power status
   is not controlled internally in the device, the command should only be sent when the
   power status changes.
*/
typedef struct CMD_LocalPowerStatus CMD_LocalPowerStatus_t;

/** Message ID for ACK_LocalPowerStatus */
#define ACK_LOCALPOWERSTATUS 0x328

/** Message ID for CMD_TXSYMBOL_ReferenceStatus */
#define CMD_TXSYMBOL_REFERENCESTATUS 0x11E

/** Message ID for ACK_TXSYMBOL_ReferenceStatus */
#define ACK_TXSYMBOL_REFERENCESTATUS 0x31E

/**
   
*/
typedef struct ACK_TXSYMBOL_ReferenceStatus ACK_TXSYMBOL_ReferenceStatus_t;

/** Message ID for CMD_MAC_ConfigGet */
#define CMD_MAC_CONFIGGET 0x118

/**
   This command gets the configured state of the MAC for a link.
*/
typedef struct CMD_MAC_ConfigGet CMD_MAC_ConfigGet_t;

/** Message ID for ACK_MAC_ConfigGet */
#define ACK_MAC_CONFIGGET 0x318

/**
   This command configures the MAC functionality for a link.
*/
typedef struct ACK_MAC_ConfigGet ACK_MAC_ConfigGet_t;

/** Message ID for ALM_EventsLost */
#define ALM_EVENTSLOST 0x608

/** Message ID for ALM_EmptyEgressQueue */
#define ALM_EMPTYEGRESSQUEUE 0x609

/** Message ID for CMD_GeneralPurpose */
#define CMD_GENERALPURPOSE 0x10B

/**
   This command is only for IDC internal usage and not for standard chip programming.
*/
typedef struct CMD_GeneralPurpose CMD_GeneralPurpose_t;

/** Message ID for ACK_GeneralPurpose */
#define ACK_GENERALPURPOSE 0x30B

/**
   
*/
typedef struct ACK_GeneralPurpose ACK_GeneralPurpose_t;

/** Message ID for EVT_SomethingHappened */
#define EVT_SOMETHINGHAPPENED 0x6FF

/**
   This event is only for IDC internal usage and indicates that something has
   happened.
*/
typedef struct EVT_SomethingHappened EVT_SomethingHappened_t;

/** Message ID for EVT_DC_StateChange */
#define EVT_DC_STATECHANGE 0x6F0

/**
   This event is only for IDC internal usage and indicates that the delay compensation
   state has changed.
*/
typedef struct EVT_DC_StateChange EVT_DC_StateChange_t;

/** Message ID for ALM_DelayMeasurementAborted */
#define ALM_DELAYMEASUREMENTABORTED 0x60A

/**
   This alarm is an indication that a delay measurement for a MPair bundle has failed.
*/
typedef struct ALM_DelayMeasurementAborted ALM_DelayMeasurementAborted_t;

/** Message ID for EVT_SCI_MissingTransportLayerAck */
#define EVT_SCI_MISSINGTRANSPORTLAYERACK 0x6C4

/**
   This event indicates that the IDC at the SCI interface has not received a transport
   layer ack for a transmitted message after 3 retries.
*/
typedef struct EVT_SCI_MissingTransportLayerAck EVT_SCI_MissingTransportLayerAck_t;

/** Message ID for EVT_SCI_MissingMessageLayerAck */
#define EVT_SCI_MISSINGMESSAGELAYERACK 0x6C5

/**
   This event indicates that the IDC at the SCI interface has not received a message
   layer ack for a transmitted command, the command was acknowledged with a transport
   layer ack but no message layer ack was received within 2 seconds.
*/
typedef struct EVT_SCI_MissingMessageLayerAck EVT_SCI_MissingMessageLayerAck_t;

/** Message ID for EVT_xSwitch_SlipDetected */
#define EVT_XSWITCH_SLIPDETECTED 0x68F

/**
   
*/
typedef struct EVT_xSwitch_SlipDetected EVT_xSwitch_SlipDetected_t;

/** Message ID for ALM_FW_TestVersionTimeout */
#define ALM_FW_TESTVERSIONTIMEOUT 0x67F

/**
   This alarm is an indication that the Firmware is a test version and the time of 1
   hour in data mode has expired.
*/
typedef struct ALM_FW_TestVersionTimeout ALM_FW_TestVersionTimeout_t;

/** Message ID for CMD_IDC_FeatureStrGet */
#define CMD_IDC_FEATURESTRGET 0x11F

/** Message ID for ACK_IDC_FeatureStrGet */
#define ACK_IDC_FEATURESTRGET 0x31F

/**
   
*/
typedef struct ACK_IDC_FeatureStrGet ACK_IDC_FeatureStrGet_t;

/** Message ID for EVT_DC_Debug */
#define EVT_DC_DEBUG 0x6F1

/**
   This event is only for IDC internal usage and indicates various debug events for a
   delay compensation, restart SDI framer jobs and AUX configuration. A special
   firmware is needed for the events to be generated.
*/
typedef struct EVT_DC_Debug EVT_DC_Debug_t;

/** Message ID for CMD_HDLC_TC_LinkCorruptPacketControl */
#define CMD_HDLC_TC_LINKCORRUPTPACKETCONTROL 0x140

/**
   This test feature when enabled forces sending of corrupt packets in the transmitter
   direction.
*/
typedef struct CMD_HDLC_TC_LinkCorruptPacketControl CMD_HDLC_TC_LinkCorruptPacketControl_t;

/** Message ID for ACK_HDLC_TC_LinkCorruptPacketControl */
#define ACK_HDLC_TC_LINKCORRUPTPACKETCONTROL 0x340

/** Message ID for CMD_HDLC_TC_LinkSyncEventsControl */
#define CMD_HDLC_TC_LINKSYNCEVENTSCONTROL 0x141

/**
   This command enables/disables the generation of HDLC-TC Sync events when the sync
   state changes.
*/
typedef struct CMD_HDLC_TC_LinkSyncEventsControl CMD_HDLC_TC_LinkSyncEventsControl_t;

/** Message ID for ACK_HDLC_TC_LinkSyncEventsControl */
#define ACK_HDLC_TC_LINKSYNCEVENTSCONTROL 0x341

/** Message ID for EVT_HDLC_TC_LinkSyncStateChange */
#define EVT_HDLC_TC_LINKSYNCSTATECHANGE 0x682

/**
   This command enables/disables the generation of HDLC-TC Sync events when the sync
   state changes.
*/
typedef struct EVT_HDLC_TC_LinkSyncStateChange EVT_HDLC_TC_LinkSyncStateChange_t;

/** Message ID for CMD_HDLC_TC_LinkACF_EventsControl */
#define CMD_HDLC_TC_LINKACF_EVENTSCONTROL 0x142

/**
   This command enables/disables the generation of HDLC-TC ACF changed events.
*/
typedef struct CMD_HDLC_TC_LinkACF_EventsControl CMD_HDLC_TC_LinkACF_EventsControl_t;

/** Message ID for ACK_HDLC_TC_LinkACF_EventsControl */
#define ACK_HDLC_TC_LINKACF_EVENTSCONTROL 0x342

/** Message ID for EVT_HDLC_TC_LinkACF_Changed */
#define EVT_HDLC_TC_LINKACF_CHANGED 0x683

/**
   This event is generated each time the address and control field change.
*/
typedef struct EVT_HDLC_TC_LinkACF_Changed EVT_HDLC_TC_LinkACF_Changed_t;

/** Message ID for CMD_HDLC_TC_LinkPmParamGet */
#define CMD_HDLC_TC_LINKPMPARAMGET 0x143

/**
   This command is used to request the performance monitoring parameters for an HDLC-TC
   link.
*/
typedef struct CMD_HDLC_TC_LinkPmParamGet CMD_HDLC_TC_LinkPmParamGet_t;

/** Message ID for ACK_HDLC_TC_LinkPmParamGet */
#define ACK_HDLC_TC_LINKPMPARAMGET 0x343

/**
   This acknowledgement contains the HDLC-TC performance monitoring counters requested
   by the command CMD_HDLC_TC_LinkPmParamGet.
*/
typedef struct ACK_HDLC_TC_LinkPmParamGet ACK_HDLC_TC_LinkPmParamGet_t;

/** Message ID for CMD_ATM_TC_LinkHecInvert */
#define CMD_ATM_TC_LINKHECINVERT 0x148

/**
   This test feature when enabled forces HEC errors at the receiver side of the
   connection, all cells will have the bits in the HEC byte inverted.
*/
typedef struct CMD_ATM_TC_LinkHecInvert CMD_ATM_TC_LinkHecInvert_t;

/** Message ID for ACK_ATM_TC_LinkHecInvert */
#define ACK_ATM_TC_LINKHECINVERT 0x348

/** Message ID for CMD_ATM_TC_LinkHecErrorInsert */
#define CMD_ATM_TC_LINKHECERRORINSERT 0x149

/**
   This is a test feature a single cell with HEC error will be transmitted to the
   receiver side of the connection, bit 7 of the HEC byte will be inverted.
*/
typedef struct CMD_ATM_TC_LinkHecErrorInsert CMD_ATM_TC_LinkHecErrorInsert_t;

/** Message ID for ACK_ATM_TC_LinkHecErrorInsert */
#define ACK_ATM_TC_LINKHECERRORINSERT 0x349

/** Message ID for CMD_ATM_TC_LinkPmParamGet */
#define CMD_ATM_TC_LINKPMPARAMGET 0x14A

/**
   This command is used to request the performance monitoring parameters for an ATM-TC
   link.
*/
typedef struct CMD_ATM_TC_LinkPmParamGet CMD_ATM_TC_LinkPmParamGet_t;

/** Message ID for ACK_ATM_TC_LinkPmParamGet */
#define ACK_ATM_TC_LINKPMPARAMGET 0x34A

/**
   This acknowledgement contains the ATM-TC performance monitoring counters requested
   by the command CMD_ATM_TC_LinkPmParamGet.
*/
typedef struct ACK_ATM_TC_LinkPmParamGet ACK_ATM_TC_LinkPmParamGet_t;

/** Message ID for CMD_ATM_TC_LinkFsmLcdStateGet */
#define CMD_ATM_TC_LINKFSMLCDSTATEGET 0x14B

/**
   This command is used to request the status of the cell delineation finite state
   machine and the maintenance state machine for an ATM-TC link in receive direction.
*/
typedef struct CMD_ATM_TC_LinkFsmLcdStateGet CMD_ATM_TC_LinkFsmLcdStateGet_t;

/** Message ID for ACK_ATM_TC_LinkFsmLcdStateGet */
#define ACK_ATM_TC_LINKFSMLCDSTATEGET 0x34B

/**
   This acknowledgement contains the current states of ATM-TC LCD and FSM.
*/
typedef struct ACK_ATM_TC_LinkFsmLcdStateGet ACK_ATM_TC_LinkFsmLcdStateGet_t;

/** Message ID for CMD_ATM_TC_LinkLcdStateEventControl */
#define CMD_ATM_TC_LINKLCDSTATEEVENTCONTROL 0x14C

/**
   This commands enables the generation of event messages when the LCD state changes
   for a given ATM-TC link.
*/
typedef struct CMD_ATM_TC_LinkLcdStateEventControl CMD_ATM_TC_LinkLcdStateEventControl_t;

/** Message ID for ACK_ATM_TC_LinkLcdStateEventControl */
#define ACK_ATM_TC_LINKLCDSTATEEVENTCONTROL 0x34C

/** Message ID for EVT_ATM_TC_LinkLcdStateChange */
#define EVT_ATM_TC_LINKLCDSTATECHANGE 0x6FC

/**
   This event contains the current state of ATM-TC LCD state machine.
*/
typedef struct EVT_ATM_TC_LinkLcdStateChange EVT_ATM_TC_LinkLcdStateChange_t;

/** Message ID for CMD_ATM_TC_LinkFsmStateEventControl */
#define CMD_ATM_TC_LINKFSMSTATEEVENTCONTROL 0x14D

/**
   This commands enables the generation of event messages when the FSM state changes
   for a given ATM-TC link.
*/
typedef struct CMD_ATM_TC_LinkFsmStateEventControl CMD_ATM_TC_LinkFsmStateEventControl_t;

/** Message ID for ACK_ATM_TC_LinkFsmStateEventControl */
#define ACK_ATM_TC_LINKFSMSTATEEVENTCONTROL 0x34D

/** Message ID for EVT_ATM_TC_LinkFsmStateChange */
#define EVT_ATM_TC_LINKFSMSTATECHANGE 0x6FD

/**
   This event contains the current state of ATM-TC FSM state machine.
*/
typedef struct EVT_ATM_TC_LinkFsmStateChange EVT_ATM_TC_LinkFsmStateChange_t;

/** Message ID for CMD_ATM_TC_LinkFailureEventControl */
#define CMD_ATM_TC_LINKFAILUREEVENTCONTROL 0x14E

/**
   NCD Failure:
   An NCD failure is declared when an NCD anomaly persists for more than 2.5 + 0.5s
   after the start of DATA MODE. An NCD failure terminates when no NCD anomaly is
   present for more than 10 + 0.5s.
   LCD Failure:
   An LCD failure is declared when an LCD defect persists for more than 2.5 + 0.5s. An
   LCD failure terminates when no LCD defect is present for more than 10 + 0.5s.
*/
typedef struct CMD_ATM_TC_LinkFailureEventControl CMD_ATM_TC_LinkFailureEventControl_t;

/** Message ID for ACK_ATM_TC_LinkFailureEventControl */
#define ACK_ATM_TC_LINKFAILUREEVENTCONTROL 0x34E

/** Message ID for EVT_ATM_TC_LinkNcdLcdFailure */
#define EVT_ATM_TC_LINKNCDLCDFAILURE 0x6FE

/**
   This event indicates a failure state in the ATM-TC state machine.
*/
typedef struct EVT_ATM_TC_LinkNcdLcdFailure EVT_ATM_TC_LinkNcdLcdFailure_t;

/** Message ID for CMD_ATM_InsertExtractControl */
#define CMD_ATM_INSERTEXTRACTCONTROL 0x145

/**
   This commands enables/disables the insert exctract functionality for a given link.
*/
typedef struct CMD_ATM_InsertExtractControl CMD_ATM_InsertExtractControl_t;

/** Message ID for ACK_ATM_InsertExtractControl */
#define ACK_ATM_INSERTEXTRACTCONTROL 0x345

/** Message ID for CMD_ATM_CellInsert */
#define CMD_ATM_CELLINSERT 0x146

/**
   This command inserts an ATM cell in the transmit direction to the line.
*/
typedef struct CMD_ATM_CellInsert CMD_ATM_CellInsert_t;

/** Message ID for ACK_ATM_CellInsert */
#define ACK_ATM_CELLINSERT 0x346

/** Message ID for CMD_ATM_InsertExtract_PM_ParamGet */
#define CMD_ATM_INSERTEXTRACT_PM_PARAMGET 0x147

/**
   This command is used to request the performance monitoring parameters for the ATM
   cell insert extract functionality.
*/
typedef struct CMD_ATM_InsertExtract_PM_ParamGet CMD_ATM_InsertExtract_PM_ParamGet_t;

/** Message ID for ACK_ATM_InsertExtract_PM_ParamGet */
#define ACK_ATM_INSERTEXTRACT_PM_PARAMGET 0x347

/**
   
*/
typedef struct ACK_ATM_InsertExtract_PM_ParamGet ACK_ATM_InsertExtract_PM_ParamGet_t;

/** Message ID for EVT_ATM_CellInserted */
#define EVT_ATM_CELLINSERTED 0x6FA

/**
   This event indicates that the cell was inserted into the data stream. This event is
   only generated when the CMD_ATM_CellInsert was acknowledged with a positive ack.
*/
typedef struct EVT_ATM_CellInserted EVT_ATM_CellInserted_t;

/** Message ID for EVT_ATM_CellExtracted */
#define EVT_ATM_CELLEXTRACTED 0x6FB

/**
   This event contains an extracted ATM cell.
*/
typedef struct EVT_ATM_CellExtracted EVT_ATM_CellExtracted_t;

/** Message ID for CMD_PMD_Reset */
#define CMD_PMD_RESET 0x160

/**
   This command resets the respective PMD and its associated database to the default
   state.
*/
typedef struct CMD_PMD_Reset CMD_PMD_Reset_t;

/** Message ID for ACK_PMD_Reset */
#define ACK_PMD_RESET 0x360

/** Message ID for CMD_PMD_Control */
#define CMD_PMD_CONTROL 0x161

/**
   This command controls the PMD Link enable, handshake cleardown and or Ignore
   incoming handshake.
*/
typedef struct CMD_PMD_Control CMD_PMD_Control_t;

/** Message ID for ACK_PMD_Control */
#define ACK_PMD_CONTROL 0x361

/** Message ID for CMD_PMD_StatusGet */
#define CMD_PMD_STATUSGET 0x162

/**
   This command requests the current status of the PMD.
*/
typedef struct CMD_PMD_StatusGet CMD_PMD_StatusGet_t;

/** Message ID for ACK_PMD_StatusGet */
#define ACK_PMD_STATUSGET 0x362

/**
   This acknowledgement returns the current status of the PMD.
*/
typedef struct ACK_PMD_StatusGet ACK_PMD_StatusGet_t;

/** Message ID for CMD_PMD_ChannelControl */
#define CMD_PMD_CHANNELCONTROL 0x163

/**
   This command enables/disables a PMD channel.
*/
typedef struct CMD_PMD_ChannelControl CMD_PMD_ChannelControl_t;

/** Message ID for ACK_PMD_ChannelControl */
#define ACK_PMD_CHANNELCONTROL 0x363

/** Message ID for CMD_PMD_PM_ParamGet */
#define CMD_PMD_PM_PARAMGET 0x164

/**
   This command requests the performance monitoring parameters from the local PMD or
   the link partner PMD or any repeaters.
*/
typedef struct CMD_PMD_PM_ParamGet CMD_PMD_PM_ParamGet_t;

/** Message ID for ACK_PMD_PM_ParamGet */
#define ACK_PMD_PM_PARAMGET 0x364

/**
   This acknowledgement returns the performance monitoring counters for the local PMD
   and the link partner PMD.
*/
typedef struct ACK_PMD_PM_ParamGet ACK_PMD_PM_ParamGet_t;

/** Message ID for CMD_PMD_LinkStateGet */
#define CMD_PMD_LINKSTATEGET 0x165

/**
   This command requests the link state of the local and remote units. After performing
   this command on a local unit the link state will be reevaluated, the device fault
   will only be removed when all alarms are zero.
*/
typedef struct CMD_PMD_LinkStateGet CMD_PMD_LinkStateGet_t;

/** Message ID for ACK_PMD_LinkStateGet */
#define ACK_PMD_LINKSTATEGET 0x365

/**
   This acknowledgement returns the status of the local and remote units.
*/
typedef struct ACK_PMD_LinkStateGet ACK_PMD_LinkStateGet_t;

/** Message ID for EVT_PMD_LinkState */
#define EVT_PMD_LINKSTATE 0x690

/**
   This event indicates the PMD state for a given link. This Event will be sent each
   time the PMD state changes.
*/
typedef struct EVT_PMD_LinkState EVT_PMD_LinkState_t;

/** Message ID for ALM_PMD_StatusChanged */
#define ALM_PMD_STATUSCHANGED 0x603

/**
   This alarm indicates the PMD status has changed for a given link. This Event will be
   sent each time the PMD state changes.
*/
typedef struct ALM_PMD_StatusChanged ALM_PMD_StatusChanged_t;

/** Message ID for CMD_PMD_AlarmControl */
#define CMD_PMD_ALARMCONTROL 0x166

/**
   This command control the generation of ALM_PMD_StatusChanged messages for a given
   link.
*/
typedef struct CMD_PMD_AlarmControl CMD_PMD_AlarmControl_t;

/** Message ID for ACK_PMD_AlarmControl */
#define ACK_PMD_ALARMCONTROL 0x366

/** Message ID for CMD_PMD_MultiWireMappingGet */
#define CMD_PMD_MULTIWIREMAPPINGGET 0x167

/**
   This command requests the multi wire mapping for a M Pair link.
*/
typedef struct CMD_PMD_MultiWireMappingGet CMD_PMD_MultiWireMappingGet_t;

/** Message ID for ACK_PMD_MultiWireMappingGet */
#define ACK_PMD_MULTIWIREMAPPINGGET 0x367

/**
   This acknowledgement returns the multi wire mapping for a M Pair configured link.
*/
typedef struct ACK_PMD_MultiWireMappingGet ACK_PMD_MultiWireMappingGet_t;

/** Message ID for EVT_PMD_MultiWireMapping */
#define EVT_PMD_MULTIWIREMAPPING 0x691

/**
   This event indicates the multi wire mapping a given link. This Event will be sent
   each time the mapping changes.
*/
typedef struct EVT_PMD_MultiWireMapping EVT_PMD_MultiWireMapping_t;

/** Message ID for EVT_PMD_MPairStatus */
#define EVT_PMD_MPAIRSTATUS 0x692

/**
   This event indicates the PMD state for a given link. This Event will be sent each
   time the PMD state changes.
*/
typedef struct EVT_PMD_MPairStatus EVT_PMD_MPairStatus_t;

/** Message ID for CMD_PMD_SM_Control */
#define CMD_PMD_SM_CONTROL 0x169

/**
   This command enables/disables the PMD state machine, by default the PMD state
   machine is enabled.
*/
typedef struct CMD_PMD_SM_Control CMD_PMD_SM_Control_t;

/** Message ID for ACK_PMD_SM_Control */
#define ACK_PMD_SM_CONTROL 0x369

/** Message ID for EVT_PMD_DelayCompState */
#define EVT_PMD_DELAYCOMPSTATE 0x693

/**
   This event indicates that delay compensation was performed for a M-pair bundle.
*/
typedef struct EVT_PMD_DelayCompState EVT_PMD_DelayCompState_t;

/** Message ID for ALM_PMD_TC_LayerMismatch */
#define ALM_PMD_TC_LAYERMISMATCH 0x604

/**
   This alarm indicates that the peer device has a different TC layer or no common TC
   layer was selected during handshake.
*/
typedef struct ALM_PMD_TC_LayerMismatch ALM_PMD_TC_LayerMismatch_t;

/** Message ID for CMD_PMD_DelayComp */
#define CMD_PMD_DELAYCOMP 0x16C

/**
   This command controls a host driven delay compensation.
*/
typedef struct CMD_PMD_DelayComp CMD_PMD_DelayComp_t;

/** Message ID for ACK_PMD_DelayComp */
#define ACK_PMD_DELAYCOMP 0x36C

/** Message ID for CMD_Clause30_PM_ParamLineSideGet */
#define CMD_CLAUSE30_PM_PARAMLINESIDEGET 0x170

/**
   This command requests the performance monitoring parameters for the clause 30 line
   side.
*/
typedef struct CMD_Clause30_PM_ParamLineSideGet CMD_Clause30_PM_ParamLineSideGet_t;

/** Message ID for ACK_Clause30_PM_ParamLineSideGet */
#define ACK_CLAUSE30_PM_PARAMLINESIDEGET 0x370

/**
   This acknowledgement returns the performance monitoring counters for clause 30 line
   side. All counters are delta counters (the delta value from the last get) and are
   wrap around
*/
typedef struct ACK_Clause30_PM_ParamLineSideGet ACK_Clause30_PM_ParamLineSideGet_t;

/** Message ID for CMD_Clause30_PM_ParamSystemSideGet */
#define CMD_CLAUSE30_PM_PARAMSYSTEMSIDEGET 0x171

/**
   This command requests the performance monitoring parameters for the clause 30 System
   side.
*/
typedef struct CMD_Clause30_PM_ParamSystemSideGet CMD_Clause30_PM_ParamSystemSideGet_t;

/** Message ID for ACK_Clause30_PM_ParamSystemSideGet */
#define ACK_CLAUSE30_PM_PARAMSYSTEMSIDEGET 0x371

/**
   This acknowledgement returns the performance monitoring counters for clause 30
   system side. All counters are delta counters (the delta value from the last get) and
   are wrap around
*/
typedef struct ACK_Clause30_PM_ParamSystemSideGet ACK_Clause30_PM_ParamSystemSideGet_t;

/** Message ID for CMD_VCC_MappingGet */
#define CMD_VCC_MAPPINGGET 0x178

/**
   This command requests the mapping between the VCC entries and the segmentation
   channels, i. e. the ATM entries (0..7) in the MAC VPI/VCI map table.
*/
typedef struct CMD_VCC_MappingGet CMD_VCC_MappingGet_t;

/** Message ID for ACK_VCC_MappingGet */
#define ACK_VCC_MAPPINGGET 0x378

/**
   This acknowledge returns the mapping between the VCC entries and the segmentation
   channels, i. e. the ATM entries (0..7) in the MAC VPI/VCI map table.
*/
typedef struct ACK_VCC_MappingGet ACK_VCC_MappingGet_t;

/** Message ID for CMD_AAL5_Segmentation_PM_ParamGet */
#define CMD_AAL5_SEGMENTATION_PM_PARAMGET 0x179

/**
   This command requests the performance monitoring parameters for the AAL5
   Segmentation.
*/
typedef struct CMD_AAL5_Segmentation_PM_ParamGet CMD_AAL5_Segmentation_PM_ParamGet_t;

/** Message ID for ACK_AAL5_Segmentation_PM_ParamGet */
#define ACK_AAL5_SEGMENTATION_PM_PARAMGET 0x379

/**
   This acknowledgement returns the performance monitoring counters for AAL5
   Segmentation. All counters are delta counters (the delta value from the last get)
   and are wrap around. For channel to VCC (VPI/VCI) mapping see CMD_VCC_MappingGet.
*/
typedef struct ACK_AAL5_Segmentation_PM_ParamGet ACK_AAL5_Segmentation_PM_ParamGet_t;

/** Message ID for CMD_AAL5_Reassembly1_PM_ParamGet */
#define CMD_AAL5_REASSEMBLY1_PM_PARAMGET 0x17A

/**
   This command requests the performance monitoring parameters for the AAL5 Reassembly
   section 1.
*/
typedef struct CMD_AAL5_Reassembly1_PM_ParamGet CMD_AAL5_Reassembly1_PM_ParamGet_t;

/** Message ID for ACK_AAL5_Reassembly1_PM_ParamGet */
#define ACK_AAL5_REASSEMBLY1_PM_PARAMGET 0x37A

/**
   This acknowledgement returns the performance monitoring counters for AAL5 Reassembly
   section 1. All counters are delta counters (the delta value from the last get) and
   are wrap around. For channel to VPI/VCI mapping see message
   CMD_Reassembly_MappingGet.
*/
typedef struct ACK_AAL5_Reassembly1_PM_ParamGet ACK_AAL5_Reassembly1_PM_ParamGet_t;

/** Message ID for CMD_AAL5_Reassembly2_PM_ParamGet */
#define CMD_AAL5_REASSEMBLY2_PM_PARAMGET 0x17B

/**
   This command requests the performance monitoring parameters for the AAL5 Reassembly
   section 2.
*/
typedef struct CMD_AAL5_Reassembly2_PM_ParamGet CMD_AAL5_Reassembly2_PM_ParamGet_t;

/** Message ID for ACK_AAL5_Reassembly2_PM_ParamGet */
#define ACK_AAL5_REASSEMBLY2_PM_PARAMGET 0x37B

/**
   This acknowledgement returns the performance monitoring counters for AAL5 Reassembly
   section 2. All counters are delta counters (the delta value from the last get) and
   are wrap around. For channel to VPI/VCI mapping see message
   CMD_Reassembly_MappingGet.
*/
typedef struct ACK_AAL5_Reassembly2_PM_ParamGet ACK_AAL5_Reassembly2_PM_ParamGet_t;

/** Message ID for CMD_Reassembly_MappingGet */
#define CMD_REASSEMBLY_MAPPINGGET 0x17C

/**
   This command requests the mapping between reassembly channels (0..7) and ATM cell
   header (VPI/VCI combination) that is used for comparison of incoming ATM cells.
*/
typedef struct CMD_Reassembly_MappingGet CMD_Reassembly_MappingGet_t;

/** Message ID for ACK_Reassembly_MappingGet */
#define ACK_REASSEMBLY_MAPPINGGET 0x37C

/**
   This acknowledgement returns the VPI/VCI entries for the reassembly channels that
   are used for comparison with the headers of incoming ATM cells.
*/
typedef struct ACK_Reassembly_MappingGet ACK_Reassembly_MappingGet_t;

/**
   This data structure defines the Ethernet OAM flags field used in the following
   messages
*/
typedef struct Ethernet_OAM_Flags Ethernet_OAM_Flags_t;

/** Message ID for CMD_Ethernet_OAM_Control */
#define CMD_ETHERNET_OAM_CONTROL 0x150

/**
   This command enables/disables the Ethernet OAM functionality, the device must be in
   MAC mode and the TC layer must be EFM.
*/
typedef struct CMD_Ethernet_OAM_Control CMD_Ethernet_OAM_Control_t;

/** Message ID for ACK_Ethernet_OAM_Control */
#define ACK_ETHERNET_OAM_CONTROL 0x350

/** Message ID for CMD_Ethernet_OAMPDU_Request */
#define CMD_ETHERNET_OAMPDU_REQUEST 0x151

/**
   This command is used to transfer an OAMPDU to a peer OAM client entity, Ethernet OAM
   must be enabled before this command can be sent.
*/
typedef struct CMD_Ethernet_OAMPDU_Request CMD_Ethernet_OAMPDU_Request_t;

/** Message ID for ACK_Ethernet_OAMPDU_Request */
#define ACK_ETHERNET_OAMPDU_REQUEST 0x351

/** Message ID for EVT_Ethernet_OAMPDU_Indication */
#define EVT_ETHERNET_OAMPDU_INDICATION 0x6A0

/**
   This event indicates the arrival of OAMPDU which is not processed by the local IDC
   Ethernet OAM process, the device must be in MAC mode, the TC layer must be EFM and
   Ethernet OAM must be enabled.
*/
typedef struct EVT_Ethernet_OAMPDU_Indication EVT_Ethernet_OAMPDU_Indication_t;

/** Message ID for CMD_Ethernet_OAM_CTL_Request */
#define CMD_ETHERNET_OAM_CTL_REQUEST 0x152

/**
   This command is used to transfer an OAM_CTL to a peer OAM client entity, Ethernet
   OAM must be enabled before this command can be sent.
*/
typedef struct CMD_Ethernet_OAM_CTL_Request CMD_Ethernet_OAM_CTL_Request_t;

/** Message ID for ACK_Ethernet_OAM_CTL_Request */
#define ACK_ETHERNET_OAM_CTL_REQUEST 0x352

/** Message ID for EVT_Ethernet_OAM_CTL_Indication */
#define EVT_ETHERNET_OAM_CTL_INDICATION 0x6A1

/**
   This event indicates local state information has changed, the event will only be
   generated when the ethernet OAM is enabled and an host is present.
*/
typedef struct EVT_Ethernet_OAM_CTL_Indication EVT_Ethernet_OAM_CTL_Indication_t;

/** Message ID for CMD_Ethernet_OAM_StateEventControl */
#define CMD_ETHERNET_OAM_STATEEVENTCONTROL 0x153

/**
   This command enables/disables the generation of events when the OAM discovery,
   Transmit and Multiplexer state machine changes, the device must be in MAC mode and
   the TC layer must be EFM.
*/
typedef struct CMD_Ethernet_OAM_StateEventControl CMD_Ethernet_OAM_StateEventControl_t;

/** Message ID for ACK_Ethernet_OAM_StateEventControl */
#define ACK_ETHERNET_OAM_STATEEVENTCONTROL 0x353

/** Message ID for CMD_Ethernet_OAM_StateGet */
#define CMD_ETHERNET_OAM_STATEGET 0x154

/**
   This command get the current OAM discovery, Transmit and Multiplexer state machine
   states, the device must be in MAC mode and the TC layer must be EFM.
*/
typedef struct CMD_Ethernet_OAM_StateGet CMD_Ethernet_OAM_StateGet_t;

/** Message ID for ACK_Ethernet_OAM_StateGet */
#define ACK_ETHERNET_OAM_STATEGET 0x354

/**
   This contains the current state of the OAM Discovery, Transmit and Multiplexer state
   machines, the device must be in MAC mode, the TC layer must be EFM and ethernet OAM
   must be enabled.
*/
typedef struct ACK_Ethernet_OAM_StateGet ACK_Ethernet_OAM_StateGet_t;

/** Message ID for EVT_Ethernet_OAM_DiscoveryStateChange */
#define EVT_ETHERNET_OAM_DISCOVERYSTATECHANGE 0x6A5

/**
   This event indicates local Discovery state has changed, the event will only be
   generated when the Ethernet OAM is enabled and an host is present.
*/
typedef struct EVT_Ethernet_OAM_DiscoveryStateChange EVT_Ethernet_OAM_DiscoveryStateChange_t;

/** Message ID for EVT_Ethernet_OAM_TransmitStateChange */
#define EVT_ETHERNET_OAM_TRANSMITSTATECHANGE 0x6A6

/**
   This event indicates local Transmit state has changed, the event will only be
   generated when the ethernet OAM is enabled and an host is present.
*/
typedef struct EVT_Ethernet_OAM_TransmitStateChange EVT_Ethernet_OAM_TransmitStateChange_t;

/** Message ID for EVT_Ethernet_OAM_MultiplexerStateChange */
#define EVT_ETHERNET_OAM_MULTIPLEXERSTATECHANGE 0x6A7

/**
   This event indicates local Multiplexer state has changed, the event will only be
   generated when the ethernet OAM is enabled and an host is present.
*/
typedef struct EVT_Ethernet_OAM_MultiplexerStateChange EVT_Ethernet_OAM_MultiplexerStateChange_t;

/** Message ID for CMD_EthernetInsertExtractControl */
#define CMD_ETHERNETINSERTEXTRACTCONTROL 0x158

/**
   This command enables/disables the ethernet insert/extract to the system/line side.
*/
typedef struct CMD_EthernetInsertExtractControl CMD_EthernetInsertExtractControl_t;

/** Message ID for ACK_EthernetInsertExtractControl */
#define ACK_ETHERNETINSERTEXTRACTCONTROL 0x358

/** Message ID for CMD_EthernetFrameInsertSystem */
#define CMD_ETHERNETFRAMEINSERTSYSTEM 0x159

/**
   This command inserts an ethernet frame or fragment to the system side in receive
   direction.
*/
typedef struct CMD_EthernetFrameInsertSystem CMD_EthernetFrameInsertSystem_t;

/** Message ID for ACK_EthernetFrameInsertSystem */
#define ACK_ETHERNETFRAMEINSERTSYSTEM 0x359

/** Message ID for CMD_EthernetFrameInsertLine */
#define CMD_ETHERNETFRAMEINSERTLINE 0x15A

/**
   This command inserts an ethernet frame or fragment to the Line side in transmit
   direction.
*/
typedef struct CMD_EthernetFrameInsertLine CMD_EthernetFrameInsertLine_t;

/** Message ID for ACK_EthernetFrameInsertLine */
#define ACK_ETHERNETFRAMEINSERTLINE 0x35A

/** Message ID for EVT_EthernetFrameInserted */
#define EVT_ETHERNETFRAMEINSERTED 0x6A2

/**
   This event indicates the insertion of an ethernet frame into the Line or system
   side.
*/
typedef struct EVT_EthernetFrameInserted EVT_EthernetFrameInserted_t;

/** Message ID for EVT_EthernetFrameExtractSystem */
#define EVT_ETHERNETFRAMEEXTRACTSYSTEM 0x6A3

/**
   This event indicates the extraction of an ethernet frame from the system side in
   transmit direction.
*/
typedef struct EVT_EthernetFrameExtractSystem EVT_EthernetFrameExtractSystem_t;

/** Message ID for EVT_EthernetFrameExtractLine */
#define EVT_ETHERNETFRAMEEXTRACTLINE 0x6A4

/**
   This event indicates the extraction of an ethernet frame from the line side in
   receive direction.
*/
typedef struct EVT_EthernetFrameExtractLine EVT_EthernetFrameExtractLine_t;

/** Message ID for EVT_EFM_TC_SyncStateChanged */
#define EVT_EFM_TC_SYNCSTATECHANGED 0x6B0

/**
   This event indicates if the sync state of the local or the remote EFM-TC changed.
*/
typedef struct EVT_EFM_TC_SyncStateChanged EVT_EFM_TC_SyncStateChanged_t;

/** Message ID for CMD_EOC_Control */
#define CMD_EOC_CONTROL 0x168

/**
   This command enables/disables EOC handling for a link.
*/
typedef struct CMD_EOC_Control CMD_EOC_Control_t;

/** Message ID for ACK_EOC_Control */
#define ACK_EOC_CONTROL 0x368

/** Message ID for CMD_EOC_StatusRequestControl */
#define CMD_EOC_STATUSREQUESTCONTROL 0x16A

/**
   This command defines the time period for performance status collection via the EOC
   channel.
*/
typedef struct CMD_EOC_StatusRequestControl CMD_EOC_StatusRequestControl_t;

/** Message ID for ACK_EOC_StatusRequestControl */
#define ACK_EOC_STATUSREQUESTCONTROL 0x36A

/** Message ID for CMD_EOC_ConfigGet */
#define CMD_EOC_CONFIGGET 0x16B

/**
   Read the EOC configuration for a link.
*/
typedef struct CMD_EOC_ConfigGet CMD_EOC_ConfigGet_t;

/** Message ID for ACK_EOC_ConfigGet */
#define ACK_EOC_CONFIGGET 0x36B

/**
   
*/
typedef struct ACK_EOC_ConfigGet ACK_EOC_ConfigGet_t;

/** Message ID for EVT_EOC_Config */
#define EVT_EOC_CONFIG 0x68A

/**
   Event to inform the host about EOC configuration changes.
*/
typedef struct EVT_EOC_Config EVT_EOC_Config_t;

/** Message ID for CMD_TDM_Get_SDI_Settings */
#define CMD_TDM_GET_SDI_SETTINGS 0x130

/**
   
*/
typedef struct CMD_TDM_Get_SDI_Settings CMD_TDM_Get_SDI_Settings_t;

/** Message ID for ACK_TDM_Get_SDI_Settings */
#define ACK_TDM_GET_SDI_SETTINGS 0x330

/**
   
*/
typedef struct ACK_TDM_Get_SDI_Settings ACK_TDM_Get_SDI_Settings_t;

/** Message ID for NFC_TDM_Get_SDI_Settings */
#define NFC_TDM_GET_SDI_SETTINGS 0x530

/**
   
*/
typedef struct NFC_TDM_Get_SDI_Settings NFC_TDM_Get_SDI_Settings_t;

/** Message ID for CMD_TDM_Get_PMD_Settings */
#define CMD_TDM_GET_PMD_SETTINGS 0x131

/** Message ID for ACK_TDM_Get_PMD_Settings */
#define ACK_TDM_GET_PMD_SETTINGS 0x331

/**
   
*/
typedef struct ACK_TDM_Get_PMD_Settings ACK_TDM_Get_PMD_Settings_t;

/** Message ID for CMD_TDM_RefPortGet */
#define CMD_TDM_REFPORTGET 0x132

/** Message ID for ACK_TDM_RefPortGet */
#define ACK_TDM_REFPORTGET 0x332

/**
   
*/
typedef struct ACK_TDM_RefPortGet ACK_TDM_RefPortGet_t;

/** Message ID for CMD_TDM_RefPortSet */
#define CMD_TDM_REFPORTSET 0x133

/**
   Select the available reference ports for the receive clocking of the TDM interface.
*/
typedef struct CMD_TDM_RefPortSet CMD_TDM_RefPortSet_t;

/** Message ID for ACK_TDM_RefPortSet */
#define ACK_TDM_REFPORTSET 0x333

/** Message ID for CMD_DbgGetPDI_Short */
#define CMD_DBGGETPDI_SHORT 0x112

/**
   
*/
typedef struct CMD_DbgGetPDI_Short CMD_DbgGetPDI_Short_t;

/** Message ID for ACK_DbgGetPDI_Short */
#define ACK_DBGGETPDI_SHORT 0x312

/**
   
*/
typedef struct ACK_DbgGetPDI_Short ACK_DbgGetPDI_Short_t;

/** Message ID for CMD_DbgSetPDI_Short */
#define CMD_DBGSETPDI_SHORT 0x113

/**
   
*/
typedef struct CMD_DbgSetPDI_Short CMD_DbgSetPDI_Short_t;

/** Message ID for ACK_DbgSetPDI_Short */
#define ACK_DBGSETPDI_SHORT 0x313

/** Message ID for CMD_DbgGetPDI */
#define CMD_DBGGETPDI 0x114

/**
   
*/
typedef struct CMD_DbgGetPDI CMD_DbgGetPDI_t;

/** Message ID for ACK_DbgGetPDI */
#define ACK_DBGGETPDI 0x314

/**
   
*/
typedef struct ACK_DbgGetPDI ACK_DbgGetPDI_t;

/** Message ID for CMD_DbgSetPDI */
#define CMD_DBGSETPDI 0x115

/**
   
*/
typedef struct CMD_DbgSetPDI CMD_DbgSetPDI_t;

/** Message ID for ACK_DbgSetPDI */
#define ACK_DBGSETPDI 0x315

/** Message ID for CMD_DbgGetFPI */
#define CMD_DBGGETFPI 0x116

/**
   
*/
typedef struct CMD_DbgGetFPI CMD_DbgGetFPI_t;

/** Message ID for ACK_DbgGetFPI */
#define ACK_DBGGETFPI 0x316

/**
   
*/
typedef struct ACK_DbgGetFPI ACK_DbgGetFPI_t;

/** Message ID for CMD_DbgSetFPI */
#define CMD_DBGSETFPI 0x117

/**
   
*/
typedef struct CMD_DbgSetFPI CMD_DbgSetFPI_t;

/** Message ID for ACK_DbgSetFPI */
#define ACK_DBGSETFPI 0x317

/** Message ID for CMD_Dbg_PMD_AuxRegWrite */
#define CMD_DBG_PMD_AUXREGWRITE 0x129

/**
   
*/
typedef struct CMD_Dbg_PMD_AuxRegWrite CMD_Dbg_PMD_AuxRegWrite_t;

/** Message ID for ACK_Dbg_PMD_AuxRegWrite */
#define ACK_DBG_PMD_AUXREGWRITE 0x329

/** Message ID for CMD_Dbg_PMD_AuxRegRead */
#define CMD_DBG_PMD_AUXREGREAD 0x12A

/**
   
*/
typedef struct CMD_Dbg_PMD_AuxRegRead CMD_Dbg_PMD_AuxRegRead_t;

/** Message ID for ACK_Dbg_PMD_AuxRegRead */
#define ACK_DBG_PMD_AUXREGREAD 0x32A

/**
   
*/
typedef struct ACK_Dbg_PMD_AuxRegRead ACK_Dbg_PMD_AuxRegRead_t;

/** Message ID for CMD_Dbg_PMD_RS_RegWrite */
#define CMD_DBG_PMD_RS_REGWRITE 0x12B

/**
   
*/
typedef struct CMD_Dbg_PMD_RS_RegWrite CMD_Dbg_PMD_RS_RegWrite_t;

/** Message ID for ACK_Dbg_PMD_RS_RegWrite */
#define ACK_DBG_PMD_RS_REGWRITE 0x32B

/** Message ID for CMD_Dbg_PMD_RS_RegRead */
#define CMD_DBG_PMD_RS_REGREAD 0x12C

/**
   
*/
typedef struct CMD_Dbg_PMD_RS_RegRead CMD_Dbg_PMD_RS_RegRead_t;

/** Message ID for ACK_Dbg_PMD_RS_RegRead */
#define ACK_DBG_PMD_RS_REGREAD 0x32C

/**
   
*/
typedef struct ACK_Dbg_PMD_RS_RegRead ACK_Dbg_PMD_RS_RegRead_t;

/** Message ID for CMD_Dbg_AUX_RS_TraceControl */
#define CMD_DBG_AUX_RS_TRACECONTROL 0x12D

/**
   This command switches ON / OFF the AUX and Ram Shell register trace, by default the
   trace is diabled.
*/
typedef struct CMD_Dbg_AUX_RS_TraceControl CMD_Dbg_AUX_RS_TraceControl_t;

/** Message ID for ACK_Dbg_AUX_RS_TraceControl */
#define ACK_DBG_AUX_RS_TRACECONTROL 0x32D

/** Message ID for DBG_AUX_RegisterAccess */
#define DBG_AUX_REGISTERACCESS 0x701

/**
   This debug trace is generated when the AUX RS trace is enabled.
*/
typedef struct DBG_AUX_RegisterAccess DBG_AUX_RegisterAccess_t;

/** Message ID for DBG_RS_RegisterAccess */
#define DBG_RS_REGISTERACCESS 0x702

/**
   This debug trace is generated when the AUX RS trace is enabled.
*/
typedef struct DBG_RS_RegisterAccess DBG_RS_RegisterAccess_t;

/** Message ID for CMD_DbgCounterRead */
#define CMD_DBGCOUNTERREAD 0x119

/**
   This command reads counter values from the counter memory.
*/
typedef struct CMD_DbgCounterRead CMD_DbgCounterRead_t;

/** Message ID for ACK_DbgCounterRead */
#define ACK_DBGCOUNTERREAD 0x319

/**
   
*/
typedef struct ACK_DbgCounterRead ACK_DbgCounterRead_t;

/** Message ID for CMD_DbgCounterMemoryWrite */
#define CMD_DBGCOUNTERMEMORYWRITE 0x11C

/**
   This command writes a counter memory location.
*/
typedef struct CMD_DbgCounterMemoryWrite CMD_DbgCounterMemoryWrite_t;

/** Message ID for ACK_DbgCounterMemoryWrite */
#define ACK_DBGCOUNTERMEMORYWRITE 0x31C

/** Message ID for CMD_DbgCounterMemoryRead */
#define CMD_DBGCOUNTERMEMORYREAD 0x11D

/**
   This command reads a counter memory location.
*/
typedef struct CMD_DbgCounterMemoryRead CMD_DbgCounterMemoryRead_t;

/** Message ID for ACK_DbgCounterMemoryRead */
#define ACK_DBGCOUNTERMEMORYREAD 0x31D

/**
   
*/
typedef struct ACK_DbgCounterMemoryRead ACK_DbgCounterMemoryRead_t;

/** Message ID for CMD_DbgSAR_MapTableDump */
#define CMD_DBGSAR_MAPTABLEDUMP 0x11A

/**
   This command dumps the contents of the SAR mapping table. For details of the memory
   format see the SAR-AAL5 Design Specification
*/
typedef struct CMD_DbgSAR_MapTableDump CMD_DbgSAR_MapTableDump_t;

/** Message ID for ACK_DbgSAR_MapTableDump */
#define ACK_DBGSAR_MAPTABLEDUMP 0x31A

/**
   
*/
typedef struct ACK_DbgSAR_MapTableDump ACK_DbgSAR_MapTableDump_t;

/** Message ID for CMD_Dbg_SCI_StatisticsGet */
#define CMD_DBG_SCI_STATISTICSGET 0x11B

/** Message ID for ACK_Dbg_SCI_StatisticsGet */
#define ACK_DBG_SCI_STATISTICSGET 0x31B

/**
   This acknowledgement contains the global statistics for the SCI interface.
*/
typedef struct ACK_Dbg_SCI_StatisticsGet ACK_Dbg_SCI_StatisticsGet_t;

/** Message ID for NFC_Dbg_SCI_LinkStatistics */
#define NFC_DBG_SCI_LINKSTATISTICS 0x51B

/**
   This notification contains the link specific statistics for the SCI interface.
*/
typedef struct NFC_Dbg_SCI_LinkStatistics NFC_Dbg_SCI_LinkStatistics_t;

/** Message ID for CMD_PAF_SeqNoAdapt */
#define CMD_PAF_SEQNOADAPT 0x124

/**
   This command is used to manually apply the PAF expected sequence number adaptation.
*/
typedef struct CMD_PAF_SeqNoAdapt CMD_PAF_SeqNoAdapt_t;

/** Message ID for ACK_PAF_SeqNoAdapt */
#define ACK_PAF_SEQNOADAPT 0x324

/**
   
*/
typedef struct ACK_PAF_SeqNoAdapt ACK_PAF_SeqNoAdapt_t;

/** Message ID for CMD_PAF_InfoGet */
#define CMD_PAF_INFOGET 0x125

/**
   This command is used to read information about the PAF interrupt service routines,
   state machine surveillance and adaptation algorithms.
*/
typedef struct CMD_PAF_InfoGet CMD_PAF_InfoGet_t;

/** Message ID for ACK_PAF_InfoGet */
#define ACK_PAF_INFOGET 0x325

/**
   
*/
typedef struct ACK_PAF_InfoGet ACK_PAF_InfoGet_t;

/** Message ID for CMD_BACP_Initialize */
#define CMD_BACP_INITIALIZE 0x138

/**
   This command is used to start initialization of a single PME PAF. This is only
   needed if the autonomous initialization is disabled in the BACP configuration
   message.
*/
typedef struct CMD_BACP_Initialize CMD_BACP_Initialize_t;

/** Message ID for ACK_BACP_Initialize */
#define ACK_BACP_INITIALIZE 0x338

/** Message ID for CMD_BACP_PmeTransfer */
#define CMD_BACP_PMETRANSFER 0x139

/**
   This command is used to move a PME from a source PAF to a target PAF.
*/
typedef struct CMD_BACP_PmeTransfer CMD_BACP_PmeTransfer_t;

/** Message ID for ACK_BACP_PmeTransfer */
#define ACK_BACP_PMETRANSFER 0x339

/** Message ID for CMD_BACP_PmeRemove */
#define CMD_BACP_PMEREMOVE 0x13A

/**
   This command is used to remove a PME from a source PAF.
*/
typedef struct CMD_BACP_PmeRemove CMD_BACP_PmeRemove_t;

/** Message ID for ACK_BACP_PmeRemove */
#define ACK_BACP_PMEREMOVE 0x33A

/** Message ID for EVT_BACP_Protocol */
#define EVT_BACP_PROTOCOL 0x6AB

/**
   This event provides information about the Bonding Aggregation Control Protocol to
   the external host.
*/
typedef struct EVT_BACP_Protocol EVT_BACP_Protocol_t;

/** Message ID for CMD_BACP_PmeStatus */
#define CMD_BACP_PMESTATUS 0x13C

/**
   This command is used to query the PME status.
*/
typedef struct CMD_BACP_PmeStatus CMD_BACP_PmeStatus_t;

/** Message ID for ACK_BACP_PmeStatus */
#define ACK_BACP_PMESTATUS 0x33C

/**
   
*/
typedef struct ACK_BACP_PmeStatus ACK_BACP_PmeStatus_t;

/** Message ID for EVT_BACP_Dbg */
#define EVT_BACP_DBG 0x6AA

/**
   This event is intended for BACP debugging. The content is subject to change!
*/
typedef struct EVT_BACP_Dbg EVT_BACP_Dbg_t;

/** Message ID for CMD_BACP_DbgConfig */
#define CMD_BACP_DBGCONFIG 0x13D

/**
   This command is used to configure BACP debugging. The content is subject to change!
*/
typedef struct CMD_BACP_DbgConfig CMD_BACP_DbgConfig_t;

/** Message ID for ACK_BACP_DbgConfig */
#define ACK_BACP_DBGCONFIG 0x33D

/** Message ID for CMD_BACP_DbgSendPdu */
#define CMD_BACP_DBGSENDPDU 0x13E

/**
   This command is used to transmit a BACPDU for debugging purposes.
*/
typedef struct CMD_BACP_DbgSendPdu CMD_BACP_DbgSendPdu_t;

/** Message ID for ACK_BACP_DbgSendPdu */
#define ACK_BACP_DBGSENDPDU 0x33E

/** Message ID for CMD_TNL_PMD_0_Message */
#define CMD_TNL_PMD_0_MESSAGE 0x180

/**
   This message is used to transport commands to the PMD 0, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
typedef struct CMD_TNL_PMD_0_Message CMD_TNL_PMD_0_Message_t;

/** Message ID for ACK_TNL_PMD_0_Message */
#define ACK_TNL_PMD_0_MESSAGE 0x380

/**
   This message is used to transport acknowledgements from the PMD 0.
*/
typedef struct ACK_TNL_PMD_0_Message ACK_TNL_PMD_0_Message_t;

/** Message ID for NFC_TNL_PMD_0_Message */
#define NFC_TNL_PMD_0_MESSAGE 0x580

/**
   This message is used to transport Notifications from the PMD 0, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
typedef struct NFC_TNL_PMD_0_Message NFC_TNL_PMD_0_Message_t;

/** Message ID for CMD_TNL_PMD_1_Message */
#define CMD_TNL_PMD_1_MESSAGE 0x181

/**
   This message is used to transport commands to the PMD 1, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
typedef struct CMD_TNL_PMD_1_Message CMD_TNL_PMD_1_Message_t;

/** Message ID for ACK_TNL_PMD_1_Message */
#define ACK_TNL_PMD_1_MESSAGE 0x381

/**
   This message is used to transport acknowledgements from the PMD 1.
*/
typedef struct ACK_TNL_PMD_1_Message ACK_TNL_PMD_1_Message_t;

/** Message ID for NFC_TNL_PMD_1_Message */
#define NFC_TNL_PMD_1_MESSAGE 0x581

/**
   This message is used to transport Notifications from the PMD 1, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
typedef struct NFC_TNL_PMD_1_Message NFC_TNL_PMD_1_Message_t;

/** Message ID for CMD_TNL_PMD_2_Message */
#define CMD_TNL_PMD_2_MESSAGE 0x182

/**
   This message is used to transport commands to the PMD 2, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
typedef struct CMD_TNL_PMD_2_Message CMD_TNL_PMD_2_Message_t;

/** Message ID for ACK_TNL_PMD_2_Message */
#define ACK_TNL_PMD_2_MESSAGE 0x382

/**
   This message is used to transport acknowledgements from the PMD 2.
*/
typedef struct ACK_TNL_PMD_2_Message ACK_TNL_PMD_2_Message_t;

/** Message ID for NFC_TNL_PMD_2_Message */
#define NFC_TNL_PMD_2_MESSAGE 0x582

/**
   This message is used to transport Notifications from the PMD 2, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
typedef struct NFC_TNL_PMD_2_Message NFC_TNL_PMD_2_Message_t;

/** Message ID for CMD_TNL_PMD_3_Message */
#define CMD_TNL_PMD_3_MESSAGE 0x183

/**
   This message is used to transport commands to the PMD 3, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
typedef struct CMD_TNL_PMD_3_Message CMD_TNL_PMD_3_Message_t;

/** Message ID for ACK_TNL_PMD_3_Message */
#define ACK_TNL_PMD_3_MESSAGE 0x383

/**
   This message is used to transport acknowledgements from the PMD 3.
*/
typedef struct ACK_TNL_PMD_3_Message ACK_TNL_PMD_3_Message_t;

/** Message ID for NFC_TNL_PMD_3_Message */
#define NFC_TNL_PMD_3_MESSAGE 0x583

/**
   This message is used to transport Notifications from the PMD 3, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
typedef struct NFC_TNL_PMD_3_Message NFC_TNL_PMD_3_Message_t;

/**
   This data structure defines an EOC transmit message type, and is used in the
   following EOC messages
*/
typedef struct EOC_TransmitMsg EOC_TransmitMsg_t;

/**
   This data structure defines an EOC received message type, and is used in the
   following EOC messages
*/
typedef struct EOC_ReceiveMsg EOC_ReceiveMsg_t;

/** Message ID for CMD_EOC_Message */
#define CMD_EOC_MESSAGE 0x190

/**
   This message is used to transport EOC requests and responses to a remote unit on a
   given link, for details of the EOC requests and responses refer to the ITU-T G.991.2
   standard.
*/
typedef struct CMD_EOC_Message CMD_EOC_Message_t;

/** Message ID for ACK_EOC_Message */
#define ACK_EOC_MESSAGE 0x390

/** Message ID for NFC_EOC_Message */
#define NFC_EOC_MESSAGE 0x590

/**
   This message indicates that all EOC messages produced by a CMD_EOC_Message have been
   transmitted.
*/
typedef struct NFC_EOC_Message NFC_EOC_Message_t;

/** Message ID for EVT_EOC_Message */
#define EVT_EOC_MESSAGE 0x689

/**
   This event is generated (only when an Host is connected) each time an EOC request or
   response was received by the internal EOC handler and cannot be processed, while the
   EOC handler is in transparent mode or while the EOC Id is not supported.
*/
typedef struct EVT_EOC_Message EVT_EOC_Message_t;

/** Message ID for DBG_EOC_EchoMessage */
#define DBG_EOC_ECHOMESSAGE 0x700

/**
   This event is generated when the EOC message echo is switched on.
*/
typedef struct DBG_EOC_EchoMessage DBG_EOC_EchoMessage_t;

/** Message ID for EVT_EOC_LinkState */
#define EVT_EOC_LINKSTATE 0x688

/**
   This event indicates the EOC channel state for a given link. This Event will be sent
   each the EOC changes it state.
*/
typedef struct EVT_EOC_LinkState EVT_EOC_LinkState_t;

/** Message ID for ALM_EOC_MessagesLost */
#define ALM_EOC_MESSAGESLOST 0x607

/**
   
*/
struct IDC_MessageHeader
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Optional message parameter length 0 - 31 words. */
   IFX_uint32_t LENGTH : 5;
   /** Message identifier see */
   IFX_uint32_t MSGID : 11;
   /** Transaction Code Identifier */
   IFX_uint32_t TCID : 11;
   /** Return Code - only relevant for ACK and NFC messages. */
   IFX_uint32_t RC : 4;
   /** Must be set to zero by the host. */
   IFX_uint32_t pad : 1;
#else
   /** Must be set to zero by the host. */
   IFX_uint32_t pad : 1;
   /** Return Code - only relevant for ACK and NFC messages. */
   IFX_uint32_t RC : 4;
   /** Transaction Code Identifier */
   IFX_uint32_t TCID : 11;
   /** Message identifier see */
   IFX_uint32_t MSGID : 11;
   /** Optional message parameter length 0 - 31 words. */
   IFX_uint32_t LENGTH : 5;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_TC_FlowModify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link 0 TC Type select */
   IFX_uint32_t Link0_TC : 8;
   /** DSL Link 1 TC Type select */
   IFX_uint32_t Link1_TC : 8;
   /** DSL Link 2 TC Type select */
   IFX_uint32_t Link2_TC : 8;
   /** DSL Link 3 TC Type select */
   IFX_uint32_t Link3_TC : 8;
#else
   /** DSL Link 3 TC Type select */
   IFX_uint32_t Link3_TC : 8;
   /** DSL Link 2 TC Type select */
   IFX_uint32_t Link2_TC : 8;
   /** DSL Link 1 TC Type select */
   IFX_uint32_t Link1_TC : 8;
   /** DSL Link 0 TC Type select */
   IFX_uint32_t Link0_TC : 8;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_TC_FlowModify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link 0 used TC Layer */
   IFX_uint32_t Link0_TC : 8;
   /** DSL Link 1 used TC Layer */
   IFX_uint32_t Link1_TC : 8;
   /** DSL Link 2 used TC Layer */
   IFX_uint32_t Link2_TC : 8;
   /** DSL Link 3 used TC layer */
   IFX_uint32_t Link3_TC : 8;
#else
   /** DSL Link 3 used TC layer */
   IFX_uint32_t Link3_TC : 8;
   /** DSL Link 2 used TC Layer */
   IFX_uint32_t Link2_TC : 8;
   /** DSL Link 1 used TC Layer */
   IFX_uint32_t Link1_TC : 8;
   /** DSL Link 0 used TC Layer */
   IFX_uint32_t Link0_TC : 8;
#endif
} __PACKED__ ;


/**
   This command enables/disables the usage of the status group pins STA_3..0 and
   PS_3..0.
*/
struct CMD_StatusPinsConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Status Pins Mode Selection */
   IFX_uint32_t Mode;
#else
   /** Status Pins Mode Selection */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This command configures the vendor information for the device.
*/
struct CMD_VendorInformationConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SHDSL Version */
   IFX_uint32_t SHDSL_Version;
   /** Vendor List */
   IFX_uint32_t VendorList;
   /** Vendor Issue */
   IFX_uint32_t VendorIssue;
   /** Vendor SW Version */
   IFX_uint32_t VendorSWVersion[2];
   /** UIC */
   IFX_uint32_t UIC[3];
   /** Vendor ID */
   IFX_uint32_t VendorID[2];
   /** Vendor Model */
   IFX_uint32_t VendorModel[3];
   /** Vendor Serial */
   IFX_uint32_t VendorSerial[3];
   /** Vendor Specific */
   IFX_uint32_t VendorSpecific[3];
   /** Power Source */
   IFX_uint32_t PowerSource;
#else
   /** SHDSL Version */
   IFX_uint32_t SHDSL_Version;
   /** Vendor List */
   IFX_uint32_t VendorList;
   /** Vendor Issue */
   IFX_uint32_t VendorIssue;
   /** Vendor SW Version */
   IFX_uint32_t VendorSWVersion[2];
   /** UIC */
   IFX_uint32_t UIC[3];
   /** Vendor ID */
   IFX_uint32_t VendorID[2];
   /** Vendor Model */
   IFX_uint32_t VendorModel[3];
   /** Vendor Serial */
   IFX_uint32_t VendorSerial[3];
   /** Vendor Specific */
   IFX_uint32_t VendorSpecific[3];
   /** Power Source */
   IFX_uint32_t PowerSource;
#endif
} __PACKED__ ;


/**
   This data structure defines the vendor specific octets for G.Hs. This is needed for
   interoperability against specific non-Infineon implementations which reject data
   mode in case of  values 00 00, that the Socrates-4e sends by default.
*/
struct VendorSpecOctets
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Not Used */
   IFX_uint32_t NotUsed : 8;
   /** Overwrite Vendor Specific Octets */
   IFX_uint32_t Overwrite : 8;
   /** Vendor Specific Octet 1 */
   IFX_uint32_t VendorSpecOctet1 : 8;
   /** Vendor Specific Octet 2 */
   IFX_uint32_t VendorSpecOctet2 : 8;
#else
   /** Vendor Specific Octet 2 */
   IFX_uint32_t VendorSpecOctet2 : 8;
   /** Vendor Specific Octet 1 */
   IFX_uint32_t VendorSpecOctet1 : 8;
   /** Overwrite Vendor Specific Octets */
   IFX_uint32_t Overwrite : 8;
   /** Not Used */
   IFX_uint32_t NotUsed : 8;
#endif
} __PACKED__ ;


/**
   This command configures the vendor information for the device and allows interop
   modes to be selected.
*/
struct CMD_IOP_Mode
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** PMMS Interop Mode */
   IFX_uint32_t pmms_iop_mode;
   /** Vendor Specific Octet */
   IFX_uint32_t vendor_spec_octets;
   /** PHY Interop Mode Select */
   IFX_uint32_t PHY_IOP_Mode;
   /** PHY Reserved For Future Usage */
   IFX_uint32_t PHY_Res_1;
   /** IDC Interop Mode Select */
   IFX_uint32_t IDC_IOP_Mode;
   /** IDC Reserved For Future Usage */
   IFX_uint32_t IDC_Res_1;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** PMMS Interop Mode */
   IFX_uint32_t pmms_iop_mode;
   /** Vendor Specific Octet */
   IFX_uint32_t vendor_spec_octets;
   /** PHY Interop Mode Select */
   IFX_uint32_t PHY_IOP_Mode;
   /** PHY Reserved For Future Usage */
   IFX_uint32_t PHY_Res_1;
   /** IDC Interop Mode Select */
   IFX_uint32_t IDC_IOP_Mode;
   /** IDC Reserved For Future Usage */
   IFX_uint32_t IDC_Res_1;
#endif
} __PACKED__ ;


/**
   This command configures the IDC resource level indications.
*/
struct CMD_ResourceLevelConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Critical Level Indication */
   IFX_uint32_t CriticalLevel;
   /** Remove Critical Leval Alarm Threshold */
   IFX_uint32_t RemoveThresh;
#else
   /** Critical Level Indication */
   IFX_uint32_t CriticalLevel;
   /** Remove Critical Leval Alarm Threshold */
   IFX_uint32_t RemoveThresh;
#endif
} __PACKED__ ;


/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_Mdio_EfmPhy and ACK_Mdio_EfmPhy.
*/
struct MdioFrame45
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Start of Frame */
   IFX_uint32_t ST : 2;
   /** Operation Code */
   IFX_uint32_t OP : 2;
   /** Port Address */
   IFX_uint32_t PRTAD : 5;
   /** Device Address */
   IFX_uint32_t DEVAD : 5;
   /** Turn-Around Bits */
   IFX_uint32_t TA : 2;
   /** Data Field */
   IFX_uint32_t DATA : 16;
#else
   /** Data Field */
   IFX_uint32_t DATA : 16;
   /** Turn-Around Bits */
   IFX_uint32_t TA : 2;
   /** Device Address */
   IFX_uint32_t DEVAD : 5;
   /** Port Address */
   IFX_uint32_t PRTAD : 5;
   /** Operation Code */
   IFX_uint32_t OP : 2;
   /** Start of Frame */
   IFX_uint32_t ST : 2;
#endif
} __PACKED__ ;


/**
   This data structure defines a MDIO frame as used in the host messages
   CMD_Mdio_ExtPhy and ACK_Mdio_ExtPhy.
*/
struct MdioFrame22
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Start of frame */
   IFX_uint32_t ST : 2;
   /** Operation code */
   IFX_uint32_t OP : 2;
   /** PHY Address */
   IFX_uint32_t PHYAD : 5;
   /** Register Address */
   IFX_uint32_t REGAD : 5;
   /** Turn-around bits */
   IFX_uint32_t TA : 2;
   /** Data field */
   IFX_uint32_t DATA : 16;
#else
   /** Data field */
   IFX_uint32_t DATA : 16;
   /** Turn-around bits */
   IFX_uint32_t TA : 2;
   /** Register Address */
   IFX_uint32_t REGAD : 5;
   /** PHY Address */
   IFX_uint32_t PHYAD : 5;
   /** Operation code */
   IFX_uint32_t OP : 2;
   /** Start of frame */
   IFX_uint32_t ST : 2;
#endif
} __PACKED__ ;


/**
   This message is used to send a batch of up to 31 MDIO register accesses, see Clause
   45 MDIO Register Access for MDIO register access.
*/
struct CMD_Mdio_EfmPhy
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** See MdioFrame45_t. */
   IFX_uint32_t Cmd_00;
   /**  */
   IFX_uint32_t Cmd_01;
   /**  */
   IFX_uint32_t Cmd_02;
   /**  */
   IFX_uint32_t Cmd_03;
   /**  */
   IFX_uint32_t Cmd_04;
   /**  */
   IFX_uint32_t Cmd_05;
   /**  */
   IFX_uint32_t Cmd_06;
   /**  */
   IFX_uint32_t Cmd_07;
   /**  */
   IFX_uint32_t Cmd_08;
   /**  */
   IFX_uint32_t Cmd_09;
   /**  */
   IFX_uint32_t Cmd_10;
   /**  */
   IFX_uint32_t Cmd_11;
   /**  */
   IFX_uint32_t Cmd_12;
   /**  */
   IFX_uint32_t Cmd_13;
   /**  */
   IFX_uint32_t Cmd_14;
   /**  */
   IFX_uint32_t Cmd_15;
   /**  */
   IFX_uint32_t Cmd_16;
   /**  */
   IFX_uint32_t Cmd_17;
   /**  */
   IFX_uint32_t Cmd_18;
   /**  */
   IFX_uint32_t Cmd_19;
   /**  */
   IFX_uint32_t Cmd_20;
   /**  */
   IFX_uint32_t Cmd_21;
   /**  */
   IFX_uint32_t Cmd_22;
   /**  */
   IFX_uint32_t Cmd_23;
   /**  */
   IFX_uint32_t Cmd_24;
   /**  */
   IFX_uint32_t Cmd_25;
   /**  */
   IFX_uint32_t Cmd_26;
   /**  */
   IFX_uint32_t Cmd_27;
   /**  */
   IFX_uint32_t Cmd_28;
   /**  */
   IFX_uint32_t Cmd_29;
   /**  */
   IFX_uint32_t Cmd_30;
#else
   /** See MdioFrame45_t. */
   IFX_uint32_t Cmd_00;
   /**  */
   IFX_uint32_t Cmd_01;
   /**  */
   IFX_uint32_t Cmd_02;
   /**  */
   IFX_uint32_t Cmd_03;
   /**  */
   IFX_uint32_t Cmd_04;
   /**  */
   IFX_uint32_t Cmd_05;
   /**  */
   IFX_uint32_t Cmd_06;
   /**  */
   IFX_uint32_t Cmd_07;
   /**  */
   IFX_uint32_t Cmd_08;
   /**  */
   IFX_uint32_t Cmd_09;
   /**  */
   IFX_uint32_t Cmd_10;
   /**  */
   IFX_uint32_t Cmd_11;
   /**  */
   IFX_uint32_t Cmd_12;
   /**  */
   IFX_uint32_t Cmd_13;
   /**  */
   IFX_uint32_t Cmd_14;
   /**  */
   IFX_uint32_t Cmd_15;
   /**  */
   IFX_uint32_t Cmd_16;
   /**  */
   IFX_uint32_t Cmd_17;
   /**  */
   IFX_uint32_t Cmd_18;
   /**  */
   IFX_uint32_t Cmd_19;
   /**  */
   IFX_uint32_t Cmd_20;
   /**  */
   IFX_uint32_t Cmd_21;
   /**  */
   IFX_uint32_t Cmd_22;
   /**  */
   IFX_uint32_t Cmd_23;
   /**  */
   IFX_uint32_t Cmd_24;
   /**  */
   IFX_uint32_t Cmd_25;
   /**  */
   IFX_uint32_t Cmd_26;
   /**  */
   IFX_uint32_t Cmd_27;
   /**  */
   IFX_uint32_t Cmd_28;
   /**  */
   IFX_uint32_t Cmd_29;
   /**  */
   IFX_uint32_t Cmd_30;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Mdio_EfmPhy
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** See MdioFrame45_t. */
   IFX_uint32_t Cmd_00;
   /**  */
   IFX_uint32_t Cmd_01;
   /**  */
   IFX_uint32_t Cmd_02;
   /**  */
   IFX_uint32_t Cmd_03;
   /**  */
   IFX_uint32_t Cmd_04;
   /**  */
   IFX_uint32_t Cmd_05;
   /**  */
   IFX_uint32_t Cmd_06;
   /**  */
   IFX_uint32_t Cmd_07;
   /**  */
   IFX_uint32_t Cmd_08;
   /**  */
   IFX_uint32_t Cmd_09;
   /**  */
   IFX_uint32_t Cmd_10;
   /**  */
   IFX_uint32_t Cmd_11;
   /**  */
   IFX_uint32_t Cmd_12;
   /**  */
   IFX_uint32_t Cmd_13;
   /**  */
   IFX_uint32_t Cmd_14;
   /**  */
   IFX_uint32_t Cmd_15;
   /**  */
   IFX_uint32_t Cmd_16;
   /**  */
   IFX_uint32_t Cmd_17;
   /**  */
   IFX_uint32_t Cmd_18;
   /**  */
   IFX_uint32_t Cmd_19;
   /**  */
   IFX_uint32_t Cmd_20;
   /**  */
   IFX_uint32_t Cmd_21;
   /**  */
   IFX_uint32_t Cmd_22;
   /**  */
   IFX_uint32_t Cmd_23;
   /**  */
   IFX_uint32_t Cmd_24;
   /**  */
   IFX_uint32_t Cmd_25;
   /**  */
   IFX_uint32_t Cmd_26;
   /**  */
   IFX_uint32_t Cmd_27;
   /**  */
   IFX_uint32_t Cmd_28;
   /**  */
   IFX_uint32_t Cmd_29;
   /**  */
   IFX_uint32_t Cmd_30;
#else
   /** See MdioFrame45_t. */
   IFX_uint32_t Cmd_00;
   /**  */
   IFX_uint32_t Cmd_01;
   /**  */
   IFX_uint32_t Cmd_02;
   /**  */
   IFX_uint32_t Cmd_03;
   /**  */
   IFX_uint32_t Cmd_04;
   /**  */
   IFX_uint32_t Cmd_05;
   /**  */
   IFX_uint32_t Cmd_06;
   /**  */
   IFX_uint32_t Cmd_07;
   /**  */
   IFX_uint32_t Cmd_08;
   /**  */
   IFX_uint32_t Cmd_09;
   /**  */
   IFX_uint32_t Cmd_10;
   /**  */
   IFX_uint32_t Cmd_11;
   /**  */
   IFX_uint32_t Cmd_12;
   /**  */
   IFX_uint32_t Cmd_13;
   /**  */
   IFX_uint32_t Cmd_14;
   /**  */
   IFX_uint32_t Cmd_15;
   /**  */
   IFX_uint32_t Cmd_16;
   /**  */
   IFX_uint32_t Cmd_17;
   /**  */
   IFX_uint32_t Cmd_18;
   /**  */
   IFX_uint32_t Cmd_19;
   /**  */
   IFX_uint32_t Cmd_20;
   /**  */
   IFX_uint32_t Cmd_21;
   /**  */
   IFX_uint32_t Cmd_22;
   /**  */
   IFX_uint32_t Cmd_23;
   /**  */
   IFX_uint32_t Cmd_24;
   /**  */
   IFX_uint32_t Cmd_25;
   /**  */
   IFX_uint32_t Cmd_26;
   /**  */
   IFX_uint32_t Cmd_27;
   /**  */
   IFX_uint32_t Cmd_28;
   /**  */
   IFX_uint32_t Cmd_29;
   /**  */
   IFX_uint32_t Cmd_30;
#endif
} __PACKED__ ;


/**
   This command performs 2 MDIO operations, 1st an ADDRESS operation is performed by
   setting the specified MMD ADDRESS, and 2nd the register contents is read from the
   set ADDRESS, if the register address is invalid then 0 will be returned.
*/
struct CMD_Mdio_RegisterRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Port Address */
   IFX_uint32_t PRTAD;
   /** Device Address */
   IFX_uint32_t DEVAD;
   /** Register Address */
   IFX_uint32_t Address;
#else
   /** Port Address */
   IFX_uint32_t PRTAD;
   /** Device Address */
   IFX_uint32_t DEVAD;
   /** Register Address */
   IFX_uint32_t Address;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Mdio_RegisterRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register Value */
   IFX_uint32_t RegValue;
#else
   /** Register Value */
   IFX_uint32_t RegValue;
#endif
} __PACKED__ ;


/**
   This command performs 2 MDIO operations, 1st an ADDRESS operation is performed by
   setting the specified MMD ADDRESS, and 2nd the register contents is overwritten at
   the set ADDRESS, if the register address is invalid or the register is read only
   then no action will be performed.
*/
struct CMD_Mdio_RegisterWrite
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Port Address */
   IFX_uint32_t PRTAD;
   /** Device Address */
   IFX_uint32_t DEVAD;
   /** Register Address */
   IFX_uint32_t Address;
   /** Register Value */
   IFX_uint32_t Value;
#else
   /** Port Address */
   IFX_uint32_t PRTAD;
   /** Device Address */
   IFX_uint32_t DEVAD;
   /** Register Address */
   IFX_uint32_t Address;
   /** Register Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This command performs several MDIO operations, 1st an ADDRESS operation is performed
   by setting the specified MMD ADDRESS, and 2nd the register contents is read from the
   set ADDRESS and the ADDRESS is incremented (Post Read Increment Operation), the read
   operation will be performed for the requested number of reads, if the register
   address is invalid then 0 will be returned.
*/
struct CMD_Mdio_RegisterMultipleRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Port Address */
   IFX_uint32_t PRTAD;
   /** Device Address */
   IFX_uint32_t DEVAD;
   /** Register Address */
   IFX_uint32_t Address;
   /** Register Count to be Read */
   IFX_uint32_t Count;
#else
   /** Port Address */
   IFX_uint32_t PRTAD;
   /** Device Address */
   IFX_uint32_t DEVAD;
   /** Register Address */
   IFX_uint32_t Address;
   /** Register Count to be Read */
   IFX_uint32_t Count;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Mdio_RegisterMultipleRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /**  */
   IFX_uint32_t Reg_00;
   /**  */
   IFX_uint32_t Reg_01;
   /**  */
   IFX_uint32_t Reg_02;
   /**  */
   IFX_uint32_t Reg_03;
   /**  */
   IFX_uint32_t Reg_04;
   /**  */
   IFX_uint32_t Reg_05;
   /**  */
   IFX_uint32_t Reg_06;
   /**  */
   IFX_uint32_t Reg_07;
   /**  */
   IFX_uint32_t Reg_08;
   /**  */
   IFX_uint32_t Reg_09;
   /**  */
   IFX_uint32_t Reg_10;
   /**  */
   IFX_uint32_t Reg_11;
   /**  */
   IFX_uint32_t Reg_12;
   /**  */
   IFX_uint32_t Reg_13;
   /**  */
   IFX_uint32_t Reg_14;
   /**  */
   IFX_uint32_t Reg_15;
   /**  */
   IFX_uint32_t Reg_16;
   /**  */
   IFX_uint32_t Reg_17;
   /**  */
   IFX_uint32_t Reg_18;
   /**  */
   IFX_uint32_t Reg_19;
   /**  */
   IFX_uint32_t Reg_20;
   /**  */
   IFX_uint32_t Reg_21;
   /**  */
   IFX_uint32_t Reg_22;
   /**  */
   IFX_uint32_t Reg_23;
   /**  */
   IFX_uint32_t Reg_24;
   /**  */
   IFX_uint32_t Reg_25;
   /**  */
   IFX_uint32_t Reg_26;
   /**  */
   IFX_uint32_t Reg_27;
   /**  */
   IFX_uint32_t Reg_28;
   /**  */
   IFX_uint32_t Reg_29;
   /**  */
   IFX_uint32_t Reg_30;
#else
   /**  */
   IFX_uint32_t Reg_00;
   /**  */
   IFX_uint32_t Reg_01;
   /**  */
   IFX_uint32_t Reg_02;
   /**  */
   IFX_uint32_t Reg_03;
   /**  */
   IFX_uint32_t Reg_04;
   /**  */
   IFX_uint32_t Reg_05;
   /**  */
   IFX_uint32_t Reg_06;
   /**  */
   IFX_uint32_t Reg_07;
   /**  */
   IFX_uint32_t Reg_08;
   /**  */
   IFX_uint32_t Reg_09;
   /**  */
   IFX_uint32_t Reg_10;
   /**  */
   IFX_uint32_t Reg_11;
   /**  */
   IFX_uint32_t Reg_12;
   /**  */
   IFX_uint32_t Reg_13;
   /**  */
   IFX_uint32_t Reg_14;
   /**  */
   IFX_uint32_t Reg_15;
   /**  */
   IFX_uint32_t Reg_16;
   /**  */
   IFX_uint32_t Reg_17;
   /**  */
   IFX_uint32_t Reg_18;
   /**  */
   IFX_uint32_t Reg_19;
   /**  */
   IFX_uint32_t Reg_20;
   /**  */
   IFX_uint32_t Reg_21;
   /**  */
   IFX_uint32_t Reg_22;
   /**  */
   IFX_uint32_t Reg_23;
   /**  */
   IFX_uint32_t Reg_24;
   /**  */
   IFX_uint32_t Reg_25;
   /**  */
   IFX_uint32_t Reg_26;
   /**  */
   IFX_uint32_t Reg_27;
   /**  */
   IFX_uint32_t Reg_28;
   /**  */
   IFX_uint32_t Reg_29;
   /**  */
   IFX_uint32_t Reg_30;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Mdio_ExtPhy
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** See MdioFrame22_t. */
   IFX_uint32_t Value[31];
#else
   /** See MdioFrame22_t. */
   IFX_uint32_t Value[31];
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Mdio_ExtPhy
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** See MdioFrame22_t. */
   IFX_uint32_t Value[31];
#else
   /** See MdioFrame22_t. */
   IFX_uint32_t Value[31];
#endif
} __PACKED__ ;


/**
   This command is used to modify the default settings of the UTOPIA interface.
*/
struct CMD_UTOPIA_L2_Modify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** UDF2 Byte */
   IFX_uint32_t UDF2_byte;
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Cell Discard if Parity Error */
   IFX_uint32_t CPDE;
   /** Utopia Port Numbers */
   IFX_uint32_t PortNos;
#else
   /** UDF2 Byte */
   IFX_uint32_t UDF2_byte;
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Cell Discard if Parity Error */
   IFX_uint32_t CPDE;
   /** Utopia Port Numbers */
   IFX_uint32_t PortNos;
#endif
} __PACKED__ ;


/**
   This command is used to modify the default settings of the POS-PHY interface.
*/
struct CMD_POSPHY_L2_Modify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Packet error Marking if Parity Error */
   IFX_uint32_t PMPE;
   /** Burst Transfer Size */
   IFX_uint32_t ChunkSize;
   /** Packet Available Deassertion Fill Level */
   IFX_uint32_t PADFL;
   /** POS-PHY bus Frequency */
   IFX_uint32_t Frequency;
   /** POS-PHY Port Numbers */
   IFX_uint32_t PortNos;
#else
   /** Parity Mode */
   IFX_uint32_t ParityMode;
   /** Packet error Marking if Parity Error */
   IFX_uint32_t PMPE;
   /** Burst Transfer Size */
   IFX_uint32_t ChunkSize;
   /** Packet Available Deassertion Fill Level */
   IFX_uint32_t PADFL;
   /** POS-PHY bus Frequency */
   IFX_uint32_t Frequency;
   /** POS-PHY Port Numbers */
   IFX_uint32_t PortNos;
#endif
} __PACKED__ ;


/**
   This command is used to modify the default settings of the xMII interface per link.
*/
struct CMD_xMII_Modify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Interface Speed */
   IFX_uint32_t Speed;
   /** Interface Duplex Mode */
   IFX_uint32_t Duplex;
   /** SMII Sync Mode */
   IFX_uint32_t SMII_SyncMode;
   /** Alternative Collision */
   IFX_uint32_t AltCollision;
   /** MII Receive During Transmit */
   IFX_uint32_t RxDuringTx;
   /** Collision Type */
   IFX_uint32_t CollisionType;
   /** Di-Bit Mode */
   IFX_uint32_t DiBitMode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Interface Speed */
   IFX_uint32_t Speed;
   /** Interface Duplex Mode */
   IFX_uint32_t Duplex;
   /** SMII Sync Mode */
   IFX_uint32_t SMII_SyncMode;
   /** Alternative Collision */
   IFX_uint32_t AltCollision;
   /** MII Receive During Transmit */
   IFX_uint32_t RxDuringTx;
   /** Collision Type */
   IFX_uint32_t CollisionType;
   /** Di-Bit Mode */
   IFX_uint32_t DiBitMode;
#endif
} __PACKED__ ;


/**
   This command configures the MAC address for the device and the maximum supported
   Ethernet frame size and support of external Ethernet OAM for the links.
*/
struct CMD_MAC_Config
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** MAC Address Octets 0 - 3 */
   IFX_uint32_t MacAddr_0_3;
   /** MAC Address Octets 4- 5 */
   IFX_uint32_t MacAddr_4_5;
   /** Max Frame Size Link 0 */
   IFX_uint32_t MaxFrameSize_0;
   /** Max Frame Size Link 1 */
   IFX_uint32_t MaxFrameSize_1;
   /** Max Frame Size Link 2 */
   IFX_uint32_t MaxFrameSize_2;
   /** Max Frame Size Link 3 */
   IFX_uint32_t MaxFrameSize_3;
   /** Support of external Ethernet OAM */
   IFX_uint32_t ExtEthernetOAM;
   /** Configuration of Pause frame rate */
   IFX_uint32_t PauseCfg;
#else
   /** MAC Address Octets 0 - 3 */
   IFX_uint32_t MacAddr_0_3;
   /** MAC Address Octets 4- 5 */
   IFX_uint32_t MacAddr_4_5;
   /** Max Frame Size Link 0 */
   IFX_uint32_t MaxFrameSize_0;
   /** Max Frame Size Link 1 */
   IFX_uint32_t MaxFrameSize_1;
   /** Max Frame Size Link 2 */
   IFX_uint32_t MaxFrameSize_2;
   /** Max Frame Size Link 3 */
   IFX_uint32_t MaxFrameSize_3;
   /** Support of external Ethernet OAM */
   IFX_uint32_t ExtEthernetOAM;
   /** Configuration of Pause frame rate */
   IFX_uint32_t PauseCfg;
#endif
} __PACKED__ ;


/**
   This command configures the MAC functionality for a link.
*/
struct CMD_MAC_LinkConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t SystemCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t System_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t SystemRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t SystemAdd;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t LineCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t Line_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t LineRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t LineAdd;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t SystemCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t System_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t SystemRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t SystemAdd;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t LineCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t Line_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t LineRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t LineAdd;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_TDM_SystemInterfaceConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** TDM System Interface Frequency */
   IFX_uint32_t Frequency;
   /** Receive Sync Pulse Driving Edge */
   IFX_uint32_t RX_SP_DrvEdge;
   /** Receive Data Driving Edge */
   IFX_uint32_t RX_DataDrvEdge;
   /** Polarity */
   IFX_uint32_t Polarity;
   /** Interface Mode */
   IFX_uint32_t InterfaceMode;
   /** Interleaving Mode */
   IFX_uint32_t InterleavingMode;
   /** Interleaving Channel Count */
   IFX_uint32_t IL_ChannelCnt;
   /** Interleaving Channel Selection */
   IFX_uint32_t IL_Channel;
   /** Payload Data Shift */
   IFX_uint32_t PayloadShift;
   /** FSC Alignment */
   IFX_uint32_t FSC_Alignment;
   /** Transmit Sync Pulse Sampling Edge */
   IFX_uint32_t TX_SP_SmpEdge;
   /** Transmit Data Sampling Edge */
   IFX_uint32_t TX_DataSmpEdge;
#else
   /** TDM System Interface Frequency */
   IFX_uint32_t Frequency;
   /** Receive Sync Pulse Driving Edge */
   IFX_uint32_t RX_SP_DrvEdge;
   /** Receive Data Driving Edge */
   IFX_uint32_t RX_DataDrvEdge;
   /** Polarity */
   IFX_uint32_t Polarity;
   /** Interface Mode */
   IFX_uint32_t InterfaceMode;
   /** Interleaving Mode */
   IFX_uint32_t InterleavingMode;
   /** Interleaving Channel Count */
   IFX_uint32_t IL_ChannelCnt;
   /** Interleaving Channel Selection */
   IFX_uint32_t IL_Channel;
   /** Payload Data Shift */
   IFX_uint32_t PayloadShift;
   /** FSC Alignment */
   IFX_uint32_t FSC_Alignment;
   /** Transmit Sync Pulse Sampling Edge */
   IFX_uint32_t TX_SP_SmpEdge;
   /** Transmit Data Sampling Edge */
   IFX_uint32_t TX_DataSmpEdge;
#endif
} __PACKED__ ;


/**
   This command is used to configure virtual TDM ports at the line interface when
   configuring TDM applications
*/
struct CMD_TDM_VirtualPortConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Interleaving Mode */
   IFX_uint32_t InterleavingMode;
   /** TDM Mode */
   IFX_uint32_t Mode;
   /** SDI Line frequency */
   IFX_uint32_t LineFrequency;
   /** FSC Alignment */
   IFX_uint32_t FSC_Alignment;
   /** Virtual Port 0 Max TDM Payload */
   IFX_uint32_t VP0_MaxPayload;
   /** Virtual Port 0 Used Payload */
   IFX_uint32_t VP0_UsedPayload;
   /** Virtual Port 0 Mpair Map */
   IFX_uint32_t VP0_MpairMap;
   /** Virtual Port 0 Z bits Alignment */
   IFX_uint32_t VP0_Zbits;
   /** Virtual Port 0 Reserved For Future Use */
   IFX_uint32_t VP0_Res2;
   /** Virtual Port 0 Reserved For Future Use */
   IFX_uint32_t VP0_Res3;
   /** Virtual Port 1 Max TDM Payload */
   IFX_uint32_t VP1_MaxPayload;
   /** Virtual Port 1 Used Payload */
   IFX_uint32_t VP1_UsedPayload;
   /** Virtual Port 1 Mpair Map */
   IFX_uint32_t VP1_MpairMap;
   /** Virtual Port 1 Z bits Alignment */
   IFX_uint32_t VP1_Zbits;
   /** Virtual Port 1 Reserved For Future Use */
   IFX_uint32_t VP1_Res2;
   /** Virtual Port 1 Reserved For Future Use */
   IFX_uint32_t VP1_Res3;
   /** Virtual Port 2 Max TDM Payload */
   IFX_uint32_t VP2_MaxPayload;
   /** Virtual Port 2 Used Payload */
   IFX_uint32_t VP2_UsedPayload;
   /** Virtual Port 2 Mpair Map */
   IFX_uint32_t VP2_MpairMap;
   /** Virtual Port 2 Z bits Alignment */
   IFX_uint32_t VP2_Zbits;
   /** Virtual Port 2 Reserved For Future Use */
   IFX_uint32_t VP2_Res2;
   /** Virtual Port 2 Reserved For Future Use */
   IFX_uint32_t VP2_Res3;
   /** Virtual Port 3 Max TDM Payload */
   IFX_uint32_t VP3_MaxPayload;
   /** Virtual Port 3 Used Payload */
   IFX_uint32_t VP3_UsedPayload;
   /** Virtual Port 3 Mpair Map */
   IFX_uint32_t VP3_MpairMap;
   /** Virtual Port 3 Z bits Alignment */
   IFX_uint32_t VP3_Zbits;
   /** Virtual Port 3 Reserved For Future Use */
   IFX_uint32_t VP3_Res2;
   /** Virtual Port 3 Reserved For Future Use */
   IFX_uint32_t VP3_Res3;
#else
   /** Interleaving Mode */
   IFX_uint32_t InterleavingMode;
   /** TDM Mode */
   IFX_uint32_t Mode;
   /** SDI Line frequency */
   IFX_uint32_t LineFrequency;
   /** FSC Alignment */
   IFX_uint32_t FSC_Alignment;
   /** Virtual Port 0 Max TDM Payload */
   IFX_uint32_t VP0_MaxPayload;
   /** Virtual Port 0 Used Payload */
   IFX_uint32_t VP0_UsedPayload;
   /** Virtual Port 0 Mpair Map */
   IFX_uint32_t VP0_MpairMap;
   /** Virtual Port 0 Z bits Alignment */
   IFX_uint32_t VP0_Zbits;
   /** Virtual Port 0 Reserved For Future Use */
   IFX_uint32_t VP0_Res2;
   /** Virtual Port 0 Reserved For Future Use */
   IFX_uint32_t VP0_Res3;
   /** Virtual Port 1 Max TDM Payload */
   IFX_uint32_t VP1_MaxPayload;
   /** Virtual Port 1 Used Payload */
   IFX_uint32_t VP1_UsedPayload;
   /** Virtual Port 1 Mpair Map */
   IFX_uint32_t VP1_MpairMap;
   /** Virtual Port 1 Z bits Alignment */
   IFX_uint32_t VP1_Zbits;
   /** Virtual Port 1 Reserved For Future Use */
   IFX_uint32_t VP1_Res2;
   /** Virtual Port 1 Reserved For Future Use */
   IFX_uint32_t VP1_Res3;
   /** Virtual Port 2 Max TDM Payload */
   IFX_uint32_t VP2_MaxPayload;
   /** Virtual Port 2 Used Payload */
   IFX_uint32_t VP2_UsedPayload;
   /** Virtual Port 2 Mpair Map */
   IFX_uint32_t VP2_MpairMap;
   /** Virtual Port 2 Z bits Alignment */
   IFX_uint32_t VP2_Zbits;
   /** Virtual Port 2 Reserved For Future Use */
   IFX_uint32_t VP2_Res2;
   /** Virtual Port 2 Reserved For Future Use */
   IFX_uint32_t VP2_Res3;
   /** Virtual Port 3 Max TDM Payload */
   IFX_uint32_t VP3_MaxPayload;
   /** Virtual Port 3 Used Payload */
   IFX_uint32_t VP3_UsedPayload;
   /** Virtual Port 3 Mpair Map */
   IFX_uint32_t VP3_MpairMap;
   /** Virtual Port 3 Z bits Alignment */
   IFX_uint32_t VP3_Zbits;
   /** Virtual Port 3 Reserved For Future Use */
   IFX_uint32_t VP3_Res2;
   /** Virtual Port 3 Reserved For Future Use */
   IFX_uint32_t VP3_Res3;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_Settings
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Clock mode for SDI input */
   IFX_uint32_t input_mode;
   /** Clock mode for SDI output */
   IFX_uint32_t output_mode;
   /** SDI Frequency */
   IFX_uint32_t frequency;
   /** Payload Bit Rate in kbits per second */
   IFX_uint32_t payload_bits;
   /** Frames per multiframe */
   IFX_uint32_t frames;
   /** Loop Selection */
   IFX_uint32_t loop;
   /** DPLL activation */
   IFX_uint32_t dpll4bclk;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Clock mode for SDI input */
   IFX_uint32_t input_mode;
   /** Clock mode for SDI output */
   IFX_uint32_t output_mode;
   /** SDI Frequency */
   IFX_uint32_t frequency;
   /** Payload Bit Rate in kbits per second */
   IFX_uint32_t payload_bits;
   /** Frames per multiframe */
   IFX_uint32_t frames;
   /** Loop Selection */
   IFX_uint32_t loop;
   /** DPLL activation */
   IFX_uint32_t dpll4bclk;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_Tx
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t sp_level;
   /** SP and MSP sampling edge */
   IFX_uint32_t sp_sample_edg;
   /** Data sampling edge */
   IFX_uint32_t data_sample_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t slip_mode;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Data delay independent of payload rate */
   IFX_uint32_t align;
   /** Reserved */
   IFX_uint32_t rsvd3;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t sp_level;
   /** SP and MSP sampling edge */
   IFX_uint32_t sp_sample_edg;
   /** Data sampling edge */
   IFX_uint32_t data_sample_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t slip_mode;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Data delay independent of payload rate */
   IFX_uint32_t align;
   /** Reserved */
   IFX_uint32_t rsvd3;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_Rx
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t sp_level;
   /** Driving edge for DATA, SP and MSP */
   IFX_uint32_t driving_edg;
   /** Data sampling edge */
   IFX_uint32_t data_sample_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t slip_mode;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Data delay independent of payload rate */
   IFX_uint32_t align;
   /** Reserved */
   IFX_uint32_t rsvd3;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t sp_level;
   /** Driving edge for DATA, SP and MSP */
   IFX_uint32_t driving_edg;
   /** Data sampling edge */
   IFX_uint32_t data_sample_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t slip_mode;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Data delay independent of payload rate */
   IFX_uint32_t align;
   /** Reserved */
   IFX_uint32_t rsvd3;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_Dly
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t frame_shift;
   /** Reserved */
   IFX_uint32_t rsvd0;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Reserved */
   IFX_uint32_t rsvd2;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t frame_shift;
   /** Reserved */
   IFX_uint32_t rsvd0;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Reserved */
   IFX_uint32_t rsvd2;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_IlChannelsTx
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Number of interleaving channels */
   IFX_uint32_t il_ch_count;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t active_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t special_mode;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Number of interleaving channels */
   IFX_uint32_t il_ch_count;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t active_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t special_mode;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_IlChannelsRx
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Number of interleaving channels */
   IFX_uint32_t il_ch_count;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t active_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t special_mode;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Number of interleaving channels */
   IFX_uint32_t il_ch_count;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t active_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t special_mode;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_FramerTx
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode0;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode1;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode2;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode3;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode4;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode5;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode6;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode7;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode8;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode9;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode10;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode11;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode12;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode13;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode14;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode15;
   /** Reserved */
   IFX_uint32_t rsvd0;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Reserved */
   IFX_uint32_t rsvd2;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode0;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode1;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode2;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode3;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode4;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode5;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode6;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode7;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode8;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode9;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode10;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode11;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode12;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode13;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode14;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode15;
   /** Reserved */
   IFX_uint32_t rsvd0;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Reserved */
   IFX_uint32_t rsvd2;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_FramerRx
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode0;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode1;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode2;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode3;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode4;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode5;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode6;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode7;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode8;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode9;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode10;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode11;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode12;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode13;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode14;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode15;
   /** Reserved */
   IFX_uint32_t rsvd0;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Reserved */
   IFX_uint32_t rsvd2;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode0;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode1;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode2;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode3;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode4;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode5;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode6;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode7;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode8;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode9;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode10;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode11;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode12;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode13;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode14;
   /** Opcode for SDI framer */
   IFX_uint32_t opcode15;
   /** Reserved */
   IFX_uint32_t rsvd0;
   /** Reserved */
   IFX_uint32_t rsvd1;
   /** Reserved */
   IFX_uint32_t rsvd2;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Dbg_MWM_ConfigGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PAMDSL input connections of link 0 */
   IFX_uint32_t link0in;
   /** PAMDSL output connections of link 0 */
   IFX_uint32_t link0out;
   /** PAMDSL input connections of link 1 */
   IFX_uint32_t link1in;
   /** PAMDSL output connections of link 1 */
   IFX_uint32_t link1out;
   /** PAMDSL input connections of link 2 */
   IFX_uint32_t link2in;
   /** PAMDSL output connections of link 2 */
   IFX_uint32_t link2out;
   /** PAMDSL input connections of link 3 */
   IFX_uint32_t link3in;
   /** PAMDSL output connections of link 3 */
   IFX_uint32_t link3out;
#else
   /** PAMDSL input connections of link 0 */
   IFX_uint32_t link0in;
   /** PAMDSL output connections of link 0 */
   IFX_uint32_t link0out;
   /** PAMDSL input connections of link 1 */
   IFX_uint32_t link1in;
   /** PAMDSL output connections of link 1 */
   IFX_uint32_t link1out;
   /** PAMDSL input connections of link 2 */
   IFX_uint32_t link2in;
   /** PAMDSL output connections of link 2 */
   IFX_uint32_t link2out;
   /** PAMDSL input connections of link 3 */
   IFX_uint32_t link3in;
   /** PAMDSL output connections of link 3 */
   IFX_uint32_t link3out;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_SDI_Loop
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Loop Selection */
   IFX_uint32_t loop;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Loop Selection */
   IFX_uint32_t loop;
#endif
} __PACKED__ ;


/**
   This command is used to modify an HDLC TC flow.
*/
struct CMD_HDLC_TC_LinkModify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Bit or Byte Stuffing */
   IFX_uint32_t BitByte;
   /** Interframe gap Character */
   IFX_uint32_t Interframe_ch;
   /** Shared Flags */
   IFX_uint32_t SharedFlags;
   /** FCS generation and check */
   IFX_uint32_t FCS;
   /** Address and Control Field Insertion */
   IFX_uint32_t ACF_Insert;
   /** Transmit Address and Control field bytes */
   IFX_uint32_t TxAddrCtrl;
   /** Line Interface M Pair Ports */
   IFX_uint32_t LI_M_PairPorts;
   /** Clocking Mode */
   IFX_uint32_t ClockingMode;
   /** Low Latency Low Packet Jitter Mode */
   IFX_uint32_t LowLatency;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Bit or Byte Stuffing */
   IFX_uint32_t BitByte;
   /** Interframe gap Character */
   IFX_uint32_t Interframe_ch;
   /** Shared Flags */
   IFX_uint32_t SharedFlags;
   /** FCS generation and check */
   IFX_uint32_t FCS;
   /** Address and Control Field Insertion */
   IFX_uint32_t ACF_Insert;
   /** Transmit Address and Control field bytes */
   IFX_uint32_t TxAddrCtrl;
   /** Line Interface M Pair Ports */
   IFX_uint32_t LI_M_PairPorts;
   /** Clocking Mode */
   IFX_uint32_t ClockingMode;
   /** Low Latency Low Packet Jitter Mode */
   IFX_uint32_t LowLatency;
#endif
} __PACKED__ ;


/**
   This command is used to modify an ATM-TC flow in the receive and transmit
   directions, the flow can be a single 1:1 flow or an M pair 1:N flow.
*/
struct CMD_ATM_TC_LinkModify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** IMA Mode */
   IFX_uint32_t IMA_Mode;
   /** Receive HEC byte Overwrite */
   IFX_uint32_t RX_HEC_Ow;
   /** Receive HEC byte */
   IFX_uint32_t RX_HEC_Byte;
   /** Cell Delineation Mode */
   IFX_uint32_t CellDelinMode;
   /** Cell Rate Decoupling ATM Cell Header */
   IFX_uint32_t CRD_AtmHdr;
   /** Cell Rate Decoupling ATM cell Payload */
   IFX_uint32_t CRD_AtmPL;
   /** Receive Alpha value */
   IFX_uint32_t RX_Alpha;
   /** Receive Delta value */
   IFX_uint32_t RX_Delta;
   /** Receive payload Descrambling */
   IFX_uint32_t RX_descrambling;
   /** Transmit payload Scrambling */
   IFX_uint32_t TX_scrambling;
   /** Line Interface M-Pair Ports */
   IFX_uint32_t LI_M_PairPorts;
   /** Clocking Mode */
   IFX_uint32_t ClockingMode;
   /** Forward Erroneous Cells in RX Direction */
   IFX_uint32_t RX_Err_Fwd;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** IMA Mode */
   IFX_uint32_t IMA_Mode;
   /** Receive HEC byte Overwrite */
   IFX_uint32_t RX_HEC_Ow;
   /** Receive HEC byte */
   IFX_uint32_t RX_HEC_Byte;
   /** Cell Delineation Mode */
   IFX_uint32_t CellDelinMode;
   /** Cell Rate Decoupling ATM Cell Header */
   IFX_uint32_t CRD_AtmHdr;
   /** Cell Rate Decoupling ATM cell Payload */
   IFX_uint32_t CRD_AtmPL;
   /** Receive Alpha value */
   IFX_uint32_t RX_Alpha;
   /** Receive Delta value */
   IFX_uint32_t RX_Delta;
   /** Receive payload Descrambling */
   IFX_uint32_t RX_descrambling;
   /** Transmit payload Scrambling */
   IFX_uint32_t TX_scrambling;
   /** Line Interface M-Pair Ports */
   IFX_uint32_t LI_M_PairPorts;
   /** Clocking Mode */
   IFX_uint32_t ClockingMode;
   /** Forward Erroneous Cells in RX Direction */
   IFX_uint32_t RX_Err_Fwd;
#endif
} __PACKED__ ;


/**
   This command is used to configure the general settings for the SAR process.
*/
struct CMD_SegmentationReassemblyConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** CPCS Protocol */
   IFX_uint32_t CPCS_Protocol;
   /** FCS Preserved within the PDU */
   IFX_uint32_t FCS_Present;
   /** Segmentation Classification Filter */
   IFX_uint32_t SegClassFilter;
   /** Segmentation Default Action */
   IFX_uint32_t SegDefAction;
   /** Segmentation Default Virtual Path Identifier */
   IFX_uint32_t SegDef_VPI;
   /** Segmentation Default Virtual Channel Identifier */
   IFX_uint32_t SegDef_VCI;
   /** Reassembly Add Default Class Filter */
   IFX_uint32_t ReaAddDefClassFilter;
   /** Offset of custom filter */
   IFX_uint32_t CustomFilterOffset;
   /** Mask of custom filter (part 1) */
   IFX_uint32_t CustomFilterMask_1;
   /** Mask of custom filter (part 2) */
   IFX_uint32_t CustomFilterMask_2;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** CPCS Protocol */
   IFX_uint32_t CPCS_Protocol;
   /** FCS Preserved within the PDU */
   IFX_uint32_t FCS_Present;
   /** Segmentation Classification Filter */
   IFX_uint32_t SegClassFilter;
   /** Segmentation Default Action */
   IFX_uint32_t SegDefAction;
   /** Segmentation Default Virtual Path Identifier */
   IFX_uint32_t SegDef_VPI;
   /** Segmentation Default Virtual Channel Identifier */
   IFX_uint32_t SegDef_VCI;
   /** Reassembly Add Default Class Filter */
   IFX_uint32_t ReaAddDefClassFilter;
   /** Offset of custom filter */
   IFX_uint32_t CustomFilterOffset;
   /** Mask of custom filter (part 1) */
   IFX_uint32_t CustomFilterMask_1;
   /** Mask of custom filter (part 2) */
   IFX_uint32_t CustomFilterMask_2;
#endif
} __PACKED__ ;


/**
   This command adds an entry into the ethernet forwarding table, up to 8 entries can
   be defined.
*/
struct CMD_Segmentation_VCC_Config
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Identifier */
   IFX_uint32_t VCC_id;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Identifier */
   IFX_uint32_t VCC_id;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#endif
} __PACKED__ ;


/**
   This command adds a classification filter to the segmentation classification filter
   table, up to 16 entries can be defined.
*/
struct CMD_SegmentationClassFilterConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** MAC Address part 1 */
   IFX_uint32_t MAC_Address_1;
   /** MAC Address part 2 */
   IFX_uint32_t MAC_Address_2;
   /** VLAN Identifier */
   IFX_uint32_t VLAN_id;
   /** VLAN priority */
   IFX_uint32_t VLAN_prio;
   /** VCC Forwarding Identifier */
   IFX_uint32_t VCC_id;
   /** Custom filter (part 1) */
   IFX_uint32_t CustomFilter_1;
   /** Custom filter (part 2) */
   IFX_uint32_t CustomFilter_2;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** MAC Address part 1 */
   IFX_uint32_t MAC_Address_1;
   /** MAC Address part 2 */
   IFX_uint32_t MAC_Address_2;
   /** VLAN Identifier */
   IFX_uint32_t VLAN_id;
   /** VLAN priority */
   IFX_uint32_t VLAN_prio;
   /** VCC Forwarding Identifier */
   IFX_uint32_t VCC_id;
   /** Custom filter (part 1) */
   IFX_uint32_t CustomFilter_1;
   /** Custom filter (part 2) */
   IFX_uint32_t CustomFilter_2;
#endif
} __PACKED__ ;


/**
   This command adds a classification filter to the reassembly classification filter
   table, up to 8 entries can be defined.
*/
struct CMD_ReassemblyClassFilterConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#endif
} __PACKED__ ;


/**
   This command deletes an entry from the ethernet forwarding table that was previously
   configured.
*/
struct CMD_Segmentation_VCC_Delete
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Identifier */
   IFX_uint32_t VCC_id;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Identifier */
   IFX_uint32_t VCC_id;
#endif
} __PACKED__ ;


/**
   This command deletes a classification filter in the reassembly classification filter
   table.
*/
struct CMD_ReassemblyClassFilterDelete
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Virtual Path Identifier */
   IFX_uint32_t VPI;
   /** Virtual Channel Identifier */
   IFX_uint32_t VCI;
#endif
} __PACKED__ ;


/**
   This command configures a link for Ethernet OAM functionality, the device must be in
   MAC mode and the TC layer must be EFM.
*/
struct CMD_Ethernet_OAM_Config
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** OAMPDU Size */
   IFX_uint32_t OAMPDU_Size;
   /** Ethernet OAM Mode */
   IFX_uint32_t OAM_Mode;
   /** Variable Retrieval Support */
   IFX_uint32_t VarRetrieval;
   /** Link Events Support */
   IFX_uint32_t LinkEvents;
   /** OAM Remote Loopback Support */
   IFX_uint32_t Loopback;
   /** Unidirectional Support */
   IFX_uint32_t Unidirectional;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** OAMPDU Size */
   IFX_uint32_t OAMPDU_Size;
   /** Ethernet OAM Mode */
   IFX_uint32_t OAM_Mode;
   /** Variable Retrieval Support */
   IFX_uint32_t VarRetrieval;
   /** Link Events Support */
   IFX_uint32_t LinkEvents;
   /** OAM Remote Loopback Support */
   IFX_uint32_t Loopback;
   /** Unidirectional Support */
   IFX_uint32_t Unidirectional;
#endif
} __PACKED__ ;


/**
   This command is used to setup the extract filters for both system side and line side
   extraction.
*/
struct CMD_EthernetExtractConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line Side */
   IFX_uint32_t Side;
   /** Extraction Filter 1 */
   IFX_uint32_t Filter1;
   /** MAC Address 1 Octets 0 - 3 */
   IFX_uint32_t MacAddr1_0_3;
   /** MAC Address 1 Octets 4- 5 */
   IFX_uint32_t MacAddr1_4_5;
   /** MAC Address Mask 1 Octets 0 - 3 */
   IFX_uint32_t AddrMask1_0_3;
   /** MAC Address Mask 1 Octets 4- 5 */
   IFX_uint32_t AddrMask1_4_5;
   /** VLAN Identifier 1 */
   IFX_uint32_t VlanID_1;
   /** VLAN Identifier Mask 1 */
   IFX_uint32_t VlanID_Mask_1;
   /** VLAN Priority 1 */
   IFX_uint32_t VlanPrio_1;
   /** VLAN Priority Mask 1 */
   IFX_uint32_t VlanPrioMask_1;
   /** Extraction Filter 2 */
   IFX_uint32_t Filter2;
   /** MAC Address 2 Octets 0 - 3 */
   IFX_uint32_t MacAddr2_0_3;
   /** MAC Address 2 Octets 4- 5 */
   IFX_uint32_t MacAddr2_4_5;
   /** MAC Address Mask 2 Octets 0 - 3 */
   IFX_uint32_t AddrMask2_0_3;
   /** MAC Address Mask 2 Octets 4- 5 */
   IFX_uint32_t AddrMask2_4_5;
   /** VLAN Identifier 2 */
   IFX_uint32_t VlanID_2;
   /** VLAN Identifier Mask 2 */
   IFX_uint32_t VlanID_Mask_2;
   /** VLAN Priority 2 */
   IFX_uint32_t VlanPrio_2;
   /** VLAN Priority Mask 2 */
   IFX_uint32_t VlanPrioMask_2;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line Side */
   IFX_uint32_t Side;
   /** Extraction Filter 1 */
   IFX_uint32_t Filter1;
   /** MAC Address 1 Octets 0 - 3 */
   IFX_uint32_t MacAddr1_0_3;
   /** MAC Address 1 Octets 4- 5 */
   IFX_uint32_t MacAddr1_4_5;
   /** MAC Address Mask 1 Octets 0 - 3 */
   IFX_uint32_t AddrMask1_0_3;
   /** MAC Address Mask 1 Octets 4- 5 */
   IFX_uint32_t AddrMask1_4_5;
   /** VLAN Identifier 1 */
   IFX_uint32_t VlanID_1;
   /** VLAN Identifier Mask 1 */
   IFX_uint32_t VlanID_Mask_1;
   /** VLAN Priority 1 */
   IFX_uint32_t VlanPrio_1;
   /** VLAN Priority Mask 1 */
   IFX_uint32_t VlanPrioMask_1;
   /** Extraction Filter 2 */
   IFX_uint32_t Filter2;
   /** MAC Address 2 Octets 0 - 3 */
   IFX_uint32_t MacAddr2_0_3;
   /** MAC Address 2 Octets 4- 5 */
   IFX_uint32_t MacAddr2_4_5;
   /** MAC Address Mask 2 Octets 0 - 3 */
   IFX_uint32_t AddrMask2_0_3;
   /** MAC Address Mask 2 Octets 4- 5 */
   IFX_uint32_t AddrMask2_4_5;
   /** VLAN Identifier 2 */
   IFX_uint32_t VlanID_2;
   /** VLAN Identifier Mask 2 */
   IFX_uint32_t VlanID_Mask_2;
   /** VLAN Priority 2 */
   IFX_uint32_t VlanPrio_2;
   /** VLAN Priority Mask 2 */
   IFX_uint32_t VlanPrioMask_2;
#endif
} __PACKED__ ;


/**
   This command changes the port sub-type from a -R subtype (default mode) to a -O
   subtype.
*/
struct CMD_PMD_CO_PortSubTypeSelect
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This command changes the port subtype.
*/
struct CMD_PMD_PortSubTypeSelect
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Port Subtype */
   IFX_uint32_t PortSubType;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Port Subtype */
   IFX_uint32_t PortSubType;
#endif
} __PACKED__ ;


/**
   This command sets the line quality thresholds for the local PMD STU-C and the link
   partner PMD STU-R.
*/
struct CMD_PMD_EndpointAlarmConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Number of Line Repeaters SRUs */
   IFX_uint32_t SRU_Cnt;
   /** Loop Attenuation Threshold */
   IFX_uint32_t ThreshLoopAtt;
   /** SNR Margin Threshold */
   IFX_uint32_t ThreshSNRMargin;
   /** Local Configuration Only */
   IFX_uint32_t LocalOnly;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Number of Line Repeaters SRUs */
   IFX_uint32_t SRU_Cnt;
   /** Loop Attenuation Threshold */
   IFX_uint32_t ThreshLoopAtt;
   /** SNR Margin Threshold */
   IFX_uint32_t ThreshSNRMargin;
   /** Local Configuration Only */
   IFX_uint32_t LocalOnly;
#endif
} __PACKED__ ;


/**
   This command configures SHDSL parameters for a span which are used to fill in the
   capability list for the handshake.
*/
struct CMD_PMD_SpanProfileGroupConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** SHDSL Line Wire Mode */
   IFX_uint32_t WireInterface;
   /** SHDSL Minimum Line Base Rate */
   IFX_uint32_t MinLineRate;
   /** SHDSL Maximum Line Base Rate */
   IFX_uint32_t MaxLineRate;
   /** SHDSL Minimum Line Sub Rate */
   IFX_uint32_t MinLineSubRate;
   /** SHDSL Maximum Line Sub Rate */
   IFX_uint32_t MaxLineSubRate;
   /** Symmetric/Asymmetric PSD Selection */
   IFX_uint32_t PSD;
   /** SHDSL Transmission Mode */
   IFX_uint32_t TransMode;
   /** SHDSL Remote (STU-R) EOC Management Enable */
   IFX_uint32_t RemoteEnabled;
   /** SHDSL Power Feeding */
   IFX_uint32_t PowerFeeding;
   /** SHDSL Current Condition Target Margin Down */
   IFX_int32_t CC_TargetMarginDown;
   /** SHDSL Worst Case Target Margin Down */
   IFX_int32_t WC_TargetMarginDown;
   /** SHDSL Current Condition Target Margin Up */
   IFX_int32_t CC_TargetMarginUp;
   /** SHDSL Worst Case Target Margin Up */
   IFX_int32_t WC_TargetMarginUp;
   /** SHDSL Used Target Margins */
   IFX_uint32_t UsedTargetMargins;
   /** SHDSL Reference Clock */
   IFX_uint32_t RefClock;
   /** SHDSL Line Probing Enable/Disable */
   IFX_uint32_t LineProbe;
   /** PAM Constellation Selection */
   IFX_uint32_t PAM_Constellation;
   /** Capability List Style Selection */
   IFX_uint32_t CapListStyle;
   /** Power Backoff Mode */
   IFX_int32_t PBO_Mode;
   /** Estimated Power Loss Mode */
   IFX_int32_t EPL_Mode;
   /** Power Backoff Value */
   IFX_int32_t PBO_Value;
   /** Power Backoff Offset */
   IFX_int32_t PBO_Offset;
   /** Maximum Baud Rate */
   IFX_int32_t MaxBaudRate;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** SHDSL Line Wire Mode */
   IFX_uint32_t WireInterface;
   /** SHDSL Minimum Line Base Rate */
   IFX_uint32_t MinLineRate;
   /** SHDSL Maximum Line Base Rate */
   IFX_uint32_t MaxLineRate;
   /** SHDSL Minimum Line Sub Rate */
   IFX_uint32_t MinLineSubRate;
   /** SHDSL Maximum Line Sub Rate */
   IFX_uint32_t MaxLineSubRate;
   /** Symmetric/Asymmetric PSD Selection */
   IFX_uint32_t PSD;
   /** SHDSL Transmission Mode */
   IFX_uint32_t TransMode;
   /** SHDSL Remote (STU-R) EOC Management Enable */
   IFX_uint32_t RemoteEnabled;
   /** SHDSL Power Feeding */
   IFX_uint32_t PowerFeeding;
   /** SHDSL Current Condition Target Margin Down */
   IFX_int32_t CC_TargetMarginDown;
   /** SHDSL Worst Case Target Margin Down */
   IFX_int32_t WC_TargetMarginDown;
   /** SHDSL Current Condition Target Margin Up */
   IFX_int32_t CC_TargetMarginUp;
   /** SHDSL Worst Case Target Margin Up */
   IFX_int32_t WC_TargetMarginUp;
   /** SHDSL Used Target Margins */
   IFX_uint32_t UsedTargetMargins;
   /** SHDSL Reference Clock */
   IFX_uint32_t RefClock;
   /** SHDSL Line Probing Enable/Disable */
   IFX_uint32_t LineProbe;
   /** PAM Constellation Selection */
   IFX_uint32_t PAM_Constellation;
   /** Capability List Style Selection */
   IFX_uint32_t CapListStyle;
   /** Power Backoff Mode */
   IFX_int32_t PBO_Mode;
   /** Estimated Power Loss Mode */
   IFX_int32_t EPL_Mode;
   /** Power Backoff Value */
   IFX_int32_t PBO_Value;
   /** Power Backoff Offset */
   IFX_int32_t PBO_Offset;
   /** Maximum Baud Rate */
   IFX_int32_t MaxBaudRate;
#endif
} __PACKED__ ;


/**
   This command is used to enable a proprietary G.hs mode, which allows to negotiate
   rates higher than the rates specified in the SHDSL.bis standard, as well as PAM
   constellations for 4, 8, 64, and 128 PAM.
*/
struct CMD_PMD_ExtendedRatesConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Extended PAM Mode */
   IFX_uint32_t Ext_PAM_Mode;
   /** Rate for Extended PAM mode */
   IFX_uint32_t Rate;
   /** Bits per symbol for Extended PAM mode */
   IFX_uint32_t Bits_per_symbol;
   /** Extended PMMS mode */
   IFX_uint32_t Ext_PMMS;
   /** Maximum Rate for Extended PMMS */
   IFX_uint32_t Ext_PMMS_Max_Rate;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Extended PAM Mode */
   IFX_uint32_t Ext_PAM_Mode;
   /** Rate for Extended PAM mode */
   IFX_uint32_t Rate;
   /** Bits per symbol for Extended PAM mode */
   IFX_uint32_t Bits_per_symbol;
   /** Extended PMMS mode */
   IFX_uint32_t Ext_PMMS;
   /** Maximum Rate for Extended PMMS */
   IFX_uint32_t Ext_PMMS_Max_Rate;
#endif
} __PACKED__ ;


/**
   This command is used to reference clock frequency in the PMD, by default the input
   is set to REF_CLK_IN_8KHZ and the output is REF_CLK_OUT_SYM_8KHZ, the direction of
   the clock by default is dependent on the port sub-type, if CPE the output clock and
   CO input clock.
*/
struct CMD_PMD_ReferenceClockConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Reference Clock Input Frequency */
   IFX_uint32_t RefClkInputFreq;
   /** Reference Clock Output Frequency */
   IFX_uint32_t RefClkOutputFreq;
   /** Clock Direction */
   IFX_uint32_t Clk_Dir;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Reference Clock Input Frequency */
   IFX_uint32_t RefClkInputFreq;
   /** Reference Clock Output Frequency */
   IFX_uint32_t RefClkOutputFreq;
   /** Clock Direction */
   IFX_uint32_t Clk_Dir;
#endif
} __PACKED__ ;


/**
   This command is used to select the mode for collecting the performance parameters
   which are provided locally and via EOC.
*/
struct CMD_PMD_PerfCountConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** UAS Counter Mode */
   IFX_uint32_t UAS_Mode;
   /** UAS Counter Enable */
   IFX_uint32_t UAS_Enable;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** UAS Counter Mode */
   IFX_uint32_t UAS_Mode;
   /** UAS Counter Enable */
   IFX_uint32_t UAS_Enable;
#endif
} __PACKED__ ;


/**
   This command is used to configure the G.hs operation of the PMD.
*/
struct CMD_PMD_GhsConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** G.hs Tone Power Threshold Offset */
   IFX_int32_t PowerThresOfs;
   /** Reserved 0 */
   IFX_uint32_t Rsvd_0;
   /** Reserved 1 */
   IFX_uint32_t Rsvd_1;
   /** Reserved 2 */
   IFX_uint32_t Rsvd_2;
   /** Reserved 3 */
   IFX_uint32_t Rsvd_3;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** G.hs Tone Power Threshold Offset */
   IFX_int32_t PowerThresOfs;
   /** Reserved 0 */
   IFX_uint32_t Rsvd_0;
   /** Reserved 1 */
   IFX_uint32_t Rsvd_1;
   /** Reserved 2 */
   IFX_uint32_t Rsvd_2;
   /** Reserved 3 */
   IFX_uint32_t Rsvd_3;
#endif
} __PACKED__ ;


/**
   This command is used to configure the PAF expected sequence number adaptation and
   the discard loop reset.
*/
struct CMD_PAF_SeqNoConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
   /** Expected Sequence Number Threshold */
   IFX_uint32_t ExpSeqNoThres;
   /** Discard Loop Reset */
   IFX_uint32_t DiscLoopRst;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
   /** Expected Sequence Number Threshold */
   IFX_uint32_t ExpSeqNoThres;
   /** Discard Loop Reset */
   IFX_uint32_t DiscLoopRst;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_PAF_SeqNoConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
   /** Expected Sequence Number Threshold */
   IFX_uint32_t ExpSeqNoThres;
   /** Discard Loop Reset */
   IFX_uint32_t DiscLoopRst;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
   /** Expected Sequence Number Threshold */
   IFX_uint32_t ExpSeqNoThres;
   /** Discard Loop Reset */
   IFX_uint32_t DiscLoopRst;
#endif
} __PACKED__ ;


/**
   This command is used to configure the events for a manual adaptation of the PAF
   expected sequence number.
*/
struct CMD_PAF_SeqNoEvtConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Guard Time */
   IFX_uint32_t GuardTime;
   /** PAF Link State Rise Event */
   IFX_uint32_t LinkStateRiseEvt;
   /** PAF Bad Fragment Event */
   IFX_uint32_t BadFragEvt;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Guard Time */
   IFX_uint32_t GuardTime;
   /** PAF Link State Rise Event */
   IFX_uint32_t LinkStateRiseEvt;
   /** PAF Bad Fragment Event */
   IFX_uint32_t BadFragEvt;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_PAF_SeqNoEvtConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Guard Time */
   IFX_uint32_t GuardTime;
   /** PAF Link State Rise Event */
   IFX_uint32_t LinkStateRiseEvt;
   /** PAF Bad Fragment Event */
   IFX_uint32_t BadFragEvt;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Guard Time */
   IFX_uint32_t GuardTime;
   /** PAF Link State Rise Event */
   IFX_uint32_t LinkStateRiseEvt;
   /** PAF Bad Fragment Event */
   IFX_uint32_t BadFragEvt;
#endif
} __PACKED__ ;


/**
   Indication that the PAF link state or the bad fragment counter has changed within
   the last guard time interval.
*/
struct EVT_PAF_SeqNo
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Current PAF Link State */
   IFX_uint32_t LinkState;
   /** PAF Link State Rise Event Counter */
   IFX_uint32_t RiseEvtCnt;
   /** PAF Bad Fragment Event Counter */
   IFX_uint32_t BadFragmentEvtCnt;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Current PAF Link State */
   IFX_uint32_t LinkState;
   /** PAF Link State Rise Event Counter */
   IFX_uint32_t RiseEvtCnt;
   /** PAF Bad Fragment Event Counter */
   IFX_uint32_t BadFragmentEvtCnt;
#endif
} __PACKED__ ;


/**
   This command is used to configure the PAF queue settings.
*/
struct CMD_PAF_Q_Config
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Delay */
   IFX_uint32_t TxDelay;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Delay */
   IFX_uint32_t TxDelay;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_PAF_Q_Config
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Delay */
   IFX_uint32_t TxDelay;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Delay */
   IFX_uint32_t TxDelay;
#endif
} __PACKED__ ;


/**
   This command is used to modify EFM / PTM 64/65-octed-based TC settings.
*/
struct CMD_EFM_6465o_TC_Modify
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** CRC Type for G.hs */
   IFX_uint32_t CrcTypeGhs;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** CRC Type for G.hs */
   IFX_uint32_t CrcTypeGhs;
#endif
} __PACKED__ ;


/**
   This command is used to configure the Bonding Aggregation Control Protocol (BACP).
*/
struct CMD_BACP_LinkConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Enable / Disable BACP */
   IFX_uint32_t Control;
   /** Group ID Low Part (Octets 0 - 3) */
   IFX_uint32_t GroupId_lo;
   /** Group ID High Part (Octets 4 - 5) */
   IFX_uint32_t GroupId_hi;
   /** Stream ID */
   IFX_uint32_t StreamId;
   /** MAC Address Octets 0 - 3 */
   IFX_uint32_t MacAddr_0_3;
   /** MAC Address Octets 4 - 5 */
   IFX_uint32_t MacAddr_4_5;
   /** Disable Autonomous BACP Initialization */
   IFX_uint32_t AutoInitDisable;
#else
   /** Link Number */
   IFX_uint32_t LinkNo;
   /** Enable / Disable BACP */
   IFX_uint32_t Control;
   /** Group ID Low Part (Octets 0 - 3) */
   IFX_uint32_t GroupId_lo;
   /** Group ID High Part (Octets 4 - 5) */
   IFX_uint32_t GroupId_hi;
   /** Stream ID */
   IFX_uint32_t StreamId;
   /** MAC Address Octets 0 - 3 */
   IFX_uint32_t MacAddr_0_3;
   /** MAC Address Octets 4 - 5 */
   IFX_uint32_t MacAddr_4_5;
   /** Disable Autonomous BACP Initialization */
   IFX_uint32_t AutoInitDisable;
#endif
} __PACKED__ ;


/**
   This command is used to enable/disable the transmit and receive flow at the system
   interface.
*/
struct CMD_LinkControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Control Mode */
   IFX_uint32_t TX_Mode;
   /** Receive Control Mode */
   IFX_uint32_t RX_Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit Control Mode */
   IFX_uint32_t TX_Mode;
   /** Receive Control Mode */
   IFX_uint32_t RX_Mode;
#endif
} __PACKED__ ;


/**
   This message is used to enable / disable the system interface loop depending on the
   flow type.
*/
struct CMD_SystemInterfaceLoopControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Loop Mode */
   IFX_uint32_t LoopMode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Loop Mode */
   IFX_uint32_t LoopMode;
#endif
} __PACKED__ ;


/**
   This message is used to enable / disable the TC Layer loop.
*/
struct CMD_TC_LayerLoopControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Loop Mode */
   IFX_uint32_t LoopMode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Loop Mode */
   IFX_uint32_t LoopMode;
#endif
} __PACKED__ ;


/**
   
*/
struct EVT_InitializationComplete
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Last Reset Reason */
   IFX_uint32_t LastResetReason;
#else
   /** Last Reset Reason */
   IFX_uint32_t LastResetReason;
#endif
} __PACKED__ ;


/**
   This alarm is an indication that the initialization of the of the chip has failed.
*/
struct ALM_InitializationAborted
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Abort Reason */
   IFX_uint32_t AbortReason;
   /** Reserved for future use */
   IFX_uint32_t Res_1;
   /** Reserved for future use */
   IFX_uint32_t Res_2;
   /** Reserved for future use */
   IFX_uint32_t Res_3;
   /** Reserved for future use */
   IFX_uint32_t Res_4;
#else
   /** Abort Reason */
   IFX_uint32_t AbortReason;
   /** Reserved for future use */
   IFX_uint32_t Res_1;
   /** Reserved for future use */
   IFX_uint32_t Res_2;
   /** Reserved for future use */
   IFX_uint32_t Res_3;
   /** Reserved for future use */
   IFX_uint32_t Res_4;
#endif
} __PACKED__ ;


/**
   This event indicates that a PMD channel has gone down.
*/
struct EVT_PMD_Channel_0_Down
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#else
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#endif
} __PACKED__ ;


/**
   This event indicates that a PMD channel has gone down.
*/
struct EVT_PMD_Channel_1_Down
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#else
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#endif
} __PACKED__ ;


/**
   This event indicates that a PMD channel has gone down.
*/
struct EVT_PMD_Channel_2_Down
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#else
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#endif
} __PACKED__ ;


/**
   This event indicates that a PMD channel has gone down.
*/
struct EVT_PMD_Channel_3_Down
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#else
   /** PMD CMD Number */
   IFX_uint32_t PMD_CmdNo;
   /** Optional CMD Parameter Bytes 0 - 3 */
   IFX_uint32_t Bytes_0_3;
   /** Optional CMD Parameter Bytes 4 - 7 */
   IFX_uint32_t Bytes_4_7;
   /** Optional CMD Parameter Bytes 8 - 11 */
   IFX_uint32_t Bytes_8_11;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_12_15;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_16_19;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_20_23;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_24_27;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_28_31;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_32_35;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_36_39;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_40_43;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_44_47;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_48_51;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_52_55;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_56_59;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_60_63;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_64_67;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_68_71;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_72_75;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_76_79;
   /** Optional CMD Parameter Bytes 40 - 43 */
   IFX_uint32_t Bytes_80_83;
   /** Optional CMD Parameter Bytes 44 - 47 */
   IFX_uint32_t Bytes_84_87;
   /** Optional CMD Parameter Bytes 48 - 51 */
   IFX_uint32_t Bytes_88_91;
   /** Optional CMD Parameter Bytes 12 - 15 */
   IFX_uint32_t Bytes_92_95;
   /** Optional CMD Parameter Bytes 16 - 19 */
   IFX_uint32_t Bytes_96_99;
   /** Optional CMD Parameter Bytes 20 - 23 */
   IFX_uint32_t Bytes_100_103;
   /** Optional CMD Parameter Bytes 24 - 27 */
   IFX_uint32_t Bytes_104_107;
   /** Optional CMD Parameter Bytes 28 - 31 */
   IFX_uint32_t Bytes_108_111;
   /** Optional CMD Parameter Bytes 32 - 35 */
   IFX_uint32_t Bytes_112_115;
   /** Optional CMD Parameter Bytes 36 - 39 */
   IFX_uint32_t Bytes_116_119;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_InventoryRequest
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Hardware Version */
   IFX_uint32_t HW_VER;
   /** ROM Version */
   IFX_uint32_t ROM_VER;
   /** FW Version IDC */
   IFX_uint32_t FW_VER;
   /** Host Interface Pin Strap */
   IFX_uint32_t CCONF;
   /** System Interface Configuration Pin Strap */
   IFX_uint32_t TCCONF;
   /** Boot Mode Pin Strap */
   IFX_uint32_t CBOOT;
   /** Device Mode */
   IFX_uint32_t MAC_PHY;
   /** PMD FW Version */
   IFX_uint32_t PMD_VER[8];
#else
   /** Hardware Version */
   IFX_uint32_t HW_VER;
   /** ROM Version */
   IFX_uint32_t ROM_VER;
   /** FW Version IDC */
   IFX_uint32_t FW_VER;
   /** Host Interface Pin Strap */
   IFX_uint32_t CCONF;
   /** System Interface Configuration Pin Strap */
   IFX_uint32_t TCCONF;
   /** Boot Mode Pin Strap */
   IFX_uint32_t CBOOT;
   /** Device Mode */
   IFX_uint32_t MAC_PHY;
   /** PMD FW Version */
   IFX_uint32_t PMD_VER[8];
#endif
} __PACKED__ ;


/**
   Reset of the IDC and PAMDSL firmware.
*/
struct CMD_Reset
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Soft Reset / Hard Reset */
   IFX_uint32_t Soft_Hard;
#else
   /** Soft Reset / Hard Reset */
   IFX_uint32_t Soft_Hard;
#endif
} __PACKED__ ;


/**
   This command is used send the power status of all STU-R links when the power status
   is not controlled internally in the device, the command should only be sent when the
   power status changes.
*/
struct CMD_LocalPowerStatus
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Power State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Power State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_TXSYMBOL_ReferenceStatus
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** NTR Status */
   IFX_uint32_t Status;
#else
   /** NTR Status */
   IFX_uint32_t Status;
#endif
} __PACKED__ ;


/**
   This command gets the configured state of the MAC for a link.
*/
struct CMD_MAC_ConfigGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This command configures the MAC functionality for a link.
*/
struct ACK_MAC_ConfigGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t SystemCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t System_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t SystemRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t SystemAdd;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t LineCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t Line_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t LineRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t LineAdd;
   /** Frame Size */
   IFX_uint32_t FrameSize;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t SystemCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t System_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t SystemRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t SystemAdd;
   /** Check the FCS of the Received Frame */
   IFX_uint32_t LineCheck;
   /** Removal of rx_er Marked Frame */
   IFX_uint32_t Line_rx_er;
   /** Remove FCS From the Received Frame */
   IFX_uint32_t LineRemove;
   /** Add the FCS to the Transmitted Frame */
   IFX_uint32_t LineAdd;
   /** Frame Size */
   IFX_uint32_t FrameSize;
#endif
} __PACKED__ ;


/**
   This command is only for IDC internal usage and not for standard chip programming.
*/
struct CMD_GeneralPurpose
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Action Number */
   IFX_uint32_t Action;
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** General Purpose Parameter 1 */
   IFX_uint32_t Param_1;
   /** General Purpose Parameter 2 */
   IFX_uint32_t Param_2;
   /** General Purpose Parameter 3 */
   IFX_uint32_t Param_3;
   /** General Purpose Parameter 4 */
   IFX_uint32_t Param_4;
   /** General Purpose Parameter 5 */
   IFX_uint32_t Param_5;
   /** General Purpose Parameter 6 */
   IFX_uint32_t Param_6;
   /** General Purpose Parameter 7 */
   IFX_uint32_t Param_7;
   /** General Purpose Parameter 8 */
   IFX_uint32_t Param_8;
   /** General Purpose Parameter 9 */
   IFX_uint32_t Param_9;
   /** General Purpose Parameter 10 */
   IFX_uint32_t Param_10;
#else
   /** Action Number */
   IFX_uint32_t Action;
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** General Purpose Parameter 1 */
   IFX_uint32_t Param_1;
   /** General Purpose Parameter 2 */
   IFX_uint32_t Param_2;
   /** General Purpose Parameter 3 */
   IFX_uint32_t Param_3;
   /** General Purpose Parameter 4 */
   IFX_uint32_t Param_4;
   /** General Purpose Parameter 5 */
   IFX_uint32_t Param_5;
   /** General Purpose Parameter 6 */
   IFX_uint32_t Param_6;
   /** General Purpose Parameter 7 */
   IFX_uint32_t Param_7;
   /** General Purpose Parameter 8 */
   IFX_uint32_t Param_8;
   /** General Purpose Parameter 9 */
   IFX_uint32_t Param_9;
   /** General Purpose Parameter 10 */
   IFX_uint32_t Param_10;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_GeneralPurpose
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Action Number */
   IFX_uint32_t Action;
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** General Purpose Parameter 1 */
   IFX_uint32_t Param_1;
   /** General Purpose Parameter 2 */
   IFX_uint32_t Param_2;
   /** General Purpose Parameter 3 */
   IFX_uint32_t Param_3;
   /** General Purpose Parameter 4 */
   IFX_uint32_t Param_4;
   /** General Purpose Parameter 5 */
   IFX_uint32_t Param_5;
   /** General Purpose Parameter 6 */
   IFX_uint32_t Param_6;
   /** General Purpose Parameter 7 */
   IFX_uint32_t Param_7;
   /** General Purpose Parameter 8 */
   IFX_uint32_t Param_8;
   /** General Purpose Parameter 9 */
   IFX_uint32_t Param_9;
   /** General Purpose Parameter 10 */
   IFX_uint32_t Param_10;
#else
   /** Action Number */
   IFX_uint32_t Action;
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** General Purpose Parameter 1 */
   IFX_uint32_t Param_1;
   /** General Purpose Parameter 2 */
   IFX_uint32_t Param_2;
   /** General Purpose Parameter 3 */
   IFX_uint32_t Param_3;
   /** General Purpose Parameter 4 */
   IFX_uint32_t Param_4;
   /** General Purpose Parameter 5 */
   IFX_uint32_t Param_5;
   /** General Purpose Parameter 6 */
   IFX_uint32_t Param_6;
   /** General Purpose Parameter 7 */
   IFX_uint32_t Param_7;
   /** General Purpose Parameter 8 */
   IFX_uint32_t Param_8;
   /** General Purpose Parameter 9 */
   IFX_uint32_t Param_9;
   /** General Purpose Parameter 10 */
   IFX_uint32_t Param_10;
#endif
} __PACKED__ ;


/**
   This event is only for IDC internal usage and indicates that something has
   happened.
*/
struct EVT_SomethingHappened
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Event Type */
   IFX_uint32_t Event;
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** General Purpose Parameter 1 */
   IFX_uint32_t Param_1;
   /** General Purpose Parameter 2 */
   IFX_uint32_t Param_2;
   /** General Purpose Parameter 3 */
   IFX_uint32_t Param_3;
   /** General Purpose Parameter 4 */
   IFX_uint32_t Param_4;
   /** General Purpose Parameter 5 */
   IFX_uint32_t Param_5;
   /** General Purpose Parameter 6 */
   IFX_uint32_t Param_6;
   /** General Purpose Parameter 7 */
   IFX_uint32_t Param_7;
   /** General Purpose Parameter 8 */
   IFX_uint32_t Param_8;
   /** General Purpose Parameter 9 */
   IFX_uint32_t Param_9;
   /** General Purpose Parameter 10 */
   IFX_uint32_t Param_10;
#else
   /** Event Type */
   IFX_uint32_t Event;
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** General Purpose Parameter 1 */
   IFX_uint32_t Param_1;
   /** General Purpose Parameter 2 */
   IFX_uint32_t Param_2;
   /** General Purpose Parameter 3 */
   IFX_uint32_t Param_3;
   /** General Purpose Parameter 4 */
   IFX_uint32_t Param_4;
   /** General Purpose Parameter 5 */
   IFX_uint32_t Param_5;
   /** General Purpose Parameter 6 */
   IFX_uint32_t Param_6;
   /** General Purpose Parameter 7 */
   IFX_uint32_t Param_7;
   /** General Purpose Parameter 8 */
   IFX_uint32_t Param_8;
   /** General Purpose Parameter 9 */
   IFX_uint32_t Param_9;
   /** General Purpose Parameter 10 */
   IFX_uint32_t Param_10;
#endif
} __PACKED__ ;


/**
   This event is only for IDC internal usage and indicates that the delay compensation
   state has changed.
*/
struct EVT_DC_StateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Old DC State */
   IFX_uint32_t OldState;
   /** New DC State */
   IFX_uint32_t NewState;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Old DC State */
   IFX_uint32_t OldState;
   /** New DC State */
   IFX_uint32_t NewState;
#endif
} __PACKED__ ;


/**
   This alarm is an indication that a delay measurement for a MPair bundle has failed.
*/
struct ALM_DelayMeasurementAborted
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Abort Reason */
   IFX_uint32_t AbortReason;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Abort Reason */
   IFX_uint32_t AbortReason;
#endif
} __PACKED__ ;


/**
   This event indicates that the IDC at the SCI interface has not received a transport
   layer ack for a transmitted message after 3 retries.
*/
struct EVT_SCI_MissingTransportLayerAck
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Channel Number */
   IFX_uint32_t ChannelNo;
   /** Information 1 */
   IFX_uint32_t Info1;
   /** Information 2 */
   IFX_uint32_t Info2;
   /** Information 3 */
   IFX_uint32_t Info3;
   /** Information 4 */
   IFX_uint32_t Info4;
#else
   /** Channel Number */
   IFX_uint32_t ChannelNo;
   /** Information 1 */
   IFX_uint32_t Info1;
   /** Information 2 */
   IFX_uint32_t Info2;
   /** Information 3 */
   IFX_uint32_t Info3;
   /** Information 4 */
   IFX_uint32_t Info4;
#endif
} __PACKED__ ;


/**
   This event indicates that the IDC at the SCI interface has not received a message
   layer ack for a transmitted command, the command was acknowledged with a transport
   layer ack but no message layer ack was received within 2 seconds.
*/
struct EVT_SCI_MissingMessageLayerAck
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Channel Number */
   IFX_uint32_t ChannelNo;
   /** Information 1 */
   IFX_uint32_t Info1;
   /** Information 2 */
   IFX_uint32_t Info2;
   /** Information 3 */
   IFX_uint32_t Info3;
   /** Information 4 */
   IFX_uint32_t Info4;
#else
   /** Channel Number */
   IFX_uint32_t ChannelNo;
   /** Information 1 */
   IFX_uint32_t Info1;
   /** Information 2 */
   IFX_uint32_t Info2;
   /** Information 3 */
   IFX_uint32_t Info3;
   /** Information 4 */
   IFX_uint32_t Info4;
#endif
} __PACKED__ ;


/**
   
*/
struct EVT_xSwitch_SlipDetected
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t Side;
   /** SLip Count */
   IFX_uint32_t SlipCnt;
#else
   /** SDI side selection */
   IFX_uint32_t Side;
   /** SLip Count */
   IFX_uint32_t SlipCnt;
#endif
} __PACKED__ ;


/**
   This alarm is an indication that the Firmware is a test version and the time of 1
   hour in data mode has expired.
*/
struct ALM_FW_TestVersionTimeout
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_IDC_FeatureStrGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** What String Header */
   IFX_uint32_t WhatHdr[3];
   /** Feature String */
   IFX_uint32_t FeatureStr[20];
#else
   /** What String Header */
   IFX_uint32_t WhatHdr[3];
   /** Feature String */
   IFX_uint32_t FeatureStr[20];
#endif
} __PACKED__ ;


/**
   This event is only for IDC internal usage and indicates various debug events for a
   delay compensation, restart SDI framer jobs and AUX configuration. A special
   firmware is needed for the events to be generated.
*/
struct EVT_DC_Debug
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Event Type */
   IFX_uint32_t Event;
   /** Parameter 1 */
   IFX_uint32_t Param_1;
   /** Parameter 2 */
   IFX_uint32_t Param_2;
   /** Parameter 3 */
   IFX_uint32_t Param_3;
   /** Parameter 4 */
   IFX_uint32_t Param_4;
   /** Parameter 5 */
   IFX_uint32_t Param_5;
   /** Parameter 6 */
   IFX_uint32_t Param_6;
   /** Parameter 7 */
   IFX_uint32_t Param_7;
   /** Parameter 8 */
   IFX_uint32_t Param_8;
   /** Parameter 9 */
   IFX_uint32_t Param_9;
   /** Parameter 10 */
   IFX_uint32_t Param_10;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Event Type */
   IFX_uint32_t Event;
   /** Parameter 1 */
   IFX_uint32_t Param_1;
   /** Parameter 2 */
   IFX_uint32_t Param_2;
   /** Parameter 3 */
   IFX_uint32_t Param_3;
   /** Parameter 4 */
   IFX_uint32_t Param_4;
   /** Parameter 5 */
   IFX_uint32_t Param_5;
   /** Parameter 6 */
   IFX_uint32_t Param_6;
   /** Parameter 7 */
   IFX_uint32_t Param_7;
   /** Parameter 8 */
   IFX_uint32_t Param_8;
   /** Parameter 9 */
   IFX_uint32_t Param_9;
   /** Parameter 10 */
   IFX_uint32_t Param_10;
#endif
} __PACKED__ ;


/**
   This test feature when enabled forces sending of corrupt packets in the transmitter
   direction.
*/
struct CMD_HDLC_TC_LinkCorruptPacketControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This command enables/disables the generation of HDLC-TC Sync events when the sync
   state changes.
*/
struct CMD_HDLC_TC_LinkSyncEventsControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This command enables/disables the generation of HDLC-TC Sync events when the sync
   state changes.
*/
struct EVT_HDLC_TC_LinkSyncStateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Sync State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Sync State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This command enables/disables the generation of HDLC-TC ACF changed events.
*/
struct CMD_HDLC_TC_LinkACF_EventsControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This event is generated each time the address and control field change.
*/
struct EVT_HDLC_TC_LinkACF_Changed
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Received Address and Control Field */
   IFX_uint32_t RxACF;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Received Address and Control Field */
   IFX_uint32_t RxACF;
#endif
} __PACKED__ ;


/**
   This command is used to request the performance monitoring parameters for an HDLC-TC
   link.
*/
struct CMD_HDLC_TC_LinkPmParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement contains the HDLC-TC performance monitoring counters requested
   by the command CMD_HDLC_TC_LinkPmParamGet.
*/
struct ACK_HDLC_TC_LinkPmParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** Transmitted Packets */
   IFX_uint32_t Counter_0;
   /** Received Packets */
   IFX_uint32_t Counter_1;
   /** Aborted Packets */
   IFX_uint32_t Counter_2;
   /** Oversized Packets */
   IFX_uint32_t Counter_3;
   /** Error Marked Packets */
   IFX_uint32_t Counter_4;
   /** Received Packets */
   IFX_uint32_t Counter_5;
   /** CRC Errors */
   IFX_uint32_t Counter_6;
   /** Aborted Packets */
   IFX_uint32_t Counter_7;
   /** Invalid Frames */
   IFX_uint32_t Counter_8;
   /** Forwarded Packets Total */
   IFX_uint32_t Counter_9;
   /** Forwarded Error Packets */
   IFX_uint32_t Counter_10;
   /** Discarded Packets/Frames */
   IFX_uint32_t Counter_11;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** Transmitted Packets */
   IFX_uint32_t Counter_0;
   /** Received Packets */
   IFX_uint32_t Counter_1;
   /** Aborted Packets */
   IFX_uint32_t Counter_2;
   /** Oversized Packets */
   IFX_uint32_t Counter_3;
   /** Error Marked Packets */
   IFX_uint32_t Counter_4;
   /** Received Packets */
   IFX_uint32_t Counter_5;
   /** CRC Errors */
   IFX_uint32_t Counter_6;
   /** Aborted Packets */
   IFX_uint32_t Counter_7;
   /** Invalid Frames */
   IFX_uint32_t Counter_8;
   /** Forwarded Packets Total */
   IFX_uint32_t Counter_9;
   /** Forwarded Error Packets */
   IFX_uint32_t Counter_10;
   /** Discarded Packets/Frames */
   IFX_uint32_t Counter_11;
#endif
} __PACKED__ ;


/**
   This test feature when enabled forces HEC errors at the receiver side of the
   connection, all cells will have the bits in the HEC byte inverted.
*/
struct CMD_ATM_TC_LinkHecInvert
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This is a test feature a single cell with HEC error will be transmitted to the
   receiver side of the connection, bit 7 of the HEC byte will be inverted.
*/
struct CMD_ATM_TC_LinkHecErrorInsert
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This command is used to request the performance monitoring parameters for an ATM-TC
   link.
*/
struct CMD_ATM_TC_LinkPmParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement contains the ATM-TC performance monitoring counters requested
   by the command CMD_ATM_TC_LinkPmParamGet.
*/
struct ACK_ATM_TC_LinkPmParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** ATM-TC Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** Transmitted Cells */
   IFX_uint32_t Counter_0;
   /** Total number of Cells Transmitted */
   IFX_uint32_t Counter_1;
   /** Uncorrected HEC Cells */
   IFX_uint32_t Counter_2;
   /** Number of correct received ATM cells */
   IFX_uint32_t Counter_3;
   /** Transmitted Cells */
   IFX_uint32_t Counter_4;
   /** Payload Bit Error Cells */
   IFX_uint32_t Counter_5;
   /** Received Idle/Unassigned Cells */
   IFX_uint32_t Counter_6;
   /** OCD Start Events */
   IFX_uint32_t Counter_7;
   /** LCD Start Events */
   IFX_uint32_t Counter_8;
   /** LCD Stop Events */
   IFX_uint32_t Counter_9;
   /** Discarded Cells */
   IFX_uint32_t Counter_10;
   /** Link Partner Uncorrected HEC Cells */
   IFX_uint32_t Counter_11;
#else
   /** ATM-TC Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** Transmitted Cells */
   IFX_uint32_t Counter_0;
   /** Total number of Cells Transmitted */
   IFX_uint32_t Counter_1;
   /** Uncorrected HEC Cells */
   IFX_uint32_t Counter_2;
   /** Number of correct received ATM cells */
   IFX_uint32_t Counter_3;
   /** Transmitted Cells */
   IFX_uint32_t Counter_4;
   /** Payload Bit Error Cells */
   IFX_uint32_t Counter_5;
   /** Received Idle/Unassigned Cells */
   IFX_uint32_t Counter_6;
   /** OCD Start Events */
   IFX_uint32_t Counter_7;
   /** LCD Start Events */
   IFX_uint32_t Counter_8;
   /** LCD Stop Events */
   IFX_uint32_t Counter_9;
   /** Discarded Cells */
   IFX_uint32_t Counter_10;
   /** Link Partner Uncorrected HEC Cells */
   IFX_uint32_t Counter_11;
#endif
} __PACKED__ ;


/**
   This command is used to request the status of the cell delineation finite state
   machine and the maintenance state machine for an ATM-TC link in receive direction.
*/
struct CMD_ATM_TC_LinkFsmLcdStateGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement contains the current states of ATM-TC LCD and FSM.
*/
struct ACK_ATM_TC_LinkFsmLcdStateGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** ATM-TC Link Number */
   IFX_uint32_t LinkNo;
   /** FSM State */
   IFX_uint32_t FSM_State;
   /** LCD State */
   IFX_uint32_t LCD_State;
   /** LCD Failure */
   IFX_uint32_t LCD_Failure;
   /** Link Partner LCD State */
   IFX_uint32_t LP_LCD_State;
   /** Link Partner LCD Failure */
   IFX_uint32_t LP_LCD_Failure;
#else
   /** ATM-TC Link Number */
   IFX_uint32_t LinkNo;
   /** FSM State */
   IFX_uint32_t FSM_State;
   /** LCD State */
   IFX_uint32_t LCD_State;
   /** LCD Failure */
   IFX_uint32_t LCD_Failure;
   /** Link Partner LCD State */
   IFX_uint32_t LP_LCD_State;
   /** Link Partner LCD Failure */
   IFX_uint32_t LP_LCD_Failure;
#endif
} __PACKED__ ;


/**
   This commands enables the generation of event messages when the LCD state changes
   for a given ATM-TC link.
*/
struct CMD_ATM_TC_LinkLcdStateEventControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This event contains the current state of ATM-TC LCD state machine.
*/
struct EVT_ATM_TC_LinkLcdStateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Uint_ID;
   /** LCD State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Uint_ID;
   /** LCD State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This commands enables the generation of event messages when the FSM state changes
   for a given ATM-TC link.
*/
struct CMD_ATM_TC_LinkFsmStateEventControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This event contains the current state of ATM-TC FSM state machine.
*/
struct EVT_ATM_TC_LinkFsmStateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** FSM State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** FSM State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   NCD Failure:
   An NCD failure is declared when an NCD anomaly persists for more than 2.5 + 0.5s
   after the start of DATA MODE. An NCD failure terminates when no NCD anomaly is
   present for more than 10 + 0.5s.
   LCD Failure:
   An LCD failure is declared when an LCD defect persists for more than 2.5 + 0.5s. An
   LCD failure terminates when no LCD defect is present for more than 10 + 0.5s.
*/
struct CMD_ATM_TC_LinkFailureEventControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Mode;
#endif
} __PACKED__ ;


/**
   This event indicates a failure state in the ATM-TC state machine.
*/
struct EVT_ATM_TC_LinkNcdLcdFailure
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Uint_ID;
   /** ATM-TC State Machine Failure */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Uint_ID;
   /** ATM-TC State Machine Failure */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This commands enables/disables the insert exctract functionality for a given link.
*/
struct CMD_ATM_InsertExtractControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Control;
   /** Direction */
   IFX_uint32_t Direction;
   /** Disable CRC-10 Generation */
   IFX_uint32_t DisableCrc;
   /** Reserved for future use */
   IFX_uint32_t Res_2;
   /** Reserved for future use */
   IFX_uint32_t Res_3;
   /** Reserved for future use */
   IFX_uint32_t Res_4;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control Mode */
   IFX_uint32_t Control;
   /** Direction */
   IFX_uint32_t Direction;
   /** Disable CRC-10 Generation */
   IFX_uint32_t DisableCrc;
   /** Reserved for future use */
   IFX_uint32_t Res_2;
   /** Reserved for future use */
   IFX_uint32_t Res_3;
   /** Reserved for future use */
   IFX_uint32_t Res_4;
#endif
} __PACKED__ ;


/**
   This command inserts an ATM cell in the transmit direction to the line.
*/
struct CMD_ATM_CellInsert
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** ATM Cell to be Inserted */
   IFX_uint8_t AtmCell[56];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** ATM Cell to be Inserted */
   IFX_uint8_t AtmCell[56];
#endif
} __PACKED__ ;


/**
   This command is used to request the performance monitoring parameters for the ATM
   cell insert extract functionality.
*/
struct CMD_ATM_InsertExtract_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_ATM_InsertExtract_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** Extracted Cell Count */
   IFX_uint32_t ExtractedCells;
   /** Dicarded Extract Cell Count */
   IFX_uint32_t DisExtractCells;
   /** Reserved for future use */
   IFX_uint32_t Res_1;
   /** Inserted Cell Count */
   IFX_uint32_t InsertedCells;
   /** Reserved for future use */
   IFX_uint32_t Res_2;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** Extracted Cell Count */
   IFX_uint32_t ExtractedCells;
   /** Dicarded Extract Cell Count */
   IFX_uint32_t DisExtractCells;
   /** Reserved for future use */
   IFX_uint32_t Res_1;
   /** Inserted Cell Count */
   IFX_uint32_t InsertedCells;
   /** Reserved for future use */
   IFX_uint32_t Res_2;
#endif
} __PACKED__ ;


/**
   This event indicates that the cell was inserted into the data stream. This event is
   only generated when the CMD_ATM_CellInsert was acknowledged with a positive ack.
*/
struct EVT_ATM_CellInserted
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This event contains an extracted ATM cell.
*/
struct EVT_ATM_CellExtracted
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** ATM Cell */
   IFX_uint8_t AtmCell[56];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** ATM Cell */
   IFX_uint8_t AtmCell[56];
#endif
} __PACKED__ ;


/**
   This command resets the respective PMD and its associated database to the default
   state.
*/
struct CMD_PMD_Reset
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This command controls the PMD Link enable, handshake cleardown and or Ignore
   incoming handshake.
*/
struct CMD_PMD_Control
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Control */
   IFX_uint32_t LinkControl;
   /** Link Activation State */
   IFX_uint32_t ActivationState;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Control */
   IFX_uint32_t LinkControl;
   /** Link Activation State */
   IFX_uint32_t ActivationState;
#endif
} __PACKED__ ;


/**
   This command requests the current status of the PMD.
*/
struct CMD_PMD_StatusGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the current status of the PMD.
*/
struct ACK_PMD_StatusGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Fault */
   IFX_uint32_t Fault;
   /** Data Rate */
   IFX_uint32_t DataRate;
   /** CO Supported */
   IFX_uint32_t CO_Support;
   /** CPE Supported */
   IFX_uint32_t CPE_Support;
   /** Link Status */
   IFX_uint32_t LinkStatus;
   /** Negotiated Constellation */
   IFX_uint32_t NegotiatedConst;
   /** Used Capability List */
   IFX_uint32_t UsedCaplist;
   /** Region Information */
   IFX_uint32_t Region;
   /** Capability List Mode */
   IFX_uint32_t CaplistMode;
   /** Bits per Symbol */
   IFX_uint32_t BitsPerSymbol;
   /** Port Subtype */
   IFX_uint32_t PortSubType;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Fault */
   IFX_uint32_t Fault;
   /** Data Rate */
   IFX_uint32_t DataRate;
   /** CO Supported */
   IFX_uint32_t CO_Support;
   /** CPE Supported */
   IFX_uint32_t CPE_Support;
   /** Link Status */
   IFX_uint32_t LinkStatus;
   /** Negotiated Constellation */
   IFX_uint32_t NegotiatedConst;
   /** Used Capability List */
   IFX_uint32_t UsedCaplist;
   /** Region Information */
   IFX_uint32_t Region;
   /** Capability List Mode */
   IFX_uint32_t CaplistMode;
   /** Bits per Symbol */
   IFX_uint32_t BitsPerSymbol;
   /** Port Subtype */
   IFX_uint32_t PortSubType;
#endif
} __PACKED__ ;


/**
   This command enables/disables a PMD channel.
*/
struct CMD_PMD_ChannelControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Action */
   IFX_uint32_t Action;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Action */
   IFX_uint32_t Action;
#endif
} __PACKED__ ;


/**
   This command requests the performance monitoring parameters from the local PMD or
   the link partner PMD or any repeaters.
*/
struct CMD_PMD_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the performance monitoring counters for the local PMD
   and the link partner PMD.
*/
struct ACK_PMD_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
   /** Counter Status Customer Side */
   IFX_uint32_t Status_CS;
   /** Line Attenuation in dB (Customer Side) */
   IFX_uint32_t Counter_0;
   /** Link Loss Counter (Customer Side) */
   IFX_uint32_t Counter_1;
   /** RX SNR Margin (Customer Side) */
   IFX_int32_t Counter_2;
   /** Code Violation Error Counter (Customer Side) */
   IFX_uint32_t Counter_3;
   /** Erroneous Seconds Counter (Customer Side) */
   IFX_uint32_t Counter_4;
   /** Severely Erroneous Seconds Counter (Customer Side) */
   IFX_uint32_t Counter_5;
   /** LOSWS Counter (Customer Side) */
   IFX_uint32_t Counter_6;
   /** Unavailable Seconds Counter (Customer Side) */
   IFX_uint32_t Counter_7;
   /** Line Attenuation in dB (Network Side) */
   IFX_uint32_t Counter_8;
   /** Link Loss Counter (Network Side) */
   IFX_uint32_t Counter_9;
   /** RX SNR Margin (Network Side) */
   IFX_int32_t Counter_10;
   /** Code Violation Error Counter (Network Side) */
   IFX_uint32_t Counter_11;
   /** Erroneous Seconds Counter (Network Side) */
   IFX_uint32_t Counter_12;
   /** Severely Erroneous Seconds Counter (Network Side) */
   IFX_uint32_t Counter_13;
   /** LOSWS Counter (Network Side) */
   IFX_uint32_t Counter_14;
   /** Unavailable Seconds Counter (Network Side) */
   IFX_uint32_t Counter_15;
   /** Power Back-Off Value (Customer Side) */
   IFX_uint32_t Counter_16;
   /** Power Back-Off Value (Network Side) */
   IFX_uint32_t Counter_17;
   /** Counter Status Network Side */
   IFX_uint32_t Status_NS;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
   /** Counter Status Customer Side */
   IFX_uint32_t Status_CS;
   /** Line Attenuation in dB (Customer Side) */
   IFX_uint32_t Counter_0;
   /** Link Loss Counter (Customer Side) */
   IFX_uint32_t Counter_1;
   /** RX SNR Margin (Customer Side) */
   IFX_int32_t Counter_2;
   /** Code Violation Error Counter (Customer Side) */
   IFX_uint32_t Counter_3;
   /** Erroneous Seconds Counter (Customer Side) */
   IFX_uint32_t Counter_4;
   /** Severely Erroneous Seconds Counter (Customer Side) */
   IFX_uint32_t Counter_5;
   /** LOSWS Counter (Customer Side) */
   IFX_uint32_t Counter_6;
   /** Unavailable Seconds Counter (Customer Side) */
   IFX_uint32_t Counter_7;
   /** Line Attenuation in dB (Network Side) */
   IFX_uint32_t Counter_8;
   /** Link Loss Counter (Network Side) */
   IFX_uint32_t Counter_9;
   /** RX SNR Margin (Network Side) */
   IFX_int32_t Counter_10;
   /** Code Violation Error Counter (Network Side) */
   IFX_uint32_t Counter_11;
   /** Erroneous Seconds Counter (Network Side) */
   IFX_uint32_t Counter_12;
   /** Severely Erroneous Seconds Counter (Network Side) */
   IFX_uint32_t Counter_13;
   /** LOSWS Counter (Network Side) */
   IFX_uint32_t Counter_14;
   /** Unavailable Seconds Counter (Network Side) */
   IFX_uint32_t Counter_15;
   /** Power Back-Off Value (Customer Side) */
   IFX_uint32_t Counter_16;
   /** Power Back-Off Value (Network Side) */
   IFX_uint32_t Counter_17;
   /** Counter Status Network Side */
   IFX_uint32_t Status_NS;
#endif
} __PACKED__ ;


/**
   This command requests the link state of the local and remote units. After performing
   this command on a local unit the link state will be reevaluated, the device fault
   will only be removed when all alarms are zero.
*/
struct CMD_PMD_LinkStateGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the status of the local and remote units.
*/
struct ACK_PMD_LinkStateGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
   /** Customer Side Status Indication */
   IFX_uint32_t CS_Status;
   /** Network Side Status Indication */
   IFX_uint32_t NS_Status;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
   /** Customer Side Status Indication */
   IFX_uint32_t CS_Status;
   /** Network Side Status Indication */
   IFX_uint32_t NS_Status;
#endif
} __PACKED__ ;


/**
   This event indicates the PMD state for a given link. This Event will be sent each
   time the PMD state changes.
*/
struct EVT_PMD_LinkState
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** PMD State */
   IFX_uint32_t State;
   /** Condition for State Change */
   IFX_uint32_t Condition;
   /** Reason for State Change */
   IFX_uint32_t Reason;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** PMD State */
   IFX_uint32_t State;
   /** Condition for State Change */
   IFX_uint32_t Condition;
   /** Reason for State Change */
   IFX_uint32_t Reason;
#endif
} __PACKED__ ;


/**
   This alarm indicates the PMD status has changed for a given link. This Event will be
   sent each time the PMD state changes.
*/
struct ALM_PMD_StatusChanged
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
   /** Customer or Network Side */
   IFX_uint32_t Side;
   /** Status Indication */
   IFX_uint32_t Status;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Unit Identifier */
   IFX_uint32_t Unit_ID;
   /** Customer or Network Side */
   IFX_uint32_t Side;
   /** Status Indication */
   IFX_uint32_t Status;
#endif
} __PACKED__ ;


/**
   This command control the generation of ALM_PMD_StatusChanged messages for a given
   link.
*/
struct CMD_PMD_AlarmControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Alarm Selection Mask */
   IFX_uint32_t Mask;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Alarm Selection Mask */
   IFX_uint32_t Mask;
#endif
} __PACKED__ ;


/**
   This command requests the multi wire mapping for a M Pair link.
*/
struct CMD_PMD_MultiWireMappingGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the multi wire mapping for a M Pair configured link.
*/
struct ACK_PMD_MultiWireMappingGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Master Link Number */
   IFX_uint32_t Master;
   /** Slave 1 Link Number */
   IFX_uint32_t Slave_1;
   /** Slave 2 Link Number */
   IFX_uint32_t Slave_2;
   /** Slave 3 Link Number */
   IFX_uint32_t Slave_3;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Master Link Number */
   IFX_uint32_t Master;
   /** Slave 1 Link Number */
   IFX_uint32_t Slave_1;
   /** Slave 2 Link Number */
   IFX_uint32_t Slave_2;
   /** Slave 3 Link Number */
   IFX_uint32_t Slave_3;
#endif
} __PACKED__ ;


/**
   This event indicates the multi wire mapping a given link. This Event will be sent
   each time the mapping changes.
*/
struct EVT_PMD_MultiWireMapping
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Master Link Number Previous */
   IFX_uint32_t Master_Prev;
   /** Master Link Number Current */
   IFX_uint32_t Master_Crnt;
   /** Slave 1 Link Number */
   IFX_uint32_t Slave_1;
   /** Slave 2 Link Number */
   IFX_uint32_t Slave_2;
   /** Slave 3 Link Number */
   IFX_uint32_t Slave_3;
   /** First In Interleaving Order */
   IFX_uint32_t InterleaveMaster;
   /** Second In Interleaving Order */
   IFX_uint32_t InterleaveSlave1;
   /** Third In Interleaving Order */
   IFX_uint32_t InterleaveSlave2;
   /** Fourth In Interleaving Order */
   IFX_uint32_t InterleaveSlave3;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Master Link Number Previous */
   IFX_uint32_t Master_Prev;
   /** Master Link Number Current */
   IFX_uint32_t Master_Crnt;
   /** Slave 1 Link Number */
   IFX_uint32_t Slave_1;
   /** Slave 2 Link Number */
   IFX_uint32_t Slave_2;
   /** Slave 3 Link Number */
   IFX_uint32_t Slave_3;
   /** First In Interleaving Order */
   IFX_uint32_t InterleaveMaster;
   /** Second In Interleaving Order */
   IFX_uint32_t InterleaveSlave1;
   /** Third In Interleaving Order */
   IFX_uint32_t InterleaveSlave2;
   /** Fourth In Interleaving Order */
   IFX_uint32_t InterleaveSlave3;
#endif
} __PACKED__ ;


/**
   This event indicates the PMD state for a given link. This Event will be sent each
   time the PMD state changes.
*/
struct EVT_PMD_MPairStatus
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** M Pair State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** M Pair State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This command enables/disables the PMD state machine, by default the PMD state
   machine is enabled.
*/
struct CMD_PMD_SM_Control
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** State Machine Control */
   IFX_uint32_t Control;
   /** NFC Forwarding Control */
   IFX_uint32_t NFC_Forwarding;
   /** Force Training */
   IFX_uint32_t ForceTraining;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** State Machine Control */
   IFX_uint32_t Control;
   /** NFC Forwarding Control */
   IFX_uint32_t NFC_Forwarding;
   /** Force Training */
   IFX_uint32_t ForceTraining;
#endif
} __PACKED__ ;


/**
   This event indicates that delay compensation was performed for a M-pair bundle.
*/
struct EVT_PMD_DelayCompState
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** M-Pair Link Number */
   IFX_uint32_t MpairLinkNo;
   /** Link 0 Delay */
   IFX_uint32_t Link_0_Delay;
   /** Link 1 Delay */
   IFX_uint32_t Link_1_Delay;
   /** Link 2 Delay */
   IFX_uint32_t Link_2_Delay;
   /** Link 3 Delay */
   IFX_uint32_t Link_3_Delay;
#else
   /** M-Pair Link Number */
   IFX_uint32_t MpairLinkNo;
   /** Link 0 Delay */
   IFX_uint32_t Link_0_Delay;
   /** Link 1 Delay */
   IFX_uint32_t Link_1_Delay;
   /** Link 2 Delay */
   IFX_uint32_t Link_2_Delay;
   /** Link 3 Delay */
   IFX_uint32_t Link_3_Delay;
#endif
} __PACKED__ ;


/**
   This alarm indicates that the peer device has a different TC layer or no common TC
   layer was selected during handshake.
*/
struct ALM_PMD_TC_LayerMismatch
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Detected TC Layer */
   IFX_uint32_t DetectedTC;
   /** Reserved 0 */
   IFX_uint32_t Rsvd_0;
   /** Reserved 1 */
   IFX_uint32_t Rsvd_1;
   /** Reserved 2 */
   IFX_uint32_t Rsvd_2;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Detected TC Layer */
   IFX_uint32_t DetectedTC;
   /** Reserved 0 */
   IFX_uint32_t Rsvd_0;
   /** Reserved 1 */
   IFX_uint32_t Rsvd_1;
   /** Reserved 2 */
   IFX_uint32_t Rsvd_2;
#endif
} __PACKED__ ;


/**
   This command controls a host driven delay compensation.
*/
struct CMD_PMD_DelayComp
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Mask of the Delay Compensation Group */
   IFX_uint32_t LinkMask;
   /** Delay Compensation Action */
   IFX_uint32_t Action;
   /** Reserved */
   IFX_uint32_t Res_0;
   /** Reserved */
   IFX_uint32_t Res_1;
   /** Reserved */
   IFX_uint32_t Res_2;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Link Mask of the Delay Compensation Group */
   IFX_uint32_t LinkMask;
   /** Delay Compensation Action */
   IFX_uint32_t Action;
   /** Reserved */
   IFX_uint32_t Res_0;
   /** Reserved */
   IFX_uint32_t Res_1;
   /** Reserved */
   IFX_uint32_t Res_2;
#endif
} __PACKED__ ;


/**
   This command requests the performance monitoring parameters for the clause 30 line
   side.
*/
struct CMD_Clause30_PM_ParamLineSideGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the performance monitoring counters for clause 30 line
   side. All counters are delta counters (the delta value from the last get) and are
   wrap around
*/
struct ACK_Clause30_PM_ParamLineSideGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** aFramesTransmittedOK Counter */
   IFX_uint32_t Counter_0;
   /** aFramesReceivedOK Counter */
   IFX_uint32_t Counter_1;
   /** aFrameCheckSequenceErrors Counter */
   IFX_uint32_t Counter_2;
   /** aAlignmentErrors Counter */
   IFX_uint32_t Counter_3;
   /** aOctetsTransmittedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_4_msw;
   /** aOctetsTransmittedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_4_lsw;
   /** aOctetsReceivedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_5_msw;
   /** aOctetsReceivedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_5_lsw;
   /** aFramesLostDueToIntMACXmitError Counter */
   IFX_uint32_t Counter_6;
   /** aFramesLostDueToIntMACRcvError Counter */
   IFX_uint32_t Counter_7;
   /** aPAUSEMACCtrlFramesTransmitted Counter */
   IFX_uint32_t Counter_8;
   /** aPAUSEMACCtrlFramesReceived Counter */
   IFX_uint32_t Counter_9;
   /** aFrameTooLongErrors Counter */
   IFX_uint32_t Counter_10;
   /** aFrameTooShortErrors Counter */
   IFX_uint32_t Counter_11;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** aFramesTransmittedOK Counter */
   IFX_uint32_t Counter_0;
   /** aFramesReceivedOK Counter */
   IFX_uint32_t Counter_1;
   /** aFrameCheckSequenceErrors Counter */
   IFX_uint32_t Counter_2;
   /** aAlignmentErrors Counter */
   IFX_uint32_t Counter_3;
   /** aOctetsTransmittedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_4_msw;
   /** aOctetsTransmittedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_4_lsw;
   /** aOctetsReceivedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_5_msw;
   /** aOctetsReceivedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_5_lsw;
   /** aFramesLostDueToIntMACXmitError Counter */
   IFX_uint32_t Counter_6;
   /** aFramesLostDueToIntMACRcvError Counter */
   IFX_uint32_t Counter_7;
   /** aPAUSEMACCtrlFramesTransmitted Counter */
   IFX_uint32_t Counter_8;
   /** aPAUSEMACCtrlFramesReceived Counter */
   IFX_uint32_t Counter_9;
   /** aFrameTooLongErrors Counter */
   IFX_uint32_t Counter_10;
   /** aFrameTooShortErrors Counter */
   IFX_uint32_t Counter_11;
#endif
} __PACKED__ ;


/**
   This command requests the performance monitoring parameters for the clause 30 System
   side.
*/
struct CMD_Clause30_PM_ParamSystemSideGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the performance monitoring counters for clause 30
   system side. All counters are delta counters (the delta value from the last get) and
   are wrap around
*/
struct ACK_Clause30_PM_ParamSystemSideGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** aFramesTransmittedOK Counter */
   IFX_uint32_t Counter_0;
   /** aSingleCollisionFrames Counter */
   IFX_uint32_t Counter_1;
   /** aMultipleCollisionFrames Counter */
   IFX_uint32_t Counter_2;
   /** aFramesReceivedOK Counter */
   IFX_uint32_t Counter_3;
   /** aFrameCheckSequenceErrors Counter */
   IFX_uint32_t Counter_4;
   /** aAlignmentErrors Counter */
   IFX_uint32_t Counter_5;
   /** aOctetsTransmittedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_6_msw;
   /** aOctetsTransmittedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_6_lsw;
   /** aOctetsReceivedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_7_msw;
   /** aOctetsReceivedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_7_lsw;
   /** aFramesLostDueToIntMACXmitError Counter */
   IFX_uint32_t Counter_8;
   /** aFramesLostDueToIntMACRcvError Counter */
   IFX_uint32_t Counter_9;
   /** aPAUSEMACCtrlFramesTransmitted Counter */
   IFX_uint32_t Counter_10;
   /** aPAUSEMACCtrlFramesReceived Counter */
   IFX_uint32_t Counter_11;
   /** aFrameTooLongErrors Counter */
   IFX_uint32_t Counter_12;
   /** aFrameTooShortErrors Counter */
   IFX_uint32_t Counter_13;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** aFramesTransmittedOK Counter */
   IFX_uint32_t Counter_0;
   /** aSingleCollisionFrames Counter */
   IFX_uint32_t Counter_1;
   /** aMultipleCollisionFrames Counter */
   IFX_uint32_t Counter_2;
   /** aFramesReceivedOK Counter */
   IFX_uint32_t Counter_3;
   /** aFrameCheckSequenceErrors Counter */
   IFX_uint32_t Counter_4;
   /** aAlignmentErrors Counter */
   IFX_uint32_t Counter_5;
   /** aOctetsTransmittedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_6_msw;
   /** aOctetsTransmittedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_6_lsw;
   /** aOctetsReceivedOK Counter (MSW) [63:32] */
   IFX_uint32_t Counter_7_msw;
   /** aOctetsReceivedOK Counter (LSW) [31:0] */
   IFX_uint32_t Counter_7_lsw;
   /** aFramesLostDueToIntMACXmitError Counter */
   IFX_uint32_t Counter_8;
   /** aFramesLostDueToIntMACRcvError Counter */
   IFX_uint32_t Counter_9;
   /** aPAUSEMACCtrlFramesTransmitted Counter */
   IFX_uint32_t Counter_10;
   /** aPAUSEMACCtrlFramesReceived Counter */
   IFX_uint32_t Counter_11;
   /** aFrameTooLongErrors Counter */
   IFX_uint32_t Counter_12;
   /** aFrameTooShortErrors Counter */
   IFX_uint32_t Counter_13;
#endif
} __PACKED__ ;


/**
   This command requests the mapping between the VCC entries and the segmentation
   channels, i. e. the ATM entries (0..7) in the MAC VPI/VCI map table.
*/
struct CMD_VCC_MappingGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledge returns the mapping between the VCC entries and the segmentation
   channels, i. e. the ATM entries (0..7) in the MAC VPI/VCI map table.
*/
struct ACK_VCC_MappingGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Entry Channel 0 */
   IFX_uint32_t Channel_0;
   /** VCC Entry Channel 1 */
   IFX_uint32_t Channel_1;
   /** VCC Entry Channel 2 */
   IFX_uint32_t Channel_2;
   /** VCC Entry Channel 3 */
   IFX_uint32_t Channel_3;
   /** VCC Entry Channel 4 */
   IFX_uint32_t Channel_4;
   /** VCC Entry Channel 5 */
   IFX_uint32_t Channel_5;
   /** VCC Entry Channel 6 */
   IFX_uint32_t Channel_6;
   /** VCC Entry Channel 7 */
   IFX_uint32_t Channel_7;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VCC Entry Channel 0 */
   IFX_uint32_t Channel_0;
   /** VCC Entry Channel 1 */
   IFX_uint32_t Channel_1;
   /** VCC Entry Channel 2 */
   IFX_uint32_t Channel_2;
   /** VCC Entry Channel 3 */
   IFX_uint32_t Channel_3;
   /** VCC Entry Channel 4 */
   IFX_uint32_t Channel_4;
   /** VCC Entry Channel 5 */
   IFX_uint32_t Channel_5;
   /** VCC Entry Channel 6 */
   IFX_uint32_t Channel_6;
   /** VCC Entry Channel 7 */
   IFX_uint32_t Channel_7;
#endif
} __PACKED__ ;


/**
   This command requests the performance monitoring parameters for the AAL5
   Segmentation.
*/
struct CMD_AAL5_Segmentation_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the performance monitoring counters for AAL5
   Segmentation. All counters are delta counters (the delta value from the last get)
   and are wrap around. For channel to VCC (VPI/VCI) mapping see CMD_VCC_MappingGet.
*/
struct ACK_AAL5_Segmentation_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** ETH Frames Rx without VCC Matching Counter */
   IFX_uint32_t Counter_0;
   /** ETH Frames Rx for Segmentation on Channel 0 Counter */
   IFX_uint32_t Counter_1;
   /** ETH Frames Rx for Segmentation on Channel 1 Counter */
   IFX_uint32_t Counter_2;
   /** ETH Frames Rx for Segmentation on Channel 2 Counter */
   IFX_uint32_t Counter_3;
   /** ETH Frames Rx for Segmentation on Channel 3 Counter */
   IFX_uint32_t Counter_4;
   /** ETH Frames Rx for Segmentation on Channel 4 Counter */
   IFX_uint32_t Counter_5;
   /** ETH Frames Rx for Segmentation on Channel 5 Counter */
   IFX_uint32_t Counter_6;
   /** ETH Frames Rx for Segmentation on Channel 6 Counter */
   IFX_uint32_t Counter_7;
   /** ETH Frames Rx for Segmentation on Channel 7 Counter */
   IFX_uint32_t Counter_8;
   /** ETH Frames Rx with Default VCC Matching Counter */
   IFX_uint32_t Counter_9;
   /** ATM Cell Counter Channel 0 */
   IFX_uint32_t Counter_10;
   /** ATM Cell Counter Channel 1 */
   IFX_uint32_t Counter_11;
   /** ATM Cell Counter Channel 2 */
   IFX_uint32_t Counter_12;
   /** ATM Cell Counter Channel 3 */
   IFX_uint32_t Counter_13;
   /** ATM Cell Counter Channel 4 */
   IFX_uint32_t Counter_14;
   /** ATM Cell Counter Channel 5 */
   IFX_uint32_t Counter_15;
   /** ATM Cell Counter Channel 6 */
   IFX_uint32_t Counter_16;
   /** ATM Cell Counter Channel 7 */
   IFX_uint32_t Counter_17;
   /** ATM Cell Counter Default Channel */
   IFX_uint32_t Counter_18;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** ETH Frames Rx without VCC Matching Counter */
   IFX_uint32_t Counter_0;
   /** ETH Frames Rx for Segmentation on Channel 0 Counter */
   IFX_uint32_t Counter_1;
   /** ETH Frames Rx for Segmentation on Channel 1 Counter */
   IFX_uint32_t Counter_2;
   /** ETH Frames Rx for Segmentation on Channel 2 Counter */
   IFX_uint32_t Counter_3;
   /** ETH Frames Rx for Segmentation on Channel 3 Counter */
   IFX_uint32_t Counter_4;
   /** ETH Frames Rx for Segmentation on Channel 4 Counter */
   IFX_uint32_t Counter_5;
   /** ETH Frames Rx for Segmentation on Channel 5 Counter */
   IFX_uint32_t Counter_6;
   /** ETH Frames Rx for Segmentation on Channel 6 Counter */
   IFX_uint32_t Counter_7;
   /** ETH Frames Rx for Segmentation on Channel 7 Counter */
   IFX_uint32_t Counter_8;
   /** ETH Frames Rx with Default VCC Matching Counter */
   IFX_uint32_t Counter_9;
   /** ATM Cell Counter Channel 0 */
   IFX_uint32_t Counter_10;
   /** ATM Cell Counter Channel 1 */
   IFX_uint32_t Counter_11;
   /** ATM Cell Counter Channel 2 */
   IFX_uint32_t Counter_12;
   /** ATM Cell Counter Channel 3 */
   IFX_uint32_t Counter_13;
   /** ATM Cell Counter Channel 4 */
   IFX_uint32_t Counter_14;
   /** ATM Cell Counter Channel 5 */
   IFX_uint32_t Counter_15;
   /** ATM Cell Counter Channel 6 */
   IFX_uint32_t Counter_16;
   /** ATM Cell Counter Channel 7 */
   IFX_uint32_t Counter_17;
   /** ATM Cell Counter Default Channel */
   IFX_uint32_t Counter_18;
#endif
} __PACKED__ ;


/**
   This command requests the performance monitoring parameters for the AAL5 Reassembly
   section 1.
*/
struct CMD_AAL5_Reassembly1_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the performance monitoring counters for AAL5 Reassembly
   section 1. All counters are delta counters (the delta value from the last get) and
   are wrap around. For channel to VPI/VCI mapping see message
   CMD_Reassembly_MappingGet.
*/
struct ACK_AAL5_Reassembly1_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** CRC Error Counter Channel 0 */
   IFX_uint32_t Counter_0;
   /** CRC Error Counter Channel 1 */
   IFX_uint32_t Counter_1;
   /** CRC Error Counter Channel 2 */
   IFX_uint32_t Counter_2;
   /** CRC Error Counter Channel 3 */
   IFX_uint32_t Counter_3;
   /** CRC Error Counter Channel 4 */
   IFX_uint32_t Counter_4;
   /** CRC Error Counter Channel 5 */
   IFX_uint32_t Counter_5;
   /** CRC Error Counter Channel 6 */
   IFX_uint32_t Counter_6;
   /** CRC Error Counter Channel 7 */
   IFX_uint32_t Counter_7;
   /** Reassembled ETH Frames Tx Counter Channel 0 */
   IFX_uint32_t Counter_8;
   /** Reassembled ETH Frames Tx Counter Channel 1 */
   IFX_uint32_t Counter_9;
   /** Reassembled ETH Frames Tx Counter Channel 2 */
   IFX_uint32_t Counter_10;
   /** Reassembled ETH Frames Tx Counter Channel 3 */
   IFX_uint32_t Counter_11;
   /** Reassembled ETH Frames Tx Counter Channel 4 */
   IFX_uint32_t Counter_12;
   /** Reassembled ETH Frames Tx Counter Channel 5 */
   IFX_uint32_t Counter_13;
   /** Reassembled ETH Frames Tx Counter Channel 6 */
   IFX_uint32_t Counter_14;
   /** Reassembled ETH Frames Tx Counter Channel 7 */
   IFX_uint32_t Counter_15;
   /** Reassembly ATM Cell Counter Channel 0 */
   IFX_uint32_t Counter_16;
   /** Reassembly ATM Cell Counter Channel 1 */
   IFX_uint32_t Counter_17;
   /** Reassembly ATM Cell Counter Channel 2 */
   IFX_uint32_t Counter_18;
   /** Reassembly ATM Cell Counter Channel 3 */
   IFX_uint32_t Counter_19;
   /** Reassembly ATM Cell Counter Channel 4 */
   IFX_uint32_t Counter_20;
   /** Reassembly ATM Cell Counter Channel 5 */
   IFX_uint32_t Counter_21;
   /** Reassembly ATM Cell Counter Channel 6 */
   IFX_uint32_t Counter_22;
   /** Reassembly ATM Cell Counter Channel 7 */
   IFX_uint32_t Counter_23;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** CRC Error Counter Channel 0 */
   IFX_uint32_t Counter_0;
   /** CRC Error Counter Channel 1 */
   IFX_uint32_t Counter_1;
   /** CRC Error Counter Channel 2 */
   IFX_uint32_t Counter_2;
   /** CRC Error Counter Channel 3 */
   IFX_uint32_t Counter_3;
   /** CRC Error Counter Channel 4 */
   IFX_uint32_t Counter_4;
   /** CRC Error Counter Channel 5 */
   IFX_uint32_t Counter_5;
   /** CRC Error Counter Channel 6 */
   IFX_uint32_t Counter_6;
   /** CRC Error Counter Channel 7 */
   IFX_uint32_t Counter_7;
   /** Reassembled ETH Frames Tx Counter Channel 0 */
   IFX_uint32_t Counter_8;
   /** Reassembled ETH Frames Tx Counter Channel 1 */
   IFX_uint32_t Counter_9;
   /** Reassembled ETH Frames Tx Counter Channel 2 */
   IFX_uint32_t Counter_10;
   /** Reassembled ETH Frames Tx Counter Channel 3 */
   IFX_uint32_t Counter_11;
   /** Reassembled ETH Frames Tx Counter Channel 4 */
   IFX_uint32_t Counter_12;
   /** Reassembled ETH Frames Tx Counter Channel 5 */
   IFX_uint32_t Counter_13;
   /** Reassembled ETH Frames Tx Counter Channel 6 */
   IFX_uint32_t Counter_14;
   /** Reassembled ETH Frames Tx Counter Channel 7 */
   IFX_uint32_t Counter_15;
   /** Reassembly ATM Cell Counter Channel 0 */
   IFX_uint32_t Counter_16;
   /** Reassembly ATM Cell Counter Channel 1 */
   IFX_uint32_t Counter_17;
   /** Reassembly ATM Cell Counter Channel 2 */
   IFX_uint32_t Counter_18;
   /** Reassembly ATM Cell Counter Channel 3 */
   IFX_uint32_t Counter_19;
   /** Reassembly ATM Cell Counter Channel 4 */
   IFX_uint32_t Counter_20;
   /** Reassembly ATM Cell Counter Channel 5 */
   IFX_uint32_t Counter_21;
   /** Reassembly ATM Cell Counter Channel 6 */
   IFX_uint32_t Counter_22;
   /** Reassembly ATM Cell Counter Channel 7 */
   IFX_uint32_t Counter_23;
#endif
} __PACKED__ ;


/**
   This command requests the performance monitoring parameters for the AAL5 Reassembly
   section 2.
*/
struct CMD_AAL5_Reassembly2_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the performance monitoring counters for AAL5 Reassembly
   section 2. All counters are delta counters (the delta value from the last get) and
   are wrap around. For channel to VPI/VCI mapping see message
   CMD_Reassembly_MappingGet.
*/
struct ACK_AAL5_Reassembly2_PM_ParamGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** ATM Cell Drop due to invalid VPI/VCI Counter */
   IFX_uint32_t Counter_0;
   /** Multiple match of VPI/VCI Counter */
   IFX_uint32_t Counter_1;
   /** ETH Frame Drop due to invalid LLC Counter */
   IFX_uint32_t Counter_2;
   /** ETH Max Frame Length Mismatch Counter Channel 0 */
   IFX_uint32_t Counter_3;
   /** ETH Max Frame Length Mismatch Counter Channel 1 */
   IFX_uint32_t Counter_4;
   /** ETH Max Frame Length Mismatch Counter Channel 2 */
   IFX_uint32_t Counter_5;
   /** ETH Max Frame Length Mismatch Counter Channel 3 */
   IFX_uint32_t Counter_6;
   /** ETH Max Frame Length Mismatch Counter Channel 4 */
   IFX_uint32_t Counter_7;
   /** ETH Max Frame Length Mismatch Counter Channel 5 */
   IFX_uint32_t Counter_8;
   /** ETH Max Frame Length Mismatch Counter Channel 6 */
   IFX_uint32_t Counter_9;
   /** ETH Max Frame Length Mismatch Counter Channel 7 */
   IFX_uint32_t Counter_10;
   /** ETH Zero Length Packet Counter Channel 0 */
   IFX_uint32_t Counter_11;
   /** ETH Zero Length Packet Counter Channel 1 */
   IFX_uint32_t Counter_12;
   /** ETH Zero Length Packet Counter Channel 2 */
   IFX_uint32_t Counter_13;
   /** ETH Zero Length Packet Counter Channel 3 */
   IFX_uint32_t Counter_14;
   /** ETH Zero Length Packet Counter Channel 4 */
   IFX_uint32_t Counter_15;
   /** ETH Zero Length Packet Counter Channel 5 */
   IFX_uint32_t Counter_16;
   /** ETH Zero Length Packet Counter Channel 6 */
   IFX_uint32_t Counter_17;
   /** ETH Zero Length Packet Counter Channel 7 */
   IFX_uint32_t Counter_18;
   /** ETH Frame Rx Length Mismatch Counter Channel 0 */
   IFX_uint32_t Counter_19;
   /** ETH Frame Rx Length Mismatch Counter Channel 1 */
   IFX_uint32_t Counter_20;
   /** ETH Frame Rx Length Mismatch Counter Channel 2 */
   IFX_uint32_t Counter_21;
   /** ETH Frame Rx Length Mismatch Counter Channel 3 */
   IFX_uint32_t Counter_22;
   /** ETH Frame Rx Length Mismatch Counter Channel 4 */
   IFX_uint32_t Counter_23;
   /** ETH Frame Rx Length Mismatch Counter Channel 5 */
   IFX_uint32_t Counter_24;
   /** ETH Frame Rx Length Mismatch Counter Channel 6 */
   IFX_uint32_t Counter_25;
   /** ETH Frame Rx Length Mismatch Counter Channel 7 */
   IFX_uint32_t Counter_26;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Counter Status */
   IFX_uint32_t Status;
   /** ATM Cell Drop due to invalid VPI/VCI Counter */
   IFX_uint32_t Counter_0;
   /** Multiple match of VPI/VCI Counter */
   IFX_uint32_t Counter_1;
   /** ETH Frame Drop due to invalid LLC Counter */
   IFX_uint32_t Counter_2;
   /** ETH Max Frame Length Mismatch Counter Channel 0 */
   IFX_uint32_t Counter_3;
   /** ETH Max Frame Length Mismatch Counter Channel 1 */
   IFX_uint32_t Counter_4;
   /** ETH Max Frame Length Mismatch Counter Channel 2 */
   IFX_uint32_t Counter_5;
   /** ETH Max Frame Length Mismatch Counter Channel 3 */
   IFX_uint32_t Counter_6;
   /** ETH Max Frame Length Mismatch Counter Channel 4 */
   IFX_uint32_t Counter_7;
   /** ETH Max Frame Length Mismatch Counter Channel 5 */
   IFX_uint32_t Counter_8;
   /** ETH Max Frame Length Mismatch Counter Channel 6 */
   IFX_uint32_t Counter_9;
   /** ETH Max Frame Length Mismatch Counter Channel 7 */
   IFX_uint32_t Counter_10;
   /** ETH Zero Length Packet Counter Channel 0 */
   IFX_uint32_t Counter_11;
   /** ETH Zero Length Packet Counter Channel 1 */
   IFX_uint32_t Counter_12;
   /** ETH Zero Length Packet Counter Channel 2 */
   IFX_uint32_t Counter_13;
   /** ETH Zero Length Packet Counter Channel 3 */
   IFX_uint32_t Counter_14;
   /** ETH Zero Length Packet Counter Channel 4 */
   IFX_uint32_t Counter_15;
   /** ETH Zero Length Packet Counter Channel 5 */
   IFX_uint32_t Counter_16;
   /** ETH Zero Length Packet Counter Channel 6 */
   IFX_uint32_t Counter_17;
   /** ETH Zero Length Packet Counter Channel 7 */
   IFX_uint32_t Counter_18;
   /** ETH Frame Rx Length Mismatch Counter Channel 0 */
   IFX_uint32_t Counter_19;
   /** ETH Frame Rx Length Mismatch Counter Channel 1 */
   IFX_uint32_t Counter_20;
   /** ETH Frame Rx Length Mismatch Counter Channel 2 */
   IFX_uint32_t Counter_21;
   /** ETH Frame Rx Length Mismatch Counter Channel 3 */
   IFX_uint32_t Counter_22;
   /** ETH Frame Rx Length Mismatch Counter Channel 4 */
   IFX_uint32_t Counter_23;
   /** ETH Frame Rx Length Mismatch Counter Channel 5 */
   IFX_uint32_t Counter_24;
   /** ETH Frame Rx Length Mismatch Counter Channel 6 */
   IFX_uint32_t Counter_25;
   /** ETH Frame Rx Length Mismatch Counter Channel 7 */
   IFX_uint32_t Counter_26;
#endif
} __PACKED__ ;


/**
   This command requests the mapping between reassembly channels (0..7) and ATM cell
   header (VPI/VCI combination) that is used for comparison of incoming ATM cells.
*/
struct CMD_Reassembly_MappingGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This acknowledgement returns the VPI/VCI entries for the reassembly channels that
   are used for comparison with the headers of incoming ATM cells.
*/
struct ACK_Reassembly_MappingGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VPI/VCI Entry Channel 0 */
   IFX_uint32_t Channel_0;
   /** VPI/VCI Entry Channel 1 */
   IFX_uint32_t Channel_1;
   /** VPI/VCI Entry Channel 2 */
   IFX_uint32_t Channel_2;
   /** VPI/VCI Entry Channel 3 */
   IFX_uint32_t Channel_3;
   /** VPI/VCI Entry Channel 4 */
   IFX_uint32_t Channel_4;
   /** VPI/VCI Entry Channel 5 */
   IFX_uint32_t Channel_5;
   /** VPI/VCI Entry Channel 6 */
   IFX_uint32_t Channel_6;
   /** VPI/VCI Entry Channel 7 */
   IFX_uint32_t Channel_7;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** VPI/VCI Entry Channel 0 */
   IFX_uint32_t Channel_0;
   /** VPI/VCI Entry Channel 1 */
   IFX_uint32_t Channel_1;
   /** VPI/VCI Entry Channel 2 */
   IFX_uint32_t Channel_2;
   /** VPI/VCI Entry Channel 3 */
   IFX_uint32_t Channel_3;
   /** VPI/VCI Entry Channel 4 */
   IFX_uint32_t Channel_4;
   /** VPI/VCI Entry Channel 5 */
   IFX_uint32_t Channel_5;
   /** VPI/VCI Entry Channel 6 */
   IFX_uint32_t Channel_6;
   /** VPI/VCI Entry Channel 7 */
   IFX_uint32_t Channel_7;
#endif
} __PACKED__ ;


/**
   This data structure defines the Ethernet OAM flags field used in the following
   messages
*/
struct Ethernet_OAM_Flags
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link Fault */
   IFX_uint32_t LinkFault : 1;
   /** Dying Gasp */
   IFX_uint32_t DyingGasp : 1;
   /** Critical Event */
   IFX_uint32_t CriticalEvent : 1;
   /** Local Discovery State */
   IFX_uint32_t L_DiscoveryState : 2;
   /** Remote Discovery State */
   IFX_uint32_t R_DiscoveryState : 2;
   /** Reserved for Future use */
   IFX_uint32_t Res05 : 9;
   /** Not Used */
   IFX_uint32_t NotUsed : 16;
#else
   /** Not Used */
   IFX_uint32_t NotUsed : 16;
   /** Reserved for Future use */
   IFX_uint32_t Res05 : 9;
   /** Remote Discovery State */
   IFX_uint32_t R_DiscoveryState : 2;
   /** Local Discovery State */
   IFX_uint32_t L_DiscoveryState : 2;
   /** Critical Event */
   IFX_uint32_t CriticalEvent : 1;
   /** Dying Gasp */
   IFX_uint32_t DyingGasp : 1;
   /** Link Fault */
   IFX_uint32_t LinkFault : 1;
#endif
} __PACKED__ ;


/**
   This command enables/disables the Ethernet OAM functionality, the device must be in
   MAC mode and the TC layer must be EFM.
*/
struct CMD_Ethernet_OAM_Control
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Ethernet OAM Select */
   IFX_uint32_t OAM;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Ethernet OAM Select */
   IFX_uint32_t OAM;
#endif
} __PACKED__ ;


/**
   This command is used to transfer an OAMPDU to a peer OAM client entity, Ethernet OAM
   must be enabled before this command can be sent.
*/
struct CMD_Ethernet_OAMPDU_Request
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** OAMPDU Code Field */
   IFX_uint32_t Code;
   /** Data */
   IFX_uint32_t Data[25];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** OAMPDU Code Field */
   IFX_uint32_t Code;
   /** Data */
   IFX_uint32_t Data[25];
#endif
} __PACKED__ ;


/**
   This event indicates the arrival of OAMPDU which is not processed by the local IDC
   Ethernet OAM process, the device must be in MAC mode, the TC layer must be EFM and
   Ethernet OAM must be enabled.
*/
struct EVT_Ethernet_OAMPDU_Indication
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Flags Field */
   IFX_uint32_t Flags;
   /** OAMPDU Code Field */
   IFX_uint32_t Code;
   /** Source Address */
   IFX_uint32_t SA[2];
   /** Data */
   IFX_uint32_t Data[25];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Flags Field */
   IFX_uint32_t Flags;
   /** OAMPDU Code Field */
   IFX_uint32_t Code;
   /** Source Address */
   IFX_uint32_t SA[2];
   /** Data */
   IFX_uint32_t Data[25];
#endif
} __PACKED__ ;


/**
   This command is used to transfer an OAM_CTL to a peer OAM client entity, Ethernet
   OAM must be enabled before this command can be sent.
*/
struct CMD_Ethernet_OAM_CTL_Request
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Unspecified Critical Event Condition at DTE */
   IFX_uint32_t local_critical_event;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Unspecified Critical Event Condition at DTE */
   IFX_uint32_t local_critical_event;
#endif
} __PACKED__ ;


/**
   This event indicates local state information has changed, the event will only be
   generated when the ethernet OAM is enabled and an host is present.
*/
struct EVT_Ethernet_OAM_CTL_Indication
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Local PDU State */
   IFX_uint32_t local_pdu;
   /** Local Stable Status */
   IFX_uint32_t local_stable;
   /** Local Lost Link Timer Done */
   IFX_uint32_t local_lost_link_timer_done;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Local PDU State */
   IFX_uint32_t local_pdu;
   /** Local Stable Status */
   IFX_uint32_t local_stable;
   /** Local Lost Link Timer Done */
   IFX_uint32_t local_lost_link_timer_done;
#endif
} __PACKED__ ;


/**
   This command enables/disables the generation of events when the OAM discovery,
   Transmit and Multiplexer state machine changes, the device must be in MAC mode and
   the TC layer must be EFM.
*/
struct CMD_Ethernet_OAM_StateEventControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Discovery State Machine Event Control */
   IFX_uint32_t DiscoverySM;
   /** Transmit State Machine Event Control */
   IFX_uint32_t TransmitSM;
   /** Multiplexer State Machine Event Control */
   IFX_uint32_t MultiplexerSM;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Discovery State Machine Event Control */
   IFX_uint32_t DiscoverySM;
   /** Transmit State Machine Event Control */
   IFX_uint32_t TransmitSM;
   /** Multiplexer State Machine Event Control */
   IFX_uint32_t MultiplexerSM;
#endif
} __PACKED__ ;


/**
   This command get the current OAM discovery, Transmit and Multiplexer state machine
   states, the device must be in MAC mode and the TC layer must be EFM.
*/
struct CMD_Ethernet_OAM_StateGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This contains the current state of the OAM Discovery, Transmit and Multiplexer state
   machines, the device must be in MAC mode, the TC layer must be EFM and ethernet OAM
   must be enabled.
*/
struct ACK_Ethernet_OAM_StateGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Discovery State */
   IFX_uint32_t DiscoveryState;
   /** Transmit State */
   IFX_uint32_t TransmitState;
   /** Multiplexer State */
   IFX_uint32_t MultiplexerState;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Discovery State */
   IFX_uint32_t DiscoveryState;
   /** Transmit State */
   IFX_uint32_t TransmitState;
   /** Multiplexer State */
   IFX_uint32_t MultiplexerState;
#endif
} __PACKED__ ;


/**
   This event indicates local Discovery state has changed, the event will only be
   generated when the Ethernet OAM is enabled and an host is present.
*/
struct EVT_Ethernet_OAM_DiscoveryStateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Discovery State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Discovery State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This event indicates local Transmit state has changed, the event will only be
   generated when the ethernet OAM is enabled and an host is present.
*/
struct EVT_Ethernet_OAM_TransmitStateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Transmit State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This event indicates local Multiplexer state has changed, the event will only be
   generated when the ethernet OAM is enabled and an host is present.
*/
struct EVT_Ethernet_OAM_MultiplexerStateChange
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Multiplexer State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Multiplexer State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


/**
   This command enables/disables the ethernet insert/extract to the system/line side.
*/
struct CMD_EthernetInsertExtractControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
   /** System or Line Side */
   IFX_uint32_t Side;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Control */
   IFX_uint32_t Control;
   /** System or Line Side */
   IFX_uint32_t Side;
#endif
} __PACKED__ ;


/**
   This command inserts an ethernet frame or fragment to the system side in receive
   direction.
*/
struct CMD_EthernetFrameInsertSystem
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Length of the Ethernet Frame or Last Fragment */
   IFX_uint32_t Length;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
   /** Octets 108:111 */
   IFX_uint32_t Octets_108_111;
   /** Octets 112:115 */
   IFX_uint32_t Octets_112_115;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Length of the Ethernet Frame or Last Fragment */
   IFX_uint32_t Length;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
   /** Octets 108:111 */
   IFX_uint32_t Octets_108_111;
   /** Octets 112:115 */
   IFX_uint32_t Octets_112_115;
#endif
} __PACKED__ ;


/**
   This command inserts an ethernet frame or fragment to the Line side in transmit
   direction.
*/
struct CMD_EthernetFrameInsertLine
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Length of the Ethernet Frame or Last Fragment */
   IFX_uint32_t Length;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
   /** Octets 108:111 */
   IFX_uint32_t Octets_108_111;
   /** Octets 112:115 */
   IFX_uint32_t Octets_112_115;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Length of the Ethernet Frame or Last Fragment */
   IFX_uint32_t Length;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
   /** Octets 108:111 */
   IFX_uint32_t Octets_108_111;
   /** Octets 112:115 */
   IFX_uint32_t Octets_112_115;
#endif
} __PACKED__ ;


/**
   This event indicates the insertion of an ethernet frame into the Line or system
   side.
*/
struct EVT_EthernetFrameInserted
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line Side Indication */
   IFX_uint32_t Side;
   /** Length of the Inserted Frame */
   IFX_uint32_t Length;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** System or Line Side Indication */
   IFX_uint32_t Side;
   /** Length of the Inserted Frame */
   IFX_uint32_t Length;
#endif
} __PACKED__ ;


/**
   This event indicates the extraction of an ethernet frame from the system side in
   transmit direction.
*/
struct EVT_EthernetFrameExtractSystem
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the Last Fragment */
   IFX_uint32_t Length;
   /** Filter Match */
   IFX_uint32_t FilterMatch;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the Last Fragment */
   IFX_uint32_t Length;
   /** Filter Match */
   IFX_uint32_t FilterMatch;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
#endif
} __PACKED__ ;


/**
   This event indicates the extraction of an ethernet frame from the line side in
   receive direction.
*/
struct EVT_EthernetFrameExtractLine
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the Last Fragment */
   IFX_uint32_t Length;
   /** Filter Match */
   IFX_uint32_t FilterMatch;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Start of Frame End of Frame Indication */
   IFX_uint32_t SOF_EOF;
   /** Length of the Last Fragment */
   IFX_uint32_t Length;
   /** Filter Match */
   IFX_uint32_t FilterMatch;
   /** Octets 0:3 */
   IFX_uint32_t Octets_0_3;
   /** Octets 4:7 */
   IFX_uint32_t Octets_4_7;
   /** Octets 8:11 */
   IFX_uint32_t Octets_8_11;
   /** Octets 12:15 */
   IFX_uint32_t Octets_12_15;
   /** Octets 16:19 */
   IFX_uint32_t Octets_16_19;
   /** Octets 20:23 */
   IFX_uint32_t Octets_20_23;
   /** Octets 24:27 */
   IFX_uint32_t Octets_24_27;
   /** Octets 28:31 */
   IFX_uint32_t Octets_28_31;
   /** Octets 32:35 */
   IFX_uint32_t Octets_32_35;
   /** Octets 36:39 */
   IFX_uint32_t Octets_36_39;
   /** Octets 40:43 */
   IFX_uint32_t Octets_40_43;
   /** Octets 44:47 */
   IFX_uint32_t Octets_44_47;
   /** Octets 48:51 */
   IFX_uint32_t Octets_48_51;
   /** Octets 52:55 */
   IFX_uint32_t Octets_52_55;
   /** Octets 56:59 */
   IFX_uint32_t Octets_56_59;
   /** Octets 60:63 */
   IFX_uint32_t Octets_60_63;
   /** Octets 64:67 */
   IFX_uint32_t Octets_64_67;
   /** Octets 68:71 */
   IFX_uint32_t Octets_68_71;
   /** Octets 72:75 */
   IFX_uint32_t Octets_72_75;
   /** Octets 76:79 */
   IFX_uint32_t Octets_76_79;
   /** Octets 80:83 */
   IFX_uint32_t Octets_80_83;
   /** Octets 84:87 */
   IFX_uint32_t Octets_84_87;
   /** Octets 88:91 */
   IFX_uint32_t Octets_88_91;
   /** Octets 92:95 */
   IFX_uint32_t Octets_92_95;
   /** Octets 96:99 */
   IFX_uint32_t Octets_96_99;
   /** Octets 100:103 */
   IFX_uint32_t Octets_100_103;
   /** Octets 104:107 */
   IFX_uint32_t Octets_104_107;
#endif
} __PACKED__ ;


/**
   This event indicates if the sync state of the local or the remote EFM-TC changed.
*/
struct EVT_EFM_TC_SyncStateChanged
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Synchronization state of the local EFM-TC */
   IFX_uint32_t LocalSync;
   /** Synchronization state of the remote EFM-TC */
   IFX_uint32_t RemoteSync;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Synchronization state of the local EFM-TC */
   IFX_uint32_t LocalSync;
   /** Synchronization state of the remote EFM-TC */
   IFX_uint32_t RemoteSync;
#endif
} __PACKED__ ;


/**
   This command enables/disables EOC handling for a link.
*/
struct CMD_EOC_Control
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Control */
   IFX_uint32_t Control;
   /** EOC Mode */
   IFX_uint32_t Mode;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusMode;
   /** EOC Force Marker for Performance Status Mode 2 */
   IFX_uint32_t ForcePerfStatusMarker;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Control */
   IFX_uint32_t Control;
   /** EOC Mode */
   IFX_uint32_t Mode;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusMode;
   /** EOC Force Marker for Performance Status Mode 2 */
   IFX_uint32_t ForcePerfStatusMarker;
#endif
} __PACKED__ ;


/**
   This command defines the time period for performance status collection via the EOC
   channel.
*/
struct CMD_EOC_StatusRequestControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Status Period */
   IFX_uint32_t StatusPeriod;
   /** ATM Status Period */
   IFX_uint32_t ATM_StatusPeriod;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Status Period */
   IFX_uint32_t StatusPeriod;
   /** ATM Status Period */
   IFX_uint32_t ATM_StatusPeriod;
#endif
} __PACKED__ ;


/**
   Read the EOC configuration for a link.
*/
struct CMD_EOC_ConfigGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_EOC_ConfigGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Control */
   IFX_uint32_t Control;
   /** EOC Mode */
   IFX_uint32_t Mode;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusModeCfg;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusModeAct;
   /** EOC Force Marker for Performance Status Mode 2 */
   IFX_uint32_t ForcePerfStatusMarker;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Control */
   IFX_uint32_t Control;
   /** EOC Mode */
   IFX_uint32_t Mode;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusModeCfg;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusModeAct;
   /** EOC Force Marker for Performance Status Mode 2 */
   IFX_uint32_t ForcePerfStatusMarker;
#endif
} __PACKED__ ;


/**
   Event to inform the host about EOC configuration changes.
*/
struct EVT_EOC_Config
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusModeAct;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Performance Status Mode */
   IFX_uint32_t PerfStatusModeAct;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_TDM_Get_SDI_Settings
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
#else
   /** SDI side selection */
   IFX_uint32_t side;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_TDM_Get_SDI_Settings
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Clock mode for SDI input */
   IFX_uint32_t input_mode;
   /** Clock mode for SDI output */
   IFX_uint32_t output_mode;
   /** SDI Frequency */
   IFX_uint32_t frequency;
   /** Payload Bit Rate in kbits per second */
   IFX_uint32_t payload_bits;
   /** Frames per multiframe */
   IFX_uint32_t frames;
   /** Loop Selection */
   IFX_uint32_t loop;
   /** External 8k clock */
   IFX_uint32_t ext_clk8k;
   /** DPLL activation */
   IFX_uint32_t dpll4bclk;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t TX_data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t TX_frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t TX_sp_level;
   /** SP and MSP sampling edge */
   IFX_uint32_t TX_sp_sample_edg;
   /** Data sampling edge */
   IFX_uint32_t TX_data_sample_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t TX_lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t TX_slip_mode;
   /** Data delay independent of payload rate */
   IFX_uint32_t TX_align;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t RX_data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t RX_frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t RX_sp_level;
   /** Driving edge for DATA, SP and MSP */
   IFX_uint32_t RX_driving_edg;
   /** Data shift edge */
   IFX_uint32_t RX_data_shift_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t RX_lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t RX_slip_mode;
   /** Data delay independent of payload rate */
   IFX_uint32_t RX_align;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Clock mode for SDI input */
   IFX_uint32_t input_mode;
   /** Clock mode for SDI output */
   IFX_uint32_t output_mode;
   /** SDI Frequency */
   IFX_uint32_t frequency;
   /** Payload Bit Rate in kbits per second */
   IFX_uint32_t payload_bits;
   /** Frames per multiframe */
   IFX_uint32_t frames;
   /** Loop Selection */
   IFX_uint32_t loop;
   /** External 8k clock */
   IFX_uint32_t ext_clk8k;
   /** DPLL activation */
   IFX_uint32_t dpll4bclk;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t TX_data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t TX_frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t TX_sp_level;
   /** SP and MSP sampling edge */
   IFX_uint32_t TX_sp_sample_edg;
   /** Data sampling edge */
   IFX_uint32_t TX_data_sample_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t TX_lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t TX_slip_mode;
   /** Data delay independent of payload rate */
   IFX_uint32_t TX_align;
   /** Data shift referring to SP (8kHz) in bits */
   IFX_uint32_t RX_data_shift;
   /** Data shift referring to MSP (166 Hz) in SP frames */
   IFX_uint32_t RX_frame_shift;
   /** SP and MSP active level */
   IFX_uint32_t RX_sp_level;
   /** Driving edge for DATA, SP and MSP */
   IFX_uint32_t RX_driving_edg;
   /** Data shift edge */
   IFX_uint32_t RX_data_shift_edg;
   /** Write to Read delay in Slip buffer */
   IFX_uint32_t RX_lstwr_1strd_dly;
   /** Setting for slip buffers */
   IFX_uint32_t RX_slip_mode;
   /** Data delay independent of payload rate */
   IFX_uint32_t RX_align;
#endif
} __PACKED__ ;


/**
   
*/
struct NFC_TDM_Get_SDI_Settings
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** SDI side selection */
   IFX_uint32_t side;
   /** Number of interleaving channels */
   IFX_uint32_t TX_il_ch_cnt;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t TX_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t TX_il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t TX_special_mode;
   /** Number of interleaving channels */
   IFX_uint32_t RX_il_ch_cnt;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t RX_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t RX_il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t RX_special_mode;
   /** Frame Reset */
   IFX_uint32_t fram_rst;
   /** Frame Sync */
   IFX_uint32_t fram_sync;
#else
   /** SDI side selection */
   IFX_uint32_t side;
   /** Number of interleaving channels */
   IFX_uint32_t TX_il_ch_cnt;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t TX_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t TX_il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t TX_special_mode;
   /** Number of interleaving channels */
   IFX_uint32_t RX_il_ch_cnt;
   /** Number of the interleaving channel occupied by the current PAMDSL channel */
   IFX_uint32_t RX_il_ch;
   /** Interleaving channel granularity */
   IFX_uint32_t RX_il_ch_gr;
   /** Special frame settings like Z-Bit aligned mode */
   IFX_uint32_t RX_special_mode;
   /** Frame Reset */
   IFX_uint32_t fram_rst;
   /** Frame Sync */
   IFX_uint32_t fram_sync;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_TDM_Get_PMD_Settings
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** TDM Mode */
   IFX_uint32_t Mode;
   /** Interleaving Mode */
   IFX_uint32_t InterleavingMode;
   /** Total Payload */
   IFX_uint32_t Payload;
   /** Link 0 Payload */
   IFX_uint32_t L0_Payload;
   /** Link 0 Data Shift */
   IFX_uint32_t L0_DataShift;
   /** Link 0 Valid Data Slots */
   IFX_uint32_t L0_ValidSlots;
   /** Link 0 Interleaving Channel Count */
   IFX_uint32_t L0_IL_CH_Cnt;
   /** Link 0 Active Interleaving Channel */
   IFX_uint32_t L0_Active_IL_Ch;
   /** Link 0 Number of Zbits */
   IFX_uint32_t L0_Zbits;
   /** Link 0 Z bit Alignment */
   IFX_uint32_t L0_Align;
   /** Link 1 Payload */
   IFX_uint32_t L1_Payload;
   /** Link 1 Data Shift */
   IFX_uint32_t L1_DataShift;
   /** Link 1 Valid Data Slots */
   IFX_uint32_t L1_ValidSlots;
   /** Link 1 Interleaving Channel Count */
   IFX_uint32_t L1_IL_CH_Cnt;
   /** Link 1 Active Interleaving Channel */
   IFX_uint32_t L1_Active_IL_Ch;
   /** Link 1 Number of Zbits */
   IFX_uint32_t L1_Zbits;
   /** Link 1 Z bit Alignment */
   IFX_uint32_t L1_Align;
   /** Link 2 Payload */
   IFX_uint32_t L2_Payload;
   /** Link 2 Data Shift */
   IFX_uint32_t L2_DataShift;
   /** Link 2 Valid Data Slots */
   IFX_uint32_t L2_ValidSlots;
   /** Link 2 Interleaving Channel Count */
   IFX_uint32_t L2_IL_CH_Cnt;
   /** Link 2 Active Interleaving Channel */
   IFX_uint32_t L2_Active_IL_Ch;
   /** Link 2 Number of Zbits */
   IFX_uint32_t L2_Zbits;
   /** Link 2 Z bit Alignment */
   IFX_uint32_t L2_Align;
   /** Link 3 Payload */
   IFX_uint32_t L3_Payload;
   /** Link 3 Data Shift */
   IFX_uint32_t L3_DataShift;
   /** Link 3 Valid Data Slots */
   IFX_uint32_t L3_ValidSlots;
   /** Link 3 Interleaving Channel Count */
   IFX_uint32_t L3_IL_CH_Cnt;
   /** Link 3 Active Interleaving Channel */
   IFX_uint32_t L3_Active_IL_Ch;
   /** Link 3 Number of Zbits */
   IFX_uint32_t L3_Zbits;
   /** Link 3 Z bit Alignment */
   IFX_uint32_t L3_Align;
#else
   /** TDM Mode */
   IFX_uint32_t Mode;
   /** Interleaving Mode */
   IFX_uint32_t InterleavingMode;
   /** Total Payload */
   IFX_uint32_t Payload;
   /** Link 0 Payload */
   IFX_uint32_t L0_Payload;
   /** Link 0 Data Shift */
   IFX_uint32_t L0_DataShift;
   /** Link 0 Valid Data Slots */
   IFX_uint32_t L0_ValidSlots;
   /** Link 0 Interleaving Channel Count */
   IFX_uint32_t L0_IL_CH_Cnt;
   /** Link 0 Active Interleaving Channel */
   IFX_uint32_t L0_Active_IL_Ch;
   /** Link 0 Number of Zbits */
   IFX_uint32_t L0_Zbits;
   /** Link 0 Z bit Alignment */
   IFX_uint32_t L0_Align;
   /** Link 1 Payload */
   IFX_uint32_t L1_Payload;
   /** Link 1 Data Shift */
   IFX_uint32_t L1_DataShift;
   /** Link 1 Valid Data Slots */
   IFX_uint32_t L1_ValidSlots;
   /** Link 1 Interleaving Channel Count */
   IFX_uint32_t L1_IL_CH_Cnt;
   /** Link 1 Active Interleaving Channel */
   IFX_uint32_t L1_Active_IL_Ch;
   /** Link 1 Number of Zbits */
   IFX_uint32_t L1_Zbits;
   /** Link 1 Z bit Alignment */
   IFX_uint32_t L1_Align;
   /** Link 2 Payload */
   IFX_uint32_t L2_Payload;
   /** Link 2 Data Shift */
   IFX_uint32_t L2_DataShift;
   /** Link 2 Valid Data Slots */
   IFX_uint32_t L2_ValidSlots;
   /** Link 2 Interleaving Channel Count */
   IFX_uint32_t L2_IL_CH_Cnt;
   /** Link 2 Active Interleaving Channel */
   IFX_uint32_t L2_Active_IL_Ch;
   /** Link 2 Number of Zbits */
   IFX_uint32_t L2_Zbits;
   /** Link 2 Z bit Alignment */
   IFX_uint32_t L2_Align;
   /** Link 3 Payload */
   IFX_uint32_t L3_Payload;
   /** Link 3 Data Shift */
   IFX_uint32_t L3_DataShift;
   /** Link 3 Valid Data Slots */
   IFX_uint32_t L3_ValidSlots;
   /** Link 3 Interleaving Channel Count */
   IFX_uint32_t L3_IL_CH_Cnt;
   /** Link 3 Active Interleaving Channel */
   IFX_uint32_t L3_Active_IL_Ch;
   /** Link 3 Number of Zbits */
   IFX_uint32_t L3_Zbits;
   /** Link 3 Z bit Alignment */
   IFX_uint32_t L3_Align;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_TDM_RefPortGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Port Mask */
   IFX_uint32_t Mask;
   /** Reference Port */
   IFX_uint32_t RefPort;
#else
   /** Port Mask */
   IFX_uint32_t Mask;
   /** Reference Port */
   IFX_uint32_t RefPort;
#endif
} __PACKED__ ;


/**
   Select the available reference ports for the receive clocking of the TDM interface.
*/
struct CMD_TDM_RefPortSet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Port Mask */
   IFX_uint32_t Mask;
#else
   /** Port Mask */
   IFX_uint32_t Mask;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_DbgGetPDI_Short
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t Register;
   /** Module */
   IFX_uint32_t Module;
   /** Slice */
   IFX_uint32_t Slice;
   /** Block */
   IFX_uint32_t Block;
#else
   /** Register */
   IFX_uint32_t Register;
   /** Module */
   IFX_uint32_t Module;
   /** Slice */
   IFX_uint32_t Slice;
   /** Block */
   IFX_uint32_t Block;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_DbgGetPDI_Short
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t Register;
   /** Module */
   IFX_uint32_t Module;
   /** Slice */
   IFX_uint32_t Slice;
   /** Block */
   IFX_uint32_t Block;
   /** Value read from the selected PDI register */
   IFX_uint32_t PdiRegVal;
#else
   /** Register */
   IFX_uint32_t Register;
   /** Module */
   IFX_uint32_t Module;
   /** Slice */
   IFX_uint32_t Slice;
   /** Block */
   IFX_uint32_t Block;
   /** Value read from the selected PDI register */
   IFX_uint32_t PdiRegVal;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_DbgSetPDI_Short
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t Register;
   /** Module */
   IFX_uint32_t Module;
   /** Slice */
   IFX_uint32_t Slice;
   /** Block */
   IFX_uint32_t Block;
   /** Value to be written into selected PDI register */
   IFX_uint32_t PdiRegVal;
#else
   /** Register */
   IFX_uint32_t Register;
   /** Module */
   IFX_uint32_t Module;
   /** Slice */
   IFX_uint32_t Slice;
   /** Block */
   IFX_uint32_t Block;
   /** Value to be written into selected PDI register */
   IFX_uint32_t PdiRegVal;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_DbgGetPDI
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t PdiRegAdr;
#else
   /** Register */
   IFX_uint32_t PdiRegAdr;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_DbgGetPDI
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t PdiRegAdr;
   /** Value read from the selected PDI register */
   IFX_uint32_t PdiRegVal;
#else
   /** Register */
   IFX_uint32_t PdiRegAdr;
   /** Value read from the selected PDI register */
   IFX_uint32_t PdiRegVal;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_DbgSetPDI
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t PdiRegAdr;
   /** Value to be written into selected PDI Register */
   IFX_uint32_t PdiRegVal;
#else
   /** Register */
   IFX_uint32_t PdiRegAdr;
   /** Value to be written into selected PDI Register */
   IFX_uint32_t PdiRegVal;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_DbgGetFPI
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t FpiRegAdr;
#else
   /** Register */
   IFX_uint32_t FpiRegAdr;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_DbgGetFPI
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t FpiRegAdr;
   /** Value read from the selected FPI register */
   IFX_uint32_t FpiRegVal;
#else
   /** Register */
   IFX_uint32_t FpiRegAdr;
   /** Value read from the selected FPI register */
   IFX_uint32_t FpiRegVal;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_DbgSetFPI
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register */
   IFX_uint32_t FpiRegAdr;
   /** Value to be written into selected FPI register value to be written */
   IFX_uint32_t FpiRegVal;
#else
   /** Register */
   IFX_uint32_t FpiRegAdr;
   /** Value to be written into selected FPI register value to be written */
   IFX_uint32_t FpiRegVal;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_PMD_AuxRegWrite
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** AUX Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#else
   /** AUX Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_PMD_AuxRegRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** AUX Register Address */
   IFX_uint32_t RegAddr;
#else
   /** AUX Register Address */
   IFX_uint32_t RegAddr;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Dbg_PMD_AuxRegRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** AUX Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#else
   /** AUX Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_PMD_RS_RegWrite
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** RS Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#else
   /** RS Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   
*/
struct CMD_Dbg_PMD_RS_RegRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** RS Register Address */
   IFX_uint32_t RegAddr;
#else
   /** RS Register Address */
   IFX_uint32_t RegAddr;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_Dbg_PMD_RS_RegRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** RS Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#else
   /** RS Register Address */
   IFX_uint32_t RegAddr;
   /** Register Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This command switches ON / OFF the AUX and Ram Shell register trace, by default the
   trace is diabled.
*/
struct CMD_Dbg_AUX_RS_TraceControl
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** AUX RS Debug Trace Control */
   IFX_uint32_t Control;
#else
   /** AUX RS Debug Trace Control */
   IFX_uint32_t Control;
#endif
} __PACKED__ ;


/**
   This debug trace is generated when the AUX RS trace is enabled.
*/
struct DBG_AUX_RegisterAccess
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register Access */
   IFX_uint32_t Access;
   /** AUX Register */
   IFX_uint32_t Register;
   /** Register Contents */
   IFX_uint32_t Value;
#else
   /** Register Access */
   IFX_uint32_t Access;
   /** AUX Register */
   IFX_uint32_t Register;
   /** Register Contents */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This debug trace is generated when the AUX RS trace is enabled.
*/
struct DBG_RS_RegisterAccess
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Register Access */
   IFX_uint32_t Access;
   /** AUX Register */
   IFX_uint32_t Register;
   /** Register Contents */
   IFX_uint32_t Value;
#else
   /** Register Access */
   IFX_uint32_t Access;
   /** AUX Register */
   IFX_uint32_t Register;
   /** Register Contents */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This command reads counter values from the counter memory.
*/
struct CMD_DbgCounterRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Memory */
   IFX_uint32_t CounterMen;
#else
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Memory */
   IFX_uint32_t CounterMen;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_DbgCounterRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_00;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_01;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_02;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_03;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_04;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_05;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_06;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_07;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_08;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_09;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_10;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_11;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_12;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_13;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_14;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_15;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_16;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_17;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_18;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_19;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_20;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_21;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_22;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_23;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_24;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_25;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_26;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_27;
   /** Reserved */
   IFX_uint32_t Counter_28;
   /** Reserved */
   IFX_uint32_t Counter_29;
   /** Reserved */
   IFX_uint32_t Counter_30;
#else
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_00;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_01;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_02;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_03;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_04;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_05;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_06;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_07;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_08;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_09;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_10;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_11;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_12;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_13;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_14;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_15;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_16;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_17;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_18;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_19;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_20;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_21;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_22;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_23;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_24;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_25;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_26;
   /** Possible counter values depending the counter memory selected: */
   IFX_uint32_t Counter_27;
   /** Reserved */
   IFX_uint32_t Counter_28;
   /** Reserved */
   IFX_uint32_t Counter_29;
   /** Reserved */
   IFX_uint32_t Counter_30;
#endif
} __PACKED__ ;


/**
   This command writes a counter memory location.
*/
struct CMD_DbgCounterMemoryWrite
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Block */
   IFX_uint32_t CounterBlock;
   /** Counter Offset */
   IFX_uint32_t Offset;
   /** Counter Value */
   IFX_uint32_t Value;
#else
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Block */
   IFX_uint32_t CounterBlock;
   /** Counter Offset */
   IFX_uint32_t Offset;
   /** Counter Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This command reads a counter memory location.
*/
struct CMD_DbgCounterMemoryRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Block */
   IFX_uint32_t CounterBlock;
   /** Counter Offset */
   IFX_uint32_t Offset;
#else
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Block */
   IFX_uint32_t CounterBlock;
   /** Counter Offset */
   IFX_uint32_t Offset;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_DbgCounterMemoryRead
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Block */
   IFX_uint32_t CounterBlock;
   /** Counter Offset */
   IFX_uint32_t Offset;
   /** Counter Value */
   IFX_uint32_t Value;
#else
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Counter Block */
   IFX_uint32_t CounterBlock;
   /** Counter Offset */
   IFX_uint32_t Offset;
   /** Counter Value */
   IFX_uint32_t Value;
#endif
} __PACKED__ ;


/**
   This command dumps the contents of the SAR mapping table. For details of the memory
   format see the SAR-AAL5 Design Specification
*/
struct CMD_DbgSAR_MapTableDump
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Command */
   IFX_uint32_t Command;
#else
   /** Link number */
   IFX_uint32_t LinkNo;
   /** Command */
   IFX_uint32_t Command;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_DbgSAR_MapTableDump
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** MAC entry 0 or 8, ATM Header 0 */
   IFX_uint32_t Word_00;
   /** MAC entry 0 or 8, ATM Header 1 */
   IFX_uint32_t Word_01;
   /** MAC entry 1 or 9, ATM Header 2 */
   IFX_uint32_t Word_02;
   /** MAC entry 1 or 9, ATM Header 3 */
   IFX_uint32_t Word_03;
   /** MAC entry 2 or 10, ATM Header 4 */
   IFX_uint32_t Word_04;
   /** MAC entry 2 or 10, ATM Header 5 */
   IFX_uint32_t Word_05;
   /** MAC entry 3 or 11, ATM Header 6 */
   IFX_uint32_t Word_06;
   /** MAC entry 3 or 11, ATM Header 7 */
   IFX_uint32_t Word_07;
   /** MAC entry 4 or 12 */
   IFX_uint32_t Word_08;
   /** MAC entry 4 or 12 */
   IFX_uint32_t Word_09;
   /** MAC entry 5 or 13 */
   IFX_uint32_t Word_10;
   /** MAC entry 5 or 13 */
   IFX_uint32_t Word_11;
   /** MAC entry 6 or 14 */
   IFX_uint32_t Word_12;
   /** MAC entry 6 or 14 */
   IFX_uint32_t Word_13;
   /** MAC entry 7 or 15 */
   IFX_uint32_t Word_14;
   /** MAC entry 7 or 15 */
   IFX_uint32_t Word_15;
#else
   /** MAC entry 0 or 8, ATM Header 0 */
   IFX_uint32_t Word_00;
   /** MAC entry 0 or 8, ATM Header 1 */
   IFX_uint32_t Word_01;
   /** MAC entry 1 or 9, ATM Header 2 */
   IFX_uint32_t Word_02;
   /** MAC entry 1 or 9, ATM Header 3 */
   IFX_uint32_t Word_03;
   /** MAC entry 2 or 10, ATM Header 4 */
   IFX_uint32_t Word_04;
   /** MAC entry 2 or 10, ATM Header 5 */
   IFX_uint32_t Word_05;
   /** MAC entry 3 or 11, ATM Header 6 */
   IFX_uint32_t Word_06;
   /** MAC entry 3 or 11, ATM Header 7 */
   IFX_uint32_t Word_07;
   /** MAC entry 4 or 12 */
   IFX_uint32_t Word_08;
   /** MAC entry 4 or 12 */
   IFX_uint32_t Word_09;
   /** MAC entry 5 or 13 */
   IFX_uint32_t Word_10;
   /** MAC entry 5 or 13 */
   IFX_uint32_t Word_11;
   /** MAC entry 6 or 14 */
   IFX_uint32_t Word_12;
   /** MAC entry 6 or 14 */
   IFX_uint32_t Word_13;
   /** MAC entry 7 or 15 */
   IFX_uint32_t Word_14;
   /** MAC entry 7 or 15 */
   IFX_uint32_t Word_15;
#endif
} __PACKED__ ;


/**
   This acknowledgement contains the global statistics for the SCI interface.
*/
struct ACK_Dbg_SCI_StatisticsGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Transmit Fifo Overflow count */
   IFX_uint32_t TX_OVFL;
   /** Transmit Fifo Underflow Count */
   IFX_uint32_t TX_UNFL;
   /** Receive Fifo Overflow count */
   IFX_uint32_t RX_OVFL;
   /** Transmit Fifo Reset Count */
   IFX_uint32_t TX_FifoReset;
   /** Receive Fifo Reset Count */
   IFX_uint32_t RX_FifoReset;
   /** AUX Register Write Access Count */
   IFX_uint32_t AUX_WriteCmds;
   /** AUX Register Read Access Count */
   IFX_uint32_t AUX_ReadCmds;
   /** Ram Shell Write Access Count */
   IFX_uint32_t RS_WriteCmds;
   /** Ram Shell Read Access Count */
   IFX_uint32_t RS_ReadCmds;
   /** Total Number of Bytes Transmitted in the Egress Direction */
   IFX_uint32_t TX_Bytes;
   /** Total Number of Bytes Received in the Ingress Direction */
   IFX_uint32_t RX_Bytes;
   /** The Number of Frames Receive with an Invalid Source ID */
   IFX_uint32_t RX_InvChId;
#else
   /** Transmit Fifo Overflow count */
   IFX_uint32_t TX_OVFL;
   /** Transmit Fifo Underflow Count */
   IFX_uint32_t TX_UNFL;
   /** Receive Fifo Overflow count */
   IFX_uint32_t RX_OVFL;
   /** Transmit Fifo Reset Count */
   IFX_uint32_t TX_FifoReset;
   /** Receive Fifo Reset Count */
   IFX_uint32_t RX_FifoReset;
   /** AUX Register Write Access Count */
   IFX_uint32_t AUX_WriteCmds;
   /** AUX Register Read Access Count */
   IFX_uint32_t AUX_ReadCmds;
   /** Ram Shell Write Access Count */
   IFX_uint32_t RS_WriteCmds;
   /** Ram Shell Read Access Count */
   IFX_uint32_t RS_ReadCmds;
   /** Total Number of Bytes Transmitted in the Egress Direction */
   IFX_uint32_t TX_Bytes;
   /** Total Number of Bytes Received in the Ingress Direction */
   IFX_uint32_t RX_Bytes;
   /** The Number of Frames Receive with an Invalid Source ID */
   IFX_uint32_t RX_InvChId;
#endif
} __PACKED__ ;


/**
   This notification contains the link specific statistics for the SCI interface.
*/
struct NFC_Dbg_SCI_LinkStatistics
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Channel Number */
   IFX_uint32_t ChannelNo;
   /** Ingress Channel State */
   IFX_uint32_t IngressState;
   /** The Egress Send State */
   IFX_uint32_t E_SendState;
   /** Total Number of Messages Received */
   IFX_uint32_t I_MsgCnt;
   /** Total Number of Dropped Messages */
   IFX_uint32_t I_MsgDropped;
   /** Total Number of Transport Layer Acknowledges sent */
   IFX_uint32_t E_TL_Acks;
   /** Total Number of Transport Layer NEG Acknowledges sent */
   IFX_uint32_t E_TL_Nacks;
   /** Total Number of Messages Sent */
   IFX_uint32_t E_MsgCnt;
   /** The Number of Message Layer Retries */
   IFX_uint32_t E_ML_Retry;
   /** Total Number of Transport Layer Acknowledges Received */
   IFX_uint32_t I_TL_Acks;
   /** Total Number of Transport Layer NEG Acks Received */
   IFX_uint32_t I_TL_Nacks;
   /** Total Number of Transport Layer Frames Dropped */
   IFX_uint32_t I_TL_Dropped;
   /** The Number of Messages Protocol Violations */
   IFX_uint32_t I_ProtViol;
   /** Number of Transport Layer Resets Received */
   IFX_uint32_t I_TL_Reset;
   /** Number of Transport Layer Resets Sent */
   IFX_uint32_t E_TL_Reset;
#else
   /** Channel Number */
   IFX_uint32_t ChannelNo;
   /** Ingress Channel State */
   IFX_uint32_t IngressState;
   /** The Egress Send State */
   IFX_uint32_t E_SendState;
   /** Total Number of Messages Received */
   IFX_uint32_t I_MsgCnt;
   /** Total Number of Dropped Messages */
   IFX_uint32_t I_MsgDropped;
   /** Total Number of Transport Layer Acknowledges sent */
   IFX_uint32_t E_TL_Acks;
   /** Total Number of Transport Layer NEG Acknowledges sent */
   IFX_uint32_t E_TL_Nacks;
   /** Total Number of Messages Sent */
   IFX_uint32_t E_MsgCnt;
   /** The Number of Message Layer Retries */
   IFX_uint32_t E_ML_Retry;
   /** Total Number of Transport Layer Acknowledges Received */
   IFX_uint32_t I_TL_Acks;
   /** Total Number of Transport Layer NEG Acks Received */
   IFX_uint32_t I_TL_Nacks;
   /** Total Number of Transport Layer Frames Dropped */
   IFX_uint32_t I_TL_Dropped;
   /** The Number of Messages Protocol Violations */
   IFX_uint32_t I_ProtViol;
   /** Number of Transport Layer Resets Received */
   IFX_uint32_t I_TL_Reset;
   /** Number of Transport Layer Resets Sent */
   IFX_uint32_t E_TL_Reset;
#endif
} __PACKED__ ;


/**
   This command is used to manually apply the PAF expected sequence number adaptation.
*/
struct CMD_PAF_SeqNoAdapt
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_PAF_SeqNoAdapt
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Expected Sequence Number Adaptation */
   IFX_uint32_t ExpSeqNoAdapt;
#endif
} __PACKED__ ;


/**
   This command is used to read information about the PAF interrupt service routines,
   state machine surveillance and adaptation algorithms.
*/
struct CMD_PAF_InfoGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Info Type */
   IFX_uint32_t InfoType;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Info Type */
   IFX_uint32_t InfoType;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_PAF_InfoGet
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Info Type */
   IFX_uint32_t InfoType;
   /** Param_00 */
   IFX_uint32_t Param_00;
   /** Param_01 */
   IFX_uint32_t Param_01;
   /** Param_02 */
   IFX_uint32_t Param_02;
   /** Param_03 */
   IFX_uint32_t Param_03;
   /** Param_04 */
   IFX_uint32_t Param_04;
   /** Param_05 */
   IFX_uint32_t Param_05;
   /** Param_06 */
   IFX_uint32_t Param_06;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** Info Type */
   IFX_uint32_t InfoType;
   /** Param_00 */
   IFX_uint32_t Param_00;
   /** Param_01 */
   IFX_uint32_t Param_01;
   /** Param_02 */
   IFX_uint32_t Param_02;
   /** Param_03 */
   IFX_uint32_t Param_03;
   /** Param_04 */
   IFX_uint32_t Param_04;
   /** Param_05 */
   IFX_uint32_t Param_05;
   /** Param_06 */
   IFX_uint32_t Param_06;
#endif
} __PACKED__ ;


/**
   This command is used to start initialization of a single PME PAF. This is only
   needed if the autonomous initialization is disabled in the BACP configuration
   message.
*/
struct CMD_BACP_Initialize
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
#endif
} __PACKED__ ;


/**
   This command is used to move a PME from a source PAF to a target PAF.
*/
struct CMD_BACP_PmeTransfer
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** Target PAF */
   IFX_uint32_t TargetPaf;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** Target PAF */
   IFX_uint32_t TargetPaf;
#endif
} __PACKED__ ;


/**
   This command is used to remove a PME from a source PAF.
*/
struct CMD_BACP_PmeRemove
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
#endif
} __PACKED__ ;


/**
   This event provides information about the Bonding Aggregation Control Protocol to
   the external host.
*/
struct EVT_BACP_Protocol
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** BACP Protocol Event */
   IFX_uint32_t Event;
   /** Result */
   IFX_uint32_t Result;
   /** Parameter 0 */
   IFX_uint32_t Param_0;
   /** Parameter 1 */
   IFX_uint32_t Param_1;
   /** Parameter 2 */
   IFX_uint32_t Param_2;
   /** Parameter 3 */
   IFX_uint32_t Param_3;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** BACP Protocol Event */
   IFX_uint32_t Event;
   /** Result */
   IFX_uint32_t Result;
   /** Parameter 0 */
   IFX_uint32_t Param_0;
   /** Parameter 1 */
   IFX_uint32_t Param_1;
   /** Parameter 2 */
   IFX_uint32_t Param_2;
   /** Parameter 3 */
   IFX_uint32_t Param_3;
#endif
} __PACKED__ ;


/**
   This command is used to query the PME status.
*/
struct CMD_BACP_PmeStatus
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
#endif
} __PACKED__ ;


/**
   
*/
struct ACK_BACP_PmeStatus
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** State Machine State */
   IFX_uint32_t SmState;
   /** Local Status */
   IFX_uint32_t Status;
   /** Remote Status */
   IFX_uint32_t RemoteStatus;
   /** Local Stream ID */
   IFX_uint32_t StreamId;
   /** Remote Stream ID */
   IFX_uint32_t RemoteStreamId;
   /** Local PME ID */
   IFX_uint32_t PmeId;
   /** Remote PME ID */
   IFX_uint32_t RemotePmeId;
   /** Group ID Low Part (Octets 0 - 3) */
   IFX_uint32_t GroupId_lo;
   /** Group ID High Part (Octets 4 - 5) */
   IFX_uint32_t GroupId_hi;
   /** Remote Group ID Low Part (Octets 0 - 3) */
   IFX_uint32_t RemoteGroupId_lo;
   /** Remote Group ID High Part (Octets 4 - 5) */
   IFX_uint32_t RemoteGroupId_hi;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** State Machine State */
   IFX_uint32_t SmState;
   /** Local Status */
   IFX_uint32_t Status;
   /** Remote Status */
   IFX_uint32_t RemoteStatus;
   /** Local Stream ID */
   IFX_uint32_t StreamId;
   /** Remote Stream ID */
   IFX_uint32_t RemoteStreamId;
   /** Local PME ID */
   IFX_uint32_t PmeId;
   /** Remote PME ID */
   IFX_uint32_t RemotePmeId;
   /** Group ID Low Part (Octets 0 - 3) */
   IFX_uint32_t GroupId_lo;
   /** Group ID High Part (Octets 4 - 5) */
   IFX_uint32_t GroupId_hi;
   /** Remote Group ID Low Part (Octets 0 - 3) */
   IFX_uint32_t RemoteGroupId_lo;
   /** Remote Group ID High Part (Octets 4 - 5) */
   IFX_uint32_t RemoteGroupId_hi;
#endif
} __PACKED__ ;


/**
   This event is intended for BACP debugging. The content is subject to change!
*/
struct EVT_BACP_Dbg
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** BACP Debug Event */
   IFX_uint32_t Event;
   /** Parameter 0 */
   IFX_uint32_t Param_00;
   /** Parameter 1 */
   IFX_uint32_t Param_01;
   /** Parameter 2 */
   IFX_uint32_t Param_02;
   /** Parameter 3 */
   IFX_uint32_t Param_03;
   /** Parameter 4 */
   IFX_uint32_t Param_04;
   /** Parameter 5 */
   IFX_uint32_t Param_05;
   /** Parameter 6 */
   IFX_uint32_t Param_06;
   /** Parameter 7 */
   IFX_uint32_t Param_07;
   /** Parameter 8 */
   IFX_uint32_t Param_08;
   /** Parameter 9 */
   IFX_uint32_t Param_09;
   /** Parameter 10 */
   IFX_uint32_t Param_10;
   /** Parameter 11 */
   IFX_uint32_t Param_11;
   /** Parameter 12 */
   IFX_uint32_t Param_12;
   /** Parameter 13 */
   IFX_uint32_t Param_13;
   /** Parameter 14 */
   IFX_uint32_t Param_14;
   /** Parameter 15 */
   IFX_uint32_t Param_15;
   /** Parameter 16 */
   IFX_uint32_t Param_16;
   /** Parameter 17 */
   IFX_uint32_t Param_17;
   /** Parameter 18 */
   IFX_uint32_t Param_18;
   /** Parameter 19 */
   IFX_uint32_t Param_19;
   /** Parameter 20 */
   IFX_uint32_t Param_20;
   /** Parameter 21 */
   IFX_uint32_t Param_21;
   /** Parameter 22 */
   IFX_uint32_t Param_22;
   /** Parameter 23 */
   IFX_uint32_t Param_23;
   /** Parameter 24 */
   IFX_uint32_t Param_24;
   /** Parameter 25 */
   IFX_uint32_t Param_25;
   /** Parameter 26 */
   IFX_uint32_t Param_26;
   /** Parameter 27 */
   IFX_uint32_t Param_27;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** BACP Debug Event */
   IFX_uint32_t Event;
   /** Parameter 0 */
   IFX_uint32_t Param_00;
   /** Parameter 1 */
   IFX_uint32_t Param_01;
   /** Parameter 2 */
   IFX_uint32_t Param_02;
   /** Parameter 3 */
   IFX_uint32_t Param_03;
   /** Parameter 4 */
   IFX_uint32_t Param_04;
   /** Parameter 5 */
   IFX_uint32_t Param_05;
   /** Parameter 6 */
   IFX_uint32_t Param_06;
   /** Parameter 7 */
   IFX_uint32_t Param_07;
   /** Parameter 8 */
   IFX_uint32_t Param_08;
   /** Parameter 9 */
   IFX_uint32_t Param_09;
   /** Parameter 10 */
   IFX_uint32_t Param_10;
   /** Parameter 11 */
   IFX_uint32_t Param_11;
   /** Parameter 12 */
   IFX_uint32_t Param_12;
   /** Parameter 13 */
   IFX_uint32_t Param_13;
   /** Parameter 14 */
   IFX_uint32_t Param_14;
   /** Parameter 15 */
   IFX_uint32_t Param_15;
   /** Parameter 16 */
   IFX_uint32_t Param_16;
   /** Parameter 17 */
   IFX_uint32_t Param_17;
   /** Parameter 18 */
   IFX_uint32_t Param_18;
   /** Parameter 19 */
   IFX_uint32_t Param_19;
   /** Parameter 20 */
   IFX_uint32_t Param_20;
   /** Parameter 21 */
   IFX_uint32_t Param_21;
   /** Parameter 22 */
   IFX_uint32_t Param_22;
   /** Parameter 23 */
   IFX_uint32_t Param_23;
   /** Parameter 24 */
   IFX_uint32_t Param_24;
   /** Parameter 25 */
   IFX_uint32_t Param_25;
   /** Parameter 26 */
   IFX_uint32_t Param_26;
   /** Parameter 27 */
   IFX_uint32_t Param_27;
#endif
} __PACKED__ ;


/**
   This command is used to configure BACP debugging. The content is subject to change!
*/
struct CMD_BACP_DbgConfig
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** Enable Debug Events for the BACP State Machine */
   IFX_uint32_t Enable_DbgEvt_Sm;
   /** Enable Debug Events for the Reception of BACPDUs */
   IFX_uint32_t Enable_DbgEvt_PduRx;
   /** Enable Debug Events for the Transmission of BACPDUs */
   IFX_uint32_t Enable_DbgEvt_PduTx;
   /** Enable Debug Events for the BACP Initialization */
   IFX_uint32_t Enable_DbgEvt_Init;
#else
   /** PME Number */
   IFX_uint32_t PmeNo;
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** Enable Debug Events for the BACP State Machine */
   IFX_uint32_t Enable_DbgEvt_Sm;
   /** Enable Debug Events for the Reception of BACPDUs */
   IFX_uint32_t Enable_DbgEvt_PduRx;
   /** Enable Debug Events for the Transmission of BACPDUs */
   IFX_uint32_t Enable_DbgEvt_PduTx;
   /** Enable Debug Events for the BACP Initialization */
   IFX_uint32_t Enable_DbgEvt_Init;
#endif
} __PACKED__ ;


/**
   This command is used to transmit a BACPDU for debugging purposes.
*/
struct CMD_BACP_DbgSendPdu
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** BACPDU Type */
   IFX_uint32_t PduType;
   /** BACPDU Length in Bytes */
   IFX_uint32_t PduLenByte;
   /** BACPDU Data Word 0 */
   IFX_uint32_t Data_00;
   /** BACPDU Data Word 1 */
   IFX_uint32_t Data_01;
   /** BACPDU Data Word 2 */
   IFX_uint32_t Data_02;
   /** BACPDU Data Word 3 */
   IFX_uint32_t Data_03;
   /** BACPDU Data Word 4 */
   IFX_uint32_t Data_04;
   /** BACPDU Data Word 5 */
   IFX_uint32_t Data_05;
   /** BACPDU Data Word 6 */
   IFX_uint32_t Data_06;
   /** BACPDU Data Word 7 */
   IFX_uint32_t Data_07;
   /** BACPDU Data Word 8 */
   IFX_uint32_t Data_08;
   /** BACPDU Data Word 9 */
   IFX_uint32_t Data_09;
   /** BACPDU Data Word 10 */
   IFX_uint32_t Data_10;
   /** BACPDU Data Word 11 */
   IFX_uint32_t Data_11;
   /** BACPDU Data Word 12 */
   IFX_uint32_t Data_12;
   /** BACPDU Data Word 13 */
   IFX_uint32_t Data_13;
   /** BACPDU Data Word 14 */
   IFX_uint32_t Data_14;
   /** BACPDU Data Word 15 */
   IFX_uint32_t Data_15;
   /** BACPDU Data Word 16 */
   IFX_uint32_t Data_16;
   /** BACPDU Data Word 17 */
   IFX_uint32_t Data_17;
   /** BACPDU Data Word 18 */
   IFX_uint32_t Data_18;
   /** BACPDU Data Word 19 */
   IFX_uint32_t Data_19;
#else
   /** PAF Number */
   IFX_uint32_t PafNo;
   /** BACPDU Type */
   IFX_uint32_t PduType;
   /** BACPDU Length in Bytes */
   IFX_uint32_t PduLenByte;
   /** BACPDU Data Word 0 */
   IFX_uint32_t Data_00;
   /** BACPDU Data Word 1 */
   IFX_uint32_t Data_01;
   /** BACPDU Data Word 2 */
   IFX_uint32_t Data_02;
   /** BACPDU Data Word 3 */
   IFX_uint32_t Data_03;
   /** BACPDU Data Word 4 */
   IFX_uint32_t Data_04;
   /** BACPDU Data Word 5 */
   IFX_uint32_t Data_05;
   /** BACPDU Data Word 6 */
   IFX_uint32_t Data_06;
   /** BACPDU Data Word 7 */
   IFX_uint32_t Data_07;
   /** BACPDU Data Word 8 */
   IFX_uint32_t Data_08;
   /** BACPDU Data Word 9 */
   IFX_uint32_t Data_09;
   /** BACPDU Data Word 10 */
   IFX_uint32_t Data_10;
   /** BACPDU Data Word 11 */
   IFX_uint32_t Data_11;
   /** BACPDU Data Word 12 */
   IFX_uint32_t Data_12;
   /** BACPDU Data Word 13 */
   IFX_uint32_t Data_13;
   /** BACPDU Data Word 14 */
   IFX_uint32_t Data_14;
   /** BACPDU Data Word 15 */
   IFX_uint32_t Data_15;
   /** BACPDU Data Word 16 */
   IFX_uint32_t Data_16;
   /** BACPDU Data Word 17 */
   IFX_uint32_t Data_17;
   /** BACPDU Data Word 18 */
   IFX_uint32_t Data_18;
   /** BACPDU Data Word 19 */
   IFX_uint32_t Data_19;
#endif
} __PACKED__ ;


/**
   This message is used to transport commands to the PMD 0, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
struct CMD_TNL_PMD_0_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport acknowledgements from the PMD 0.
*/
struct ACK_TNL_PMD_0_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport Notifications from the PMD 0, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
struct NFC_TNL_PMD_0_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport commands to the PMD 1, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
struct CMD_TNL_PMD_1_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport acknowledgements from the PMD 1.
*/
struct ACK_TNL_PMD_1_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport Notifications from the PMD 1, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
struct NFC_TNL_PMD_1_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport commands to the PMD 2, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
struct CMD_TNL_PMD_2_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport acknowledgements from the PMD 2.
*/
struct ACK_TNL_PMD_2_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport Notifications from the PMD 2, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
struct NFC_TNL_PMD_2_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport commands to the PMD 3, for details of the SDFE
   commands refer to the SDFE Message catalogue.
*/
struct CMD_TNL_PMD_3_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport acknowledgements from the PMD 3.
*/
struct ACK_TNL_PMD_3_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This message is used to transport Notifications from the PMD 3, for details of the
   SDFE notifications refer to the SDFE Message catalogue.
*/
struct NFC_TNL_PMD_3_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** PMD message Data */
   IFX_uint32_t Data[31];
#else
   /** PMD message Data */
   IFX_uint32_t Data[31];
#endif
} __PACKED__ ;


/**
   This data structure defines an EOC transmit message type, and is used in the
   following EOC messages
*/
struct EOC_TransmitMsg
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** EOC Request number, range 1 - 127 */
   IFX_uint8_t EOC_Id;
   /** Source destination Identifier */
   IFX_uint8_t SrcDst;
   /** Number of octets in the EOC message (SrcDst + EOC_Id + Params) */
   IFX_uint8_t Length;
   /** Only for internal usage */
   IFX_uint8_t xme;
   /** Optional EOC message parameters */
   IFX_uint8_t Params[110];
#else
   /** Only for internal usage */
   IFX_uint8_t xme;
   /** Number of octets in the EOC message (SrcDst + EOC_Id + Params) */
   IFX_uint8_t Length;
   /** Source destination Identifier */
   IFX_uint8_t SrcDst;
   /** EOC Request number, range 1 - 127 */
   IFX_uint8_t EOC_Id;
   /** Optional EOC message parameters */
   IFX_uint8_t Params[110];
#endif
} __PACKED__ ;


/**
   This data structure defines an EOC received message type, and is used in the
   following EOC messages
*/
struct EOC_ReceiveMsg
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** Source destination Identifier */
   IFX_uint8_t SrcDst;
   /** Number of octets in the EOC message (SrcDst + EOC_Id + Params) */
   IFX_uint8_t Length;
   /** Fail indication: */
   IFX_uint8_t fail;
   /** Only for internal usage */
   IFX_uint8_t rme;
   /** EOC message octet 4 */
   IFX_uint8_t Octet_4;
   /** EOC message octet 3 */
   IFX_uint8_t Octet_3;
   /** EOC message octet 2 */
   IFX_uint8_t Octet_2;
   /** EOC Request number, range 1 - 127 */
   IFX_uint8_t EOC_Id;
   /** Optional EOC Response parameters */
   IFX_uint8_t Params[106];
#else
   /** Only for internal usage */
   IFX_uint8_t rme;
   /** Fail indication: */
   IFX_uint8_t fail;
   /** Number of octets in the EOC message (SrcDst + EOC_Id + Params) */
   IFX_uint8_t Length;
   /** Source destination Identifier */
   IFX_uint8_t SrcDst;
   /** EOC Request number, range 1 - 127 */
   IFX_uint8_t EOC_Id;
   /** EOC message octet 2 */
   IFX_uint8_t Octet_2;
   /** EOC message octet 3 */
   IFX_uint8_t Octet_3;
   /** EOC message octet 4 */
   IFX_uint8_t Octet_4;
   /** Optional EOC Response parameters */
   IFX_uint8_t Params[106];
#endif
} __PACKED__ ;


/**
   This message is used to transport EOC requests and responses to a remote unit on a
   given link, for details of the EOC requests and responses refer to the ITU-T G.991.2
   standard.
*/
struct CMD_EOC_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Message */
   IFX_uint32_t EocMsg[29];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Message */
   IFX_uint32_t EocMsg[29];
#endif
} __PACKED__ ;


/**
   This message indicates that all EOC messages produced by a CMD_EOC_Message have been
   transmitted.
*/
struct NFC_EOC_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
#endif
} __PACKED__ ;


/**
   This event is generated (only when an Host is connected) each time an EOC request or
   response was received by the internal EOC handler and cannot be processed, while the
   EOC handler is in transparent mode or while the EOC Id is not supported.
*/
struct EVT_EOC_Message
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Message */
   IFX_uint32_t EocMessage[29];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Message */
   IFX_uint32_t EocMessage[29];
#endif
} __PACKED__ ;


/**
   This event is generated when the EOC message echo is switched on.
*/
struct DBG_EOC_EchoMessage
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Message */
   IFX_uint32_t EocMessage[29];
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Message */
   IFX_uint32_t EocMessage[29];
#endif
} __PACKED__ ;


/**
   This event indicates the EOC channel state for a given link. This Event will be sent
   each the EOC changes it state.
*/
struct EVT_EOC_LinkState
{
#if IFX_BYTE_ORDER == IFX_LITTLE_ENDIAN
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Channel State */
   IFX_uint32_t State;
#else
   /** DSL Link Number */
   IFX_uint32_t LinkNo;
   /** EOC Channel State */
   IFX_uint32_t State;
#endif
} __PACKED__ ;


#ifdef __cplusplus
}
#endif

#ifdef __PACKED_DEFINED__
   #if !(defined (__GNUC__) || defined (__GNUG__))
      #pragma pack()
   #endif
   #undef __PACKED_DEFINED__
#endif /* __PACKED_DEFINED__ */

/** @} */
#endif
