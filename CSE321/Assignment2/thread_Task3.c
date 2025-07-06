#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int lin[3];
int idx=0;
void *str_match(){
char line[500];
printf("Enter a string\n");
fgets(line,sizeof(line),stdin);
int a=0;
	for (int i=0;line[i]!='\0';i++){

	    a+=line[i];
	}
	   lin[idx]=a;
	   idx+=1; 
	}
int main(){
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_create(&t1,NULL,str_match,NULL);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,str_match,NULL);
	pthread_join(t2,NULL);
	pthread_create(&t3,NULL,str_match,NULL);
	pthread_join(t3,NULL);

if(lin[0]==lin[1] && lin[1]==lin[2] && lin[0]==lin[2]){
printf("Youreka");
}
else if(lin[0]==lin[1] || lin[1]==lin[2] || lin[0]==lin[2]){
printf("Miracle\n");
}
else{
printf("Hasta la vista\n");
}
return 0;
}

