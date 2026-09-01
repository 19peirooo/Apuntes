package AbstractFactoryIphone;
/**
 * Clase abstracta de producto Iphone
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public abstract class Iphone implements Mobile {
	protected String language;
	public String getLanguage() {
		return language;
	}
	public void setLanguage(String language) {
		this.language = language;
	}
	@Override
	public String getBrand() {
		return "Apple";
	}
	//En el constructor indicamos el lenguaje de uso.
	public Iphone(String language) { 
		super();
		this.language = language;
	}
}
