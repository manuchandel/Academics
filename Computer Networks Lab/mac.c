/* Write a C program to find mac address*/

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <net/if.h>
#include <sys/ioctl.h>
void getMacAddress(char *interface)
{
    int i;
    int fd;
    unsigned char mac[IFHWADDRLEN]; //will hold macaddress in non printable format
    struct ifreq ifstruct;
    strcpy(ifstruct.ifr_name,interface);
    /* open the connectionless socket */
    fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    /* request to get hardware address into mac */
    ioctl(fd, SIOCGIFHWADDR, &ifstruct);
    memcpy(mac, ifstruct.ifr_hwaddr.sa_data, IFHWADDRLEN);
    printf("\nMAC ADDRESS : ");
    for( i = 0; i < IFHWADDRLEN; i++ )
        printf("%02X:", (unsigned int)(mac[i]));
    printf("\n\n" );
}
int main(int argc, char *argv[]){
  /* argv[1] is the network interface */
  getMacAddress(argv[1]);
}
