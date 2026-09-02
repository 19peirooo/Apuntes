#include <stdio.h>
#include <stdlib.h>

typedef struct img_t{
	float real;
	float img;
}img_t;

img_t sumaImgs(img_t num1, img_t num2);
img_t restaImgs(img_t num1, img_t num2);
img_t multiplicaImgs(img_t num1, img_t num2);
img_t divideImgs(img_t num1, img_t num2);

int main(int argc, char **argv){
	char op='\0';
	int opValido = 1;
	if (argc != 6){
		printf("Numero de Parametros Incorrecto");
	}else{
		op = argv[1][0];
		img_t num1={
			.real=strtof(argv[2],NULL),
			.img=strtof(argv[3],NULL)
		};
	
		img_t num2={
			.real=strtof(argv[4],NULL),
			.img=strtof(argv[5],NULL)
		};
		img_t res={
			.real=0,
			.img=0
		};
		switch (op){
			case '+':{
				res=sumaImgs(num1,num2);
			}
			break;
			case '-':{
				res=restaImgs(num1,num2);
			}
			break;
			case '*':{
				res=multiplicaImgs(num1,num2);
			}
			break;
			case '/':{
				res=divideImgs(num1,num2);
			}
			break;
			default:{
				opValido=0;
			}
			break;
		}
		if (opValido){
			if (res.img < 0){
				printf("Resultado: %.2f%.2fi",res.real,res.img);
			} else {
				printf("Resultado: %.2f+%.2fi",res.real,res.img);
			}
		}
		else{
			printf("Operador no valido");
		}
	}
	return 0;
}

img_t sumaImgs(img_t num1, img_t num2){
	img_t result={
		.real=(num1.real + num2.real),
		.img=(num1.img + num2.img)
	};
	return result;
}

img_t restaImgs(img_t num1, img_t num2){
	img_t result={
		.real=(num1.real - num2.real),
		.img=(num1.img - num2.img)
	};
	return result;
}

img_t multiplicaImgs(img_t num1, img_t num2){
	img_t result={
		.real=((num1.real*num2.real)-(num1.img*num2.img)),
		.img=((num1.real*num2.img)+(num1.img*num2.real))
	};
	return result;
}

img_t divideImgs(img_t num1, img_t num2){
	float pReal, pImg;
	img_t result={
		.real=0,
		.img=0
	};
	pReal = ((num1.real*num2.real)+(num1.img*num2.img))/((num2.real*num2.real)+(num2.img*num2.img));
	pImg = ((num1.img*num2.real)-(num1.real*num2.img))/((num2.real*num2.real)+(num2.img*num2.img));
	result.real = pReal;
	result.img = pImg;
	return result;
}