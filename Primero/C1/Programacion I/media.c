#include <stdio.h>

int main(){
	int n, num, max, min, suma=0;
	float media;
	printf("Introduce en numero de numeros a introducir: ");
	scanf("%d", &n);
	for (int i=0;i != n;i++){
		printf("Introduce el numero %d: ",i+1);
		scanf("%d",&num);
		suma += num;
		if (max < num){
			max = num;
		}
		if (min > num){
			min = num;
		}
	}
	media = suma/n;
	printf("El mas grande: %d",max);
	printf("\nEl mas petito: %d",min);
	printf("\nMedia: %.2f", media);
	return 0;
}
