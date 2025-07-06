#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    
    char str[200];
    FILE *fp;
    
    fp=fopen("input.txt","w");
    
    int i=1;
    
    while(i){
        printf("Enter a string:");
        fgets(str,sizeof(str),stdin);
        
        if(strcmp(str,"-1\n")==0){
            break;
        }
        else{
            fprintf(fp,"%s",str);
        }
        
    }
    
    
    
    
    
    return 0;
} 
 

