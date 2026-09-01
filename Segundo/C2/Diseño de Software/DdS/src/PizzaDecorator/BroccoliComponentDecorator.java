package PizzaDecorator;
/**
 * Decorador concreto
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class BroccoliComponentDecorator extends AbstractToppingComponentDecorator {
	public static final Double DEFAULT_PRICE = 1.25;
	public static final String DEFAULT_NAME = "Broccoli";
	
	public BroccoliComponentDecorator() {
		this(null);
	}
	
	public BroccoliComponentDecorator(PizzaComponent pizzaComponent) {
		this(BroccoliComponentDecorator.DEFAULT_PRICE, 
				pizzaComponent);
	}

	public BroccoliComponentDecorator(Double price,PizzaComponent pizzaComponent) {
		super(BroccoliComponentDecorator.DEFAULT_NAME, 
				price, 
				pizzaComponent);
	}
	

}
