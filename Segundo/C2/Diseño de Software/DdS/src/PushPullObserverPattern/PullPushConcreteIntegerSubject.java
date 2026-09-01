package PushPullObserverPattern;

import java.util.ArrayList;
import java.util.List;

/**
 * Modelo observable 'concreto' que aplica protocolo Pull-Push
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class PullPushConcreteIntegerSubject implements PullPushSubject {

	 private List<PullPushObserver> observers;
	 private Integer state;
	
	 public PullPushConcreteIntegerSubject() {
		this(0);
	}

	public PullPushConcreteIntegerSubject(Integer state) {
		this(state, new ArrayList<PullPushObserver>());
	}

	public PullPushConcreteIntegerSubject(Integer state, 
										List<PullPushObserver> observers) {
		super();
		this.state = state;
		this.observers = observers;
	}

	public Integer getState() {
		return state;
	}

	public void setState(Integer state) {
		this.state = state;
		this.notifyObservers();
	}

	public void attach(PullPushObserver observer){
		this.observers.add(observer);
	 }
	 
	 public void detach(PullPushObserver observer){
		 this.observers.remove(observer);
	 }
	 public void notifyObservers(){
		 for (PullPushObserver observer : observers) {
			 observer.update(this,this.state);
		 }
	 }
	
	
}
