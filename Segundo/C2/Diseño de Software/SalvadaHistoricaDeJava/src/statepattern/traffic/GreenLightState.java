package statepattern.traffic;

public class GreenLightState implements TrafficLightState{
	
	private TrafficLight trafficLight;
	
	public GreenLightState (TrafficLight trafficLight) {
		this.trafficLight = trafficLight;
	}
	
	@Override
	public void showState() {
		System.out.println("Green Light!!!");
		trafficLight.setTrafficLightState(new AmberLightState(trafficLight));
	}
	
}
