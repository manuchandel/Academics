/*
 *Write a C program demonstrating client server communication using pipes
 *Impelement one sorting algorithm in such a way that client should sent set of numbers and
 *server should send the result back
 */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define FOR(a,b) for(a=0;a<b;a++)
void swap(int *a,int *b){
  int c=*a;
  *a=*b;
  *b=c;
}
void bubbleSort(int a[],int n){
  int i,j;
  FOR(i,n)
    FOR(j,n)
      if(a[i]<a[j])
        swap(&a[i],&a[j]);
}
int clientServerModel(int n){
  int i,status;
  int a[n];
  int clientpipe[2];
  int serverpipe[2];
  char buffer[11];
  char ack;
  if(pipe(clientpipe)<0 || pipe(serverpipe)<0){  //creating pipes to communicate
    printf("Error in creating pipes\n");
    exit(0);
  }
  pid_t server=fork();  //forking the process
  if(server<0){
    printf("Error in forking not enough memory\n");
    exit(0);
  }
  if(server){ //entering the client process i.e parent process
    FOR(i,n){
      snprintf (buffer,sizeof(buffer),"%d",rand()%100);  //convert integer to string
      //printf("Client : writing to the client pipe %s waiting for ack\n",buffer);
      write(clientpipe[1],buffer,strlen(buffer));  //write integer to pipe
      read(serverpipe[0],&ack,1);  //wait for acknowledgement
      //printf("Client : ack received\n\n");
    }
    FOR(i,n){
      //printf("Client : reading from the server pipe ");
      read(serverpipe[0],buffer,11);
      a[i]=atoi(buffer);
      //printf("%d ack sent\n",a[i]);
      write(clientpipe[1],"1",1);
    }
    close(clientpipe[0]);
    close(clientpipe[1]);
  }else{  //entering the server process i.e child process
    FOR(i,n){
      //printf("Server : reading from the client pipe ");
      read(clientpipe[0],buffer,11);
      a[i]=atoi(buffer);
      //printf("%d ack sent\n",a[i]);
      write(serverpipe[1],"1",1);
    }
    bubbleSort(a,n);
    FOR(i,n){
      snprintf (buffer,sizeof(buffer),"%d",a[i]);  //convert integer to string
      //printf("Server : writing to the server pipe %s waiting for ack\n",buffer);
      write(serverpipe[1],buffer,strlen(buffer));  //write integer to pipe
      read(clientpipe[0],&ack,1);  //wait for acknowledgement
      //printf("Server : ack received\n\n");
    }
    close(serverpipe[0]);
    close(serverpipe[1]);
  }
  wait(&status);
  if(server){
    FOR(i,n)
      printf("%d ",a[i]);
    printf("\n");
  }
}
int main()
{
  clientServerModel(10);
}
