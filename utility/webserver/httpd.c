/*
@project name: web server for cosmos
@system:       nOS with uIP1.0	
@bug:          zhoukesec@163.com, QQ 9482145
@date:         2013-03-20
*/

#include "uip.h"
#include "fs.h"
#include "httpd.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

//#include "misc1.h"
#include "webhnd.h"
#include "webpost.h"

static void http_process_init (void);
static void http_process (void);
static void build_status_code (uchar status_code, struct httpd_state  *hs);

#ifndef NULL
#define NULL (void *)0
#endif

/* The HTTP server states: */
#define HTTP_METHOD         0
#define HTTP_URI            1
#define HTTP_VERSION        2
#define HTTP_HEADER         3
#define HTTP_BODY           4
#define HTTP_BOUNDARY       5
#define HTTP_MULTI_HEADER   6
#define HTTP_UPLOAD_CONTENT 7
#define HTTP_END            8

 

struct httpd_state  *hs;


static const char content_length_text []      = "Content-Length: ";
static const char content_type_upload_text [] = "CONTENT-TYPE: MULTIPART/FORM-DATA; BOUNDARY=";
static const char content_type_appl_text []   = "CONTENT-TYPE: APPLICATION/OCTET-STREAM";
static const char content_type_text_text []   = "CONTENT-TYPE: TEXT/PLAIN";
static const char content_filename_text []   = "filename=";


#define CONTENT_LENGTH_TEXT_LEN      (sizeof(content_length_text) - 1)
#define CONTENT_TYPE_UPLOAD_TEXT_LEN (sizeof(content_type_upload_text) - 1)
#define CONTENT_TYPE_APPL_TEXT_LEN   (sizeof(content_type_appl_text) - 1)
#define CONTENT_TYPE_TEXT_TEXT_LEN   (sizeof(content_type_text_text) - 1)
#define CONTENT_FILENAME_TEXT_LEN   (sizeof(content_filename_text) - 1)


#define ISO_G        0x47
#define ISO_E        0x45
#define ISO_T        0x54
#define ISO_P        0x50
#define ISO_O        0x4F
#define ISO_S        0x53

#define ISO_slash    0x2f    
#define ISO_c        0x63
#define ISO_g        0x67
#define ISO_i        0x69
#define ISO_space    0x20
#define ISO_nl       0x0a
#define ISO_cr       0x0d
#define ISO_a        0x61
#define ISO_t        0x74
#define ISO_hash     0x23
#define ISO_period   0x2e


/* error status codes */
#define BAD_REQUEST_400     0
#define NOT_FOUND_404       1
#define NOT_IMPLEMENTED_501 2



//allen
typedef struct{
    int flag;
    int imgsize;
}IMG_INFO;


uchar boundary_buf [MAX_BOUNDARY_LEN];
uchar body_buf [MAX_BODY_LEN + 4];
uchar file_buff[4096];
uchar g_filedownload=0;
int g_filelen;
extern ulong upload_file_length;
int g_totalpage;
unsigned char g_filetype;


IMG_INFO g_imginfo;

void rt_burnapp(unsigned char* buf, unsigned int pos, unsigned char filetype);
void save_file()
{
	int i;
	static int j=0;
	if(g_filedownload)
	{
		//for(i=0;i<upload_file_length;i++,j++)
		{			
			//rt_kprintf("%02X ",file_buff[i]);
			//if(j%16 == 15)
				//rt_kprintf("\r\n");
		}
	}
	else
		j=0;
	//upload_file_length=0;
}


/*-----------------------------------------------------------------------------------*/
/**
 * Initialize the web server.
 *
 * Starts to listen for incoming connection requests on TCP port 80.
 */
/*-----------------------------------------------------------------------------------*/
void
httpd_init(void)
{
  fs_init();
  
  /* Listen to port 80. */
  uip_listen(HTONS(80));
}
/*-----------------------------------------------------------------------------------*/
void
httpd_appcall(void)
{
    ushort j;
	int i;
    post_func_t post_func;

    //rt_kprintf("httpd_appcall,flag=%d\r\n",uip_flags);
#if 1	
    switch(uip_conn->lport) {
        /* This is the web server: */
    case HTONS(80):
        /* Pick out the application state from the uip_conn structure. */
        hs = (struct httpd_state *)(uip_conn->appstate);

        /* We use the uip_ test functions to deduce why we were
           called. If uip_connected() is non-zero, we were called
           because a remote host has connected to us. If
           uip_newdata() is non-zero, we were called because the
           remote host has sent us new data, and if uip_acked() is
           non-zero, the remote host has acknowledged the data we
           previously sent to it. */
        if(uip_connected()) {
            /* Since we have just been connected with the remote host, we
               reset the state for this connection. The ->count variable
               contains the amount of data that is yet to be sent to the
               remote host, and the ->state is set to HTTP_METHOD to signal
               that we haven't received any request for this
               connection yet. */
            http_process_init();
            return;

        } else if(uip_poll()) {
            /* If we are polled ten times, we abort the connection. This is
               because we don't want connections lingering indefinately in
               the system. */
            if(hs->count++ >= 10) {
                uip_abort();
            }
            return;

        } else if(uip_newdata()) {

            /*
            ** Process new data received.
            */
            //rt_kprintf("http_process\r\n");
            http_process();
	     //allen
            //save_file();	
			
            if (hs->state == HTTP_END) {
		  if(g_filedownload)
		  {
			 rt_kprintf("\r\nfile load finished<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\r\n");		
			  g_filedownload = 0;
			  if(upload_file_length != 0)
			  {
					//memset(&file_buff[upload_file_length],0xFF,4096-upload_file_length);
					i=upload_file_length;
					while(i<4096)
						file_buff[i++]=0xff;
					rt_burnapp(file_buff,g_totalpage,g_filetype);
			  }
			  //write config block for app image
			  if(1==g_filetype)
			  {
                               rt_kprintf("\r\nflash image information\r\n");		  
                               g_imginfo.flag = 1;
        			   g_imginfo.imgsize=g_totalpage*4096+upload_file_length;
                               memset(file_buff,0xFF,4096);
                               memcpy(file_buff,&g_imginfo,sizeof(g_imginfo));
                               rt_burnapp(file_buff,0,5);
			  }
              }
                /*
                ** Find file/data to send
                */
                //rt_kprintf("hs->state == HTTP_END \r\n");
                if ((hs->http.uri_len == 0) || hs->http.error) {
                    build_status_code(BAD_REQUEST_400, hs);
                }
                else {

                    hs->http.uri[hs->http.uri_len] = '\0';

                    /*
                    ** If Get method and uri holds a '?' then convert it to a 
                    ** post method (GET /func?name=value)
                    */
                    if (hs->http.method == ISO_G) {
                        for (j = 0; j < hs->http.uri_len; j++) {
                            if (hs->http.uri[j] == '?') {
                                hs->http.uri[j] = '\0';
                                hs->http.method = ISO_P;
                                hs->http.body_i = 0;
                                while (++j < hs->http.uri_len) {
                                    body_buf[hs->http.body_i++] = hs->http.uri[j];
                                }
                                body_buf[hs->http.body_i] = '\0';
                                hs->http.body_len = hs->http.body_i;
                            }
                        }
                    }

                    /*
                    ** Handle actual method, GET or POST
                    */
                    switch (hs->http.method) {
                    case ISO_G:
 

                        /* Check for a request for "/". */
                        if (hs->http.uri[0] == ISO_slash && hs->http.uri_len == 1) {
                            web_select_page("index", hs);
                        } else {
                            web_select_page((const char *) &hs->http.uri[1], hs);
                        } 

                        break;
                    case ISO_P:

                        if (hs->http.body_len == 0) {
                            build_status_code(BAD_REQUEST_400, hs);
                        }
                        else {
                            post_func = fs_post_func((const char *) &hs->http.uri[1]);
                            if (post_func != 0) {                              
                                (*post_func)(hs);                                
                            }
                            else {                                
                                build_status_code(NOT_FOUND_404, hs);
                            }
                        }                    
                        break;
                    default:
                        /* If it isn't a GET or a POST, we send a 501 status. */
                        build_status_code(NOT_IMPLEMENTED_501, hs);
                        break;
                    }
                }
            }
        }

        /*
        ** Check for any close events.
        */
        if (uip_closed() || uip_aborted() || uip_timedout()) {
	     //rt_kprintf("\r\n http_process_init \r\n");
            web_send_complete(hs);
            http_process_init();
        }
        else {
            if (hs->state == HTTP_END) {
                /* Check if the client (remote end) has acknowledged any data that
                   we've previously sent. If so, we move the file pointer further
                   into the file and send back more data. If we are out of data to
                   send, we close the connection. */
		//rt_kprintf("hs->state == HTTP_END 1 \r\n");
		if(uip_acked()) {
                    if(hs->count >= uip_conn->len) {
                        hs->count -= uip_conn->len;
                        hs->dataptr += uip_conn->len;
                    } else {
                        hs->count = 0;
                    }

                    if ((hs->file.type >= DYNAMIC) && (hs->count == 0)) {
                        // build next chunk if any
			  //rt_kprintf("2\r\n");	  
			   web_build_dyn(hs, WEB_DYN_PAGE_CONTINUE);
                    }
                
                    if(hs->count == 0) {
                        uip_close();
                        web_send_complete(hs);
                    }
                }
                else if (uip_rexmit() && (hs->file.type >= DYNAMIC)) {
                    // rebuild chunk
                    web_build_dyn(hs, WEB_DYN_PAGE_REPEAT);

                }

                /* Send a piece of data, but not more than the MSS of the
                   connection. */
                //rt_kprintf("3 \r\n");   
                uip_send(hs->dataptr, hs->count);
 		  //rt_kprintf("4 \r\n");   
            }
        }

        /* Finally, return to uIP. Our outgoing packet will soon be on its
           way... */
        return;
        
    default:
        /* Should never happen. */
        uip_abort();
        break;
    }  
#endif
}

 
/* ************************************************************************ */
uchar http_search_body (const char *name_ptr, char *value_ptr, uchar bufsiz)
/* ------------------------------------------------------------------------ --
 * Purpose     : Search post body buffer for a specified parameter.
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{    
    uchar name_len;
     char  *body_ptr;
    ushort remainder;
    uchar done;

    name_len = strlen(name_ptr);
    body_ptr = body_buf;
    remainder = hs->http.body_len;

    while (remainder != 0) {
        if (*body_ptr == *name_ptr) {
            if (strncmp(body_ptr, name_ptr, name_len) == 0) {
                if (*(body_ptr + name_len) == '=') {
                    body_ptr += (name_len + 1);
                    break;
                }
            }
        }
        body_ptr++;
        remainder--;
    }

    if (remainder == 0) {
        return 0;
    }

    /*
    ** Retrieve value (in ASCII) and convert any escape sequence
    */
    done = 0;
    while (!done) {
        switch (*body_ptr) {
        case '\r':
        case '&':
        case '\0':
            done = 1;
            break;
        case '%':
            /* Convert %nn from ascii hex to binary */
            *value_ptr = ascii_to_hex_nib(*(body_ptr + 1)) << 4 | 
                ascii_to_hex_nib(*(body_ptr + 2));
            value_ptr++;
            body_ptr += 3;
            break;
        case '+':
            *value_ptr = ' ';
            value_ptr++;
            body_ptr++;
            break;
        default:
            *value_ptr = *body_ptr;
            value_ptr++;
            body_ptr++;
            break;
        }
        if (--bufsiz == 1) {
/*            print_txt(TXT_NO_HTTP_WARNING_BAD_WAR);
            print_str(name_ptr);
            print_cr_lf();
*/
            break;
        }
    }
    *value_ptr = '\0';
    return 1;
}

/* ************************************************************************ */
static void build_status_code (uchar status_code, struct httpd_state  *hs)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    switch (status_code) {
    case BAD_REQUEST_400:
        (void) fs_open("400", &hs->file);
        break;
    case NOT_FOUND_404:
        (void) fs_open("404", &hs->file);
        break;
    case NOT_IMPLEMENTED_501:
        (void) fs_open("501", &hs->file);
        break;
    default:
        (void) fs_open("400", &hs->file);
        break;
    }

    hs->dataptr = (char *)hs->file.dat;
    hs->count   = hs->file.len;	
}

/* ************************************************************************ */
static void http_process_init (void)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    hs->state = HTTP_METHOD;
    hs->count = 0;

    hs->http.method = 0;
    hs->http.prev_ch = 0;
    hs->http.expect_iso_nl = 0;
    hs->http.boundary_len = 0;
    hs->http.boundary_match = 0;
    hs->http.body_len = 0;
    hs->http.body_i = 0;
    hs->http.uri_len = 0;

    hs->http.content_len_match = 0;
    hs->http.content_type_match = 0;
    hs->http.content_type_appl_match = 0;
    //allen
    hs->http.filename_match = 0;

    hs->http.error = 0;
}

/* ************************************************************************ */
unsigned char g_name[30];
static void http_process (void)
/* ------------------------------------------------------------------------ --
 * Purpose     :
 * Remarks     :
 * Restrictions:
 * See also    :
 * Example     :
 * ************************************************************************ */
{
    ushort remainder;
    uchar  *dat;
    uchar ch;
    uchar ch_ref;
    int j;

    dat = uip_appdata;
    remainder = uip_len;

#if 1
    //rt_kprintf("%d\r\n",uip_len);
#endif
	
    while (remainder != 0) {

        ch = *dat;
        remainder--;
        if (hs->http.expect_iso_nl) {
            hs->http.expect_iso_nl = 0;
            if (ch != ISO_nl) {
                hs->http.error = 1;
                hs->state = HTTP_END;
            }
        }
        else {
            switch (hs->state) {

            case HTTP_METHOD:
                if (dat[0] == ISO_G && 
                    dat[1] == ISO_E && 
                    dat[2] == ISO_T &&
                    dat[3] == ISO_space) {
                    hs->http.method = ISO_G;
                    hs->state = HTTP_URI;
                    dat += 3;
                    remainder -= 3;
                }
                else if (dat[0] == ISO_P &&
                         dat[1] == ISO_O &&
                         dat[2] == ISO_S &&
                         dat[3] == ISO_T &&
                         dat[4] == ISO_space) {
                    hs->http.method = ISO_P;
                    hs->state = HTTP_URI;
                    dat += 4;
                    remainder -= 4;
                }
                else {
                    hs->http.method = 0;
                    hs->state = HTTP_END;
                }
                break;
            case HTTP_URI:
                if (ch == ISO_space) {
                    hs->state = HTTP_VERSION;
                }
                else if (ch == ISO_cr) {
                    hs->state = HTTP_END;
                }
                else {
                    if (hs->http.uri_len < MAX_URI_LEN) {
                        hs->http.uri[hs->http.uri_len] = ch;
                        hs->http.uri_len++;
                    }
                    else {
                        hs->http.error = 1;
                        hs->state = HTTP_END;
                    }
                }
                break;
            case HTTP_VERSION:
                /* skip version */
                if (ch == ISO_nl) {
                    hs->state = HTTP_HEADER;
                }
                break;
            case HTTP_HEADER:
                if (ch == ISO_cr && hs->http.prev_ch == ISO_nl) {
                    if (hs->http.method == ISO_P) {
                        if (hs->http.boundary_len != 0) {
                            hs->state = HTTP_BOUNDARY;
                            hs->http.boundary_match = 0;
                        }
                        else {
                            hs->state = HTTP_BODY;
                        }
                    }
                    else {
                        hs->state = HTTP_END;
                    }
                    hs->http.expect_iso_nl = 1;
                }
                else if (hs->http.method == ISO_P) {

                    if (ch == ISO_cr) {
                        hs->http.expect_iso_nl = 1;
                        hs->http.content_len_match = 0;
                        hs->http.content_type_match = 0;
                        if (hs->http.boundary_len) {
                            boundary_buf[hs->http.boundary_len]     = '-';
                            boundary_buf[hs->http.boundary_len + 1] = '-';
                        }
                    }
                    else {
                        if (hs->http.content_len_match == CONTENT_LENGTH_TEXT_LEN) {
                            if ((ch >= '0') && (ch <= '9')) {
                                hs->http.body_len = (hs->http.body_len * 10) + (ch - '0');
                            }
                            if (hs->http.body_len > MAX_BODY_LEN) {
                                hs->http.body_len = MAX_BODY_LEN;
                            }
                        }
                        else if (hs->http.content_type_match == CONTENT_TYPE_UPLOAD_TEXT_LEN) {
                            if (hs->http.boundary_len < MAX_BOUNDARY_LEN) {
                                boundary_buf[hs->http.boundary_len++] = ch;
                            }
                        }
                        else {
                            ch = conv_to_upper_case(ch);
                            /*
                            ** Check if "Content-Length: "
                            */
                            ch_ref = conv_to_upper_case(content_length_text[hs->http.content_len_match]);
                            if (ch == ch_ref) {
                                hs->http.content_len_match++;
                            }
                            else {
                                hs->http.content_len_match = 0;
                            }
                            /*
                            ** Check if "CONTENT-TYPE: MULTIPART/FORM-DATA: BOUNDARY=" 
                            */
                            ch_ref = conv_to_upper_case(content_type_upload_text[hs->http.content_type_match]);
                            if (ch == ch_ref || ch_ref == ';' || ch_ref == ' ') {
                                hs->http.content_type_match++;
                                if (hs->http.content_type_match == CONTENT_TYPE_UPLOAD_TEXT_LEN) {
                                    boundary_buf[0] = '-';
                                    boundary_buf[1] = '-';
                                    hs->http.boundary_len = 2;
                                }
                            }
                            else {
                                hs->http.content_type_match = 0;
                            }
                        }
                    }
                }
                break;
            case HTTP_BODY:
                if (ch == ISO_cr) {
                    hs->state = HTTP_END;
                    body_buf[hs->http.body_i] = '\0';
                }
                else {
                    if (hs->http.body_i < hs->http.body_len) {
                        body_buf[hs->http.body_i] = ch;
                        hs->http.body_i++;
                    }
                    if (hs->http.body_i >= hs->http.body_len) {
                        hs->state = HTTP_END;
                        body_buf[hs->http.body_i] = '\0';
                    }
                }
                break;
            case HTTP_BOUNDARY:
                if (hs->http.boundary_match < hs->http.boundary_len) {
                    if (ch == boundary_buf[hs->http.boundary_match]) {
                        hs->http.boundary_match++;
                    }
                    else {
                        hs->http.boundary_match = 0;
                    }
                }
                else {
                    if (ch == ISO_cr) {
                        hs->http.expect_iso_nl = 1;
                        hs->state = HTTP_MULTI_HEADER;
                    }
                }
                break;
            case HTTP_MULTI_HEADER:
                if (hs->http.content_type_appl_match < CONTENT_TYPE_APPL_TEXT_LEN) {
                    ch_ref = conv_to_upper_case(content_type_appl_text[hs->http.content_type_appl_match]);

                    if (conv_to_upper_case(ch) == ch_ref || ch_ref == ' ') {
                        hs->http.content_type_appl_match++;
                    }
                    else {
                        hs->http.content_type_appl_match = 0;
                    }
                }
		//allen: check upload file name
		if(hs->http.filename_match<CONTENT_FILENAME_TEXT_LEN)
		{
			//printf("%c",conv_to_upper_case(ch));
			ch_ref = conv_to_upper_case(content_filename_text[hs->http.filename_match]);
			if (conv_to_upper_case(ch) == ch_ref || ch_ref == ' ') 
			{
				hs->http.filename_match++;
				//printf("%c",conv_to_upper_case(ch));
			}
			else
			{
				hs->http.filename_match = 0;
				j=0;
			}
		}
		//matched
		else
		{
		       //printf("%c",ch);
			if(ch=='\"')
			{
				//check if the " is the end or the begin
				if(j!=0)
				{
					//set terminal \0 to the str
					g_name[j]='\0';
					j=-1;
				}
			}
			else
			{
				//if not end, cp the name into buffer
				if(j!=-1)
				{
					g_name[j]=ch;
					j++;
				}
			}
		}
							 
                if (ch == ISO_cr && hs->http.prev_ch == ISO_nl) {
                    //if (hs->http.content_type_appl_match == CONTENT_TYPE_APPL_TEXT_LEN) {
                        hs->state = HTTP_UPLOAD_CONTENT;
#ifdef FILE_UPDOWN_LOAD
			   if(strcmp(g_name,"rtthread.bin") == 0)
			   {
			   	rt_kprintf("update app file\r\n");
                        	web_upload_init(hs->http.uri);
			   	g_totalpage = 0;
				g_filetype =1;
			   }
			   else if(strcmp(g_name,"shdsl.bin") == 0)
			   {
			   	rt_kprintf("update shdsl fw\r\n");
                        	web_upload_init(hs->http.uri);
			   	g_totalpage = 0;
				g_filetype =2;
			   }
			   else if(strcmp(g_name,"IDC.bin") == 0)
			   {
			   	rt_kprintf("update IDC fw\r\n");
                        	web_upload_init(hs->http.uri);
			   	g_totalpage = 0;
				g_filetype =3;
			   }
                        else if(strcmp(g_name,"remedy.bin") == 0)
			   {
			   	rt_kprintf("update remedy file\r\n");
                        	web_upload_init(hs->http.uri);
			   	g_totalpage = 0;
				g_filetype =4;
			   }
			   else
			   {
			       rt_kprintf("file %s not recognized\r\n",g_name);
				g_filedownload = 0;
				g_filetype = 0xFF;
			   }
#endif /* FILE_UPDOWN_LOAD */
                    //}
                    //else {
                    //    hs->state = HTTP_BOUNDARY;
                    //}
                    hs->http.expect_iso_nl = 1;
                    hs->http.boundary_match = 0;
                }
                break;
            case HTTP_UPLOAD_CONTENT:
                if (hs->http.boundary_match < (hs->http.boundary_len + 2)) {
                    if (ch == boundary_buf[hs->http.boundary_match]) {
                        hs->http.boundary_match++;
                    }
                    else {
                        hs->http.boundary_match = 0;
                    }
                }
                else {
                    if (ch == ISO_cr) {
                        hs->state = HTTP_END;
			   upload_file_length = upload_file_length - (hs->http.boundary_len + 2 + 2);					
                        break;
                    }
                }

#ifdef FILE_UPDOWN_LOAD                
                //web_upload_continue(ch);
                if(g_filedownload != 0)
                {
			file_buff[upload_file_length]=ch;
			upload_file_length++;
			//update to flash when buff full
			if(upload_file_length == 4096)
			{
				rt_burnapp(file_buff,g_totalpage,g_filetype);
				g_totalpage++;
				upload_file_length=0;
			}
                }
#endif /* FILE_UPDOWN_LOAD */
                /* reset poll counter to avoid having a timeout while updating software! */
                hs->count = 0;
                break;
            case HTTP_END:
                break;
            default:
                break;
            }
        }

        hs->http.prev_ch = ch;
        dat++;
    }
}

/*-----------------------------------------------------------------------------------*/
/** @} */
/** @} */







