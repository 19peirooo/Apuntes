package PushPullObserverPattern;
/**
 * Clase Test Observer pattern con protocolo Pull-Push
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class PullPushObserverPatternTest {
	public static void main(String[] args) {
		PullPushSubject subject = new PullPushConcreteIntegerSubject();

		PullPushConcreteIntegerSubject integerConcreteSubject 
									= (PullPushConcreteIntegerSubject) subject;

		PullPushObserver binaryIntegerObserver = new BinaryIntegerObserver();
		PullPushObserver hexaIntegerObserver = new HexaIntegerObserver();
		PullPushObserver octalIntegerObserver = new OctalIntegerObserver();

		integerConcreteSubject.attach(binaryIntegerObserver);
		integerConcreteSubject.attach(hexaIntegerObserver);
		integerConcreteSubject.attach(octalIntegerObserver);
		System.out.println("First state value****************");
		System.out.println("state decimal value: 11");
		integerConcreteSubject.setState(11);

		System.out.println("Second state value***************");
		System.out.println("State decimal value: 14");
		integerConcreteSubject.setState(14);
		
	}
}
