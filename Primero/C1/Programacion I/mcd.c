#include <stdio.h>

int main(){
	int num1,num2, mcd, resto;
	printf("Introduce 2 enteros positivos separados por una coma: ");
	scanf("%d,%d",&num1,&num2);
	if (num1 > num2){
		resto = num1 % num2;
		while(resto != 0){
			num1 = num2,
			num2 = resto;
			resto = num1 % num2;
		}
		mcd = num2;
	}
	else if (num1 < num2){
		resto = num2 % num1;
		while(resto != 0){
			num2 = num1,
			num1 = resto;
			resto = num2 % num1;
		}
		mcd = num1;
	}
	else{
		mcd = num1;
	}
	printf("%d",mcd);
}