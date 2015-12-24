#include "configmanage.h"


extern unsigned char g_rcmode;//0 for CO mode;1 for CPE mode
extern unsigned int g_maxbaserate;
extern unsigned int g_lineProbe;

//global config struct
CONFIG_PARAM g_config;

//dummmy
void initconfig()
{
    g_config.dslService= 1;
    if(0==g_rcmode)
        g_config.dslService= 2;    
    
    g_config.caplist_co= 0;
    g_config.caplist_rt = 0;

    g_config.dslWires = 3; 

    g_config.dslStandard = 7;

    g_config.lineprobe = g_lineProbe-1;

    g_config.extend = 0;
    g_config.extend_rate_fix_value = 0;

    g_config.minrate=12;
    g_config.maxrate = g_maxbaserate/(64*1000);

    //13 for efm mode
    //12 for atm mode
    g_config.dslmode = 13;

}


//save config to flash
void saveconfig()
{
    return;

}

//read config from flash
void getconfig()
{
    return;    
}
