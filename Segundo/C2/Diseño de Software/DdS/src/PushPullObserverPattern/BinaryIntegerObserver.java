package PushPullObserverPattern;
/**
 * Observador Pull-Push que muestra un valor en base decimal en base binaria
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class BinaryIntegerObserver implements PullPushObserver {

	public void update(PullPushSubject subject,Object object) {
		PullPushConcreteIntegerSubject concreteIntegerSubject = (PullPushConcreteIntegerSubject) subject; 
		
		System.out.println( "[Pull protocol] Binary Integer as String: " + 
				Integer.toBinaryString( concreteIntegerSubject.getState() ));
		System.out.println( "[Push protocol] Binary Integer as String: " +
				Integer.toBinaryString( (Integer) object));
		
	}

}
