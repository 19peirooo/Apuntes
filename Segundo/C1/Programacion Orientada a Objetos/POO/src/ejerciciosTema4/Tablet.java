package ejerciciosTema4;

public class Tablet extends Computador{
	
	private Double pesoEnGramos;
	
	public Tablet(Double pesoEnGramos) {
		super(pesoEnGramos/1000);
		this.pesoEnGramos = pesoEnGramos;
	}

	public Double getPesoEnGramos() {
		return pesoEnGramos;
	}

	public void setPesoEnGramos(Double pesoEnGramos) {
		this.pesoEnGramos = pesoEnGramos;
	}

	@Override
	public String toString() {
		return super.toString() + " Tablet [pesoEnGramos=" + this.pesoEnGramos + "]";
	}
	
	public void imprimirPesos() {
		System.out.println("Peso en kg: " + this.pesoEnKg + "kg");
		System.out.println("Peso en g: " + this.pesoEnGramos + "g");
	}
	
	public static void main(String[] args) {
		Tablet tablet = new Tablet(1000.0);
		tablet.imprimirPesos();
	}
	
	
	
}
