
/* Write a C program who takes input as a integer and prints it in big endian and little endian format  */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <stdlib.h>
void getBitValue(int a,char s[]){
  int i=0;
  for(i=0;i<8;i++)
    s[i]='0';
  switch(a){
    case 1:
      s[7]='1';
      return;
    case 2:
      s[6]='1';
      return;
    case 3:
      s[7]=s[6]='1';
      return;
    case 4:
      s[5]='1';
      return;
    case 5:
      s[5]=s[7]='1';
      return;
    case 6:
      s[5]=s[6]='1';
      return;
    case 7:
      s[5]=s[6]=s[7]='1';
      return;
    case 8:
      s[4]='1';
      return;
    case 9:
      s[4]=s[7]='1';
      return;
    default:
      return;
  }
}
/* prints digits as 8 bit characters in big endian format */
void display_Big_endian(int n){
  int digit;
  int i=2000;
  int ten=1;
  while(ten<n) ten*=10;
  ten/=10;
  char bit[9];
  bit[8]='\0';
  printf("\nIn Big Endian,the First Byte Is Stored First And Stack Grows Downwards\n\n");
  while(n>0){
    digit=(int)n/ten;
    getBitValue(digit,bit);
    printf("%s",bit);
    printf("  <------  %0x\n",i);
    n-=digit*ten;
    ten/=10;
    i++;
  }
  printf("\n");
}
/* prints digits as 8 bit characters in little endian format */
void display_Little_endian(int n){
  int digit;
  int i=2000;
  char bit[9];
  bit[8]='\0';
  printf("\nIn Little Endian,the Last Byte Is Stored First And Stack Grows Downwards\n\n");
  while(n>0){
    digit=n%10;
    getBitValue(digit,bit);
    printf("%s",bit);
    printf("  <------  %0x\n",i);
    n/=10;
    i++;
  }
  printf("\n");
}
int main(){
  int n;
  scanf("%d",&n);
  display_Little_endian(n);
  display_Big_endian(n);
}
