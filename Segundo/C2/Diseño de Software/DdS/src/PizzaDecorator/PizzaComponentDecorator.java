package PizzaDecorator;
/**
 * Identificación de todo elemento Decorador de elementos Pizza
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public interface PizzaComponentDecorator extends PizzaComponent {
	//TODO Todo decorador tiene "acceso" al componente decorado
	public PizzaComponent getPizzaComponent();
}
