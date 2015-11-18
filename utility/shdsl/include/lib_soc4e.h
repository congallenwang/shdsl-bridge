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

#ifndef _lib_soc4e_h
#define _lib_soc4e_h

/** interface and types from the upper layer interfaces. */
#include "user_if_SOC4BIS.h"
#include "user_if_SOC4BIS_AUX.h"



/** Possible global states of the lib */
typedef enum
{
   SOC4E_STATE_DOWN,
   SOC4E_STATE_INIT,
   SOC4E_STATE_REPEATER,
   SOC4E_STATE_TERMINAL
} E_SOC4E_GLOBAL_STATE;

/** elements for configuration arrays (PAMDSL) */
typedef struct soc4e_config_entry_pamdsl  soc4e_config_entry_pamdsl_t;
struct soc4e_config_entry_pamdsl
{
   UINT8 idc;       
   UINT8 idx;
   UINT16 msg_id;
   VOID const * msg_data;
   UINT16 msg_len;
};

/** elements for configuration arrays (AUX) */
typedef struct soc4e_config_entry_aux  soc4e_config_entry_aux_t;
struct soc4e_config_entry_aux
{
   UINT8 aux_reg;
   UINT8 aux_val;
};

typedef struct config_description   config_description_t;
struct config_description
{
   E_BOARD_CFG_TYPE board_cfg;
   soc4e_config_entry_pamdsl_t const * cfg_pamdsl;
   UINT16  size_pamdsl;
   soc4e_config_entry_aux_t const * cfg_aux;
   UINT16 size_aux;
};

/* do cfg include here, after types for config entries are defined!!! */
#include "cfg_soc4e.h"

#define MAKE_CONFIG_DESC(prefix,board_cfg)                  \
   {                                                        \
      board_cfg,                                            \
      SOC4E_CFG_PREFIXED_NAME1(prefix,pamdsl_msg),          \
      sizeof(SOC4E_CFG_PREFIXED_NAME1(prefix,pamdsl_msg)),  \
      SOC4E_CFG_PREFIXED_NAME1(prefix,aux_msg),             \
      sizeof(SOC4E_CFG_PREFIXED_NAME1(prefix,aux_msg))      \
   }

typedef enum
{
   e_REP_INIT,
   e_REP_IDLE,
   e_REP_STU_R_CAP_AVAIL_CHIP,
   e_REP_STU_R_CAP_REQESTED,
   e_REP_STU_C_CAP_WRITTEN,
   e_REP_STU_C_CAP_REQESTED,
   e_REP_STU_R_CAP_WRITTEN,
   e_REP_STU_C_GHS_INIT,
   e_REP_ACTIVE,
   e_REP_RESTART
} E_SOC4E_REPEATER_STATE;


typedef enum
{
   e_DELAY_MEASURE_IDLE,
   e_DELAY_MEASURE_DATA_REACHED,
   e_DELAY_MEASURE_FIRST_SYNC,
   e_DELAY_MEASURE_RSFSC_ALIGN_SENT,
   e_DELAY_MEASURE_SECND_SYNC,
   e_DELAY_MEASURE_RUNNING,
   e_DELAY_MEASURE_COMPLETE
} E_SOC4E_DELAY_MEASURE_STATE;


typedef struct
{
   UINT8 uc_caplist_type;            /**< 1 */
   UINT8 uc_Type;                    /**< 2 - message type field */
   UINT8 uc_CmdByte2;                /**< 3 - Second CmdByte */
   UINT8 uc_STUMode;                 /**< 4 - STU mode: STU-R or STU-C */
   UINT8 uc_Repeater;                /**< 5 - STU or SRU */
   UINT8 uc_Rev;                     /**< 6 - revision number field */

   /* ==== Vendor ID field (8 bytes) ==== */
   UINT8 uc_Country1;                /**< 7 - T.35 country code (2 octets) */
   UINT8 uc_Country2;                /**< 8 - T.35 country code (2 octets) */
   UINT8 uc_Provider1;               /**< 9 - provider code (Vendor ID, 4 octets) */
   UINT8 uc_Provider2;               /**< 10 - provider code (Vendor ID, 4 octets) */
   UINT8 uc_Provider3;               /**< 11 - provider code (Vendor ID, 4 octets) */
   UINT8 uc_Provider4;               /**< 12 - provider code (Vendor ID, 4 octets) */
   UINT8 uc_VendorInfo1;             /**< 13 - vendor specific information (2 octets) */
   UINT8 uc_VendorInfo2;             /**< 14 - vendor specific information (2 octets) */

   /* ==== Parameter field ==== */

   UINT8 uc_ID_NPar1;                /**< 15 - Non-Standard field */
   UINT8 uc_ID_SPar1;                /**< 16 - Parameter to select ID_NPar2 */
   /* for new standard: */
   UINT8 uc_ID_SPar1_2;              /**< 17 - Parameter to select ID_NPar2 */
   UINT8 uc_ID_SPar1_3;              /**< 18 - Parameter to select ID_NPar2 */

   /* ---- Npar2 (10 bytes) ---- */
   UINT8 uc_UpMaxNDR;                /**< 19 - maximum net data rate upstream */
   UINT8 uc_UpMinNDR;                /**< 20 - minimum net data rate upstream */
   UINT8 uc_UpAvgNDR;                /**< 21 - average net data rate upstream */

   UINT8 uc_DnMaxNDR;                /**< 22 - maximum net data rate downstream */
   UINT8 uc_DnMinNDR;                /**< 23 - minimum net data rate downstream */
   UINT8 uc_DnAvgNDR;                /**< 24 - average net data rate downstream */

   UINT8 uc_UpMaxLat;                /**< 25 - maximum latency upstream (units given by formula in Table 16 of G.hs) */
   UINT8 uc_UpAvgLat;                /**< 26 - average latency upstream (units given by formula in Table 17 of G.hs) */

   UINT8 uc_DnMaxLat;                /**< 27 - maximum latency downstream (units given by formula in Table 18 of G.hs) */
   UINT8 uc_DnAvgLat;                /**< 28 - average latency downstream  (units given by formula in Table 19 of G.hs) */

   /* for new standard: */
   UINT8 uc_Power_CarrierUp;         /**< 29 - up Attenuation transmit power per carrier */
   UINT8 uc_Power_CarrierDn;         /**< 30 - dn Attenuation transmit power per carrier */


   /* ==== Standard Information Field ==== */
   /* ==================================================== */

   /* --- NPAR1/SPAR1 (3 bytes) --- */
   UINT8 uc_SI_NPar1;                /**< 31 - needs to be set in a CL or CLR message */
   UINT8 uc_SI_SPar1_1;              /**< 32 - G.992.x Annex X */
   UINT8 uc_SI_SPar1_2;              /**< 33 - G.991.2 Annex A,B */

   /* --- NPAR2/SPAR2 (3 bytes) --- */
   UINT8 uc_SI_NPar2;                /**< 34 - Training, Line Probing or Reg_Silent */
   UINT8 uc_SI_SPar2_1;              /**< 35 - Parameter to select SI_NPar3 */
   UINT8 uc_SI_SPar2_2;              /**< 36 - DN/UP Train, DN/UP Line Probe, TPS-TC or DN Frame Para */
   /* UP Frame Para */
   /* ---- NPar3 ----  */
   /* Training  downstream (10 bytes) */
   UINT8 uc_T_PboDn;                 /**< 37 - 0 dB   - 31 dB */
   UINT8 uc_T_BRateDn1;              /**< 38 - 192  -  256 kbit/s */
   UINT8 uc_T_BRateDn2;              /**< 39 - 320  -  640 kbit/s */
   UINT8 uc_T_BRateDn3;              /**< 40 - 704  - 1024 kbit/s */
   UINT8 uc_T_BRateDn4;              /**< 41 - 1088 - 1408 kbit/s */
   UINT8 uc_T_BRateDn5;              /**< 42 - 1472 - 1792 kbit/s */
   UINT8 uc_T_BRateDn6;              /**< 43 - 1856 - 2176 kbit/s */
   UINT8 uc_T_BRateDn7;              /**< 44 - 2240 - 2304 kbit/s */
   UINT8 uc_T_SRateDn1;              /**< 45 -    0 - 40 kbit/s */
   UINT8 uc_T_SRateDn2;              /**< 46 -   48 - 56 kbit/s */

   /* Training  upstream (10 bytes) */
   UINT8 uc_T_PboUp;                 /**< 47 - 0 dB   - 31 dB */
   UINT8 uc_T_BRateUp1;              /**< 48 - 192  -  256 kbit/s */
   UINT8 uc_T_BRateUp2;              /**< 49 - 320  -  640 kbit/s */
   UINT8 uc_T_BRateUp3;              /**< 50 - 704  - 1024 kbit/s */
   UINT8 uc_T_BRateUp4;              /**< 51 - 1088 - 1408 kbit/s */
   UINT8 uc_T_BRateUp5;              /**< 52 - 1472 - 1792 kbit/s */
   UINT8 uc_T_BRateUp6;              /**< 53 - 1856 - 2176 kbit/s */
   UINT8 uc_T_BRateUp7;              /**< 54 - 2240 - 2304 kbit/s */
   UINT8 uc_T_SRateUp1;              /**< 55 -    0 - 40 kbit/s */
   UINT8 uc_T_SRateUp2;              /**< 56 -   48 - 56 kbit/s */

   /* Line Probing downstream (12 bytes) */
   UINT8 uc_PboDn;                   /**< 57 - 0 dB   - 31 dB */
   UINT8 uc_BRateDn1;                /**< 58 - 192  -  256 kbit/s */
   UINT8 uc_BRateDn2;                /**< 59 - 320  -  640 kbit/s */
   UINT8 uc_BRateDn3;                /**< 60 - 704  - 1024 kbit/s */
   UINT8 uc_BRateDn4;                /**< 61 - 1088 - 1408 kbit/s */
   UINT8 uc_BRateDn5;                /**< 62 - 1472 - 1792 kbit/s */
   UINT8 uc_BRateDn6;                /**< 63 - 1856 - 2176 kbit/s */
   UINT8 uc_BRateDn7;                /**< 64 - 2240 - 2304 kbit/s */
   UINT8 uc_FixVDn1;                 /**< 65 - constant value  */
   UINT8 uc_FixVDn2;                 /**< 66 - constant value */
   UINT8 uc_DuratDn;                 /**< 67 - 50ms - 3.1sec */
   UINT8 uc_ScrambDn;                /**< 68 - 6 different types */
   /* for new standard: */
   UINT8 uc_wcMarginDn;              /**< 69 - Worst-case target margin */
   UINT8 uc_CcMarginDn;              /**< 70 - Current-condition target margin */

   /* Line Probing upstream (12 bytes) */
   UINT8 uc_PboUp;                   /**< 71 - 0 dB   - 31 dB */
   UINT8 uc_BRateUp1;                /**< 72 - 192  -  256 kbit/s */
   UINT8 uc_BRateUp2;                /**< 73 - 320  -  640 kbit/s */
   UINT8 uc_BRateUp3;                /**< 74 - 704  - 1024 kbit/s */
   UINT8 uc_BRateUp4;                /**< 75 - 1088 - 1408 kbit/s */
   UINT8 uc_BRateUp5;                /**< 76 - 1472 - 1792 kbit/s */
   UINT8 uc_BRateUp6;                /**< 77 - 1856 - 2176 kbit/s */
   UINT8 uc_BRateUp7;                /**< 78 - 2240 - 2304 kbit/s */
   UINT8 uc_FixVUp1;                 /**< 79 - constant value */
   UINT8 uc_FixVUp2;                 /**< 80 - constant value */
   UINT8 uc_DuratUp;                 /**< 81 - 50ms - 3.1sec */
   UINT8 uc_ScrambUp;                /**< 82 - 6 different types */
   /* for new standard: */
   UINT8 uc_wcMarginUp;              /**< 83 - Worst-case PMMS target margin */
   UINT8 uc_CcMarginUp;              /**< 84 - Current-condition PMMS target margin */

   /* Framing Parameter downstrem (3 Octets) */
   UINT8 uc_StuffBit_Dn;             /**< 85 - Stuff bits and Sync word (bits 14 and 13) */
   UINT8 uc_SyncOc1_Dn;              /**< 86 - Sync word (bits 12 and 7) */
   UINT8 uc_SyncOc2_Dn;              /**< 87 - Sync word (bits 6 and 1) */

   /* Framing Parameter upstrem (3 Octets) */
   UINT8 uc_StuffBit_Up;             /**< 88 - Stuff bits and Sync word (bits 14 and 13) */
   UINT8 uc_SyncOc1_Up;              /**< 89 - Sync word (bits 12 and 7) */
   UINT8 uc_SyncOc2_Up;              /**< 90 - Sync word (bits 6 and 1) */

   /* --- Annex A --- */
   /* TPS-TC Parameter (2 Octets) */
   UINT8 uc_TpsClock;                /**< 91 - Clock Mode1, 2 and 3a */
   UINT8 uc_TpsChannel;              /**< 92 - unaligned D2048S and clear channel byte orien */
   UINT8 uc_TpsISDN;                 /**< 93 - number and Z-bits of ISDN BRA */

   /* Dual Mode TPS-TC Parameter */
   UINT8 uc_DualTps1;                /**< 94 - */
   UINT8 uc_DualTps2;                /**< 95 - */
   UINT8 uc_DualTps3;                /**< 96 - */
   UINT8 uc_DualTps4;                /**< 97 - */
   UINT8 uc_DualTps5;                /**< 98 - */
   UINT8 uc_DualTps6;                /**< 99 - */

   /* --- Annex B --- */
   /* TPS-TC Parameter (2 Octets) */
   UINT8 uc_TpsClock_B;              /**< 100 - Clock Mode1, 2 and 3a */
   UINT8 uc_TpsChannel1_B;           /**< 101 - Clear Channel, - byte orien, unaligned D2048S, etc. */
   UINT8 uc_TpsChannel2_B;           /**< 102 - SynchronousISDN-BRA */
   UINT8 uc_TpsISDN_B;               /**< 103 - number and Z-bits of ISDN BRA */

   /* Dual Mode TPS-TC Parameter */
   UINT8 uc_DualTps1_B;              /**< 104 - */
   UINT8 uc_DualTps2_B;              /**< 105 - */
   UINT8 uc_DualTps3_B;              /**< 106 - */
   UINT8 uc_DualTps4_B;              /**< 107 - */
   UINT8 uc_DualTps5_B;              /**< 108 - */
   UINT8 uc_DualTps6_B;              /**< 109 - */

} __PACKED__ soc4e_caplist_t;

/* an union for caplist (easier to debug caplist problems!) */
typedef union
{
   soc4e_caplist_t cl_sym;
   UINT8 cl_bytes[120];
} soc4e_caplist_u;

typedef struct soc4e_reg_cfg_ch soc4e_reg_cfg_ch_t;
struct soc4e_reg_cfg_ch
{
   /** channel number of SRU C */
   UINT8 sru_c_ch;
   /** channel number of SRU R */
   UINT8 sru_r_ch;
};

typedef struct soc4e_channel_status soc4e_channel_status_t;
struct soc4e_channel_status
{
   /** for STC-C/R dependent operations (will be read from config) */
   UINT8 stu_mode;

/* from xxx_CONNECT_CTRL */
   /** line state */
   INT8 main_state;
   BOOL main_state_changed;

/* from ACK_DSL_PARAM_GET */
   /** Payload Base Rate */
   UINT16 base_rate;
   /** Payload Sub Rate */
   UINT8 sub_rate;
#if 0
   /** Annex */
   UINT8 annex;
   /** Clocking Mode */
   UINT8 clk_ref;
   /** Power Spectral Density Mask */
   UINT8 psd_mask;
   /** SHDSL Framing Mode */
   UINT8 frame_mode;
#endif

/** mpair infos */
   /** "pointer" to the master channel, a value 0xFF means "not a mpair member" */
   UINT8 master;
   E_SOC4E_DELAY_MEASURE_STATE dly_measure_state;
   UINT8 mpair_delay_value;

/** flag to see if we need to restart a channel (in case of an error) */
#if INCLUDE_TERMINAL == 1
   BOOL  need_channel_restart;
   UINT32   restart_time;
#endif /* INCLUDE_TERMINAL == 1 */

/* for repeater mode */
#if INCLUDE_REPEATER == 1
   UINT8                   ghs_state;
   BOOL                    ghs_state_changed;

   /* repeater connection number */
   UINT8                   rep_nr;

   soc4e_caplist_u         rep_caplist;
   BOOL                    rep_caplist_fresh_data;
   UINT8                   reg_counterpart;
#endif
#if (INCLUDE_REPEATER == 1) || (INCLUDE_EOC_HANDLING == 1)
   cmd_eoc_tx_t            eoc_buffer;
   BOOL                    eoc_rx_fresh_data;
   INT8                    eoc_tx_status;
#endif
};

typedef struct soc4e_rep_status soc4e_rep_status_t;
struct soc4e_rep_status
{
   E_SOC4E_REPEATER_STATE state;

   UINT32 timestamp;
   BOOL time_running;
};

/* macro table for list of config parameters */
/* format: name, name string, maximum value, help description string, enum */
#define SOC4E_CFG_PARAM                \
   gen_cfg_param_list_entry(base_rate_min,"Base Rate Min",  2304, \
      "(192-2304 in steps of 64)",  e_PARAM_BASE_MIN, SEPARATOR)  \
   gen_cfg_param_list_entry(base_rate_max,"Base Rate Max",  2304, \
      "(192-2304 in steps of 64)",  e_PARAM_BASE_MAX, SEPARATOR)  \
   gen_cfg_param_list_entry(sub_rate_min, "Sub Rate Min",   56,   \
      "(0-56 in steps of 8)",       e_PARAM_SUB_MIN,  SEPARATOR)  \
   gen_cfg_param_list_entry(sub_rate_max, "Sub Rate Max",   56,   \
      "(0-56 in steps of 8)",       e_PARAM_SUB_MAX,  SEPARATOR)  \
   gen_cfg_param_list_entry(annex,        "Annex       ",    3,   \
      "(1 A, 2 B, 3 AB)",           e_PARAM_ANNEX,    SEPARATOR)  \
   gen_cfg_param_list_entry(line_probing, "Line Probing",   1,    \
      "(0 off, 1 on)",              e_PARAM_LP,       NO_SEPARATOR)

#define e_PARAM_LAST    e_PARAM_LP

/* prepare the macro table expansion for enum */
#undef gen_cfg_param_list_entry
#define gen_cfg_param_list_entry(a,b,c,d,e,sep) e sep
/* separator for enum is ',' */
#undef  SEPARATOR
#define SEPARATOR ,
/* specify no separator for the last table entry */
#undef  NO_SEPARATOR
#define NO_SEPARATOR

typedef enum
{
   SOC4E_CFG_PARAM
} E_CFG_PARAM;

/* prepare the macro table expansion for struct */
#undef gen_cfg_param_list_entry
#define gen_cfg_param_list_entry(a,b,c,d,e,sep) UINT16 a sep
/* separator for struct is ';' */
#undef  SEPARATOR
#define SEPARATOR ;
/* specify ; for the last table entry */
#undef  NO_SEPARATOR
#define NO_SEPARATOR ;

typedef struct soc4e_cfg_params soc4e_cfg_params_t;
struct soc4e_cfg_params
{
   SOC4E_CFG_PARAM
};

extern char* soc4e_config_names[];

extern soc4e_cfg_params_t soc4e_cfg_params;

extern BOOL use_custom_line_params;
extern ack_perf_status_get_t soc4e_perf_cntr[PEF24628E_MAX_LINE_NUMBER];

/* external functions */

/* from lib_soc4e.c */
extern BOOL soc4e_lib_init(const BOARD_Configuration_t *pDeviceConfiguration);
extern BOOL soc4e_lib_poll(const BOARD_Configuration_t *pDeviceConfiguration);
extern BOOL soc4e_decode_upstream(UINT8 ch, UINT16 msg_id, SDFE4_t * pMsg, UINT16 nLength);
extern VOID soc4e_lib_change_state(E_SOC4E_GLOBAL_STATE new_state);
extern VOID soc4e_lib_set_next_config(E_CFG_TYPE new_config);
extern E_CFG_TYPE soc4e_lib_get_current_config(VOID);
extern VOID soc4e_lib_send_perf_status_get(UINT8 ch);
extern VOID soc4e_lib_get_fw_info(VOID);
extern soc4e_channel_status_t const * soc4e_lib_get_channel_status(UINT8 ch);
extern ack_perf_status_get_t const * soc4e_lib_get_perf (UINT8 ch);

#endif /* _lib_soc4e_h */

