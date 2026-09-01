package PullObserverPatternChannels;

import java.util.Observable;

public class PullPushModelObservable extends Observable{
	public static final String DEFAULT_STATE = "N/A";
	protected String weatherState;
	
	public PullPushModelObservable() {
		this(PullModelObservable.DEFAULT_STATE);
	}
	
	public PullPushModelObservable(String weatherState) {
		this.weatherState = weatherState;
	}
	
	public String getWeatherState() {
		return this.weatherState;
	}
	
	public void setWeatherState(String weatherState) {
		this.weatherState = weatherState;
		this.setChanged();
		this.notifyObservers(this.weatherState);
	}
}
