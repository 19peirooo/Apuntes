package PullObserverPattern;

import java.util.List;
import java.util.ArrayList;

public class ConcreteIntegerSubject implements PullSubject{
	
	public List<PullObserver> observers;
	public Integer state;
	
	public ConcreteIntegerSubject() {
		this(0);
	}
	
	public ConcreteIntegerSubject(Integer state) {
		this(state, new ArrayList<PullObserver>());		
	}
	
	public ConcreteIntegerSubject(Integer state, List<PullObserver> observers) {
		this.state = state;
		this.observers = observers;
	}
	
	
	public List<PullObserver> getObservers() {
		return this.observers;
	}

	public void setObservers(List<PullObserver> observers) {
		this.observers = observers;
	}

	public Integer getState() {
		return this.state;
	}

	public void setState(Integer state) {
		this.state = state;
		this.notifyObservers();
	}

	public void attach(PullObserver observer) {
		this.observers.add(observer);
	}

	public void detach(PullObserver observer) {
		this.observers.remove(observer);
	}

	public void notifyObservers() {
		for(PullObserver observer : observers) {
			observer.update();
		}
	}

}
