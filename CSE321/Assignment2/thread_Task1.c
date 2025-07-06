#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void *thread_function(void *msg){
   char *message;
   message=(char*) msg;
   printf("%s\n",message);
}

int main(){
pthread_t t1;
pthread_t t2;
pthread_t t3;
pthread_t t4;
pthread_t t5;

char *msg1="thread-1 running";
char *msg2="thread-2 running";
char *msg3="thread-3 running";
char *msg4="thread-4 running";
char *msg5="thread-5 running";

pthread_create(&t1,NULL,thread_function,(void*)msg1);
pthread_join(t1,NULL);
printf("Thread-1 closed\n");
pthread_create(&t2,NULL,thread_function,(void*)msg2);
pthread_join(t2,NULL);
printf("Thread-2 closed\n");
pthread_create(&t3,NULL,thread_function,(void*)msg3);
pthread_join(t3,NULL);
printf("Thread-3 closed\n");
pthread_create(&t4,NULL,thread_function,(void*)msg4);
pthread_join(t4,NULL);
printf("Thread-4 closed\n");
pthread_create(&t5,NULL,thread_function,(void*)msg5);
pthread_join(t5,NULL);
printf("Thread-5 closed\n");

return 0;
}

