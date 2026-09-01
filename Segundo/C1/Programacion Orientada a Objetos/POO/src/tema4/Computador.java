package tema4;

public class Computador {
	
	public static final Double DEFAULT_PESO = 1.0;
	protected Double pesoKilos;
	
	public Computador() {
		this(Computador.DEFAULT_PESO);
	}
	
	public Computador(Double pesoKilos) {
		this.pesoKilos = pesoKilos;
	}

	public Double getPesoKilos() {
		return pesoKilos;
	}

	public void setPesoKilos(Double pesoKilos) {
		this.pesoKilos = pesoKilos;
	}

	@Override
	public String toString() {
		return "Computador [pesoKilos=" + pesoKilos + "]";
	}
	
}
