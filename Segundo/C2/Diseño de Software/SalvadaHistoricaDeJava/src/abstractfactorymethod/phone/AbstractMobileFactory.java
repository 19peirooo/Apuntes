package abstractfactorymethod.phone;

public interface AbstractMobileFactory {
	public Mobile createIphone();
	public Mobile createSamsung();
	public Mobile createMotorola();
}
