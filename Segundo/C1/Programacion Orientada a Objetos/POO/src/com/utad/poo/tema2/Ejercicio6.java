package com.utad.poo.tema2;

public class Ejercicio6 {
	public static final int NUM = 4;
	
	public static int factorial(int x) {
		if (x <= 1) {
			return 1;
		}
		else {
			return x*factorial(x-1);
		}
	}
	
	public static void main(String[] args) {
		int result = 1;
		int j = 1;
		
		for (int i = 1; i <= Ejercicio6.NUM; i++) {
			result *= i;
		}
		System.out.println(result);
		result = 1;
		
		while (j <= Ejercicio6.NUM) {
			result *= j;
			j++;
		}
		System.out.println(result);
		
		result = Ejercicio6.factorial(Ejercicio6.NUM);
		System.out.println(result);
		
	}

}
