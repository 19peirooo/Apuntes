package observerpattern.bases;

public class BinaryObserver implements PullPushObserver {

	@Override
	public void update(PullPushObservable observable, Object object) {
		if (observable instanceof ObservableNumber) { //Protocol Pull
			System.out.println("[Pull Protocol] Binary Integer as String: " + Integer.toBinaryString(((ObservableNumber)observable).getNumber()));
		}
		if (object instanceof Integer) { //Protocol Push
			System.out.println("[Push Protocol] Binary Integer as String: " + Integer.toBinaryString((Integer)object));
		}
	}

}
