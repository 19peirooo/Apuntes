package FactoryPhoneMethod;

public class PhoneManagerTest {
	public static void main(String[] args) {
		Phone phone = PhoneManager.getInstance().createMobile();
		System.out.println(phone.getBrand());
	}
}
