#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5
#define BufferSize 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;

char crops[BufferSize] = {'R', 'W', 'P', 'S', 'M'};
char warehouse[BufferSize] = {'N', 'N', 'N', 'N', 'N'};

pthread_mutex_t mutex;

void *Farmer(void *far) {
    int farmer_id = *((int *)far);
    for (int i = 0; i < MaxItems; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        warehouse[in] = crops[in];
        printf("Farmer %d: Insert crops %c at %d\n", farmer_id, warehouse[in], in);
        in = (in + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_mutex_lock(&mutex);
    printf("Farmer%d:", farmer_id);
    for (int g = 0; g < BufferSize; g++) {
        printf(" %c", warehouse[g]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *ShopOwner(void *sho) {
    int shopowner_id = *((int *)sho);
    for (int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        char item = warehouse[out];
        printf("Shop Owner %d: Remove crops %c from %d\n", shopowner_id, item, out);
        warehouse[out] = 'N';
        out = (out + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_mutex_lock(&mutex);
    printf("ShopOwner%d:", shopowner_id);
    for (int w = 0; w < BufferSize; w++) {
        printf(" %c", warehouse[w]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t farm[5], shop[5];
    int a[5] = {1, 2, 3, 4, 5};

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("pthread_mutex_init");
        return 1;
    }
    if (sem_init(&empty, 0, BufferSize) == -1) {
        perror("sem_init");
        return 1;
    }
    if (sem_init(&full, 0, 0) == -1) {
        perror("sem_init");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (pthread_create(&farm[i], NULL, Farmer, (void *)&a[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
        if (pthread_create(&shop[i], NULL, ShopOwner, (void *)&a[i]) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (pthread_join(farm[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
        if (pthread_join(shop[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}


//20301269
