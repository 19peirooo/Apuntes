package AbstractFactoryMotorola;
/**
 * Clase concreta de producto Samsung con conectividad 4G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class Motorola4G extends Motorola {

	private TypeConnectivity typeConnectivity;
	
	
	
	public void setTypeConnectivity(TypeConnectivity typeConnectivity) {
		this.typeConnectivity = typeConnectivity;
	}



	@Override
	public TypeConnectivity getTypeConnectivity() {
		// TODO Auto-generated method stub
		return this.typeConnectivity;
	}



	public Motorola4G(String language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T4G;
	}



	@Override
	public String toString() {
		return "Motorola4G [typeConnectivity=" + this.typeConnectivity + ", language=" + 
				this.language + ", brand=" +  this.getBrand() + "]";
	}

}
