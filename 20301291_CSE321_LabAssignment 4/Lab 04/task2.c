#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define MaxCrops 5 
#define warehouseSize 5 

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize]={'R','W','P','S','M'};
char warehouse[warehouseSize]={'N','N','N','N','N'};
pthread_mutex_t mutex;

void *Farmer(void *far)
{   
  
  char item;
  for(int ln=0;ln<MaxCrops;ln++)
  {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    item=crops[in];
    warehouse[in]=item;
    printf("Farmer %d: Insert crops %c at %d\n", *((int *)far), warehouse[in], in);
    in = (in+1)%warehouseSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
    pthread_mutex_lock(&mutex);
    printf("Farmer%d: ", *((int *)far));
    for(int i=0;i<MaxCrops;i++){
        printf("%c",warehouse[i]);
        if(i==MaxCrops-1)
            printf("\n");

    }

    
    pthread_mutex_unlock(&mutex);
    
}
void *ShopOwner(void *sho)
{   

    char item;
    for(int ln=0;ln<MaxCrops;ln++)
    {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    item=crops[out];
     warehouse[out]='N';
    printf("Shop owner %d: Remove crops %c from %d\n", *((int *)sho), item, out);
    out = (out+1)%warehouseSize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    }
    pthread_mutex_lock(&mutex);
    printf("ShopOwner%d: ", *((int *)sho));
    for(int i=0;i<MaxCrops;i++){
        printf("%c",warehouse[i]);
        if(i==MaxCrops-1)
            printf("\n");
    }    
    pthread_mutex_unlock(&mutex);



}

int main()
{   
    
    pthread_t Far[5],Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,warehouseSize);
    sem_init(&full,0,0);

    int a[5] = {1,2,3,4,5}; 
   
    for(int i = 0; i < 5; i++){
		pthread_create(&Far[i], NULL, (void *)Farmer, (void *)&a[i]);}

	for(int i = 0; i < 5; i++){
		pthread_create(&Sho[i], NULL, (void *)ShopOwner, (void *)&a[i]);}
	
    for(int i = 0; i < 5; i++){
		pthread_join(Far[i], NULL);}
	
    for(int i = 0; i < 5; i++){
		pthread_join(Sho[i], NULL);}
    
    pthread_mutex_destroy(&mutex);
    
    sem_destroy(&empty);
    
    sem_destroy(&full);

    return 0;
    
}
