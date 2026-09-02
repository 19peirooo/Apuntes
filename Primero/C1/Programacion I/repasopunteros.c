#include <stdio.h>

float sumareal(float r1,float r2);
float sumaimg(float i1,float i2);
void sumaComplejos(float r1, float r2, float i1, float i2, float *sumaReal, float *sumaImg);

int main(){
	float r1,r2,i1,i2,res_r,res_i;
	printf("Introduce el primero complejo en formato x+yi: ");
	scanf("%d+%di",&r1,&i1);
	printf("Introduce el segundo complejo en formato x+yi: ");
	scanf("%d+%di",&r2,&i2);
	sumaComplejos(r1,r2,i1,i2,&res_r,&res_i);
}

float sumareal(float r1,float r2){
	return r1+r2;
}

float sumaimg(float i1,float i2){
	return i1+i2;
}

void sumaComplejos(float r1, float r2, float i1, float i2, float *sumaReal, float *sumaImg){
	*sumaReal = sumareal(r1,r2);
	*sumaImg = sumaImg(i1,i2);
}