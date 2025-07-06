#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    static int count=1;
    pid_t a=fork();
    pid_t b=fork();
    pid_t c=fork();
   
    if(getpid()%2!=0){
    pid_t d=fork();
    }
    count+=1;
    printf("%d\n",count);
    
    return 0;
}

