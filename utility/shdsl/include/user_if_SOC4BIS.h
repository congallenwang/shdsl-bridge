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

#ifndef _SDFE4_125_H
#define _SDFE4_125_H

#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#define __PACKED__ __attribute__ ((packed))
#elif !defined (__PACKED__)
#define __PACKED__ /* nothing */
#endif

#ifndef basic_types 
#define basic_types 
typedef unsigned int uint32; 
typedef signed int int32; 
typedef unsigned short uint16; 
typedef signed short int16; 
typedef unsigned char uint8; 
typedef signed char int8; 
#ifndef __cplusplus 
typedef unsigned int bool; 
#endif 
#endif 


/** \addtogroup SDFE4 SDFE4 */

/*@{*/


/* constant defines */


 #define  NORMAL_MODE  0x0 
 #define  SHDSL_TRANSP_FRAM_MODE  0x1 
 #define  ANNEX_A  0x1 
 #define  ANNEX_B  0x2 
 #define  ANNEX_A_B  0x3 
 #define  ANNEX_EFM  0x4 
 #define  ANNEX_A_EFM  0x5 
 #define  ANNEX_B_EFM  0x6 
 #define  ANNEX_A_B_EFM  0x7 
 #define  SYM_PSD  0x0 
 #define  ASYM_PSD  0x1 
 #define  STU_C  0x1 
 #define  STU_R  0x2 
 #define  SHDSL_CLK_MODE_1  0x1 
 #define  SHDSL_CLK_MODE_2  0x2 
 #define  SHDSL_CLK_MODE_3a  0x4 
 #define  SHDSL_CLK_MODE_3b  0x8 
 #define  PMMS_OFF  0x00 
 #define  CUR_COND  0x01 
 #define  WC_COND  0x02 
 #define  CLK_INTERNAL  0x0 
 #define  CLK_EXTERNAL  0x1 
 #define  CLK_RX_SYMBOL  0x2 
 #define  CLK_TIM_INTERNAL  0x3 
 #define  REPEATER  0x1 
 #define  TERMINATOR  0x0 
 #define  FRAME_PLESIO  0x0 
 #define  FRAME_SYNC  0x1 
 #define  FRAME_TRANSPARENT  0x2 
 #define  OWN  0x0 
 #define  REMOTE  0x1 
 #define  WORKING  0x2 
 #define  MODE_SELECT  0x3 
 #define  MERGED_CL_SRU  0x4 
 #define  MAIN_INIT  0x0 
 #define  MAIN_PRE_ACT  0x1 
 #define  MAIN_CORE_ACT  0x2 
 #define  MAIN_DATA_MODE  0x3 
 #define  MAIN_EXCEPTION  0x5 
 #define  MAIN_TEST  0x6 
 #define  ENABLED  0x1 
 #define  DISABLED  0x0 
 #define  TRANS_DONE  0x00 
 #define  TRANS_REJECTED  0x01 
 #define  SDI_TDMCLK  0x00 
 #define  SDI_TDMCLK_TDMSP  0x01 
 #define  SDI_TDMCLK_TDMMSP  0x02 
 #define  SDI_TDMCLK_TDMSP_TDMMSP  0x03 
 #define  SDI_INCLK_INSP_INMSP  0x04 
 #define  SDI_INCLK_INSP_TDMMSP  0x05 
 #define  SDI_INCLK_TDMSP_TDMMSP  0x06 
 #define  SDI_TDMSP  0x07 
 #define  SDI_TDMSP_TDMMSP  0x08 
 #define  SDI_DSL3  0x09 
 #define  SDI_INCLK  0x0A 
 #define  SDI_DO_NOTHING  0x0B 
 #define  SDI_HIGH_Z  0x0C 
 #define  SDI_DSL3_NS  0x0D 
 #define  SDI_IOM2  0x0E 
 #define  SDI_ISDN  0x0F 
 #define  SDI_TU12S  0x10 
 #define  SDI_TU12A  0x11 
 #define  SDI_NODPLL  0x00 
 #define  SDI_DPLL4IN  0x01 
 #define  SDI_DPLL4OUT  0x02 
 #define  SDI_DPLL4INOUT  0x03 
 #define  SDI_NO_LOOP  0x00 
 #define  SDI_REMOTE_LOOP  0x01 
 #define  SDI_REMOTE_CLK_ONLY  0x02 
 #define  SDI_LOCAL_LOOP  0x03 
 #define  SDI_COMB_LOOP  0x04 
 #define  SDI_LBUF_LOOP  0x05 
 #define  SDI_RBUF_LOOP  0x06 
 #define  DEFAULT  0x00 
 #define  CH_GR_BIT  0x80 
 #define  CH_GR_BYTE  0x87 
 #define  SDI_NO  0x00 
 #define  SDI_YES  0x01 
 #define  SDI_FALLING  0x00 
 #define  SDI_RISING  0x01 
 #define  SDI_LOW  0x00 
 #define  SDI_HIGH  0x01 
 #define  SLIP_FAST  0x00 
 #define  SLIP_NORMAL4  0x01 
 #define  SLIP_NORMAL8  0x03 
 #define  TIM_REF_CLK_IN_8KHZ  0x00 
 #define  TIM_REF_CLK_IN_1536KHZ  0x01 
 #define  TIM_REF_CLK_IN_1544KHZ  0x02 
 #define  TIM_REF_CLK_IN_2048KHZ  0x03 
 #define  TIM_REF_CLK_IN_4096KHZ  0x04 
 #define  TIM_REF_CLK_IN_8192KHZ  0x05 
 #define  TIM_REF_CLK_IN_15360KHZ  0x06 
 #define  TIM_REF_CLK_IN_20480KHZ  0x07 
 #define  TIM_REF_CLK_OUT_SYM_8KHZ  0x00 
 #define  TIM_REF_CLK_OUT_FREE_FSC  0x01 
 #define  TIM_REF_CLK_OUT_SYMBOL_REF  0x03 
 #define  TIM_DATA_CLK_8KHZ  0x10 
 #define  TIM_DATA_CLK_1536KHZ  0x11 
 #define  TIM_DATA_CLK_1544KHZ  0x12 
 #define  TIM_DATA_CLK_2048KHZ  0x13 
 #define  TIM_DATA_CLK_4096KHZ  0x14 
 #define  TIM_DATA_CLK_8192KHZ  0x15 
 #define  TIM_DATA_CLK_15360KHZ  0x16 
 #define  TIM_DATA_CLK_19440KHZ  0x17 
 #define  TIM_DATA_CLK_20480KHZ  0x18 
 #define  TIM_DATA_CLK_24576KHZ  0x19 
 #define  EOC_TX_IDLE  0x01 
 #define  EOC_TX_READY  0x02 
 #define  EOC_TX_FRAME  0x03 
 #define  EOC_TX_ABORT  0x04 
 #define  EOC_TX_ACK_POS  0x05 
 #define  EOC_TX_ACK_NEG  0x06 
 #define  SINGLE  0x00 
 #define  FOURWIRE  0x01 
 #define  MPAIR  0x02 
 #define  MW_OP_STANDARD  0x00 
 #define  MW_OP_GSPN4WIRE  0x01 
 #define  MW_OP_GSPN_STD  0x02 
 #define  MW_OP_GSPN_AUTO  0x03 
 #define  GHS_TRANSFER  0x01 
 #define  LP_START  0x02 
 #define  GHS_NO_COMMON  0x03 
 #define  EXCEPTION  0x04 
 #define  SINGLE_PAIR_DET  0x05 
 #define  GHS_STARTUP  0x06 
 #define  GHS_SILENCE  0x07 
 #define  GHS_RSP_FAILURE  0x08 
 #define  GHS_IDLE  0x09 
 #define  GHS_WAIT_STU_R  0x0A 
 #define  GHS_WAIT_STU_C  0x0B 
 #define  GHS_LINK_INITIATION  0x0C 
 #define  GHS_CAP_AVAILABLE  0x0D 
 #define  GHS_30SEC_TIMEOUT  0x0E 
 #define  FOUR_WIRE_DET  0x0F 
 #define  LP_EXCEPTION  0x10 
 #define  M_PAIR_DET  0x11 
 #define  M_PAIR_COUNT_MIS  0x12 
 #define  SRU_CFG_CL_REJ  0x13 
 #define  SRU_CFG_CL_DONE  0x14 
 #define  ERR_UNUSED  0x00 
 #define  ERR_ANNEX_MIS  0x01 
 #define  ERR_MODE_MIS  0x02 
 #define  ERR_SPAR2_MIS  0x03 
 #define  ERR_TPS_TC_CLOCK_MIS  0x04 
 #define  ERR_TPS_TC_CHANNEL_MIS  0x05 
 #define  ERR_DATA_RATES_MIS  0x06 
 #define  ERR_SUB_RATES_MIS  0x07 
 #define  ERR_DUAL_TPSTC_MIS  0x08 
 #define  ERR_LP_PARA_DN_MIS  0x10 
 #define  ERR_LP_PARA_UP_MIS  0x20 
 #define  ERR_LP_TIME_MIS  0x30 
 #define  LP_PRB_NUM_RX_NS  0x31 
 #define  LP_PRB_NUM_TX_NS  0x32 
 #define  ERR_LP_ECHO_DN_MIS  0x40 
 #define  ERR_LP_PARA_DN_LACK  0x50 
 #define  ERR_LP_PARA_UP_LACK  0x60 
 #define  ERR_LP_PARA_DNUP_LACK  0x70 
 #define  ERR_MS_NO_MODE  0xFF 
 #define  PROBE_NOT_DETECTED  0x90 
 #define  PROBE_END_NOT_DETECTED  0x91 
 #define  CR_NOT_DETECTED  0xA3 
 #define  NOT_CONVERGED_ON_SR  0xA6 
 #define  TR_NOT_DETECTED  0xA9 
 #define  DSL_FRAMING_NOT_SYNCHRONIZED  0xAC 
 #define  NOT_CONVERGED_ON_SC  0xB3 
 #define  TC_NOT_DETECTED  0xB6 
 #define  FC_NOT_DETECTED  0xB9 
 #define  DATA_EXCEPTION  0xC0 
 #define  LINK_INITIATION  0x00 
 #define  GHS_INITIATION  0x01 
 #define  DOP_SET_IF_CLEAR  0x00 
 #define  DOP_GET  0x02 
 #define  DOP_CLEAR_IF_SAME  0x03 
 #define  DOP_INVALID  0xFF 
 #define  DOP_NOT_STARTED  0x00 
 #define  DOP_IN_PROGRESS  0x01 
 #define  DOP_FINISHED  0x02 
 #define  DOP_FAILED  0xFF 
 #define  AOP_SET  0x00 
 #define  AOP_GET  0x02 
 #define  AOP_INVALID  0xFF 
 #define  AOP_NOT_STARTED  0x00 
 #define  AOP_IN_PROGRESS  0x01 
 #define  AOP_FINISHED  0x02 
 #define  AOP_FAILED  0xFF 
 #define  GHS_TRNS_00  0x00 
 #define  GHS_TRNS_01  0x01 
 #define  GHS_TRNS_10  0x02 
 #define  GHS_TRNS_11  0x03 
 #define  STARTUP_LOCAL  0x00 
 #define  STARTUP_FAREND  0x80 
 #define  PBO_NORMAL  0x00 
 #define  PBO_FORCED  0x04 
 #define  EPL_DISABLED  0x00 
 #define  EPL_ENABLED  0x08 
 #define  PMMS_NORMAL  0x00 
 #define  PMMS_FORCED  0x10 
 #define  SHDSL  0x01 
 #define  VENDOR_ID  0x00 
 #define  VENDOR_SPEC_INFO  0x00 
 #define  ID_NPAR1_SPAR1  0x01 
 #define  ID_NDR_UP  0x02 
 #define  ID_NDR_DN  0x03 
 #define  ID_DFC_UP  0x04 
 #define  ID_DFC_DN  0x05 
 #define  ID_RPLC_UP_A4  0x06 
 #define  ID_RPLC_DN_A4  0x07 
 #define  ID_SPAR1  0x08 
 #define  SI_NPAR1_SPAR1  0x30 
 #define  SI_NPAR2_SPAR2_AB  0x31 
 #define  SI_NPAR2_SPAR2_2BASE_TL  0x32 
 #define  SI_NPAR2_SPAR2_VAR_SILENCE  0x33 
 #define  SI_NPAR2_VAR_SILENCE  0x33 
 #define  SI_SPAR1  0x34 
 #define  SI_SPAR2_ABFG  0x35 
 #define  SI_NPAR2_ABFG  0x36 
 #define  TRAIN_DN_AB  0x60 
 #define  TRAIN_UP_AB  0x61 
 #define  PMMS_DN_AB  0x62 
 #define  PMMS_UP_AB  0x63 
 #define  FRAM_DN_AB  0x64 
 #define  FRAM_UP_AB  0x65 
 #define  TPS_TC_A  0x66 
 #define  DUAL_TPS_TC_A  0x67 
 #define  TPS_TC_B  0x68 
 #define  DUAL_TPS_TC_B  0x69 
 #define  MPAIR_OP_AB  0x6A 
 #define  EXT_TRAIN_16PAM_DN_FG  0x6B 
 #define  EXT_TRAIN_16PAM_FG  0x6B 
 #define  EXT_TRAIN_32PAM_DN_FG  0x6C 
 #define  EXT_TRAIN_32PAM_FG  0x6C 
 #define  EXT_TRAIN_16PAM_UP_FG  0x6D 
 #define  EXT_TRAIN_32PAM_UP_FG  0x6E 
 #define  EXT_PMMS_DN_FG  0x6F 
 #define  EXT_PMMS_FG  0x6F 
 #define  EXT_PMMS_UP_FG  0x70 
 #define  TRAIN_PAR_DN_2BASE_TL  0xA0 
 #define  TRAIN_16PAM_DN_2BASE_TL  0xA1 
 #define  TRAIN_16PAM_2BASE_TL  0xA1 
 #define  TRAIN_32PAM_DN_2BASE_TL  0xA2 
 #define  TRAIN_32PAM_2BASE_TL  0xA2 
 #define  TRAIN_PAR_UP_2BASE_TL  0xA3 
 #define  TRAIN_16PAM_UP_2BASE_TL  0xA4 
 #define  TRAIN_32PAM_UP_2BASE_TL  0xA5 
 #define  PMMS_PAR_DN_2BASE_TL  0xA6 
 #define  PMMS_DN_2BASE_TL  0xA7 
 #define  PMMS_2BASE_TL  0xA7 
 #define  PMMS_PAR_UP_2BASE_TL  0xA8 
 #define  PMMS_UP_2BASE_TL  0xA9 
 #define  DBG_PROBE_ENC  0x00 
 #define  DBG_PROBE_DFETOM_0  0x01 
 #define  DBG_PROBE_TXPSD  0x02 
 #define  DBG_PROBE_TXWDF  0x03 
 #define  DBG_PROBE_RXWDF  0x04 
 #define  DBG_PROBE_RXPSD  0x05 
 #define  DBG_PROBE_RXGHS  0x06 
 #define  DBG_PROBE_RXFIL  0x07 
 #define  DBG_PROBE_EKO  0x08 
 #define  DBG_PROBE_CEQ  0x09 
 #define  DBG_PROBE_LEQ  0x0A 
 #define  DBG_PROBE_DFETOM_1  0x0B 
 #define  DBG_PROBE_NP  0x0C 
 #define  DBG_PROBE_DEC_LEQDFE  0x0D 
 #define  DBG_PROBE_DEC_EQNP  0x0E 
 #define  DBG_PROBE_DEC_METRIC  0x0F 
 #define  DBG_PROBE_DEC_PCDS  0x10 
 #define  DBG_PROBE_PMB_CONV0  0x11 
 #define  DBG_PROBE_PMB_CONV1  0x12 
 #define  DBG_PROBE_PMB_CONV2  0x13 
 #define  DBG_PROBE_PMB_CONV3  0x14 
 #define  DBG_PROBE_TIM_TXPLL_PHERR  0x15 
 #define  DBG_PROBE_TIM_RXPLL_PHERR  0x16 
 #define  DBG_PROBE_TIM_CUSTPLL_PHERR  0x17 
 #define  DBG_PROBE_TIM_TXPLL_LFOUT  0x18 
 #define  DBG_PROBE_TIM_RXPLL_LFOUT  0x19 
 #define  DBG_PROBE_TIM_CUSTPLL_LFOUT  0x1A 
 #define  DBG_PROBE_TIM_DEBUG_BUS  0x1B 
 #define  DBG_PROBE_DEC_RXPOUT_ENC_TXPOUT  0x1C 
 #define  DBG_PROBE_ENCSTATE  0x1D 
 #define  DBG_PROBE_NEXTIC_TXDOUT  0x1E 
 #define  DBG_PROBE_NEXTIC_RXDOUT  0x1F 
 #define  DBG_PROBE_NEXTIC_DBG_SYN  0x20 
 #define  DBG_PROBE_NEXTIC_DBG_EER  0x21 
 #define  DBG_PROBE_NEXTIC_DBG_SER  0x22 
 #define  DBG_PROBE_DEC_RXERR_AFTNP  0x23 
 #define  DBG_PROBE_DEC_RXERR_BEFNP  0x24 
 #define  DBG_PROBE_DEC_UDSP_DPOUT  0x25 
 #define  DBG_TRG_RXBAUD  0x00 
 #define  DBG_TRG_RXBAUD4  0x01 
 #define  DBG_TRG_TXBAUD  0x02 
 #define  DBG_TRG_TXBAUD4  0x03 
 #define  DBG_TRG_INT0  0x04 
 #define  DBG_TRG_INT1  0x05 
 #define  DBG_TRG_INT2  0x06 
 #define  DBG_TRG_INT3  0x07 
 #define  DBG_TRG_INT4  0x08 
 #define  DBG_TRG_INT5  0x09 
 #define  DBG_TRG_TXPLL_CLOCK  0x0A 
 #define  DBG_TRG_CUSTPLL_CLOCK  0x0B 
 #define  DBG_TRG_PDI_DUMP0_AUTO  0x0C 
 #define  DBG_TRG_PDI_DUMP1_AUTO  0x0D 
 #define  DBG_TRG_PDI_READ  0x0E 
 #define  FILT_COEF_EKO  0x00 
 #define  FILT_COEF_DFETOM  0x01 
 #define  FILT_COEF_LEQ  0x02 
 #define  FILT_COEF_NP  0x03 
 #define  FILT_COEF_ALL  0x04 
 #define  FILT_COEF_NPDEC  0x05 
 #define  VENDOR_IFX_OR_ADTRAN  0x00 
 #define  VENDOR_GLOBESPAN  0x01 
 #define  VENDOR_METALINK  0x02 
 #define  AFE_V1_1  0x00 
 #define  AFE_V1_2  0x01 
 #define  LD_MODE_NORMAL  0x00 
 #define  LD_MODE_HIGH_POWER  0x02 
 #define  LD_PROT_0_OHM  0x00 
 #define  LD_PROT_1_OHM  0x01 
 #define  LD_PROT_2_OHM  0x02 
 #define  LD_PROT_3_OHM  0x03 
 #define  LD_PROT_4_OHM  0x04 
 #define  LD_PROT_5_OHM  0x05 
 #define  LD_PROT_6_OHM  0x06 
 #define  LD_PROT_7_OHM  0x07 


/** \addtogroup SDFE4_Device_Configuration Device Configuration */

/*@{*/


/* message identifiers */


 #define  CMD_ID_GET  0x080F 
 #define  CMD_FEATURE_STR_GET  0x081F 
 #define  CMD_CFG_SYM_DSL_MODE  0x0404 
 #define  CMD_CHANNEL_DISABLE  0x0C0F 
 #define  CMD_CFG_AFE_PARAMS  0x041F 
 #define  CMD_ID_GET_S  "CMD_ID_GET" 
 #define  CMD_FEATURE_STR_GET_S  "CMD_FEATURE_STR_GET" 
 #define  CMD_CFG_SYM_DSL_MODE_S  "CMD_CFG_SYM_DSL_MODE" 
 #define  CMD_CHANNEL_DISABLE_S  "CMD_CHANNEL_DISABLE" 
 #define  CMD_CFG_AFE_PARAMS_S  "CMD_CFG_AFE_PARAMS" 



/* message elements: CMD_CFG_SYM_DSL_MODE */


 #define  CMD_CFG_SYM_DSL_MODE_mode_S  L"mode" 
 #define  CMD_CFG_SYM_DSL_MODE_repeater_S  L"repeater" 
 #define  CMD_CFG_SYM_DSL_MODE_standard_S  L"standard" 
 #define  CMD_CFG_SYM_DSL_MODE_op_mode_S  L"op_mode" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd4_S  L"rsvd4" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd5_S  L"rsvd5" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd6_S  L"rsvd6" 
 #define  CMD_CFG_SYM_DSL_MODE_rsvd7_S  L"rsvd7" 



/* message elements: CMD_CFG_AFE_PARAMS */


 #define  CMD_CFG_AFE_PARAMS_mode_S  L"mode" 
 #define  CMD_CFG_AFE_PARAMS_ptc_value_S  L"ptc_value" 
 #define  CMD_CFG_AFE_PARAMS_rsvd5_S  L"rsvd5" 
 #define  CMD_CFG_AFE_PARAMS_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_AFE_PARAMS_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_AFE_PARAMS_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_AFE_PARAMS_rsvd4_S  L"rsvd4" 



/* message definitions */

/** message: CMD_CFG_SYM_DSL_MODE */

typedef struct cmd_cfg_sym_dsl_mode_s 
{ 
  /** Selects the device mode */ 
  uint8  mode; 
  /** Repeater or Terminator */ 
  uint8  repeater; 
  /** selects the DSL standard (currently only SHDSL supported) */ 
  uint8  standard; 
  /** Selects special operation modes */ 
  uint8  op_mode; 
  /** reserved for future use */ 
  uint8  rsvd1; 
  /** reserved for future use */ 
  uint8  rsvd2; 
  /** reserved for future use */ 
  uint8  rsvd3; 
  /** reserved for future use */ 
  uint8  rsvd4; 
  /** reserved for future use */ 
  uint8  rsvd5; 
  /** reserved for future use */ 
  uint8  rsvd6; 
  /** reserved for future use */ 
  uint8  rsvd7; 
} __PACKED__ cmd_cfg_sym_dsl_mode_t; 


/** message: CMD_CFG_AFE_PARAMS */

typedef struct cmd_cfg_afe_params_s 
{ 
  /** Selects the line driver mode */ 
  uint8  mode; 
  /** Resistance of the protection PTCs */ 
  uint8  ptc_value; 
  /** reserved for future use, should always be set to 0 */ 
  uint16  rsvd5; 
  /** reserved for future use, should always be set to 0 */ 
  uint8  rsvd1; 
  /** reserved for future use, should always be set to 0 */ 
  uint8  rsvd2; 
  /** reserved for future use, should always be set to 0 */ 
  uint8  rsvd3; 
  /** reserved for future use, should always be set to 0 */ 
  uint8  rsvd4; 
} __PACKED__ cmd_cfg_afe_params_t; 

/*@}*/ /* Device Configuration */


/** \addtogroup SDFE4_SHDSL_Configuration SHDSL Configuration */

/*@{*/


/* message identifiers */


 #define  CMD_CFG_GHS_MODE  0x2422 
 #define  CMD_CFG_CAPLIST_SHORT  0x2432 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2  0x2452 
 #define  CMD_CFG_CAPLIST  0x2412 
 #define  CMD_CFG_GHS_NS_FIELD  0x2442 
 #define  CMD_GHS_NS_FIELD_GET  0x2852 
 #define  CMD_GHS_CAP_GET  0x2822 
 #define  CMD_CFG_GHS_CAP  0x2462 
 #define  CMD_CFG_E1_ATM_OCTET_ALIGNED  0x0412 
 #define  CMD_CAPLIST_GET  0x2802 
 #define  CMD_CFG_EFM_DISCOVERY_DATA  0xE402 
 #define  CMD_EFM_DISCOVERY_DATA_GET  0xE802 
 #define  CMD_CFG_EFM_AGGREGATE_DATA  0xE412 
 #define  CMD_EFM_AGGREGATE_DATA_GET  0xE812 
 #define  CMD_EFM_START_ACTIVATION  0xEC02 
 #define  CMD_CFG_DSL_PARAM  0x4402 
 #define  CMD_DSL_PARAM_GET  0x4802 
 #define  CMD_CONNECT_CTRL  0x0C04 
 #define  CMD_CONNECT_STAT_GET  0x0804 
 #define  CMD_CFG_GHS_MODE_S  "CMD_CFG_GHS_MODE" 
 #define  CMD_CFG_CAPLIST_SHORT_S  "CMD_CFG_CAPLIST_SHORT" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_S  "CMD_CFG_CAPLIST_SHORT_VER_2" 
 #define  CMD_CFG_CAPLIST_S  "CMD_CFG_CAPLIST" 
 #define  CMD_CFG_GHS_NS_FIELD_S  "CMD_CFG_GHS_NS_FIELD" 
 #define  CMD_GHS_NS_FIELD_GET_S  "CMD_GHS_NS_FIELD_GET" 
 #define  CMD_GHS_CAP_GET_S  "CMD_GHS_CAP_GET" 
 #define  CMD_CFG_GHS_CAP_S  "CMD_CFG_GHS_CAP" 
 #define  CMD_CFG_E1_ATM_OCTET_ALIGNED_S  "CMD_CFG_E1_ATM_OCTET_ALIGNED" 
 #define  CMD_CAPLIST_GET_S  "CMD_CAPLIST_GET" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_S  "CMD_CFG_EFM_DISCOVERY_DATA" 
 #define  CMD_EFM_DISCOVERY_DATA_GET_S  "CMD_EFM_DISCOVERY_DATA_GET" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_S  "CMD_CFG_EFM_AGGREGATE_DATA" 
 #define  CMD_EFM_AGGREGATE_DATA_GET_S  "CMD_EFM_AGGREGATE_DATA_GET" 
 #define  CMD_EFM_START_ACTIVATION_S  "CMD_EFM_START_ACTIVATION" 
 #define  CMD_CFG_DSL_PARAM_S  "CMD_CFG_DSL_PARAM" 
 #define  CMD_DSL_PARAM_GET_S  "CMD_DSL_PARAM_GET" 
 #define  CMD_CONNECT_CTRL_S  "CMD_CONNECT_CTRL" 
 #define  CMD_CONNECT_STAT_GET_S  "CMD_CONNECT_STAT_GET" 



/* message elements: CMD_CFG_GHS_MODE */


 #define  CMD_CFG_GHS_MODE_transaction_S  L"transaction" 
 #define  CMD_CFG_GHS_MODE_startup_initialization_S  L"startup_initialization" 
 #define  CMD_CFG_GHS_MODE_pbo_mode_S  L"pbo_mode" 
 #define  CMD_CFG_GHS_MODE_pmms_margin_mode_S  L"pmms_margin_mode" 
 #define  CMD_CFG_GHS_MODE_epl_mode_S  L"epl_mode" 
 #define  CMD_CFG_GHS_MODE_pbo_offset_S  L"pbo_offset" 
 #define  CMD_CFG_GHS_MODE_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_GHS_MODE_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_GHS_MODE_rsvd4_S  L"rsvd4" 
 #define  CMD_CFG_GHS_MODE_rsvd5_S  L"rsvd5" 
 #define  CMD_CFG_GHS_MODE_rsvd6_S  L"rsvd6" 
 #define  CMD_CFG_GHS_MODE_rsvd7_S  L"rsvd7" 



/* message elements: CMD_CFG_CAPLIST_SHORT */


 #define  CMD_CFG_CAPLIST_SHORT_clock_mode_S  L"clock_mode" 
 #define  CMD_CFG_CAPLIST_SHORT_annex_S  L"annex" 
 #define  CMD_CFG_CAPLIST_SHORT_psd_mask_S  L"psd_mask" 
 #define  CMD_CFG_CAPLIST_SHORT_base_rate_min_S  L"base_rate_min" 
 #define  CMD_CFG_CAPLIST_SHORT_base_rate_max_S  L"base_rate_max" 
 #define  CMD_CFG_CAPLIST_SHORT_sub_rate_max_S  L"sub_rate_max" 
 #define  CMD_CFG_CAPLIST_SHORT_pow_backoff_S  L"pow_backoff" 
 #define  CMD_CFG_CAPLIST_SHORT_enable_pmms_S  L"enable_pmms" 
 #define  CMD_CFG_CAPLIST_SHORT_pmms_margin_S  L"pmms_margin" 
 #define  CMD_CFG_CAPLIST_SHORT_sub_rate_min_S  L"sub_rate_min" 
 #define  CMD_CFG_CAPLIST_SHORT_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_CAPLIST_SHORT_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_CAPLIST_SHORT_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_0_S  L"octet_no_0" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_0_S  L"octet_val_0" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_1_S  L"octet_no_1" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_1_S  L"octet_val_1" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_2_S  L"octet_no_2" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_2_S  L"octet_val_2" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_3_S  L"octet_no_3" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_3_S  L"octet_val_3" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_4_S  L"octet_no_4" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_4_S  L"octet_val_4" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_5_S  L"octet_no_5" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_5_S  L"octet_val_5" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_6_S  L"octet_no_6" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_6_S  L"octet_val_6" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_7_S  L"octet_no_7" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_7_S  L"octet_val_7" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_8_S  L"octet_no_8" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_8_S  L"octet_val_8" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_9_S  L"octet_no_9" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_9_S  L"octet_val_9" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_10_S  L"octet_no_10" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_10_S  L"octet_val_10" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_11_S  L"octet_no_11" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_11_S  L"octet_val_11" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_12_S  L"octet_no_12" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_12_S  L"octet_val_12" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_13_S  L"octet_no_13" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_13_S  L"octet_val_13" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_14_S  L"octet_no_14" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_14_S  L"octet_val_14" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_no_15_S  L"octet_no_15" 
 #define  CMD_CFG_CAPLIST_SHORT_octet_val_15_S  L"octet_val_15" 



/* message elements: CMD_CFG_CAPLIST_SHORT_VER_2 */


 #define  CMD_CFG_CAPLIST_SHORT_VER_2_clock_mode_S  L"clock_mode" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_annex_S  L"annex" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_psd_mask_S  L"psd_mask" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_pow_backoff_S  L"pow_backoff" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_base_rate_min_S  L"base_rate_min" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_base_rate_max_S  L"base_rate_max" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_base_rate_min16_S  L"base_rate_min16" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_base_rate_max16_S  L"base_rate_max16" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_base_rate_min32_S  L"base_rate_min32" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_base_rate_max32_S  L"base_rate_max32" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_sub_rate_min_S  L"sub_rate_min" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_sub_rate_max_S  L"sub_rate_max" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_enable_pmms_S  L"enable_pmms" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_pmms_margin_S  L"pmms_margin" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_annex_efm_S  L"annex_efm" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_0_S  L"octet_no_0" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_0_S  L"octet_val_0" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_1_S  L"octet_no_1" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_1_S  L"octet_val_1" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_2_S  L"octet_no_2" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_2_S  L"octet_val_2" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_3_S  L"octet_no_3" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_3_S  L"octet_val_3" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_4_S  L"octet_no_4" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_4_S  L"octet_val_4" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_5_S  L"octet_no_5" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_5_S  L"octet_val_5" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_6_S  L"octet_no_6" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_6_S  L"octet_val_6" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_7_S  L"octet_no_7" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_7_S  L"octet_val_7" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_8_S  L"octet_no_8" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_8_S  L"octet_val_8" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_9_S  L"octet_no_9" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_9_S  L"octet_val_9" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_10_S  L"octet_no_10" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_10_S  L"octet_val_10" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_11_S  L"octet_no_11" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_11_S  L"octet_val_11" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_12_S  L"octet_no_12" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_12_S  L"octet_val_12" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_13_S  L"octet_no_13" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_13_S  L"octet_val_13" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_14_S  L"octet_no_14" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_14_S  L"octet_val_14" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_no_15_S  L"octet_no_15" 
 #define  CMD_CFG_CAPLIST_SHORT_VER_2_octet_val_15_S  L"octet_val_15" 



/* message elements: CMD_CFG_CAPLIST */


 #define  CMD_CFG_CAPLIST_ghs_caplist_S  L"ghs_caplist" 



/* message elements: CMD_CFG_GHS_NS_FIELD */


 #define  CMD_CFG_GHS_NS_FIELD_valid_ns_data_S  L"valid_ns_data" 
 #define  CMD_CFG_GHS_NS_FIELD_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_GHS_NS_FIELD_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_GHS_NS_FIELD_ns_info_length_S  L"ns_info_length" 
 #define  CMD_CFG_GHS_NS_FIELD_ns_info_S  L"ns_info" 



/* message elements: CMD_GHS_CAP_GET */


 #define  CMD_GHS_CAP_GET_ClType_S  L"ClType" 
 #define  CMD_GHS_CAP_GET_ClParam_S  L"ClParam" 
 #define  CMD_GHS_CAP_GET_rsvd0_S  L"rsvd0" 
 #define  CMD_GHS_CAP_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_GHS_CAP_GET_rsvd2_S  L"rsvd2" 
 #define  CMD_GHS_CAP_GET_rsvd3_S  L"rsvd3" 
 #define  CMD_GHS_CAP_GET_rsvd4_S  L"rsvd4" 
 #define  CMD_GHS_CAP_GET_rsvd5_S  L"rsvd5" 



/* message elements: CMD_CFG_GHS_CAP */


 #define  CMD_CFG_GHS_CAP_ClParam_S  L"ClParam" 
 #define  CMD_CFG_GHS_CAP_ClStartOctet_S  L"ClStartOctet" 
 #define  CMD_CFG_GHS_CAP_ClNrOctets_S  L"ClNrOctets" 
 #define  CMD_CFG_GHS_CAP_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_GHS_CAP_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_GHS_CAP_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_GHS_CAP_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_GHS_CAP_rsvd4_S  L"rsvd4" 
 #define  CMD_CFG_GHS_CAP_ClData_S  L"ClData" 



/* message elements: CMD_CFG_E1_ATM_OCTET_ALIGNED */


 #define  CMD_CFG_E1_ATM_OCTET_ALIGNED_mode_S  L"mode" 
 #define  CMD_CFG_E1_ATM_OCTET_ALIGNED_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_E1_ATM_OCTET_ALIGNED_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_E1_ATM_OCTET_ALIGNED_rsvd3_S  L"rsvd3" 



/* message elements: CMD_CAPLIST_GET */


 #define  CMD_CAPLIST_GET_caplist_type_get_S  L"caplist_type_get" 
 #define  CMD_CAPLIST_GET_rsvd0_S  L"rsvd0" 
 #define  CMD_CAPLIST_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_CAPLIST_GET_rsvd2_S  L"rsvd2" 



/* message elements: CMD_CFG_EFM_DISCOVERY_DATA */


 #define  CMD_CFG_EFM_DISCOVERY_DATA_discovery_op_S  L"discovery_op" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_discovery_reg_hi_S  L"discovery_reg_hi" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_discovery_reg_lo_S  L"discovery_reg_lo" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_EFM_DISCOVERY_DATA_rsvd4_S  L"rsvd4" 



/* message elements: CMD_EFM_DISCOVERY_DATA_GET */


 #define  CMD_EFM_DISCOVERY_DATA_GET_rsvd0_S  L"rsvd0" 
 #define  CMD_EFM_DISCOVERY_DATA_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_EFM_DISCOVERY_DATA_GET_rsvd2_S  L"rsvd2" 
 #define  CMD_EFM_DISCOVERY_DATA_GET_rsvd3_S  L"rsvd3" 



/* message elements: CMD_CFG_EFM_AGGREGATE_DATA */


 #define  CMD_CFG_EFM_AGGREGATE_DATA_aggregate_op_S  L"aggregate_op" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_aggregate_reg_S  L"aggregate_reg" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd4_S  L"rsvd4" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd5_S  L"rsvd5" 
 #define  CMD_CFG_EFM_AGGREGATE_DATA_rsvd6_S  L"rsvd6" 



/* message elements: CMD_EFM_AGGREGATE_DATA_GET */


 #define  CMD_EFM_AGGREGATE_DATA_GET_rsvd0_S  L"rsvd0" 
 #define  CMD_EFM_AGGREGATE_DATA_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_EFM_AGGREGATE_DATA_GET_rsvd2_S  L"rsvd2" 
 #define  CMD_EFM_AGGREGATE_DATA_GET_rsvd3_S  L"rsvd3" 



/* message elements: CMD_EFM_START_ACTIVATION */


 #define  CMD_EFM_START_ACTIVATION_rsvd0_S  L"rsvd0" 
 #define  CMD_EFM_START_ACTIVATION_rsvd1_S  L"rsvd1" 
 #define  CMD_EFM_START_ACTIVATION_rsvd2_S  L"rsvd2" 
 #define  CMD_EFM_START_ACTIVATION_rsvd3_S  L"rsvd3" 



/* message elements: CMD_CFG_DSL_PARAM */


 #define  CMD_CFG_DSL_PARAM_stu_mode_S  L"stu_mode" 
 #define  CMD_CFG_DSL_PARAM_repeater_S  L"repeater" 
 #define  CMD_CFG_DSL_PARAM_annex_S  L"annex" 
 #define  CMD_CFG_DSL_PARAM_clk_ref_S  L"clk_ref" 
 #define  CMD_CFG_DSL_PARAM_base_rate_S  L"base_rate" 
 #define  CMD_CFG_DSL_PARAM_sub_rate_S  L"sub_rate" 
 #define  CMD_CFG_DSL_PARAM_psd_mask_S  L"psd_mask" 
 #define  CMD_CFG_DSL_PARAM_frame_mode_S  L"frame_mode" 
 #define  CMD_CFG_DSL_PARAM_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_DSL_PARAM_tx_sync_word_S  L"tx_sync_word" 
 #define  CMD_CFG_DSL_PARAM_rx_sync_word_S  L"rx_sync_word" 
 #define  CMD_CFG_DSL_PARAM_tx_stuff_bits_S  L"tx_stuff_bits" 
 #define  CMD_CFG_DSL_PARAM_rx_stuff_bits_S  L"rx_stuff_bits" 
 #define  CMD_CFG_DSL_PARAM_pow_backoff_S  L"pow_backoff" 
 #define  CMD_CFG_DSL_PARAM_pow_backoff_farend_S  L"pow_backoff_farend" 
 #define  CMD_CFG_DSL_PARAM_ghs_pwr_lev_carr_S  L"ghs_pwr_lev_carr" 
 #define  CMD_CFG_DSL_PARAM_bits_p_symbol_S  L"bits_p_symbol" 



/* message elements: CMD_CONNECT_CTRL */


 #define  CMD_CONNECT_CTRL_state_S  L"state" 
 #define  CMD_CONNECT_CTRL_rsvd1_S  L"rsvd1" 
 #define  CMD_CONNECT_CTRL_rsvd2_S  L"rsvd2" 



/* message definitions */

/** message: CMD_CFG_GHS_MODE */

typedef struct cmd_cfg_ghs_mode_s 
{ 
  /** Transaction type */ 
  uint8  transaction; 
  /** Initialization of the G.Hs session */ 
  uint8  startup_initialization; 
  /** Power Backoff Mode */ 
  uint8  pbo_mode; 
  /** Selection mode for the PMMS margin */ 
  uint8  pmms_margin_mode; 
  /** EPL Mode */ 
  uint8  epl_mode; 
  /** Offset from standard EPL-Based Power Backoff */ 
  int8  pbo_offset; 
  /** reserved for future use */ 
  uint8  rsvd2; 
  /** reserved for future use */ 
  uint8  rsvd3; 
  /** reserved for future use */ 
  uint8  rsvd4; 
  /** reserved for future use */ 
  uint8  rsvd5; 
  /** reserved for future use */ 
  uint8  rsvd6; 
  /** reserved for future use */ 
  uint8  rsvd7; 
} __PACKED__ cmd_cfg_ghs_mode_t; 


/** message: CMD_CFG_CAPLIST_SHORT */

typedef struct cmd_cfg_caplist_short_s 
{ 
  /** Clocking Mode according to g.991.2 */ 
  uint8  clock_mode; 
  /** Annex */ 
  uint8  annex; 
  /** Power Spectral Density Mask */ 
  uint8  psd_mask; 
  /** Minimum of the range of Base Data Rates or first rate in case of asymmetric PSDs */ 
  uint16  base_rate_min; 
  /** Maximum of the range of Base Data Rates or second rate in case of asymmetric PSDs */ 
  uint16  base_rate_max; 
  /** Sub Data rate */ 
  uint8  sub_rate_max; 
  /** Power Backoff */ 
  uint8  pow_backoff; 
  /** Enable PMMS */ 
  uint8  enable_pmms; 
  /** SNR margin for PMMS */ 
  uint8  pmms_margin; 
  /** Minimum Sub data rate */ 
  uint8  sub_rate_min; 
  /** for future use */ 
  uint8  rsvd1; 
  /** for future use */ 
  uint8  rsvd2; 
  /** for future use */ 
  uint8  rsvd3; 
  /** number of the octet */ 
  uint8  octet_no_0; 
  /** value of the coctet */ 
  uint8  octet_val_0; 
  /** number of the octet */ 
  uint8  octet_no_1; 
  /** value of the coctet */ 
  uint8  octet_val_1; 
  /** number of the octet */ 
  uint8  octet_no_2; 
  /** value of the coctet */ 
  uint8  octet_val_2; 
  /** number of the octet */ 
  uint8  octet_no_3; 
  /** value of the coctet */ 
  uint8  octet_val_3; 
  /** number of the octet */ 
  uint8  octet_no_4; 
  /** value of the coctet */ 
  uint8  octet_val_4; 
  /** number of the octet */ 
  uint8  octet_no_5; 
  /** value of the coctet */ 
  uint8  octet_val_5; 
  /** number of the octet */ 
  uint8  octet_no_6; 
  /** value of the coctet */ 
  uint8  octet_val_6; 
  /** number of the octet */ 
  uint8  octet_no_7; 
  /** value of the coctet */ 
  uint8  octet_val_7; 
  /** number of the octet */ 
  uint8  octet_no_8; 
  /** value of the coctet */ 
  uint8  octet_val_8; 
  /** number of the octet */ 
  uint8  octet_no_9; 
  /** value of the coctet */ 
  uint8  octet_val_9; 
  /** number of the octet */ 
  uint8  octet_no_10; 
  /** value of the coctet */ 
  uint8  octet_val_10; 
  /** number of the octet */ 
  uint8  octet_no_11; 
  /** value of the coctet */ 
  uint8  octet_val_11; 
  /** number of the octet */ 
  uint8  octet_no_12; 
  /** value of the coctet */ 
  uint8  octet_val_12; 
  /** number of the octet */ 
  uint8  octet_no_13; 
  /** value of the coctet */ 
  uint8  octet_val_13; 
  /** number of the octet */ 
  uint8  octet_no_14; 
  /** value of the coctet */ 
  uint8  octet_val_14; 
  /** number of the octet */ 
  uint8  octet_no_15; 
  /** value of the coctet */ 
  uint8  octet_val_15; 
} __PACKED__ cmd_cfg_caplist_short_t; 


/** message: CMD_CFG_CAPLIST_SHORT_VER_2 */

typedef struct cmd_cfg_caplist_short_ver_2_s 
{ 
  /** Clocking Mode according to G.991.2 */ 
  uint8  clock_mode; 
  /** Annex */ 
  uint8  annex; 
  /** Power Spectral Density Mask */ 
  uint8  psd_mask; 
  /** Power Backoff */ 
  uint8  pow_backoff; 
  /** Minimum of the range of Base Data Rates (out of range 192 kbit/s to 2304 kbit/s) or first rate in case of asymmetric PSDs */ 
  uint16  base_rate_min; 
  /** Maximum of the range of Base Data Rates (out of range 192 kbit/s to 2304 kbit/s) or second rate in case of asymmetric PSDs */ 
  uint16  base_rate_max; 
  /** Minimum of the range of extended Base Data Rates 16 TC-PAM (out of range 2304 kbit/s to 3840 kbit/s). */ 
  uint16  base_rate_min16; 
  /** Maximum of the range of extended Base Data Rates 16 TC-PAM (out of range 2304 kbit/s to 3840 kbit/s). */ 
  uint16  base_rate_max16; 
  /** Minimum of the range of extended Base Data Rates 32 TC-PAM (out of range 768 kbit/s to 5696 kbit/s). */ 
  uint16  base_rate_min32; 
  /** Maximum of the range of extended Base Data Rates 32 TC-PAM (out of range 768 kbit/s to 5696 kbit/s). */ 
  uint16  base_rate_max32; 
  /** Minimum Sub data rate */ 
  uint8  sub_rate_min; 
  /** Sub Data rate */ 
  uint8  sub_rate_max; 
  /** Enable PMMS */ 
  uint8  enable_pmms; 
  /** PMMS target margin in dB */ 
  uint8  pmms_margin; 
  /** Supported Annexes of Annex EFM */ 
  uint8  annex_efm; 
  /** for future use */ 
  uint8  rsvd1; 
  /** for future use */ 
  uint8  rsvd2; 
  /** for future use */ 
  uint8  rsvd3; 
  /** number of the octet */ 
  uint8  octet_no_0; 
  /** value of the coctet */ 
  uint8  octet_val_0; 
  /** number of the octet */ 
  uint8  octet_no_1; 
  /** value of the coctet */ 
  uint8  octet_val_1; 
  /** number of the octet */ 
  uint8  octet_no_2; 
  /** value of the coctet */ 
  uint8  octet_val_2; 
  /** number of the octet */ 
  uint8  octet_no_3; 
  /** value of the coctet */ 
  uint8  octet_val_3; 
  /** number of the octet */ 
  uint8  octet_no_4; 
  /** value of the coctet */ 
  uint8  octet_val_4; 
  /** number of the octet */ 
  uint8  octet_no_5; 
  /** value of the coctet */ 
  uint8  octet_val_5; 
  /** number of the octet */ 
  uint8  octet_no_6; 
  /** value of the coctet */ 
  uint8  octet_val_6; 
  /** number of the octet */ 
  uint8  octet_no_7; 
  /** value of the coctet */ 
  uint8  octet_val_7; 
  /** number of the octet */ 
  uint8  octet_no_8; 
  /** value of the coctet */ 
  uint8  octet_val_8; 
  /** number of the octet */ 
  uint8  octet_no_9; 
  /** value of the coctet */ 
  uint8  octet_val_9; 
  /** number of the octet */ 
  uint8  octet_no_10; 
  /** value of the coctet */ 
  uint8  octet_val_10; 
  /** number of the octet */ 
  uint8  octet_no_11; 
  /** value of the coctet */ 
  uint8  octet_val_11; 
  /** number of the octet */ 
  uint8  octet_no_12; 
  /** value of the coctet */ 
  uint8  octet_val_12; 
  /** number of the octet */ 
  uint8  octet_no_13; 
  /** value of the coctet */ 
  uint8  octet_val_13; 
  /** number of the octet */ 
  uint8  octet_no_14; 
  /** value of the coctet */ 
  uint8  octet_val_14; 
  /** number of the octet */ 
  uint8  octet_no_15; 
  /** value of the coctet */ 
  uint8  octet_val_15; 
} __PACKED__ cmd_cfg_caplist_short_ver_2_t; 


/** message: CMD_CFG_CAPLIST */

typedef struct cmd_cfg_caplist_s 
{ 
  /** ghs_caplist */ 
  uint8  ghs_caplist[120]; 
} __PACKED__ cmd_cfg_caplist_t; 


/** message: CMD_CFG_GHS_NS_FIELD */

typedef struct cmd_cfg_ghs_ns_field_s 
{ 
  /** valid_ns_data */ 
  uint8  valid_ns_data; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** ns_info_length */ 
  uint8  ns_info_length; 
  /** ns_info */ 
  uint8  ns_info[16]; 
} __PACKED__ cmd_cfg_ghs_ns_field_t; 


/** message: CMD_GHS_CAP_GET */

typedef struct cmd_ghs_cap_get_s 
{ 
  /** ClType */ 
  uint8  ClType; 
  /** ClParam */ 
  uint8  ClParam; 
  /** rsvd0 */ 
  uint8  rsvd0; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** rsvd3 */ 
  uint8  rsvd3; 
  /** rsvd4 */ 
  uint8  rsvd4; 
  /** rsvd5 */ 
  uint8  rsvd5; 
} __PACKED__ cmd_ghs_cap_get_t; 


/** message: CMD_CFG_GHS_CAP */

typedef struct cmd_cfg_ghs_cap_s 
{ 
  /** ClParam */ 
  uint8  ClParam; 
  /** ClStartOctet */ 
  uint8  ClStartOctet; 
  /** ClNrOctets */ 
  uint8  ClNrOctets; 
  /** rsvd0 */ 
  uint8  rsvd0; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** rsvd3 */ 
  uint8  rsvd3; 
  /** rsvd4 */ 
  uint8  rsvd4; 
  /** ClData */ 
  uint8  ClData[32]; 
} __PACKED__ cmd_cfg_ghs_cap_t; 


/** message: CMD_CFG_E1_ATM_OCTET_ALIGNED */

typedef struct cmd_cfg_e1_atm_octet_aligned_s 
{ 
  /** The framing mode */ 
  uint8  mode; 
  /** reserved. Should be set to zero. */ 
  uint8  rsvd1; 
  /** reserved. Should be set to zero. */ 
  uint8  rsvd2; 
  /** reserved. Should be set to zero. */ 
  uint8  rsvd3; 
} __PACKED__ cmd_cfg_e1_atm_octet_aligned_t; 


/** message: CMD_CAPLIST_GET */

typedef struct cmd_caplist_get_s 
{ 
  /** caplist_type_get */ 
  uint8  caplist_type_get; 
  /** Reserved. Should be set to Zero. */ 
  uint8  rsvd0; 
  /** Reserved. Should be set to Zero. */ 
  uint8  rsvd1; 
  /** Reserved. Should be set to Zero. */ 
  uint8  rsvd2; 
} __PACKED__ cmd_caplist_get_t; 


/** message: CMD_CFG_EFM_DISCOVERY_DATA */

typedef struct cmd_cfg_efm_discovery_data_s 
{ 
  /** discovery_op */ 
  uint8  discovery_op; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** discovery_reg_hi */ 
  uint16  discovery_reg_hi; 
  /** discovery_reg_lo */ 
  uint32  discovery_reg_lo; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
  /** Reserved */ 
  uint8  rsvd4; 
} __PACKED__ cmd_cfg_efm_discovery_data_t; 


/** message: CMD_EFM_DISCOVERY_DATA_GET */

typedef struct cmd_efm_discovery_data_get_s 
{ 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ cmd_efm_discovery_data_get_t; 


/** message: CMD_CFG_EFM_AGGREGATE_DATA */

typedef struct cmd_cfg_efm_aggregate_data_s 
{ 
  /** aggregate_op */ 
  uint8  aggregate_op; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** aggregate_reg */ 
  uint32  aggregate_reg; 
  /** Reserved */ 
  uint8  rsvd3; 
  /** Reserved */ 
  uint8  rsvd4; 
  /** Reserved */ 
  uint8  rsvd5; 
  /** Reserved */ 
  uint8  rsvd6; 
} __PACKED__ cmd_cfg_efm_aggregate_data_t; 


/** message: CMD_EFM_AGGREGATE_DATA_GET */

typedef struct cmd_efm_aggregate_data_get_s 
{ 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ cmd_efm_aggregate_data_get_t; 


/** message: CMD_EFM_START_ACTIVATION */

typedef struct cmd_efm_start_activation_s 
{ 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ cmd_efm_start_activation_t; 


/** message: CMD_CFG_DSL_PARAM */

typedef struct cmd_cfg_dsl_param_s 
{ 
  /** STU Mode */ 
  uint8  stu_mode; 
  /** Repeater or Terminator */ 
  uint8  repeater; 
  /** Annex */ 
  uint8  annex; 
  /** Clocking Mode */ 
  uint8  clk_ref; 
  /** Payload Base Rate */ 
  uint16  base_rate; 
  /** Payload Sub Rate */ 
  uint8  sub_rate; 
  /** Power Spectral Density Mask */ 
  uint8  psd_mask; 
  /** SHDSL Framing Mode */ 
  uint8  frame_mode; 
  /** Rsvd */ 
  uint8  rsvd2; 
  /** Tx Sync Word */ 
  uint16  tx_sync_word; 
  /** Rx Sync Word */ 
  uint16  rx_sync_word; 
  /** Tx Stuff Bits */ 
  uint8  tx_stuff_bits; 
  /** Rx Stuff Bits */ 
  uint8  rx_stuff_bits; 
  /** Power Backoff */ 
  int8  pow_backoff; 
  /** Power Backoff Far End */ 
  int8  pow_backoff_farend; 
  /** Handshake Power Leverage Carrier */ 
  uint8  ghs_pwr_lev_carr; 
  /** Bits per Symbol */ 
  uint8  bits_p_symbol; 
} __PACKED__ cmd_cfg_dsl_param_t; 


/** message: CMD_CONNECT_CTRL */

typedef struct cmd_connect_ctrl_s 
{ 
  /** State */ 
  int8  state; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ cmd_connect_ctrl_t; 

/*@}*/ /* SHDSL Configuration */


/** \addtogroup SDFE4_SHDSL_EOC_and_Fbits SHDSL EOC and Fbits */

/*@{*/


/* message identifiers */


 #define  CMD_CFG_PERF_PRIM  0x9402 
 #define  CMD_PERF_PRIM_GET  0x9442 
 #define  CMD_CFG_REQ_SHDSL  0x9422 
 #define  CMD_PERF_STATUS_GET  0x9432 
 #define  CMD_PERF_DETAILS_GET  0x9803 
 #define  CMD_FBIT_TX  0x9452 
 #define  CMD_CFG_FBIT_RX  0x9412 
 #define  CMD_FBIT_RX_GET  0x9C02 
 #define  CMD_EOC_TX  0xAC02 
 #define  CMD_CFG_EOC_RX  0xA422 
 #define  CMD_CFG_PERF_PRIM_S  "CMD_CFG_PERF_PRIM" 
 #define  CMD_PERF_PRIM_GET_S  "CMD_PERF_PRIM_GET" 
 #define  CMD_CFG_REQ_SHDSL_S  "CMD_CFG_REQ_SHDSL" 
 #define  CMD_PERF_STATUS_GET_S  "CMD_PERF_STATUS_GET" 
 #define  CMD_PERF_DETAILS_GET_S  "CMD_PERF_DETAILS_GET" 
 #define  CMD_FBIT_TX_S  "CMD_FBIT_TX" 
 #define  CMD_CFG_FBIT_RX_S  "CMD_CFG_FBIT_RX" 
 #define  CMD_FBIT_RX_GET_S  "CMD_FBIT_RX_GET" 
 #define  CMD_EOC_TX_S  "CMD_EOC_TX" 
 #define  CMD_CFG_EOC_RX_S  "CMD_CFG_EOC_RX" 



/* message elements: CMD_CFG_PERF_PRIM */


 #define  CMD_CFG_PERF_PRIM_prims_S  L"prims" 



/* message elements: CMD_CFG_REQ_SHDSL */


 #define  CMD_CFG_REQ_SHDSL_thresholds_0_S  L"thresholds_0" 
 #define  CMD_CFG_REQ_SHDSL_thresholds_1_S  L"thresholds_1" 



/* message elements: CMD_FBIT_TX */


 #define  CMD_FBIT_TX_fbits_S  L"fbits" 



/* message elements: CMD_CFG_FBIT_RX */


 #define  CMD_CFG_FBIT_RX_fbits_S  L"fbits" 



/* message elements: CMD_EOC_TX */


 #define  CMD_EOC_TX_xme_S  L"xme" 
 #define  CMD_EOC_TX_num_bytes_S  L"num_bytes" 
 #define  CMD_EOC_TX_msg_S  L"msg" 



/* message elements: CMD_CFG_EOC_RX */


 #define  CMD_CFG_EOC_RX_max_num_bytes_S  L"max_num_bytes" 



/* message definitions */

/** message: CMD_CFG_PERF_PRIM */

typedef struct cmd_cfg_perf_prim_s 
{ 
  /** Bit vector for performance primitives */ 
  uint8  prims; 
} __PACKED__ cmd_cfg_perf_prim_t; 


/** message: CMD_CFG_REQ_SHDSL */

typedef struct cmd_cfg_req_shdsl_s 
{ 
  /** Bit slices in this field (bit 7: MSB; bit 0: LSB) */ 
  uint8  thresholds_0; 
  /** Bit slices in this field */ 
  uint8  thresholds_1; 
} __PACKED__ cmd_cfg_req_shdsl_t; 


/** message: CMD_FBIT_TX */

typedef struct cmd_fbit_tx_s 
{ 
  /** The four fbits of the SHDSL frame (bit3: MSB; bit0: LSB) */ 
  uint8  fbits; 
} __PACKED__ cmd_fbit_tx_t; 


/** message: CMD_CFG_FBIT_RX */

typedef struct cmd_cfg_fbit_rx_s 
{ 
  /** The four fbits of the SHDSL frame (bit3: MSB; bit0: LSB */ 
  uint8  fbits; 
} __PACKED__ cmd_cfg_fbit_rx_t; 


/** message: CMD_EOC_TX */

typedef struct cmd_eoc_tx_s 
{ 
  /** Transmit message end flag */ 
  uint8  xme; 
  /** The number of valid bytes in the msg field */ 
  uint8  num_bytes; 
  /** EOC bytes to be transmitted */ 
  uint8  msg[112]; 
} __PACKED__ cmd_eoc_tx_t; 


/** message: CMD_CFG_EOC_RX */

typedef struct cmd_cfg_eoc_rx_s 
{ 
  /** Maximum number of bytes of an EOC RX message. */ 
  uint16  max_num_bytes; 
} __PACKED__ cmd_cfg_eoc_rx_t; 

/*@}*/ /* SHDSL EOC and Fbits */


/** \addtogroup SDFE4_SHDSL_Line_Probing_(PMMS) SHDSL Line Probing (PMMS) */

/*@{*/


/* message identifiers */


 #define  CMD_PMMS_RESULTS_GET  0xC82F 
 #define  CMD_PMMS_RESULTS_GET_S  "CMD_PMMS_RESULTS_GET" 



/* message definitions */


/*@}*/ /* SHDSL Line Probing (PMMS) */


/** \addtogroup SDFE4_Serial_Data_Interface Serial Data Interface */

/*@{*/


/* message identifiers */


 #define  CMD_CFG_SDI_SETTINGS  0x840F 
 #define  CMD_CFG_SDI_SET_EXTENDED  0x845F 
 #define  CMD_CFG_SDI_TX  0x841F 
 #define  CMD_CFG_SDI_RX  0x842F 
 #define  CMD_CFG_SDI_DLY  0x846F 
 #define  CMD_CFG_SDI_IL_CHANNELS_TX  0x848F 
 #define  CMD_CFG_SDI_IL_CHANNELS_RX  0x849F 
 #define  CMD_CFG_SDI_FRAMER_TX  0x843F 
 #define  CMD_CFG_SDI_FRAMER_RX  0x844F 
 #define  CMD_CFG_SDI_SETTINGS_S  "CMD_CFG_SDI_SETTINGS" 
 #define  CMD_CFG_SDI_SET_EXTENDED_S  "CMD_CFG_SDI_SET_EXTENDED" 
 #define  CMD_CFG_SDI_TX_S  "CMD_CFG_SDI_TX" 
 #define  CMD_CFG_SDI_RX_S  "CMD_CFG_SDI_RX" 
 #define  CMD_CFG_SDI_DLY_S  "CMD_CFG_SDI_DLY" 
 #define  CMD_CFG_SDI_IL_CHANNELS_TX_S  "CMD_CFG_SDI_IL_CHANNELS_TX" 
 #define  CMD_CFG_SDI_IL_CHANNELS_RX_S  "CMD_CFG_SDI_IL_CHANNELS_RX" 
 #define  CMD_CFG_SDI_FRAMER_TX_S  "CMD_CFG_SDI_FRAMER_TX" 
 #define  CMD_CFG_SDI_FRAMER_RX_S  "CMD_CFG_SDI_FRAMER_RX" 



/* message elements: CMD_CFG_SDI_SETTINGS */


 #define  CMD_CFG_SDI_SETTINGS_input_mode_S  L"input_mode" 
 #define  CMD_CFG_SDI_SETTINGS_output_mode_S  L"output_mode" 
 #define  CMD_CFG_SDI_SETTINGS_frequency_S  L"frequency" 
 #define  CMD_CFG_SDI_SETTINGS_payload_bits_S  L"payload_bits" 
 #define  CMD_CFG_SDI_SETTINGS_frames_S  L"frames" 
 #define  CMD_CFG_SDI_SETTINGS_loop_S  L"loop" 
 #define  CMD_CFG_SDI_SETTINGS_ext_clk8k_S  L"ext_clk8k" 
 #define  CMD_CFG_SDI_SETTINGS_dpll4bclk_S  L"dpll4bclk" 
 #define  CMD_CFG_SDI_SETTINGS_refclkin_freq_S  L"refclkin_freq" 
 #define  CMD_CFG_SDI_SETTINGS_refclkout_freq_S  L"refclkout_freq" 



/* message elements: CMD_CFG_SDI_SET_EXTENDED */


 #define  CMD_CFG_SDI_SET_EXTENDED_payload_bits_S  L"payload_bits" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd4_S  L"rsvd4" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd5_S  L"rsvd5" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd6_S  L"rsvd6" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd7_S  L"rsvd7" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd8_S  L"rsvd8" 
 #define  CMD_CFG_SDI_SET_EXTENDED_rsvd9_S  L"rsvd9" 



/* message elements: CMD_CFG_SDI_TX */


 #define  CMD_CFG_SDI_TX_data_shift_S  L"data_shift" 
 #define  CMD_CFG_SDI_TX_frame_shift_S  L"frame_shift" 
 #define  CMD_CFG_SDI_TX_sp_level_S  L"sp_level" 
 #define  CMD_CFG_SDI_TX_sp_sample_edg_S  L"sp_sample_edg" 
 #define  CMD_CFG_SDI_TX_data_sample_edg_S  L"data_sample_edg" 
 #define  CMD_CFG_SDI_TX_lstwr_1strd_dly_S  L"lstwr_1strd_dly" 
 #define  CMD_CFG_SDI_TX_slip_mode_S  L"slip_mode" 
 #define  CMD_CFG_SDI_TX_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SDI_TX_align_S  L"align" 
 #define  CMD_CFG_SDI_TX_rsvd3_S  L"rsvd3" 



/* message elements: CMD_CFG_SDI_RX */


 #define  CMD_CFG_SDI_RX_data_shift_S  L"data_shift" 
 #define  CMD_CFG_SDI_RX_frame_shift_S  L"frame_shift" 
 #define  CMD_CFG_SDI_RX_sp_level_S  L"sp_level" 
 #define  CMD_CFG_SDI_RX_driving_edg_S  L"driving_edg" 
 #define  CMD_CFG_SDI_RX_data_shift_edg_S  L"data_shift_edg" 
 #define  CMD_CFG_SDI_RX_lstwr_1strd_dly_S  L"lstwr_1strd_dly" 
 #define  CMD_CFG_SDI_RX_slip_mode_S  L"slip_mode" 
 #define  CMD_CFG_SDI_RX_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SDI_RX_align_S  L"align" 
 #define  CMD_CFG_SDI_RX_rsvd3_S  L"rsvd3" 



/* message elements: CMD_CFG_SDI_DLY */


 #define  CMD_CFG_SDI_DLY_frame_shift_S  L"frame_shift" 
 #define  CMD_CFG_SDI_DLY_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_SDI_DLY_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SDI_DLY_rsvd2_S  L"rsvd2" 



/* message elements: CMD_CFG_SDI_IL_CHANNELS_TX */


 #define  CMD_CFG_SDI_IL_CHANNELS_TX_il_ch_count_S  L"il_ch_count" 
 #define  CMD_CFG_SDI_IL_CHANNELS_TX_active_il_ch_S  L"active_il_ch" 
 #define  CMD_CFG_SDI_IL_CHANNELS_TX_il_ch_gr_S  L"il_ch_gr" 
 #define  CMD_CFG_SDI_IL_CHANNELS_TX_rsvd1_S  L"rsvd1" 



/* message elements: CMD_CFG_SDI_IL_CHANNELS_RX */


 #define  CMD_CFG_SDI_IL_CHANNELS_RX_il_ch_count_S  L"il_ch_count" 
 #define  CMD_CFG_SDI_IL_CHANNELS_RX_active_il_ch_S  L"active_il_ch" 
 #define  CMD_CFG_SDI_IL_CHANNELS_RX_il_ch_gr_S  L"il_ch_gr" 
 #define  CMD_CFG_SDI_IL_CHANNELS_RX_rsvd1_S  L"rsvd1" 



/* message elements: CMD_CFG_SDI_FRAMER_TX */


 #define  CMD_CFG_SDI_FRAMER_TX_opcode0_S  L"opcode0" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode1_S  L"opcode1" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode2_S  L"opcode2" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode3_S  L"opcode3" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode4_S  L"opcode4" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode5_S  L"opcode5" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode6_S  L"opcode6" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode7_S  L"opcode7" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode8_S  L"opcode8" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode9_S  L"opcode9" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode10_S  L"opcode10" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode11_S  L"opcode11" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode12_S  L"opcode12" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode13_S  L"opcode13" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode14_S  L"opcode14" 
 #define  CMD_CFG_SDI_FRAMER_TX_opcode15_S  L"opcode15" 
 #define  CMD_CFG_SDI_FRAMER_TX_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_SDI_FRAMER_TX_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SDI_FRAMER_TX_rsvd2_S  L"rsvd2" 



/* message elements: CMD_CFG_SDI_FRAMER_RX */


 #define  CMD_CFG_SDI_FRAMER_RX_opcode0_S  L"opcode0" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode1_S  L"opcode1" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode2_S  L"opcode2" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode3_S  L"opcode3" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode4_S  L"opcode4" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode5_S  L"opcode5" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode6_S  L"opcode6" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode7_S  L"opcode7" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode8_S  L"opcode8" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode9_S  L"opcode9" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode10_S  L"opcode10" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode11_S  L"opcode11" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode12_S  L"opcode12" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode13_S  L"opcode13" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode14_S  L"opcode14" 
 #define  CMD_CFG_SDI_FRAMER_RX_opcode15_S  L"opcode15" 
 #define  CMD_CFG_SDI_FRAMER_RX_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_SDI_FRAMER_RX_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_SDI_FRAMER_RX_rsvd2_S  L"rsvd2" 



/* message definitions */

/** message: CMD_CFG_SDI_SETTINGS */

typedef struct cmd_cfg_sdi_settings_s 
{ 
  /** Clock mode for SDI input */ 
  uint8  input_mode; 
  /** Clock mode for SDI output */ 
  uint8  output_mode; 
  /** SDI Frequency */ 
  uint16  frequency; 
  /** Payload Bit Rate in kbits per second */ 
  uint16  payload_bits; 
  /** Frames per multiframe */ 
  uint8  frames; 
  /** Loop Selection */ 
  uint8  loop; 
  /** External clock on TX side */ 
  uint8  ext_clk8k; 
  /** DPLL activation */ 
  uint8  dpll4bclk; 
  /** RefClk input frequency */ 
  uint8  refclkin_freq; 
  /** RefClk output frequency */ 
  uint8  refclkout_freq; 
} __PACKED__ cmd_cfg_sdi_settings_t; 


/** message: CMD_CFG_SDI_SET_EXTENDED */

typedef struct cmd_cfg_sdi_set_extended_s 
{ 
  /** Payload Bit Rate in kbits per second */ 
  uint16  payload_bits; 
  /** Reserved */ 
  uint16  rsvd0; 
  /** Reserved */ 
  uint16  rsvd1; 
  /** Reserved */ 
  uint16  rsvd2; 
  /** Reserved */ 
  uint16  rsvd3; 
  /** Reserved */ 
  uint16  rsvd4; 
  /** Reserved */ 
  uint16  rsvd5; 
  /** Reserved */ 
  uint16  rsvd6; 
  /** Reserved */ 
  uint16  rsvd7; 
  /** Reserved */ 
  uint16  rsvd8; 
  /** Reserved */ 
  uint16  rsvd9; 
} __PACKED__ cmd_cfg_sdi_set_extended_t; 


/** message: CMD_CFG_SDI_TX */

typedef struct cmd_cfg_sdi_tx_s 
{ 
  /** Data shift referring to SP (8kHz) in bits */ 
  int32  data_shift; 
  /** Data shift referring to MSP (166 Hz) in SP frames */ 
  int8  frame_shift; 
  /** SP and MSP active level */ 
  uint8  sp_level; 
  /** SP and MSP sampling edge */ 
  uint8  sp_sample_edg; 
  /** Data sampling edge */ 
  uint8  data_sample_edg; 
  /** Write to Read delay in Slip buffer */ 
  int32  lstwr_1strd_dly; 
  /** Setting for slip buffers */ 
  uint8  slip_mode; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Data delay independend of payload rate */ 
  uint8  align; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ cmd_cfg_sdi_tx_t; 


/** message: CMD_CFG_SDI_RX */

typedef struct cmd_cfg_sdi_rx_s 
{ 
  /** Data shift referring to SP (8kHz) in bits */ 
  int32  data_shift; 
  /** Data shift referring to MSP (166 Hz) in SP frames */ 
  int8  frame_shift; 
  /** SP and MSP active level */ 
  uint8  sp_level; 
  /** driving edge for DATA, SP and MSP */ 
  uint8  driving_edg; 
  /** Data is shifted to the opposite driving edge */ 
  uint8  data_shift_edg; 
  /** Write to Read delay in Slip buffer */ 
  int32  lstwr_1strd_dly; 
  /** Setting for slip buffers */ 
  uint8  slip_mode; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Data delay independend of payload rate */ 
  uint8  align; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ cmd_cfg_sdi_rx_t; 


/** message: CMD_CFG_SDI_DLY */

typedef struct cmd_cfg_sdi_dly_s 
{ 
  /** Data shift referring to MSP (166 Hz) in SP frames */ 
  int8  frame_shift; 
  /** Reserved, should be set to Zero. */ 
  uint8  rsvd0; 
  /** Reserved, should be set to Zero. */ 
  uint8  rsvd1; 
  /** Reserved, should be set to Zero. */ 
  uint8  rsvd2; 
} __PACKED__ cmd_cfg_sdi_dly_t; 


/** message: CMD_CFG_SDI_IL_CHANNELS_TX */

typedef struct cmd_cfg_sdi_il_channels_tx_s 
{ 
  /** Number of interleaving channels */ 
  uint8  il_ch_count; 
  /** Number of the interleaving channel occupied by the current PAMDSL channel */ 
  uint8  active_il_ch; 
  /** Interleaving channel granularity */ 
  uint8  il_ch_gr; 
  /** Reserved. Should be set to Zero. */ 
  uint8  rsvd1; 
} __PACKED__ cmd_cfg_sdi_il_channels_tx_t; 


/** message: CMD_CFG_SDI_IL_CHANNELS_RX */

typedef struct cmd_cfg_sdi_il_channels_rx_s 
{ 
  /** Number of interleaving channels */ 
  uint8  il_ch_count; 
  /** Number of the interleaving channel occupied by the current PAMDSL channel */ 
  uint8  active_il_ch; 
  /** Interleaving channel granularity */ 
  uint8  il_ch_gr; 
  /** Reserved. Should be set to Zero. */ 
  uint8  rsvd1; 
} __PACKED__ cmd_cfg_sdi_il_channels_rx_t; 


/** message: CMD_CFG_SDI_FRAMER_TX */

typedef struct cmd_cfg_sdi_framer_tx_s 
{ 
  /** opcode for SDI framer */ 
  uint32  opcode0; 
  /** opcode for SDI framer */ 
  uint32  opcode1; 
  /** opcode for SDI framer */ 
  uint32  opcode2; 
  /** opcode for SDI framer */ 
  uint32  opcode3; 
  /** opcode for SDI framer */ 
  uint32  opcode4; 
  /** opcode for SDI framer */ 
  uint32  opcode5; 
  /** opcode for SDI framer */ 
  uint32  opcode6; 
  /** opcode for SDI framer */ 
  uint32  opcode7; 
  /** opcode for SDI framer */ 
  uint32  opcode8; 
  /** opcode for SDI framer */ 
  uint32  opcode9; 
  /** opcode for SDI framer */ 
  uint32  opcode10; 
  /** opcode for SDI framer */ 
  uint32  opcode11; 
  /** opcode for SDI framer */ 
  uint32  opcode12; 
  /** opcode for SDI framer */ 
  uint32  opcode13; 
  /** opcode for SDI framer */ 
  uint32  opcode14; 
  /** opcode for SDI framer */ 
  uint32  opcode15; 
  /** This field should always be set to zero */ 
  uint32  rsvd0; 
  /** This field should always be set to zero */ 
  uint32  rsvd1; 
  /** This field should always be set to zero */ 
  uint32  rsvd2; 
} __PACKED__ cmd_cfg_sdi_framer_tx_t; 


/** message: CMD_CFG_SDI_FRAMER_RX */

typedef struct cmd_cfg_sdi_framer_rx_s 
{ 
  /** opcode for SDI framer */ 
  uint32  opcode0; 
  /** opcode for SDI framer */ 
  uint32  opcode1; 
  /** opcode for SDI framer */ 
  uint32  opcode2; 
  /** opcode for SDI framer */ 
  uint32  opcode3; 
  /** opcode for SDI framer */ 
  uint32  opcode4; 
  /** opcode for SDI framer */ 
  uint32  opcode5; 
  /** opcode for SDI framer */ 
  uint32  opcode6; 
  /** opcode for SDI framer */ 
  uint32  opcode7; 
  /** opcode for SDI framer */ 
  uint32  opcode8; 
  /** opcode for SDI framer */ 
  uint32  opcode9; 
  /** opcode for SDI framer */ 
  uint32  opcode10; 
  /** opcode for SDI framer */ 
  uint32  opcode11; 
  /** opcode for SDI framer */ 
  uint32  opcode12; 
  /** opcode for SDI framer */ 
  uint32  opcode13; 
  /** opcode for SDI framer */ 
  uint32  opcode14; 
  /** opcode for SDI framer */ 
  uint32  opcode15; 
  /** This field should always be set to zero */ 
  uint32  rsvd0; 
  /** This field should always be set to zero */ 
  uint32  rsvd1; 
  /** This field should always be set to zero */ 
  uint32  rsvd2; 
} __PACKED__ cmd_cfg_sdi_framer_rx_t; 

/*@}*/ /* Serial Data Interface */


/** \addtogroup SDFE4_Multiwire_Mode Multiwire Mode */

/*@{*/


/* message identifiers */


 #define  CMD_CFG_MULTIWIRE_MASTER  0xB40F 
 #define  CMD_CFG_MULTIWIRE_SLAVE  0xB41F 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR  0xB42F 
 #define  CMD_MULTIWIRE_PMMS_RESULT_GET  0xB83F 
 #define  CMD_MULTIWIRE_MDATA_GET  0xB80F 
 #define  CMD_MULTIWIRE_SDATA_GET  0xB81F 
 #define  CMD_CFG_MULTIWIRE_OPERATION  0xB45F 
 #define  CMD_MPAIR_DELAY_MEASURE_SDFE4  0x8C0F 
 #define  CMD_MPAIR_RSFSC_ALIGN  0x8C02 
 #define  CMD_CFG_MULTIWIRE_MASTER_S  "CMD_CFG_MULTIWIRE_MASTER" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_S  "CMD_CFG_MULTIWIRE_SLAVE" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_S  "CMD_CFG_MULTIWIRE_PMMS_PAR" 
 #define  CMD_MULTIWIRE_PMMS_RESULT_GET_S  "CMD_MULTIWIRE_PMMS_RESULT_GET" 
 #define  CMD_MULTIWIRE_MDATA_GET_S  "CMD_MULTIWIRE_MDATA_GET" 
 #define  CMD_MULTIWIRE_SDATA_GET_S  "CMD_MULTIWIRE_SDATA_GET" 
 #define  CMD_CFG_MULTIWIRE_OPERATION_S  "CMD_CFG_MULTIWIRE_OPERATION" 
 #define  CMD_MPAIR_DELAY_MEASURE_SDFE4_S  "CMD_MPAIR_DELAY_MEASURE_SDFE4" 
 #define  CMD_MPAIR_RSFSC_ALIGN_S  "CMD_MPAIR_RSFSC_ALIGN" 



/* message elements: CMD_CFG_MULTIWIRE_MASTER */


 #define  CMD_CFG_MULTIWIRE_MASTER_MPairMode_S  L"MPairMode" 
 #define  CMD_CFG_MULTIWIRE_MASTER_NrWirePairs_S  L"NrWirePairs" 
 #define  CMD_CFG_MULTIWIRE_MASTER_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_MULTIWIRE_MASTER_ValidDataSlotsSDI_S  L"ValidDataSlotsSDI" 
 #define  CMD_CFG_MULTIWIRE_MASTER_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_MULTIWIRE_MASTER_SlaveID_1_S  L"SlaveID_1" 
 #define  CMD_CFG_MULTIWIRE_MASTER_SlaveID_2_S  L"SlaveID_2" 
 #define  CMD_CFG_MULTIWIRE_MASTER_SlaveID_3_S  L"SlaveID_3" 



/* message elements: CMD_CFG_MULTIWIRE_SLAVE */


 #define  CMD_CFG_MULTIWIRE_SLAVE_MPairMode_S  L"MPairMode" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_NrWirePairs_S  L"NrWirePairs" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_PairNr_S  L"PairNr" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_ValidDataSlotsSDI_S  L"ValidDataSlotsSDI" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_MasterID_S  L"MasterID" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_SlaveID_1_S  L"SlaveID_1" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_SlaveID_2_S  L"SlaveID_2" 
 #define  CMD_CFG_MULTIWIRE_SLAVE_SlaveID_3_S  L"SlaveID_3" 



/* message elements: CMD_CFG_MULTIWIRE_PMMS_PAR */


 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_pbo_dn_S  L"pmms_pbo_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_1_dn_S  L"pmms_baserate_1_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_2_dn_S  L"pmms_baserate_2_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_3_dn_S  L"pmms_baserate_3_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_4_dn_S  L"pmms_baserate_4_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_5_dn_S  L"pmms_baserate_5_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_6_dn_S  L"pmms_baserate_6_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_7_dn_S  L"pmms_baserate_7_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_rsvd1_S  L"rsvd1" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_rsvd2_S  L"rsvd2" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_duration_dn_S  L"pmms_duration_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_scrambler_dn_S  L"pmms_scrambler_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_wcmargin_dn_S  L"pmms_wcmargin_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_ccmargin_dn_S  L"pmms_ccmargin_dn" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_pbo_up_S  L"pmms_pbo_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_1_up_S  L"pmms_baserate_1_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_2_up_S  L"pmms_baserate_2_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_3_up_S  L"pmms_baserate_3_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_4_up_S  L"pmms_baserate_4_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_5_up_S  L"pmms_baserate_5_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_6_up_S  L"pmms_baserate_6_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_baserate_7_up_S  L"pmms_baserate_7_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_rsvd3_S  L"rsvd3" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_rsvd4_S  L"rsvd4" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_duration_up_S  L"pmms_duration_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_scrambler_up_S  L"pmms_scrambler_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_wcmargin_up_S  L"pmms_wcmargin_up" 
 #define  CMD_CFG_MULTIWIRE_PMMS_PAR_pmms_ccmargin_up_S  L"pmms_ccmargin_up" 



/* message elements: CMD_MULTIWIRE_MDATA_GET */


 #define  CMD_MULTIWIRE_MDATA_GET_SlaveNr_S  L"SlaveNr" 
 #define  CMD_MULTIWIRE_MDATA_GET_DataType_S  L"DataType" 
 #define  CMD_MULTIWIRE_MDATA_GET_rsvd0_S  L"rsvd0" 
 #define  CMD_MULTIWIRE_MDATA_GET_rsvd1_S  L"rsvd1" 



/* message elements: CMD_MULTIWIRE_SDATA_GET */


 #define  CMD_MULTIWIRE_SDATA_GET_DataType_S  L"DataType" 
 #define  CMD_MULTIWIRE_SDATA_GET_rsvd0_S  L"rsvd0" 
 #define  CMD_MULTIWIRE_SDATA_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_MULTIWIRE_SDATA_GET_rsvd2_S  L"rsvd2" 



/* message elements: CMD_CFG_MULTIWIRE_OPERATION */


 #define  CMD_CFG_MULTIWIRE_OPERATION_operation_S  L"operation" 
 #define  CMD_CFG_MULTIWIRE_OPERATION_rsvd0_S  L"rsvd0" 
 #define  CMD_CFG_MULTIWIRE_OPERATION_rsvd1_S  L"rsvd1" 



/* message definitions */

/** message: CMD_CFG_MULTIWIRE_MASTER */

typedef struct cmd_cfg_multiwire_master_s 
{ 
  /** Multiple Wire Pair Mode */ 
  uint8  MPairMode; 
  /** Number of wire pairs */ 
  uint8  NrWirePairs; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Valid Data Slots on SDI */ 
  uint8  ValidDataSlotsSDI; 
  /** Rsvd */ 
  uint8  rsvd2; 
  /** SlaveID_1 */ 
  uint8  SlaveID_1; 
  /** SlaveID_2 */ 
  uint8  SlaveID_2; 
  /** SlaveID_3 */ 
  uint8  SlaveID_3; 
} __PACKED__ cmd_cfg_multiwire_master_t; 


/** message: CMD_CFG_MULTIWIRE_SLAVE */

typedef struct cmd_cfg_multiwire_slave_s 
{ 
  /** Multiple Wire Pair Mode */ 
  uint8  MPairMode; 
  /** Number of wire pairs */ 
  uint8  NrWirePairs; 
  /** PairNr */ 
  uint8  PairNr; 
  /** Valid Data Slots on SDI */ 
  uint8  ValidDataSlotsSDI; 
  /** MasterID */ 
  uint8  MasterID; 
  /** SlaveID_1 */ 
  uint8  SlaveID_1; 
  /** SlaveID_2 */ 
  uint8  SlaveID_2; 
  /** SlaveID_3 */ 
  uint8  SlaveID_3; 
} __PACKED__ cmd_cfg_multiwire_slave_t; 


/** message: CMD_CFG_MULTIWIRE_PMMS_PAR */

typedef struct cmd_cfg_multiwire_pmms_par_s 
{ 
  /** PMMS power backoff */ 
  uint8  pmms_pbo_dn; 
  /** PMMS base rate 1 */ 
  uint8  pmms_baserate_1_dn; 
  /** PMMS base rate 2 */ 
  uint8  pmms_baserate_2_dn; 
  /** PMMS base rate 3 */ 
  uint8  pmms_baserate_3_dn; 
  /** PMMS base rate 4 */ 
  uint8  pmms_baserate_4_dn; 
  /** PMMS base rate 5 */ 
  uint8  pmms_baserate_5_dn; 
  /** PMMS base rate 6 */ 
  uint8  pmms_baserate_6_dn; 
  /** PMMS base rate 7 */ 
  uint8  pmms_baserate_7_dn; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** PMMS duration */ 
  uint8  pmms_duration_dn; 
  /** PMMS scrambler */ 
  uint8  pmms_scrambler_dn; 
  /** PMMS wcmargin */ 
  uint8  pmms_wcmargin_dn; 
  /** PMMS ccmargin */ 
  uint8  pmms_ccmargin_dn; 
  /** PMMS power backoff */ 
  uint8  pmms_pbo_up; 
  /** PMMS base rate 1 */ 
  uint8  pmms_baserate_1_up; 
  /** PMMS base rate 2 */ 
  uint8  pmms_baserate_2_up; 
  /** PMMS base rate 3 */ 
  uint8  pmms_baserate_3_up; 
  /** PMMS base rate 4 */ 
  uint8  pmms_baserate_4_up; 
  /** PMMS base rate 5 */ 
  uint8  pmms_baserate_5_up; 
  /** PMMS base rate 6 */ 
  uint8  pmms_baserate_6_up; 
  /** PMMS base rate 7 */ 
  uint8  pmms_baserate_7_up; 
  /** Reserved */ 
  uint8  rsvd3; 
  /** Reserved */ 
  uint8  rsvd4; 
  /** PMMS duration */ 
  uint8  pmms_duration_up; 
  /** PMMS scrambler */ 
  uint8  pmms_scrambler_up; 
  /** PMMS wcmargin */ 
  uint8  pmms_wcmargin_up; 
  /** PMMS ccmargin */ 
  uint8  pmms_ccmargin_up; 
} __PACKED__ cmd_cfg_multiwire_pmms_par_t; 


/** message: CMD_MULTIWIRE_MDATA_GET */

typedef struct cmd_multiwire_mdata_get_s 
{ 
  /** SlaveNr. */ 
  uint8  SlaveNr; 
  /** Type of the requested data. */ 
  uint8  DataType; 
  /** Reserved. */ 
  uint8  rsvd0; 
  /** Reserved. */ 
  uint8  rsvd1; 
} __PACKED__ cmd_multiwire_mdata_get_t; 


/** message: CMD_MULTIWIRE_SDATA_GET */

typedef struct cmd_multiwire_sdata_get_s 
{ 
  /** Type of the requested data. */ 
  uint8  DataType; 
  /** Reserved. */ 
  uint8  rsvd0; 
  /** Reserved. */ 
  uint8  rsvd1; 
  /** Reserved. */ 
  uint8  rsvd2; 
} __PACKED__ cmd_multiwire_sdata_get_t; 


/** message: CMD_CFG_MULTIWIRE_OPERATION */

typedef struct cmd_cfg_multiwire_operation_s 
{ 
  /** Slave operation mode. */ 
  uint8  operation; 
  /** rsvd0 */ 
  uint8  rsvd0; 
  /** rsvd1 */ 
  uint16  rsvd1; 
} __PACKED__ cmd_cfg_multiwire_operation_t; 

/*@}*/ /* Multiwire Mode */


/** \addtogroup SDFE4_Repeater Repeater */

/*@{*/


/* message identifiers */


 #define  CMD_GHS_REG_INITIATION  0x2C62 
 #define  CMD_GHS_REG_DIAG_MODE  0x2C72 
 #define  CMD_GHS_REG_INITIATION_S  "CMD_GHS_REG_INITIATION" 
 #define  CMD_GHS_REG_DIAG_MODE_S  "CMD_GHS_REG_DIAG_MODE" 



/* message elements: CMD_GHS_REG_INITIATION */


 #define  CMD_GHS_REG_INITIATION_initiation_S  L"initiation" 
 #define  CMD_GHS_REG_INITIATION_rsvd1_S  L"rsvd1" 
 #define  CMD_GHS_REG_INITIATION_rsvd2_S  L"rsvd2" 
 #define  CMD_GHS_REG_INITIATION_rsvd3_S  L"rsvd3" 



/* message elements: CMD_GHS_REG_DIAG_MODE */


 #define  CMD_GHS_REG_DIAG_MODE_diagnostic_mode_S  L"diagnostic_mode" 
 #define  CMD_GHS_REG_DIAG_MODE_rsvd1_S  L"rsvd1" 
 #define  CMD_GHS_REG_DIAG_MODE_rsvd2_S  L"rsvd2" 
 #define  CMD_GHS_REG_DIAG_MODE_rsvd3_S  L"rsvd3" 



/* message definitions */

/** message: CMD_GHS_REG_INITIATION */

typedef struct cmd_ghs_reg_initiation_s 
{ 
  /** initiation */ 
  uint8  initiation; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** rsvd3 */ 
  uint8  rsvd3; 
} __PACKED__ cmd_ghs_reg_initiation_t; 


/** message: CMD_GHS_REG_DIAG_MODE */

typedef struct cmd_ghs_reg_diag_mode_s 
{ 
  /** diagnostic_mode */ 
  uint8  diagnostic_mode; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** rsvd3 */ 
  uint8  rsvd3; 
} __PACKED__ cmd_ghs_reg_diag_mode_t; 

/*@}*/ /* Repeater */


/** \addtogroup SDFE4_Test_and_Loop_Commands Test and Loop Commands */

/*@{*/


/* message identifiers */


 #define  CMD_MSG_STAT_GET  0x0802 
 #define  CMD_SDI_REMOTE_LOOP_ENABLE  0x8C1F 
 #define  CMD_SDI_CUSTOMER_LOOP_ENABLE  0x8C2F 
 #define  CMD_SDI_CLOCK_LOOP_ENABLE  0x8C3F 
 #define  CMD_SDI_LOOP_DISABLE  0x8C4F 
 #define  CMD_SDI_ALIGNED_LOOP_ENABLE  0x8C5F 
 #define  CMD_SDI_ALIGNED_LOOP_DISABLE  0x8C6F 
 #define  CMD_ANALOG_LOOP_ENABLE  0xDC3F 
 #define  CMD_PSD_MEASUREMENT_ENABLE  0xD402 
 #define  CMD_PSD_MEASUREMENT_DISABLE  0xD412 
 #define  CMD_SEND_CORRUPTED_CRC_ENABLE  0xD422 
 #define  CMD_SEND_CORRUPTED_CRC_DISABLE  0xD432 
 #define  CMD_MSG_STAT_GET_S  "CMD_MSG_STAT_GET" 
 #define  CMD_SDI_REMOTE_LOOP_ENABLE_S  "CMD_SDI_REMOTE_LOOP_ENABLE" 
 #define  CMD_SDI_CUSTOMER_LOOP_ENABLE_S  "CMD_SDI_CUSTOMER_LOOP_ENABLE" 
 #define  CMD_SDI_CLOCK_LOOP_ENABLE_S  "CMD_SDI_CLOCK_LOOP_ENABLE" 
 #define  CMD_SDI_LOOP_DISABLE_S  "CMD_SDI_LOOP_DISABLE" 
 #define  CMD_SDI_ALIGNED_LOOP_ENABLE_S  "CMD_SDI_ALIGNED_LOOP_ENABLE" 
 #define  CMD_SDI_ALIGNED_LOOP_DISABLE_S  "CMD_SDI_ALIGNED_LOOP_DISABLE" 
 #define  CMD_ANALOG_LOOP_ENABLE_S  "CMD_ANALOG_LOOP_ENABLE" 
 #define  CMD_PSD_MEASUREMENT_ENABLE_S  "CMD_PSD_MEASUREMENT_ENABLE" 
 #define  CMD_PSD_MEASUREMENT_DISABLE_S  "CMD_PSD_MEASUREMENT_DISABLE" 
 #define  CMD_SEND_CORRUPTED_CRC_ENABLE_S  "CMD_SEND_CORRUPTED_CRC_ENABLE" 
 #define  CMD_SEND_CORRUPTED_CRC_DISABLE_S  "CMD_SEND_CORRUPTED_CRC_DISABLE" 



/* message definitions */


/*@}*/ /* Test and Loop Commands */


/** \addtogroup SDFE4_Notifications Notifications */

/*@{*/


/* message identifiers */


 #define  NFC_CONNECT_CTRL  0x0D04 
 #define  NFC_CONNECT_CONDITION  0x0D14 
 #define  NFC_SDI_DPLL_SYNC  0x855F 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4  0x8D0F 
 #define  NFC_PERF_PRIM  0x9912 
 #define  NFC_FBIT_RX  0x9952 
 #define  NFC_EOC_TX  0xAD02 
 #define  NFC_EOC_RX  0xA912 
 #define  NFC_UNDEF_MSG_ID  0x010F 
 #define  NFC_MULTIWIRE_MASTER  0xB94F 
 #define  NFC_MULTIWIRE_PAIR_NR  0xB96F 
 #define  NFC_CONNECT_CTRL_S  "NFC_CONNECT_CTRL" 
 #define  NFC_CONNECT_CONDITION_S  "NFC_CONNECT_CONDITION" 
 #define  NFC_SDI_DPLL_SYNC_S  "NFC_SDI_DPLL_SYNC" 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_S  "NFC_MPAIR_DELAY_MEASURE_SDFE4" 
 #define  NFC_PERF_PRIM_S  "NFC_PERF_PRIM" 
 #define  NFC_FBIT_RX_S  "NFC_FBIT_RX" 
 #define  NFC_EOC_TX_S  "NFC_EOC_TX" 
 #define  NFC_EOC_RX_S  "NFC_EOC_RX" 
 #define  NFC_UNDEF_MSG_ID_S  "NFC_UNDEF_MSG_ID" 
 #define  NFC_MULTIWIRE_MASTER_S  "NFC_MULTIWIRE_MASTER" 
 #define  NFC_MULTIWIRE_PAIR_NR_S  "NFC_MULTIWIRE_PAIR_NR" 



/* message elements: NFC_CONNECT_CTRL */


 #define  NFC_CONNECT_CTRL_state_S  L"state" 
 #define  NFC_CONNECT_CTRL_rsvd1_S  L"rsvd1" 
 #define  NFC_CONNECT_CTRL_rsvd2_S  L"rsvd2" 



/* message elements: NFC_CONNECT_CONDITION */


 #define  NFC_CONNECT_CONDITION_condition_S  L"condition" 
 #define  NFC_CONNECT_CONDITION_reason_S  L"reason" 



/* message elements: NFC_MPAIR_DELAY_MEASURE_SDFE4 */


 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_data0_S  L"data0" 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_data1_S  L"data1" 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_data2_S  L"data2" 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_data3_S  L"data3" 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_data4_S  L"data4" 
 #define  NFC_MPAIR_DELAY_MEASURE_SDFE4_data5_S  L"data5" 



/* message elements: NFC_PERF_PRIM */


 #define  NFC_PERF_PRIM_prims_S  L"prims" 



/* message elements: NFC_FBIT_RX */


 #define  NFC_FBIT_RX_fbits_S  L"fbits" 



/* message elements: NFC_EOC_TX */


 #define  NFC_EOC_TX_nfc_type_S  L"nfc_type" 



/* message elements: NFC_EOC_RX */


 #define  NFC_EOC_RX_rme_S  L"rme" 
 #define  NFC_EOC_RX_fail_S  L"fail" 
 #define  NFC_EOC_RX_num_bytes_S  L"num_bytes" 
 #define  NFC_EOC_RX_msg_S  L"msg" 



/* message elements: NFC_UNDEF_MSG_ID */


 #define  NFC_UNDEF_MSG_ID_msg_type_undef_S  L"msg_type_undef" 



/* message elements: NFC_MULTIWIRE_MASTER */


 #define  NFC_MULTIWIRE_MASTER_PreviousMasterID_S  L"PreviousMasterID" 
 #define  NFC_MULTIWIRE_MASTER_CurrentMasterID_S  L"CurrentMasterID" 
 #define  NFC_MULTIWIRE_MASTER_SlaveID_1_S  L"SlaveID_1" 
 #define  NFC_MULTIWIRE_MASTER_SlaveID_2_S  L"SlaveID_2" 
 #define  NFC_MULTIWIRE_MASTER_SlaveID_3_S  L"SlaveID_3" 
 #define  NFC_MULTIWIRE_MASTER_InterleavingMaster_S  L"InterleavingMaster" 
 #define  NFC_MULTIWIRE_MASTER_InterleavingSlave1_S  L"InterleavingSlave1" 
 #define  NFC_MULTIWIRE_MASTER_InterleavingSlave2_S  L"InterleavingSlave2" 
 #define  NFC_MULTIWIRE_MASTER_InterleavingSlave3_S  L"InterleavingSlave3" 
 #define  NFC_MULTIWIRE_MASTER_ActiveWirePairs_S  L"ActiveWirePairs" 
 #define  NFC_MULTIWIRE_MASTER_rsvd0_S  L"rsvd0" 



/* message elements: NFC_MULTIWIRE_PAIR_NR */


 #define  NFC_MULTIWIRE_PAIR_NR_SlaveID_S  L"SlaveID" 
 #define  NFC_MULTIWIRE_PAIR_NR_PairNr_S  L"PairNr" 
 #define  NFC_MULTIWIRE_PAIR_NR_rsvd0_S  L"rsvd0" 
 #define  NFC_MULTIWIRE_PAIR_NR_rsvd1_S  L"rsvd1" 



/* message definitions */

/** message: NFC_CONNECT_CTRL */

typedef struct nfc_connect_ctrl_s 
{ 
  /** State */ 
  int8  state; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ nfc_connect_ctrl_t; 


/** message: NFC_CONNECT_CONDITION */

typedef struct nfc_connect_condition_s 
{ 
  /** Condition */ 
  uint8  condition; 
  /** Reason */ 
  uint8  reason; 
} __PACKED__ nfc_connect_condition_t; 


/** message: NFC_MPAIR_DELAY_MEASURE_SDFE4 */

typedef struct nfc_mpair_delay_measure_sdfe4_s 
{ 
  /** The multiframe information bits of a 6 ms period. */ 
  uint32  data0; 
  /** The multiframe information bits of a 6 ms period, part 2. */ 
  uint32  data1; 
  /** The multiframe information bits of a 6 ms period, part 3. */ 
  uint32  data2; 
  /** The multiframe information bits of a 6 ms period, part 4. */ 
  uint32  data3; 
  /** The multiframe information bits of a 6 ms period, part 5. */ 
  uint32  data4; 
  /** The multiframe information bits of a 6 ms period, part 6. */ 
  uint32  data5; 
} __PACKED__ nfc_mpair_delay_measure_sdfe4_t; 


/** message: NFC_PERF_PRIM */

typedef struct nfc_perf_prim_s 
{ 
  /** Bit vector for performance primitives */ 
  uint8  prims; 
} __PACKED__ nfc_perf_prim_t; 


/** message: NFC_FBIT_RX */

typedef struct nfc_fbit_rx_s 
{ 
  /** The four fbits of the SHDSL frame */ 
  uint8  fbits; 
} __PACKED__ nfc_fbit_rx_t; 


/** message: NFC_EOC_TX */

typedef struct nfc_eoc_tx_s 
{ 
  /** Type of acknowledgement */ 
  uint8  nfc_type; 
} __PACKED__ nfc_eoc_tx_t; 


/** message: NFC_EOC_RX */

typedef struct nfc_eoc_rx_s 
{ 
  /** Receive message end flag */ 
  uint8  rme; 
  /** Fail Flag */ 
  uint8  fail; 
  /** The number of valid bytes in the msg field */ 
  uint8  num_bytes; 
  /** EOC bytes received */ 
  uint8  msg[112]; 
} __PACKED__ nfc_eoc_rx_t; 


/** message: NFC_UNDEF_MSG_ID */

typedef struct nfc_undef_msg_id_s 
{ 
  /** msg_type_undef */ 
  uint16  msg_type_undef; 
} __PACKED__ nfc_undef_msg_id_t; 


/** message: NFC_MULTIWIRE_MASTER */

typedef struct nfc_multiwire_master_s 
{ 
  /** Previous Master ID */ 
  uint8  PreviousMasterID; 
  /** Current Master ID */ 
  uint8  CurrentMasterID; 
  /** Slave ID 1 */ 
  uint8  SlaveID_1; 
  /** Slave ID 2 */ 
  uint8  SlaveID_2; 
  /** Slave ID 3 */ 
  uint8  SlaveID_3; 
  /** channel number which is FIRST in interleaving order */ 
  uint8  InterleavingMaster; 
  /** channel number which is SECOND in interleaving order */ 
  uint8  InterleavingSlave1; 
  /** channel number which is THIRD in interleaving order */ 
  uint8  InterleavingSlave2; 
  /** channel number which is FOURTH in interleaving order */ 
  uint8  InterleavingSlave3; 
  /** ActiveWirePairs */ 
  uint8  ActiveWirePairs; 
  /** rsvd0 */ 
  uint16  rsvd0; 
} __PACKED__ nfc_multiwire_master_t; 


/** message: NFC_MULTIWIRE_PAIR_NR */

typedef struct nfc_multiwire_pair_nr_s 
{ 
  /** SlaveID */ 
  uint8  SlaveID; 
  /** PairNr */ 
  uint8  PairNr; 
  /** rsvd0 */ 
  uint8  rsvd0; 
  /** rsvd1 */ 
  uint8  rsvd1; 
} __PACKED__ nfc_multiwire_pair_nr_t; 

/*@}*/ /* Notifications */


/** \addtogroup SDFE4_Acknowledge_Messages Acknowledge Messages */

/*@{*/


/* message identifiers */


 #define  ACK_PMMS_RESULTS_GET  0xCA2F 
 #define  ACK_CFG_SYM_DSL_MODE  0x2622 
 #define  ACK_CFG_GHS_MODE  0x0604 
 #define  ACK_CFG_CAPLIST_SHORT  0x2632 
 #define  ACK_CFG_CAPLIST_SHORT_VER_2  0x2652 
 #define  ACK_CFG_GHS_NS_FIELD  0x2642 
 #define  ACK_GHS_NS_FIELD_GET  0x2A52 
 #define  ACK_GHS_CAP_GET  0x2A22 
 #define  ACK_CFG_GHS_CAP  0x2662 
 #define  ACK_GHS_REG_INITIATION  0x2E62 
 #define  ACK_GHS_REG_DIAG_MODE  0x2E72 
 #define  ACK_CFG_E1_ATM_OCTET_ALIGNED  0x0612 
 #define  ACK_CFG_CAPLIST  0x2612 
 #define  ACK_CONNECT_CTRL  0x0E04 
 #define  ACK_CONNECT_STAT_GET  0x0A04 
 #define  ACK_CFG_DSL_PARAM  0x4602 
 #define  ACK_DSL_PARAM_GET  0x4A02 
 #define  ACK_CAPLIST_GET  0x2A02 
 #define  ACK_CFG_EFM_DISCOVERY_DATA  0xE602 
 #define  ACK_EFM_DISCOVERY_DATA_GET  0xEA02 
 #define  NFC_EFM_DISCOVERY_OP_RDY  0xE902 
 #define  ACK_CFG_EFM_AGGREGATE_DATA  0xE612 
 #define  ACK_EFM_AGGREGATE_DATA_GET  0xEA12 
 #define  NFC_EFM_AGGREGATE_OP_RDY  0xE912 
 #define  ACK_EFM_START_ACTIVATION  0xEE02 
 #define  ACK_ID_GET  0x0A0F 
 #define  ACK_FEATURE_STR_GET  0x0A1F 
 #define  ACK_CHANNEL_DISABLE  0x0E0F 
 #define  ACK_CFG_AFE_PARAMS  0x061F 
 #define  ACK_MSG_STAT_GET  0x0A02 
 #define  ACK_CFG_SDI_SETTINGS  0x860F 
 #define  ACK_CFG_SDI_SET_EXTENDED  0x865F 
 #define  ACK_CFG_SDI_TX  0x861F 
 #define  ACK_CFG_SDI_RX  0x862F 
 #define  ACK_CFG_SDI_FRAMER_TX  0x863F 
 #define  ACK_CFG_SDI_FRAMER_RX  0x864F 
 #define  ACK_CFG_SDI_DLY  0x867F 
 #define  ACK_CFG_SDI_IL_CHANNELS_TX  0x868F 
 #define  ACK_CFG_SDI_IL_CHANNELS_RX  0x869F 
 #define  ACK_MPAIR_DELAY_MEASURE_SDFE4  0x8E0F 
 #define  ACK_MPAIR_RSFSC_ALIGN  0x8E02 
 #define  ACK_SDI_REMOTE_LOOP_ENABLE  0x8E1F 
 #define  ACK_SDI_CUSTOMER_LOOP_ENABLE  0x8E2F 
 #define  ACK_SDI_CLOCK_LOOP_ENABLE  0x8E3F 
 #define  ACK_SDI_LOOP_DISABLE  0x8E4F 
 #define  ACK_SDI_ALIGNED_LOOP_ENABLE  0x8E5F 
 #define  ACK_SDI_ALIGNED_LOOP_DISABLE  0x8E6F 
 #define  ACK_ANALOG_LOOP_ENABLE  0xDE3F 
 #define  ACK_CFG_PERF_PRIM  0x9602 
 #define  ACK_PERF_PRIM_GET  0x9642 
 #define  ACK_CFG_REQ_SHDSL  0x9622 
 #define  ACK_PERF_STATUS_GET  0x9632 
 #define  ACK_PERF_DETAILS_GET  0x9A03 
 #define  ACK_CFG_FBIT_RX  0x9612 
 #define  ACK_FBIT_TX  0x9652 
 #define  ACK_FBIT_RX_GET  0x9E02 
 #define  ACK_EOC_TX  0xAE02 
 #define  ACK_CFG_EOC_RX  0xA622 
 #define  ACK_CFG_MULTIWIRE_MASTER  0xB60F 
 #define  ACK_CFG_MULTIWIRE_SLAVE  0xB61F 
 #define  ACK_CFG_MULTIWIRE_PMMS_PAR  0xB62F 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET  0xBA3F 
 #define  ACK_CFG_MULTIWIRE_OPERATION  0xB65F 
 #define  ACK_MULTIWIRE_MDATA_GET  0xBA0F 
 #define  ACK_MULTIWIRE_SDATA_GET  0xBA1F 
 #define  ACK_PSD_MEASUREMENT_ENABLE  0xD602 
 #define  ACK_PSD_MEASUREMENT_DISABLE  0xD612 
 #define  ACK_SEND_CORRUPTED_CRC_ENABLE  0xD622 
 #define  ACK_SEND_CORRUPTED_CRC_DISABLE  0xD632 
 #define  ACK_PMMS_RESULTS_GET_S  "ACK_PMMS_RESULTS_GET" 
 #define  ACK_CFG_SYM_DSL_MODE_S  "ACK_CFG_SYM_DSL_MODE" 
 #define  ACK_CFG_GHS_MODE_S  "ACK_CFG_GHS_MODE" 
 #define  ACK_CFG_CAPLIST_SHORT_S  "ACK_CFG_CAPLIST_SHORT" 
 #define  ACK_CFG_CAPLIST_SHORT_VER_2_S  "ACK_CFG_CAPLIST_SHORT_VER_2" 
 #define  ACK_CFG_GHS_NS_FIELD_S  "ACK_CFG_GHS_NS_FIELD" 
 #define  ACK_GHS_NS_FIELD_GET_S  "ACK_GHS_NS_FIELD_GET" 
 #define  ACK_GHS_CAP_GET_S  "ACK_GHS_CAP_GET" 
 #define  ACK_CFG_GHS_CAP_S  "ACK_CFG_GHS_CAP" 
 #define  ACK_GHS_REG_INITIATION_S  "ACK_GHS_REG_INITIATION" 
 #define  ACK_GHS_REG_DIAG_MODE_S  "ACK_GHS_REG_DIAG_MODE" 
 #define  ACK_CFG_E1_ATM_OCTET_ALIGNED_S  "ACK_CFG_E1_ATM_OCTET_ALIGNED" 
 #define  ACK_CFG_CAPLIST_S  "ACK_CFG_CAPLIST" 
 #define  ACK_CONNECT_CTRL_S  "ACK_CONNECT_CTRL" 
 #define  ACK_CONNECT_STAT_GET_S  "ACK_CONNECT_STAT_GET" 
 #define  ACK_CFG_DSL_PARAM_S  "ACK_CFG_DSL_PARAM" 
 #define  ACK_DSL_PARAM_GET_S  "ACK_DSL_PARAM_GET" 
 #define  ACK_CAPLIST_GET_S  "ACK_CAPLIST_GET" 
 #define  ACK_CFG_EFM_DISCOVERY_DATA_S  "ACK_CFG_EFM_DISCOVERY_DATA" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_S  "ACK_EFM_DISCOVERY_DATA_GET" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_S  "NFC_EFM_DISCOVERY_OP_RDY" 
 #define  ACK_CFG_EFM_AGGREGATE_DATA_S  "ACK_CFG_EFM_AGGREGATE_DATA" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_S  "ACK_EFM_AGGREGATE_DATA_GET" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_S  "NFC_EFM_AGGREGATE_OP_RDY" 
 #define  ACK_EFM_START_ACTIVATION_S  "ACK_EFM_START_ACTIVATION" 
 #define  ACK_ID_GET_S  "ACK_ID_GET" 
 #define  ACK_FEATURE_STR_GET_S  "ACK_FEATURE_STR_GET" 
 #define  ACK_CHANNEL_DISABLE_S  "ACK_CHANNEL_DISABLE" 
 #define  ACK_CFG_AFE_PARAMS_S  "ACK_CFG_AFE_PARAMS" 
 #define  ACK_MSG_STAT_GET_S  "ACK_MSG_STAT_GET" 
 #define  ACK_CFG_SDI_SETTINGS_S  "ACK_CFG_SDI_SETTINGS" 
 #define  ACK_CFG_SDI_SET_EXTENDED_S  "ACK_CFG_SDI_SET_EXTENDED" 
 #define  ACK_CFG_SDI_TX_S  "ACK_CFG_SDI_TX" 
 #define  ACK_CFG_SDI_RX_S  "ACK_CFG_SDI_RX" 
 #define  ACK_CFG_SDI_FRAMER_TX_S  "ACK_CFG_SDI_FRAMER_TX" 
 #define  ACK_CFG_SDI_FRAMER_RX_S  "ACK_CFG_SDI_FRAMER_RX" 
 #define  ACK_CFG_SDI_DLY_S  "ACK_CFG_SDI_DLY" 
 #define  ACK_CFG_SDI_IL_CHANNELS_TX_S  "ACK_CFG_SDI_IL_CHANNELS_TX" 
 #define  ACK_CFG_SDI_IL_CHANNELS_RX_S  "ACK_CFG_SDI_IL_CHANNELS_RX" 
 #define  ACK_MPAIR_DELAY_MEASURE_SDFE4_S  "ACK_MPAIR_DELAY_MEASURE_SDFE4" 
 #define  ACK_MPAIR_RSFSC_ALIGN_S  "ACK_MPAIR_RSFSC_ALIGN" 
 #define  ACK_SDI_REMOTE_LOOP_ENABLE_S  "ACK_SDI_REMOTE_LOOP_ENABLE" 
 #define  ACK_SDI_CUSTOMER_LOOP_ENABLE_S  "ACK_SDI_CUSTOMER_LOOP_ENABLE" 
 #define  ACK_SDI_CLOCK_LOOP_ENABLE_S  "ACK_SDI_CLOCK_LOOP_ENABLE" 
 #define  ACK_SDI_LOOP_DISABLE_S  "ACK_SDI_LOOP_DISABLE" 
 #define  ACK_SDI_ALIGNED_LOOP_ENABLE_S  "ACK_SDI_ALIGNED_LOOP_ENABLE" 
 #define  ACK_SDI_ALIGNED_LOOP_DISABLE_S  "ACK_SDI_ALIGNED_LOOP_DISABLE" 
 #define  ACK_ANALOG_LOOP_ENABLE_S  "ACK_ANALOG_LOOP_ENABLE" 
 #define  ACK_CFG_PERF_PRIM_S  "ACK_CFG_PERF_PRIM" 
 #define  ACK_PERF_PRIM_GET_S  "ACK_PERF_PRIM_GET" 
 #define  ACK_CFG_REQ_SHDSL_S  "ACK_CFG_REQ_SHDSL" 
 #define  ACK_PERF_STATUS_GET_S  "ACK_PERF_STATUS_GET" 
 #define  ACK_PERF_DETAILS_GET_S  "ACK_PERF_DETAILS_GET" 
 #define  ACK_CFG_FBIT_RX_S  "ACK_CFG_FBIT_RX" 
 #define  ACK_FBIT_TX_S  "ACK_FBIT_TX" 
 #define  ACK_FBIT_RX_GET_S  "ACK_FBIT_RX_GET" 
 #define  ACK_EOC_TX_S  "ACK_EOC_TX" 
 #define  ACK_CFG_EOC_RX_S  "ACK_CFG_EOC_RX" 
 #define  ACK_CFG_MULTIWIRE_MASTER_S  "ACK_CFG_MULTIWIRE_MASTER" 
 #define  ACK_CFG_MULTIWIRE_SLAVE_S  "ACK_CFG_MULTIWIRE_SLAVE" 
 #define  ACK_CFG_MULTIWIRE_PMMS_PAR_S  "ACK_CFG_MULTIWIRE_PMMS_PAR" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_S  "ACK_MULTIWIRE_PMMS_RESULT_GET" 
 #define  ACK_CFG_MULTIWIRE_OPERATION_S  "ACK_CFG_MULTIWIRE_OPERATION" 
 #define  ACK_MULTIWIRE_MDATA_GET_S  "ACK_MULTIWIRE_MDATA_GET" 
 #define  ACK_MULTIWIRE_SDATA_GET_S  "ACK_MULTIWIRE_SDATA_GET" 
 #define  ACK_PSD_MEASUREMENT_ENABLE_S  "ACK_PSD_MEASUREMENT_ENABLE" 
 #define  ACK_PSD_MEASUREMENT_DISABLE_S  "ACK_PSD_MEASUREMENT_DISABLE" 
 #define  ACK_SEND_CORRUPTED_CRC_ENABLE_S  "ACK_SEND_CORRUPTED_CRC_ENABLE" 
 #define  ACK_SEND_CORRUPTED_CRC_DISABLE_S  "ACK_SEND_CORRUPTED_CRC_DISABLE" 



/* message elements: ACK_PMMS_RESULTS_GET */


 #define  ACK_PMMS_RESULTS_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_PMMS_RESULTS_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_1_S  L"probe_rate_1" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_1_S  L"SNR_mrg16_1" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_1_S  L"SNR_mrg32_1" 
 #define  ACK_PMMS_RESULTS_GET_EPL_1_S  L"EPL_1" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_2_S  L"probe_rate_2" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_2_S  L"SNR_mrg16_2" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_2_S  L"SNR_mrg32_2" 
 #define  ACK_PMMS_RESULTS_GET_EPL_2_S  L"EPL_2" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_3_S  L"probe_rate_3" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_3_S  L"SNR_mrg16_3" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_3_S  L"SNR_mrg32_3" 
 #define  ACK_PMMS_RESULTS_GET_EPL_3_S  L"EPL_3" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_4_S  L"probe_rate_4" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_4_S  L"SNR_mrg16_4" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_4_S  L"SNR_mrg32_4" 
 #define  ACK_PMMS_RESULTS_GET_EPL_4_S  L"EPL_4" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_5_S  L"probe_rate_5" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_5_S  L"SNR_mrg16_5" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_5_S  L"SNR_mrg32_5" 
 #define  ACK_PMMS_RESULTS_GET_EPL_5_S  L"EPL_5" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_6_S  L"probe_rate_6" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_6_S  L"SNR_mrg16_6" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_6_S  L"SNR_mrg32_6" 
 #define  ACK_PMMS_RESULTS_GET_EPL_6_S  L"EPL_6" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_7_S  L"probe_rate_7" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_7_S  L"SNR_mrg16_7" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_7_S  L"SNR_mrg32_7" 
 #define  ACK_PMMS_RESULTS_GET_EPL_7_S  L"EPL_7" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_8_S  L"probe_rate_8" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_8_S  L"SNR_mrg16_8" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_8_S  L"SNR_mrg32_8" 
 #define  ACK_PMMS_RESULTS_GET_EPL_8_S  L"EPL_8" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_9_S  L"probe_rate_9" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_9_S  L"SNR_mrg16_9" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_9_S  L"SNR_mrg32_9" 
 #define  ACK_PMMS_RESULTS_GET_EPL_9_S  L"EPL_9" 
 #define  ACK_PMMS_RESULTS_GET_probe_rate_10_S  L"probe_rate_10" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg16_10_S  L"SNR_mrg16_10" 
 #define  ACK_PMMS_RESULTS_GET_SNR_mrg32_10_S  L"SNR_mrg32_10" 
 #define  ACK_PMMS_RESULTS_GET_EPL_10_S  L"EPL_10" 



/* message elements: ACK_GHS_NS_FIELD_GET */


 #define  ACK_GHS_NS_FIELD_GET_valid_ns_data_S  L"valid_ns_data" 
 #define  ACK_GHS_NS_FIELD_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_GHS_NS_FIELD_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_GHS_NS_FIELD_GET_ns_info_length_S  L"ns_info_length" 
 #define  ACK_GHS_NS_FIELD_GET_ns_info_S  L"ns_info" 



/* message elements: ACK_GHS_CAP_GET */


 #define  ACK_GHS_CAP_GET_ClType_S  L"ClType" 
 #define  ACK_GHS_CAP_GET_ClParam_S  L"ClParam" 
 #define  ACK_GHS_CAP_GET_ClOctetNrNPar_S  L"ClOctetNrNPar" 
 #define  ACK_GHS_CAP_GET_ClOctetNrSPar_S  L"ClOctetNrSPar" 
 #define  ACK_GHS_CAP_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_GHS_CAP_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_GHS_CAP_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_GHS_CAP_GET_rsvd3_S  L"rsvd3" 
 #define  ACK_GHS_CAP_GET_ClData_S  L"ClData" 



/* message elements: ACK_CFG_GHS_CAP */


 #define  ACK_CFG_GHS_CAP_ClParam_S  L"ClParam" 
 #define  ACK_CFG_GHS_CAP_ClSupOctets_S  L"ClSupOctets" 
 #define  ACK_CFG_GHS_CAP_ClReqOctets_S  L"ClReqOctets" 
 #define  ACK_CFG_GHS_CAP_ClConfigOctets_S  L"ClConfigOctets" 
 #define  ACK_CFG_GHS_CAP_rsvd0_S  L"rsvd0" 
 #define  ACK_CFG_GHS_CAP_rsvd1_S  L"rsvd1" 
 #define  ACK_CFG_GHS_CAP_rsvd2_S  L"rsvd2" 
 #define  ACK_CFG_GHS_CAP_rsvd3_S  L"rsvd3" 



/* message elements: ACK_CONNECT_CTRL */


 #define  ACK_CONNECT_CTRL_state_S  L"state" 
 #define  ACK_CONNECT_CTRL_status_S  L"status" 
 #define  ACK_CONNECT_CTRL_rsvd2_S  L"rsvd2" 



/* message elements: ACK_CONNECT_STAT_GET */


 #define  ACK_CONNECT_STAT_GET_state_S  L"state" 
 #define  ACK_CONNECT_STAT_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_CONNECT_STAT_GET_rsvd2_S  L"rsvd2" 



/* message elements: ACK_DSL_PARAM_GET */


 #define  ACK_DSL_PARAM_GET_stu_mode_S  L"stu_mode" 
 #define  ACK_DSL_PARAM_GET_repeater_S  L"repeater" 
 #define  ACK_DSL_PARAM_GET_annex_S  L"annex" 
 #define  ACK_DSL_PARAM_GET_clk_ref_S  L"clk_ref" 
 #define  ACK_DSL_PARAM_GET_base_rate_S  L"base_rate" 
 #define  ACK_DSL_PARAM_GET_sub_rate_S  L"sub_rate" 
 #define  ACK_DSL_PARAM_GET_psd_mask_S  L"psd_mask" 
 #define  ACK_DSL_PARAM_GET_frame_mode_S  L"frame_mode" 
 #define  ACK_DSL_PARAM_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_DSL_PARAM_GET_tx_sync_word_S  L"tx_sync_word" 
 #define  ACK_DSL_PARAM_GET_rx_sync_word_S  L"rx_sync_word" 
 #define  ACK_DSL_PARAM_GET_tx_stuff_bits_S  L"tx_stuff_bits" 
 #define  ACK_DSL_PARAM_GET_rx_stuff_bits_S  L"rx_stuff_bits" 
 #define  ACK_DSL_PARAM_GET_pow_backoff_S  L"pow_backoff" 
 #define  ACK_DSL_PARAM_GET_pow_backoff_farend_S  L"pow_backoff_farend" 
 #define  ACK_DSL_PARAM_GET_ghs_pwr_lev_carr_S  L"ghs_pwr_lev_carr" 
 #define  ACK_DSL_PARAM_GET_bits_p_symbol_S  L"bits_p_symbol" 



/* message elements: ACK_CAPLIST_GET */


 #define  ACK_CAPLIST_GET_caplist_type_get_S  L"caplist_type_get" 
 #define  ACK_CAPLIST_GET_ghs_caplist_S  L"ghs_caplist" 



/* message elements: ACK_CFG_EFM_DISCOVERY_DATA */


 #define  ACK_CFG_EFM_DISCOVERY_DATA_discovery_op_S  L"discovery_op" 
 #define  ACK_CFG_EFM_DISCOVERY_DATA_rsvd0_S  L"rsvd0" 
 #define  ACK_CFG_EFM_DISCOVERY_DATA_rsvd1_S  L"rsvd1" 
 #define  ACK_CFG_EFM_DISCOVERY_DATA_rsvd2_S  L"rsvd2" 



/* message elements: ACK_EFM_DISCOVERY_DATA_GET */


 #define  ACK_EFM_DISCOVERY_DATA_GET_discovery_op_S  L"discovery_op" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_discovery_op_stat_S  L"discovery_op_stat" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_discovery_reg_hi_S  L"discovery_reg_hi" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_discovery_reg_lo_S  L"discovery_reg_lo" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_EFM_DISCOVERY_DATA_GET_rsvd3_S  L"rsvd3" 



/* message elements: NFC_EFM_DISCOVERY_OP_RDY */


 #define  NFC_EFM_DISCOVERY_OP_RDY_discovery_op_S  L"discovery_op" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_discovery_op_stat_S  L"discovery_op_stat" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_discovery_reg_hi_S  L"discovery_reg_hi" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_discovery_reg_lo_S  L"discovery_reg_lo" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_rsvd0_S  L"rsvd0" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_rsvd1_S  L"rsvd1" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_rsvd2_S  L"rsvd2" 
 #define  NFC_EFM_DISCOVERY_OP_RDY_rsvd3_S  L"rsvd3" 



/* message elements: ACK_CFG_EFM_AGGREGATE_DATA */


 #define  ACK_CFG_EFM_AGGREGATE_DATA_aggregate_op_S  L"aggregate_op" 
 #define  ACK_CFG_EFM_AGGREGATE_DATA_rsvd0_S  L"rsvd0" 
 #define  ACK_CFG_EFM_AGGREGATE_DATA_rsvd1_S  L"rsvd1" 
 #define  ACK_CFG_EFM_AGGREGATE_DATA_rsvd2_S  L"rsvd2" 



/* message elements: ACK_EFM_AGGREGATE_DATA_GET */


 #define  ACK_EFM_AGGREGATE_DATA_GET_aggregate_op_S  L"aggregate_op" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_aggregate_op_stat_S  L"aggregate_op_stat" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_aggregate_reg_S  L"aggregate_reg" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_rsvd3_S  L"rsvd3" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_rsvd4_S  L"rsvd4" 
 #define  ACK_EFM_AGGREGATE_DATA_GET_rsvd5_S  L"rsvd5" 



/* message elements: NFC_EFM_AGGREGATE_OP_RDY */


 #define  NFC_EFM_AGGREGATE_OP_RDY_aggregate_op_S  L"aggregate_op" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_aggregate_op_stat_S  L"aggregate_op_stat" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_rsvd0_S  L"rsvd0" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_rsvd1_S  L"rsvd1" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_aggregate_reg_S  L"aggregate_reg" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_rsvd2_S  L"rsvd2" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_rsvd3_S  L"rsvd3" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_rsvd4_S  L"rsvd4" 
 #define  NFC_EFM_AGGREGATE_OP_RDY_rsvd5_S  L"rsvd5" 



/* message elements: ACK_EFM_START_ACTIVATION */


 #define  ACK_EFM_START_ACTIVATION_rsvd0_S  L"rsvd0" 
 #define  ACK_EFM_START_ACTIVATION_rsvd1_S  L"rsvd1" 
 #define  ACK_EFM_START_ACTIVATION_rsvd2_S  L"rsvd2" 
 #define  ACK_EFM_START_ACTIVATION_rsvd3_S  L"rsvd3" 



/* message elements: ACK_ID_GET */


 #define  ACK_ID_GET_what_S  L"what" 
 #define  ACK_ID_GET_fw_id_S  L"fw_id" 



/* message elements: ACK_FEATURE_STR_GET */


 #define  ACK_FEATURE_STR_GET_what_S  L"what" 
 #define  ACK_FEATURE_STR_GET_feature_str_S  L"feature_str" 



/* message elements: ACK_MSG_STAT_GET */


 #define  ACK_MSG_STAT_GET_num_timeout_S  L"num_timeout" 
 #define  ACK_MSG_STAT_GET_num_neg_ack_rec_S  L"num_neg_ack_rec" 
 #define  ACK_MSG_STAT_GET_num_neg_ack_sent_S  L"num_neg_ack_sent" 
 #define  ACK_MSG_STAT_GET_num_wrong_order_ack_S  L"num_wrong_order_ack" 
 #define  ACK_MSG_STAT_GET_num_tx_fwfifo_full_S  L"num_tx_fwfifo_full" 
 #define  ACK_MSG_STAT_GET_num_rx_fwfifo_full_S  L"num_rx_fwfifo_full" 
 #define  ACK_MSG_STAT_GET_num_RFO_S  L"num_RFO" 
 #define  ACK_MSG_STAT_GET_num_XDOV_S  L"num_XDOV" 
 #define  ACK_MSG_STAT_GET_num_XDU_S  L"num_XDU" 
 #define  ACK_MSG_STAT_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_MSG_STAT_GET_rsvd2_S  L"rsvd2" 



/* message elements: ACK_CFG_PERF_PRIM */


 #define  ACK_CFG_PERF_PRIM_prims_S  L"prims" 



/* message elements: ACK_PERF_PRIM_GET */


 #define  ACK_PERF_PRIM_GET_prims_S  L"prims" 



/* message elements: ACK_PERF_STATUS_GET */


 #define  ACK_PERF_STATUS_GET_SNR_Margin_dB_S  L"SNR_Margin_dB" 
 #define  ACK_PERF_STATUS_GET_LoopAttenuation_dB_S  L"LoopAttenuation_dB" 
 #define  ACK_PERF_STATUS_GET_ES_count_S  L"ES_count" 
 #define  ACK_PERF_STATUS_GET_SES_count_S  L"SES_count" 
 #define  ACK_PERF_STATUS_GET_CRC_Anomaly_count_S  L"CRC_Anomaly_count" 
 #define  ACK_PERF_STATUS_GET_LOSWS_count_S  L"LOSWS_count" 
 #define  ACK_PERF_STATUS_GET_UAS_Count_S  L"UAS_Count" 
 #define  ACK_PERF_STATUS_GET_SegmentAnomaly_Count_S  L"SegmentAnomaly_Count" 
 #define  ACK_PERF_STATUS_GET_SegmentDefectS_Count_S  L"SegmentDefectS_Count" 
 #define  ACK_PERF_STATUS_GET_CounterOverflowInd_S  L"CounterOverflowInd" 
 #define  ACK_PERF_STATUS_GET_CounterResetInd_S  L"CounterResetInd" 



/* message elements: ACK_PERF_DETAILS_GET */


 #define  ACK_PERF_DETAILS_GET_CRC_Anomaly_count_S  L"CRC_Anomaly_count" 
 #define  ACK_PERF_DETAILS_GET_LOSWD_count_S  L"LOSWD_count" 
 #define  ACK_PERF_DETAILS_GET_SNR_Margin_dB_S  L"SNR_Margin_dB" 
 #define  ACK_PERF_DETAILS_GET_LoopAttenuation_dB_S  L"LoopAttenuation_dB" 
 #define  ACK_PERF_DETAILS_GET_AAGC_dB_S  L"AAGC_dB" 
 #define  ACK_PERF_DETAILS_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_PERF_DETAILS_GET_DAGC_dB_S  L"DAGC_dB" 
 #define  ACK_PERF_DETAILS_GET_total_rx_gain_S  L"total_rx_gain" 
 #define  ACK_PERF_DETAILS_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_PERF_DETAILS_GET_rsvd2_S  L"rsvd2" 



/* message elements: ACK_FBIT_RX_GET */


 #define  ACK_FBIT_RX_GET_fbits_S  L"fbits" 



/* message elements: ACK_EOC_TX */


 #define  ACK_EOC_TX_ack_type_S  L"ack_type" 



/* message elements: ACK_MULTIWIRE_PMMS_RESULT_GET */


 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_pbo_S  L"train_pbo" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_1_S  L"train_baserate_1" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_2_S  L"train_baserate_2" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_3_S  L"train_baserate_3" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_4_S  L"train_baserate_4" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_5_S  L"train_baserate_5" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_6_S  L"train_baserate_6" 
 #define  ACK_MULTIWIRE_PMMS_RESULT_GET_train_baserate_7_S  L"train_baserate_7" 



/* message elements: ACK_MULTIWIRE_MDATA_GET */


 #define  ACK_MULTIWIRE_MDATA_GET_DataType_S  L"DataType" 
 #define  ACK_MULTIWIRE_MDATA_GET_Data_S  L"Data" 
 #define  ACK_MULTIWIRE_MDATA_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_MULTIWIRE_MDATA_GET_rsvd1_S  L"rsvd1" 



/* message elements: ACK_MULTIWIRE_SDATA_GET */


 #define  ACK_MULTIWIRE_SDATA_GET_DataType_S  L"DataType" 
 #define  ACK_MULTIWIRE_SDATA_GET_Data_S  L"Data" 
 #define  ACK_MULTIWIRE_SDATA_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_MULTIWIRE_SDATA_GET_rsvd1_S  L"rsvd1" 



/* message definitions */

/** message: ACK_PMMS_RESULTS_GET */

typedef struct ack_pmms_results_get_s 
{ 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** probe payload rate */ 
  uint16  probe_rate_1; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_1; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_1; 
  /** Estimated Power Loss */ 
  int8  EPL_1; 
  /** probe payload rate */ 
  uint16  probe_rate_2; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_2; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_2; 
  /** Estimated Power Loss */ 
  int8  EPL_2; 
  /** probe payload rate */ 
  uint16  probe_rate_3; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_3; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_3; 
  /** Estimated Power Loss */ 
  int8  EPL_3; 
  /** probe payload rate */ 
  uint16  probe_rate_4; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_4; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_4; 
  /** Estimated Power Loss */ 
  int8  EPL_4; 
  /** probe payload rate */ 
  uint16  probe_rate_5; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_5; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_5; 
  /** Estimated Power Loss */ 
  int8  EPL_5; 
  /** probe payload rate */ 
  uint16  probe_rate_6; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_6; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_6; 
  /** Estimated Power Loss */ 
  int8  EPL_6; 
  /** probe payload rate */ 
  uint16  probe_rate_7; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_7; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_7; 
  /** Estimated Power Loss */ 
  int8  EPL_7; 
  /** probe payload rate */ 
  uint16  probe_rate_8; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_8; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_8; 
  /** Estimated Power Loss */ 
  int8  EPL_8; 
  /** probe payload rate */ 
  uint16  probe_rate_9; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_9; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_9; 
  /** Estimated Power Loss */ 
  int8  EPL_9; 
  /** probe payload rate */ 
  uint16  probe_rate_10; 
  /** SNR margin for 16-TCPAM */ 
  int8  SNR_mrg16_10; 
  /** SNR margin for 32-TCPAM */ 
  int8  SNR_mrg32_10; 
  /** Estimated Power Loss */ 
  int8  EPL_10; 
} __PACKED__ ack_pmms_results_get_t; 


/** message: ACK_GHS_NS_FIELD_GET */

typedef struct ack_ghs_ns_field_get_s 
{ 
  /** valid_ns_data */ 
  uint8  valid_ns_data; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** ns_info_length */ 
  uint8  ns_info_length; 
  /** ns_info */ 
  uint8  ns_info[16]; 
} __PACKED__ ack_ghs_ns_field_get_t; 


/** message: ACK_GHS_CAP_GET */

typedef struct ack_ghs_cap_get_s 
{ 
  /** ClType */ 
  uint8  ClType; 
  /** ClParam */ 
  uint8  ClParam; 
  /** ClOctetNrNPar */ 
  uint8  ClOctetNrNPar; 
  /** ClOctetNrSPar */ 
  uint8  ClOctetNrSPar; 
  /** rsvd0 */ 
  uint8  rsvd0; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** rsvd3 */ 
  uint8  rsvd3; 
  /** ClData */ 
  uint8  ClData[32]; 
} __PACKED__ ack_ghs_cap_get_t; 


/** message: ACK_CFG_GHS_CAP */

typedef struct ack_cfg_ghs_cap_s 
{ 
  /** ClParam */ 
  uint8  ClParam; 
  /** ClSupOctets */ 
  uint8  ClSupOctets; 
  /** ClReqOctets */ 
  uint8  ClReqOctets; 
  /** ClConfigOctets */ 
  uint8  ClConfigOctets; 
  /** rsvd0 */ 
  uint8  rsvd0; 
  /** rsvd1 */ 
  uint8  rsvd1; 
  /** rsvd2 */ 
  uint8  rsvd2; 
  /** rsvd3 */ 
  uint8  rsvd3; 
} __PACKED__ ack_cfg_ghs_cap_t; 


/** message: ACK_CONNECT_CTRL */

typedef struct ack_connect_ctrl_s 
{ 
  /** State */ 
  int8  state; 
  /** Return status */ 
  uint8  status; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ ack_connect_ctrl_t; 


/** message: ACK_CONNECT_STAT_GET */

typedef struct ack_connect_stat_get_s 
{ 
  /** State */ 
  int8  state; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ ack_connect_stat_get_t; 


/** message: ACK_DSL_PARAM_GET */

typedef struct ack_dsl_param_get_s 
{ 
  /** STU Mode */ 
  uint8  stu_mode; 
  /** Repeater or Terminator */ 
  uint8  repeater; 
  /** Annex */ 
  uint8  annex; 
  /** Clocking Mode */ 
  uint8  clk_ref; 
  /** Payload Base Rate */ 
  uint16  base_rate; 
  /** Payload Sub Rate */ 
  uint8  sub_rate; 
  /** Power Spectral Density Mask */ 
  uint8  psd_mask; 
  /** SHDSL Framing Mode */ 
  uint8  frame_mode; 
  /** Rsvd */ 
  uint8  rsvd2; 
  /** Tx Sync Word */ 
  uint16  tx_sync_word; 
  /** Rx Sync Word */ 
  uint16  rx_sync_word; 
  /** Tx Stuff Bits */ 
  uint8  tx_stuff_bits; 
  /** Rx Stuff Bits */ 
  uint8  rx_stuff_bits; 
  /** Power Backoff */ 
  int8  pow_backoff; 
  /** Power Backoff Far End */ 
  int8  pow_backoff_farend; 
  /** Handshake Power Leverage Carrier */ 
  uint8  ghs_pwr_lev_carr; 
  /** Bits per Symbol */ 
  uint8  bits_p_symbol; 
} __PACKED__ ack_dsl_param_get_t; 


/** message: ACK_CAPLIST_GET */

typedef struct ack_caplist_get_s 
{ 
  /** caplist_type_get */ 
  uint8  caplist_type_get; 
  /** ghs_caplist */ 
  uint8  ghs_caplist[120]; 
} __PACKED__ ack_caplist_get_t; 


/** message: ACK_CFG_EFM_DISCOVERY_DATA */

typedef struct ack_cfg_efm_discovery_data_s 
{ 
  /** discovery_op */ 
  uint8  discovery_op; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
} __PACKED__ ack_cfg_efm_discovery_data_t; 


/** message: ACK_EFM_DISCOVERY_DATA_GET */

typedef struct ack_efm_discovery_data_get_s 
{ 
  /** discovery_op */ 
  uint8  discovery_op; 
  /** discovery_op_stat */ 
  uint8  discovery_op_stat; 
  /** discovery_reg_hi */ 
  uint16  discovery_reg_hi; 
  /** discovery_reg_lo */ 
  uint32  discovery_reg_lo; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ ack_efm_discovery_data_get_t; 


/** message: NFC_EFM_DISCOVERY_OP_RDY */

typedef struct nfc_efm_discovery_op_rdy_s 
{ 
  /** discovery_op */ 
  uint8  discovery_op; 
  /** discovery_op_stat */ 
  uint8  discovery_op_stat; 
  /** discovery_reg_hi */ 
  uint16  discovery_reg_hi; 
  /** discovery_reg_lo */ 
  uint32  discovery_reg_lo; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ nfc_efm_discovery_op_rdy_t; 


/** message: ACK_CFG_EFM_AGGREGATE_DATA */

typedef struct ack_cfg_efm_aggregate_data_s 
{ 
  /** aggregate_op */ 
  uint8  aggregate_op; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
} __PACKED__ ack_cfg_efm_aggregate_data_t; 


/** message: ACK_EFM_AGGREGATE_DATA_GET */

typedef struct ack_efm_aggregate_data_get_s 
{ 
  /** aggregate_op */ 
  uint8  aggregate_op; 
  /** aggregate_op_stat */ 
  uint8  aggregate_op_stat; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** aggregate_reg */ 
  uint32  aggregate_reg; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
  /** Reserved */ 
  uint8  rsvd4; 
  /** Reserved */ 
  uint8  rsvd5; 
} __PACKED__ ack_efm_aggregate_data_get_t; 


/** message: NFC_EFM_AGGREGATE_OP_RDY */

typedef struct nfc_efm_aggregate_op_rdy_s 
{ 
  /** aggregate_op */ 
  uint8  aggregate_op; 
  /** aggregate_op_stat */ 
  uint8  aggregate_op_stat; 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** aggregate_reg */ 
  uint32  aggregate_reg; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
  /** Reserved */ 
  uint8  rsvd4; 
  /** Reserved */ 
  uint8  rsvd5; 
} __PACKED__ nfc_efm_aggregate_op_rdy_t; 


/** message: ACK_EFM_START_ACTIVATION */

typedef struct ack_efm_start_activation_s 
{ 
  /** Reserved */ 
  uint8  rsvd0; 
  /** Reserved */ 
  uint8  rsvd1; 
  /** Reserved */ 
  uint8  rsvd2; 
  /** Reserved */ 
  uint8  rsvd3; 
} __PACKED__ ack_efm_start_activation_t; 


/** message: ACK_ID_GET */

typedef struct ack_id_get_s 
{ 
  /** WHAT string header */ 
  uint8  what[4]; 
  /** Firmware ID */ 
  uint8  fw_id[32]; 
} __PACKED__ ack_id_get_t; 


/** message: ACK_FEATURE_STR_GET */

typedef struct ack_feature_str_get_s 
{ 
  /** WHAT string header */ 
  uint8  what[12]; 
  /** Feature string */ 
  uint8  feature_str[64]; 
} __PACKED__ ack_feature_str_get_t; 


/** message: ACK_MSG_STAT_GET */

typedef struct ack_msg_stat_get_s 
{ 
  /** number of timeouts */ 
  uint8  num_timeout; 
  /** number of negative acknowledges received */ 
  uint8  num_neg_ack_rec; 
  /** number of negative acknowledges sent */ 
  uint8  num_neg_ack_sent; 
  /** number of wrong order acknowledges */ 
  uint8  num_wrong_order_ack; 
  /** number of overflows in the SCI transmit firmware fifo */ 
  uint8  num_tx_fwfifo_full; 
  /** number of overflows in the SCI receive firmware fifo */ 
  uint8  num_rx_fwfifo_full; 
  /** number of RFO interrupts in the SCI receive hardware buffer */ 
  uint8  num_RFO; 
  /** number of XDOV interrupts in the SCI receive hardware buffer */ 
  uint8  num_XDOV; 
  /** number of XDU interrupts in the SCI receive hardware buffer */ 
  uint8  num_XDU; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ ack_msg_stat_get_t; 


/** message: ACK_CFG_PERF_PRIM */

typedef struct ack_cfg_perf_prim_s 
{ 
  /** Bit vector for performance primitives. */ 
  uint8  prims; 
} __PACKED__ ack_cfg_perf_prim_t; 


/** message: ACK_PERF_PRIM_GET */

typedef struct ack_perf_prim_get_s 
{ 
  /** Bit vector for performance primitives. */ 
  uint8  prims; 
} __PACKED__ ack_perf_prim_get_t; 


/** message: ACK_PERF_STATUS_GET */

typedef struct ack_perf_status_get_s 
{ 
  /** SNR margin for BER of 10 E-7 */ 
  int8  SNR_Margin_dB; 
  /** Measured loop attenuation in dB */ 
  int8  LoopAttenuation_dB; 
  /** Errored seconds counter */ 
  uint8  ES_count; 
  /** Severely Errored seconds counter */ 
  uint8  SES_count; 
  /** CRC Anomaly counter counter */ 
  uint16  CRC_Anomaly_count; 
  /** Loss of Syncword defect seconds count */ 
  uint8  LOSWS_count; 
  /** Unavailable seconds count */ 
  uint8  UAS_Count; 
  /** Segment anomaly counter */ 
  uint16  SegmentAnomaly_Count; 
  /** Segment Defect seconds count */ 
  uint8  SegmentDefectS_Count; 
  /** Counter overflow occurred */ 
  uint8  CounterOverflowInd; 
  /** Counter reset occurred */ 
  uint8  CounterResetInd; 
} __PACKED__ ack_perf_status_get_t; 


/** message: ACK_PERF_DETAILS_GET */

typedef struct ack_perf_details_get_s 
{ 
  /** CRC anomaly counter */ 
  uint16  CRC_Anomaly_count; 
  /** LOSW anomaly counter */ 
  uint16  LOSWD_count; 
  /** SNR margin for BER of 10 E-7 */ 
  int16  SNR_Margin_dB; 
  /** Measured loop attenuation in dB */ 
  int16  LoopAttenuation_dB; 
  /** Value of the analog AGC in DB */ 
  int8  AAGC_dB; 
  /** Reserved, padding for int16 alignment */ 
  uint8  rsvd0; 
  /** Value of the digital AGC in DB */ 
  int16  DAGC_dB; 
  /** Total adaptive gain */ 
  int32  total_rx_gain; 
  /** Reserved for future use */ 
  uint32  rsvd1; 
  /** Reserved for future use */ 
  uint32  rsvd2; 
} __PACKED__ ack_perf_details_get_t; 


/** message: ACK_FBIT_RX_GET */

typedef struct ack_fbit_rx_get_s 
{ 
  /** The four fbits of the SHDSL frame */ 
  uint8  fbits; 
} __PACKED__ ack_fbit_rx_get_t; 


/** message: ACK_EOC_TX */

typedef struct ack_eoc_tx_s 
{ 
  /** Type of acknowledgement */ 
  uint8  ack_type; 
} __PACKED__ ack_eoc_tx_t; 


/** message: ACK_MULTIWIRE_PMMS_RESULT_GET */

typedef struct ack_multiwire_pmms_result_get_s 
{ 
  /** Training power backoff */ 
  uint8  train_pbo; 
  /** Training base rate 1 */ 
  uint8  train_baserate_1; 
  /** Training base rate 2 */ 
  uint8  train_baserate_2; 
  /** Training base rate 3 */ 
  uint8  train_baserate_3; 
  /** Training base rate 4 */ 
  uint8  train_baserate_4; 
  /** Training base rate 5 */ 
  uint8  train_baserate_5; 
  /** Training base rate 6 */ 
  uint8  train_baserate_6; 
  /** Training base rate 7 */ 
  uint8  train_baserate_7; 
} __PACKED__ ack_multiwire_pmms_result_get_t; 


/** message: ACK_MULTIWIRE_MDATA_GET */

typedef struct ack_multiwire_mdata_get_s 
{ 
  /** Type of the requested data. */ 
  uint8  DataType; 
  /** Requested data. */ 
  uint8  Data; 
  /** Reserved. */ 
  uint8  rsvd0; 
  /** Reserved. */ 
  uint8  rsvd1; 
} __PACKED__ ack_multiwire_mdata_get_t; 


/** message: ACK_MULTIWIRE_SDATA_GET */

typedef struct ack_multiwire_sdata_get_s 
{ 
  /** Type of the requested data. */ 
  uint8  DataType; 
  /** Requested data. */ 
  uint8  Data; 
  /** Reserved. */ 
  uint8  rsvd0; 
  /** Reserved. */ 
  uint8  rsvd1; 
} __PACKED__ ack_multiwire_sdata_get_t; 

/*@}*/ /* Acknowledge Messages */


/** \addtogroup SDFE4_Debug_Commands Debug Commands */

/*@{*/


/* message identifiers */


 #define  CMD_FILT_COEF_PRINTF  0x5C02 
 #define  CMD_FILT_COEF_GET  0x5812 
 #define  CMD_SET_PDI_REG  0x5C1F 
 #define  CMD_PDI_REG_GET  0x580F 
 #define  CMD_SET_DBG_PROBE  0x5C0F 
 #define  CMD_BERT_ENABLE  0x5C2F 
 #define  CMD_PDI_REGS_PRINTF  0x5C3F 
 #define  CMD_FINGERPRINT_GET  0x5802 
 #define  CMD_BERT_COUNT_GET  0x581F 
 #define  CMD_CFG_PARAM_VECTOR  0x540F 
 #define  CMD_PARAM_VECTOR_GET  0x541F 
 #define  CMD_START_TDR  0xDC0F 
 #define  CMD_TDR_DATA_GET  0xDC1F 
 #define  CMD_PMMS_SNRMARGIN_GET  0xC80F 
 #define  CMD_PMMS_EPL_GET  0xC81F 
 #define  CMD_FILT_COEF_PRINTF_S  "CMD_FILT_COEF_PRINTF" 
 #define  CMD_FILT_COEF_GET_S  "CMD_FILT_COEF_GET" 
 #define  CMD_SET_PDI_REG_S  "CMD_SET_PDI_REG" 
 #define  CMD_PDI_REG_GET_S  "CMD_PDI_REG_GET" 
 #define  CMD_SET_DBG_PROBE_S  "CMD_SET_DBG_PROBE" 
 #define  CMD_BERT_ENABLE_S  "CMD_BERT_ENABLE" 
 #define  CMD_PDI_REGS_PRINTF_S  "CMD_PDI_REGS_PRINTF" 
 #define  CMD_FINGERPRINT_GET_S  "CMD_FINGERPRINT_GET" 
 #define  CMD_BERT_COUNT_GET_S  "CMD_BERT_COUNT_GET" 
 #define  CMD_CFG_PARAM_VECTOR_S  "CMD_CFG_PARAM_VECTOR" 
 #define  CMD_PARAM_VECTOR_GET_S  "CMD_PARAM_VECTOR_GET" 
 #define  CMD_START_TDR_S  "CMD_START_TDR" 
 #define  CMD_TDR_DATA_GET_S  "CMD_TDR_DATA_GET" 
 #define  CMD_PMMS_SNRMARGIN_GET_S  "CMD_PMMS_SNRMARGIN_GET" 
 #define  CMD_PMMS_EPL_GET_S  "CMD_PMMS_EPL_GET" 



/* message elements: CMD_FILT_COEF_PRINTF */


 #define  CMD_FILT_COEF_PRINTF_filter_S  L"filter" 
 #define  CMD_FILT_COEF_PRINTF_rsvd1_S  L"rsvd1" 
 #define  CMD_FILT_COEF_PRINTF_rsvd2_S  L"rsvd2" 



/* message elements: CMD_FILT_COEF_GET */


 #define  CMD_FILT_COEF_GET_filter_S  L"filter" 
 #define  CMD_FILT_COEF_GET_block_no_S  L"block_no" 
 #define  CMD_FILT_COEF_GET_rsvd1_S  L"rsvd1" 



/* message elements: CMD_SET_PDI_REG */


 #define  CMD_SET_PDI_REG_pdi_addr_S  L"pdi_addr" 
 #define  CMD_SET_PDI_REG_rsvd1_S  L"rsvd1" 
 #define  CMD_SET_PDI_REG_rsvd2_S  L"rsvd2" 
 #define  CMD_SET_PDI_REG_data_S  L"data" 
 #define  CMD_SET_PDI_REG_mask_S  L"mask" 



/* message elements: CMD_PDI_REG_GET */


 #define  CMD_PDI_REG_GET_pdi_addr_S  L"pdi_addr" 
 #define  CMD_PDI_REG_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_PDI_REG_GET_rsvd2_S  L"rsvd2" 



/* message elements: CMD_SET_DBG_PROBE */


 #define  CMD_SET_DBG_PROBE_dump_port_no_S  L"dump_port_no" 
 #define  CMD_SET_DBG_PROBE_probe_S  L"probe" 
 #define  CMD_SET_DBG_PROBE_trigger_S  L"trigger" 
 #define  CMD_SET_DBG_PROBE_rsvd_S  L"rsvd" 



/* message elements: CMD_CFG_PARAM_VECTOR */


 #define  CMD_CFG_PARAM_VECTOR_par0_S  L"par0" 
 #define  CMD_CFG_PARAM_VECTOR_par1_S  L"par1" 
 #define  CMD_CFG_PARAM_VECTOR_par2_S  L"par2" 
 #define  CMD_CFG_PARAM_VECTOR_par3_S  L"par3" 
 #define  CMD_CFG_PARAM_VECTOR_par4_S  L"par4" 
 #define  CMD_CFG_PARAM_VECTOR_par5_S  L"par5" 
 #define  CMD_CFG_PARAM_VECTOR_par6_S  L"par6" 
 #define  CMD_CFG_PARAM_VECTOR_par7_S  L"par7" 
 #define  CMD_CFG_PARAM_VECTOR_par8_S  L"par8" 
 #define  CMD_CFG_PARAM_VECTOR_par9_S  L"par9" 
 #define  CMD_CFG_PARAM_VECTOR_par10_S  L"par10" 
 #define  CMD_CFG_PARAM_VECTOR_par11_S  L"par11" 
 #define  CMD_CFG_PARAM_VECTOR_par12_S  L"par12" 
 #define  CMD_CFG_PARAM_VECTOR_par13_S  L"par13" 
 #define  CMD_CFG_PARAM_VECTOR_par14_S  L"par14" 
 #define  CMD_CFG_PARAM_VECTOR_par15_S  L"par15" 



/* message elements: CMD_TDR_DATA_GET */


 #define  CMD_TDR_DATA_GET_k_S  L"k" 
 #define  CMD_TDR_DATA_GET_rsvd1_S  L"rsvd1" 
 #define  CMD_TDR_DATA_GET_rsvd2_S  L"rsvd2" 



/* message definitions */

/** message: CMD_FILT_COEF_PRINTF */

typedef struct cmd_filt_coef_printf_s 
{ 
  /** Identifier of the filter */ 
  uint8  filter; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ cmd_filt_coef_printf_t; 


/** message: CMD_FILT_COEF_GET */

typedef struct cmd_filt_coef_get_s 
{ 
  /** Identifier of the filter */ 
  uint8  filter; 
  /** Number of the required block */ 
  uint8  block_no; 
  /** Reserved for future use. */ 
  uint16  rsvd1; 
} __PACKED__ cmd_filt_coef_get_t; 


/** message: CMD_SET_PDI_REG */

typedef struct cmd_set_pdi_reg_s 
{ 
  /** address of the PDI register */ 
  uint8  pdi_addr; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
  /** data to be written to the register */ 
  uint32  data; 
  /** mask for writing tho the register */ 
  uint32  mask; 
} __PACKED__ cmd_set_pdi_reg_t; 


/** message: CMD_PDI_REG_GET */

typedef struct cmd_pdi_reg_get_s 
{ 
  /** address of the PDI register */ 
  uint8  pdi_addr; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ cmd_pdi_reg_get_t; 


/** message: CMD_SET_DBG_PROBE */

typedef struct cmd_set_dbg_probe_s 
{ 
  /** dbg dump port number of PAMDSL */ 
  uint8  dump_port_no; 
  /** Identifier of the PAMDSL datapath signal */ 
  uint8  probe; 
  /** Trigger signal */ 
  uint8  trigger; 
  /** Rsvd */ 
  uint8  rsvd; 
} __PACKED__ cmd_set_dbg_probe_t; 


/** message: CMD_CFG_PARAM_VECTOR */

typedef struct cmd_cfg_param_vector_s 
{ 
  /** Parameter */ 
  int32  par0; 
  /** Parameter */ 
  int32  par1; 
  /** Parameter */ 
  int32  par2; 
  /** Parameter */ 
  int32  par3; 
  /** Parameter */ 
  int32  par4; 
  /** Parameter */ 
  int32  par5; 
  /** Parameter */ 
  int32  par6; 
  /** Parameter */ 
  int32  par7; 
  /** Parameter */ 
  int32  par8; 
  /** Parameter */ 
  int32  par9; 
  /** Parameter */ 
  int32  par10; 
  /** Parameter */ 
  int32  par11; 
  /** Parameter */ 
  int32  par12; 
  /** Parameter */ 
  int32  par13; 
  /** Parameter */ 
  int32  par14; 
  /** Parameter */ 
  int32  par15; 
} __PACKED__ cmd_cfg_param_vector_t; 


/** message: CMD_TDR_DATA_GET */

typedef struct cmd_tdr_data_get_s 
{ 
  /** kth subset of EC coefficients */ 
  uint8  k; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
} __PACKED__ cmd_tdr_data_get_t; 

/*@}*/ /* Debug Commands */


/** \addtogroup SDFE4_Debug_Indications Debug Indications */

/*@{*/


/* message identifiers */


 #define  ACK_PDI_REG_GET  0x5A0F 
 #define  ACK_SET_DEBUG_PROBE  0x5E0F 
 #define  ACK_FILT_COEF_PRINTF  0x5E02 
 #define  ACK_SET_PDI_REG  0x5E1F 
 #define  ACK_BERT_ENABLE  0x5E2F 
 #define  NFC_PRINTF  0x510F 
 #define  ACK_PDI_REGS_PRINTF  0x5E3F 
 #define  ACK_BERT_COUNT_GET  0x5A1F 
 #define  ACK_FINGERPRINT_GET  0x5A02 
 #define  ACK_CFG_PARAM_VECTOR  0x560F 
 #define  ACK_PARAM_VECTOR_GET  0x561F 
 #define  ACK_START_TDR  0xDE0F 
 #define  NFC_TDR_DONE  0xDD2F 
 #define  ACK_TDR_DATA_GET  0xDE1F 
 #define  ACK_FILT_COEF_GET  0x5A12 
 #define  ACK_PMMS_SNRMARGIN_GET  0xCA0F 
 #define  ACK_PMMS_EPL_GET  0xCA1F 
 #define  ACK_PDI_REG_GET_S  "ACK_PDI_REG_GET" 
 #define  ACK_SET_DEBUG_PROBE_S  "ACK_SET_DEBUG_PROBE" 
 #define  ACK_FILT_COEF_PRINTF_S  "ACK_FILT_COEF_PRINTF" 
 #define  ACK_SET_PDI_REG_S  "ACK_SET_PDI_REG" 
 #define  ACK_BERT_ENABLE_S  "ACK_BERT_ENABLE" 
 #define  NFC_PRINTF_S  "NFC_PRINTF" 
 #define  ACK_PDI_REGS_PRINTF_S  "ACK_PDI_REGS_PRINTF" 
 #define  ACK_BERT_COUNT_GET_S  "ACK_BERT_COUNT_GET" 
 #define  ACK_FINGERPRINT_GET_S  "ACK_FINGERPRINT_GET" 
 #define  ACK_CFG_PARAM_VECTOR_S  "ACK_CFG_PARAM_VECTOR" 
 #define  ACK_PARAM_VECTOR_GET_S  "ACK_PARAM_VECTOR_GET" 
 #define  ACK_START_TDR_S  "ACK_START_TDR" 
 #define  NFC_TDR_DONE_S  "NFC_TDR_DONE" 
 #define  ACK_TDR_DATA_GET_S  "ACK_TDR_DATA_GET" 
 #define  ACK_FILT_COEF_GET_S  "ACK_FILT_COEF_GET" 
 #define  ACK_PMMS_SNRMARGIN_GET_S  "ACK_PMMS_SNRMARGIN_GET" 
 #define  ACK_PMMS_EPL_GET_S  "ACK_PMMS_EPL_GET" 



/* message elements: ACK_PDI_REG_GET */


 #define  ACK_PDI_REG_GET_pdi_addr_S  L"pdi_addr" 
 #define  ACK_PDI_REG_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_PDI_REG_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_PDI_REG_GET_data_S  L"data" 



/* message elements: NFC_PRINTF */


 #define  NFC_PRINTF_string_S  L"string" 



/* message elements: ACK_BERT_COUNT_GET */


 #define  ACK_BERT_COUNT_GET_bert_count_S  L"bert_count" 



/* message elements: ACK_FINGERPRINT_GET */


 #define  ACK_FINGERPRINT_GET_PBO_local_S  L"PBO_local" 
 #define  ACK_FINGERPRINT_GET_PBO_farend_S  L"PBO_farend" 
 #define  ACK_FINGERPRINT_GET_farend_vendor_S  L"farend_vendor" 
 #define  ACK_FINGERPRINT_GET_AFE_version_S  L"AFE_version" 
 #define  ACK_FINGERPRINT_GET_echo_pwr_before_hyb_S  L"echo_pwr_before_hyb" 
 #define  ACK_FINGERPRINT_GET_echo_pwr_after_hyb_S  L"echo_pwr_after_hyb" 
 #define  ACK_FINGERPRINT_GET_AFE_gain_S  L"AFE_gain" 
 #define  ACK_FINGERPRINT_GET_parset_S  L"parset" 
 #define  ACK_FINGERPRINT_GET_subset_S  L"subset" 
 #define  ACK_FINGERPRINT_GET_pad0_S  L"pad0" 
 #define  ACK_FINGERPRINT_GET_DAGC_gain_S  L"DAGC_gain" 
 #define  ACK_FINGERPRINT_GET_osr_int_4_S  L"osr_int_4" 
 #define  ACK_FINGERPRINT_GET_osr_frac_4_S  L"osr_frac_4" 
 #define  ACK_FINGERPRINT_GET_aif_frame0_S  L"aif_frame0" 
 #define  ACK_FINGERPRINT_GET_aif_frame1_S  L"aif_frame1" 
 #define  ACK_FINGERPRINT_GET_aif_frame2_S  L"aif_frame2" 
 #define  ACK_FINGERPRINT_GET_rsvd0_S  L"rsvd0" 
 #define  ACK_FINGERPRINT_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_FINGERPRINT_GET_rsvd2_S  L"rsvd2" 
 #define  ACK_FINGERPRINT_GET_rsvd3_S  L"rsvd3" 



/* message elements: ACK_PARAM_VECTOR_GET */


 #define  ACK_PARAM_VECTOR_GET_par0_S  L"par0" 
 #define  ACK_PARAM_VECTOR_GET_par1_S  L"par1" 
 #define  ACK_PARAM_VECTOR_GET_par2_S  L"par2" 
 #define  ACK_PARAM_VECTOR_GET_par3_S  L"par3" 
 #define  ACK_PARAM_VECTOR_GET_par4_S  L"par4" 
 #define  ACK_PARAM_VECTOR_GET_par5_S  L"par5" 
 #define  ACK_PARAM_VECTOR_GET_par6_S  L"par6" 
 #define  ACK_PARAM_VECTOR_GET_par7_S  L"par7" 
 #define  ACK_PARAM_VECTOR_GET_par8_S  L"par8" 
 #define  ACK_PARAM_VECTOR_GET_par9_S  L"par9" 
 #define  ACK_PARAM_VECTOR_GET_par10_S  L"par10" 
 #define  ACK_PARAM_VECTOR_GET_par11_S  L"par11" 
 #define  ACK_PARAM_VECTOR_GET_par12_S  L"par12" 
 #define  ACK_PARAM_VECTOR_GET_par13_S  L"par13" 
 #define  ACK_PARAM_VECTOR_GET_par14_S  L"par14" 
 #define  ACK_PARAM_VECTOR_GET_par15_S  L"par15" 



/* message elements: ACK_TDR_DATA_GET */


 #define  ACK_TDR_DATA_GET_tdr_data_1_S  L"tdr_data_1" 
 #define  ACK_TDR_DATA_GET_tdr_data_2_S  L"tdr_data_2" 
 #define  ACK_TDR_DATA_GET_tdr_data_3_S  L"tdr_data_3" 
 #define  ACK_TDR_DATA_GET_tdr_data_4_S  L"tdr_data_4" 
 #define  ACK_TDR_DATA_GET_tdr_data_5_S  L"tdr_data_5" 
 #define  ACK_TDR_DATA_GET_tdr_data_6_S  L"tdr_data_6" 
 #define  ACK_TDR_DATA_GET_tdr_data_7_S  L"tdr_data_7" 
 #define  ACK_TDR_DATA_GET_tdr_data_8_S  L"tdr_data_8" 
 #define  ACK_TDR_DATA_GET_tdr_data_9_S  L"tdr_data_9" 
 #define  ACK_TDR_DATA_GET_tdr_data_10_S  L"tdr_data_10" 
 #define  ACK_TDR_DATA_GET_tdr_data_11_S  L"tdr_data_11" 
 #define  ACK_TDR_DATA_GET_tdr_data_12_S  L"tdr_data_12" 
 #define  ACK_TDR_DATA_GET_tdr_data_13_S  L"tdr_data_13" 
 #define  ACK_TDR_DATA_GET_tdr_data_14_S  L"tdr_data_14" 
 #define  ACK_TDR_DATA_GET_tdr_data_15_S  L"tdr_data_15" 
 #define  ACK_TDR_DATA_GET_tdr_data_16_S  L"tdr_data_16" 



/* message elements: ACK_FILT_COEF_GET */


 #define  ACK_FILT_COEF_GET_filter_S  L"filter" 
 #define  ACK_FILT_COEF_GET_block_no_S  L"block_no" 
 #define  ACK_FILT_COEF_GET_num_valid_S  L"num_valid" 
 #define  ACK_FILT_COEF_GET_rsvd1_S  L"rsvd1" 
 #define  ACK_FILT_COEF_GET_coef_1_S  L"coef_1" 
 #define  ACK_FILT_COEF_GET_coef_2_S  L"coef_2" 
 #define  ACK_FILT_COEF_GET_coef_3_S  L"coef_3" 
 #define  ACK_FILT_COEF_GET_coef_4_S  L"coef_4" 
 #define  ACK_FILT_COEF_GET_coef_5_S  L"coef_5" 
 #define  ACK_FILT_COEF_GET_coef_6_S  L"coef_6" 
 #define  ACK_FILT_COEF_GET_coef_7_S  L"coef_7" 
 #define  ACK_FILT_COEF_GET_coef_8_S  L"coef_8" 
 #define  ACK_FILT_COEF_GET_coef_9_S  L"coef_9" 
 #define  ACK_FILT_COEF_GET_coef_10_S  L"coef_10" 
 #define  ACK_FILT_COEF_GET_coef_11_S  L"coef_11" 
 #define  ACK_FILT_COEF_GET_coef_12_S  L"coef_12" 
 #define  ACK_FILT_COEF_GET_coef_13_S  L"coef_13" 
 #define  ACK_FILT_COEF_GET_coef_14_S  L"coef_14" 
 #define  ACK_FILT_COEF_GET_coef_15_S  L"coef_15" 
 #define  ACK_FILT_COEF_GET_coef_16_S  L"coef_16" 



/* message elements: ACK_PMMS_SNRMARGIN_GET */


 #define  ACK_PMMS_SNRMARGIN_GET_rsvd_S  L"rsvd" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_192_MARGIN_S  L"SNR_192_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_256_MARGIN_S  L"SNR_256_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_320_MARGIN_S  L"SNR_320_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_384_MARGIN_S  L"SNR_384_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_448_MARGIN_S  L"SNR_448_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_512_MARGIN_S  L"SNR_512_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_576_MARGIN_S  L"SNR_576_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_640_MARGIN_S  L"SNR_640_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_704_MARGIN_S  L"SNR_704_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_768_MARGIN_S  L"SNR_768_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_832_MARGIN_S  L"SNR_832_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_896_MARGIN_S  L"SNR_896_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_960_MARGIN_S  L"SNR_960_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1024_MARGIN_S  L"SNR_1024_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1088_MARGIN_S  L"SNR_1088_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1152_MARGIN_S  L"SNR_1152_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1216_MARGIN_S  L"SNR_1216_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1280_MARGIN_S  L"SNR_1280_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1344_MARGIN_S  L"SNR_1344_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1408_MARGIN_S  L"SNR_1408_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1472_MARGIN_S  L"SNR_1472_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1536_MARGIN_S  L"SNR_1536_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1600_MARGIN_S  L"SNR_1600_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1664_MARGIN_S  L"SNR_1664_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1728_MARGIN_S  L"SNR_1728_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1792_MARGIN_S  L"SNR_1792_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1856_MARGIN_S  L"SNR_1856_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1920_MARGIN_S  L"SNR_1920_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_1984_MARGIN_S  L"SNR_1984_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_2048_MARGIN_S  L"SNR_2048_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_2112_MARGIN_S  L"SNR_2112_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_2176_MARGIN_S  L"SNR_2176_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_2240_MARGIN_S  L"SNR_2240_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_2304_MARGIN_S  L"SNR_2304_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_RATE1_ASYM_MARGIN_S  L"SNR_RATE1_ASYM_MARGIN" 
 #define  ACK_PMMS_SNRMARGIN_GET_SNR_RATE2_ASYM_MARGIN_S  L"SNR_RATE2_ASYM_MARGIN" 



/* message elements: ACK_PMMS_EPL_GET */


 #define  ACK_PMMS_EPL_GET_rsvd_S  L"rsvd" 
 #define  ACK_PMMS_EPL_GET_EPL_192_S  L"EPL_192" 
 #define  ACK_PMMS_EPL_GET_EPL_256_S  L"EPL_256" 
 #define  ACK_PMMS_EPL_GET_EPL_320_S  L"EPL_320" 
 #define  ACK_PMMS_EPL_GET_EPL_384_S  L"EPL_384" 
 #define  ACK_PMMS_EPL_GET_EPL_448_S  L"EPL_448" 
 #define  ACK_PMMS_EPL_GET_EPL_512_S  L"EPL_512" 
 #define  ACK_PMMS_EPL_GET_EPL_576_S  L"EPL_576" 
 #define  ACK_PMMS_EPL_GET_EPL_640_S  L"EPL_640" 
 #define  ACK_PMMS_EPL_GET_EPL_704_S  L"EPL_704" 
 #define  ACK_PMMS_EPL_GET_EPL_768_S  L"EPL_768" 
 #define  ACK_PMMS_EPL_GET_EPL_832_S  L"EPL_832" 
 #define  ACK_PMMS_EPL_GET_EPL_896_S  L"EPL_896" 
 #define  ACK_PMMS_EPL_GET_EPL_960_S  L"EPL_960" 
 #define  ACK_PMMS_EPL_GET_EPL_1024_S  L"EPL_1024" 
 #define  ACK_PMMS_EPL_GET_EPL_1088_S  L"EPL_1088" 
 #define  ACK_PMMS_EPL_GET_EPL_1152_S  L"EPL_1152" 
 #define  ACK_PMMS_EPL_GET_EPL_1216_S  L"EPL_1216" 
 #define  ACK_PMMS_EPL_GET_EPL_1280_S  L"EPL_1280" 
 #define  ACK_PMMS_EPL_GET_EPL_1344_S  L"EPL_1344" 
 #define  ACK_PMMS_EPL_GET_EPL_1408_S  L"EPL_1408" 
 #define  ACK_PMMS_EPL_GET_EPL_1472_S  L"EPL_1472" 
 #define  ACK_PMMS_EPL_GET_EPL_1536_S  L"EPL_1536" 
 #define  ACK_PMMS_EPL_GET_EPL_1600_S  L"EPL_1600" 
 #define  ACK_PMMS_EPL_GET_EPL_1664_S  L"EPL_1664" 
 #define  ACK_PMMS_EPL_GET_EPL_1728_S  L"EPL_1728" 
 #define  ACK_PMMS_EPL_GET_EPL_1792_S  L"EPL_1792" 
 #define  ACK_PMMS_EPL_GET_EPL_1856_S  L"EPL_1856" 
 #define  ACK_PMMS_EPL_GET_EPL_1920_S  L"EPL_1920" 
 #define  ACK_PMMS_EPL_GET_EPL_1984_S  L"EPL_1984" 
 #define  ACK_PMMS_EPL_GET_EPL_2048_S  L"EPL_2048" 
 #define  ACK_PMMS_EPL_GET_EPL_2112_S  L"EPL_2112" 
 #define  ACK_PMMS_EPL_GET_EPL_2176_S  L"EPL_2176" 
 #define  ACK_PMMS_EPL_GET_EPL_2240_S  L"EPL_2240" 
 #define  ACK_PMMS_EPL_GET_EPL_2304_S  L"EPL_2304" 
 #define  ACK_PMMS_EPL_GET_EPL_Rate1_ASYM_S  L"EPL_Rate1_ASYM" 
 #define  ACK_PMMS_EPL_GET_EPL_Rate2_ASYM_S  L"EPL_Rate2_ASYM" 



/* message definitions */

/** message: ACK_PDI_REG_GET */

typedef struct ack_pdi_reg_get_s 
{ 
  /** address of the PDI register */ 
  uint8  pdi_addr; 
  /** Rsvd */ 
  uint8  rsvd1; 
  /** Rsvd */ 
  uint16  rsvd2; 
  /** contents of the PDI register */ 
  uint32  data; 
} __PACKED__ ack_pdi_reg_get_t; 


/** message: NFC_PRINTF */

typedef struct nfc_printf_s 
{ 
  /** String */ 
  int8  string[96]; 
} __PACKED__ nfc_printf_t; 


/** message: ACK_BERT_COUNT_GET */

typedef struct ack_bert_count_get_s 
{ 
  /** Bit error count value */ 
  uint32  bert_count; 
} __PACKED__ ack_bert_count_get_t; 


/** message: ACK_FINGERPRINT_GET */

typedef struct ack_fingerprint_get_s 
{ 
  /** The power backoff value used by the local transceiver. Unit: dB */ 
  int8  PBO_local; 
  /** The power backoff value used by the far end transceiver. Unit: dB */ 
  int8  PBO_farend; 
  /** The farend vendor code obtained during G.Hs. */ 
  uint8  farend_vendor; 
  /** The AFE version */ 
  uint8  AFE_version; 
  /** Measured echo power before hybrid training */ 
  uint16  echo_pwr_before_hyb; 
  /** Measured echo power after hybrid training */ 
  uint16  echo_pwr_after_hyb; 
  /** AFE gain after AFE training. Unit: dB */ 
  int8  AFE_gain; 
  /** Index of parameter set used for core activation */ 
  uint8  parset; 
  /** Index of parameter subset used for core activation */ 
  uint8  subset; 
  /** Reserved. Should be set to Zero. */ 
  uint8  pad0; 
  /** The gain of the DAGC after core activation. Fix point value, (1,16) quantization. */ 
  int32  DAGC_gain; 
  /** Oversampling ratio, integer part */ 
  uint32  osr_int_4; 
  /** Oversampling ratio, fractional part */ 
  uint32  osr_frac_4; 
  /** bit 0..31 of AIF frame, LSB is first bit in serial transmission */ 
  uint32  aif_frame0; 
  /** bit 32..63 of AIF frame, LSB is first bit in serial transmission */ 
  uint32  aif_frame1; 
  /** bit 64..95 of AIF frame, LSB is first bit in serial transmission */ 
  uint32  aif_frame2; 
  /** reserved */ 
  uint32  rsvd0; 
  /** reserved */ 
  uint32  rsvd1; 
  /** reserved */ 
  uint32  rsvd2; 
  /** reserved */ 
  uint32  rsvd3; 
} __PACKED__ ack_fingerprint_get_t; 


/** message: ACK_PARAM_VECTOR_GET */

typedef struct ack_param_vector_get_s 
{ 
  /** Parameter */ 
  int32  par0; 
  /** Parameter */ 
  int32  par1; 
  /** Parameter */ 
  int32  par2; 
  /** Parameter */ 
  int32  par3; 
  /** Parameter */ 
  int32  par4; 
  /** Parameter */ 
  int32  par5; 
  /** Parameter */ 
  int32  par6; 
  /** Parameter */ 
  int32  par7; 
  /** Parameter */ 
  int32  par8; 
  /** Parameter */ 
  int32  par9; 
  /** Parameter */ 
  int32  par10; 
  /** Parameter */ 
  int32  par11; 
  /** Parameter */ 
  int32  par12; 
  /** Parameter */ 
  int32  par13; 
  /** Parameter */ 
  int32  par14; 
  /** Parameter */ 
  int32  par15; 
} __PACKED__ ack_param_vector_get_t; 


/** message: ACK_TDR_DATA_GET */

typedef struct ack_tdr_data_get_s 
{ 
  /** TDR_DATA */ 
  int32  tdr_data_1; 
  /** TDR_DATA */ 
  int32  tdr_data_2; 
  /** TDR_DATA */ 
  int32  tdr_data_3; 
  /** TDR_DATA */ 
  int32  tdr_data_4; 
  /** TDR_DATA */ 
  int32  tdr_data_5; 
  /** TDR_DATA */ 
  int32  tdr_data_6; 
  /** TDR_DATA */ 
  int32  tdr_data_7; 
  /** TDR_DATA */ 
  int32  tdr_data_8; 
  /** TDR_DATA */ 
  int32  tdr_data_9; 
  /** TDR_DATA */ 
  int32  tdr_data_10; 
  /** TDR_DATA */ 
  int32  tdr_data_11; 
  /** TDR_DATA */ 
  int32  tdr_data_12; 
  /** TDR_DATA */ 
  int32  tdr_data_13; 
  /** TDR_DATA */ 
  int32  tdr_data_14; 
  /** TDR_DATA */ 
  int32  tdr_data_15; 
  /** TDR_DATA */ 
  int32  tdr_data_16; 
} __PACKED__ ack_tdr_data_get_t; 


/** message: ACK_FILT_COEF_GET */

typedef struct ack_filt_coef_get_s 
{ 
  /** Identifier of the filter */ 
  uint8  filter; 
  /** Number of the required block */ 
  uint8  block_no; 
  /** Number of valid coefficients in this message */ 
  uint8  num_valid; 
  /** Reserved for future use. */ 
  uint8  rsvd1; 
  /** Coefficient data. */ 
  int32  coef_1; 
  /** Coefficient data. */ 
  int32  coef_2; 
  /** Coefficient data. */ 
  int32  coef_3; 
  /** Coefficient data. */ 
  int32  coef_4; 
  /** Coefficient data. */ 
  int32  coef_5; 
  /** Coefficient data. */ 
  int32  coef_6; 
  /** Coefficient data. */ 
  int32  coef_7; 
  /** Coefficient data. */ 
  int32  coef_8; 
  /** Coefficient data. */ 
  int32  coef_9; 
  /** Coefficient data. */ 
  int32  coef_10; 
  /** Coefficient data. */ 
  int32  coef_11; 
  /** Coefficient data. */ 
  int32  coef_12; 
  /** Coefficient data. */ 
  int32  coef_13; 
  /** Coefficient data. */ 
  int32  coef_14; 
  /** Coefficient data. */ 
  int32  coef_15; 
  /** Coefficient data. */ 
  int32  coef_16; 
} __PACKED__ ack_filt_coef_get_t; 


/** message: ACK_PMMS_SNRMARGIN_GET */

typedef struct ack_pmms_snrmargin_get_s 
{ 
  /** Silence Probe */ 
  int8  rsvd; 
  /** SNR Margin value */ 
  int8  SNR_192_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_256_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_320_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_384_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_448_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_512_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_576_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_640_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_704_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_768_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_832_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_896_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_960_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1024_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1088_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1152_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1216_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1280_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1344_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1408_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1472_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1536_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1600_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1664_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1728_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1792_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1856_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1920_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_1984_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_2048_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_2112_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_2176_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_2240_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_2304_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_RATE1_ASYM_MARGIN; 
  /** SNR Margin value */ 
  int8  SNR_RATE2_ASYM_MARGIN; 
} __PACKED__ ack_pmms_snrmargin_get_t; 


/** message: ACK_PMMS_EPL_GET */

typedef struct ack_pmms_epl_get_s 
{ 
  /** Silence Probe */ 
  int8  rsvd; 
  /** EPL value */ 
  int8  EPL_192; 
  /** EPL value */ 
  int8  EPL_256; 
  /** EPL value */ 
  int8  EPL_320; 
  /** EPL value */ 
  int8  EPL_384; 
  /** EPL value */ 
  int8  EPL_448; 
  /** EPL value */ 
  int8  EPL_512; 
  /** EPL value */ 
  int8  EPL_576; 
  /** EPL value */ 
  int8  EPL_640; 
  /** EPL value */ 
  int8  EPL_704; 
  /** EPL value */ 
  int8  EPL_768; 
  /** EPL value */ 
  int8  EPL_832; 
  /** EPL value */ 
  int8  EPL_896; 
  /** EPL value */ 
  int8  EPL_960; 
  /** EPL value */ 
  int8  EPL_1024; 
  /** EPL value */ 
  int8  EPL_1088; 
  /** EPL value */ 
  int8  EPL_1152; 
  /** EPL value */ 
  int8  EPL_1216; 
  /** EPL value */ 
  int8  EPL_1280; 
  /** EPL value */ 
  int8  EPL_1344; 
  /** EPL value */ 
  int8  EPL_1408; 
  /** EPL value */ 
  int8  EPL_1472; 
  /** EPL value */ 
  int8  EPL_1536; 
  /** EPL value */ 
  int8  EPL_1600; 
  /** EPL value */ 
  int8  EPL_1664; 
  /** EPL value */ 
  int8  EPL_1728; 
  /** EPL value */ 
  int8  EPL_1792; 
  /** EPL value */ 
  int8  EPL_1856; 
  /** EPL value */ 
  int8  EPL_1920; 
  /** EPL value */ 
  int8  EPL_1984; 
  /** EPL value */ 
  int8  EPL_2048; 
  /** EPL value */ 
  int8  EPL_2112; 
  /** EPL value */ 
  int8  EPL_2176; 
  /** EPL value */ 
  int8  EPL_2240; 
  /** EPL value */ 
  int8  EPL_2304; 
  /** EPL value */ 
  int8  EPL_Rate1_ASYM; 
  /** EPL value */ 
  int8  EPL_Rate2_ASYM; 
} __PACKED__ ack_pmms_epl_get_t; 

/*@}*/ /* Debug Indications */

typedef union SDFE4_u
{

 /** message: CMD_CFG_SYM_DSL_MODE */ 
 cmd_cfg_sym_dsl_mode_t  cmd_cfg_sym_dsl_mode_m;

 /** message: CMD_CFG_AFE_PARAMS */ 
 cmd_cfg_afe_params_t  cmd_cfg_afe_params_m;

 /** message: CMD_CFG_GHS_MODE */ 
 cmd_cfg_ghs_mode_t  cmd_cfg_ghs_mode_m;

 /** message: CMD_CFG_CAPLIST_SHORT */ 
 cmd_cfg_caplist_short_t  cmd_cfg_caplist_short_m;

 /** message: CMD_CFG_CAPLIST_SHORT_VER_2 */ 
 cmd_cfg_caplist_short_ver_2_t  cmd_cfg_caplist_short_ver_2_m;

 /** message: CMD_CFG_CAPLIST */ 
 cmd_cfg_caplist_t  cmd_cfg_caplist_m;

 /** message: CMD_CFG_GHS_NS_FIELD */ 
 cmd_cfg_ghs_ns_field_t  cmd_cfg_ghs_ns_field_m;

 /** message: CMD_GHS_CAP_GET */ 
 cmd_ghs_cap_get_t  cmd_ghs_cap_get_m;

 /** message: CMD_CFG_GHS_CAP */ 
 cmd_cfg_ghs_cap_t  cmd_cfg_ghs_cap_m;

 /** message: CMD_CFG_E1_ATM_OCTET_ALIGNED */ 
 cmd_cfg_e1_atm_octet_aligned_t  cmd_cfg_e1_atm_octet_aligned_m;

 /** message: CMD_CAPLIST_GET */ 
 cmd_caplist_get_t  cmd_caplist_get_m;

 /** message: CMD_CFG_EFM_DISCOVERY_DATA */ 
 cmd_cfg_efm_discovery_data_t  cmd_cfg_efm_discovery_data_m;

 /** message: CMD_EFM_DISCOVERY_DATA_GET */ 
 cmd_efm_discovery_data_get_t  cmd_efm_discovery_data_get_m;

 /** message: CMD_CFG_EFM_AGGREGATE_DATA */ 
 cmd_cfg_efm_aggregate_data_t  cmd_cfg_efm_aggregate_data_m;

 /** message: CMD_EFM_AGGREGATE_DATA_GET */ 
 cmd_efm_aggregate_data_get_t  cmd_efm_aggregate_data_get_m;

 /** message: CMD_EFM_START_ACTIVATION */ 
 cmd_efm_start_activation_t  cmd_efm_start_activation_m;

 /** message: CMD_CFG_DSL_PARAM */ 
 cmd_cfg_dsl_param_t  cmd_cfg_dsl_param_m;

 /** message: CMD_CONNECT_CTRL */ 
 cmd_connect_ctrl_t  cmd_connect_ctrl_m;

 /** message: CMD_CFG_PERF_PRIM */ 
 cmd_cfg_perf_prim_t  cmd_cfg_perf_prim_m;

 /** message: CMD_CFG_REQ_SHDSL */ 
 cmd_cfg_req_shdsl_t  cmd_cfg_req_shdsl_m;

 /** message: CMD_FBIT_TX */ 
 cmd_fbit_tx_t  cmd_fbit_tx_m;

 /** message: CMD_CFG_FBIT_RX */ 
 cmd_cfg_fbit_rx_t  cmd_cfg_fbit_rx_m;

 /** message: CMD_EOC_TX */ 
 cmd_eoc_tx_t  cmd_eoc_tx_m;

 /** message: CMD_CFG_EOC_RX */ 
 cmd_cfg_eoc_rx_t  cmd_cfg_eoc_rx_m;

 /** message: CMD_CFG_SDI_SETTINGS */ 
 cmd_cfg_sdi_settings_t  cmd_cfg_sdi_settings_m;

 /** message: CMD_CFG_SDI_SET_EXTENDED */ 
 cmd_cfg_sdi_set_extended_t  cmd_cfg_sdi_set_extended_m;

 /** message: CMD_CFG_SDI_TX */ 
 cmd_cfg_sdi_tx_t  cmd_cfg_sdi_tx_m;

 /** message: CMD_CFG_SDI_RX */ 
 cmd_cfg_sdi_rx_t  cmd_cfg_sdi_rx_m;

 /** message: CMD_CFG_SDI_DLY */ 
 cmd_cfg_sdi_dly_t  cmd_cfg_sdi_dly_m;

 /** message: CMD_CFG_SDI_IL_CHANNELS_TX */ 
 cmd_cfg_sdi_il_channels_tx_t  cmd_cfg_sdi_il_channels_tx_m;

 /** message: CMD_CFG_SDI_IL_CHANNELS_RX */ 
 cmd_cfg_sdi_il_channels_rx_t  cmd_cfg_sdi_il_channels_rx_m;

 /** message: CMD_CFG_SDI_FRAMER_TX */ 
 cmd_cfg_sdi_framer_tx_t  cmd_cfg_sdi_framer_tx_m;

 /** message: CMD_CFG_SDI_FRAMER_RX */ 
 cmd_cfg_sdi_framer_rx_t  cmd_cfg_sdi_framer_rx_m;

 /** message: CMD_CFG_MULTIWIRE_MASTER */ 
 cmd_cfg_multiwire_master_t  cmd_cfg_multiwire_master_m;

 /** message: CMD_CFG_MULTIWIRE_SLAVE */ 
 cmd_cfg_multiwire_slave_t  cmd_cfg_multiwire_slave_m;

 /** message: CMD_CFG_MULTIWIRE_PMMS_PAR */ 
 cmd_cfg_multiwire_pmms_par_t  cmd_cfg_multiwire_pmms_par_m;

 /** message: CMD_MULTIWIRE_MDATA_GET */ 
 cmd_multiwire_mdata_get_t  cmd_multiwire_mdata_get_m;

 /** message: CMD_MULTIWIRE_SDATA_GET */ 
 cmd_multiwire_sdata_get_t  cmd_multiwire_sdata_get_m;

 /** message: CMD_CFG_MULTIWIRE_OPERATION */ 
 cmd_cfg_multiwire_operation_t  cmd_cfg_multiwire_operation_m;

 /** message: CMD_GHS_REG_INITIATION */ 
 cmd_ghs_reg_initiation_t  cmd_ghs_reg_initiation_m;

 /** message: CMD_GHS_REG_DIAG_MODE */ 
 cmd_ghs_reg_diag_mode_t  cmd_ghs_reg_diag_mode_m;

 /** message: NFC_CONNECT_CTRL */ 
 nfc_connect_ctrl_t  nfc_connect_ctrl_m;

 /** message: NFC_CONNECT_CONDITION */ 
 nfc_connect_condition_t  nfc_connect_condition_m;

 /** message: NFC_MPAIR_DELAY_MEASURE_SDFE4 */ 
 nfc_mpair_delay_measure_sdfe4_t  nfc_mpair_delay_measure_sdfe4_m;

 /** message: NFC_PERF_PRIM */ 
 nfc_perf_prim_t  nfc_perf_prim_m;

 /** message: NFC_FBIT_RX */ 
 nfc_fbit_rx_t  nfc_fbit_rx_m;

 /** message: NFC_EOC_TX */ 
 nfc_eoc_tx_t  nfc_eoc_tx_m;

 /** message: NFC_EOC_RX */ 
 nfc_eoc_rx_t  nfc_eoc_rx_m;

 /** message: NFC_UNDEF_MSG_ID */ 
 nfc_undef_msg_id_t  nfc_undef_msg_id_m;

 /** message: NFC_MULTIWIRE_MASTER */ 
 nfc_multiwire_master_t  nfc_multiwire_master_m;

 /** message: NFC_MULTIWIRE_PAIR_NR */ 
 nfc_multiwire_pair_nr_t  nfc_multiwire_pair_nr_m;

 /** message: ACK_PMMS_RESULTS_GET */ 
 ack_pmms_results_get_t  ack_pmms_results_get_m;

 /** message: ACK_GHS_NS_FIELD_GET */ 
 ack_ghs_ns_field_get_t  ack_ghs_ns_field_get_m;

 /** message: ACK_GHS_CAP_GET */ 
 ack_ghs_cap_get_t  ack_ghs_cap_get_m;

 /** message: ACK_CFG_GHS_CAP */ 
 ack_cfg_ghs_cap_t  ack_cfg_ghs_cap_m;

 /** message: ACK_CONNECT_CTRL */ 
 ack_connect_ctrl_t  ack_connect_ctrl_m;

 /** message: ACK_CONNECT_STAT_GET */ 
 ack_connect_stat_get_t  ack_connect_stat_get_m;

 /** message: ACK_DSL_PARAM_GET */ 
 ack_dsl_param_get_t  ack_dsl_param_get_m;

 /** message: ACK_CAPLIST_GET */ 
 ack_caplist_get_t  ack_caplist_get_m;

 /** message: ACK_CFG_EFM_DISCOVERY_DATA */ 
 ack_cfg_efm_discovery_data_t  ack_cfg_efm_discovery_data_m;

 /** message: ACK_EFM_DISCOVERY_DATA_GET */ 
 ack_efm_discovery_data_get_t  ack_efm_discovery_data_get_m;

 /** message: NFC_EFM_DISCOVERY_OP_RDY */ 
 nfc_efm_discovery_op_rdy_t  nfc_efm_discovery_op_rdy_m;

 /** message: ACK_CFG_EFM_AGGREGATE_DATA */ 
 ack_cfg_efm_aggregate_data_t  ack_cfg_efm_aggregate_data_m;

 /** message: ACK_EFM_AGGREGATE_DATA_GET */ 
 ack_efm_aggregate_data_get_t  ack_efm_aggregate_data_get_m;

 /** message: NFC_EFM_AGGREGATE_OP_RDY */ 
 nfc_efm_aggregate_op_rdy_t  nfc_efm_aggregate_op_rdy_m;

 /** message: ACK_EFM_START_ACTIVATION */ 
 ack_efm_start_activation_t  ack_efm_start_activation_m;

 /** message: ACK_ID_GET */ 
 ack_id_get_t  ack_id_get_m;

 /** message: ACK_FEATURE_STR_GET */ 
 ack_feature_str_get_t  ack_feature_str_get_m;

 /** message: ACK_MSG_STAT_GET */ 
 ack_msg_stat_get_t  ack_msg_stat_get_m;

 /** message: ACK_CFG_PERF_PRIM */ 
 ack_cfg_perf_prim_t  ack_cfg_perf_prim_m;

 /** message: ACK_PERF_PRIM_GET */ 
 ack_perf_prim_get_t  ack_perf_prim_get_m;

 /** message: ACK_PERF_STATUS_GET */ 
 ack_perf_status_get_t  ack_perf_status_get_m;

 /** message: ACK_PERF_DETAILS_GET */ 
 ack_perf_details_get_t  ack_perf_details_get_m;

 /** message: ACK_FBIT_RX_GET */ 
 ack_fbit_rx_get_t  ack_fbit_rx_get_m;

 /** message: ACK_EOC_TX */ 
 ack_eoc_tx_t  ack_eoc_tx_m;

 /** message: ACK_MULTIWIRE_PMMS_RESULT_GET */ 
 ack_multiwire_pmms_result_get_t  ack_multiwire_pmms_result_get_m;

 /** message: ACK_MULTIWIRE_MDATA_GET */ 
 ack_multiwire_mdata_get_t  ack_multiwire_mdata_get_m;

 /** message: ACK_MULTIWIRE_SDATA_GET */ 
 ack_multiwire_sdata_get_t  ack_multiwire_sdata_get_m;

 /** message: CMD_FILT_COEF_PRINTF */ 
 cmd_filt_coef_printf_t  cmd_filt_coef_printf_m;

 /** message: CMD_FILT_COEF_GET */ 
 cmd_filt_coef_get_t  cmd_filt_coef_get_m;

 /** message: CMD_SET_PDI_REG */ 
 cmd_set_pdi_reg_t  cmd_set_pdi_reg_m;

 /** message: CMD_PDI_REG_GET */ 
 cmd_pdi_reg_get_t  cmd_pdi_reg_get_m;

 /** message: CMD_SET_DBG_PROBE */ 
 cmd_set_dbg_probe_t  cmd_set_dbg_probe_m;

 /** message: CMD_CFG_PARAM_VECTOR */ 
 cmd_cfg_param_vector_t  cmd_cfg_param_vector_m;

 /** message: CMD_TDR_DATA_GET */ 
 cmd_tdr_data_get_t  cmd_tdr_data_get_m;

 /** message: ACK_PDI_REG_GET */ 
 ack_pdi_reg_get_t  ack_pdi_reg_get_m;

 /** message: NFC_PRINTF */ 
 nfc_printf_t  nfc_printf_m;

 /** message: ACK_BERT_COUNT_GET */ 
 ack_bert_count_get_t  ack_bert_count_get_m;

 /** message: ACK_FINGERPRINT_GET */ 
 ack_fingerprint_get_t  ack_fingerprint_get_m;

 /** message: ACK_PARAM_VECTOR_GET */ 
 ack_param_vector_get_t  ack_param_vector_get_m;

 /** message: ACK_TDR_DATA_GET */ 
 ack_tdr_data_get_t  ack_tdr_data_get_m;

 /** message: ACK_FILT_COEF_GET */ 
 ack_filt_coef_get_t  ack_filt_coef_get_m;

 /** message: ACK_PMMS_SNRMARGIN_GET */ 
 ack_pmms_snrmargin_get_t  ack_pmms_snrmargin_get_m;

 /** message: ACK_PMMS_EPL_GET */ 
 ack_pmms_epl_get_t  ack_pmms_epl_get_m;
} __PACKED__ SDFE4_t; 
#endif

/*@}*/ /* SDFE4 */

