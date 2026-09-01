package proyectoFinal;

//Clase Hija de Habilidad de Tipo Double
public class HabilidadResistencia extends Habilidad<Double> {

	public HabilidadResistencia(String nombre, Integer probabilidadUso, Double multiplicador) {
		super(nombre, probabilidadUso, multiplicador);
	}
	
	
	//Aumenta o disminuye la resistencia
	@Override
	public Double usarHabilidad(Double resistencia) {
		Double resistenciaNueva = resistencia;
		if (Utils.generarNumeroAleatorio(100) < this.probabilidadUso) {
			resistenciaNueva = resistencia*super.multiplicador;
			if (super.multiplicador > 1) {
				System.out.println("Ahora eres mas resistente");
			} else {
				System.out.println("Te sientes mas debil");
			}
		} else {
			System.out.println("Has fallado tu habilidad");
		}
		return resistenciaNueva;
	}
	
	public String toString() {
		return "HabilidadResistencia" + super.toString();
	}

}
