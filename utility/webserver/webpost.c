/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/

//#include <ctype.h>
#include "uip.h"
#include "common.h"
 
#include "webhnd.h"
#include "webvar.h"
#include "miscfun.h" 

 
 

/* ************************************************************************ **
 *
 *
 * Defines
 *
 *
 *
 * ************************************************************************ */

/* Radio buttons */
#define R00 0x00
#define R10 0x10
#define R11 0x11
#define R12 0x12
#define R17 0x17
#define R20 0x20
#define R30 0x30
#define R40 0x40
#define R50 0x50
#define R70 0x70
#define R90 0x90
#define Rd0 0xd0


/*
** WEB upload cases
*/
#define WEB_UPLOAD_IDLE 0
#define WEB_UPLOAD_SW   1
#define WEB_UPLOAD_CFG  2



/* ************************************************************************ **
 *
 *
 * Typedefs and enums
 *
 *
 *
 * ************************************************************************ */


/* ************************************************************************ **
 *
 *
 * Prototypes for local functions
 *
 *
 *
 * ************************************************************************ */

static char find_submit_value (void);
static char submit_value_equals (uchar cmd_txt_no);
static char refresh_request (void);
static char find_radio_button_value (uchar button_no, uchar *value_ptr);
static char find_radio_button_value_d (uchar button_no, uchar *value_ptr);
static char find_radio_button_string (uchar *button_name, uchar *str_ptr, uchar len);
static char find_radio_button_value_w (uchar button_no, ushort *value_ptr);
static char find_radio_button_value_2 (uchar button_no, uchar *value_ptr);
static char find_form_var (uchar *var_name);
static char find_port_form_var (uchar prefix, uchar port_no);
#if TRANSIT_DOT1X
static char find_form_var_value (uchar button_id, uchar button_no, ushort *value_ptr);
#endif
static char form_var_equals (uchar cmd_txt_no);
static void cmd_append_form_var (void);
static void cmd_append_quoted_form_var (void);
static void cmd_append_number (ulong number);
static void error_func (struct httpd_state  *hs, uchar error_no);
static char password_entered (struct httpd_state  *hs);
static char parse_ip_address(uchar  *ip_str, uchar  *ip_addr);

/* ************************************************************************ **
 *
 *
 * Constants
 *
 *
 *
 * ************************************************************************ */




/* ************************************************************************ **
 *
 *
 * Local data
 *
 *
 *
 * ************************************************************************ */

static uchar submit_buf [15];
static uchar form_var [40];
static uchar find_form_buf[32];
static uchar cmd [100];

static unsigned int web_upload_case = WEB_UPLOAD_IDLE;


/* ************************************************************************ */
void web_password_func (struct httpd_state  *hs)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    uchar len;
   
#if TRANSIT_WEB_TIMEOUT
        // Check user session
        if ( web_logged_in && (adminIp[0] != uip_conn->ripaddr[0] || adminIp[1] != uip_conn->ripaddr[1]) )
        {
            fs_open("duplicate", &hs->file);
            web_build_dyn(hs, WEB_DYN_PAGE_CREATE);
            return;
        }
        
#endif      


    if (find_form_var("password"))  {  /* "password" */

        // Check password
        //
        len = strlen(form_var);
        if (len >= sizeof(form_var)) {
            len = sizeof(form_var) - 1;
        }
        form_var[len] = 0x0d;
        if (password_ok(form_var)) {
            // Set the boolean
            //
            web_logged_in = 1;
#if TRANSIT_WEB_TIMEOUT
            web_failed_login = 0;
            web_login_to = LOGIN_TIMEOUT;
            
            memcpy(&adminIp[0], &uip_conn->ripaddr[0], 2);
            memcpy(&adminIp[1], &uip_conn->ripaddr[1], 2);
#endif            

            // Output the confirmation message
            //
            web_select_page("pwconfirm", hs);

            return;
        }
    }

    // If any of the 'ifs' failed, we'll be here so output the password prompt again
    //
#if TRANSIT_WEB_TIMEOUT
    web_failed_login = 1;
#endif   
    web_select_page("password", hs);
}


 
#ifdef FILE_UPDOWN_LOAD
 ulong upload_file_length = 0;
extern uchar file_buff[];
extern uchar g_filedownload;
extern int g_filelen;
/* ************************************************************************ */
void web_upload_init (const char *name)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    
	//USART1_Put_String("web_upload_init");
	web_upload_case = WEB_UPLOAD_CFG;
	upload_file_length = 0;
	g_filedownload =1;

	rt_kprintf("\r\n%s\r\n",name);
	rt_kprintf("\r\nstart load file>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\r\n");
    if (reserve_updown_load() == 0)
        return;
		
		//USART1_Put_String("web_upload_init done");
		
    if (memcmp(name, "/fileupload", 11) == 0) {
				//USART1_Put_String("fileupload");
        web_upload_case = WEB_UPLOAD_CFG;
        upload_file_length = 0;
    }
 
}

/* ************************************************************************ */
void web_upload_continue (uchar ch)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    file_buff[upload_file_length]=ch;
    upload_file_length++;
    switch (web_upload_case) {
 
 
    case WEB_UPLOAD_CFG:
				//USART1_Put_Char(ch);
        //upload_file_length++;
        break;
 
    default:
        break;
    }
}

/* ************************************************************************ */
void web_upload_func_done (struct httpd_state  *hs)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    switch (web_upload_case) {
 
 
    case WEB_UPLOAD_CFG:
        web_select_page("uploaddone", hs);
        break;
 
    default:
        break;
    }
    release_updown_load();
}
#endif /* FILE_UPDOWN_LOAD */

 

 
 

#if TRANSIT_WEB_TIMEOUT
/* ************************************************************************ */
void web_logout_func (struct httpd_state  *hs)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    web_select_page("password.htm", hs);
    web_logged_in = 0;
    web_failed_login = 0;
    web_login_to = 0;
}
#endif


void web_led_func (struct httpd_state  *hs)
{
		if ( !password_entered(hs) ) {
        return;
    }
		
		if (find_form_var("submit"))  {
				str_conv_to_upper_case(form_var);
				if(strcmp(form_var, "ON") == 0){
						//LED_Green_ON();
				}else if(strcmp(form_var, "OFF") == 0){
						//LED_Green_OFF();
				}
		}

	web_select_page("get", hs);
}


void web_select_func (struct httpd_state  *hs)
{
	if ( !password_entered(hs) ) {
        return;
    }
		
		if (find_form_var("led"))  {
				str_conv_to_upper_case(form_var);
				if(strcmp(form_var, "ON") == 0){
						//LED_Green_ON();
				}else if(strcmp(form_var, "OFF") == 0){
						//LED_Green_OFF();
				}
		}

             if(find_form_var("dslmode"))
             {
                    rt_kprintf("dslmode:%d\n",atoi(form_var));
             }
	web_select_page("postdemo", hs);
}
extern char Vxy[];
void web_text_func (struct httpd_state  *hs)
{
		if ( !password_entered(hs) ) {
        return;
    }
		
		if (find_form_var("text"))  {
			       //allen
				strcpy(Vxy,form_var);
				str_conv_to_upper_case(form_var);
				if(strcmp(form_var, "ON") == 0){
						//LED_Green_ON();
				}else if(strcmp(form_var, "OFF") == 0){
						//LED_Green_OFF();
				}
		}

	web_select_page("postdemo", hs);
}
void web_check_func (struct httpd_state  *hs)
{
		if ( !password_entered(hs) ) {
        return;
    }
		
		if (find_form_var("led"))  {
			//LED_Green_ON();
		}else{
			//LED_Green_OFF();
		}
		
	web_select_page("postdemo", hs);
}
void web_radio_func (struct httpd_state  *hs)
{

	if ( !password_entered(hs) ) {
        return;
    }
		
		if (find_form_var("led"))  {
				if(strcmp(form_var, "1") == 0){
						//LED_Green_ON();
				}else if(strcmp(form_var, "0") == 0){
						//LED_Green_OFF();
				}
		}
		
		web_select_page("postdemo", hs);
}


#include "configmanage.h"
extern CONFIG_PARAM g_config;

/*
int atoi(unsigned char* str)
{
    return 1;
}
*/

void rt_shdsl_apply_config();
void rt_sendmb(unsigned int id);
void web_dslconfig_func(struct httpd_state *hs)
{
    //dslService=1&caplist_co=0&caplist_rt=0&dslWires=3&dslStandard=7&lineprobe=1&extend=0&extend_rate_fix_value=0&minrate=3&maxrate=89&dslmode=13&SUBMIT=Apply
    int dslService;
    int caplist_co;
    int caplist_rt;
    int dslWires;
    int dslStandard;
    int lineprobe;
    int extend;
    int extend_rate_fix_value;
    int minrate;
    int maxrate;
    int dslmode;

    
    if ( !password_entered(hs) ) 
    {
        return;
    }

    if(find_form_var("dslService"))
    {
        g_config.dslService = atoi(form_var);
        rt_kprintf("dslService:%d\n",g_config.dslService);
    }

    if(find_form_var("caplist_co"))
    {
        g_config.caplist_co = atoi(form_var);
        rt_kprintf("caplist_co:%d\n",g_config.caplist_co);
    }

    if(find_form_var("caplist_rt"))
    {
        g_config.caplist_rt = atoi(form_var);
        rt_kprintf("caplist_rt:%d\n",g_config.caplist_rt);
    }

    if(find_form_var("dslWires"))
    {
        g_config.dslWires = atoi(form_var);
        rt_kprintf("dslWires:%d\n",g_config.dslWires);
    }

    if(find_form_var("dslStandard"))
    {
        g_config.dslStandard = atoi(form_var);
        rt_kprintf("dslStandard:%d\n",g_config.dslStandard);
    }

    if(find_form_var("lineprobe"))
    {
        g_config.lineprobe = atoi(form_var);
        rt_kprintf("lineprobe:%d\n",g_config.lineprobe);
    }

     if(find_form_var("extend"))
    {
        g_config.extend = atoi(form_var);
        rt_kprintf("extend:%d\n",g_config.extend);
    }
    
    if(find_form_var("extend_rate_fix_value"))
    {
        g_config.extend_rate_fix_value = atoi(form_var);
        rt_kprintf("dslmode:%d\n",g_config.extend_rate_fix_value);
    }

    if(find_form_var("maxrate"))
    {
        g_config.maxrate=maxrate = atoi(form_var);
        rt_kprintf("maxrate:%d\n",maxrate);
    }

     if(find_form_var("minrate"))
    {
        g_config.minrate= atoi(form_var);
        rt_kprintf("minrate:%d\n",g_config.minrate);
     }

    if(find_form_var("dslmode"))
    {
        g_config.dslmode = atoi(form_var);
        rt_kprintf("dslmode:%d\n",g_config.dslmode);
    }

   

    web_select_page("config", hs);

    //update the config and re init shdsl
    //rt_shdsl_apply_config();    
    rt_sendmb(100);

}
 
 
static char password_entered (struct httpd_state  *hs) 
{
    if ( !web_logged_in ) {

        // If there is no password, throw the prompt up
        //
        web_select_page("password", hs);
        return 0;
    }
    else {
        return 1;
    }
}
 

static char find_submit_value (void)
{
    memset(submit_buf, ' ', sizeof(submit_buf));
    submit_buf[sizeof(submit_buf) - 1]  = '\0';
    
    return http_search_body("submit", submit_buf, sizeof(submit_buf));
}

 


static char refresh_request (void)
{
    return (strcmp("Refresh", &submit_buf) != 0);
}

static char find_radio_button_string (uchar *button_name, uchar *str_ptr, uchar len)
{
 

    if (http_search_body(button_name, str_ptr, len)) {
        return 1;
    }
    return 0;
}


static char find_form_var (uchar *var_name)
{
    return http_search_body(var_name, form_var, sizeof(form_var));
}
/*

static char submit_value_equals (uchar cmd_txt_no)
{
    return (cmp_cmd_txt(cmd_txt_no, &submit_buf) != 0);
}

static char form_var_equals (uchar cmd_txt_no)
{
    return (cmp_cmd_txt(cmd_txt_no, &form_var) != 0);
}
*/
