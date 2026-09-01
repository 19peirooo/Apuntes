package AbstractFactoryIphone;
/**
 * Clase concreta de producto Iphone con conectividad 4G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class Iphone4G extends Iphone {
	private TypeConnectivity typeConnectivity;
	public Iphone4G(String language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T4G;
	}
	@Override
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}
	@Override
	public String toString() {
		return "Iphone4G [typeConnectivity=" + typeConnectivity + ", language=" + 
				this.language + ", getBrand()="
				+ getBrand() + "]";
	}
}
