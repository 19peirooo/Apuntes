/*
Programa de ejemplo de estructura switch.
Pide un caracter y devuelve un color en funcion de ese caracter
*/

#include <stdio.h>

void main() {
  char caracter;

  printf("Introduce uno de estos caracteres por pantalla: b, r, n, v \n"); // Sobre el coma caracter
  scanf("%c", &caracter);

  switch (caracter) { //Faltan los break
    case 'b':
    case 'B':
      printf("Has escogido el color blanco\n");
	  break;

    case 'r':
    case 'R':
      printf("Has escogido el color rojo\n");
	  break;

    case 'n':
    case 'N':
      printf("Has escogido el color negro\n");
	  break;

    case 'v':
    case 'V':
      printf("Has escogido el color verde\n");
	  break;
    default:
      printf("No has escogido ningun color\n");
	  break;
      
  }
  
}