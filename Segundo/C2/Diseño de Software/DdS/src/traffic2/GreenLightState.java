package traffic2;
/**
 * Estado concreto de un State Pattern
 * En este caso, corresponde a Pasar que se muestra con luz verde
 * El propio estado produce la transición al siguiente estado
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class GreenLightState implements TrafficLightState { 
	private TrafficLightContext trafficLightContext; 
	public GreenLightState(TrafficLightContext trafficLightContext) {
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
		System.out.println("Green light, go forward!!"); 
		this.trafficLightContext.setTrafficLightState(new AmberLightState(this.trafficLightContext)); 
	} 
} 