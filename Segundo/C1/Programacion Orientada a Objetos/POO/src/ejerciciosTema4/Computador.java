package ejerciciosTema4;

public class Computador {
	
	protected Double pesoEnKg;
	
	public Computador(Double pesoEnKg) {
		this.pesoEnKg = pesoEnKg;
	}

	public Double getPesoEnKg() {
		return this.pesoEnKg;
	}

	public void setPesoEnKg(Double pesoEnKg) {
		this.pesoEnKg = pesoEnKg;
	}

	@Override
	public String toString() {
		return "Computador [pesoEnKg=" + this.pesoEnKg + "]";
	}
	
	
}
