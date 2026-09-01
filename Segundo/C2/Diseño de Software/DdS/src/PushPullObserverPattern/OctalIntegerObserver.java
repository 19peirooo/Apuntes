package PushPullObserverPattern;
/**
 * Observador Pull-Push que muestra un valor en base decimal en base octal
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class OctalIntegerObserver implements PullPushObserver {

	public void update(PullPushSubject subject, Object object) {
		PullPushConcreteIntegerSubject concreteIntegerSubject = 
				(PullPushConcreteIntegerSubject) subject; 
		
		System.out.println( "[Pull protocol] Octal String: " + 
				Integer.toOctalString( concreteIntegerSubject.getState() ));
		System.out.println( "[Push protocol] Octal String: " +
				Integer.toOctalString( (Integer) object));
		
	}

}
