package PizzaDecorator;
/**
 * Identificación de los elementos sujetos a decoración
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public interface PizzaBaseComponent extends PizzaComponent {
	public DoughType getDoughType();
}
