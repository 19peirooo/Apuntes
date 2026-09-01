package PizzaDecorator;

public class HamExtraPizzaComponentDecorator extends AbstractToppingComponentDecorator{
	
	public static final Integer DEFAULT_EXTRAS = 0;
	
	private Integer numberOfExtras;
	
	public HamExtraPizzaComponentDecorator(PizzaComponent pizzaComponent) {
		this(HamComponentDecorator.DEFAULT_NAME,HamComponentDecorator.DEFAULT_PRICE,pizzaComponent,HamExtraPizzaComponentDecorator.DEFAULT_EXTRAS);
	}
	
	public HamExtraPizzaComponentDecorator(String name, Double unitPrice, PizzaComponent pizzaComponent, Integer numberOfExtras) {
		super(name, unitPrice, pizzaComponent);
		this.numberOfExtras = numberOfExtras;
	}

	public Integer getNumberOfExtras() {
		return numberOfExtras;
	}

	public void setNumberOfExtras(Integer numberOfExtras) {
		this.numberOfExtras = numberOfExtras;
	}
	
	public String getDescription() {
		if (this.numberOfExtras >= 1) {
			return this.getPizzaComponent().getDescription() + 
					" con " +this.name + " ("+this.unitPrice+"€) (Extras: " + this.numberOfExtras + ")";
		} else {
			return this.getPizzaComponent().getDescription() + 
					" con " +this.name + " ("+this.unitPrice+"€)";
		}
		
	}

	public Double getPrice() {
		if (this.numberOfExtras >= 1) {
			return this.getPizzaComponent().getPrice() + this.unitPrice + this.numberOfExtras*(0.5*this.unitPrice);
		} else {
			return this.getPizzaComponent().getPrice() + this.unitPrice;
		}
			
	}
	
	public void addExtra() {
		this.numberOfExtras++;
	}
	
}
