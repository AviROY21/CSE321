#include <stdio.h>
#include <stdlib.h>

int addition(float n1,float n2);
int mul(float n1,float n2);
int sub(float n1,float n2);

int main()

{   
    float n1,n2;
    char s[1];
    int r;
    printf("Enter first number:");
    scanf("%f",&n1);
    printf("Enter second number:");
    scanf("%f",&n2);
    printf("Enter operator:");
    scanf("%s",s);
    if(n1>n2){
    
    r=sub(n1,n2);
    
    printf("Result:%d",r);
    
    
    }
    
    else if(n1<n2){
    
    r=addition(n1,n2);
    printf("Result:%d",r);
    
    }
    
    else if(n1==n2){
    r=mul(n1,n2);
    printf("Result:%d",r);
    }
   

    return 0;
}

int sub(float n1,float n2){
   int r;
   r=n1-n2;
   return r;
}

int addition(float n1,float n2){
   int r;
   r=n1+n2;
   return r;

}
int mul(float n1,float n2){
    int r;
    r=n1*n2;
    return r;
}
