#include <iostream>
using namespace std;

/*  Ordenacion en Burbuja
    Compara numeros adjacentes y ordena la lista de menor a mayor
    Precondicion: La lista no puede estar vacia
    Complejidad Temporal: n^2/2 + n/2 + 1,O(n^2) --> n = longitud de la lista 
    Complejidad Espacial: O(1) --> Solo se crean variables

*/

void ordenarBurbuja(int x[],int len) {
    for(int i=1;i<len;i++) {
        for (int j=0; j<len-i;j++){
            if (x[j] > x[j+1]) {
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp; 
            }
        }
        for(int k=0;k<len;k++)
            cout<<x[k]<<" ";
        cout<<endl;
    }  
}


int main() {
    int n;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    ordenarBurbuja(x,n);
}