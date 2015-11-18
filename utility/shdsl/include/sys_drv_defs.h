/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/
/****************************************************************************
   Module      : sys_drv_defs.h
   Date        : 2004-07-12
   Description : This file contains definitions of some basic type definitions.
*******************************************************************************/

#ifndef _SYS_DRV_DEFS_H
#define _SYS_DRV_DEFS_H

/* ============================= */
/* Global Defines                */
/* ============================= */

#if defined (__GNUC__) || defined (__GNUG__)
/* GNU C or C++ compiler */
#undef __PACKED__
#define __PACKED__ __attribute__ ((packed))
#elif !defined (__PACKED__)
#define __PACKED__ /* nothing */
#endif

#ifndef VXWORKS
#define LOCAL                    static
#define IMPORT                   extern
#endif /* VXWORKS */

#ifndef PUBLIC
#define PUBLIC                   extern
#endif

#ifndef SUCCESS
#define SUCCESS                  0
#endif

#ifndef ERR
#define ERR                      -1
#endif

#ifndef NULL
#define NULL                      0
#endif

/* typedefs */
typedef unsigned char            BYTE;
typedef char                     CHAR;
typedef int                      INT;
typedef float                    FLOAT;
typedef short                    SHORT;

#ifndef WIN32
/* WORD must be 16 bit */
typedef unsigned short           WORD;
/* WORD must be 32 bit */
typedef unsigned long            DWORD;
#endif /* WIN32 */

#ifndef VXWORKS
typedef unsigned int             UINT;
#ifndef WIN32
/* DWORD must be 32 bit */
typedef unsigned int             UINT32;
#endif /* WIN32 */
#endif /* VXWORKS */


#ifndef VXWORKS
#ifndef WIN32
typedef void                     VOID;
#endif

typedef unsigned char            UCHAR;

typedef signed char              INT8;
typedef unsigned char            UINT8;
typedef signed short             INT16;
typedef unsigned short           UINT16;
#ifndef WIN32
typedef signed int               INT32;
#endif /* WIN32 */
typedef volatile INT8            VINT8;
typedef volatile UINT8           VUINT8;
typedef volatile INT16           VINT16;
typedef volatile UINT16          VUINT16;
#ifndef WIN32
typedef volatile INT32           VINT32;
typedef volatile UINT32          VUINT32;

typedef INT                      (*FUNCPTR)     (VOID);
typedef VOID                     (*VOIDFUNCPTR) (VOID);
#endif


#endif /* VXWORKS */

#ifndef basic_types
#define basic_types
typedef signed char              int8;
typedef unsigned char            uint8;
typedef signed short             int16;
typedef unsigned short           uint16;
typedef signed int               int32;
typedef unsigned int             uint32;
#endif /* basic_types */

#ifdef NEED_64BIT_TYPES
#ifndef WIN32
typedef signed long long         INT64;
typedef unsigned long long       UINT64;
#endif /* WIN32 */

#ifndef WIN32
typedef signed long long         int64;
typedef unsigned long long       uint64;
#endif
#endif

#ifndef __cplusplus
typedef enum {false, true} bool;
#endif

#if !(defined VXWORKS) && !(defined WIN32)
#ifndef BOOL
#ifdef FALSE
#undef FALSE
#endif /* FALSE */
#ifdef TRUE
#undef TRUE
#endif /* TRUE */
//typedef enum {FALSE,TRUE}  BOOL;
#endif /* BOOL */
#endif /* !(defined VXWORKS) && !(defined WIN32) */

#ifndef _MKSTR_1
#define _MKSTR_1(x)    #x
#define _MKSTR(x)      _MKSTR_1(x)
#endif

#endif /* _SYS_DRV_DEFS_H */

