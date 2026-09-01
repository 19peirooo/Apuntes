package tema4;

public class Tablet extends Computador{
	
	private Double pesoEnGramos;
	private String modelo;
	
	public Tablet(Double pesoGramos,String modelo) {
		super(pesoGramos/1000);
		this.pesoEnGramos = pesoGramos;
		this.modelo = modelo;
	}

	public Double getPesoEnGramos() {
		return pesoEnGramos;
	}

	public void setPesoEnGramos(Double pesoEnGramos) {
		this.pesoEnGramos = pesoEnGramos;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	@Override
	public String toString() {
		return "Tablet [pesoEnGramos=" + pesoEnGramos + ", modelo=" + modelo + "]";
	}
	
	public void muestraPesos() {
		System.out.println(this.pesoEnGramos);
		System.out.println(super.getPesoKilos());
	}
	
	public static void main(String[] args) {
		Tablet t = new Tablet(200.0, "iPad");
		System.out.println(t);
	}
	
}
