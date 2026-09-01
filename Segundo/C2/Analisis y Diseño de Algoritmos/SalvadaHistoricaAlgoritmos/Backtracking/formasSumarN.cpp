#include "../assertdomjudge.h"
using namespace std;

void imprimirCombinacion(int* lista,int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    } 
    cout << endl;
}

void formasSumarN(int n, int suma, int indice, int* combinacion) {
    if (n == suma) {
        imprimirCombinacion(combinacion,indice);
        return;
    }

    for (int i = 1; i < n; i++) {
        if (suma + i <= n) {
            combinacion[indice] = i;
            formasSumarN(n,suma+i,indice+1,combinacion);
        }
    }

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* combinacion = new int[n];
    formasSumarN(n,0,0,combinacion);
    return 0;
}
