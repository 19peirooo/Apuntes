package PizzaDecorator;
/**
 * Decorador concreto
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class TomatoComponentDecorator extends AbstractToppingComponentDecorator {
	public static final Double DEFAULT_PRICE = 1.20;
	public static final String DEFAULT_NAME = "Tomate";
	
	public TomatoComponentDecorator(PizzaComponent pizzaComponent) {
		this(TomatoComponentDecorator.DEFAULT_PRICE, 
				pizzaComponent);
	}

	public TomatoComponentDecorator(Double price,PizzaComponent pizzaComponent) {
		super(TomatoComponentDecorator.DEFAULT_NAME, 
				price, 
				pizzaComponent);
	}
	

}
