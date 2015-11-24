#include "configmanage.h"

//global config struct
CONFIG_PARAM g_config;


//dummmy
void initconfig()
{
    g_config.dslService= 1;
    
    g_config.caplist_co= 0;
    g_config.caplist_rt = 0;

    g_config.dslWires = 3; 

    g_config.dslStandard = 7;

    g_config.lineprobe = 1;

    g_config.extend = 88;
    g_config.extend_rate_fix_value = 0;

    g_config.minrate=12;
    g_config.maxrate = 88;

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
