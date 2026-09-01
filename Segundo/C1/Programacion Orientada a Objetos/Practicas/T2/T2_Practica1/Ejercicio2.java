package com.utad.poo.tema2;

import java.util.Scanner;

public class Ejercicio2 {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double num = 0;
		double mult = 0;
		double div = 0;
		int resto = 0;
		
		System.out.print("Introduce un numero: ");
		num = input.nextDouble();
		input.close();
		
		mult = num * 20;
		div = mult / 10;
		System.out.println("Division: "+ div);
		
		mult += num;
		div = mult / 10;
		resto = (int)(mult % 10);
		if (resto != 0) {
			System.out.println("Division: "+ div + ". Resto: "+ resto);
		}
		else {
			System.out.println("Division: "+ div);
		}

	}
}
