package EntregaStatePattern;

//Interfaz para definir notificaciones --> Implementacion mas abstracta
public interface NotificationStrategy {
	public void update(PullPushObserver observer, Object notification);
}
