package traffic2;
/**
 * Estado concreto de un State Pattern
 * En este caso, corresponde a Frenar que se muestra con luz ámbar
 * El propio estado produce la transición al siguiente estado
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class AmberLightState implements TrafficLightState { 
	private TrafficLightContext trafficLightContext; 
	
	public AmberLightState(TrafficLightContext trafficLightContext) {
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
		System.out.println("Amber light, stop!"); 
		this.trafficLightContext.setTrafficLightState(new RedLightState(this.trafficLightContext)); 
	} 
} 