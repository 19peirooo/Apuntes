package decoratorpattern.pizza;

import java.text.DecimalFormat;

public class DiscountDecoratorPatternTest {
	public static void main(String[] args) {
		DecimalFormat dFormat = new DecimalFormat("#.##");
		
		PizzaComponent mixPizza = new RomanDough();
		PizzaComponent pizzaVegetable = new TraditionalDough();
		PizzaComponent pizzaNonVegetable = new RomanDough();
		
		mixPizza = new BroccoliComponentDecorator(mixPizza);
		mixPizza = new HamComponentDecorator(mixPizza);
		mixPizza = new RedOnionsComponentDecorator(mixPizza);
		
		pizzaVegetable = new TomatoComponentDecorator(pizzaVegetable);
		pizzaVegetable = new GreenOlivesComponentDecorator(pizzaVegetable);
		pizzaVegetable = new SpinachComponentDecorator(pizzaVegetable);
		
		pizzaNonVegetable = new MeatComponentDecorator(pizzaNonVegetable);
		pizzaNonVegetable = new CheeseComponentDecorator(pizzaNonVegetable);
		pizzaNonVegetable = new ChickenComponentDecorator(pizzaNonVegetable);
		pizzaNonVegetable = new HamComponentDecorator(pizzaNonVegetable);
		
		System.out.println("Producto: " + mixPizza.getDescription());
		System.out.println("Precio (€): " + dFormat.format(mixPizza.getPrice()));
		System.out.println("Ingredientes: " + mixPizza.toppingsNumber());
		
		System.out.println("Producto: " + pizzaVegetable.getDescription());
		System.out.println("Precio (€): " + dFormat.format(pizzaVegetable.getPrice()));
		System.out.println("Ingredientes: " + pizzaVegetable.toppingsNumber());
		
		System.out.println("Producto: " + pizzaNonVegetable.getDescription());
		System.out.println("Precio (€): " + dFormat.format(pizzaNonVegetable.getPrice()));
		System.out.println("Ingredientes: " + pizzaNonVegetable.toppingsNumber());
		
		System.out.println("Aplicamos descuento");
		mixPizza = new DiscountComponentDecorator(0.05,mixPizza);
		pizzaVegetable = new DiscountComponentDecorator(0.1, pizzaVegetable);
		pizzaNonVegetable = new DiscountComponentDecorator(0.15, pizzaNonVegetable);
		
		
		System.out.println("Producto: " + mixPizza.getDescription());
		System.out.println("Precio (€): " + dFormat.format(mixPizza.getPrice()));
		System.out.println("Ingredientes: " + mixPizza.toppingsNumber());
		
		System.out.println("Producto: " + pizzaVegetable.getDescription());
		System.out.println("Precio (€): " + dFormat.format(pizzaVegetable.getPrice()));
		System.out.println("Ingredientes: " + pizzaVegetable.toppingsNumber());
		
		System.out.println("Producto: " + pizzaNonVegetable.getDescription());
		System.out.println("Precio (€): " + dFormat.format(pizzaNonVegetable.getPrice()));
		System.out.println("Ingredientes: " + pizzaNonVegetable.toppingsNumber());
	}
}
