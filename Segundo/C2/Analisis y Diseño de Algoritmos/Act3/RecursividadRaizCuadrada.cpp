#include <iostream>
#include <math.h>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/*  Calculadora Raiz Cuadrada
    Calcula la Raiz Cuadrada de un numero mediante aproximaciones sucesivas. Calcula hasta que la diferencia entre 
    la aproximacion al cuadrado y el numero sea menor que 0
    Precondicion: n >= 0, error > 0
    Complejidad Temporal: T(n) = T(n/2) + 1 = O(log(n)) 
    Complejidad Espacial: M(n) = M(n/2) + 1 = O(log(n))
*/

void calcularRaizCuadrada(double min, double max, double num, double error) {

    double aprox = (min+max)/2;
    double aproxCuadrado = aprox*aprox;
    cout << aprox << endl;

    if (abs(aproxCuadrado - num) <= error){ // Complejidad de tiempo de abs(x) = O(1) --> Abs = Valor Absoluto
        return;
    } 
    //Si el cuadrado de la aproximacion es mayor, cojo la primera mitad desde la aproximacion ya que necesito un numero mas pequeño
    if (aproxCuadrado > num) { 
        calcularRaizCuadrada(min,aprox,num,error); //T(n) = 1 +T(n/2)
    } else {
        calcularRaizCuadrada(aprox,max,num,error);
    }
}

int main(){
    double num, error;
    cin >> num;
    cin >> error;

    assertdomjudge(num>=0);
    assertdomjudge(error>0);    

    calcularRaizCuadrada(0,num,num,error);

}