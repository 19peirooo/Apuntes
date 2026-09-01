package com.utad.poo.tema2;

public class Ejercicio11 {
	//Matrices
	public static final int[][] M1 = {{1,2,3},{4,5,6}};
	public static final int[][] M2 = {{7,8},{9,1},{2,3}};
	
	
	
	public static void main(String[] args) {
		//Filas y columnas de cada array
		int filas = Ejercicio11.M1.length;
		int columnasM1 = Ejercicio11.M1[0].length;
		int columnasM2 = Ejercicio11.M2[0].length;
		//Creo la matriz resultado
		int[][] m3 = new int[filas][columnasM2];
		
		//Por cada elemento de la matriz resultado
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnasM2; j++) {
				//Añado este bucle para poder hacer el algoritmo de multiplicacion
				for (int k = 0; k < columnasM1; k++) {
					m3[i][j] += Ejercicio11.M1[i][k] * Ejercicio11.M2[k][j]; //Añado hasta que se hagan todas las filas/columnas para el resultado de ese elemento
				}
			}
		}
		
		//Imprime la matriz resultado
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < columnasM2; j++) {
				System.out.print(m3[i][j]+ " ");
			}
			System.out.println();
		}

	}

}
