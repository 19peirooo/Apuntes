package traffic1;
/**
 * Clase Test State pattern según solución 1
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class TrafficLightTest { 
	public static void main(String[] args) { 
		
		TrafficLight trafficLight = new TrafficLight(new GreenLightState()); 
		trafficLight.show(); 
		trafficLight.setTrafficLightState(new AmberLightState()); 
		trafficLight.show(); 
		trafficLight.setTrafficLightState(new RedLightState()); 
		trafficLight.show(); 
	} 
}