package PullObserverPattern;

public class BinIntegerObserver implements PullObserver{
	
	private ConcreteIntegerSubject concreteIntegerSubject;
	
	public BinIntegerObserver(ConcreteIntegerSubject concreteIntegerObserver) {
		this.concreteIntegerSubject = concreteIntegerObserver;
	}

	public void update() {
		System.out.println("Binary Integer as String: " 
				+ Integer.toBinaryString(this.concreteIntegerSubject.getState()));
	}
	
}
