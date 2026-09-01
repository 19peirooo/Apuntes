package decoratorpattern.pizza;

public class CheeseComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Queso";
	public static final Double DEFAULT_PRICE = 2.25;
	
	public CheeseComponentDecorator(PizzaComponent pizzaComponent) {
		this(CheeseComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public CheeseComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(CheeseComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
