#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	int *arr1=NULL;
	int *arr2=NULL;
	int err = -1;
	int nums = 0;
	int datoLeido=0;
	
	arr1 = (int*)realloc(NULL,sizeof(int) * nums);
	
	do{
		printf("Introduce un numero: ");
		err = scanf("%d", &datoLeido);
		while (getchar() != '\n');
		if (err == 1){
			arr1 = (int*)realloc(arr1,sizeof(int) * nums+1);
			arr1[nums]=datoLeido;
			nums++;
		}
	} while (err == 1);
	
	arr2 = (int*)malloc(sizeof(int)*nums);
	arr2 = (int*)malloc(sizeof(int)*nums);
	for (int i = 0; i < nums; i++){
		arr2[i] = arr1[i];
		printf("%d %d",arr1[i], arr2[i]);
	}
	
	free(arr1);
	free(arr2);
	return 0;
}