package PizzaDecorator;
/**
 * Clase abstracta de los decoradores
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public abstract class AbstractToppingComponentDecorator 
								implements PizzaComponentDecorator {
	//TODO Cada decorador tiene acceso al componente decorado
	//y sus propios atributos como Componente

	protected PizzaComponent pizzaComponent;
	protected String		 name;
	protected Double 		 unitPrice;
	
		
	public AbstractToppingComponentDecorator(String name, 
			Double unitPrice,
			PizzaComponent pizzaComponent) {
		super();
		this.name = name;
		this.unitPrice = unitPrice;
		this.pizzaComponent = pizzaComponent;
	}
	
	
	public PizzaComponent getPizzaComponent() {
		return pizzaComponent;
	}


	public String getDescription() {
		// TODO Descripción del componente, la del objeto decorado
		// más el precio unitario del objeto decorador
		return this.getPizzaComponent().getDescription() + 
				" con " +this.name + " ("+this.unitPrice+"€)";
	}

	public Double getPrice() {
		// TODO Precio del componente + precio del objeto decorador
		return this.getPizzaComponent().getPrice() + this.unitPrice;
	}

	public Double getUnitPrice() {
		// TODO Precio del objeto decorador
		return this.unitPrice;
	}


	public String getName() {
		// TODO Nombre del objeto decorador
		return this.name;
	}

	public Integer toppingsNumber() {
		// TODO Los ingredientes del componente decorado más el propio
		return this.getPizzaComponent().toppingsNumber() + 1;
	}
	
	public static PizzaComponent isDecoratorOf(PizzaComponent pizzaComponent, PizzaComponentDecorator pizzaComponentDecorator) {
		if (pizzaComponent.getClass().equals(pizzaComponentDecorator.getClass()) || !(pizzaComponent instanceof PizzaComponentDecorator)) {
			return pizzaComponent;
		} else {
			return isDecoratorOf(((PizzaComponentDecorator)pizzaComponent).getPizzaComponent(), pizzaComponentDecorator);
		}
	}
	
	public static PizzaComponentDecorator instanceComponentDecorator(PizzaComponent pizzaComponent, PizzaComponentDecorator componentDecorator) {
		PizzaComponent pizzaComponentSearched = isDecoratorOf(pizzaComponent,componentDecorator);
		if (pizzaComponentSearched.getClass().equals(componentDecorator.getClass())) {
			return (PizzaComponentDecorator) pizzaComponentSearched;
		} else {
			return null;
		}
	}
	
	public void removePizzaComponentDecorator(PizzaComponent pizzaComponent, PizzaComponentDecorator componentDecorator) {
		PizzaComponentDecorator decoradorAEliminar = instanceComponentDecorator(pizzaComponent,componentDecorator);
		if (decoradorAEliminar != null) {
			removePizzaComponentDecorator(((PizzaComponentDecorator)pizzaComponent).getPizzaComponent(), componentDecorator);
		} else {
			System.out.println("Esta pizza no tiene " + componentDecorator.getName());
		}
	}
}