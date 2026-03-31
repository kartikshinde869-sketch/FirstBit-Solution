#include<stdio.h>
void main()
{
	int sec=3608;
	int hrs,remsec,min;
	min=sec/60;
	remsec=sec%60;
	hrs=min/60;
//	remmin=min%60;
	printf("hrs : %d\nmin : %d\nremsec : %d\n",hrs,min,remsec);
}