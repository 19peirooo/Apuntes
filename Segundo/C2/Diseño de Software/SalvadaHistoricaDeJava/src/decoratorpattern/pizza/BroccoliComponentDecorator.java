package decoratorpattern.pizza;

public class BroccoliComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Brocoli";
	public static final Double DEFAULT_PRICE = 1.25;
	
	public BroccoliComponentDecorator(PizzaComponent pizzaComponent) {
		this(BroccoliComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public BroccoliComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(BroccoliComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
