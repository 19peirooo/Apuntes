#include <stdio.h>
#include <math.h>

int suma(int a,int b, int*suma);
int resta(int a,int b, int* resta);
int multiplica(int a,int b, int c, int d, int* multiplicarr, int* multiplicari);

int main(){
	int r1,i1,r2,i2, sumar, sumai, restar, restai, multiplicacionr, multiplicacioni;
	printf("Introdice la parte real del numero 1: ");
	scanf("%d", &r1);
	printf("Introdice la parte imaginaria del numero 1: ");
	scanf("%d", &i1);
	printf("Introdice la parte real del numero 2: ");
	scanf("%d", &r2);
	printf("Introdice la parte imaginaria del numero 2: ");
	scanf("%d", &i2);
	
	suma(r1,r2,&sumar);
	suma(i1,i2,&sumai);
	resta(r1,r2,&restar);
	resta(i1,i2,&restai);
	multiplica(r1,i1,r2,i2,&multiplicacionr,&multiplicacioni);
	
	printf("Suma: %d + %di\n",sumar,sumai);
	printf("Resta: %d + %di\n",restar,restai);
	printf("Multiplicacion: %d + %di",multiplicacionr,multiplicacioni);
	return 0;
}

int suma(int a, int b, int* suma){
	*suma = a+b;
	return *suma;
}

int resta(int a, int b, int* resta){
	*resta = a-b;
	return *resta;
}

int multiplica(int a,int b, int c, int d, int* multiplicarr, int* multiplicari){
	*multiplicarr = a*c-b*d;
	*multiplicari = a*d+b*c;
	return *multiplicarr;
}