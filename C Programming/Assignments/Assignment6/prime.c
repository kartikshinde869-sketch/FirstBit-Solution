int prime();
void main()
{ 
//   int res; 
//   res=	prime();
   if(prime())
   printf("prime");
   else
   printf("non prime");
}
int prime()
{
	int no=7;
	for(int i=2; i<no; i++){
		if(no%i==0)
		return 0;
	}
	return 1;
}