
/* Write a C program to List all Files in a Directory and Each of its properties */

/*
 *Manu Chandel
 *Btech 3rd year
 *13114013
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
/* This function prints all the properties of file passed in argument*/
void fileproperty(char *filename){
  struct stat obj;
  stat(filename,&obj);
  struct stat *fileStat=&obj;
  printf("Information for %s\n",filename);
  printf("---------------------------\n");
  printf("File Size: \t\t%d bytes\n",fileStat->st_size);
  printf("Number of Links: \t%d\n",fileStat->st_nlink);
  printf("File inode: \t\t%d\n",fileStat->st_ino);
  printf("File Permissions: \t");
  printf( (S_ISDIR(fileStat->st_mode)) ? "d" : "-");
  printf( (fileStat->st_mode & S_IRUSR) ? "r" : "-");
  printf( (fileStat->st_mode & S_IWUSR) ? "w" : "-");
  printf( (fileStat->st_mode & S_IXUSR) ? "x" : "-");
  printf( (fileStat->st_mode & S_IRGRP) ? "r" : "-");
  printf( (fileStat->st_mode & S_IWGRP) ? "w" : "-");
  printf( (fileStat->st_mode & S_IXGRP) ? "x" : "-");
  printf( (fileStat->st_mode & S_IROTH) ? "r" : "-");
  printf( (fileStat->st_mode & S_IWOTH) ? "w" : "-");
  printf( (fileStat->st_mode & S_IXOTH) ? "x" : "-");
  printf("\n\n");
  printf("The file %s a symbolic link\n", (S_ISLNK(fileStat->st_mode)) ? "is" : "is not");
  printf("\n\n\n");
}
/* This function list all the files with its properties */
void listFiles(const char *dirname){
  DIR *dir=opendir(dirname);
  if(!dir){
    printf("Error in Directory Name\n");
    exit(0);
  }
  struct dirent *file=readdir(dir);
  chdir(dirname);
  while(file){
    if(file->d_name[0]!='.')
      fileproperty(file->d_name);
    file=readdir(dir);
  }
}
int main(int argc,char *argv[]){
  if(argc < 2)
    printf("Pass directory path as an argument  \"directory path\"\n");
  else listFiles(argv[1]);
}
