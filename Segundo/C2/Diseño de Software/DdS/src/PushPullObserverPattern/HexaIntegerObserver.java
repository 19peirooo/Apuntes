package PushPullObserverPattern;/**
 * Observador Pull-Push que muestra un valor en base decimal en base hexadecimal
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class HexaIntegerObserver implements PullPushObserver {

	public void update(PullPushSubject subject, Object object) {
		PullPushConcreteIntegerSubject concreteIntegerSubject = 
				(PullPushConcreteIntegerSubject) subject; 
		
		System.out.println( "[Pull protocol] Hexadecimal String: " + 
				Integer.toHexString( concreteIntegerSubject.getState() ));
		System.out.println( "[Push protocol] Hexadecimal String: " +
				Integer.toHexString( (Integer) object));
		
	}

}
