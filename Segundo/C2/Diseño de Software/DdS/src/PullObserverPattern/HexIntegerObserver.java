package PullObserverPattern;

public class HexIntegerObserver implements PullObserver{
private ConcreteIntegerSubject concreteIntegerSubject;
	
	public HexIntegerObserver(ConcreteIntegerSubject concreteIntegerObserver) {
		this.concreteIntegerSubject = concreteIntegerObserver;
	}

	public void update() {
		System.out.println("Hexadecimal Integer as String: " 
				+ Integer.toHexString(this.concreteIntegerSubject.getState()));
	}
}
