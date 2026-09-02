/*Ejercicio C
Conversor de código RGB a Hexadecimal para colores.
Genera un programa que pida las componentes roja, verde y azul de dos colores por pantalla,muestre su código hexadecimal, y calcule cuál de los dos es más brillante. Para ello:
  - Para generar el código hexadecimal hay que mostrar los valores de las 3 componentesutilizando dos caracteres hexadecimales para cada componente (#RRGGBB), 
    demanera que las RR se corresponden al valor del componente rojo, las GG al verde y las BB al azul.
  - Los valores de cada componente deben estar entre 0 y 255.
  - Si el valor de la componente es menor de 16 ocuparía solo un espacio y hay que rellenarlo con ceros.
  - Utilizar letras mayúsculas en la salida por pantalla.
  - Delante del valor imprime un ‘#’ para indicar que es un código de color hexadecimal.
  - Fórmula para calcular “brillantez” de un color: Brightness = (0.2126*R + 0.7152*G + 0.0722*B)*/
  
  #include <stdio.h>
  
  int main(){
	 int r1,g1,b1,r2,g2,b2;
	 double brillo1,brillo2;
	  
	  printf("Introduce los componentes rojo,verde y azul del color 1 separados por comas: \n");
	  scanf("%d,%d,%d",&r1,&g1,&b1);
	  printf("Introduce los componentes rojo,verde y azul del color 2 separados por comas: \n");
	  scanf("%d,%d,%d",&r2,&g2,&b2);
		if ((r1 < 0 || r1 > 255)||(g1 < 0 || g1 > 255)||(b1 < 0 || b1 > 255)){
			printf("Uno de tus numeros del color 1 es muy bajo o muy grande");
			return 0;
		}
		else if ((r2 < 0 || r2 > 255)||(g2 < 0 || g2 > 255)||(b2 < 0 || b2 > 255)){
			printf("Uno de tus numeros del color 2 es muy bajo o muy grande");
			return 0;
		}
		else{
			brillo1 = (0.2126*r1 + 0.7152*g1 + 0.0722*b1);
			brillo2 = (0.2126*r2 + 0.7152*g2 + 0.0722*b2);
			printf("El Codigo Hex del color 1 es: #%02X%02X%02X \n",r1,g1,b1);
			printf("El Codigo Hex del color 2 es: #%02X%02X%02X \n",r2,g2,b2);
			if (brillo1 > brillo2){
				printf("El Primer Color es mas brillante");
			}
			else if (brillo1 < brillo2){
				printf("El segundo color es mas brillante");
			}
			else{
				printf("Los colores tienen el mismo brillo");
			}		
		}
	 return 0; 
  }