#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

void calcularFormasSumar(int n, int suma, int indice, int* combinacion) {
    if (suma == n) {
        for (int i = 0; i < indice; i++) {
            cout << combinacion[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        if (suma + i <= n) {
            combinacion[indice] = i;
            calcularFormasSumar(n,suma+i,indice+1,combinacion);
        } 
    }
}

int main() {
    int n;
    cin >> n;
    int* combinacion = new int[n];
    calcularFormasSumar(n,0,0,combinacion);
}