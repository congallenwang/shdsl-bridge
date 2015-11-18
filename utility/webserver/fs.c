/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/

#include "common.h"
#include "uip.h"
#include "fs.h"
#include "httpd.h"

 

#ifndef NULL
#define NULL (void *)0
#endif


#include "../webpages/filedir.c"
#include "../webpages/funcdir.c"

/*-----------------------------------------------------------------------------------*/
static u8_t
fs_strcmp(const char *str1, const char *str2)
{
  u8_t i;
  i = 0;
 loop:

  if(str2[i] == 0 && (
     str1[i] == '\r' || str1[i] == '\n' || str1[i] == '?' || str1[i] == '\0')) {
    return 0;
  }

  if(str2[i] == '.' && str1[i] == '\0') {
      return 0;
  }



  if(str1[i] != str2[i]) {
    return 1;
  }


  ++i;
  goto loop;
}
/*-----------------------------------------------------------------------------------*/
int
fs_open(const char *name, struct fs_file  *file)
{
    uchar j;

    for (j = 0; j < ARRAY_LENGTH(file_dir); j++) {
        if(fs_strcmp(name, file_dir[j].name) == 0) {
            file->dat = file_dir[j].file_ptr;
            file->len = file_dir[j].len;
            file->type = file_dir[j].type;
            return 1;
        }
    }
    return 0;
}
#if 1
post_func_t fs_post_func (const char *name)
{
    uchar j;

    for (j = 0; j < ARRAY_LENGTH(func_dir); j++) {
        if(fs_strcmp(name, func_dir[j].func_name) == 0) {
            return func_dir[j].func_ptr;
        }
    }
    return 0; // pnc
}
#endif
/*-----------------------------------------------------------------------------------*/
void
fs_init(void)
{
}

















