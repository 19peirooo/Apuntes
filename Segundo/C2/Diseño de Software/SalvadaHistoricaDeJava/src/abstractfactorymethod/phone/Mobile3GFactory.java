package abstractfactorymethod.phone;

public class Mobile3GFactory implements AbstractMobileFactory {

	@Override
	public Mobile createIphone() {
		return new Iphone3G(Language.ENGLISH);
	}

	@Override
	public Mobile createSamsung() {
		return new Samsung3G(Language.ENGLISH);
	}

	@Override
	public Mobile createMotorola() {
		return new Motorola3G(Language.ENGLISH);
	}

}
