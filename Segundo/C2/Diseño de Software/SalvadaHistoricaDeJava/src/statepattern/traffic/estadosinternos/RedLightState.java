package statepattern.traffic.estadosinternos;

public class RedLightState implements TrafficLightState{
	
	private TrafficLight trafficLight; //Se le pasa el contexto al estado concreto para manejar los estados internos
	
	public RedLightState (TrafficLight trafficLight) {
		this.trafficLight = trafficLight;
	}
	
	@Override
	public void showState() {
		System.out.println("Red Light!!!");
		this.trafficLight.setTrafficLightState(this.trafficLight.getGreenLight());
	}

}
