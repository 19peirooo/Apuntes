/*Ejercicio D
Multiplicar dos números enteros de tres cifras usando el algoritmo queaprendimos en la escuela primaria:
*/

#include <stdio.h>

int main(){
	int num1,num2,centena,decena,calc_centena,calc_decena,calc_unidad,unidad,resultado;
	printf("Introduce la multiplicacion de numeros de 3 cifras separando los numeros con un x: \n");
	scanf("%dx%d", &num1,&num2);
	if ((num1 >= 100 && num1 <= 999) && (num2 >= 100 && num2 <= 999)){
		centena = num2/100;
		decena = (num2 - (centena*100))/10;
		unidad = (num2 - (centena*100) - (decena*10));
		calc_centena = num1*centena*100;
		calc_decena = num1*decena*10;
		calc_unidad = num1*unidad;
		resultado = calc_centena + calc_decena + calc_unidad;
		printf("Resultado: %d", resultado);
	}
	else{
		printf("Uno de los numeros no es de 3 cifras");
	}
	return 0;
}