#pragma once
#include "ListaEnlazada.h"

// Imprime una lista enlazada por pantalla (su "n" y sus elementos), con un m�ximo de 20 elementos
// Par�metros:
// - lista: puntero a la lista enlazada que queremos imprimir
// Precondici�n: lista!=NULL
// Complejidad temporal: O(n). Realmente es O(1) porque como maximo imprimira 20 elementos
// Complejidad espacial: O(1)
void imprimirListaEnlazada(ListaEnlazada *lista);

