package traffic1;
/**
 * Estado concreto de un State Pattern
 * En este caso, corresponde a Frenar que se muestra con luz ámbar
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class AmberLightState implements TrafficLightState {
	
	private TrafficLight trafficLight;

	public 
	
	public void show() {
		System.out.println("Amber light, stop!");
		trafficLight.setTrafficLightState(new RedLightState());
	}

}
