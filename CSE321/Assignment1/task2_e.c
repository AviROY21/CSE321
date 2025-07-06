#include <stdio.h>
#include <string.h>
int main()
{
    char str[70];
    printf("Enter the string:");
    scanf("%s",str);
    int flag=0;
    int mid_idx=strlen(str)/2;
    int len=strlen(str);
    for (int i=0;i<mid_idx;i++){
        if (str[i]!=str[len-i-1]){
            flag=1;
        }
        else{
            flag=0;
        }
    }
    if(flag==1){
        printf("Not Palindrome");
    }
    else{
        printf("Palindrome");
    }

    return 0;
}

