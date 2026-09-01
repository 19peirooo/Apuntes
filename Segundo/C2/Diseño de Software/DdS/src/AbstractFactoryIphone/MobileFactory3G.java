package AbstractFactoryIphone;
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

}
