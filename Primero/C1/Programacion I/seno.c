#include <stdio.h>
#include <math.h>
void main(){
	for (double i = 0;i <= 10;i+=0.5){
		double y = sin(2*i)-i;
		printf("x=%5.2lf \t\t y=%5.2lf\n",i,y);
	}
}