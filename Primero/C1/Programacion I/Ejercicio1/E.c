/*Ejercicio E
Crear un programa que pida al usuario dos vectores de dos números (cuatro números entotal) en coma flotante. Cada grupo de dos números representa un vector de doscomponentes llamadas “x” “y”. 
El programa indicará si los dos vectores introducidos son similares entre sí:
- Dividir las componentes (x, y) del primer vector entre las componentes (x, y) del segundo vector (x1/x2, y1/y2)
- Comparar si los resultados de las divisiones son similares:
	o Son similares si la diferencia entre las divisiones menor de 0.01 unidades
- El programa indicará que si son similares.*/

#include <stdio.h>


int main(){
	float x1,x2,y1,y2, div_x,div_y, diferencia;
	printf("Introduce el vector uno en formato x,y: \n");
	scanf("%f,%f",&x1,&y1);
	printf("Introduce el vector dos en formato x,y: \n");
	scanf("%f,%f",&x2,&y2);
	if (x2 == 0 || y2 == 0){
		printf("Vectores no divisibles");
		return 0;
	}
	else{
		div_x = x1/x2;
		div_y = y1/y2;
	}
	
	diferencia = div_x - div_y;
	if (diferencia < 0){
		diferencia *= -1;
	}
	if ( diferencia < 0.01){
		printf("Los vectores son similares");
	}
	else{
		printf("Los vectores no son similares");
	}
	return 0;
}