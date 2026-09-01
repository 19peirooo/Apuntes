#include "../assertdomjudge.h"
using namespace std;

void imprimir(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
}

bool buscar(int x[], int n, int num) {
    if (n <= 1) {
        if (x[0] == num) {
            return true;
        } else {
            return false;
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
        return buscar(izq,len_izq,num) || buscar(der,len_der,num);
    }
}

int main() {
    int n;
    int num;
    cin>>n;
    int *x=new int[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    cin >> num;
    bool encontrado = buscar(x,n,num);
    if (encontrado) {
        cout << "ENCONTRADO!!" << endl;
    } else {
        cout << "NO ENCONTRADO!!" << endl;
    }
}