package traffic1;
/**
 * Estado concreto de un State Pattern
 * En este caso, corresponde a No pasar que se muestra con luz roja
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class RedLightState implements TrafficLightState {

	public void show() {
		System.out.println("Red light, stop and wait!!"); 
	}

}
