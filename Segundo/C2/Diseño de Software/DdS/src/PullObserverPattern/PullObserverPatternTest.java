package PullObserverPattern;

public class PullObserverPatternTest {
	public static void main(String[] args) {
		ConcreteIntegerSubject subject = new ConcreteIntegerSubject();
		PullObserver binaryObserver = new BinIntegerObserver(subject);
		PullObserver hexObserver = new HexIntegerObserver(subject);
		PullObserver octalObserver = new OctalIntegerObserver(subject);
		
		subject.attach(binaryObserver);
		subject.attach(hexObserver);
		subject.attach(octalObserver);
		
		for (int i = 1; i < 16; i++) {
			System.out.println("New State Value *****************");
			System.out.println("Value: " + i);
			subject.setState(i);
			System.out.println();
		}
		
	}
}
