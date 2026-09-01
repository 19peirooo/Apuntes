#include "../assertdomjudge.h"
using namespace std;

void imprimir(int* lista,int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " + ";
    } 
    cout << endl;
}

bool buscarSuma(int n, int* arr, int len, int suma, int indice, int* res, int nivel, bool* exito) {
    for (int i = indice; i < len && !(*exito); i++) {
        res[nivel] = arr[i];
        if (suma + arr[i] == n) {
            imprimir(res, nivel + 1);
            *exito = true;
            return true;
        } else {
            buscarSuma(n, arr, len, suma + arr[i], i + 1, res, nivel + 1, exito);
        }
    } 
    return *exito;
}


int main() {
    int n,len;
    int* arr;
    int* res;
    bool exito = false;
    cout << "Numero a buscar: ";
    cin >> n;
    cout << "Numero de elemento en la lista: ";
    cin >> len;
    arr = new int[len];
    res = new int[len];
    cout << "Elementos: ";
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    if (buscarSuma(n,arr,len,0,0,res,0,&exito)){
        cout << "Suma Encontrada" << endl;
    } else {
        cout << "Suma No Encontrada" << endl;
    }
}