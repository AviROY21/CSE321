#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h> 

int main(){ 

  pid_t pid=fork();
  int status;
  if (pid>0){
  printf("1.Parent process ID:%d\n",getpid());
  }
  if(pid==0){
  pid_t pid1=fork();
  if (pid1==0){
  pid_t pid2=fork();
  if (pid2==0){
  pid_t pid3=fork();
  if(pid3==0){
  wait(&status);
  printf("3.Grand Child process ID:%d\n",getpid());
  
  }
  else{
  wait(&status);
  printf("4.Grand Child process2 ID:%d\n",getpid());
  }
  }
  else{
  wait(&status);
  printf("5.Grand Child process1 ID:%d\n",getpid());
  }
  
  }
  else{
  printf("2.Child process ID:%d\n",getpid());
  }
  
  
  }
  return 0;
}
