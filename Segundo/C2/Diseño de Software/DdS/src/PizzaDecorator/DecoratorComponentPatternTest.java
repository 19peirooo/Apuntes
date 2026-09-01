package PizzaDecorator;

import java.text.DecimalFormat;
/**
 * Clase Test de decoración, añadimos tomate a una pizza con masa tradicional
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class DecoratorComponentPatternTest {
	public static void main(String[] args) {
		DecimalFormat dformat = new DecimalFormat("#.##"); 
	
		//Base de pizza
		PizzaComponent pizza = new TraditionalDough();
		
		System.out.println("Producto : "+pizza.getDescription()); 
		System.out.println("Precio (€): "+dformat.format(pizza.getPrice()));
		System.out.println("Ingredientes, "+pizza.toppingsNumber()); 	
	
		System.out.println("Añadimos los tomates al componente base");
		//TODO Cómo se añaden los tomates a la base de pizza.
		pizza = new TomatoComponentDecorator(pizza); 
		
		System.out.println("Producto final : "+pizza.getDescription()); 
		System.out.println("Precio (€): "+dformat.format(pizza.getPrice()));
		System.out.println("Ingredientes, "+pizza.toppingsNumber()); 		
	}
}