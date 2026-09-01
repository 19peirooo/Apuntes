package AbstractFactoryIphone;
/**
 * Factoría concreta que instancia productos con conectividad 4G
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class MobileFactory4G implements AbstractMobileFactory {

	public Mobile createIphone() {
		return new Iphone4G(Language.ENGLISH.getIsoCode());
	}

	public Mobile createSamsung() {
		return new SamsungMobile4G(Language.ENGLISH.getIsoCode());
	}

}
