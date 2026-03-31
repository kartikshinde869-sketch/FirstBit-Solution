#include<stdio.h>
void main()
{
	int no=17;
	int i=2, flag=0;
	while(i<=no/2)
	{
		if(no%i==0){
		flag=1;
		break;
	}
	i++;
}
    if(flag==0)
    printf("no. is Prime");
    else
    printf("no. is not Prime");
}