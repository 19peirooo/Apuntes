package proyectoFinal;

//Clase Hija de Habilidad de Tipo Boolean
public class HabilidadTurno extends Habilidad<Boolean>{
	
	
	//Constructor de 2 parametros ya que no tiene multiplicador
	public HabilidadTurno(String nombre, Integer probabilidadUso) {
		super(nombre, probabilidadUso);
		
	}

	
	//Desactiva el turno de el contrincante
	public Boolean usarHabilidad(Boolean valor) {
		Boolean turnoActivo = valor;
		if (Utils.generarNumeroAleatorio(100) < this.probabilidadUso && turnoActivo) {
			turnoActivo = false;
		} else {
			System.out.println("Has fallado tu habilidad");
		}
		return turnoActivo;
	}


	@Override
	public String toString() {
		return "HabilidadTurno [nombre=" + super.nombre + ", probabilidadUso=" + super.probabilidadUso + "]";
	}
	
	

}
