#include <iostream>
using namespace std;

/*  Ordenacion por Seleccion
    Encuentra el elemento menor y lo coloca al principio. Hace lo mismo para la siguente posicion hasta ordenar la lista
    Precondicion: La lista no puede estar vacia
    Complejidad Temporal: T(n) = n^2/2 +3n/2 + 1,O(n^2) --> n = longitud de la lista 
    Complejidad Espacial: O(1) --> Solo se crean variables

*/

void ordenarSeleccion(int x[],int len) {
    for(int i=0;i<len;i++) {
        int min = i;
        for (int j = i+1; j < len;j++){
            if (x[j] < x[min]){
                min = j;
            }
        }

        int temp = x[i];
        x[i] = x[min];
        x[min] = temp;

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
    ordenarSeleccion(x,n);
}