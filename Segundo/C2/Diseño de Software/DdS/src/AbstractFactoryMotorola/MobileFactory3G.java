package AbstractFactoryMotorola;
/**
 * Factoría concreta que instancia productos con conectividad 3G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class MobileFactory3G implements AbstractMobileFactory {

	public Mobile createIphone() {
		return new Iphone3G(Language.ENGLISH.getIsoCode());
	}

	public Mobile createSamsung() {
		return new SamsungMobile3G(Language.ENGLISH.getIsoCode());
	}


	public Mobile createIphone(Language language) {
		return new Iphone3G(language.getIsoCode());
	}

	public Mobile createSamsung(Language language) {

		return new SamsungMobile3G(language.getIsoCode());
	}

	
	  public Mobile createMotorola() { 
		  return new Motorola3G(Language.ENGLISH.getIsoCode()); 
	}
	  
	  public Mobile createMotorola(Language language) { 
		  return new Motorola3G(language.getIsoCode()); 
	  }
	 

}
