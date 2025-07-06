#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> 

int main(){

  int pid,status;

  pid=fork();

  if(pid==0){
    printf("Enter the desired numbers to take:");
    int n;
    scanf("%d",&n);
    int arr[n];

    int a;
    int temp=0;

    for(int i=0;i<n;i++){
      scanf("%d",&a);
      arr[i]=a;
    }
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if (arr[i]<arr[j]){
          temp=arr[j];
          arr[j]=arr[i];
          arr[i]=temp;
        }
      }
    }
    for(int i=0;i<n;i++){
      printf("%d",arr[i]);
      printf(" ");
    }
    printf("\n");
  }

  if(pid>0){
    wait(&status);
    printf("Enter the desired numbers to take:");
    int n1;
    scanf("%d",&n1);
    int arr1[n1]; 

    int a1;

    for(int i=0;i<n1;i++){
      scanf("%d",&a1);
      arr1[i]=a1;
    }
    for(int i=0;i<n1;i++){
      if(arr1[i]%2!=0){
        printf("Odd Number\n");
      }
      else{
        printf("Even Number\n");
      }
    }
  }
}
