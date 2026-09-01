package trafficInterno;

public class RedLightState implements TrafficLightState {

	private TrafficLightStateContext trafficLightStateContext;
	
	public RedLightState(TrafficLightStateContext context) {
		this.trafficLightStateContext = context;
	}
	
	public void setTrafficLightStateContext(TrafficLightStateContext trafficLightStateContext) {
		this.trafficLightStateContext = trafficLightStateContext;
	}

	public void show() {
		System.out.println("RED LIGHT --> stop and wait!!!");
		this.trafficLightStateContext.setTrafficLightState(this.trafficLightStateContext.getGreenLightState());
	}

	public TrafficLightStateContext getTrafficLightStateContext() {
		return this.trafficLightStateContext;
	}
	

}
