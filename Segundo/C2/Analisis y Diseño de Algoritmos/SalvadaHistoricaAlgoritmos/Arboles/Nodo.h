#pragma once

// Nodo del �rbol binario de b�squeda
struct Nodo {
	int contenido; // Contenido del nodo
	Nodo *padre; // Apunta al padre, o NULL si no tiene
	Nodo *hijoIzquierdo; // Apunta al hijo izquierdo, o NULL si no tiene hijo izquierdo
	Nodo *hijoDerecho; // Apunta al hijo derecho, o NULL si no tiene hijo derecho

	Nodo(int v,Nodo *pad=nullptr, Nodo *hijoIzq = nullptr, Nodo* hijoDer = nullptr)
    {
      contenido=v;
      padre=pad;
	  hijoIzquierdo = hijoIzq;
	  hijoDerecho = hijoDer;
    }
};

