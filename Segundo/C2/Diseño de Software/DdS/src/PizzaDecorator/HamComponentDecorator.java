package PizzaDecorator;
/**
 * Decorador concreto
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class HamComponentDecorator extends AbstractToppingComponentDecorator {
	public static final Double DEFAULT_PRICE = 4.12;
	public static final String DEFAULT_NAME = "Ham";
	
	public HamComponentDecorator(PizzaComponent pizzaComponent) {
		this(HamComponentDecorator.DEFAULT_PRICE, 
				pizzaComponent);
	}

	public HamComponentDecorator(Double price,PizzaComponent pizzaComponent) {
		super(HamComponentDecorator.DEFAULT_NAME, 
				price, 
				pizzaComponent);
	}
	

}
