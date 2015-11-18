#ifndef SYS_DRV_NOOSLIB_H
#define SYS_DRV_NOOSLIB_H
/*******************************************************************************
       Copyright (c) 2000, Infineon Technologies.  All rights reserved.

                               No Warranty
   Because the program is licensed free of charge, there is no warranty for
   the program, to the extent permitted by applicable law.  Except when
   otherwise stated in writing the copyright holders and/or other parties
   provide the program "as is" without warranty of any kind, either
   expressed or implied, including, but not limited to, the implied
   warranties of merchantability and fitness for a particular purpose. The
   entire risk as to the quality and performance of the program is with
   you.  should the program prove defective, you assume the cost of all
   necessary servicing, repair or correction.

   In no event unless required by applicable law or agreed to in writing
   will any copyright holder, or any other party who may modify and/or
   redistribute the program as permitted above, be liable to you for
   damages, including any general, special, incidental or consequential
   damages arising out of the use or inability to use the program
   (including but not limited to loss of data or data being rendered
   inaccurate or losses sustained by you or third parties or a failure of
   the program to operate with any other programs), even if such holder or
   other party has been advised of the possibility of such damages.
********************************************************************************
   Module      : $RCSfile: sys_noOSLib.h,v $
   Date        : $Date: 2004/05/18 11:30:18 $
   Description : This file contains the declarations of library functions
                 like delay, timer, interrupt handler functions
   Remarks     :
      -  if the target driver also defines one of the user interface macros
         "open", "close", ..., for any reason,  -DDONT_USE_NO_OS_PROTOTYPES
         should be added to the compiler defines to avoid compiler errors
*******************************************************************************/
/** \file
    \brief No OS system interface library.
*/
/** \mainpage No OS system interface library.

    \section s_one 1) Overview
    The No OS system interface emulates a simple single task
    operating system for device drivers. The functions exported here import
    functions from OS and Hardware abstractions layers and provide the No OS
    driver/application programmer with following capabilities :

      - interrupt handling,
      - timers,
      - time/clock (wait milliseconds/microseconds),
      - event and semaphores handling,
      - user interface (open/close/ioctl/read/write),
      - driver registration/unregistration.

    Programmers attempting to use this library should make sure that :

      - the hardware abstraction layer functions are implemeted (sys_HAL_<uC>.c),
      - the micro operating system ( boot loader i.e) functions layer are implemented (sys_OS_AL_<uOS>.c),
      - that the (cross) compiler and linker used generate appropriate code for their machine,
      - they statically link the code towards standard libraries,
      - they use compiler switches for uC, Endianness and CPU Frequency
        (i.e -DPPC -DNO_OS_BIG_ENDIAN -DCPUFREQ=80),
      - they use appropriate linker options to generate an ELF file,
      - that the function No_OS_Init should be the entry point of the ELF-File.
      - the user code implements for his environment the functions
         - No_OS_InitBoard(),
         - No_OS_ShutdownBoard(),
         - usrApp().

    If the microprocessor used is the PowerPC and the micro system used UBOOT,
    a makefile used for Specific Vinetic/Geminax projects can be provided as a reference.

    The File sys_drv_noOS.h contains a set of global Macros mapped to some functions
    of this interface to assure the availability of driver source code for
    the No OS system.

    \section s_two 2) Microcontroler abstraction layer

    This abstraction layer exports needed hardware functions for
      - initialization,
      - timer management,
      - interrupt management.

    The interface macros and functions have to be implemented according to the
    used hardware. The adaptation for PowerPC is available and could be taken as
    example.

   \section s_three 3) Operating system abstraction layer.

    abstraction layer exports necessary operating system functions for
      - initialization,
      - interrupt handler installation and uninstallation.

    The interface functions have to be implemented according to the
    used boot loader. The adaptation for the bool loader Uboot is available
    and could be taken as reference.
*/

/* ============================= */
/* Includes                      */
/* ============================= */

/* Standard Library includes */
#include <assert.h>        /* Assertions */
#include <ctype.h>         /* Character identification */
#include <setjmp.h>        /* Non-local jump */
#include <float.h>         /* Max and Min values for floats */
#include <errno.h>         /* Error handling */
#include <limits.h>        /* limits for integral types */
/*#include <locale.h>*/    /* Internationalisation info */
#include <math.h>          /* Advanced math functions */
/*#include <signal.h>*/    /* Exception handling */
#include <stdarg.h>        /* Variable numbers of arguments */
#include <stddef.h>        /* Standard definitions */
#include <stdio.h>         /* Input/Output */
#include <stdlib.h>        /* General Utilities */
#include <string.h>        /* String Manipulation */
#include <time.h>          /* Date and Time functions */


#ifdef PPC
   #include "drv_mpc.h"
#endif /* PPC */

/* Local includes */
#include "sys_drv_defs.h"

/* ============================= */
/* Global defines and macros     */
/* ============================= */

/* fixed timeout defines  */
/** Timeout is infinite. */
#define WAIT_FOREVER                (-1)
/** Timeout is 0. */
#define NO_WAIT                     0
/** Maximun events number */
#define NO_OS_MAXEVT                50
/** Maximun supported drivers number. */
#define NO_OS_MAXDRIVERS            1
/** Maximum supported devices number. */
#define NO_OS_MAXDEVS               1

/* ============================= */
/* Global functions  macros      */
/* ============================= */

#ifndef DONT_USE_NO_OS_PROTOTYPES
/* User Interface mapped to No OS prototypes */
/* This mapping will be done to provide application code
   with common known open/close/read/write/ioctl interface */
#define open(a,b)                   No_OS_Open((a), (b))
#define close(a)                    No_OS_Close((a))
#define ioctl(a,b,c)                No_OS_Ioctl((a), (b), (c))
#define read(a,b,c)                 No_OS_Read((a), (b), (c))
#define write(a,b,c)                No_OS_Write((a), (b), (c))
#endif


/* ============================= */
/* Global typedefs               */
/* ============================= */

/* No OS driver interface types */
/** Driver open interface. */
typedef INT (* NO_OS_OPEN) (CHAR* path, INT flags);
/** Driver close interface. */
typedef INT (* NO_OS_CLOSE)(VOID* pPrivate);
/** Driver ioctl interface. */
typedef INT (* NO_OS_IOCTL)(VOID* pPrivate, UINT cmd, UINT arg);
/** Driver read interface. */
typedef INT (* NO_OS_READ) (VOID* pPrivate, CHAR* buf, INT len);
/** Driver write interface. */
typedef INT (* NO_OS_WRITE)(VOID* pPrivate, CHAR* buf, INT len);

/** No OS driver operations. */
typedef struct NO_OS_DRVOP
{
   NO_OS_OPEN  open;  /**<No OS open  method. */
   NO_OS_CLOSE close; /**<No OS close method. */
   NO_OS_IOCTL ioctl; /**<No OS ioctl method. */
   NO_OS_READ  read;  /**<No OS read  method. */
   NO_OS_WRITE write; /**<No OS write method. */
} No_OS_DrvOp;

/** No OS event type. */
typedef volatile INT*               NO_OS_EVENT;

/* ============================= */
/* Global variable declaration   */
/* ============================= */

/** No OS global errno variable. */
PUBLIC INT  No_OS_Errno;

/* ============================= */
/* Global functions  declaration */
/* ============================= */

/* Entry function for the user application code */
/** \fn PUBLIC INT usrApp (VOID)
    \brief Entry function the user application code.

    The user application functions will be triggered with this function.

    \b Example\b :
    \code
    #include "sys_noOSLib.h"
    #include "vinetic_io.h"
    #include "geminax_io.h"

    INT usrApp ()
    {
      INT nRet;

      nRet = VineticInit ();
      if (nRet == SUCCESS)
         nRet = GeminaxInit ();
      if (nRet == SUCCESS)
         nRet = VineticDoTests ();
      if (nRet == SUCCESS)
         nRet = GeminaxDoTests ();

      return nRet;
    }
    \endcode
    \remark
       The user application should implement this function.
*/
PUBLIC INT usrApp       (VOID);

/** \fn PUBLIC INT No_OS_InitBoard (VOID)
    \brief Plattform specific hardware/software initialization.

    This function installs the driver, initializes the chip selects and the CPLD
    for example. It should be implemented by the driver.
*/
PUBLIC INT No_OS_InitBoard       (VOID);

/** \fn PUBLIC INT No_OS_ShutdownBoard (VOID)
    \brief Plattform specific hardware/sofware shutdown.

    This function does the reverse job of No_OS_InitBoard() and should be
    implemented by the driver.
*/
PUBLIC INT No_OS_ShutdownBoard   (VOID);

/* No OS init installs the "NO_OS" OS */
PUBLIC VOID No_OS_Init  (VOID);

/* Hardware base address */
PUBLIC UINT No_OS_GetHwBaseAddr       (VOID);

/* interrupt related functions. */
PUBLIC INT  No_OS_InstallIntHandler   (INT irq, VOID(*handler)(INT), INT data);
PUBLIC VOID No_OS_UninstallIntHandler (INT irq);
PUBLIC INT  No_OS_IntEnable           (INT irq);
PUBLIC VOID No_OS_IntDisable          (INT irq);
PUBLIC INT  No_OS_LockInt             (VOID);
PUBLIC VOID No_OS_UnlockInt           (INT lock);

/* Timer related functions. */
PUBLIC INT  No_OS_CreateTimer (UINT nTimeout, VOID (*timerfunc)(INT), INT data);
PUBLIC INT  No_OS_StartTimer  (INT nTimerId);
PUBLIC INT  No_OS_StopTimer   (INT nTimerId);
PUBLIC INT  No_OS_ModifyTimer (INT nTimerId, UINT nNewTimeout);
PUBLIC VOID No_OS_DeleteTimer (INT nTimerId);
PUBLIC VOID No_OS_ReschedTimer(INT nTimerId);

/* Event handling */
PUBLIC VOID No_OS_InitEvent   (NO_OS_EVENT *event, BOOL bState);
PUBLIC VOID No_OS_DeleteEvent (NO_OS_EVENT *event);
PUBLIC BOOL No_OS_WaitEvent   (NO_OS_EVENT event, BOOL bCond, UINT nTimeout);
PUBLIC VOID No_OS_WakeupEvent (NO_OS_EVENT event);
PUBLIC INT  No_OS_SleepOnEvent(NO_OS_EVENT event, INT nTimeout);

/* Time/Clock functions */
PUBLIC VOID No_OS_Wait_us    (UINT u_sec);
PUBLIC VOID No_OS_Wait_ms    (UINT m_sec);
PUBLIC VOID No_OS_Wait       (UINT m_sec);
PUBLIC INT  No_OS_ClkRateGet (VOID);
PUBLIC UINT No_OS_GetTickCnt (VOID);
PUBLIC UINT No_OS_GetTickms  (VOID);

/* No Os user interface */
#ifdef DONT_USE_NO_OS_PROTOTYPES
/* in case driver code already have any of the
   macros open, close, ioctl ... defined, this
   functions will be used instead to prevent
   from compiler errors
*/
PUBLIC INT  open        (CHAR* path, INT flags);
PUBLIC INT  close       (INT fd);
PUBLIC INT  ioctl       (INT fd, UINT cmd, UINT arg);
PUBLIC INT  read        (INT fd, CHAR* buffer, INT len);
PUBLIC INT  write       (INT fd, CHAR* buffer, INT len);
#else
PUBLIC INT  No_OS_Open  (CHAR* path, INT flags);
PUBLIC INT  No_OS_Close (INT fd);
PUBLIC INT  No_OS_Ioctl (INT fd, UINT cmd, UINT arg);
PUBLIC INT  No_OS_Read  (INT fd, CHAR* buffer, INT len);
PUBLIC INT  No_OS_Write (INT fd, CHAR* buffer, INT len);
#endif

/* install/Remove driver */
PUBLIC INT  No_OS_InstallDriver    (No_OS_DrvOp *pDrvOp);
PUBLIC INT  No_OS_AddDevice        (CHAR * rootPath, INT nDrvNo);
PUBLIC INT  No_OS_DeleteDevice     (CHAR * name);
PUBLIC VOID No_OS_UninstallDriver  (INT nDrvNo);

/*******************************************************************************
   $Log: sys_noOSLib.h,v $
   Revision 1.5  2004/05/18 11:30:18  tauche
   functions HAL_LockInt() and HAL_UnlockInt() replaced by No_OS_LockInt and No_OS_UnlockInt() implemented in sys_noOSLib.c

   Revision 1.4  2004/03/10 16:25:27  kamdem
   comment adapted and some includes commented.

   Revision 1.3  2004/02/18 10:12:56  kamdem
   C-Files commented in doxygen style.
   sys_OS_AL_userOS.c and sys_HAL_userHW.c should be used by customer as template for his implementation.

   Revision 1.2  2004/02/10 16:08:29  kamdem
   No os doxygen config file uses now relatives paths.
   Document can always be generated by executing :
   ${DOXIGEN_INSTALL_PATH}/doxygen/bin/doxygen.exe Non_OS.cfg

   Revision 1.1  2004/02/09 09:49:54  tauche
   Moved noOS files to new location in system/noOS

   Revision 1.1  2004/02/09 09:17:30  tauche
   Moved noOS files to new location in system/noOS

   Revision 1.27  2004/02/05 19:36:43  wachendorf
   zzzzzz and another unchanged...

   Revision 1.26  2004/02/05 19:35:25  wachendorf
   ooops fixed #include "sys_OS_AL.h"

   Revision 1.25  2004/02/05 19:33:12  wachendorf
   #include "sys_drv_HAL.h"
   #include "sys_drv_OS_AL.h"

   Revision 1.24  2004/02/05 15:05:46  martin
   renames done, for previous version see tag "before_rename":
   sys_fifo -> sys_drv_fifo
   sys_defs.h -> sys_drv_defs.h
   sys_timerlib -> sys_drv_timerlib
   sys_delaylib -> sys_drv_delaylib
   sys_kthread -> sys_drv_kthread

   Revision 1.23  2004/02/04 14:19:19  kamdem
   Improvements in the No OS Library :

   - if the target driver also defines one of the user interface
     macros "open", "close", ..., for any reason,
     -DDONT_USE_NO_OS_PROTOTYPES
      should be added to the compiler defines to avoid compiler
      errors

   - Drivers using this OS - file should be compiled with additional
      compiler switch -DNO_OS

   - More comments added

   Revision 1.22  2004/02/02 17:56:25  tauche
   User Interface for device driver handling (open,close,...) implemented and tested

   Revision 1.20  2004/01/30 15:25:28  kamdem
   more corrections in documentation text.
   prints added to keep track of system life.

   Revision 1.18  2004/01/29 19:18:20  kamdem
   sys_drv_noOSLib.c : all variables used for delay calibration are volatile

   sys_drv_noOSLib.h/sys_HAL.h/sys_OS_AL.h :

   doxygen comments added for interface document generation.

   Revision 1.17  2004/01/28 17:54:55  kamdem
   Lib.h/c : Interface relevant info hidden in c-file
   Other  : implementation of _IO changed.

   Revision 1.16  2004/01/27 11:40:25  kamdem
   new interface function added for timer rescheduling if periodical timer is
   needed (i.e TAPI) : No_OS_ReschedTimer

   Revision 1.15  2004/01/26 17:31:47  tauche
   available events incread to 50 by default

   Revision 1.14  2004/01/23 19:53:53  kamdem
   improvments in the library. Use compiler switch  NON_OS_LITTLE_ENDIAN or
   NON_OS_BIG_ENDIAN to determine your endianess

   Revision 1.8  2004/01/20 12:56:44  kamdem
   Events macros reviewed : Init_Event initializes the queue with one event
   from the event list

   Revision 1.4  2004/01/15 17:04:38  kamdem
   Hardware functions for disable/enable interrupts

   Revision 1.3  2004/01/14 18:11:59  tauche
   Added prototypes for NO_OS user interface

   Revision 1.1  2004/01/09 19:33:18  kamdem
   * interface library implementation for No OS system
********************************************************************************/
#endif /* NO_OS_LITTLE_ENDIAN */
