package com.utad.poo.tema2;

import java.util.Scanner;

public class ej6 {

	public static void main(String[] args) {
		int suma = 0, mult = 1;
		float div = 1;
		
		for (int i = 1; i <= 5; i++) {
			suma += i;
			mult = mult * i;
		}
		div = (mult * 3)/5;
		
		System.out.println("Suma: " + suma + ". Multiplicacion: " + mult + ". Division: " + div + ".");
	}

}
