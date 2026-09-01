package abstractfactorymethod.phone;

public class Samsung3G extends Samsung {
	
	private TypeConnectivity typeConnectivity;
	
	public Samsung3G(Language language) {
		super(language);
		this.typeConnectivity = TypeConnectivity.T3G;
	}

	@Override
	public TypeConnectivity getTypeConnectivity() {
		return this.typeConnectivity;
	}

	@Override
	public String toString() {
		return "Samsung3G [typeConnectivity=" + this.typeConnectivity + ", brand=" + this.getBrand() + ", language="
				+ this.getLanguage() + "]";
	}
	
}
