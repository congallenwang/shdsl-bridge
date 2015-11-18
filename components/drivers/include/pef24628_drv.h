#ifndef PEF24628_DRV_INCLUDED
#define PEF24628_DRV_INCLUDED

#include "rtdef.h"

#include <rtthread.h>
//#include <drivers/spi.h>
#include "drv_pef24628e_api.h"



struct rt_pef24628
{
    /* inherit from ethernet device */
    struct rt_device parent;

    PEF24628E_DEV_t data;
};

extern rt_err_t pef24628_drv_init(struct rt_pef24628* dev,const char * device_name);


struct rt_msg
{
	unsigned int msg_id;
	unsigned char linkno;
	unsigned char state;
};


#endif 
