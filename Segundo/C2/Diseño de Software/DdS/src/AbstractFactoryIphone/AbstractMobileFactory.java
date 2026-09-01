package AbstractFactoryIphone;
/**
 * Interface de abstract factory
 * declara los diferentes productos que puede proveer
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public interface AbstractMobileFactory {
	public Mobile createIphone();
	public Mobile createSamsung();
}

