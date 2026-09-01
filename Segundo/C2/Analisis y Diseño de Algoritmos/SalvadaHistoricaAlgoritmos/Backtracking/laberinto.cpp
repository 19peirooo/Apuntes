#include "../assertdomjudge.h"
#define TAM 10

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void imprimirLaberinto(char** laberinto)
{
  for(int i=0;i<TAM;i++)
    {
    for(int j=0;j<TAM;j++)
      cout<<laberinto[i][j];
    cout<<endl;
    }
}

bool validarPosicion(char** laberinto ,int x, int y) {
    return (x >= 0 && x < TAM) && (y >= 0 && y < TAM) && (laberinto[x][y] == '.' || laberinto[x][y] == 'T');
}

bool buscarTesoro(char **laberinto,bool* exito, int x, int y,int* sol_x, int* sol_y) {
  laberinto[x][y] = 'X';
  for (int i = 0; i < 4 && !(*exito); i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (validarPosicion(laberinto,new_x,new_y)) {
      if (laberinto[new_x][new_y] == 'T') {
        *exito = true;
        *sol_x = new_x;
        *sol_y = new_y;
        imprimirLaberinto(laberinto);
        return true;
      } else if (laberinto[new_x][new_y] == '.') {
        buscarTesoro(laberinto,exito,new_x,new_y,sol_x,sol_y);
      }
    }
  }
  if (!exito) {
    laberinto[x][y] = '.';
  }
  return *exito;
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
  if(buscarTesoro(laberinto,&exito,0,0,&sol_x,&sol_y))
    {
      cout<<"ENCONTRADO "<<sol_x<<" "<<sol_y<<endl;
    }
  else
    cout<<"INALCANZABLE"<<endl;
  
}