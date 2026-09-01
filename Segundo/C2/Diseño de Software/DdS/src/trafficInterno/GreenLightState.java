package trafficInterno;

public class GreenLightState implements TrafficLightState {

	private TrafficLightStateContext trafficLightStateContext;
	
	public GreenLightState(TrafficLightStateContext context) {
		this.trafficLightStateContext = context;
	}
	
	
	public void setTrafficLightStateContext(TrafficLightStateContext trafficLightStateContext) {
		this.trafficLightStateContext = trafficLightStateContext;
	}

	public void show() {
		System.out.println("RED LIGHT --> stop and wait!!!");
		this.trafficLightStateContext.setTrafficLightState(this.trafficLightStateContext.getAmberLightState());
	}

	public TrafficLightStateContext getTrafficLightStateContext() {
		return this.trafficLightStateContext;
	}

}
