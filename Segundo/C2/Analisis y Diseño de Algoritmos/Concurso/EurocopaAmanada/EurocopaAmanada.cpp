#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
using namespace std;

char calcular_ganador(char *equipos, int n, int ronda) {
    if (n == 1) {
        return equipos[0];
    }

    int mitad = n/2;
    char* arrIzq = new char[mitad];
    char* arrDer = new char[n-mitad];
    for (int i = 0; i < n/2; i++){
        arrIzq[i] = equipos[i];
    }

    for (int i = 0; i < n - n/2; i++) {
        arrDer[i] = equipos[n/2 + i];
    }
    
    char ganadorIzq = calcular_ganador(arrIzq,mitad,ronda+1);
    char ganadorDer = calcular_ganador(arrDer,n-mitad,ronda+1);
    char ganador;
    if (ronda % 2 == 0) {
        ganador = ganadorDer;
    } else {
        ganador = ganadorIzq;
    }
    cout << "Ronda " << ronda << " Ganador: " << ganador << endl;
    return ganador;
}


int main() {
 int n;
 cin >> n;
 assertdomjudge(n % 2 == 0);
 char *equipos = new char[n+1];
 for(int i = 0;i <n; i++)
    equipos[i]='A'+i;
 equipos[n]=0;
 calcular_ganador(equipos,n,0);
}