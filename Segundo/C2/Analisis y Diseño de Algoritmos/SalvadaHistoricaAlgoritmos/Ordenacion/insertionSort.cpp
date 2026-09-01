#include <iostream>
using namespace std;

void imprimir(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void ordenar(int x[], int n) {
    for (int i = 1; i < n; i++) {
        int key = x[i];
        int j = i - 1;
        while (j >= 0 && x[j] > key) {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key; 
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