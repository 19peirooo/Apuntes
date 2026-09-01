package strategypattern.areas;

import java.util.Scanner;

public class GeometricAreaStrategyTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Elige el area a calcular: ");
		System.out.println("1. Cuadrado, 2. Circulo");
		Integer n = sc.nextInt();
		if (n==1) {
			System.out.println("Introduce el lado en cms");
			Double lado = sc.nextDouble();
			Square cuadrado = new Square(lado);
			System.out.println(cuadrado);
		} else if (n == 2) {
			System.out.println("Introduce el radio en cms");
			Double radio = sc.nextDouble();
			Circle circulo = new Circle(radio);
			System.out.println(circulo);
		} else {
			System.out.println("Argumento Invalido");
		}
		sc.close();
	}
}
