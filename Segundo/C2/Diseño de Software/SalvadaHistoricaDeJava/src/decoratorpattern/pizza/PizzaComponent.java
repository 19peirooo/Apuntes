package decoratorpattern.pizza;

public interface PizzaComponent {
	public String getDescription();
	public Double getPrice();
	public Double getUnitPrice();
	public String getName();
	public Integer toppingsNumber();
}
