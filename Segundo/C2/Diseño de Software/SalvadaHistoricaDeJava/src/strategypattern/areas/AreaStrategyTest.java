package strategypattern.areas;

import java.util.Scanner;

public class AreaStrategyTest {
	public static void main(String[] args) {
		ContextAreaStrategy areaCalculator = new ContextAreaStrategy();
		Scanner sc = new Scanner(System.in);
		System.out.println("Elige el area a calcular: ");
		System.out.println("1. Cuadrado, 2. Circulo");
		Integer n = sc.nextInt();
		if (n==1) {
			System.out.println("Introduce el lado en cms");
			Double lado = sc.nextDouble();
			areaCalculator.setAreaStrategy(new SquareAreaStrategy());
			System.out.println("El area es: " + areaCalculator.calcularArea(lado));
		} else if (n == 2) {
			System.out.println("Introduce el radio en cms");
			Double radio = sc.nextDouble();
			areaCalculator.setAreaStrategy(new CircleAreaStrategy());
			System.out.println("El area es: " + areaCalculator.calcularArea(radio));
		} else {
			System.out.println("Argumento Invalido");
		}
		sc.close();
	}
}
