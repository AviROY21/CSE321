#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char pass[100];
    int idx;
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0; 

    int has_digit = 0;
    int has_upp = 0;
    int has_lower = 0;
    int has_sp = 0;

    for (idx = 0; pass[idx] != '\0'; idx++) {
        if (isdigit(pass[idx])) {
            has_digit = 1;
        }
        if (islower(pass[idx])) {
            has_lower = 1;
        }
        if (isupper(pass[idx])) {
            has_upp = 1;
        }
        if (!isalnum(pass[idx])) {
            has_sp = 1;
        }
    }

    if (has_digit == 1 && has_upp == 1 && has_lower == 1 && has_sp == 1) {
        printf("OK");
    } else {
        if (has_digit == 0) {
            printf("Digit missing\n");
        }
        if (has_sp == 0) {
            printf("Special character missing\n");
        }
        if (has_upp == 0) {
            printf("Uppercase character missing\n");
        }
        if (has_lower == 0) {
            printf("Lowercase character missing\n");
        }
    }

    return 0;
}
