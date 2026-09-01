#include <iostream>
using namespace std;

void imprimir(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void ordenar(int x[], int n) {
    imprimir(x,n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            if (x[j] > x[j+1]) {
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
                imprimir(x,n);
            }
        }
        cout << "Iteracion " << i << ":"; 
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