#include <stdio.h>
int
main()
{
   static char netmask[]="255.255.254.0";
   int part[4];
   int net;
   unsigned int mask = 0x01;
   int i, pos=32;

   sscanf(netmask,"%d.%d.%d.%d", &part[0], &part[1], &part[2], &part[3]);
   net =  part[0] << 24 | part[1] << 16 | part [2] << 8 | part [3];
   printf("%0x, %0x, %0x, %0x: %0x\n", part[0], part[1], part[2], part[3], net);
   for   (i=0; i< 32; i++) {
        if (net & mask) {
                printf("%d\n", pos);
                break;
        }
        mask <<=1;
        pos--;
   }
}
