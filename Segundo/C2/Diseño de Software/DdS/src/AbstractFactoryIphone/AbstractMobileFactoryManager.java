package AbstractFactoryIphone;
/**
 * Singleton Manager de abstract factory 
 * Usa Factoría concreta de 3G por defecto
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class AbstractMobileFactoryManager {
	private static AbstractMobileFactoryManager abstractMobileFactoryManager = 
			new AbstractMobileFactoryManager(new MobileFactory3G());
	
	private AbstractMobileFactoryManager(AbstractMobileFactory abstractMobileFactory){
		this.abstractMobileFactory= abstractMobileFactory;
	}
	
	AbstractMobileFactory abstractMobileFactory;

	public static AbstractMobileFactoryManager getInstance() {
		return abstractMobileFactoryManager;
	}


	public AbstractMobileFactory getAbstractMobileFactory() {
		return abstractMobileFactory;
	}


	public void setAbstractMobileFactory(AbstractMobileFactory abstractMobileFactory) {
		this.abstractMobileFactory = abstractMobileFactory;
	}


	public Mobile createIphone() {
		return this.abstractMobileFactory.createIphone();
	}


	public Mobile createSamsung() {
		return this.abstractMobileFactory.createSamsung();
	}

	
}
