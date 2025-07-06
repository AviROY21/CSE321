//20301269
//your main method should take 2 arguements, the arguements should be numbers. after getting those numbers it will print which number.

// 20301269
#include <stdio.h>

#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    if (num1>num2) {
        printf("%d is > than %d\n", num1,num2);
    } else if (num2>num1) {
        printf("%d is > than %d\n", num2,num1);
    } else {
        printf("%d and %d are equal\n", num1,num2);
    }

    return 0;
}
