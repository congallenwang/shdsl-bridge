#ifndef __WEBVAR_H__
#define __WEBVAR_H__
/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/

typedef struct {
    ushort len;
    uchar dat[512 - sizeof(ushort)];
} var_buf_t;

 

#endif
