/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2013, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 */

/**
 * @addtogroup STM32
 */
/*@{*/

#include <board.h>
#include <rtthread.h>

#ifdef RT_USING_DFS
#include <dfs_fs.h>
#include <dfs_init.h>
#include <dfs_elm.h>
#endif

#ifdef RT_USING_LWIP
#include <stm32_eth.h>
#include <netif/ethernetif.h>
extern int lwip_system_init(void);
#else
#include <stm32_eth.h>
#include "httpd.h"
#include "uip_ethernetif.h"
extern void uip_sys_init(void);
#endif

#ifdef RT_USING_FINSH
#include <shell.h>
#include <finsh.h>
#endif

#include "lib_sysdep.h"
#include "shdsl_board.h"
#include "lib_soc4e_map.h"

char Vxy[]="beta v1.e";			



static BOARD_Configuration_t DeviceConfiguration =
{
   PEF24628E_IF_MPI,
   FALSE,
   4,
   PEF24628E_MAX_DEV_NUMBER,
   PEF24628E_MAX_LINE_NUMBER,   
};

/*
int usrApp(void)
{
   int key;
   BOOL bRestart = FALSE;
   BOOL status;
   BOOL loop_active;
   //E_ACTION_MENU_T action;
   UINT8 device;

RESTART:
   bRestart = FALSE;

   rt_kprintf("20150521 restart \n\r");
   rt_kprintf("Interface mode: %d\n\r", DeviceConfiguration.nInterfaceMode);
   rt_kprintf("Polling mode:   %d\n\r", DeviceConfiguration.bPollingMode);
   rt_kprintf("SCI clock:      %d\n\r", DeviceConfiguration.nSciClock);

   status = soc4e_drv_init(&DeviceConfiguration);

   if (status != TRUE)
   {
      PRINTF("soc4e_drv_init() failed ... \n\r");
      goto ERROR_EXIT;
   }

   //conifg for
   //loop forever
   while(1);
ERROR_EXIT:

   PRINTF("\r\n");

   if (soc4e_drv_exit() != TRUE)
      return -1;

   if (bRestart== TRUE)
      goto RESTART;

   return 0;
}
*/


unsigned char ReadButton()
{
  	unsigned char button=0;
	
	button = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
	button |= GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)<<1;
	button |= GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)<<2;
	button |= GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)<<3;
	button |= GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3)<<4;
	button |= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)<<5;
	button |= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)<<6;
	button |= GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13)<<7;

	return button;
}

void rt_starteth()
{
	rt_device_t eth;
	eth=rt_device_find("e0");
	if(eth != RT_NULL)
	{
		if(RT_EOK != rt_device_init(eth))
			rt_kprintf("init e0 failed\r\n");
		else
			rt_kprintf("init e0 ok\r\n");
	}
	else
		rt_kprintf("find e0 failed\r\n");
	return;
}


void rt_init_thread_entry(void* parameter)
{
    {
        extern void rt_platform_init(void);
        rt_platform_init();
    }

#if 1
	rt_shdsl_register();
	if(rt_shdsl_init() != RT_ERROR)
		rt_shdsl_thread_init();
#endif
	//while(1);

    /* Filesystem Initialization */
#if defined(RT_USING_DFS) && defined(RT_USING_DFS_ELMFAT)
	/* initialize the device file system */
	dfs_init();

	/* initialize the elm chan FatFS file system*/
	elm_init();
    
    /* mount sd card fat partition 1 as root directory */
    if (dfs_mount("sd0", "/", "elm", 0, 0) == 0)
    {
        rt_kprintf("File System initialized!\n");
    }
    else
    {
        rt_kprintf("File System initialzation failed!\n");
    }
#endif /* RT_USING_DFS && RT_USING_DFS_ELMFAT */

#ifdef RT_USING_LWIP
	/* initialize lwip stack */
	/* register ethernetif device */
	eth_system_device_init();

	/* initialize lwip system */
	lwip_system_init();
	rt_kprintf("TCP/IP initialized!\n");
#else
	eth_system_device_init();
	uip_sys_init();
	//uip_init();
	rt_kprintf("UIp initialized!\n");

	
	//allen, start the eth device
	rt_starteth();
#endif

#ifdef RT_USING_FINSH
	/* initialize finsh */
	finsh_system_init();
	finsh_set_device(RT_CONSOLE_DEVICE_NAME);
#endif

}

int rt_application_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("init",
        rt_init_thread_entry, RT_NULL,
        2048, RT_THREAD_PRIORITY_MAX/3, 20);
    if (tid != RT_NULL) rt_thread_startup(tid);

    return 0;
}

/*@}*/
