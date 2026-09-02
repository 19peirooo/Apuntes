#include <stdio.h>

#define MAX 10

void main(){
	char DNI[MAX];
	int dniValido = 0;
	
	do{
		printf("Introduce un DNI: \n");
		fgets(DNI,MAX-1,stdin);
		
		//Compruebo si los primeros 8 son digitos
		for (int i = 0; i<8 && dniValido; i++){
			if (DNI[i]>='0' && DNI[i]<='9'){
				dniValido = 1;
			}
		}
		//Compruebo si caracter 9 en una letra mayuscula y si el decimo es un \0
		if(dniValido && !(DNI[8]>='A' && DNI[8]<='Z')){
			dniValido=0;
		}
		if(dniValido && DNI[9]!='\0'){
			dniValido=0;
		}
	}while (!dniValido);
	printf("DNI Correcto")
}