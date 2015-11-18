#ifndef __MISCFUN_H__
#define __MISCFUN_H__
/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/


uchar password_ok (uchar *entry_ptr);
char conv_to_upper_case (char ch);
uchar hex_to_ascii_nib (uchar nib);
uchar ascii_to_hex_nib (uchar ch);
void str_conv_to_upper_case (char *str);

uchar reserve_updown_load(void);
void release_updown_load(void);
#endif
