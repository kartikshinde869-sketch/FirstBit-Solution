void main()
{
	for(int row=1; row<=4; row++){
		for(int col=1; col<=4; col++){
			if(row==1||row==4||col==1||col==4){
			printf("* ");
		}
			else{
				printf("  ");
			}
			
		}
		    printf("\n");
	}
}