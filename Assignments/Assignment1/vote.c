#include<stdio.h>
void main()
{
	int age;
	printf("Enter the Age :");
	scanf("%d",&age);
	if(age>=18){
		printf("Person is eligible to Vote");
	}
    else{
    	printf("Person is not eligible to Vote");
	}
}