package decoratorpattern.pizza;

public class MeatComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Carne";
	public static final Double DEFAULT_PRICE = 4.25;
	
	public MeatComponentDecorator(PizzaComponent pizzaComponent) {
		this(MeatComponentDecorator.DEFAULT_PRICE,pizzaComponent);
	}
	
	public MeatComponentDecorator(Double unitPrice, PizzaComponent pizzaComponent) {
		super(MeatComponentDecorator.DEFAULT_NAME, unitPrice, pizzaComponent);
	}
}
