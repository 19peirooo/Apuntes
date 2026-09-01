package decoratorpattern.pizza;

public class HamExtraComponentDecorator extends AbstractToppingComponentDecorator{

	public static final Integer DEFAULT_EXTRAS = 0;
	
	private Integer numExtras;
	
	public HamExtraComponentDecorator(PizzaComponent pizzaComponent) {
		this(HamComponentDecorator.DEFAULT_NAME,HamComponentDecorator.DEFAULT_PRICE,pizzaComponent,
				HamExtraComponentDecorator.DEFAULT_EXTRAS);
	}
	
	public HamExtraComponentDecorator(String name, Double unitPrice, 
			PizzaComponent pizzaComponent, Integer numExtras) {
		super(name, unitPrice, pizzaComponent);
		this.numExtras = numExtras;
	}
	
	public String getDescription() {
		if (this.numExtras >= 1) {
			return this.pizzaComponent.getDescription() + " con " + this.name + "(Extras: " +this.numExtras + ")" + "(" + this.unitPrice + "€)";
		} else {
			return this.pizzaComponent.getDescription() + " con " + this.name + "(" + this.unitPrice + "€)";
		}
	}
	
	public Double getPrice() {
		if (this.numExtras >= 1) {
			return this.getPizzaComponent().getPrice() + this.unitPrice + this.numExtras*(this.unitPrice/2);
		} else {
			return this.getPizzaComponent().getPrice() + this.unitPrice;
		}
	}
	
	public void addExtra() {
		this.numExtras++;
	}
}
