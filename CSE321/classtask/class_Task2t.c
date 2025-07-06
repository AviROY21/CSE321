#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

void *print_odd(void *arg) {
    int *n = (int *)arg;
    int i;
    for (i = 1; i <= *n; i++) {
        if (i % 2 != 0) {
            printf("Odd thread: %d\n", i);
        }
    }
    pthread_exit(NULL);
}

void *print_fibonacci(void *arg) {
    int *n = (int *)arg;
    int i, a = 0, b = 1, temp;
    for (i = 0; i < *n; i++) {
        printf("Fibonacci thread: %d\n", a);
        temp = a;
        a = b;
        b = temp + b;
    }
    pthread_exit(NULL);
}

int main() {
    int pid, status;
    pid = fork();

    if (pid == 0) {
        printf("Enter how many numbers you want to enter:");
        int n;
        scanf("%d", &n);

        pthread_t t1, t2;

        // Create thread 1 to print odd numbers
        pthread_create(&t1, NULL, print_odd, &n);

        // Create thread 2 to print Fibonacci numbers
        pthread_create(&t2, NULL, print_fibonacci, &n);

        // Wait for both threads to finish
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
    }

    if (pid > 0) {
        wait(&status);
    }

    return 0;
}
