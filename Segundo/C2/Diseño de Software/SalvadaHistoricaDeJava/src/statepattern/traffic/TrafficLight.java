package statepattern.traffic;

public class TrafficLight {
	private TrafficLightState trafficLightState;
	
	public TrafficLight() {
		this(null);
		this.trafficLightState = new RedLightState(this);
	}
	
	public TrafficLight(TrafficLightState trafficLightState) {
		super();
		this.trafficLightState = trafficLightState;
	}

	public TrafficLightState getTrafficLightState() {
		return this.trafficLightState;
	}

	public void setTrafficLightState(TrafficLightState trafficLightState) {
		this.trafficLightState = trafficLightState;
	}
	
	public void showState() {
		this.trafficLightState.showState();
	}
}
