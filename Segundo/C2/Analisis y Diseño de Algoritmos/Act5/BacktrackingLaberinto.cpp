#include<iostream>
#define TAM 10

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4]= {0,1,0,-1};

/*  Imprimir Laberinto
    Imprime el laberinto que se le pase por parametro
    Entrada: El laberinto a imprimir
    Retorno: Ninguno
    Precondicion: Laberinto no puede ser vacio
    Complejidad Temporal: T(n) = n^2 + 1, O(n^2)
    Complejidad Espacial: M(n) = 1, O(1)
*/

void imprimirLaberinto(char** laberinto)
{
  for(int i=0;i<TAM;i++) 
    {
    for(int j=0;j<TAM;j++)
      cout<<laberinto[i][j];
    cout<<endl;
    }
}

/*  Validar posicion
    Mira si la posicion esta dentro del laberinto y si se puede avanzar hacia ella
    Entrada: Las coordenadas x,y y el laberinto
    Retorno: true o false en funcion si la posicion es valida
    Precondicion: El laberinto no puede ser vacio
    Complejidad Temporal: T(n) = 1, O(1)
    Complejidad Espacial: M(n) = 1, O(1)
*/

bool validarPosicion(int x, int y, char** laberinto) {
    return ((x >= 0 && x < TAM) && (y >= 0 && y < TAM) && (laberinto[x][y] == '.' || laberinto[x][y] == 'T'));
}

/*  Buscador de tesoros
    Usando el orden de movimientos: arriba,derecha,abajo y izquierda; comprueba si se puede llegar a un tesoro en un mapa
    Entrada: El laberinto, variable exito, coordenadas actuales del aventurero, coordenadas donde se va a guardar las coordenadas del tesoro
    Retorno: true o false en funcion si el tesoro es alcanzable
    Precondicion: Laberinto no vacio y coordenadas actuales validas
    Complejidad Temporal: T(n) = n^2 + n +1, O(n^2)
    Complejidad Temporal sin Imprimir Laberinto: T(n) = n + 1, O(n)
    Complejidad Espacial: M(n) = n + 1, O(n)
*/

bool buscarTesoro(char** laberinto,bool &exito, int x, int y,int &sol_x, int &sol_y)
{
    int k = 0;
    laberinto[x][y] = 'X';
    for (k = 0; k < 4 && !(exito);k++){ //T(n) = 4 = 1
        int u = x + dx[k];
        int v = y + dy[k];
        if (validarPosicion(u,v,laberinto)) { //T(n) = 1
            if (laberinto[u][v] == 'T') { 
                exito = true;
                sol_x = u;
                sol_y = v;
                imprimirLaberinto(laberinto); //T(n) = n^2
                return true;
            } else if (laberinto[u][v] == '.') {
                buscarTesoro(laberinto,exito,u,v,sol_x,sol_y); //T(n) = T(n) = 1, M(n) = M(n)
            }
        }
    }
    //Cambiar por el resultado
    if (!exito) {
        laberinto[x][y] = '.';
    }
    return exito;
}

int main()
{
  int i,j;
  int sol_x,sol_y;
  char **laberinto;
  bool exito = false;
  
  //reservar memoria laberinto
  laberinto = new char*[TAM];
  for (i = 0; i < TAM; i++) {
    laberinto[i] = new char[TAM];
  }

  for(i=0;i<TAM;i++)
    for(j=0;j<TAM;j++)
      cin>>laberinto[i][j];

  if(buscarTesoro(laberinto,exito,0,0,sol_x,sol_y)) {
      cout<<"ENCONTRADO "<<sol_x<<" "<<sol_y<<endl;
    } else {
      cout<<"INALCANZABLE"<<endl;
    }
    
    for (i = 0; i<TAM;i++){
        delete[] laberinto[i];
    }
    delete[] laberinto;

}
