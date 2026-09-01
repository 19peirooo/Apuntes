package com.utad.poo.tema2;

import java.util.Scanner;

public class ej9 {
	public static void main(String[] args) {
		int n = 0;
		int suma = 0;
		
		Scanner input = new Scanner(System.in);
		while (n <= 0) {
			System.out.println("Introduce un numero mayor que 0: ");
			n = input.nextInt();
		}
		input.close();
		for (int i = 1; i <= n; i++) {
			suma += i;
		}
		System.out.println("La suma es: "+ suma);
	}
}
