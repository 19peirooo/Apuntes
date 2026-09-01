package observerpattern.channels;

public interface PullPushObserver {
	public void update(PullPushObservable observable, Object object);
}
