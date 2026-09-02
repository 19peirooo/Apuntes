/*Ejercicio A:
Para una máquina de vending se desea realizar un programa que calcule los billetes y monedas que debe devolver a un cliente después de realizada una compra.
Escribir un programa que como entradas tenga el precio de un producto y el dinero que el cliente introduce y como salida se tiene la vuelta. 
Además, debe indicar el número de billetes y monedas que se deben devolver teniendo en cuanta que se debe devolver el número mínimo de monedasy billetes y 
que los billetes que se utilizan son de 20 euros, 10 euros y 5 euros y las monedas de 2 euros, 1 euro, 0,50 euros, 0,20 euros, 0.10 euros, 0,05 euros, 0,02 euros y 0,01 euro. 
La cantidad máxima que se permite introducir es de 50 euros*/

#include <stdio.h>
#include <math.h> //Para poder redondear numeros y aumentar la precision//

int main(){
	double precio,dinero,vuelta;
	int divisa;
	printf("Introduce el precio del producto: \n");
	scanf("%lf",&precio);
	printf("Introduce el dinero introducido en la maquina: \n");
	scanf("%lf",&dinero);
	if (dinero > 50){
		printf("La maquina no acepta mas de 50 euros \n");
	}
	else if (dinero < precio){
		printf("No tienes dinero para comprar este producto \n");
	}
	else{
		vuelta = dinero - precio;
		printf("La vuelta es: %.2lf euros. Calculando billetes y monedas a devolver.\n", vuelta);
		divisa = vuelta / 20.;
		if (divisa != 0){
			vuelta -= (divisa*20);
			vuelta = round(vuelta*100)/100; /*Redondea a 2 decimales*/
			printf("Se devuelven %d billetes de 20 euros.\n", divisa);
		}
		divisa = vuelta / 10;
		if (divisa != 0){
			vuelta -= (divisa*10);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d billetes de 10 euros.\n", divisa);
		}
		divisa = vuelta / 5;
		if (divisa != 0){
			vuelta -= (divisa*5);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d billetes de 5 euros.\n", divisa);
		}
		divisa = vuelta / 2;
		if (divisa != 0){
			vuelta -= (divisa*2);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 2 euros.\n", divisa);
		}
		divisa = vuelta / 1;
		if (divisa != 0){
			vuelta -= divisa;
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 1 euro.\n", divisa);
		}
		divisa = vuelta / 0.5;
		if (divisa != 0){
			vuelta -= (divisa*0.5);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 50 centimos.\n", divisa);
		}
		divisa = vuelta / 0.2;
		if (divisa != 0){
			vuelta -= (divisa*0.2);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 20 centimos.\n", divisa);
		}
		divisa = vuelta / 0.1;
		if (divisa != 0){
			vuelta -= (divisa*0.1);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 10 centimos.\n", divisa);
		}
		divisa = vuelta / 0.05;
		if (divisa != 0){
			vuelta -= (divisa*0.05);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 5 centimos.\n", divisa);
		}
		divisa = vuelta / 0.02;
		if (divisa != 0){
			vuelta -= (divisa*0.02);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 2 centimos.\n", divisa);
		}
		divisa = vuelta / 0.01;
		if (divisa != 0){
			vuelta -= (divisa*0.01);
			vuelta = round(vuelta*100)/100;
			printf("Se devuelven %d monedas de 1 centimo.\n", divisa);
		}
	}
	
	return 0;
}