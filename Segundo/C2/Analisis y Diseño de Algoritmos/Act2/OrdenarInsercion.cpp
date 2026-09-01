#include <iostream>
using namespace std;

/*  Ordenacion por Insercion
    Compara numeros adjacentes y lo coloca el menor hasta que haya uno menor que el
    Precondicion: La lista no puede estar vacia
    Complejidad Temporal: T(n) = n^2/2 + n/2 + 1,O(n^2) --> n = longitud de la lista 
    Complejidad Espacial: O(1) --> No se crea ningun tipo de memoria adicional

*/

void ordenarInsercion(int x[],int len) {
    for(int i=1;i<len;i++) {
        int elemento = x[i];
        int posicionHueco = i-1;
        while (posicionHueco >= 0 && x[posicionHueco] > elemento) {
            x[posicionHueco + 1] = x[posicionHueco];
            posicionHueco--;
        }
        x[posicionHueco+1] = elemento;
        for(int k=0;k<len;k++) {
            cout<<x[k]<<" ";
        }   
        cout<<endl;
    }  
}


int main() {
    int n;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    ordenarInsercion(x,n);
}