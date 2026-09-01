package com.utad.poo.tema2;

public class Ejercicio10 {
	public static int[] clonarArray(int[] arr) {
		int[] copia = new int[arr.length]; //Crea un array vacio de la misma longitud
		//Copia todos los elementos del array original en la copia
		for (int i = 0; i < arr.length; i++) {
			copia[i] = arr[i];
		}
		return copia;
	}
	public static void main(String[] args) {
		int arr[] = {1,2,3,4,5};
		int arr2[] = clonarArray(arr);
		
		//Imprime todos los elementos de ambos arrays
		System.out.print("Array Original: ");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		
		System.out.print("Copia: ");
		for (int i = 0; i < arr2.length; i++) {
			System.out.print(arr2[i] + " ");
		}
	}

}
