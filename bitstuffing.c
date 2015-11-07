/* Write a C program implementing bit stuffing algorithm */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *data is string of 0s and 1s
 *this function stuffs bit 0 whereever '011111' pattern appears and returns stuffed data;
 */
void bitstuff(char *data){
  int len=strlen(data);
  char stuffedString[(len/5)*6+1];
  int i=0,j,k=0,sum;
  while(i<len){
    stuffedString[k]=data[i];
    if(data[i]=='0'){
      j=0; sum=0;
      while(j<5 && j<len){
        sum+=data[j+i+1]-'0';
        j++;
      }
      if(sum==5){
        i+=5;k++; j=0;
        while(j<5){
          stuffedString[k]='1';
          k++;
          j++;
        }
        stuffedString[k]='0';
      }
    }
    i++;
    k++;
  }
  stuffedString[k]='\0';
  strcpy(data,stuffedString);
  printf("\nStuffed Data : %s\n",data );
}
/* recovers the original data from stuffed bits */
void bitunstuff(char *data){
  int len=strlen(data);
  char unstuffed[len+1];
  int i=0,j,k=0,sum=0;
  while(i<len){
    unstuffed[k]=data[i];
    if(data[i]=='0'){
      j=0; sum=0;
      while(j<5 && j<len){
        sum+=data[j+i+1]-'0';
        j++;
      }
      if(sum==5){
        i+=6;k++; j=0;
        while(j<5){
          unstuffed[k]='1';
          k++;
          j++;
        }
        k--;
      }
    }
    i++;
    k++;
  }
  unstuffed[k]='\0';
  strcpy(data,unstuffed);
  printf("\nUnstuffed Data : %s\n",data );
}
int main(int argc,char *argv[]){

  bitstuff(argv[1]);
  bitunstuff(argv[1]);
}
