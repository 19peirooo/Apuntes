package decoratorpattern.pizza;

public class DiscountComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final String DEFAULT_NAME = "Espinacas";
	public static final Double DEFAULT_PRICE = 1.50;
	
	private Double discount;
	
	public DiscountComponentDecorator(Double discount,PizzaComponent pizzaComponent) {
		super(discount.toString(),0.0,pizzaComponent);
		this.discount = discount;
	}
	
	public String getDescription() {
		return this.getPizzaComponent().getDescription() + " con descuento de " + this.discount*100 + "%";
	}
	
	public Double getPrice() {
		return this.getPizzaComponent().getPrice() * (1-this.discount);
	}
	
	public Integer toppingsNumber() {
		return this.getPizzaComponent().toppingsNumber();
	}
}
