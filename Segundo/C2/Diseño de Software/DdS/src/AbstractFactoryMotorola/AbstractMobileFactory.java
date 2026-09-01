package AbstractFactoryMotorola;
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
	public Mobile createIphone(Language language);
	public Mobile createSamsung();
	public Mobile createSamsung(Language language);
	public Mobile createMotorola();
	public Mobile createMotorola(Language language);
}