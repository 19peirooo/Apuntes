package ejerciciosTema3;

public class Circulo {
	
	public static final Punto DEFAULT_CENTRO = new Punto();
	public static final Double DEFUALT_RADIO = 1.0;
	
	private Punto centro;
	private Double radio;
	
	public Circulo () {
		this(Circulo.DEFAULT_CENTRO, Circulo.DEFUALT_RADIO);
	}
	
	public Circulo (Punto centro, Double radio) {
		this.centro = centro;
		this.radio = radio;
	}

	public Punto getCentro() {
		return this.centro;
	}

	public void setCentro(Punto centro) {
		this.centro = centro;
	}

	public Double getRadio() {
		return this.radio;
	}

	public void setRadio(Double radio) {
		this.radio = radio;
	}

	@Override
	public String toString() {
		return "Circulo [centro=" + centro + ", radio=" + radio + "]";
	}
	
	public static void main(String[] args) {
		Circulo circulo = new Circulo();
		System.out.println(circulo);
	}
	
	
	
}
