package decoratorpattern.pizza;

public class RedOnionsComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Cebolla Roja";
	public static final Double DEFAULT_PRICE = 0.80;
	
	public RedOnionsComponentDecorator(PizzaComponent pizzaComponent) {
		this(RedOnionsComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public RedOnionsComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(RedOnionsComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
