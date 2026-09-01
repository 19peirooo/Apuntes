package PushPullObserverPattern;
/**
 * Interface de un modelo observable que aplica protocolo Pull-Push 
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public interface PullPushSubject {
	public void attach(PullPushObserver observer);
	public void detach(PullPushObserver observer);
	public void notifyObservers();  
}
