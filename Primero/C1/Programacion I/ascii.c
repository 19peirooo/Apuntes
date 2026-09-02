
#include <stdio.h>

int main(){
	char caracter = 'A';
	int ascii;
	ascii = ("%d",caracter);
	ascii += 32;
	printf("%c", ascii);
	
	float num;
	printf("\n Introduce un numero con decimales: ");
	scanf("%f",&num);
	printf("%f", num + 4);
	
	float f1 = 12.5;
	float f2 = 0.1;
	float suma = f1 + f2;
	float f3 = 12.6;
	printf("%f", suma);
	if ((suma) == 12.6){
		printf("El resultado es 12.6\n");
	} 
	else{
		printf("\n Wa Wa");
		printf("12.6 = : %a \n", f3);
	}
	
	int x = printf("Viva el espagnol");
	printf("%d", x);
	return 0;
}