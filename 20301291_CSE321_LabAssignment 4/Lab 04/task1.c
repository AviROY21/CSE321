#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#define MAX 10 
#define BUFLEN 6
#define NUMTHREAD 2 
void * consumer(int *id);
void * producer(int *id);
char buffer[BUFLEN];
char source[BUFLEN]; 
int pCount = 0;
int cCount = 0;
int buflen;
int n=0;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0,1};
int i = 0;
int j = 0;
int main()
{
    int i;

    pthread_t thread[NUMTHREAD];
    strcpy(source,"abcdef");
    buflen = strlen(source);
    
    pthread_create(&thread[0], NULL, producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, consumer, &thread_id[1]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    return 0;

}

void * producer(int *id)
{
    char item;
    for(int in=0;in<MAX;in++)
    {
        item=source[in%buflen];
        pthread_mutex_lock(&count_mutex);
        while(1){
            if(n!=buflen)
                break;
            pthread_cond_wait(&full,&count_mutex);      
			
		} 
        buffer[in%buflen]=item;
        n+=1;
        printf("%d produced %c by Thread %d\n",pCount,buffer[in%buflen],*((int* )id));
        pCount+=1;
        pthread_mutex_unlock(&count_mutex);
        pthread_cond_signal(&nonEmpty);

    }

}
void * consumer(int *id)
{
    char item;
    for(int in=0;in<MAX;in++)
    {
        
        pthread_mutex_lock(&count_mutex);
        while(1){
            
            if(n!=0)
                break;      
	    pthread_cond_wait(&nonEmpty,&count_mutex);
		} 
        item=buffer[in%buflen];
        n-=1;
        printf("%d consumed %c by Thread %d\n",cCount,buffer[in%buflen],*((int *)id));
        cCount+=1;
        pthread_mutex_unlock(&count_mutex);
        pthread_cond_signal(&full);
    }
}
