#include <iostream>
using namespace std;

void imprimir(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
}

void combinar(int a[],int b[], int res[], int len_a, int len_b) {
    int i=0,j=0,k = 0;

    while (i < len_a && j < len_b) {
        if (a[i] < b[j]) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }

    while (i < len_a) {
        res[k++] = a[i++];
    }

    while (j < len_b) {
        res[k++] = b[j++];
    }
}

void ordenar(int x[], int n) {
    int temp[n];
    if (n <= 1) {
        return;
    } else {
        int *izq = x;
        int len_izq = n/2;
        int *der = x + n/2;
        int len_der = n - n/2;
        imprimir(izq,len_izq);
        cout << " / ";
        imprimir(der,len_der);
        cout << endl;
        ordenar(izq,len_izq);
        ordenar(der,len_der);
        combinar(izq,der,temp,len_izq,len_der);
        for (int i = 0; i < n; i++) {
            x[i] = temp[i];
        }
        imprimir(x,n);
        cout << endl;
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