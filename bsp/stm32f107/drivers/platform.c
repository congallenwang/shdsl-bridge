#include <rtthread.h>
#include <board.h>

#ifdef RT_USING_LWIP
#include "stm32_eth.h"
#else
#include "stm32_eth.h"
#endif /* RT_USING_LWIP */

#include "finsh.h"
void delay(volatile unsigned int nCount)
{
	volatile unsigned int index = 0;
	for(index = (100000 * nCount); index != 0; index--)
	{}
}
#ifdef RT_USING_SPI
#include "rt_stm32f10x_spi.h"
#include "spi_flash_w25qxx.h"

#if defined(RT_USING_DFS) && defined(RT_USING_DFS_ELMFAT)
#include "msd.h"
#endif /* RT_USING_DFS */
void rt_hw_shdsl_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
    // Enable the FSMC Clock
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);

	//PA0 for shdsl reset
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//FSMC reg/gpio init
	pef24628_Bus_Init();
    pef24628_GPIO_Configuration();

	//reset shdsl
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    delay(10);
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
    delay(10);
}

/*
 * SPI1_MOSI: PA7
 * SPI1_MISO: PA6
 * SPI1_SCK : PA5
 *
 * CS0: PA4  SD card.
*/
static void rt_hw_spi_init(void)
{
#ifdef RT_USING_SPI1
    /* register spi bus */
    {
        static struct stm32_spi_bus stm32_spi;
        GPIO_InitTypeDef GPIO_InitStructure;

		//disable JTag for spi1 remap usage
	   GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		 
	 /* Enable GPIO clock */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO,ENABLE);
  	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);          
  	 //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);						   // Enable the FSMC Clock

	//remap spi1 for flash access
	*(__IO unsigned int*)(AFIO_BASE+0x04) |= 0x1;
#if 0
        GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
        GPIO_Init(GPIOA, &GPIO_InitStructure);
#else
		//Pb3:SCK,Pb5:MOSI
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 |GPIO_Pin_5; 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOB, &GPIO_InitStructure);

		/* Confugure PB4:MISO pin as Input Floating  */		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
#endif
		//rt_kprintf("try register spi\r\n");
        stm32_spi_register(SPI1, &stm32_spi, "spi1");
		//rt_kprintf("try register spi 1\r\n");
    }

    /* attach cs */
    {
        static struct rt_spi_device spi_device;
        static struct stm32_spi_cs  spi_cs;

        GPIO_InitTypeDef GPIO_InitStructure;

        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

#if 0
        /* spi21: PG10 */
        spi_cs.GPIOx = GPIOA;
        spi_cs.GPIO_Pin = GPIO_Pin_4;
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
#else		
		/* spi21: PA15 */
		spi_cs.GPIOx = GPIOA;
		spi_cs.GPIO_Pin = GPIO_Pin_15;
		//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
#endif
        GPIO_InitStructure.GPIO_Pin = spi_cs.GPIO_Pin;
        GPIO_SetBits(spi_cs.GPIOx, spi_cs.GPIO_Pin);
        GPIO_Init(spi_cs.GPIOx, &GPIO_InitStructure);

        rt_spi_bus_attach_device(&spi_device, "spi10", "spi1", (void*)&spi_cs);
		
	}
#endif /* RT_USING_SPI1 */
}
#endif /* RT_USING_SPI */

rt_device_t g_spi;
#define LEN 256
long rt_dumpspi(unsigned int addr, int num)
{
	unsigned char buf[LEN];
	int i,j;
	if(g_spi != RT_NULL)
	{
		for(j=0;j<num;j++)
		{
			rt_device_read(g_spi,addr+j*LEN,buf,LEN);
			for(i=0;i<LEN;i++)
			{
				if(i%16==0)
					rt_kprintf("%05X: ",addr+j*LEN+i);

				rt_kprintf("%02X ",buf[i]);

				if(i%16 == 15)				
					rt_kprintf("\r\n");
			}
		}
	}
	return 0;
}
FINSH_FUNCTION_EXPORT(rt_dumpspi, dump spi);


void rt_burnapp(unsigned char* buf, unsigned int pos, unsigned char filetype)
{
	if(g_spi != RT_NULL)
	{
		//app = 1, start from 1M
		if(filetype==1)			
			rt_device_write(g_spi,0x100+pos,buf,1);
		//shdsl fw, start from 0
		else if(filetype==2)			
			rt_device_write(g_spi,0+pos,buf,1);
		//idc fw, start from 200k
		else if(filetype==3)			
			rt_device_write(g_spi,50+pos,buf,1);
	}
	return;
}
void rt_platform_init(void)
{
#ifdef RT_USING_SPI
    unsigned char buf[LEN];
	int i;

    rt_hw_spi_init();
	w25qxx_init("W25Q128","spi10");
	g_spi=rt_device_find("W25Q128");
	if(g_spi != RT_NULL)
	{
		if (rt_device_open(g_spi, RT_DEVICE_OFLAG_RDWR) == RT_EOK)
		{
			rt_device_read(g_spi,0,buf,LEN);
/*
			for(i=0;i<LEN;i++)
			{
				rt_kprintf("%02x ",buf[i]);
				if(i!=0 && i%16 == 15)
					rt_kprintf("\r\n");
			}
			rt_kprintf("\r\n");
*/
		}
		else
			rt_kprintf("open spi device failed\r\n");
	}
	else
		rt_kprintf("find spi device failed\r\n");

	//init shdsl related GPIO/bus
	rt_hw_shdsl_init();
	
#if defined(RT_USING_DFS) && defined(RT_USING_DFS_ELMFAT)
    /* init sdcard driver */
    {
        extern void rt_hw_msd_init(void);
        GPIO_InitTypeDef  GPIO_InitStructure;

        /* PC4 : SD Power */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

        GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        /* SD card power on. */
        GPIO_ResetBits(GPIOC, GPIO_Pin_4);
        rt_thread_delay(2);

        msd_init("sd0", "spi10");
    }
#endif /* RT_USING_DFS && RT_USING_DFS_ELMFAT */

#endif // RT_USING_SPI


#ifdef RT_USING_LWIP
    /* initialize eth interface */
    rt_hw_stm32_eth_init();
#else
	/* initialize eth interface */
	rt_kprintf("rt_hw_stm32_eth_init\r\n");
    rt_hw_stm32_eth_init();
#endif /* RT_USING_LWIP */
}


 

