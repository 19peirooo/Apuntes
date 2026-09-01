package tema2.sesion3;

import java.util.Scanner;

public class AreaStrategyTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ContextAreaStrategy strategy = new ContextAreaStrategy();
		CircleAreaStrategy circleStrategy = new CircleAreaStrategy();
		SquareAreaStrategy squareStrategy = new SquareAreaStrategy();
		
		
		System.out.println("Introduce la forma para calcular el Area: ");
		System.out.println("1 - Circulo, 2 - Cuadrado");
		Integer opcion = sc.nextInt();
		if (opcion == 1 ) {
			System.out.println("Radio del circulo: ");
			Double radio = sc.nextDouble();
			strategy.setAreaStrategy(circleStrategy);
			System.out.println("El area es: "+strategy.calcularArea(radio) + "cm");
		} else if (opcion == 2) {
			System.out.println("Longitud del Cuadrado: ");
			Double longitud = sc.nextDouble();
			strategy.setAreaStrategy(squareStrategy);
			System.out.println("El area es: "+strategy.calcularArea(longitud) + "cm");
		} else {
			System.out.println("Opcion no valida");
		}
	}
}
