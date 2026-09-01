package com.utad.poo.tema2;

import java.util.Scanner;

public class ej4 {
	public static void main(String[] args) {
		double radio = 0;
		double area = 0;
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("Escriba el radio: ");
		radio = entrada.nextDouble();
		entrada.close();
		
		area = Math.PI * radio * radio;
		System.out.println("El area es: " + area);
	}
}
