package abstractfactorymethod.phone;

public class Motorola4G extends Motorola{
	private TypeConnectivity typeConnectivity;
	
	public Motorola4G(Language language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T4G;
	}

	@Override
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}

	@Override
	public String toString() {
		return "Motorola4G [typeConnectivity=" + this.typeConnectivity + ", brand=" + this.getBrand() + ", language="
				+ this.getLanguage() + "]";
	}
	
}
