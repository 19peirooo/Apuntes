#include"Matriz.h"
#include<iostream>

int main()
{
  Matriz *temp;
  Matriz a,b,c;
  int n_filas;
  int n_columnas;
  double scalar;
  long semilla;
  
  char operacion;
  do
    {
      cout<<"Elige operacion:"<<endl;
      cin>>operacion;
      switch(operacion)
	{
	case 'N':
	  cout<<"Creando nueva matriz"<<endl;
	  cout<<"Introduzca numero filas y columnas ";
	  cin>>n_filas;
	  cin>>n_columnas;
	  temp=new Matriz(n_filas,n_columnas);
	  temp->rellenarManual();
	  break;
	case 'R':
	  cout<<"Creando nueva matriz aleatoria"<<endl;
	  cout<<"Introduzca numero filas y columnas ";
	  cin>>n_filas;
	  cin>>n_columnas;
	  temp=new Matriz(n_filas,n_columnas);
	  cout<<"Semilla aleatoria: ";
	  cin>>semilla;
	  temp->rellenarAleatorio(semilla);
	  break;

	case 'A':
	  a=*temp;
	  cout<<"Asignando A"<<endl;
	  break;
	case 'B':
	  b=*temp;
	  cout<<"Asignando B"<<endl;
	  break;
	case '+':
	  c=a+b;
	  cout<<"C=A+B"<<endl;
	  break;	  
	case '-':
	  c=a-b;
	  cout<<"C=A-B"<<endl;
	  break;
	case '*':
	  cin>>scalar;
	  c=a*scalar;
	  cout<<"C=A*val"<<endl;
	  break;
	case 'X':
	  c=a*b;
	  cout<<"C=AxB"<<endl;
	  break;
	case 'I':
	  cout<<"Imprimir C"<<endl;
	  c.mostrarMatriz();
	  break;
	case '>':
	  cout<<"Maximo de A: ";
	  cout<<a.obtenerMaximo();
	  cout<<endl;
	  break;
	case '<':
	  cout<<"Minimo de A: ";
	  cout<<a.obtenerMinimo();
	  cout<<endl;
	  break;
	case 'S':
	  cout<<"A es simetrica ";
	  cout<<a.esSimetrica();
	  cout<<endl;
	  break;
	case 'T':
	  cout<<"C=At"<<endl;
	  c=a.calcularTraspuesta();
	  break;
	case 'D':
	  cout<<"Determinante de A: ";
	  cout<<a.calcularDeterminante();
	  cout<<endl;
	  break;

	case 'F':
	  cout<<"FIN"<<endl;
	  break;
	}
      
    }while(operacion!='F');
  return 0;
}
