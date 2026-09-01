#include"ListaContigua.h"
#include<iostream>
using namespace std;

int main()
{
  ListaContigua *lista; 
  ListaContigua* numeros;
  int incremento,numero,posicion;
  char operacion;
  do
    {
      cout<<"Elige operacion:"<<endl;
      cin>>operacion;
      switch(operacion)
	{
	case 'N':
	  cout<<"Creando nueva lista"<<endl;
	  cout<<"Introduzca incremento ";
	  cin>>incremento;
	  lista=new ListaContigua(incremento);
	  cout<<endl;
	  break;
	case 'I':
	  cout<<"Insertar en lista en la posicion ";
	  cin>>posicion;
	  cout<<" el valor ";
	  cin>>numero;
	  lista->insertar(posicion,numero);
	  cout<<endl;
	  break;
	case 'E':
	  cout<<"Eliminar de la lista el elemento en posicion ";
	  cin>>posicion;
	  lista->eliminar(posicion);
	  cout <<endl;
	  break;
	case 'V':
	  cout<<"Ver el elemento ";
	  cin>>posicion;
	  cout<<" de la lista"<<endl;
	  cout<<lista->getValor(posicion)<<endl;
	  cout<<endl;
	  break;
	case 'T':
	  cout<<"Ver todos los "<<lista->getN()<<" elementos de la lista"<<endl;
	  for(int i=0;i<lista->getN();i++)
	    cout<<lista->getValor(i)<<" ";
	  cout<<endl;
	  break;
	case 'S':
	  cout<<"Modificar elemento en posicion  ";
	  cin>>posicion;
	  cout<<"por el valor ";
	  cin>>numero;
	  lista->setValor(posicion,numero);
	  cout<<endl;
	  break;
	case 'L':
	  cout<<"La longitud de la lista es "<<lista->getN()<<endl;
	  break;
	case 'M':
	  cout<<"La capacidad maxima de la lista es "<<lista->getCapacidad()<<endl;	  
	  break;
	case 'C':
	  cout<<"Cuantos numeros quieres concatenar ";
	  cin>>numero;
	  numeros=new ListaContigua(1);
	  for(int i=0;i<numero;i++)
	     numeros->insertar(i,i+1);
 	  cout<<"Concatenando "<<numero<<" numeros a la lista "<<endl;
	  lista->concatenar(numeros);	  
	  break;
	case 'B':
	  cout<<"Indica el valor a buscar ";
	  cin>>numero;	  
	  posicion=lista->buscar(numero);
	  if(posicion<0)
	    cout<<"El valor no esta en la lista"<<endl;
	  else
	    cout<<"El valor esta en la lista en la posicion "<<posicion<<endl;
	  break;   
	case 'F':
	  cout<<"FIN"<<endl;
	  break;
	
	}
      
    }while(operacion!='F');
  return 0;
}
