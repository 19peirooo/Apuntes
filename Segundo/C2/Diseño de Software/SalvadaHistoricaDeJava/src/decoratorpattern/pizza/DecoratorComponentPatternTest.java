package decoratorpattern.pizza;

import java.text.DecimalFormat;

public class DecoratorComponentPatternTest {
	public static void main(String[] args) {
		DecimalFormat dFormat = new DecimalFormat("#.##");
		
		PizzaComponent pizza = new TraditionalDough();
		
		System.out.println("Producto: " + pizza.getDescription());
		System.out.println("Precio (€): " + dFormat.format(pizza.getPrice()));
		System.out.println("Ingredientes: " + pizza.toppingsNumber());
		
		System.out.println("Añadimos el Tomate");
		pizza = new TomatoComponentDecorator(pizza);
		System.out.println("Producto: " + pizza.getDescription());
		System.out.println("Precio (€): " + dFormat.format(pizza.getPrice()));
		System.out.println("Ingredientes: " + pizza.toppingsNumber());
	}
}
