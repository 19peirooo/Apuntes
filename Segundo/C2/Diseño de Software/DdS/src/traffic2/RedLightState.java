package traffic2;
/**
 * Estado concreto de un State Pattern
 * En este caso, corresponde a No pasar que se muestra con luz roja
 * El propio estado produce la transición al siguiente estado
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class RedLightState implements TrafficLightState { 
	private TrafficLightContext trafficLightContext; 
	
	
	public RedLightState(TrafficLightContext trafficLightContext) {
		super();
		this.trafficLightContext = trafficLightContext;
	}


	public TrafficLightContext getTrafficLightContext() {
		return trafficLightContext;
	}


	public void setTrafficLightContext(TrafficLightContext trafficLightContext) {
		this.trafficLightContext = trafficLightContext;
	}


	public void show() { 
		System.out.println("Red light, stop and wait!!"); 
		this.trafficLightContext.setTrafficLightState(new GreenLightState(trafficLightContext)); 
	} 
} 
