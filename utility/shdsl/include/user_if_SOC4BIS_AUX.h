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

#ifndef _SDFE4_AUX_128_H
#define _SDFE4_AUX_128_H

#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#define __PACKED__ __attribute__ ((packed))
#elif !defined (__PACKED__)
#define __PACKED__ /* nothing */
#endif



/** \addtogroup SDFE4_AUX SDFE4_AUX */

/*@{*/


/** \addtogroup SDFE4_AUX_Common_Messages Common Messages */

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


/* message identifiers */


 #define  ACK_RD_REG_AUX  0x0001 
 #define  ACK_WR_REG_AUX  0x0002 
 #define  CMD_RD_REG_AUX_AUX_I_0  0x0000 
 #define  CMD_WR_REG_AUX_AUX_O_0  0x0009 
 #define  CMD_RD_REG_AUX_AUX_O_0  0x0008 
 #define  CMD_WR_REG_AUX_AUX_ENQ_0  0x0011 
 #define  CMD_RD_REG_AUX_AUX_ENQ_0  0x0010 
 #define  CMD_RD_REG_AUX_AUX_I_1  0x0018 
 #define  CMD_WR_REG_AUX_AUX_O_1  0x0021 
 #define  CMD_RD_REG_AUX_AUX_O_1  0x0020 
 #define  CMD_WR_REG_AUX_AUX_ENQ_1  0x0029 
 #define  CMD_RD_REG_AUX_AUX_ENQ_1  0x0028 
 #define  CMD_RD_REG_AUX_AUX_I_2  0x0030 
 #define  CMD_WR_REG_AUX_AUX_O_2  0x0039 
 #define  CMD_RD_REG_AUX_AUX_O_2  0x0038 
 #define  CMD_WR_REG_AUX_AUX_ENQ_2  0x0041 
 #define  CMD_RD_REG_AUX_AUX_ENQ_2  0x0040 
 #define  CMD_RD_REG_AUX_AUX_I_3  0x0048 
 #define  CMD_WR_REG_AUX_AUX_O_3  0x0051 
 #define  CMD_RD_REG_AUX_AUX_O_3  0x0050 
 #define  CMD_WR_REG_AUX_AUX_ENQ_3  0x0059 
 #define  CMD_RD_REG_AUX_AUX_ENQ_3  0x0058 
 #define  CMD_WR_REG_AUX_MUX10_LOW_SEL  0x0061 
 #define  CMD_RD_REG_AUX_MUX10_LOW_SEL  0x0060 
 #define  CMD_WR_REG_AUX_MUX10_HIGH_SEL  0x0069 
 #define  CMD_RD_REG_AUX_MUX10_HIGH_SEL  0x0068 
 #define  CMD_WR_REG_AUX_MUX4_LOW_SEL  0x0071 
 #define  CMD_RD_REG_AUX_MUX4_LOW_SEL  0x0070 
 #define  CMD_WR_REG_AUX_MUX4_HIGH_SEL  0x0079 
 #define  CMD_RD_REG_AUX_MUX4_HIGH_SEL  0x0078 
 #define  CMD_WR_REG_AUX_AUX_IF_MODE  0x0081 
 #define  CMD_RD_REG_AUX_AUX_IF_MODE  0x0080 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_0  0x0089 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_0  0x0088 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_1  0x0091 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_1  0x0090 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_2  0x0099 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_2  0x0098 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_3  0x00A1 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_3  0x00A0 
 #define  CMD_WR_REG_AUX_SCI_IF_MODE  0x00A9 
 #define  CMD_RD_REG_AUX_SCI_IF_MODE  0x00A8 
 #define  CMD_RD_REG_AUX_DEV_ID  0x00B0 
 #define  CMD_WR_REG_AUX_DEV_ADDR  0x00B9 
 #define  CMD_RD_REG_AUX_DEV_ADDR  0x00B8 
 #define  CMD_WR_REG_AUX_DUMMY  0x00C1 
 #define  CMD_RD_REG_AUX_DUMMY  0x00C0 
 #define  CMD_WR_REG_AUX_TEMP_IN  0x00C9 
 #define  CMD_RD_REG_AUX_TEMP_IN  0x00C8 
 #define  CMD_RD_REG_AUX_TEMP_PUT  0x00D0 
 #define  CMD_WR_REG_AUX_PD2DBG_SEL  0x00D9 
 #define  CMD_RD_REG_AUX_PD2DBG_SEL  0x00D8 
 #define  CMD_WR_REG_AUX_PRT_0_DBG  0x00E1 
 #define  CMD_RD_REG_AUX_PRT_0_DBG  0x00E0 
 #define  CMD_WR_REG_AUX_PRT_1_DBG  0x00E9 
 #define  CMD_RD_REG_AUX_PRT_1_DBG  0x00E8 
 #define  CMD_WR_REG_AUX_PRT_2_DBG  0x00F1 
 #define  CMD_RD_REG_AUX_PRT_2_DBG  0x00F0 
 #define  CMD_WR_REG_AUX_PRT_3_DBG  0x00F9 
 #define  CMD_RD_REG_AUX_PRT_3_DBG  0x00F8 
 #define  ACK_RD_REG_AUX_S  "ACK_RD_REG_AUX" 
 #define  ACK_WR_REG_AUX_S  "ACK_WR_REG_AUX" 
 #define  CMD_RD_REG_AUX_AUX_I_0_S  "CMD_RD_REG_AUX_AUX_I_0" 
 #define  CMD_WR_REG_AUX_AUX_O_0_S  "CMD_WR_REG_AUX_AUX_O_0" 
 #define  CMD_RD_REG_AUX_AUX_O_0_S  "CMD_RD_REG_AUX_AUX_O_0" 
 #define  CMD_WR_REG_AUX_AUX_ENQ_0_S  "CMD_WR_REG_AUX_AUX_ENQ_0" 
 #define  CMD_RD_REG_AUX_AUX_ENQ_0_S  "CMD_RD_REG_AUX_AUX_ENQ_0" 
 #define  CMD_RD_REG_AUX_AUX_I_1_S  "CMD_RD_REG_AUX_AUX_I_1" 
 #define  CMD_WR_REG_AUX_AUX_O_1_S  "CMD_WR_REG_AUX_AUX_O_1" 
 #define  CMD_RD_REG_AUX_AUX_O_1_S  "CMD_RD_REG_AUX_AUX_O_1" 
 #define  CMD_WR_REG_AUX_AUX_ENQ_1_S  "CMD_WR_REG_AUX_AUX_ENQ_1" 
 #define  CMD_RD_REG_AUX_AUX_ENQ_1_S  "CMD_RD_REG_AUX_AUX_ENQ_1" 
 #define  CMD_RD_REG_AUX_AUX_I_2_S  "CMD_RD_REG_AUX_AUX_I_2" 
 #define  CMD_WR_REG_AUX_AUX_O_2_S  "CMD_WR_REG_AUX_AUX_O_2" 
 #define  CMD_RD_REG_AUX_AUX_O_2_S  "CMD_RD_REG_AUX_AUX_O_2" 
 #define  CMD_WR_REG_AUX_AUX_ENQ_2_S  "CMD_WR_REG_AUX_AUX_ENQ_2" 
 #define  CMD_RD_REG_AUX_AUX_ENQ_2_S  "CMD_RD_REG_AUX_AUX_ENQ_2" 
 #define  CMD_RD_REG_AUX_AUX_I_3_S  "CMD_RD_REG_AUX_AUX_I_3" 
 #define  CMD_WR_REG_AUX_AUX_O_3_S  "CMD_WR_REG_AUX_AUX_O_3" 
 #define  CMD_RD_REG_AUX_AUX_O_3_S  "CMD_RD_REG_AUX_AUX_O_3" 
 #define  CMD_WR_REG_AUX_AUX_ENQ_3_S  "CMD_WR_REG_AUX_AUX_ENQ_3" 
 #define  CMD_RD_REG_AUX_AUX_ENQ_3_S  "CMD_RD_REG_AUX_AUX_ENQ_3" 
 #define  CMD_WR_REG_AUX_MUX10_LOW_SEL_S  "CMD_WR_REG_AUX_MUX10_LOW_SEL" 
 #define  CMD_RD_REG_AUX_MUX10_LOW_SEL_S  "CMD_RD_REG_AUX_MUX10_LOW_SEL" 
 #define  CMD_WR_REG_AUX_MUX10_HIGH_SEL_S  "CMD_WR_REG_AUX_MUX10_HIGH_SEL" 
 #define  CMD_RD_REG_AUX_MUX10_HIGH_SEL_S  "CMD_RD_REG_AUX_MUX10_HIGH_SEL" 
 #define  CMD_WR_REG_AUX_MUX4_LOW_SEL_S  "CMD_WR_REG_AUX_MUX4_LOW_SEL" 
 #define  CMD_RD_REG_AUX_MUX4_LOW_SEL_S  "CMD_RD_REG_AUX_MUX4_LOW_SEL" 
 #define  CMD_WR_REG_AUX_MUX4_HIGH_SEL_S  "CMD_WR_REG_AUX_MUX4_HIGH_SEL" 
 #define  CMD_RD_REG_AUX_MUX4_HIGH_SEL_S  "CMD_RD_REG_AUX_MUX4_HIGH_SEL" 
 #define  CMD_WR_REG_AUX_AUX_IF_MODE_S  "CMD_WR_REG_AUX_AUX_IF_MODE" 
 #define  CMD_RD_REG_AUX_AUX_IF_MODE_S  "CMD_RD_REG_AUX_AUX_IF_MODE" 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_0_S  "CMD_WR_REG_AUX_SDI_IF_SEL_0" 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_0_S  "CMD_RD_REG_AUX_SDI_IF_SEL_0" 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_1_S  "CMD_WR_REG_AUX_SDI_IF_SEL_1" 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_1_S  "CMD_RD_REG_AUX_SDI_IF_SEL_1" 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_2_S  "CMD_WR_REG_AUX_SDI_IF_SEL_2" 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_2_S  "CMD_RD_REG_AUX_SDI_IF_SEL_2" 
 #define  CMD_WR_REG_AUX_SDI_IF_SEL_3_S  "CMD_WR_REG_AUX_SDI_IF_SEL_3" 
 #define  CMD_RD_REG_AUX_SDI_IF_SEL_3_S  "CMD_RD_REG_AUX_SDI_IF_SEL_3" 
 #define  CMD_WR_REG_AUX_SCI_IF_MODE_S  "CMD_WR_REG_AUX_SCI_IF_MODE" 
 #define  CMD_RD_REG_AUX_SCI_IF_MODE_S  "CMD_RD_REG_AUX_SCI_IF_MODE" 
 #define  CMD_RD_REG_AUX_DEV_ID_S  "CMD_RD_REG_AUX_DEV_ID" 
 #define  CMD_WR_REG_AUX_DEV_ADDR_S  "CMD_WR_REG_AUX_DEV_ADDR" 
 #define  CMD_RD_REG_AUX_DEV_ADDR_S  "CMD_RD_REG_AUX_DEV_ADDR" 
 #define  CMD_WR_REG_AUX_DUMMY_S  "CMD_WR_REG_AUX_DUMMY" 
 #define  CMD_RD_REG_AUX_DUMMY_S  "CMD_RD_REG_AUX_DUMMY" 
 #define  CMD_WR_REG_AUX_TEMP_IN_S  "CMD_WR_REG_AUX_TEMP_IN" 
 #define  CMD_RD_REG_AUX_TEMP_IN_S  "CMD_RD_REG_AUX_TEMP_IN" 
 #define  CMD_RD_REG_AUX_TEMP_PUT_S  "CMD_RD_REG_AUX_TEMP_PUT" 
 #define  CMD_WR_REG_AUX_PD2DBG_SEL_S  "CMD_WR_REG_AUX_PD2DBG_SEL" 
 #define  CMD_RD_REG_AUX_PD2DBG_SEL_S  "CMD_RD_REG_AUX_PD2DBG_SEL" 
 #define  CMD_WR_REG_AUX_PRT_0_DBG_S  "CMD_WR_REG_AUX_PRT_0_DBG" 
 #define  CMD_RD_REG_AUX_PRT_0_DBG_S  "CMD_RD_REG_AUX_PRT_0_DBG" 
 #define  CMD_WR_REG_AUX_PRT_1_DBG_S  "CMD_WR_REG_AUX_PRT_1_DBG" 
 #define  CMD_RD_REG_AUX_PRT_1_DBG_S  "CMD_RD_REG_AUX_PRT_1_DBG" 
 #define  CMD_WR_REG_AUX_PRT_2_DBG_S  "CMD_WR_REG_AUX_PRT_2_DBG" 
 #define  CMD_RD_REG_AUX_PRT_2_DBG_S  "CMD_RD_REG_AUX_PRT_2_DBG" 
 #define  CMD_WR_REG_AUX_PRT_3_DBG_S  "CMD_WR_REG_AUX_PRT_3_DBG" 
 #define  CMD_RD_REG_AUX_PRT_3_DBG_S  "CMD_RD_REG_AUX_PRT_3_DBG" 



/* message elements: ACK_RD_REG_AUX */


 #define  ACK_RD_REG_AUX_rsta_S  L"rsta" 
 #define  ACK_RD_REG_AUX_value_S  L"value" 



/* message elements: ACK_WR_REG_AUX */


 #define  ACK_WR_REG_AUX_rsta_S  L"rsta" 



/* message elements: CMD_WR_REG_AUX_AUX_O_0 */


 #define  CMD_WR_REG_AUX_AUX_O_0_aux_o_0_S  L"aux_o_0" 



/* message elements: CMD_WR_REG_AUX_AUX_ENQ_0 */


 #define  CMD_WR_REG_AUX_AUX_ENQ_0_aux_enq_0_S  L"aux_enq_0" 



/* message elements: CMD_WR_REG_AUX_AUX_O_1 */


 #define  CMD_WR_REG_AUX_AUX_O_1_aux_o_1_S  L"aux_o_1" 



/* message elements: CMD_WR_REG_AUX_AUX_ENQ_1 */


 #define  CMD_WR_REG_AUX_AUX_ENQ_1_aux_enq_1_S  L"aux_enq_1" 



/* message elements: CMD_WR_REG_AUX_AUX_O_2 */


 #define  CMD_WR_REG_AUX_AUX_O_2_aux_o_2_S  L"aux_o_2" 



/* message elements: CMD_WR_REG_AUX_AUX_ENQ_2 */


 #define  CMD_WR_REG_AUX_AUX_ENQ_2_aux_enq_2_S  L"aux_enq_2" 



/* message elements: CMD_WR_REG_AUX_AUX_O_3 */


 #define  CMD_WR_REG_AUX_AUX_O_3_aux_o_3_S  L"aux_o_3" 



/* message elements: CMD_WR_REG_AUX_AUX_ENQ_3 */


 #define  CMD_WR_REG_AUX_AUX_ENQ_3_aux_enq_3_S  L"aux_enq_3" 



/* message elements: CMD_WR_REG_AUX_MUX10_LOW_SEL */


 #define  CMD_WR_REG_AUX_MUX10_LOW_SEL_mux10_low_sel_S  L"mux10_low_sel" 



/* message elements: CMD_WR_REG_AUX_MUX10_HIGH_SEL */


 #define  CMD_WR_REG_AUX_MUX10_HIGH_SEL_mux10_high_sel_S  L"mux10_high_sel" 



/* message elements: CMD_WR_REG_AUX_MUX4_LOW_SEL */


 #define  CMD_WR_REG_AUX_MUX4_LOW_SEL_mux4_low_sel_S  L"mux4_low_sel" 



/* message elements: CMD_WR_REG_AUX_MUX4_HIGH_SEL */


 #define  CMD_WR_REG_AUX_MUX4_HIGH_SEL_mux4_high_sel_S  L"mux4_high_sel" 



/* message elements: CMD_WR_REG_AUX_AUX_IF_MODE */


 #define  CMD_WR_REG_AUX_AUX_IF_MODE_aux_if_mode_S  L"aux_if_mode" 



/* message elements: CMD_WR_REG_AUX_SDI_IF_SEL_0 */


 #define  CMD_WR_REG_AUX_SDI_IF_SEL_0_sdi_if_sel_0_S  L"sdi_if_sel_0" 



/* message elements: CMD_WR_REG_AUX_SDI_IF_SEL_1 */


 #define  CMD_WR_REG_AUX_SDI_IF_SEL_1_sdi_if_sel_1_S  L"sdi_if_sel_1" 



/* message elements: CMD_WR_REG_AUX_SDI_IF_SEL_2 */


 #define  CMD_WR_REG_AUX_SDI_IF_SEL_2_sdi_if_sel_2_S  L"sdi_if_sel_2" 



/* message elements: CMD_WR_REG_AUX_SDI_IF_SEL_3 */


 #define  CMD_WR_REG_AUX_SDI_IF_SEL_3_sdi_if_sel_3_S  L"sdi_if_sel_3" 



/* message elements: CMD_WR_REG_AUX_SCI_IF_MODE */


 #define  CMD_WR_REG_AUX_SCI_IF_MODE_sci_if_mode_S  L"sci_if_mode" 



/* message elements: CMD_WR_REG_AUX_DEV_ADDR */


 #define  CMD_WR_REG_AUX_DEV_ADDR_dev_addr_S  L"dev_addr" 



/* message elements: CMD_WR_REG_AUX_DUMMY */


 #define  CMD_WR_REG_AUX_DUMMY_dummy_S  L"dummy" 



/* message elements: CMD_WR_REG_AUX_TEMP_IN */


 #define  CMD_WR_REG_AUX_TEMP_IN_temp_in_S  L"temp_in" 



/* message elements: CMD_WR_REG_AUX_PD2DBG_SEL */


 #define  CMD_WR_REG_AUX_PD2DBG_SEL_pd2dbg_sel_S  L"pd2dbg_sel" 



/* message elements: CMD_WR_REG_AUX_PRT_0_DBG */


 #define  CMD_WR_REG_AUX_PRT_0_DBG_prt_0_dbg_S  L"prt_0_dbg" 



/* message elements: CMD_WR_REG_AUX_PRT_1_DBG */


 #define  CMD_WR_REG_AUX_PRT_1_DBG_prt_1_dbg_S  L"prt_1_dbg" 



/* message elements: CMD_WR_REG_AUX_PRT_2_DBG */


 #define  CMD_WR_REG_AUX_PRT_2_DBG_prt_2_dbg_S  L"prt_2_dbg" 



/* message elements: CMD_WR_REG_AUX_PRT_3_DBG */


 #define  CMD_WR_REG_AUX_PRT_3_DBG_prt_3_dbg_S  L"prt_3_dbg" 



/* message definitions */

/** message: ACK_RD_REG_AUX */

typedef struct ack_rd_reg_aux_s 
{ 
  /** Receive Status */ 
  UINT8  rsta; 
  /** Value */ 
  UINT8  value; 
} __PACKED__ ack_rd_reg_aux_t; 


/** message: ACK_WR_REG_AUX */

typedef struct ack_wr_reg_aux_s 
{ 
  /** Receive Status */ 
  UINT8  rsta; 
} __PACKED__ ack_wr_reg_aux_t; 


/** message: CMD_WR_REG_AUX_AUX_O_0 */

typedef struct cmd_wr_reg_aux_aux_o_0_s 
{ 
  /** AUX_O_0 */ 
  UINT8  aux_o_0; 
} __PACKED__ cmd_wr_reg_aux_aux_o_0_t; 


/** message: CMD_WR_REG_AUX_AUX_ENQ_0 */

typedef struct cmd_wr_reg_aux_aux_enq_0_s 
{ 
  /** AUX_ENQ_0 */ 
  UINT8  aux_enq_0; 
} __PACKED__ cmd_wr_reg_aux_aux_enq_0_t; 


/** message: CMD_WR_REG_AUX_AUX_O_1 */

typedef struct cmd_wr_reg_aux_aux_o_1_s 
{ 
  /** AUX_O_1 */ 
  UINT8  aux_o_1; 
} __PACKED__ cmd_wr_reg_aux_aux_o_1_t; 


/** message: CMD_WR_REG_AUX_AUX_ENQ_1 */

typedef struct cmd_wr_reg_aux_aux_enq_1_s 
{ 
  /** AUX_ENQ_1 */ 
  UINT8  aux_enq_1; 
} __PACKED__ cmd_wr_reg_aux_aux_enq_1_t; 


/** message: CMD_WR_REG_AUX_AUX_O_2 */

typedef struct cmd_wr_reg_aux_aux_o_2_s 
{ 
  /** AUX_O_2 */ 
  UINT8  aux_o_2; 
} __PACKED__ cmd_wr_reg_aux_aux_o_2_t; 


/** message: CMD_WR_REG_AUX_AUX_ENQ_2 */

typedef struct cmd_wr_reg_aux_aux_enq_2_s 
{ 
  /** AUX_ENQ_2 */ 
  UINT8  aux_enq_2; 
} __PACKED__ cmd_wr_reg_aux_aux_enq_2_t; 


/** message: CMD_WR_REG_AUX_AUX_O_3 */

typedef struct cmd_wr_reg_aux_aux_o_3_s 
{ 
  /** AUX_O_3 */ 
  UINT8  aux_o_3; 
} __PACKED__ cmd_wr_reg_aux_aux_o_3_t; 


/** message: CMD_WR_REG_AUX_AUX_ENQ_3 */

typedef struct cmd_wr_reg_aux_aux_enq_3_s 
{ 
  /** AUX_ENQ_3 */ 
  UINT8  aux_enq_3; 
} __PACKED__ cmd_wr_reg_aux_aux_enq_3_t; 


/** message: CMD_WR_REG_AUX_MUX10_LOW_SEL */

typedef struct cmd_wr_reg_aux_mux10_low_sel_s 
{ 
  /** MUX10_LOW_SEL */ 
  UINT8  mux10_low_sel; 
} __PACKED__ cmd_wr_reg_aux_mux10_low_sel_t; 


/** message: CMD_WR_REG_AUX_MUX10_HIGH_SEL */

typedef struct cmd_wr_reg_aux_mux10_high_sel_s 
{ 
  /** MUX10_HIGH_SEL */ 
  UINT8  mux10_high_sel; 
} __PACKED__ cmd_wr_reg_aux_mux10_high_sel_t; 


/** message: CMD_WR_REG_AUX_MUX4_LOW_SEL */

typedef struct cmd_wr_reg_aux_mux4_low_sel_s 
{ 
  /** MUX4_LOW_SEL */ 
  UINT8  mux4_low_sel; 
} __PACKED__ cmd_wr_reg_aux_mux4_low_sel_t; 


/** message: CMD_WR_REG_AUX_MUX4_HIGH_SEL */

typedef struct cmd_wr_reg_aux_mux4_high_sel_s 
{ 
  /** MUX4_HIGH_SEL */ 
  UINT8  mux4_high_sel; 
} __PACKED__ cmd_wr_reg_aux_mux4_high_sel_t; 


/** message: CMD_WR_REG_AUX_AUX_IF_MODE */

typedef struct cmd_wr_reg_aux_aux_if_mode_s 
{ 
  /** AUX_IF_MODE */ 
  UINT8  aux_if_mode; 
} __PACKED__ cmd_wr_reg_aux_aux_if_mode_t; 


/** message: CMD_WR_REG_AUX_SDI_IF_SEL_0 */

typedef struct cmd_wr_reg_aux_sdi_if_sel_0_s 
{ 
  /** SDI_IF_SEL_0 */ 
  UINT8  sdi_if_sel_0; 
} __PACKED__ cmd_wr_reg_aux_sdi_if_sel_0_t; 


/** message: CMD_WR_REG_AUX_SDI_IF_SEL_1 */

typedef struct cmd_wr_reg_aux_sdi_if_sel_1_s 
{ 
  /** SDI_IF_SEL_1 */ 
  UINT8  sdi_if_sel_1; 
} __PACKED__ cmd_wr_reg_aux_sdi_if_sel_1_t; 


/** message: CMD_WR_REG_AUX_SDI_IF_SEL_2 */

typedef struct cmd_wr_reg_aux_sdi_if_sel_2_s 
{ 
  /** SDI_IF_SEL_2 */ 
  UINT8  sdi_if_sel_2; 
} __PACKED__ cmd_wr_reg_aux_sdi_if_sel_2_t; 


/** message: CMD_WR_REG_AUX_SDI_IF_SEL_3 */

typedef struct cmd_wr_reg_aux_sdi_if_sel_3_s 
{ 
  /** SDI_IF_SEL_3 */ 
  UINT8  sdi_if_sel_3; 
} __PACKED__ cmd_wr_reg_aux_sdi_if_sel_3_t; 


/** message: CMD_WR_REG_AUX_SCI_IF_MODE */

typedef struct cmd_wr_reg_aux_sci_if_mode_s 
{ 
  /** SCI_IF_MODE */ 
  UINT8  sci_if_mode; 
} __PACKED__ cmd_wr_reg_aux_sci_if_mode_t; 


/** message: CMD_WR_REG_AUX_DEV_ADDR */

typedef struct cmd_wr_reg_aux_dev_addr_s 
{ 
  /** DEV_ADDR */ 
  UINT8  dev_addr; 
} __PACKED__ cmd_wr_reg_aux_dev_addr_t; 


/** message: CMD_WR_REG_AUX_DUMMY */

typedef struct cmd_wr_reg_aux_dummy_s 
{ 
  /** DUMMY */ 
  UINT8  dummy; 
} __PACKED__ cmd_wr_reg_aux_dummy_t; 


/** message: CMD_WR_REG_AUX_TEMP_IN */

typedef struct cmd_wr_reg_aux_temp_in_s 
{ 
  /** TEMP_IN */ 
  UINT8  temp_in; 
} __PACKED__ cmd_wr_reg_aux_temp_in_t; 


/** message: CMD_WR_REG_AUX_PD2DBG_SEL */

typedef struct cmd_wr_reg_aux_pd2dbg_sel_s 
{ 
  /** PD2DBG_SEL */ 
  UINT8  pd2dbg_sel; 
} __PACKED__ cmd_wr_reg_aux_pd2dbg_sel_t; 


/** message: CMD_WR_REG_AUX_PRT_0_DBG */

typedef struct cmd_wr_reg_aux_prt_0_dbg_s 
{ 
  /** PRT_0_DBG */ 
  UINT8  prt_0_dbg; 
} __PACKED__ cmd_wr_reg_aux_prt_0_dbg_t; 


/** message: CMD_WR_REG_AUX_PRT_1_DBG */

typedef struct cmd_wr_reg_aux_prt_1_dbg_s 
{ 
  /** PRT_1_DBG */ 
  UINT8  prt_1_dbg; 
} __PACKED__ cmd_wr_reg_aux_prt_1_dbg_t; 


/** message: CMD_WR_REG_AUX_PRT_2_DBG */

typedef struct cmd_wr_reg_aux_prt_2_dbg_s 
{ 
  /** PRT_2_DBG */ 
  UINT8  prt_2_dbg; 
} __PACKED__ cmd_wr_reg_aux_prt_2_dbg_t; 


/** message: CMD_WR_REG_AUX_PRT_3_DBG */

typedef struct cmd_wr_reg_aux_prt_3_dbg_s 
{ 
  /** PRT_3_DBG */ 
  UINT8  prt_3_dbg; 
} __PACKED__ cmd_wr_reg_aux_prt_3_dbg_t; 

/*@}*/ /* Common Messages */

typedef union SDFE4_AUX_u
{

 /** message: ACK_RD_REG_AUX */ 
 ack_rd_reg_aux_t  ack_rd_reg_aux_m;

 /** message: ACK_WR_REG_AUX */ 
 ack_wr_reg_aux_t  ack_wr_reg_aux_m;

 /** message: CMD_WR_REG_AUX_AUX_O_0 */ 
 cmd_wr_reg_aux_aux_o_0_t  cmd_wr_reg_aux_aux_o_0_m;

 /** message: CMD_WR_REG_AUX_AUX_ENQ_0 */ 
 cmd_wr_reg_aux_aux_enq_0_t  cmd_wr_reg_aux_aux_enq_0_m;

 /** message: CMD_WR_REG_AUX_AUX_O_1 */ 
 cmd_wr_reg_aux_aux_o_1_t  cmd_wr_reg_aux_aux_o_1_m;

 /** message: CMD_WR_REG_AUX_AUX_ENQ_1 */ 
 cmd_wr_reg_aux_aux_enq_1_t  cmd_wr_reg_aux_aux_enq_1_m;

 /** message: CMD_WR_REG_AUX_AUX_O_2 */ 
 cmd_wr_reg_aux_aux_o_2_t  cmd_wr_reg_aux_aux_o_2_m;

 /** message: CMD_WR_REG_AUX_AUX_ENQ_2 */ 
 cmd_wr_reg_aux_aux_enq_2_t  cmd_wr_reg_aux_aux_enq_2_m;

 /** message: CMD_WR_REG_AUX_AUX_O_3 */ 
 cmd_wr_reg_aux_aux_o_3_t  cmd_wr_reg_aux_aux_o_3_m;

 /** message: CMD_WR_REG_AUX_AUX_ENQ_3 */ 
 cmd_wr_reg_aux_aux_enq_3_t  cmd_wr_reg_aux_aux_enq_3_m;

 /** message: CMD_WR_REG_AUX_MUX10_LOW_SEL */ 
 cmd_wr_reg_aux_mux10_low_sel_t  cmd_wr_reg_aux_mux10_low_sel_m;

 /** message: CMD_WR_REG_AUX_MUX10_HIGH_SEL */ 
 cmd_wr_reg_aux_mux10_high_sel_t  cmd_wr_reg_aux_mux10_high_sel_m;

 /** message: CMD_WR_REG_AUX_MUX4_LOW_SEL */ 
 cmd_wr_reg_aux_mux4_low_sel_t  cmd_wr_reg_aux_mux4_low_sel_m;

 /** message: CMD_WR_REG_AUX_MUX4_HIGH_SEL */ 
 cmd_wr_reg_aux_mux4_high_sel_t  cmd_wr_reg_aux_mux4_high_sel_m;

 /** message: CMD_WR_REG_AUX_AUX_IF_MODE */ 
 cmd_wr_reg_aux_aux_if_mode_t  cmd_wr_reg_aux_aux_if_mode_m;

 /** message: CMD_WR_REG_AUX_SDI_IF_SEL_0 */ 
 cmd_wr_reg_aux_sdi_if_sel_0_t  cmd_wr_reg_aux_sdi_if_sel_0_m;

 /** message: CMD_WR_REG_AUX_SDI_IF_SEL_1 */ 
 cmd_wr_reg_aux_sdi_if_sel_1_t  cmd_wr_reg_aux_sdi_if_sel_1_m;

 /** message: CMD_WR_REG_AUX_SDI_IF_SEL_2 */ 
 cmd_wr_reg_aux_sdi_if_sel_2_t  cmd_wr_reg_aux_sdi_if_sel_2_m;

 /** message: CMD_WR_REG_AUX_SDI_IF_SEL_3 */ 
 cmd_wr_reg_aux_sdi_if_sel_3_t  cmd_wr_reg_aux_sdi_if_sel_3_m;

 /** message: CMD_WR_REG_AUX_SCI_IF_MODE */ 
 cmd_wr_reg_aux_sci_if_mode_t  cmd_wr_reg_aux_sci_if_mode_m;

 /** message: CMD_WR_REG_AUX_DEV_ADDR */ 
 cmd_wr_reg_aux_dev_addr_t  cmd_wr_reg_aux_dev_addr_m;

 /** message: CMD_WR_REG_AUX_DUMMY */ 
 cmd_wr_reg_aux_dummy_t  cmd_wr_reg_aux_dummy_m;

 /** message: CMD_WR_REG_AUX_TEMP_IN */ 
 cmd_wr_reg_aux_temp_in_t  cmd_wr_reg_aux_temp_in_m;

 /** message: CMD_WR_REG_AUX_PD2DBG_SEL */ 
 cmd_wr_reg_aux_pd2dbg_sel_t  cmd_wr_reg_aux_pd2dbg_sel_m;

 /** message: CMD_WR_REG_AUX_PRT_0_DBG */ 
 cmd_wr_reg_aux_prt_0_dbg_t  cmd_wr_reg_aux_prt_0_dbg_m;

 /** message: CMD_WR_REG_AUX_PRT_1_DBG */ 
 cmd_wr_reg_aux_prt_1_dbg_t  cmd_wr_reg_aux_prt_1_dbg_m;

 /** message: CMD_WR_REG_AUX_PRT_2_DBG */ 
 cmd_wr_reg_aux_prt_2_dbg_t  cmd_wr_reg_aux_prt_2_dbg_m;

 /** message: CMD_WR_REG_AUX_PRT_3_DBG */ 
 cmd_wr_reg_aux_prt_3_dbg_t  cmd_wr_reg_aux_prt_3_dbg_m;
} __PACKED__ SDFE4_AUX_t; 
#endif

/*@}*/ /* SDFE4_AUX */

