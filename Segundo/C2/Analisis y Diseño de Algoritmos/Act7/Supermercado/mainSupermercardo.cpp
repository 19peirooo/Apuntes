#include<iostream>
#include"Supermercado.h"
using namespace std;

int main()
{
  Supermercado *supermercado;
  char operacion;
  int n,id;
  do
    {
      cin>>operacion;
      switch(operacion)
	{
	case 'N':
	  cout<<"Indique numero de cajas del supermercado: ";
	  cin>>n;
	  supermercado= new Supermercado(n);
	  cout<<endl;
	  break;
	case 'U':
	  cout<<"Introducir nuevo usuario"<<endl;
	  cout<<"Indique caja: ";
	  cin>>n;
	  cout<<"Indique id usuario: ";
	  cin>>id;
	  supermercado->nuevoUsuario(n,id);
	  cout<<endl;
	  break;
	case 'C':
	  cout<<"Indique caja a cerrar :";
	  cin>>n;
	  if(supermercado->cajaVacia(n))
	    cout<<"VACIA"<<endl;
	  else
	    supermercado->cerrarCaja(n);
	  cout<<endl;
	  break;
	case 'A':
	  cout<<"Atender usuario en caja: ";
	  cin>>n;
	  if(supermercado->cajaVacia(n))
	    cout<<"VACIA"<<endl;
	  else	    
	    cout<<supermercado->atenderUsuario(n)<<endl;
	case 'S':
	  break;
	}
    }while(operacion!='S');
  
  return 0;
}
