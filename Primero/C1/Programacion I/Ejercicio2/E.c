#include <stdio.h>

void pedirMedidas(int *a,int *b, int *c, int n);
int calcTipoDeCaja(int a, int b, int c,int *d);

int main(){
	int tipoCaja,ancho,alto,fondo,numCajas = -1, i = 1,pequeña=0,mediana=0,grande=0,noval=0, total;
	while (numCajas < 0){
		printf("Introduce el numero de productos: ");
		scanf("%d",&numCajas);
	}
	while (i <= numCajas){
		pedirMedidas(&ancho,&alto,&fondo,i);
		if (ancho > 0 && alto > 0 && fondo > 0){
			i++;
			calcTipoDeCaja(ancho,alto,fondo,&tipoCaja);
			if (tipoCaja == 1){
				pequeña += 1;
			}
			else if (tipoCaja == 2){
				mediana += 1;
			}
			else if (tipoCaja == 3){
				grande += 1;
			}
			else{
				noval += 1;
			}
		}
		else {
			printf("Dimensiones incorrectas. Intentalo de nuevo\n");
		}
	}
	total = pequeña+mediana+grande;
	printf("Datos:\n");
	printf("Numero de cajas utilizadas: %d\n",total);
	printf("Cajas Pequenyas: %d\n",pequeña);
	printf("Cajas Medianas: %d\n",mediana);
	printf("Cajas Grandes: %d\n",grande);
	printf("Productos no validos: %d\n",noval);
	return 0;
}

void pedirMedidas(int *a, int *b, int *c, int n){
	printf("Producto %d:\n", n);
	printf("Dimensiones en formato anchoxaltoxfondo: ");
	scanf("%dx%dx%d",&*a,&*b,&*c);
}

int calcTipoDeCaja(int a, int b, int c, int *d){
	if (a <= 10 && b <= 10 && c <= 15){
		*d = 1;
	}
	else if (a <= 20 && b <= 15 && c <= 15){
		*d = 2;
	}
	else if (a <= 30 && b <= 25 && c <= 20){
		*d = 3;
	}
	else{
		*d = 0;
	}
	return *d;
}