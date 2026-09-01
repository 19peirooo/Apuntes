package traffic2;
/**
 * Interface de estado
 * El estado debe tener acceso al contexto
 * @author  Miguel Ángel Mesas Uzal
 * fecha:   2022-2023
 *
 */
public interface TrafficLightState {
	public void show(); 
	public TrafficLightContext getTrafficLightContext();
}
