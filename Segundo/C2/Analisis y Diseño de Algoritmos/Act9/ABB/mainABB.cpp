#include <iostream>
#include "ABB.h"

using namespace std;

int main()
{
  
  char opcion; // Opcion de menu introducida por teclado
  int numero;
  
  ABB *arbol=NULL;
    
    
  do
    {
      cin >> opcion;
      
      switch (opcion) {
      case 'N':
	cout<<"Creando nuevo ABB"<<endl;
	arbol=new ABB();
      case 'I':
	arbol->imprimir();
	cout<<endl;
	break;
      case 'C':
	cout<<"Elemento a buscar: ";
	cin>>numero;
	if(arbol->buscar(numero)!=NULL)
	  cout<<"ENCONTRADO"<<endl;
	else
	  cout<<"NO ESTA"<<endl;	  
	break;
      case 'L':
	cout<<"Leer Arbol";
	arbol->leerArbol();
	cout<<endl;
	break;
      case 'B':
	cout<<"Es ABB?";
	if(arbol->esABB())
	  cout<<"SI"<<endl;
	else
	  cout<<"NO"<<endl;	
	break;
      case 'V':
	cout<<"Es AVL?";
	if(arbol->esAVL())
	  cout<<"SI"<<endl;
	else
	  cout<<"NO"<<endl;	
	break;
      case 'A':
	// Añadir un numero
	cout<<"Anadir numero"<<endl;
	cin >> numero;
	arbol->insertar(numero);
	cout<<endl;
	break;
      case 'E':
	// Eliminar un contacto
	cout << "Numero a eliminar: ";
	cin >> numero;
	arbol->eliminar(numero);
	cout<<endl;
	break;
      case 'F':
	cout<<"Liberando memoria del arbol"<<endl;
	delete arbol;
      case 'S':
	break;
      default:
	cout << "Opcion incorrecta\n";
	break;
	
      } // Fin switch
      
    } while (opcion != 'S'); 
  
  return 0;
}
