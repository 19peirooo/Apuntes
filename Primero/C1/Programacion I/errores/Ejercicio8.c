/*
  Programa que comprueba que un nuemro es mayor que 0 y menor que 8
*/
//Falta el include
#include <stdio.h>

int main () {

  int number = 0;
  printf("Introduce un numero\n");

  scanf("%d", &number);

  if(number < 8 && number > 0) { // Cambiar por 2 condiciones
    printf("El numero es mayor que 0 y menor que 8\n");// Hay un puta x por la putisima cara
  } else {                                                                                                                            
    printf("Numero invalido\n");
  }
  return 0; // return fuera del else
}