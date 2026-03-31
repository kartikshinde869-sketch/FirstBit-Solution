#include<stdio.h>
void main()
{
	int no;
	int Square,Cube;
	printf("Enter the Number:");
	scanf("%d",&no);
	Square=no*no;
	printf("Square of %d = %d\n",no,Square);
	Cube=no*no*no;
	printf("Cube of %d = %d\n",no,Cube);
}