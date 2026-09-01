package AbstractFactoryIphone;
/**
 * Clase test para obtener una instancia de objeto Iphone y otro Samsung
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class MobileClientTest {
	public static void main(String[] args) {
		AbstractMobileFactoryManager factoryManager = AbstractMobileFactoryManager.getInstance();
		
		Mobile myIPhone = factoryManager.createIphone();
		Mobile mySamsung = factoryManager.createSamsung();
		
		System.out.println("My Iphone available is "+myIPhone);
		
		System.out.println("My Samsung available is "+mySamsung);
	}
}
