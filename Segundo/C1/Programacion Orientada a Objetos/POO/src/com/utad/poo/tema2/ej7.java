package com.utad.poo.tema2;

import java.util.Scanner;

public class ej7 {
	public static void main(String[] args) {
		int n = 0;
		Scanner input = new Scanner(System.in);
		System.out.println("Introduce un numero: ");
		n = input.nextInt();
		
		if (n % 2 != 0) {
			System.out.println(n + " es un numero impar.");
		}
		else {
			System.out.println(n + " es un numero par");
		}
		input.close();
	}
}
