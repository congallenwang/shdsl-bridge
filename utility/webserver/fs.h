/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/
#ifndef __FS_H__
#define __FS_H__

/*#include "uip.h"*/

/**
 * An open file in the read-only file system.
 */


#ifdef FS_STATISTICS
#if FS_STATISTICS == 1  
u16_t fs_count(char *name);
#endif /* FS_STATISTICS */
#endif /* FS_STATISTICS */

/**
 * Initialize the read-only file system.
 */
void fs_init(void);

#endif /* __FS_H__ */







