package decoratorpattern.pizza;

public class RomanDough implements PizzaBaseComponent {

	public static final String DEFAULT_NAME = "Romana";
	public static final Double DEFAULT_PRICE = 9.0;
	private Double unitPrice;
	private String name;
	private DoughType doughType;
	
	public RomanDough() {
		this(RomanDough.DEFAULT_NAME);
	}
	
	public RomanDough(String name) {
		this(name,RomanDough.DEFAULT_PRICE);
	}
	
	public RomanDough(String name, Double unitPrice) {
		this(name,unitPrice,DoughType.FINA);
	}
	
	public RomanDough(String name, Double unitPrice, DoughType doughType) {
		this.name = name;
		this.unitPrice = unitPrice;
		this.doughType = doughType;
	}

	public Double getUnitPrice() {
		return this.unitPrice;
	}

	public void setUnitPrice(Double unitPrice) {
		this.unitPrice = unitPrice;
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public DoughType getDoughType() {
		return this.doughType;
	}

	public void setDoughType(DoughType doughType) {
		this.doughType = doughType;
	}

	@Override
	public String getDescription() {
		return "Nombre: "+this.name+", Masa: " + this.doughType + ", Precio Unitario: " + this.unitPrice;
	}

	@Override
	public Double getPrice() {
		return this.unitPrice;
	}

	@Override
	public Integer toppingsNumber() {
		return 0;
	}

	@Override
	public String toString() {
		return "RomanDough [description="+this.getDescription()+"]";
	}

}
