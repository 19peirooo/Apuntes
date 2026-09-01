package AbstractFactoryMotorola;
/**
 * Clase test para obtener instancias de objetos Iphone, Samsung y Moto
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
		Mobile myMoto = factoryManager.createMotorola();
		
		System.out.println("My Iphone available is "+myIPhone);
		
		System.out.println("My Samsung available is "+mySamsung);
		
		System.out.println("My Motorola available is "+myMoto);
		
		Mobile mySpanishMoto = factoryManager.createMotorola(Language.SPANISH);
		
		System.out.println("Mi motorola español disponible es "+mySpanishMoto);
		
		factoryManager.setAbstractMobileFactory(new MobileFactory4G());
		
		Mobile myIPhone2 = factoryManager.createIphone();
		Mobile mySamsung2 = factoryManager.createSamsung();
		Mobile myMoto2 = factoryManager.createMotorola();
		Mobile mySpanishMoto2 = factoryManager.createMotorola(Language.SPANISH);
		
		System.out.println("My Iphone2 available is "+myIPhone2);
		
		System.out.println("My Samsung2 available is "+mySamsung2);
		
		System.out.println("My Motorola2 available is "+myMoto2);
		
		System.out.println("Mi motorola2 español disponible es "+mySpanishMoto2);
		
	}
}
