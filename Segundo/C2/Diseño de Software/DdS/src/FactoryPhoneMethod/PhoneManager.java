package FactoryPhoneMethod;

public class PhoneManager {
	
	private static PhoneManager phoneManager = new PhoneManager(new IphoneFactory());
	private PhoneFactory phoneFactory;
	
	private PhoneManager (PhoneFactory phoneFactory) {
		this.phoneFactory = phoneFactory;
	}
	
	public static PhoneManager getInstance() {
		return PhoneManager.phoneManager;
	}
	
	public PhoneFactory getPhoneFactory() {
		return this.phoneFactory;
	}

	public void setPhoneFactory(PhoneFactory phoneFactory) {
		this.phoneFactory = phoneFactory;
	}
	
	public Phone createMobile() {
		return this.phoneFactory.createPhone(); //Delegacion por Agregacion
	}
}
