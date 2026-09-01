package decoratorpattern.pizza;

public class HamComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Jamon";
	public static final Double DEFAULT_PRICE = 4.12;
	
	public HamComponentDecorator(PizzaComponent pizzaComponent) {
		this(HamComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public HamComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(HamComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
