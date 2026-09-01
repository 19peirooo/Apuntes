package EntregaStatePattern;

//Interfaz plantilla de los observable
public interface PullPushObservable {
	public void attach(PullPushObserver observer);
	public void detach(PullPushObserver observer);
	public void notifyObservers();
}
