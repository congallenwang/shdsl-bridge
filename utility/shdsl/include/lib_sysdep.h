/******************************************************************************

                               Copyright (c) 2005
                            Infineon Technologies AG
                  St. Martin Strasse 53; 81669 Munich, Germany

  THE DELIVERY OF THIS SOFTWARE AS WELL AS THE HEREBY GRANTED NON-EXCLUSIVE, 
  WORLDWIDE LICENSE TO USE, COPY, MODIFY, DISTRIBUTE AND SUBLICENSE THIS 
  SOFTWARE IS FREE OF CHARGE.

  THE LICENSED SOFTWARE IS PROVIDED "AS IS" AND INFINEON EXPRESSLY DISCLAIMS 
  ALL REPRESENTATIONS AND WARRANTIES, WHETHER EXPRESS OR IMPLIED, INCLUDING 
  WITHOUT LIMITATION, WARRANTIES OR REPRESENTATIONS OF WORKMANSHIP, 
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, DURABILITY, THAT THE 
  OPERATING OF THE LICENSED SOFTWARE WILL BE ERROR FREE OR FREE OF ANY THIRD 
  PARTY CLAIMS, INCLUDING WITHOUT LIMITATION CLAIMS OF THIRD PARTY INTELLECTUAL 
  PROPERTY INFRINGEMENT. 

  EXCEPT FOR ANY LIABILITY DUE TO WILLFUL ACTS OR GROSS NEGLIGENCE AND EXCEPT 
  FOR ANY PERSONAL INJURY INFINEON SHALL IN NO EVENT BE LIABLE FOR ANY CLAIM 
  OR DAMAGES OF ANY KIND, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
  DEALINGS IN THE SOFTWARE.

******************************************************************************/

/** \file
   Handle system dependencies.

   Supported environments:
      - U-Boot (Bootloader on MPC8xx) (UBOOT define)
      - Linux
*/

#ifndef _lib_sysdep_h
#define _lib_sysdep_h

#ifndef __PACKED__
#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#define __PACKED__ __attribute__ ((packed))
#elif defined(__C166_)
/* Keil C16x compiler (FIXME)*/
#pragma REENTRANT
#define __PACKED__ /* nothing */
#else
#define __PACKED__ /* nothing */
#endif
#endif /* __PACKED__ */

#define UNUSED_PARAM(x) (x)=(x)

#define DBG_LEVEL_OFF               4
#define DBG_LEVEL_HIGH              3
#define DBG_LEVEL_NORMAL            2
#define DBG_LEVEL_LOW               1

//allen
#define UBOOT
#define DEBUG



#ifdef DEBUG
   #define LOG_DRV_DBG_LEVEL           DBG_LEVEL_NORMAL

   /* SOC4E EvalBoard Driver */
   #define SOC4E_EB_DRV_DBG_LEVEL      DBG_LEVEL_HIGH
   /* FPGA HDLC Driver */
   #define HDLC_FPGA_DRV_DBG_LEVEL     DBG_LEVEL_HIGH
   /* SOC4E Chip Driver */
   #define PEF24624_DRV_DBG_LEVEL      DBG_LEVEL_NORMAL
   /* SOC4E Library */
   #define PEF24624_LIB_DBG_LEVEL      DBG_LEVEL_NORMAL

   /* currently ignore name */
   //#define LOG(name,level,message)     do { if (level >= LOG_DRV_DBG_LEVEL) PRINTF message; } while(0)
   #define LOG(name,level,message)	do { rt_kprintf message; } while(0)
   //#define TRACE(name,level,message)   do { if (level >= name ## _DBG_LEVEL) PRINTF message; } while(0)
   #define TRACE(name,level,message)	do { rt_kprintf message; } while(0)
#else
   #define LOG(name,level,message)     do { /* empty !! */ } while(0)
   #define TRACE(name,level,message)   do { /* empty !! */ } while(0)
#endif


#ifdef UBOOT
   /* just to disable a warning from the u-boot headers: */
   extern unsigned int cpu_to_le32p ( unsigned int *p);
   //#include <exports.h>

   /* to get the system dependent definition of __BIG_ENDIAN or __LITTLE_ENDIAN */
   //#include <asm/byteorder.h>
   #ifdef __BIG_ENDIAN
      #define ENDIAN_BIG
   #endif
   #ifdef __LITTLE_ENDIAN
      #define ENDIAN_LITTLE
   #endif

//allen
   #define ENDIAN_LITTLE

   #define MAINARGS                    int argc, char *argv[]

   #define PRINTF                      rt_kprintf
   #define GETCHAR                     getc

   #define GETTIME                     get_timer
   //#define WAIT                        udelay
   //#define WAIT   Delay_100us
   #define WAIT(x) delay(x/100)
   #define MALLOC                      malloc

   #define DO_RESET()                  do_reset()

   /* type of interrupt handler function */
   #define INTERRUPT_HANDLER_T         interrupt_handler_t
   /* register an interrupt handler */
   #define INSTALL_HDLR                install_hdlr
   /* release an interrupt handler */
   #define FREE_HDLR                   free_hdlr

   /** macro for bit manipulation of registers */
   #define BFLD(var, mask, val)        ((var)=((var) & ~(mask)) | ((val)&(mask)))

   /* define empty for non C166 */
   #define HUGE

   /** Do inline functions. */
   #define INLINE                      inline
   /** Define functions only local. */
   #define LOCAL                       static

   /** memcpy is part of the uboot-lib */
   #define HAVE_MEMCPY
   /** memset is part of the uboot-lib */
   #define HAVE_MEMSET

#endif /* UBOOT */

#ifdef LINUX
   #include <stdio.h>
   /* usleep */
   #include <unistd.h>
   
   #if __BYTE_ORDER == __BIG_ENDIAN
      #define ENDIAN_BIG
   #else      
      #define ENDIAN_LITTLE
   #endif

   #define MAINARGS                    int argc, char *argv[]

   #define PRINTF                      rt_kprintf
   #define GETCHAR                     getchar

   //extern int get_timer(int oops);
   
   #define GETTIME                     get_timer
   #define WAIT                        usleep
   #define MALLOC                      malloc

   #define DO_RESET()                  exit(0)

   /* type of interrupt handler function */
   #define INTERRUPT_HANDLER_T         interrupt_handler_t
   /* register an interrupt handler */
   #define INSTALL_HDLR                install_hdlr
   /* release an interrupt handler */
   #define FREE_HDLR                   free_hdlr

   /** macro for bit manipulation of registers */
   #define BFLD(var, mask, val)        ((var)=((var) & ~(mask)) | ((val)&(mask)))

   /* define empty for non C166 */
   #define HUGE

   /** Do inline functions. */
   #define INLINE                      inline
   /** Define functions only local. */
   #define LOCAL                       static

   extern int tstc(void);
   extern void echo_off(void);
   extern void echo_on(void);
   extern void set_keypress(void);
   extern void reset_keypress(void);
   
   /** memcpy is part of the c-lib */
   #define HAVE_MEMCPY
   /** memset is part of the c-lib */
   #define HAVE_MEMSET
   
#endif  /* LINUX */




#define SWAP_UINT32(x)  ( (((x) & 0xFF000000)>>24)  \
                        | (((x) & 0x00FF0000)>>8)   \
                        | (((x) & 0x0000FF00)<<8)   \
                        | (((x) & 0x000000FF)<<24))
#define SWAP_UINT16(x)  ( (((x) & 0xFF00)>>8) | (((x) & 0x00FF)<<8) )

#ifndef _BIG_ENDIAN
   /* define the endianess (if not supported by the compiler) */
   /** big endian host system (MPC, MIPSEB) */
   #define _BIG_ENDIAN                 1
   /** little endian system (C16x, i386, XScale, MIPSEL) */
   #define _LITTLE_ENDIAN              2
#endif

//allen
#define ENDIAN_LITTLE
#define HAVE_MEMCPY
#define HAVE_MEMSET

#if defined(ENDIAN_BIG)
   #define _BYTE_ORDER                 _BIG_ENDIAN
   #define CPU_TO_LE16(val)            SWAP_UINT16(val)
   #define LE16_TO_CPU(val)            SWAP_UINT16(val)
   #define CPU_TO_LE32(val)            SWAP_UINT32(val)
   #define LE32_TO_CPU(val)            SWAP_UINT32(val)
#elif defined(ENDIAN_LITTLE)
   #define _BYTE_ORDER                 _LITTLE_ENDIAN
   #define CPU_TO_LE16(val)            (val)
   #define LE16_TO_CPU(val)            (val)
   #define CPU_TO_LE32(val)            (val)
   #define LE32_TO_CPU(val)            (val)
#else
   #error Please define endianess of your system (ENDIAN_BIG / ENDIAN_LITTLE)
#endif


/* standard typedefs */
typedef void                        VOID;
typedef enum {FALSE, TRUE}          BOOL;

typedef char                        CHAR;
typedef signed char                 INT8;
typedef unsigned char               UINT8;
typedef signed char volatile        VINT8;
typedef unsigned char volatile      VUINT8;

typedef signed short                INT16;
typedef unsigned short              UINT16;
typedef signed short volatile       VINT16;
typedef unsigned short volatile     VUINT16;
typedef signed int                  INT32;
typedef unsigned int                UINT32;
typedef signed int volatile         VINT32;
typedef unsigned int volatile       VUINT32;

typedef char*                       LPSTR;
typedef const char*                 LPCSTR;

#ifndef HAVE_MEMCPY
extern void * memcpy(void * dst, void const * src, unsigned int len);
#endif

#ifndef HAVE_MEMSET
extern void * memset(void * dst, int c, unsigned int len);
#endif


#include "prj_config.h"

/* some definitions dependent on the project config */

#ifndef INCLUDE_MWIRE
   #if INCLUDE_TERMINAL == 1
   #define INCLUDE_MWIRE   1
   #else
   #define INCLUDE_MWIRE   0
   #endif
#endif /* INCLUDE_MWIRE */

#ifdef UBOOT
/* include the noOS stuff */
extern int  No_OS_Open  (char* path, int flags);
extern int  No_OS_Close (int fd);
extern int  No_OS_Ioctl (int fd, unsigned int cmd, unsigned int arg);
extern int  test(char* buffer,int lenth);
extern int  No_OS_Read(int fd, char* buffer, int length);
extern int  No_OS_Write(int fd, char* buffer, int length);

#define open(a,b)                   No_OS_Open((a), (b))
#define close(a)                    No_OS_Close((a))
#define ioctl(a,b,c)                No_OS_Ioctl((a), (b), (c))
#define read(a,b,c)                 No_OS_Read((a), (b), (c))
#define write(a,b,c)                No_OS_Write((a), (b), (c))

#define _IO(magic, nr)             ((magic << 8) | nr)

/* include the driver stuff */
extern int Pef24628e_DevCreate(void);
extern int Pef24628e_DevDelete(void);
extern int easy24644_DevCreate(void);
extern int easy24644_DevDelete(void);

#endif

#ifdef LINUX
#include <fcntl.h>      /* open */ 
#include <unistd.h>     /* exit */
#include <sys/ioctl.h>  /* ioctl */
#endif

#endif /* _lib_sysdep_h */

