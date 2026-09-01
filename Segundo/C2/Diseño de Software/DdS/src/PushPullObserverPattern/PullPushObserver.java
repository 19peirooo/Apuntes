package PushPullObserverPattern;

public interface PullPushObserver {
	public void update(PullPushSubject subject, Object object);
}
