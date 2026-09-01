package proyectoFinal;

//Clase Hija de Habilidad de Tipo Integer
public class HabilidadRevive extends Habilidad<Integer>{
	
	//Constructor de 2 parametros ya que no tiene multiplicador
	public HabilidadRevive(String nombre, Integer probabilidadUso) {
		super(nombre, probabilidadUso);
	}

	//Metodo para revivir --> Revives a la mitad de la salud
	@Override
	public Integer usarHabilidad(Integer valor) {
		Integer salud = 0;
		if (Utils.generarNumeroAleatorio(100) < this.probabilidadUso) {
			salud = (int) (valor * 0.5);
		} else {
			System.out.println("Has fallado tu habilidad");
		}
		return salud;
	}

	@Override
	public String toString() {
		return "HabilidadRevive [nombre=" + super.nombre + ", probabilidadUso=" + super.probabilidadUso + "]";
	}

}
