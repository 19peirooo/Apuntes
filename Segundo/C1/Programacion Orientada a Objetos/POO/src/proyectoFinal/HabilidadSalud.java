package proyectoFinal;

//Clase Hija de Habilidad de Tipo Integer
public class HabilidadSalud extends Habilidad<Integer> {

	public HabilidadSalud(String nombre, Integer probabilidadUso, Double multiplicador) {
		super(nombre, probabilidadUso, multiplicador);
	}
	
	
	//Cura porcentaje de la vida del usuario --> Resultado es la curacion
	@Override
	public Integer usarHabilidad(Integer salud) {	
		 Integer curacion = 0;
		if (Utils.generarNumeroAleatorio(100) < this.probabilidadUso) {
			curacion = (int) (salud*super.multiplicador);
			System.out.println("Te has curado " + curacion + " puntos de vida");
		} else {
			System.out.println("Has fallado tu habilidad");
		}
		
		return curacion;
	}
	
	public String toString() {
		return "Habilidad Curativa" + super.toString();
	}
}
