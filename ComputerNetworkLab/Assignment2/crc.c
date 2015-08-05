/* Write a C program implementing crc algorithm */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <stdlib.h>
void moduloTwoDivision(char word[],int n,char divisor[], char remain[],int k){
  int i;
  for(i=0;i<k;i++)
    remain[i]=word[i];
  int p=k;
  while(p<=n){
    if(remain[0]=='1')
      for(i=0;i<k;i++)
          remain[i]=((remain[i]-'0')+(divisor[i]-'0'))%2+'0';
    for(i=0;i<k-1;i++)
      remain[i]=remain[i+1];

    if(p==n)
      remain[k-1]='\0';
    else remain[k-1]=word[p];
    p++;
  }
}
int crcDecoder(char codeword[],char divisor[],int n,int k){
    int i;
    char dataword[k];
    char remain[n-k+1];
    moduloTwoDivision(codeword,n,divisor,remain,n-k+1);
    int recovered=1;
    for(i=0;i<n-k;i++)
      if(remain[i]!='0')
        recovered=0;
    if(!recovered)
      printf("\nNot able to recover message\n");
    else {
      printf("\nMessage recovered\n");
      for(i=0;i<k;i++){
        dataword[i]=codeword[i];
      printf("%c",dataword[i]);
      }
      printf("\n");
    }

}
int crcEncoder(char dataword[], char codeword[], char divisor[],int n,int k){
  int i;
  char remain[n-k+1];
  for(i=0;i<k;i++)
    codeword[i]=dataword[i];
  for(;i<n;i++)
    codeword[i]='0';
  moduloTwoDivision(codeword,n,divisor,remain,n-k+1);
  for(i=k;i<n;i++)
    codeword[i]=remain[i-k];
}
int crcAlgorithm(char dataword[],int n,int k){
  int i;
  char codeword[n];
  char divisor[n-k+1];
  for(i=0;i<n-k+1;i++)
    divisor[i]='1';
  divisor[2]='0';
  printf("\nThis is divisor used :\n");
  for(i=0;i<n-k+1;i++)
    printf("%c",divisor[i]);
  printf("\n");
  crcEncoder(dataword,codeword,divisor,n,k);
  printf("\nThis is encoded string :\n");
  for(i=0;i<n;i++)
    printf("%c",codeword[i]);
  printf("\n");
  crcDecoder(codeword,divisor,n,k);
}
int main(){
  char dataword[]={'1','0','1','1'};
  crcAlgorithm(dataword,7,4);

}
