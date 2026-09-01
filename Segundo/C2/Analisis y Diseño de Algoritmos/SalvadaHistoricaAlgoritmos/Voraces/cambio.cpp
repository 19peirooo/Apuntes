#include "../assertdomjudge.h"
using namespace std;

int monedas[8] = {500,200,100,50,25,10,5,1}; 

void imprimir(int* lista,int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    } 
    cout << endl;
}


void calcularCambio(int n) {
    int res[8] = {0,0,0,0,0,0,0,0};
    int i = 0;
    while (n > 0) {
        int numMonedas = n / monedas[i];
        res[i] = numMonedas;
        n = n % monedas[i];
        i++;
    }
    imprimir(res,8);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    while (n >= 0) {
        cin >> n;
        if (n >= 0) {
            calcularCambio(n);
        }
    }


    return 0;
}
