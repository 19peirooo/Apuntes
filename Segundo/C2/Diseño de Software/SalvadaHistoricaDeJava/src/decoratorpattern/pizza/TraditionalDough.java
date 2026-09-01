package decoratorpattern.pizza;

public class TraditionalDough implements PizzaBaseComponent {
	
	public static final String DEFAULT_NAME = "Napolitana";
	public static final Double DEFAULT_PRICE = 8.0;
	private Double unitPrice;
	private String name;
	private DoughType doughType;
	
	public TraditionalDough() {
		this(TraditionalDough.DEFAULT_NAME);
	}
	
	public TraditionalDough(String name) {
		this(name,TraditionalDough.DEFAULT_PRICE);
	}
	
	public TraditionalDough(String name, Double unitPrice) {
		this(name,unitPrice,DoughType.GRUESA);
	}
	
	public TraditionalDough(String name, Double unitPrice, DoughType doughType) {
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
		return "TraditionalDough [description="+this.getDescription()+"]";
	}
	
}
