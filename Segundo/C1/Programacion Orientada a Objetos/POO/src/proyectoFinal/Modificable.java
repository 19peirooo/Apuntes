package proyectoFinal;

import java.util.List;

//Intefaz de la evolucion
public interface Modificable {
	public Boolean comprobarModificacion(List<Jugador> jugadores, Integer numRondas);
	public void modificar(List<Jugador> jugadores, Integer numRondas);
}
