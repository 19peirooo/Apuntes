package AbstractFactoryMotorola;
/**
 * Clase abstracta de producto Motorola
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public abstract class Motorola implements Mobile {
	protected String language;
	public String getLanguage() {
		return language;
	}
	public void setLanguage(String language) {
		this.language = language;
	}
	@Override
	public String getBrand() {
		return "Motorola";
	}
	//En el constructor indicamos el lenguaje de uso.
	public Motorola(String language) { 
		super();
		this.language = language;
	}
}
