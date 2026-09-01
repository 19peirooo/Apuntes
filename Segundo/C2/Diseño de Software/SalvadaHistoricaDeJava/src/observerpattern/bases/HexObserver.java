package observerpattern.bases;

public class HexObserver implements PullPushObserver{
	
	@Override
	public void update(PullPushObservable observable, Object object) {
		if (observable instanceof ObservableNumber) {
			System.out.println("[Pull Protocol] Hexadecimal Integer as String: " + Integer.toHexString(((ObservableNumber)observable).getNumber()));
		}
		if (object instanceof Integer) {
			System.out.println("[Push Protocol] Hexadecimal Integer as String: " + Integer.toHexString((Integer)object));
		}
	}
	
}
