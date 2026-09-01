#include <iostream>
using namespace std;
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

/*  Verificador de Palindromos
    Comprueba si una palabra es un palindromo
    Precondicion: La cadena no puede esta vacia y ha de tener menos de 21 caracteres
    Complejidad Temporal: T(n) = 1 + T(n-2), O(n)
    Complejidad Espacial: M(n) 1
*/

int esPalindromo(string palabra, int inicio, int fin) {
    //Caso Base. Se ha recorrido la mitad de la palabra
    if (inicio >= fin) { //T(1)
        return 1;
    }

    //Caso Base 2. Los caracteres no son iguales entonces la palabra no es un palindromo
    if (palabra[inicio] != palabra[fin]){
        return 0;
    }

    return esPalindromo(palabra,inicio+1,fin-1); //T(n-2)
}

int main(){
    string cadena;
    cin >> cadena;
    assertdomjudge(cadena.length()<=20 && cadena.length() > 0);
    cout << esPalindromo(cadena,0,cadena.length()-1) << endl;
}