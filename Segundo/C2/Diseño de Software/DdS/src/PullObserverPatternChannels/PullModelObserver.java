package PullObserverPatternChannels;

import java.util.Observable;
import java.util.Observer;

public class PullModelObserver implements Observer{
	protected String name;
	
	public PullModelObserver(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void update(Observable observable, Object arg) {
			System.out.println("[Pull Protocol " + this.name + "]" +
					((PullModelObservable) observable).getWeatherState());
	}
}
