package observerpattern.bases;

public interface PullPushObserver {
	public void update(PullPushObservable observable, Object object);
}
