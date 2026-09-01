package decoratorpattern.pizza;

import java.text.DecimalFormat;

public class ExtraDecoratorPatternTest {
	public static void main(String[] args) {
		DecimalFormat dFormat = new DecimalFormat("#.##");
		
		PizzaComponent mixPizza = new RomanDough();
		
		mixPizza = new BroccoliComponentDecorator(mixPizza);
		mixPizza = new HamExtraComponentDecorator(mixPizza);
		mixPizza = new RedOnionsComponentDecorator(mixPizza);
		
		
		System.out.println("Producto: " + mixPizza.getDescription());
		System.out.println("Precio (€): " + dFormat.format(mixPizza.getPrice()));
		System.out.println("Ingredientes: " + mixPizza.toppingsNumber());
		
		System.out.println("Aplicamos descuento");
		mixPizza = new DiscountComponentDecorator(0.05,mixPizza);
		
		System.out.println("Producto: " + mixPizza.getDescription());
		System.out.println("Precio (€): " + dFormat.format(mixPizza.getPrice()));
		System.out.println("Ingredientes: " + mixPizza.toppingsNumber());
		System.out.println("Añadimos extra de jamon");
		
		PizzaComponentDecorator pizzaHamComponent = AbstractToppingComponentDecorator
				.instanceHasComponentDecorator(mixPizza, new HamExtraComponentDecorator(null));
		if (pizzaHamComponent instanceof HamExtraComponentDecorator) {
			((HamExtraComponentDecorator) pizzaHamComponent ).addExtra();
			System.out.println("Se ha añadido un extra de jamón: "+mixPizza.getDescription());
			System.out.println("Precio final con extra de jamón "+ dFormat.format(mixPizza.getPrice()));
		}
		
	}
}
