/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/


#include "common.h"
#include "webhnd.h"
#include "webvar.h"
 
#include "uip.h"
//#include <string.h> 

extern char Vxy[];
extern uip_ipaddr_t uip_hostaddr, uip_netmask, uip_draddr;
extern struct uip_eth_addr uip_ethaddr;

#ifdef FILE_UPDOWN_LOAD
 extern ulong upload_file_length;
#endif
extern int g_totalpage;
/* ************************************************************************ **
 *
 *
 * Defines
 *
 *
 *
 * ************************************************************************ */

#define COUNTER_NONE 0

#define MAXWEBVAR 24

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

 
static ushort type_a_functions (uchar  *escape, char  *dst_ptr);
static ushort type_b_functions (uchar  *escape, char  *dst_ptr);

static void format_js_array_element (uchar index, char  *src_ptr, char  *dst_ptr);
static void print_ip_str(char  *dst_ptr, uip_ipaddr_t addr);
 
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
 
 
/* ************************************************************************ **
 *
 *
 * Public data
 *
 *
 *
 * ************************************************************************ */



/* ************************************************************************ */
uchar web_get_var (var_buf_t  *var_buf,  uchar  *src)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
 /*
    uchar tmp;
    char  *dst_ptr;
    char tmp_buf [15];
 */
    var_buf->len = 0;
 

    src++; /* point to first char after '@' */

    switch (*src++) {

    case '@': 
        var_buf->dat[0] = '@';
        var_buf->len = 1;
        return 2;
				break;

 
    case 'A' :
        // Copy data string over the @A in the HTTP buffer
        //
        var_buf->len = type_a_functions(src, var_buf->dat);
        return 2;
        
    case 'B' :
        // Copy data string over the @Bxx in the HTTP buffer
        //
        var_buf->len =  type_b_functions(src, var_buf->dat);
        return 4; 
#ifdef FILE_UPDOWN_LOAD
		case 'C' :
        // Copy data string over the @C in the HTTP buffer
        //
        var_buf->len = sprintf(var_buf->dat, "%ld", g_totalpage*4096+upload_file_length);
        return 2; 
#endif
		
		default:
        return 2;
        break;
	} 


}



static ushort type_a_functions(uchar  *escape, char  *dst_ptr)
{
     
		strcpy(dst_ptr, "COSMOS Web Server Demo");
    return strlen(dst_ptr);
}
 

static ushort type_b_functions(uchar  *escape, char  *dst_ptr)
{
    uchar p1;
 

    // Switch on the Function Number
   
    p1 = (escape[0] - '0') * 10 + (escape[1] - '0');
 
    switch (p1) {
			//MAC Address
			case 0:
				sprintf(dst_ptr,"%02X-%02X-%02X-%02X-%02X-%02X", uip_ethaddr.addr[0], uip_ethaddr.addr[1], uip_ethaddr.addr[2], uip_ethaddr.addr[3], uip_ethaddr.addr[4], uip_ethaddr.addr[5] );
				break;
			//SW version
			case 1:
        strcpy(dst_ptr, Vxy);
        break;
			//IP Address
			case 2:
        print_ip_str(dst_ptr, uip_hostaddr);
        break;
			//Subnet Mask
			case 3:
        print_ip_str(dst_ptr, uip_netmask);
        break;
			//Gateway
 			case 4:
        print_ip_str(dst_ptr, uip_draddr);
        break;
 
    default :
        break;
 
    }
 
    return strlen(dst_ptr);
}

static void print_ip_str(char  *dst_ptr, uip_ipaddr_t addr)
{
			sprintf(dst_ptr,"%d.%d.%d.%d", addr[0]&0xff, addr[0]>>8, addr[1]&0xff, addr[1]>>8);
}

static void format_js_array_element (uchar index, char  *src_ptr, char  *dst_ptr)
{
    if (index > 0) {
        *dst_ptr = ',';
        dst_ptr++;
    }
    *dst_ptr = '"';
    dst_ptr++;
    strcpy(dst_ptr, src_ptr);
    dst_ptr += strlen(dst_ptr);
    *dst_ptr = '"';
    dst_ptr++;

    *dst_ptr = '\0';
}
