package abstractfactorymethod.phone;

public class MobileClientTest {
	public static void main(String[] args) {
		MobileFactoryManager manager = MobileFactoryManager.getInstance();
		Mobile iphone = manager.createIphone();
		Mobile samsung = manager.createSamsung();
		Mobile motorola = manager.createMotorola();
		System.out.println("My Iphone available is: " + iphone);
		System.out.println("My Samsung available is: " + samsung);
		System.out.println("My Motorola avalable is: " + motorola);
		manager.setFactory(new Mobile4GFactory());
		Mobile iphone2 = manager.createIphone();
		Mobile samsung2 = manager.createSamsung();
		Mobile motorola2 = manager.createMotorola();
		System.out.println("My Iphone available is: " + iphone2);
		System.out.println("My Samsung available is: " + samsung2);
		System.out.println("My Motorola avalable is: " + motorola2);
		
	}
}
