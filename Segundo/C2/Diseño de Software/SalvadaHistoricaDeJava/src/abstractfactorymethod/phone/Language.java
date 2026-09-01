package abstractfactorymethod.phone;

public enum Language {
	ENGLISH("EN"),SPANISH("SP");
	
	private String isoCode;
	
	private Language(String isoCode) {
		this.isoCode = isoCode;
	}
	
	public String getIsoCode() {
		return this.isoCode;
	}
	
}
