#include<iostream>
using namespace std;

/*  Funcion Combinar
    Combina el array a y el array b y ordena sus elementos guardando el array conjunto en c 
    Entrada: Arrays entrantes con sus longitudes y array donde se van a juntar los otros 2
    Retorno: Ninguno
    Precondicion: Los arrays a combinar no pueden ser vacios
    Complejidad Temporal: T(n) = n + 1, O(n) --> n = len_a + len_b
    Complejidad Espacial: M(n) = 1, O(1) --> No se crea memoria adicional en esta funcion
*/

void combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
  int i = 0, j = 0, k = 0;

  while (i < len_a && j < len_b) { //T(n) = n --> Lo que no se lea ahora se leera en los bucles siguientes
    if (a[i] <= b[j]) {
      c[k++] = a[i++];
    } else {
      c[k++] = b[j++];
    }
  }

  while (i < len_a) { 
    c[k++] = a[i++];
  }

  while (j < len_b) {
    c[k++] = b[j++];
  }
}

/*  Funcion Merge Sort
    Combina el array a y el array b y ordena sus elementos guardando el array conjunto en c 
    Entrada: Array a ordenar y su longitud
    Retorno: Ninguno
    Precondicion: El array a combinar no puede ser vacio
    Complejidad Temporal: T(n) = 2*T(n/2)+ n + 1, O(nlog(n))
    Complejidad Espacial: M(n) = M(n/2) + n + 1, O(n)
*/

void ordenarMergeSort (int x[], int len)
{
  int temp[len]; //M(n) = n
  int len_a;
  int len_b;
  int i = 0, j = 0;
  if (len <= 1)
    return;
  else
    {
      len_a = len/2;
      len_b = len - len_a;
      /*Ordenar dos mitades */
      int *a = x;
      int *b = x + len_a;
      ordenarMergeSort(a,len_a); //T(n) = T(n/2)
      ordenarMergeSort(b,len_b); //T(n) = T(n/2) 
      /*Combinar ambas mitades y guardarlo en temp */
      combinar(a,len_a,b,len_b,temp); //T(n) = n + 1, M(n) = 1
      /*Copiar del array temporal al array resultado */
      for (int k = 0; k < len; k++){
	      x[k] = temp[k];
	      cout<<x[k]<<" ";
	    }
      cout<<endl;
    }
}



int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarMergeSort(x,n);
}

