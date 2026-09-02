#include <stdio.h>
#include <limits.h>

int x = 15,
signed int y = -15

void main(){
	printf("int ocupa: %d bytes\n",sizeof(int));
	printf("El valor minimo para int es: %d\n",INT_MIN);
	printf("El valor maximo para int es: %d\n",INT_MAX);
	
	printf("signed int ocupa: %d bytes\n",sizeof(signed int));
	printf("El valor minimo para  signed int es: %d\n",SCHAR_MIN);
	printf("El valor maximo para signed int es: %d\n",SCHAR_MAX);
	
	printf("unsigned int ocupa: %d bytes\n",sizeof(unsigned int));
	printf("El valor maximo para unsigned int es: %d\n",UCHAR_MAX);
	
	
	printf("long int ocupa: %d bytes\n",sizeof(long int));
	printf("El valor minimo para long int es: %d\n",LONG_MIN);
	printf("El valor maximo para long int es: %d\n",LONG_MAX);
	
	printf("short int ocupa: %d bytes\n",sizeof(short int));
	printf("El valor minimo para short int es: %d\n",SHRT_MIN);
	printf("El valor maximo para short int es: %d\n",SHRT_MAX);
	
	printf("%x %x", x,y);
}