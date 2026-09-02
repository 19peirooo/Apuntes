#include <stdio.h>

//Ej2
//Direccion = 0b 0000 0000 1100 1001 0000

int main(int argc, char** argv){

    unsigned int address = 0b00000000110010010000;
    unsigned int word = address & 0b00000000000000111111;
    unsigned int block = address >> 6;
    unsigned int line_from_address = (address & 0b00000000001111000000) >> 6;
    unsigned int line_from_block = (block & 0b00000000001111);
    unsigned int label_from_address = (address & 11111111110000000000) >> 10;
    unsigned int label_from_block = (block & 0b11111111110000) >> 4;

    printf("Direccion %X con palabra %d (d) %X (H)\n", address, word, word);
    printf("con numero de bloque %d (d) %X (H)\n",block,block);
    printf("con linea desde direccion %d (d) %X (H)\n", line_from_address, line_from_address);
    printf("con linea desde bloque %d (d) %X (H)\n", line_from_block, line_from_block);
    printf("con etiqueta desde direccion %d (d) %X (H)\n", label_from_address, label_from_address);
    printf("con etiqueta desde bloque %d (d) %X (H)\n", label_from_block, label_from_block);
}
