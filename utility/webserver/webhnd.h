/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/
#ifndef __WEBHND_H__
#define __WEBHND_H__

typedef struct {
    unsigned char current_port;
    unsigned char current_error;
} web_var_save_t;

extern unsigned char  web_logged_in;
#if TRANSIT_WEB_TIMEOUT
extern unsigned short adminIp[2];
extern unsigned char  web_failed_login;
extern unsigned short web_login_to;
#endif /* TRANSIT_WEB_TIMEOUT */

void web_init (void);
void web_timer_1 (void);
void web_send_complete (struct httpd_state *hs);
void web_change_ip (const char *cmd, struct httpd_state  *hs);
#if TRANSIT_DHCPCLIENT
void web_change_dhcp (unsigned char mode, struct httpd_state  *hs);
#endif /* TRANSIT_DHCPCLIENT */
void web_request_reboot (struct httpd_state  *hs);
void web_select_page (const char *name, struct httpd_state  *hs);

typedef enum {
    WEB_DYN_PAGE_CREATE,
    WEB_DYN_PAGE_CONTINUE,
    WEB_DYN_PAGE_REPEAT
} web_dyn_state_t;

void web_build_dyn (struct httpd_state  *hs, web_dyn_state_t state);

#endif












