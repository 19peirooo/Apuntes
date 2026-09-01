package decoratorpattern.pizza;

public class GreenOlivesComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Aceitunas Verdes";
	public static final Double DEFAULT_PRICE = 3.40;
	
	public GreenOlivesComponentDecorator(PizzaComponent pizzaComponent) {
		this(GreenOlivesComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public GreenOlivesComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(GreenOlivesComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
