package PullObserverPattern;

public interface PullSubject {
	
	public void attach(PullObserver observer);
	public void detach(PullObserver observer);
	public void notifyObservers();
	
}
