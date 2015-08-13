/* Write a C program to find hostname from given ip address*/

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <string.h>
#include <netdb.h>
char *getHostName(char *ip){
  struct in_addr addr;  //stucture which contains ipaddress in networkbyte order
  inet_aton(ip,&addr);  //This is function which sets in_addr struct according to ip address
  struct hostent *ptr=gethostbyaddr(&addr,sizeof(addr),AF_INET);  //a hostent structure is returned
  if(!ptr)
    return NULL;
  return ptr->h_name; //prints official name of the host
}
int main(int argc, char *argv[]){
  char *hostname=getHostName(argv[1]);
  if(!hostname)
    printf("There is error in ip address\n");
  else printf("\nHost Name: %s\n\n",hostname );
}
