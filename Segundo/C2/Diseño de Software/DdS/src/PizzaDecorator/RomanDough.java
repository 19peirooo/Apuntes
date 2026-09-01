package PizzaDecorator;
/**
 * Componente base concreto
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class RomanDough implements PizzaBaseComponent {
	public static final Double DEFAULT_PRICE = 9.0;
	public static final String DEFAULT_NAME = "Romana";
	private Double 		unitPrice;
	private String		name;
	private DoughType	doughType; // Masa de pizza
	
	public RomanDough() {
		this(RomanDough.DEFAULT_NAME);
	}
		
	public RomanDough(String name) {
		this(name,RomanDough.DEFAULT_PRICE);
	}

	public RomanDough(String name, Double basePrice) {
		this(name, basePrice, DoughType.FINA);
	}
	public RomanDough(String name, Double unitPrice, DoughType doughType) {
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
		return unitPrice;
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
		// TODO Descripción formada por el nombre y tipo de masa 
		//junto al precio unitario
		return this.name + " de masa ("+this.doughType+ ") ("+this.unitPrice+"€)";
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
		return "RomanDough [description=" + getDescription() + "]";
	}





}
