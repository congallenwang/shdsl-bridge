
/* Note, this file is not compiled directly, but included by uip/fs.c */

#include "index.h"
#include "httpstat.h" 
#include "password.h"
#include "bg.h"
#include "passwordConfirmation.h"
#include "upload.h"
#include "uploaddone.h"
#include "sys.h"
#include "top.h"
#include "left.h"
#include "postdemo.h"
#include "get.h"
#if TRANSIT_WEB_TIMEOUT	
#include "duplicate.h"
#endif
#include "config.h"
#include "default.h"
#include "manage.h"
#include "status.h"

const struct {
    char *name;
    const uchar *file_ptr;
    ushort len;
    file_type_t type; /* DYNAMIC:    contains variable data and needs processing 
                         STATIC:     contains static data, no processing needed
                         STATIC_SPC: contains static data, but must be password protected.
                         DYNAMIC_NOSPC: contains variable data, but needs no password
                      */
} file_dir [] = {
    (char *)"index.htm",     index_htm,               INDEX_SIZE,                 DYNAMIC_NOSPC,
    (char *)"400.htm",       http_status_400,         sizeof(http_status_400),    STATIC,
    (char *)"404.htm",       http_status_404,         sizeof(http_status_404),    STATIC,
    (char *)"501.htm",       http_status_501,         sizeof(http_status_501),    STATIC,
    (char *)"503.htm",       http_status_503,         sizeof(http_status_503),    STATIC,
/*
    (char *)"password.htm",  password_htm,            PASSWORD_SIZE,              STATIC,
*/
#if TRANSIT_WEB_TIMEOUT
    (char *)"duplicate",     duplicate_htm,           DUPLICATE_SIZE,             STATIC,
#endif
		(char *)"left.htm",      left_htm,                LEFT_SIZE,                  STATIC,
		(char *)"top.htm",       top_htm,                 TOP_SIZE,                   DYNAMIC_NOSPC,
		(char *)"bg.gif",      	 bg_gif,                  BG_SIZE,                    STATIC,
/*
(char *)"pwconfirm",     passwordConfirmation_htm,PASSWORDCONFIRMATION_SIZE,  STATIC, 
*/
		(char *)"sys",           sys_htm,                 SYS_SIZE,                   DYNAMIC,
/*    
                (char *)"postdemo",      postdemo_htm,            POSTDEMO_SIZE,              DYNAMIC,
               (char *)"get",           get_htm,                 GET_SIZE,                   STATIC_SPC,
*/
              (char *)"upload",        upload_htm,              UPLOAD_SIZE,                STATIC_SPC,
		(char *)"uploaddone",    uploaddone_htm,          UPLOADDONE_SIZE,            DYNAMIC,
		(char *)"config",    config_htm,          CONFIG_SIZE,            DYNAMIC,
		(char *)"default.css",  default_css,    DEFAULT_SIZE,     STATIC,
		(char *)"manage",   manage_htm,   MANAGE_SIZE,     STATIC,
		(char *)"status",      status_htm,    STATUS_SIZE,     DYNAMIC,
 
};

