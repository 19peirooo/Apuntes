#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	/*int num,randnum;
	srand(time(0));
	randnum = (rand()%10);
	while (num != randnum){
		printf("Introduce un numero del 1 al 10: \n");
		scanf("%d",&num);
	}*/
	
	double i = 100, ni;
	int d = 20;
	
	ni = (i - (i*((double)d/100)));
	printf("%lf",ni);
	ni *= 1.21;
	printf("%lf",ni);
	
}