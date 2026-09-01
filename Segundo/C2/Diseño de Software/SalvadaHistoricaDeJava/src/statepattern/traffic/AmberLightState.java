package statepattern.traffic;

public class AmberLightState implements TrafficLightState{
	
	private TrafficLight trafficLight;
	
	public AmberLightState (TrafficLight trafficLight) {
		this.trafficLight = trafficLight;
	}
	
	@Override
	public void showState() {
		System.out.println("Amber Light!!!");
		trafficLight.setTrafficLightState(new RedLightState(trafficLight));
	}

}
