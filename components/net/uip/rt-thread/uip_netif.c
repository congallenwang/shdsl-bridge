#include "rtdef.h"
#include "uip-conf.h"
#include "uip.h"
#include "uip_netif.h"
#include "uip_arp.h"
#include "rtconfig.h"
#include "uip_pbuf.h"

void netif_set_default(struct netif *netif)
{
  
}
unsigned char  mymac[6]={0xcc,0xbb,0xaa,0x99,0x88,0x02}; 


unsigned char ReadButton();


void netif_set_addr(struct netif *netif, struct ip_addr *ipaddr,  struct ip_addr *netmask,
    struct ip_addr *gw)
{
     uip_ipaddr_t hipaddr;

     unsigned char tmp=0;
     //read button to differ mac/ip,fix me
     tmp=0x80 & ReadButton();
     if(tmp)
        tmp=1;

     uip_ipaddr(hipaddr, RT_LWIP_IPADDR0,RT_LWIP_IPADDR1,RT_LWIP_IPADDR2,(RT_LWIP_IPADDR3+tmp));
     uip_sethostaddr(hipaddr);
     uip_ipaddr(hipaddr, RT_LWIP_GWADDR0,RT_LWIP_GWADDR1,RT_LWIP_GWADDR2,RT_LWIP_GWADDR3);
     uip_setdraddr(hipaddr);
     uip_ipaddr(hipaddr, RT_LWIP_MSKADDR0,RT_LWIP_MSKADDR1,RT_LWIP_MSKADDR2,RT_LWIP_MSKADDR3);
     uip_setnetmask(hipaddr);

	uip_ethaddr.addr[0] = mymac[0];
	uip_ethaddr.addr[1] = mymac[1];
	uip_ethaddr.addr[2] = mymac[2];
	uip_ethaddr.addr[3] = mymac[3];
	uip_ethaddr.addr[4] = mymac[4];
	uip_ethaddr.addr[5] = mymac[5];
	uip_setethaddr(uip_ethaddr);	 

     return ;
}

struct netif *
netif_add(struct netif *netif, struct ip_addr *ipaddr,  struct ip_addr *netmask,
  struct ip_addr *gw,
  void *state,
  err_t (* init)(struct netif *netif),
  err_t (* input)(struct pbuf *p, struct netif *netif))
{
	//if (netif_add(netif, IP_ADDR_ANY, IP_ADDR_BROADCAST, IP_ADDR_ANY, dev,
		//eth_init, eth_input) == RT_NULL)
    // netif->uip_hostaddr = ipaddr;
     //netif->uip_draddr = netmask;
    // netif->uip_netmask = gw;
    // netif_set_addr(netif,ipaddr,netmask,gw);  
     
       // call user specified initialization function for netif  
     if (init(netif) != 0) {
        return RT_NULL;
     }
     netif->input = input;
     netif->state = state;
     netif_set_addr(netif,ipaddr,netmask,gw);
     return netif;
               
}
err_t etharp_output(struct netif *netif, struct pbuf *q, struct ip_addr *ipaddr)
{
     return 0;
}
