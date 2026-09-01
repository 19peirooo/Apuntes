package PizzaDecorator;
/**
 * Componente base concreto
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class TraditionalDough implements PizzaBaseComponent {
	public static final Double DEFAULT_PRICE = 8.0;
	public static final String DEFAULT_NAME = "Napolitana";
	private Double 		unitPrice;
	private String		name;
	private DoughType	doughType; // Masa de pizza
		
	public TraditionalDough() {
		this(TraditionalDough.DEFAULT_NAME);
	}

	public TraditionalDough(String name) {
		this(name,TraditionalDough.DEFAULT_PRICE);
	}

	public TraditionalDough(String name, Double basePrice) {
		this(name, basePrice, DoughType.GRUESA);
	}
	public TraditionalDough(String name, Double unitPrice, DoughType doughType) {
		super();
		this.unitPrice = unitPrice;
		this.doughType = doughType;
		this.name = name;
	}
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Double getUnitPrice() {
		return this.unitPrice;
	}

	public void setUnitPrice(Double unitPrice) {
		this.unitPrice = unitPrice;
	}
	public DoughType getDoughType() {
		return doughType;
	}

	public void setDoughType(DoughType doughType) {
		this.doughType = doughType;
	}
	
	@Override
	public String getDescription() {
		// TODO Descripción formada por el nombre y el tipo de masa 
		// junto al precio unitario
		return this.name + " de masa ("+this.doughType+ ")("+this.unitPrice+"€) ";
	}

	@Override
	public Double getPrice() {
		// TODO Al ser un componente base corresponde con el precio base
		return this.unitPrice;
	}

	@Override
	public Integer toppingsNumber() {
		// TODO ¿Cuántos componentes añadidos tiene el componente base?
		return 0;
	}

	@Override
	public String toString() {
		return "TraditionalDough [description=" + this.getDescription()+ "]";
	}


	



	
	


}
