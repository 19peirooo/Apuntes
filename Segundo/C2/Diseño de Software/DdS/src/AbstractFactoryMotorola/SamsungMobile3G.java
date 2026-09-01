package AbstractFactoryMotorola;
/**
 * Clase concreta de producto Samsung con conectividad 3G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class SamsungMobile3G extends SamsungMobile {
	private TypeConnectivity typeConnectivity;
	public void setTypeConnectivity(TypeConnectivity typeConnectivity) {
		this.typeConnectivity = typeConnectivity;
	}
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}
	public SamsungMobile3G(String language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T3G;
	}
	@Override
	public String toString() {
		return "SamsungMobile3G [typeConnectivity=" + this.typeConnectivity + ", language=" + 
				this.language + ", brand=" +  this.getBrand() + "]";
	}
}

