package trafficInterno;

public class AmberLightState implements TrafficLightState {

	private TrafficLightStateContext trafficLightStateContext;
	
	public AmberLightState(TrafficLightStateContext context) {
		this.trafficLightStateContext = context;
	}
	
	
	public void setTrafficLightStateContext(TrafficLightStateContext trafficLightStateContext) {
		this.trafficLightStateContext = trafficLightStateContext;
	}

	public void show() {
		System.out.println("AMBER LIGHT --> stop!!!");
		this.trafficLightStateContext.setTrafficLightState(this.trafficLightStateContext.getRedLightState());
	}

	public TrafficLightStateContext getTrafficLightStateContext() {
		return this.trafficLightStateContext;
	}

}
