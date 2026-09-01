package PullObserverPatternChannels;

import java.util.Observer;
import java.util.Observable;

public class PullPushModelObserver extends Observer{
	protected String name;
	
	public PullPushModelObserver(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void update(Observable observable, Object state) {
		if (observable instanceof PullPushModelObservable) {
			System.out.println("[Pull Protocol " + this.name + "]" +
					((PullModelObservable) observable).getWeatherState());
		}
		if (state instanceof String) {
			System.out.println("[Push Protocol " + this.name + "]" + ((String)state));
		}
	}
}
