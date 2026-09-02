/* 
  Programa que calcula el factorial de un numero
*/

#include <stdio.h>

int factorial (int number);

int main() {

  int myNumber;//no se usa result

  printf("Introduzca un entero positivo: ");
  scanf ("%d", &myNumber);
  printf ("El factorial es: %d \n", factorial(myNumber));//No le pasa el numero a la funcion

  return 0;
}

int factorial (int number) {

  if (number == 0){
    return 1;
  } 
  else {
    return (number* factorial(number-1));
  }
}