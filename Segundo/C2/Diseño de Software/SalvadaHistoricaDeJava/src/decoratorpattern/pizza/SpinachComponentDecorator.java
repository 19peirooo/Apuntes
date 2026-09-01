package decoratorpattern.pizza;

public class SpinachComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Espinacas";
	public static final Double DEFAULT_PRICE = 1.50;
	
	public SpinachComponentDecorator(PizzaComponent pizzaComponent) {
		this(SpinachComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public SpinachComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(SpinachComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
