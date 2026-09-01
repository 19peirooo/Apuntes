package statepattern.traffic;

public class RedLightState implements TrafficLightState{
	
	private TrafficLight trafficLight;
	
	public RedLightState (TrafficLight trafficLight) {
		this.trafficLight = trafficLight;
	}
	
	@Override
	public void showState() {
		System.out.println("Red Light!!!");
		this.trafficLight.setTrafficLightState(new GreenLightState(this.trafficLight));
	}

}
