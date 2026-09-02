#include <iostream>
using namespace std;
#define N_TIPO_CENTRALES 5
char tipo_centrales [N_TIPO_CENTRALES] = {'E','S','H','N','T'};
#define assertdomjudge(x) if(!(x)) {cout << "ERROR" << endl; exit;}

void imprimir(char* x, int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i];
	}
	cout << endl;
}

void fuentesRenovables(int n, int r, char* combinacion, int indice, int numRenovables) {
	
	if (indice == n && numRenovables == r) { //Si tengo todas las centrales y tengo el numero de centrales renovables necesito --> Resultado
		imprimir(combinacion,n);
		return;
	} else if (indice == n && numRenovables != r) { //Si tengo todas las centrales y no tengo el numero de centrales renovables que necesito --> Resultado invalido. Nunca voy a llegar al resultado correcto
		return;
	}
	
	for (int i = 0; i < N_TIPO_CENTRALES; i++) {
		combinacion[indice] = tipo_centrales[i]; //Añado la central
		if (i >= 0 && i < 3) {
			fuentesRenovables(n,r,combinacion,indice+1,numRenovables+1); //Si es renovable, añado una renovable
		} else {
			fuentesRenovables(n,r,combinacion,indice+1,numRenovables); //Si no lo es, solo aumento el indice
		}
	}
}

int main() {
	int n;
	int r;
	cin >> n;
	cin >> r;
	assertdomjudge(n > 0 && r >= 0 && n >= r); //Comprueba que, hay por lo menos una central y que no haya mas centrales renovables que centrales en total
	char* combinacion = new char[n];
	fuentesRenovables(n,r,combinacion,0,0);
	
}