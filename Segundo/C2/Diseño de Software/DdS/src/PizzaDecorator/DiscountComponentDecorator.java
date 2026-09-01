package PizzaDecorator;

public class DiscountComponentDecorator 
					extends AbstractToppingComponentDecorator {
	private Double discount;
	public DiscountComponentDecorator(Double discount,
			PizzaComponent pizzaComponent) {
		super(discount.toString(),0.0,pizzaComponent);
		this.discount = discount;
	}
	public Double getDiscount() {
		return discount;
	}
	public void setDiscount(Double discount) {
		this.discount = discount;
	}
	@Override
	public String getDescription() {
		return this.pizzaComponent.getDescription() + " discount ("+this.discount+")";	
	}
	@Override
	public Double getPrice() {
		return this.pizzaComponent.getPrice()* (1-discount);
	}
	@Override
	public Integer toppingsNumber() {
		return this.getPizzaComponent().toppingsNumber();
	}
	
	
}
