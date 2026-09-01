package FactoryPhoneMethod;

public class SamsungFactory implements PhoneFactory {

	@Override
	public Phone createPhone() {
		return new Samsung();
	}
	
}
