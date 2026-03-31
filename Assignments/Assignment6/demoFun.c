void ABC();
void XYZ();
void PQR();
void main()
{
    printf("Start \n");	
	ABC();
	XYZ();
	PQR();
	printf("End \n");
}

ABC(){
	XYZ();
	printf("FirstBit \n");
}

XYZ(){
	printf("Solution \n");
	PQR();
}

PQR(){
	printf("JAVA \n");
}