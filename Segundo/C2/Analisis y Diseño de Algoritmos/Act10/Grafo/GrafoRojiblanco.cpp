#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#include "Cola.h"
using namespace std;

/* crearMatrizAdjacencia
    Crea la matriz de adjacencia dondese visualizan las aristas entre vertices
    Entrada: Numero de vertices(V) y aristas(A)
    Salida: Matriz de Adjacencia
    Precondicion: Numero de vertices entre 1 y 100
    Complejidad Temporal: O(V^2 + A)
    Complejidad Espacial: O(V^2)
*/

int** crearMatrizAdjacencia(int numVertices, int numAristas) {
    int** matrizAdjacencia = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        matrizAdjacencia[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            matrizAdjacencia[i][j] = 0;
        }
    }

    for (int i = 0; i < numAristas; i++) {
        int nodo1;
        int nodo2;

        cin >> nodo1;
        cin >> nodo2;

        assertdomjudge(nodo1 != nodo2);
        assertdomjudge(matrizAdjacencia[nodo1][nodo2] == 0);

        matrizAdjacencia[nodo1][nodo2] = 1;
        matrizAdjacencia[nodo2][nodo1] = 1;
    }

    return matrizAdjacencia;
}

/* esRojiblanco
    Comprueba si una grafo se puede colorear con los colores rojo y blanco
    Entrada: Matriz de adjacencia y el numero de vertices
    Salida: True si se puede colorear con rojo y blanco. False si no
    Precondicion: Ninguna
    Complejidad Temporal: O(V^2)
    Complejidad Espacial: O(V)
*/

bool esRojiBlanco(int **matrizAdjacencia, int numVertices) {
    int* coloresVertices = new int[numVertices];
    for (int i = 0; i < numVertices; i++) {
        coloresVertices[i] = -1; //-1 --> Sin Colorear
    }

    for (int i = 0; i < numVertices; i++) {
        if (coloresVertices[i] == -1) {
            coloresVertices[i] = 0; //0 --> Rojo
            Cola* colaBFS = new Cola();
            colaBFS->encolar(i);

            while (!colaBFS->estaVacia()) {
                int verticeActual = colaBFS->desencolar();

                //Busco sus vecinos
                for (int j = 0; j < numVertices; j++) {
                    if (matrizAdjacencia[verticeActual][j] == 1) {
                        if (coloresVertices[j] == -1) {
                            coloresVertices[j] = 1 - coloresVertices[verticeActual]; //Lo hago de el otro color
                            colaBFS->encolar(j);
                        } else if (coloresVertices[j] == coloresVertices[verticeActual]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int numVertices = -1;
    int numAristas = 0;

    while (numVertices != 0) {
        cin >> numVertices;
        if (numVertices == 0) break;
        assertdomjudge(numVertices > 0 && numVertices <= 100);

        cin >> numAristas;

        int** matrizAdjacencia = crearMatrizAdjacencia(numVertices,numAristas);

        if (esRojiBlanco(matrizAdjacencia,numVertices)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }     
}