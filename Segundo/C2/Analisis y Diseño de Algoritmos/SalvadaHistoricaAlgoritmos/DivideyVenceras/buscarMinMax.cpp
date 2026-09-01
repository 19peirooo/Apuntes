#include "../assertdomjudge.h"
using namespace std;

void imprimir(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
}

void buscarMinMax(int x[], int n, int* max, int* min) {
    if (n <= 1) {
        for (int i = 0; i < n; i++) {
            if (x[i] < *min) {
                *min = x[i]; 
            } else if (x[i] > *max) {
                *max = x[i];
            }
        }
    } else {
        int* izq = x;
        int* der = x + n/2;
        int len_izq = n/2;
        int len_der = n - n/2;

        imprimir(izq,len_izq);
        cout << " | ";
        imprimir(der,len_der);
        cout << endl;

        buscarMinMax(izq,len_izq,max,min);
        buscarMinMax(der,len_der,max,min);
        cout << "Max: " << *max << " | Min: " << *min << endl;
    }
}

int main() {
    int n;
    int max = INT16_MIN;
    int min = INT16_MAX;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    buscarMinMax(x,n,&max,&min);
}