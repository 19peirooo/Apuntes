package statepattern.biblioteca;

public class PushNotificationStrategy implements NotificationStrategy{

	@Override
	public void update(PullPushObserver observer, Object notification) {
		observer.update(null, notification);
	}
	
}
