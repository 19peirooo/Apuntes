#include "../assertdomjudge.h"
using namespace std;



//Insertion Sort
void ordenar(int* x, int n) {

    for (int i = 1; i < n; i++) {
        int key = x[i];
        int j = i - 1;
        while (j >= 0 && x[j] > key) {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
    }

}

void imprimir(int* lista, int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

int calcularMaxCoches(int vMin, int* voltajes, int numPilas) {
    ordenar(voltajes,numPilas);

    int pares = 0;
    int inicio = 0;
    int final = numPilas - 1; 

    while (inicio < final) {
        if (voltajes[inicio] + voltajes[final] >= vMin) {
            pares++;
            inicio++;
            final--;
        } else {
            inicio++;
        }
    }

    return pares;
}

int main() {
    int casosPrueba = 0;
    int numPilas; //numPilas
    int vMin; //Voltaje minimo
    int * voltajes = nullptr;
    cin >> casosPrueba;
    assertdomjudge(casosPrueba > 0);

    for (int i = 0; i < casosPrueba; i++) {
        cin >> numPilas;
        assertdomjudge(numPilas >= 1 && numPilas <= 100000);
        cin >> vMin;
        assertdomjudge(vMin >= 0 && vMin <= 1000000);
        voltajes = new int[numPilas];

        for (int i = 0; i < numPilas; i++) {
            cin >> voltajes[i];
            assertdomjudge(voltajes[i] >= 0 && voltajes[i] <= 1000000);
        }
        cout << calcularMaxCoches(vMin,voltajes,numPilas) << endl;
    }
    
}
