#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2

void *producer(void *id);
void *consumer(void *id);

char buffer[BUFLEN];
char source[BUFLEN + 1];
int pCount = 0;
int cCount = 0;
int buflen;
int n = 0;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0, 1};

int main()
{
    pthread_t thread[NUMTHREAD];
    strcpy(source, "abcdef");
    buflen = strlen(source);

    pthread_create(&thread[0], NULL, producer, &thread_id[0]);
    pthread_create(&thread[1], NULL, consumer, &thread_id[1]);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    return 0;
}

void *producer(void *id)
{
    int *id_ptr = (int*)id;
    int thread_id = *id_ptr;
    char item;
    for (int in = 0; in < MAX; in++) {
        item = source[in % buflen];
        pthread_mutex_lock(&count_mutex);
        while (n == buflen) {
            pthread_cond_wait(&full, &count_mutex);
        }
        buffer[in % buflen] = item;
        n++;
        printf("%d produced %c by Thread %d\n", pCount, buffer[in % buflen], thread_id);
        pCount++;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}

void *consumer(void *id)
{
    int *id_ptr = (int*)id;
    int thread_id = *id_ptr;
    char item;
    for (int in = 0; in < MAX; in++) {
        pthread_mutex_lock(&count_mutex);
        while (n == 0) {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        item = buffer[in % buflen];
        n--;
        printf("%d consumed %c by Thread %d\n", cCount, buffer[in % buflen], thread_id);
        cCount++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}
