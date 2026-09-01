package observerpattern.tienda;

public interface PullPushObserver {
	public void update(PullPushObservable observable, Object object);
}
