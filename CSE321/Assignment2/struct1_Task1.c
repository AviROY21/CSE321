#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bill{
float quantity;
float price;
};

int main(){

 struct bill Paratha;
 struct bill Vegetables;
 struct bill Mineral_Water;
 
 float total_bill=0;
 float idv_bill=0;
 float people;
 printf("Quantity of Paratha:\n");
 scanf("%f",&Paratha.quantity);
 
 printf("Unit price:\n");
 scanf("%f",&Paratha.price);
 
 printf("Quantity of Vegetables:\n");
 scanf("%f",&Vegetables.quantity);
 
 printf("Unit price:\n");
 scanf("%f",&Vegetables.price);
 
 printf("Quantity of Mineral Water:\n");
 scanf("%f",&Mineral_Water.quantity);
 
 printf("Unit price :\n");
 scanf("%f",&Mineral_Water.price);
 
 printf("Number of people:\n");
 scanf("%f",&people);
 
 total_bill=(Paratha.price*Paratha.quantity)+(Vegetables.price*Vegetables.quantity)+(Mineral_Water.price*Mineral_Water.quantity); 
 
 
 idv_bill=total_bill/people;
 
 printf("Individual people will pay %.2f Tk",idv_bill);
 
 
 
return 0;
}

