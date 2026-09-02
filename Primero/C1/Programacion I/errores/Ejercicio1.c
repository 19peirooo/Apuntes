/*
    Pide tres caracteres por teclado y los ordena alfabeticamente
*/

#include <stdio.h>

void main() {
    char char1, char2, char3;
    int resulValido = 1;

    printf("Introduce 3 caracteres por pantalla separados de un espacio: ");
    scanf("%c %c %c", &char1, &char2, &char3); // Falta el &

    //comprobamos que son minusculas, en caso contrario hacemos la conversion
    
    if (char1 < 97) {
        if ((char1 >= 65) && (char1 <= 90)) {
            char1 = char1 + 32;
        } else {
            resulValido = 0;
        }
    }
    if (char2 < 97) {
        if ((char2 >= 65) && (char2 <= 90)) {
            char2 = char2 + 32;
        } else {
            resulValido = 0;
        }
    }
    if (char3 < 97) {
        if ((char3 >= 65) && (char3 <= 90)) {
            char3 = char3 + 32;
        } else {
            resulValido = 0;
        }
    }

    if (resulValido) {
        if (char1 < char2){
            if (char2 < char3) {
                printf ("%c %c %c", char1, char2, char3);
            } else if (char1 < char3) {
                printf ("%c %c %c", char1, char3, char2);
            }else {
                printf ("%c %c %c", char3, char1, char2);
            }
        } else {
            if (char2 > char3) {
                printf ("%c %c %c", char3, char2, char1);
            } else if (char1 > char3) {
                printf ("%c %c %c", char2, char3, char1);
            }else {
                printf ("%c %c %c", char2, char1, char3);
            }
        }

    } else {
        printf("Los caracteres no eran validos \n");
    }
    
}