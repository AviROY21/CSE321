#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function();
int main(){
 pthread_t t0;
 pthread_t t1;
 pthread_t t2;
 pthread_t t3;
 pthread_t t4;
 
 pthread_create(&t0,NULL,thread_function,NULL);
 pthread_exit(NULL);
 pthread_create(&t1,NULL,thread_function,NULL);
 pthread_exit(NULL);
 pthread_create(&t2,NULL,thread_function,NULL);
 pthread_exit(NULL);
 pthread_create(&t3,NULL,thread_function,NULL);
 pthread_exit(NULL);
 pthread_create(&t4,NULL,thread_function,NULL);
 pthread_exit(NULL);
  
 return 0;
 }
 
 void *thread_function(){
 int k=1;
 for (int i=0;i<6;i++){
 for(int j=0;j<5;j++){
 printf("Thread %d prints %d\n",i,k);
 k++;
 }
 
 }
 
 }
    
    
 









