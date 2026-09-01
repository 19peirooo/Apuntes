package observerpattern.bases;

public interface PullPushObservable {
	public void attach(PullPushObserver observer);
	public void detach(PullPushObserver observer);
	public void notifyObservers();
}
