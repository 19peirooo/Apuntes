#include <stdio.h>

int expo(int x, int y);

int main(){
	int x = 3, y = 5, resultado;
	resultado = expo(x,y);
	printf("%d",resultado);
	
}

int expo(int x, int y){
	int res;
	if (y <= 0){
		res = 1;
	}
	else if ((y % 2) == 1){
		res = (x * expo(x,y/2)*expo(x,y/2)); 
	}
	else{
		res = (expo(x,y/2)*expo(x,y/2));
	}
	return res;
}