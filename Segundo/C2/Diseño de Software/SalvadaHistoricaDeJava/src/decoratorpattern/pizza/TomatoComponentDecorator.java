package decoratorpattern.pizza;

public class TomatoComponentDecorator extends AbstractToppingComponentDecorator{

	public static final String DEFAULT_NAME = "Tomate";
	public static final Double DEFAULT_PRICE = 1.20;
	
	public TomatoComponentDecorator(PizzaComponent pizzaComponent) {
		this(TomatoComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public TomatoComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(TomatoComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
	
}
