package com.utad.poo.tema2;

public class Ejercicio7 {
	public static double calcTiempo(double x0, double v, double x) {
		return (x - x0)/v;
	}
	public static void main(String[] args) {
		double tiempo = 0;
		tiempo = Ejercicio7.calcTiempo(0, 3.2, 5.5);
		System.out.println(tiempo + "s");
	}

}
