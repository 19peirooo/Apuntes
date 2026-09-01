package observerpattern.channels;

import java.util.ArrayList;
import java.util.List;

public class WeatherObservable implements PullPushObservable{
	
	List<PullPushObserver> observers;
	public String weather;
	
	public WeatherObservable(String weather) {
		this.weather = weather;
		this.observers = new ArrayList<PullPushObserver>();
	}
	
	public String getWeather() {
		return this.weather;
	}

	public void setWeather(String weather) {
		this.weather = weather;
		this.notifyObservers();
	}

	@Override
	public void attach(PullPushObserver observer) {
		this.observers.add(observer);
	}
	
	@Override
	public void detach(PullPushObserver observer) {
		this.observers.remove(observer);
	}
	
	@Override
	public void notifyObservers() {
		for (PullPushObserver observer : this.observers) {
			observer.update(this, this.weather);
		}
	}
	
	
}
