/* Note, this file is not compiled directly, but include by uip/fs.c */
#include "common.h"
#include "webpost.h"

const struct {
    char       *func_name;
    post_func_t func_ptr;
} func_dir [] = {
    (char *)"pass",      web_password_func,
    (char *)"led",       web_led_func,
    (char *)"select",		 web_select_func,
    (char *)"text",      web_text_func,
    (char *)"check",     web_check_func,
    (char *)"radio",     web_radio_func,
    (char *)"file",         web_upload_func_done,
#if TRANSIT_WEB_TIMEOUT
    (char *)"logout",    web_logout_func,
#endif    
    (char*)"config",    web_dslconfig_func,
};
