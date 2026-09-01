#include "../assertdomjudge.h"
using namespace std;

void imprimir(int* lista, int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

void calcularFormasSumar(int n, int suma, int indice, int* combinacion) {
    if (n == suma) {
        imprimir(combinacion,indice);
        return;
    }

    for (int i = 1; i < n; i++) {
        if (suma + i <= n) {
            combinacion[indice] = i;
            calcularFormasSumar(n,suma+i,indice+1,combinacion);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* combinacion = new int[n];
    calcularFormasSumar(n,0,0,combinacion);
    return 0;
}


