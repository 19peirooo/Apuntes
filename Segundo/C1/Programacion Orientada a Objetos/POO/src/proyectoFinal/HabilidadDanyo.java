package proyectoFinal;

//Clase Hija de Habilidad de Tipo Integer
public class HabilidadDanyo extends Habilidad<Integer>{

	public HabilidadDanyo(String nombre, Integer probabilidadUso, Double multiplicador) {
		super(nombre, probabilidadUso,multiplicador);

	}
	
	
	//Aumenta o disminuye el daño 
	@Override
	public Integer usarHabilidad(Integer danyo) {
		Integer danyoNuevo = danyo;
		if (Utils.generarNumeroAleatorio(100) < this.probabilidadUso) {
			danyoNuevo = (int) (danyo*multiplicador);
			if (super.multiplicador > 1) {
				System.out.println("Ahora eres mas fuerte");
			} else {
				System.out.println("Tus golpes no son lo que eran");
			}
		} else {
			System.out.println("Has fallado tu habilidad");
		}
		
		return danyoNuevo;
	}
	
	public String toString() {
		return "Habilidad de Daño" + super.toString();
	}

}
