package traffic1;
/**
 * Contexto de un State Pattern, en este caso un semáforo de tráfico
 *
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public class TrafficLight  {
	private TrafficLightState trafficLightState;

	public TrafficLight(TrafficLightState trafficLightState) {
		super();
		this.trafficLightState = trafficLightState;
	}

	public TrafficLightState getTrafficLightState() {
		return trafficLightState;
	}

	public void setTrafficLightState(TrafficLightState trafficLightState) {
		this.trafficLightState = trafficLightState;
	}

	public void show() {
		this.trafficLightState.show(); //Delegación
	}
	
}
