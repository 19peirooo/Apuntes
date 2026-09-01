package PizzaDecorator;

import java.text.DecimalFormat;

public class DecoratorDiscountPatternTest {
	public static void main(String[] args) {
		DecimalFormat dformat = new DecimalFormat("#.##"); 
		PizzaComponent mixPizza = new RomanDough();
		mixPizza = new BroccoliComponentDecorator(mixPizza); 
		mixPizza = new HamComponentDecorator(mixPizza); 
		mixPizza = new RedOnionComponentDecorator(mixPizza); 
		
		System.out.println("Precio: "+dformat.format(mixPizza.getPrice()));
		System.out.println("Producto: "+mixPizza.getDescription()); 
		System.out.println("Ingredientes, "+mixPizza.toppingsNumber());
		
		System.out.println("Se aplica un descuento del 5%");
		mixPizza = new DiscountComponentDecorator(0.05,mixPizza);
		System.out.println("Producto final: "+mixPizza.getDescription()); 
		System.out.println("Precio: "+dformat.format(mixPizza.getPrice()));
		System.out.println("Ingredientes, "+mixPizza.toppingsNumber());
	}
}
