package abstractfactorymethod.phone;

public abstract class Iphone implements Mobile {
	
	private Language language;
	private TypeMobile brand;
	
	public Iphone(Language language) {
		this.language = language;
		this.brand = TypeMobile.IPHONE;
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
