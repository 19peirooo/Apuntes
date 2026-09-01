package EntregaObserverPattern;

//Interfaz plantilla para los observadores
public interface PullPushObserver {
	public void update(PullPushObservable observable, Object state);
}
