#include "../assertdomjudge.h"
using namespace std;

char calcular_ganador(char* equipos, int n, int ronda) {
    if (n <= 1) {
        return equipos[0];
    }

    char* izq = equipos;
    int len_izq = n/2;
    char* der = equipos + n/2;
    int len_der = n - n/2;

    char ganador_izq = calcular_ganador(izq,len_izq,ronda+1);
    char ganador_der = calcular_ganador(der,len_der,ronda+1);
    char ganador;
    if (ronda % 2 == 0) {
        ganador = ganador_izq;
    } else {
        ganador = ganador_der;
    }
    cout << "Ganador Ronda " << ronda << ": " << ganador << endl;
    return ganador;
}

int main() {
 int n;
 cin >> n;
 assertdomjudge(n > 0 && (n & (n - 1)) == 0);
 char *equipos = new char[n+1];
 for(int i = 0;i <n; i++)
    equipos[i]='A'+i;
 equipos[n]=0;
 calcular_ganador(equipos,n,0);
}