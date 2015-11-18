/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH
                     Am Campeon 3; 85579 Neubiberg, Germany

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

/**
   \file
   This file contains the defines, the structures declarations
                 the tables declarations and the global functions declarations.
   \remark
   Use compiler switch ENABLE_TRACE for trace output, for debugging purposes.
   Compiler switch for OS is needed. Use LINUX for linux and VXWORKS for
   VxWorks..
*/

#ifndef _DRV_API_H_PEF24628E
#define _DRV_API_H_PEF24628E

/* ============================= */
/* Global Defines                */
/* ============================= */

#if !defined(NO_OS) && !defined(EXCLUDE_SCC_HDLC)
   /** include SCC HDLC support */
   #define INCLUDE_SCC_HDLC
#endif

/** include MPI support */
#define INCLUDE_MPI

#if !defined(INCLUDE_SCC_HDLC) && !defined(INCLUDE_MPI)
   #error One of the interfaces should be supported (MPI or SCI)
#endif

/* Traces */
/** enable traces */
#define ENABLE_TRACE
#define ENABLE_LOG

#if defined(VXWORKS) && defined(GENERIC_OS) && !defined(DONT_USE_XAPI_TRACE) && !(defined(LINUX) && !defined(__KERNEL__))
    /** common prefix for logging */
    #define _LOGGING_PREFIX __FILE__, __LINE__,
    #define  DSL_ASB_DRV_SHORT_NAME "DSLD"
#else
    /** common prefix for logging */
    #define _LOGGING_PREFIX
#endif

#ifdef LINUX
#define LOCAL                       static
#endif

/* ============================= */
/* includes                      */
/* ============================= */

#include "sys_drv_defs.h"
#include "sys_drv_debug.h"
//#include "lib_sysdep.h"
#include "ifx_types.h"
#include "sys_drv_ifxos.h"

/* return values */

#ifndef OK
/** return value on success */
#define OK      0
#endif

#ifndef ERROR
/** return value on failure */
#define ERROR  (-1)
#endif

#endif /* _DRV_API_H_PEF24628E */
