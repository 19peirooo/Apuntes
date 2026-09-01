#include "ListaCircular.h"

int buscar_ganador(int n, int s) {
    int ganador = 0;
    for (int i = 0; i < n; i++) {
        ganador = (ganador + (s + 1)) % n;
    }
    if (ganador == 0) {
        ganador = n;
    } 
    return ganador;
}

int main() {
    int n = -1; //numNiños
    int s = -1; //numNiños que nos saltaremos antes de sacar a uno

    while (true) {
        cin >> n;
        cin >> s;
        assertdomjudge(n >= 0 && n <= 10000);
        assertdomjudge(s >= 0 && s <= 1000);
        if (n == 0 && s == 0) {
            break;
        }
        cout << buscar_ganador(n,s) << endl;
        
    }

}