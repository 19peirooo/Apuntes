package AbstractFactoryIphone;
/**
 * Clase concreta de producto Iphone con conectividad 3G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class Iphone3G extends Iphone {
	private TypeConnectivity typeConnectivity;
	public Iphone3G(String language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T3G;
	}
	@Override
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}
	@Override
	public String toString() {
		return "Iphone3G [typeConnectivity=" + typeConnectivity + ", language=" + 
				this.language + ", getBrand()="
				+ getBrand() + "]";
	}
}

