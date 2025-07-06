#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[2];

    printf("Enter two numbers: ");
    scanf("%d %d", &arr[0], &arr[1]);

    printf("Before swap: %d %d\n", arr[0], arr[1]);

    swap(&arr[0], &arr[1]);

    printf("After swap: %d %d\n", arr[0], arr[1]);

    return 0;
}
