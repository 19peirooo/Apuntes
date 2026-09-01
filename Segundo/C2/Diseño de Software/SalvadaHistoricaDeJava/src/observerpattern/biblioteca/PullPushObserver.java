package observerpattern.biblioteca;

public interface PullPushObserver {
	public void update(PullPushObservable observable, Object object);
}
