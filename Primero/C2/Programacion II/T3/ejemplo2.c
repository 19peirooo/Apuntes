#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	int *arr1=NULL;
	int *arr2=NULL;
	int tamArr=0;
	int tamArr2=0,tamArr2Max=0;
	
	
	srand(time(NULL));
	
	printf("Introduce el tamaño de los arrays: ");
	scanf("%d", &tamArr);
	while (getchar() != '\n');
	
	arr1 = (int*)malloc(sizeof(int)*tamArr);
	
	for (int i = 0; i < tamArr; i++){
		arr1[i] = rand()%10 + 1;
	}
	
	for (int i = 0; i < tamArr; i++){
		if (tamArr2 == tamArr2Max){
			tamArr2Max+=4;
			arr2 = (int*)realloc(arr2,sizeof(int)*tamArr2Max);
		}
		arr2[i] = arr1[i]; 
		printf("%d %d\n", arr1[i],arr2[i]);
	}
	
	free(arr1);
	free(arr2);
	return 0;
}