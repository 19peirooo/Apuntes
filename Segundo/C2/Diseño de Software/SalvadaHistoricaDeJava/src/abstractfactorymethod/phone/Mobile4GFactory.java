package abstractfactorymethod.phone;

public class Mobile4GFactory implements AbstractMobileFactory{

	@Override
	public Mobile createIphone() {
		return new Iphone4G(Language.SPANISH);
	}

	@Override
	public Mobile createSamsung() {
		return new Samsung4G(Language.SPANISH);
	}

	@Override
	public Mobile createMotorola() {
		return new Motorola4G(Language.SPANISH);
	}

}
