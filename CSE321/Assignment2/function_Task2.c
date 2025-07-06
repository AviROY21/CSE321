#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int perfectnum(int i){
int div=0;
for(int n=1;n<i;n++)
{
 if(i%n==0){
 div+=n;
 }

}
if(i==div){
printf("%d\n",i);

}
else{
return 0;

}

}
int main(){
int num1;
int num2;
int func=0;
printf("Enter the number for starting interval:");
scanf("%d",&num1);
printf("Enter the number for ending interval:");
scanf("%d",&num2);
for(int i=0;num1<=num2;num1++){
       func=perfectnum(num1);

}

}

