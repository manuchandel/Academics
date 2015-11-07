/* Write a C program implementing parity encode and parity check algorithm */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *add parity adds parity bit to data
 *if oddparity is 1 it does oddparity else even parity
 */
void addParity(char *data,int oddparity){
  int n=strlen(data);
  int i;
  int sum=0;
  for(i=0;i<n;i++)
    sum+=data[i]-'0';
  char parity[2];
  parity[1]='\0';
  if(oddparity==1){
    parity[0]=(1+sum)%2+'0';
  }else
    parity[0]=sum%2 +'0';
  memcpy(data+n,parity,2);
  printf("\nModified Data :%s\n",data);
}
/* checks parity */
void checkParity(char *data,int oddparity){
  int n=strlen(data);
  int i;
  int sum=0;
  int check=0;
  for(i=0;i<n;i++)
    sum+=data[i]-'0';
  if(oddparity==1 && sum&1)
      check=1;
  else if(oddparity==0 && !(sum&1) )
      check=1;
  data[n-1]='\0';
  if(check)
      printf("\nData Verified Success :%s\n",data);
  else printf("\nData Discarded\n");


}
int main(int argc,char *argv[]){

  if(argc!=3){
    printf("\nInput correct Format\n");
    printf("./a.out 01string type=1(odd parity) type=0(even parity)\n");
    return 0;
  }
  int parity=argv[2][0]-'0';
  addParity(argv[1],parity);
  checkParity(argv[1],parity);
}
