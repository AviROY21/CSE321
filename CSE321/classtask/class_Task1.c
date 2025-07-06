#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> 
// Function to print odd numbers
void *print_odd(void *arg) {
    int *n = (int *)arg;
    int i;
    for (i = 1; i <= *n; i++) {
        if (i % 2 != 0) {
            printf("Odd thread: %d\n", i);
            usleep(100000); // sleep for 0.1 seconds
        }
    }
    pthread_exit(NULL);
}

// Function to print Fibonacci numbers
void *print_fibonacci(void *arg) {
    int *n = (int *)arg;
    int i, a = 0, b = 1, temp;
    for (i = 0; i < *n; i++) {
        printf("Fibonacci thread: %d\n", a);
        temp = a;
        a = b;
        b = temp + b;
        usleep(100000); // sleep for 0.1 seconds
    }
    pthread_exit(NULL);
}

int main() {
    int n;
    pthread_t t1, t2;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Create thread 1 to print odd numbers
    pthread_create(&t1, NULL, print_odd, &n);

    // Create thread 2 to print Fibonacci numbers
    pthread_create(&t2, NULL, print_fibonacci, &n);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
