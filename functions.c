/* Write a C program to find hostname from given ip address and also to find mac address*/

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
/*char *getHostName(char *ip){
  struct in_addr addr;
  addr.s_addr=inet_addr(ip);  // returns the address as an in_addr_t
  struct hostent *ptr=gethostbyaddr(&addr,sizeof(addr),AF_INET);  //a hostent structure is returned
  if(!ptr)
    return NULL;
  return ptr->h_name; //prints official name of the host
}*/
/*char *getHostName(char *ip){
  struct in_addr addr;  //stucture which contains ipaddress in networkbyte order
  inet_aton(ip,&addr);  //This is function which sets in_addr struct according to ip address
  char *convertedip=inet_ntoa(addr);  //opposite of inet_aton converts in_addr struct to dots and string format
  printf("converted ip %s\n",convertedip);
  struct hostent *ptr=gethostbyaddr(&addr,sizeof(addr),AF_INET);  //a hostent structure is returned
  if(!ptr)
    return NULL;
  return ptr->h_name; //prints official name of the host
}*/
int main(int argc, char *argv[]){
  char *hostname=getHostName(argv[1]);
  if(!hostname)
    printf("There is error in ip address\n");
  else printf("\n\nHost Name: %s\n",hostname );
}
