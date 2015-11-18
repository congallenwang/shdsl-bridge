/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/

#ifndef __HTTPD_H__
#define __HTTPD_H__
#include "common.h"
#include "uip-conf.h"
void httpd_init(void);
void httpd_appcall(void);
void http_dump_body(void);
u8_t http_search_body (const char *name_ptr, char *value_ptr, uchar bufsiz);


#define MAX_URI_LEN      80
#define MAX_BODY_LEN      1000
#define MAX_BOUNDARY_LEN 80
#if 0
typedef enum {STATIC, STATIC_SPC, DYNAMIC, DYNAMIC_NOSPC} file_type_t;

 struct  fs_file {
  const char *dat;  /**< The actual file data. */
  int len;     /**< The length of the file data. */
  file_type_t type;
};
#endif
typedef struct {
    u8_t  method;
    u8_t  uri_len;
    u8_t  uri [MAX_URI_LEN + 4];
    u16_t body_i;
    unsigned long body_len;
    u8_t  boundary_len;
    u8_t  boundary_match;
    u8_t  prev_ch;
    u8_t  expect_iso_nl;
    u8_t  content_len_match;
    u8_t  content_type_match;
    u8_t  content_type_appl_match;
    //allen
    u8_t  filename_match;
    u8_t  error;
} http_t;

struct httpd_state{
  u8_t state; 
  struct fs_file file;
  u16_t count;
  char *dataptr;
  u16_t count_rom;
  char *dataptr_rom;

  http_t http;
 
};

typedef void (*post_func_t)(struct httpd_state *hs);

int fs_open(const char *name, struct fs_file  *file);
post_func_t fs_post_func (const char *name);

/* UIP_APPSTATE_SIZE: The size of the application-specific state
   stored in the uip_conn structure. */
#ifndef UIP_APPSTATE_SIZE
#define UIP_APPSTATE_SIZE (sizeof(struct httpd_state))
#endif

#define FS_STATISTICS 0

//extern struct httpd_state xdata *hs;

#endif /* __HTTPD_H__ */
