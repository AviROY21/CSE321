#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/wait.h> 

void main(){
  int pid,status,pid1;
  
  pid=fork();
  
  if (pid<0){ 
    printf("fork failed\n");
    exit(1);
  }  
  
  if (pid==0){
    pid1=fork();
    
    if (pid1==0){
      printf("I am grandchild\n");
    }
    else{
      wait(&status);
      printf("I am child\n");
    }
  }
  if(pid>0){
    wait(&status);
    printf("I am parent\n"); 
  }
}
