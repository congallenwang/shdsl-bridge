/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/

#ifndef __WEBPOST_H__
#define __WEBPOST_H__


void web_password_func (struct httpd_state  *hs);
void web_led_func (struct httpd_state  *hs);
void web_select_func (struct httpd_state  *hs);
void web_text_func (struct httpd_state  *hs);
void web_check_func (struct httpd_state  *hs);
void web_radio_func (struct httpd_state  *hs);
void web_upload_func_done (struct httpd_state  *hs);
void web_logout_func (struct httpd_state  *hs);
void web_dslconfig_func(struct httpd_state *hs); 


#endif



