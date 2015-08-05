
/* Write a C program To make a perfect process tree of 4 processes  */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
/* prints process pids as mentioned */
void printPids(int i){
  int status;
  wait(status);
  wait(status);
  if(i>2)
    printf("I am Grand Children of Root with pid %d\n",getpid());
  else if (i>0)
    printf("I am Children of Root with pid %d\n",getpid());
  else  printf("I am Root with pid %d\n",getpid());
}
/* creates process tree recursively */
int createProcessPerfectTree(int i,int n){
  int lc=(i<<1)+1,rc=(i<<1)+2;
  printf("%d\n",getpid());
  if(lc>=n)
    return i;
  pid_t leftchild=fork(); //create the leftchild process
  if(leftchild==0)
    return createProcessPerfectTree(lc,n);
  else {
    pid_t rightChild;
    rightChild=fork();  //create the rightChild process
    if(rightChild==0)
      return createProcessPerfectTree(rc,n);
  }
  return i;
}
int main(){
  int n=7;
  printPids(createProcessPerfectTree(0,n));
}
