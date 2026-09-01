package com.utad.poo.tema2;

public class Ejercicio3 {
	public static final String BLACK = "B";
	public static final String WHITE = "W";
	public static final int TAM = 8;
	
	public static void main(String[] args) {
		for (int i = 0; i < Ejercicio3.TAM; i++) {
			for (int j = 0; j < Ejercicio3.TAM; j++) {
				if ((i+j)%2 == 0) {
					System.out.print(Ejercicio3.BLACK);
				}
				else {
					System.out.print(Ejercicio3.WHITE);
				}
			}
			System.out.println();
		}

	}

}
