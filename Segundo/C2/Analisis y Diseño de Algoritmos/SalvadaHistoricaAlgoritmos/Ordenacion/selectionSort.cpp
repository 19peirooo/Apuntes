#include <iostream>
using namespace std;

void imprimir(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void ordenar(int x[], int n) {
    for (int i = 0; i < n; i++) {
        int min = x[i];
        int posMin = i;
        for (int j = i+1; j < n; j++) {
            if (x[j] < min) {
                min = x[j];
                posMin = j;
            }
        }
        cout << "Iteracion " << i << ":" << endl << "Antes: ";
        imprimir(x,n);
        x[posMin] = x[i];
        x[i] = min;
        cout << "Despues: ";
        imprimir(x,n);
    }
}

int main() {
    int n;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    ordenar(x,n);
}