#include "tuntap.h"

int tan_alloc(char *dev)
{
  struct ifreq ifr;
  int fd, err;

  if ((fd = open("/dev/net/tap", O_RDWR)) < 0)
  {
    printf("Cannot open TUN/TAP device.\n");
    exit(1);
  }

  memset(&(ifr), 0, sizeof(ifr));

  ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
  if (*dev)
  {
    strlcpy(ifr.ifr_name, dev, IFNAMSIZ);
  }

  if ((err = ioctl(fd, TUNSETIFF, (void *) &ifr) < 0))
  {
    fprintf("ERR: Couldnt ioctl tun: %s\n", strerror(errno));
    close(fd);
    return err;
  }

  strlcpy(dev, ifr.ifr_name);
  return fd;
}