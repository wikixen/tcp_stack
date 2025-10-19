#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int tan_alloc(char *dev)
{
  // struct ifreq ifr;
  int fd, err;

  if ((fd = open("/dev/net/tap", O_RDWR)) < 0)
  {
    /* code */
  }
  
}