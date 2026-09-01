package AbstractFactoryMotorola;
/**
 * Clase concreta de producto Motorola con conectividad 3G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class Motorola3G extends Motorola {

	private TypeConnectivity typeConnectivity;
	
	
	
	public void setTypeConnectivity(TypeConnectivity typeConnectivity) {
		this.typeConnectivity = typeConnectivity;
	}



	@Override
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}



	public Motorola3G(String language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T3G;
	}



	@Override
	public String toString() {
		return "Motorola3G [typeConnectivity=" + this.typeConnectivity + ", language=" + 
				this.language + ", brand=" +  this.getBrand() + "]";
	}

}
