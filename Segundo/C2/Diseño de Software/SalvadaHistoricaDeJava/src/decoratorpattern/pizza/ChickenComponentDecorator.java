package decoratorpattern.pizza;

public class ChickenComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Pollo";
	public static final Double DEFAULT_PRICE = 2.75;
	
	public ChickenComponentDecorator(PizzaComponent pizzaComponent) {
		this(ChickenComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public ChickenComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(ChickenComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
