#include <iostream>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/*  Calculadora Numero Combinatorio
    Calcula la Raiz Cuadrada de un numero mediante aproximaciones sucesivas. Calcula hasta que la diferencia entre 
    la aproximacion al cuadrado y el numero sea menor que 0
    Precondicion: n >= 0, error > 0
    Complejidad Temporal: T(n) = 1 + T(n-1),O(n) --> Se ejecuta n, la siguiente es n-1
    Complejidad Espacial: O(1) --> Solo se crean variables
*/

int factorial(int n){
    if (n < 2){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main(){
    int n=0,r=0,result=0;

    while (n>=0){
        std::cin>>n;
        std::cin>>r;

        if (n > 0) {
            assertdomjudge(r > 0 || n > r)
            result = (factorial(n))/((factorial(r))*(factorial(n-r)));
            std::cout << result << std::endl;
        }
    }
}