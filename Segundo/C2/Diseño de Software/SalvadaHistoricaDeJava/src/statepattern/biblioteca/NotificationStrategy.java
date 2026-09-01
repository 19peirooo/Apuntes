package statepattern.biblioteca;

public interface NotificationStrategy {
	public void update(PullPushObserver observer, Object object);
}
