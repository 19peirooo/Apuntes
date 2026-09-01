package tema3;

public class Circulo {
	
	public static final Double DEFAULT_RADIO = 1.0;
	public static final Punto DEFAULT_CENTRO = new Punto();
	
	private Double radio;
	private Punto centro;
	
	
	public Circulo() {
		this(DEFAULT_RADIO,DEFAULT_CENTRO);
	}
	
	public Circulo(Double radio) {
		this(radio,DEFAULT_CENTRO);
	}
	
	//Constructor Principal
	public Circulo(Double radio, Punto centro) {
		this.radio = radio;
		this.centro = centro;
	}
	
	public Double getRadio() {
		return this.radio;
	}
	
	public void setRadio(Double newRadio) {
		this.radio = newRadio;
	}
	
	public Punto getCentro() {
		return this.centro;
	}
	
	public void setCentro(Punto newCentro) {
		this.centro = newCentro;
		
	}
	
	public String toString() {
		return "Circulo [Radio= " + this.radio + " Centro= " + this.centro + "]";
	}
	
	public void desplazarCentro(Punto p) {
		this.centro.deplazaHastaPunto(p);
		this.centro.setDesplazado(true);
	}
	
	public static void main(String[] args) {
		Circulo circulo = new Circulo();
		Circulo otroCirculo = new Circulo(2.0, new Punto(2,2));
		Circulo anotherCirculo = new Circulo(5.3, new Punto(10,7));
		
		System.out.println(otroCirculo);
		circulo.desplazarCentro(anotherCirculo.getCentro());
		System.out.println(circulo);
	}

}
