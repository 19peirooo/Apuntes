package PizzaDecorator;
/**
 * Decorador concreto
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class RedOnionComponentDecorator extends AbstractToppingComponentDecorator {
	public static final Double DEFAULT_PRICE = 0.80;
	public static final String DEFAULT_NAME = "Red onions";
	
	public RedOnionComponentDecorator(PizzaComponent pizzaComponent) {
		this(RedOnionComponentDecorator.DEFAULT_PRICE, 
				pizzaComponent);
	}

	public RedOnionComponentDecorator(Double price,PizzaComponent pizzaComponent) {
		super(RedOnionComponentDecorator.DEFAULT_NAME, 
				price, 
				pizzaComponent);
	}
	

}
