#include <iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}
#define NUM_MONEDAS 8 //n


/*  Calculadora de cambio
    Dada una cantidad de pesetas positiva, calcula el menor numero de monedas de cambio que se dan y lo imprime
    Entrada: Cantidad en pesetas.
    Retorno: Ninguno
    Precondicion: La cantidad ha de ser positiva
    Complejidad Temporal: T(n) = 1 , O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void calcularCambio(int cantidad) {

    int cambios[NUM_MONEDAS] = {500,200,100,50,25,10,5,1}; //M(n) = 8 = 1
    int monedasADar[NUM_MONEDAS] = {0,0,0,0,0,0,0,0}; //M(n) = 8 = 1
    int i = 0;

    do {
        int numMonedas = cantidad / cambios[i];
        monedasADar[i] = numMonedas;
        cantidad = cantidad % cambios[i];
        i++;
    } while (cantidad % cambios[i-1] != 0); //T(n) = 8 = 1, M(n) = 1

    for (int j = 0; j < NUM_MONEDAS; j++) { //T(n) = 1, M(n) = 1
        cout << monedasADar[j] << " ";
    }

}

int main(){

    int num;

    do {
        cin >> num;
        if (num >= 0) {
            calcularCambio(num);
        } 
        cout << endl;
    } while (num >= 0);

    

    return 0;
}