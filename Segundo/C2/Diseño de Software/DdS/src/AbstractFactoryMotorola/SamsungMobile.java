package AbstractFactoryMotorola;
/**
 * Clase abstracta de producto Samsung
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public abstract class SamsungMobile implements Mobile {
	protected String language;
	public String getLanguage() {
		return language;
	}
	public void setLanguage(String language) {
		this.language = language;
	}
	@Override
	public String getBrand() {
		return "Samsung";
	}
	public SamsungMobile(String language) {
		super();
		this.language = language;
	}
}

