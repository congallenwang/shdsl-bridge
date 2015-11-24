/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/ 
#include "common.h"
#include "uip.h" 
#include "fs.h"
#include  "httpd.h" 
#include "webhnd.h"
#include "webvar.h"

//#include <string.h>
 
/* ************************************************************************ **
 *
 *
 * Defines
 *
 *
 *
 * ************************************************************************ */

/*  */
#define REBOOT          1
#define CHANGE_IP       2
#define CHANGE_DHCP     3

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

static uchar  reboot_pending = 0;
static uchar  reboot_execute = 0;
static uchar  reboot_timer   = 0;
static struct httpd_state *reboot_hs = 0; // pnc PTR_NULL;

/* ************************************************************************ **
 *
 *
 * Public data
 *
 *
 *
 * ************************************************************************ */
//allen: no log in
//uchar  web_logged_in = 0;
uchar  web_logged_in = 1;
#if TRANSIT_WEB_TIMEOUT
ushort	adminIp[2];   /** The IP address of the currently connected remote host. **/
uchar	web_failed_login = 0;
ushort	web_login_to = 0;
#endif /* TRANSIT_WEB_TIMEOUT */


/* ************************************************************************  
; ushort web_copy (ushort count, uchar   *dst_ptr, uchar   *src_ptr);
_web_copy:
;* ------------------------------------------------------------------------ --
;* Purpose     : Copy data from source (in flash) to destination (in XRAM)
;*               until '@' char is encountered or no more data. 
;*               Return no. of bytes remaining.
;* Restrictions:
;* See also    :
;* Example     :
; * ************************************************************************ */
ushort web_copy (ushort count, uchar *dst_ptr, uchar *src_ptr)
{
 
	
	if(count == 0){
			return 0; 
		}
	while(count > 0){
		if(*src_ptr == '@'){
			return count;		
		}		
		*dst_ptr = *src_ptr;
		dst_ptr++;
		src_ptr++;
		count--;
  }		
		return count;		
}






/* ************************************************************************ */
void web_init (void)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    /* Nothing to do, really  */
}



 

/* ************************************************************************ */
 
void web_send_complete (struct httpd_state *hs)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    if (reboot_pending) {
        if (hs == reboot_hs) {
            reboot_execute = 1;
            reboot_timer   = 0;
        }
    }
}

/* ************************************************************************ */
void web_select_page (const char *name, struct httpd_state  *hs)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
	//rt_kprintf("web_select_page, name:%s\r\n",name);

#define INDEX_PAGE "password"
#if TRANSIT_WEB_TIMEOUT
 	// Check user session
	if ( web_logged_in && (adminIp[0] != uip_conn->ripaddr[0] || adminIp[1] != uip_conn->ripaddr[1]) )
	{
		fs_open("duplicate", &hs->file);
	    web_build_dyn(hs, WEB_DYN_PAGE_CREATE);
		return;
	}
	
	// wux Handle login session
    if ( web_logged_in  ) web_login_to = LOGIN_TIMEOUT;  
#endif /* TRANSIT_WEB_TIMEOUT */
    if (!fs_open(name, &hs->file)) {
        fs_open("404", &hs->file);
    }

    if (hs->file.type == STATIC) {
        hs->dataptr = (char *)hs->file.dat;
        hs->count   = hs->file.len;	
        return;
    }

    if (hs->file.type != DYNAMIC_NOSPC) {
        if (!web_logged_in) {
            if (!fs_open(INDEX_PAGE, &hs->file)) {
                fs_open("404", &hs->file);
            }
            hs->dataptr = (char *)hs->file.dat;
            hs->count   = hs->file.len;	
            return;
        }
    }

    if (hs->file.type == STATIC_SPC) {
        hs->dataptr = (char *)hs->file.dat;
        hs->count   = hs->file.len;	
        return;
    }

    /* build page into RAM buffer */
    web_build_dyn(hs, WEB_DYN_PAGE_CREATE);
#undef INDEX_PAGE
}


void web_timer_1(void)
{
#if TRANSIT_WEB_TIMEOUT
    // Has the user login timed out ?
	if ( web_login_to && web_logged_in )
	{
		if ( !(--web_login_to) )  web_logged_in = 0;
	}
#endif /* TRANSIT_WEB_TIMEOUT */
}




#if 0
/* ************************************************************************ */
void web_timer_1 (void)
/* ------------------------------------------------------------------------ --
 * Purpose     : One second timing for the web tasks.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    if (reboot_pending) {
        /* If more than 10 seconds elapsed without completion from TCP/IP stack */
        /* do force the reboot. */
        if (++reboot_timer >= 10) { 
            reboot_execute = 1;
            reboot_timer   = 0;
        }
    }

    if (reboot_execute) {

        reboot_execute = 0; /* hopefully superfluous */

        /* Execute the delayed action */
        switch (reboot_pending) {
        case REBOOT :
            reboot_pending = 0; 
            reboot();
            break;
        case CHANGE_IP :
            /* Not handling the error condition of a IP change cause there is nothing I */
            /* could do anyway.   I can't write out any more messages. */
            reboot_pending = 0; 
            web2cli(ip_setup_cmd);
            break;
#if TRANSIT_DHCPCLIENT
        case CHANGE_DHCP:
            reboot_pending = 0; 
            dhcpclient_setup();
            break;
#endif /* TRANSIT_DHCPCLIENT */
        }
        
    }

#if TRANSIT_WEB_TIMEOUT
    // Has the user login timed out ?
	if ( web_login_to && web_logged_in )
	{
		if ( !(--web_login_to) )  web_logged_in = 0;
	}
#endif /* TRANSIT_WEB_TIMEOUT */
}


void web_change_ip (const char *cmd, struct httpd_state  *hs)
{
   // strcpy(&ip_setup_cmd, cmd);

    // Start looking for completion of transmission
    //
    reboot_pending = CHANGE_IP;
    reboot_hs = hs;
}

#if TRANSIT_DHCPCLIENT
void web_change_dhcp (uchar mode, struct httpd_state  *hs)
{
    eeprom_write_dhcp_mode(mode);

    // Start looking for completion of transmission
    //
    reboot_pending = CHANGE_DHCP;
    reboot_hs = hs;
}
#endif /* TRANSIT_DHCPCLIENT */

void web_request_reboot (struct httpd_state  *hs)
{
    reboot_pending = REBOOT;
    reboot_hs = hs;
}
#endif

void web_build_dyn (struct httpd_state  *hs, web_dyn_state_t state)
{
    uchar  *file_ptr;
    ushort file_left;
    ushort file_delta;
    ushort copied;
    ushort max_copy;
    uchar escape_len;
    var_buf_t var_buf;
    ushort buf_count;
    uchar  *buf_ptr;
	
	  ulong temp1,temp2,temp3;

    /*
    ** Determine source of data dependent on state
    */
    switch (state) {
    case WEB_DYN_PAGE_CREATE:
        file_ptr  = (char *)hs->file.dat;
        file_left = hs->file.len;
        hs->dataptr_rom = (char *)hs->file.dat;
        break;
    case WEB_DYN_PAGE_CONTINUE:
        hs->dataptr_rom += hs->count_rom;
        /* fall through */
    case WEB_DYN_PAGE_REPEAT:
        file_ptr  = hs->dataptr_rom;
		    temp1 = (ulong)file_ptr;
		    temp2 = (ulong)(hs->file.dat);
		    file_left = hs->file.len - (temp1 - temp2); 
        //file_left = hs->file.len - (ulong)((ulong)(file_ptr) - (ulong)(hs->file.dat));
        break;
    default:
        file_ptr  = (char *)hs->file.dat;
        file_left = hs->file.len;
        hs->dataptr_rom = (char *)hs->file.dat;
        break;
    }

    /* Use RAM buffer provided by TCP/IP for data */
    buf_ptr = uip_appdata;
    buf_count = 0;

    /*
    ** Generate a chunk of data in RAM buffer until no more data in file or 
    ** no more room in RAM buffer.
    */
    file_delta = 0;
    while (file_left > 0) {

        /*
        ** Copy data from the htm file in  memory into RAM buffer until 
        ** end of file, end of RAM buffer or escape char '@' met.
        */
        if (file_left > (uip_mss() - buf_count)) {
            max_copy = uip_mss() - buf_count;
        }
        else {
            max_copy = file_left;
        }
        copied = max_copy - web_copy(max_copy, &buf_ptr[buf_count], &file_ptr[file_delta]);
				
        buf_count  += copied;
        file_delta += copied;

        /*
        ** Check if done or variable data to be inserted
        */
        if (copied == max_copy) {
            break; /* no more room in current buffer */
        }
        else { /* i.e. we have a data field */

            file_left -= copied;

            /*
            ** Get variable and insert it in RAM buffer if room
            */
            escape_len = web_get_var(&var_buf,   &file_ptr[file_delta]);
            if ((buf_count + var_buf.len) <= uip_mss()) {

                file_left  -= escape_len;
                file_delta += escape_len;

                memcpy(&buf_ptr[buf_count], &var_buf.dat, var_buf.len);
                buf_count += var_buf.len;
            }
            else {
                break; /* not room for entire variable in current buffer */
            }
        }

    }

    /* update file pointer and length */
    hs->dataptr = buf_ptr;
    hs->count   = buf_count;
    hs->count_rom = file_delta;
}
