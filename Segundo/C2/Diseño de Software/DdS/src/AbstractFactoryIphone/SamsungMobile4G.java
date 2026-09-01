package AbstractFactoryIphone;
/**
 * Clase concreta de producto Samsung con conectividad 4G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class SamsungMobile4G extends SamsungMobile {
	private TypeConnectivity typeConnectivity;
	public void setTypeConnectivity(TypeConnectivity typeConnectivity) {
		this.typeConnectivity = typeConnectivity;
	}
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}
	public SamsungMobile4G(String language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T4G;
	}
	@Override
	public String toString() {
		return "SamsungMobile4G [typeConnectivity=" + typeConnectivity + ", language=" + 
				this.language
		+ ", getBrand()=" + getBrand() + "]";
	}
}

