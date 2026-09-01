package observerpattern.bases;

public class OctalObserver implements PullPushObserver{
	
	@Override
	public void update(PullPushObservable observable, Object object) {
		if (observable instanceof ObservableNumber) {
			System.out.println("[Pull Protocol] Octal Integer as String: " + Integer.toOctalString(((ObservableNumber)observable).getNumber()));
		}
		if (object instanceof Integer) {
			System.out.println("[Push Protocol] Octal Integer as String: " + Integer.toOctalString((Integer)object));
		}
	}
	
}
