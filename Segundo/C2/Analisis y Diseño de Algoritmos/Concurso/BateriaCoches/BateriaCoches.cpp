#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

void bubbleSort(int* x, int len) {
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            if (x[j] > x[j+1]) {
                int temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}

int calcularMaxCoches(int vMin, int* voltajes,int numPilas) {
    int pares = 0;
    bubbleSort(voltajes,numPilas);

    int inicio = 0;
    int final = numPilas -1;
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