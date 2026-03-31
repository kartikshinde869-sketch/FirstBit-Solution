int evenodd();
void main()
{
   
   if(evenodd())
   printf("No is Even");
   else
   printf("No is Odd");
}
int evenodd()
{
	int no;
	
	printf("Enter the No=");
	scanf("%d",&no);
	if(no%2==0)
	   return 1;
	   else
	   return 0;
}