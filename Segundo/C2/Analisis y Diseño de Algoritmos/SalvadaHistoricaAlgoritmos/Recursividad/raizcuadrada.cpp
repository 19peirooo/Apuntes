#include "../assertdomjudge.h"
using namespace std;

double calcularRaizCuadrada(double min, double max, double num, double error) {
    double aprox = (min + max)/2;
    cout << aprox << endl;
    double aproxCuadrado = aprox*aprox;
    double resta = aproxCuadrado - num;

    if (abs(resta) <= error) {
        return aprox;
    }

    if (resta > 0) {
        return calcularRaizCuadrada(min,aprox,num,error);
    } else {
        return calcularRaizCuadrada(aprox,max,num,error);
    }
}

int main(int argc, char const *argv[])
{
    double error = 0.0;
    double num = 0.0;

    cin >> num;
    cin >> error;
    assertdomjudge(num >= 0 && error > 0);
    cout << "La raiz cuadrada de " << num << " es :" << endl;
    calcularRaizCuadrada(0,num,num,error);
    return 0;
}
