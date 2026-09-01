package PullObserverPatternChannels;

import java.util.Observer;

public class PullObserverPatternTest {
	public static void main(String[] args) {
		PullModelObservable model = new PullModelObservable();
		Observer observerRadio = new PullModelObserver("Radio Channel");
		Observer observerTv = new PullModelObserver("TV Channel");
		
		model.addObserver(observerRadio);
		model.addObserver(observerTv);
		
		model.setWeatherState("Its bright and sunny --> Lets play football");
		model.setWeatherState("Its raining heavily --> Lets play fifa");
		
	}
}
