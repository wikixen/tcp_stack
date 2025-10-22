#include <linux/if_ether.h>
#include <stdlib.h>
#include <inttypes.h>

struct eth_hdr
{
  unsigned char dest_mac[6];
  unsigned char src_mac[6];
  uint16_t ether_t; //If <=1536 payload type, else payload length
  unsigned char payload[];
} __attribute__((packed));

