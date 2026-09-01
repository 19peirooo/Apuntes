package FactoryPhoneMethod;

public class IphoneFactory implements PhoneFactory{

	@Override
	public Phone createPhone() {
		return new Iphone();
	}

}
