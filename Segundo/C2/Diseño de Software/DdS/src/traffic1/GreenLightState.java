package traffic1;
/**
 * Estado concreto de un State Pattern
 * En este caso, corresponde a Pasar que se muestra con luz verde
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class GreenLightState implements TrafficLightState {

	public void show() {
		System.out.println("Green light, go forward!!"); 
	}

}
