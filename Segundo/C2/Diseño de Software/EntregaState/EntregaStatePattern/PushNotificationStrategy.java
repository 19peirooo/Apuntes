package EntregaStatePattern;

//Clase que desarrolla el metodo definido en la interfaz --> Implementacion menos abstracta
public class PushNotificationStrategy implements NotificationStrategy{

	public void update(PullPushObserver observer, Object notification) {
		observer.update(null, notification);
	}
}
