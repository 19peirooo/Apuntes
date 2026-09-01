package observerpattern.bases;

public class BasesObserverPatternTest {
	public static void main(String[] args) {
		ObservableNumber number = new ObservableNumber(0);
		BinaryObserver binaryObserver = new BinaryObserver();
		HexObserver hexObserver = new HexObserver();
		OctalObserver octalObserver = new OctalObserver();
		
		number.attach(binaryObserver);
		number.attach(hexObserver);
		number.attach(octalObserver);
		
		for(int i = 0; i <= 16; i++) {
			System.out.println("**** Numero " + i + " ****");
			number.setNumber(i);
		}
	}
}
