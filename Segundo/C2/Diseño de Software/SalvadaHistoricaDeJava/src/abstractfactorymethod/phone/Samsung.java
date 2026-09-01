package abstractfactorymethod.phone;

public abstract class Samsung implements Mobile {
	
	private Language language;
	private TypeMobile brand;
	
	public Samsung(Language language) {
		this.language = language;
		this.brand = TypeMobile.SAMSUNG;
	}
	
	@Override
	public TypeMobile getBrand() {
		return this.brand;
	}

	@Override
	public String getLanguage() {
		return this.language.getIsoCode();
	}

	@Override
	public abstract TypeConnectivity getTypeConnectivity();
	
	
}

