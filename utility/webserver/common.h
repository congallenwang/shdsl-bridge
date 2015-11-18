#ifndef __COMMON_H__
#define __COMMON_H__
/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/


/*
** General types
*/
#define uchar   unsigned char
#define uint    unsigned int
#define ulong   unsigned long
#define ushort  unsigned short


#define TRANSIT_WEB_TIMEOUT  1
#define FILE_UPDOWN_LOAD     1

/* 
** Max sizes and max numbers of configuration parameters
*/
#define MAX_SYSTEM_NAME_LEN 16
#define MAX_PASSWORD_LEN    16
#define MAX_USER_PROMPT_LEN 10
#define LOGIN_TIMEOUT			300

 
typedef uchar password_t [MAX_PASSWORD_LEN + 4];
#define ARRAY_LENGTH( arr ) (sizeof(arr) / sizeof(arr[0]))


typedef enum {STATIC, STATIC_SPC, DYNAMIC, DYNAMIC_NOSPC} file_type_t;

 struct  fs_file {
  const char *dat;  /**< The actual file data. */
  int len;     /**< The length of the file data. */
  file_type_t type;
};


#endif
