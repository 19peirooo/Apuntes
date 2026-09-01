package PullObserverPattern;

public class OctalIntegerObserver implements PullObserver{
	
	private ConcreteIntegerSubject concreteIntegerSubject;
	
	public OctalIntegerObserver(ConcreteIntegerSubject concreteIntegerObserver) {
		this.concreteIntegerSubject = concreteIntegerObserver;
	}

	public void update() {
		System.out.println("Octal Integer as String: " 
				+ Integer.toOctalString(this.concreteIntegerSubject.getState()));
	}
	
}
