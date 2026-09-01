#include <iostream>
#include "../assertdomjudge.h"
using namespace std;

bool esPalindromo(string cadena, int inicio, int final) {
    if (inicio >= final) {
        return true;
    }
    if (cadena[inicio]==cadena[final]){
        return esPalindromo(cadena,inicio+1,final-1);
    } else {
        return false;
    }
}

int main(){
    string cadena;
    cin >> cadena;
    assertdomjudge(cadena.length()<=20 && cadena.length() > 0);
    cout << esPalindromo(cadena,0,cadena.length()-1) << endl;
}