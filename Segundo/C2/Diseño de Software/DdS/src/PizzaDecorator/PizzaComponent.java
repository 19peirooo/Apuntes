package PizzaDecorator;
/**
 * Identificación de todo elemento Pizza
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public interface PizzaComponent {
	public String  getDescription();
	public Double  getPrice();
	public Double  getUnitPrice();
	public String  getName();
	public Integer toppingsNumber(); // componentes añadidos a las Pizzas
}
