#include <stdio.h>

double probNumero(int a);
void comprobarNumerosRepetidos(int a, int *b , int *c);
double calcProbPueblo(int a, int b, int c);
double calcProbMateria(int p);
int casosNum(int a);

int main(){
	int opcion = 0,num1_p1=0,num2_p1=0,num3_p1=0,prob_p1=0,num1_p2=0,num2_p2=0,num3_p2=0,prob_p2,num_pueblos,prob_materia;
	while (opcion != 1 && opcion != 2){
		printf("Introduce 1 para ver que pueblo tiene mayor probabilidad\n");
		printf("Introduce 2 para ver la probabilidad de una materia prima\n");
		scanf("%d",&opcion);
	}
	if (opcion == 1){
		printf("Introduce 0 sin el pueblo no tiene 3 numeros\n");
		printf("Introduce los numeros del pueblo 1 separados por coman sin espacios(2-12): ");
		scanf("%d,%d,%d",&num1_p1,&num2_p1,&num3_p1);
		printf("Introduce los numeros del pueblo 2 separados por coman sin espacios(2-12): ");
		scanf("%d,%d,%d",&num1_p2,&num2_p2,&num3_p2);
		comprobarNumerosRepetidos(num1_p1,&num2_p1,&num3_p1);
		comprobarNumerosRepetidos(num1_p2,&num2_p2,&num3_p2);
		prob_p1 = calcProbPueblo(num1_p1,num2_p1,num3_p1);
		prob_p2 = calcProbPueblo(num1_p2,num2_p2,num3_p2);
		printf("La probabilidad de obtener una carta en el pueblo 1 es: %d%\n",prob_p1);
		printf("La probabilidad de obtener una carta en el pueblo 2 es: %d%\n",prob_p2);
	}
	else if (opcion == 2){
		printf("Introduce el numero de pueblos que tengan numero es esa materia: ");
		scanf("%d", &num_pueblos);
		prob_materia = calcProbMateria(num_pueblos);
		printf("La probabilidad de recibir esa materia es: %d%\n", prob_materia);
	}
	else{
		opcion = 0;
	}
	return 0;
}

int casosNum(int a){
	int casos;
	if (a <= 7 && a > 1){
		casos = a-1;
	}
	else if (a > 7 && a <= 12){
		casos = a-13;
		casos*=-1;
	}
	else{
		casos = 0;
	}
	return casos;
}

double probNumero(int a){
	double prob,casos;
	casos = casosNum(a);
	prob = casos/36;
	return prob;
}

double calcProbMateria(int p){
	double suma = 0, res;
	int num, posib = 0;
	int numsintroducidos[11] = {0};
	for(int i = 0; i < p; i++){
		while (num < 2 && num > 12){
			printf("Introduce el numero del pueblo %d: ", (i+1));
			scanf("%d", &num);
		}
		if (numsintroducidos[num-2] > 0){
			suma += 0;
		}
		else{
			suma += probNumero(num);
			numsintroducidos[num-2]++;
		}
	}
	res = suma*100;
	return res;
}

void comprobarNumerosRepetidos(int a, int *b, int *c){
	if (a == *b){
		*b = 0;
	}
	if (a == *c || *b == *c){
		*c = 0;
	}
}

double calcProbPueblo(int a,int b,int c){
	double res;
	res = (probNumero(a)+probNumero(b)+probNumero(c))*100;
	return res;
}