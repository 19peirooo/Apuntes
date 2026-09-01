package decoratorpattern.pizza;

public abstract class AbstractToppingComponentDecorator implements PizzaComponentDecorator{
	
	protected PizzaComponent pizzaComponent;
	protected String name;
	protected Double unitPrice;
	
	public AbstractToppingComponentDecorator(String name, Double unitPrice, PizzaComponent pizzaComponent) {
		this.name = name;
		this.unitPrice = unitPrice;
		this.pizzaComponent = pizzaComponent;
	}

	@Override
	public String getDescription() {
		return this.pizzaComponent.getDescription() + " con " + this.name + "(" + this.unitPrice + "€)";
	}

	@Override
	public Double getPrice() {
		return this.pizzaComponent.getPrice() + this.unitPrice;
	}

	@Override
	public Double getUnitPrice() {
		return this.unitPrice;
	}

	@Override
	public String getName() {
		return this.name;
	}

	@Override
	public Integer toppingsNumber() {
		return this.pizzaComponent.toppingsNumber() + 1;
	}

	@Override
	public PizzaComponent getPizzaComponent() {
		return this.pizzaComponent;
	}
	
	public static PizzaComponent isDecoratorOf(PizzaComponent pizzaComponent, PizzaComponentDecorator decoradorABuscar) {
		if (!(pizzaComponent instanceof PizzaComponentDecorator) || 
				pizzaComponent.getClass().equals(decoradorABuscar.getClass())) {
			return pizzaComponent;
		} else {
			return isDecoratorOf( 
					((PizzaComponentDecorator) pizzaComponent).getPizzaComponent(),
					decoradorABuscar);
		}
	}
	
	public static PizzaComponent hasDecoratorOf(PizzaComponent pizzaComponent, 
			PizzaComponentDecorator componentDecorator) {
		if ( (!(pizzaComponent instanceof PizzaComponentDecorator)) 
				|| ((PizzaComponentDecorator) pizzaComponent).getPizzaComponent()
				.getClass().equals(componentDecorator.getClass())){
			return pizzaComponent;
		} else {
			return hasDecoratorOf ( ((PizzaComponentDecorator) pizzaComponent).
					getPizzaComponent(), componentDecorator);
		}
			
	}
	
	public static PizzaComponentDecorator instanceHasComponentDecorator(PizzaComponent pizzaComponent,
			PizzaComponentDecorator pizzaComponentDecorator) {
			PizzaComponent pizzaComponentSearched = hasDecoratorOf(pizzaComponent, pizzaComponentDecorator);
			if ((pizzaComponentSearched instanceof PizzaComponentDecorator)
					&& ((PizzaComponentDecorator) pizzaComponentSearched).getPizzaComponent().
					getClass().equals(pizzaComponentDecorator.getClass())){
				return (PizzaComponentDecorator) pizzaComponentSearched;
			} else {
				return null;
			}
	}	
}
