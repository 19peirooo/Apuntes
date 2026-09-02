#include <stdio.h>

int num;

int main(){
	
	printf("Ingresa un numero del 1 al 7:\n" );
	scanf("%d", &num);
	switch (num){
		case 1:
			printf("Hoy es Lunes");
			break;
		case 2:
			printf("Hoy es Martes");
			break;
		case 3:
			printf("Hoy es Miercoles");
			break;
		case 4:
			printf("Hoy es Jueves");
			break;
		case 5:
			printf("Hoy es Viernes");
			break;
		case 6:
			printf("Hoy es Sabado");
			break;
		default:
			printf("Hoy es Domingo");
			break;
		
	}
	return 0;
}