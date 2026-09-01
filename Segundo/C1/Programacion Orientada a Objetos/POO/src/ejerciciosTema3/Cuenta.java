package ejerciciosTema3;

public class Cuenta {
	
	public static final Double DEFAULT_CANTIDAD = 0.0;
	
	private String titular;
	private Double cantidad;
	
	public Cuenta(String titular) {
		this(titular, Cuenta.DEFAULT_CANTIDAD);
	}
	
	public Cuenta(String titular, Double cantidad) {
		this.titular = titular;
		this.cantidad = cantidad;
	}
	
	public String getTitular() {
		return this.titular;
	}
	
	public void setTitular(String titular) {
		this.titular = titular;
	}
	
	public Double getCantidad() {
		return this.cantidad;
	}
	
	public void setCantidad(Double cantidad) {
		this.cantidad = cantidad;
	}
	
	public String toString() {
		return "Cuenta [titular= " + this.titular + ", cantidad= " + this.cantidad + "]";
	}
	
	public void ingresar(Double cantidad) {
		this.cantidad += cantidad;
	}
	
	public void retirar(Double cantidad) {
		if (this.cantidad - cantidad >= 0) {
			this.cantidad -= cantidad;
		} else {
			System.out.println("ERROR: No tienes tanto dinero en la cuenta");
		}
	}
	
	public static void main(String[] args) {
		Cuenta c1 = new Cuenta("Pablo", 10.0);
		Cuenta c2 = new Cuenta("Victor");
		
		c2.ingresar(2.0);
		System.out.println(c2.cantidad);
		c1.retirar(5.0);
		System.out.println(c1.cantidad);
		c2.retirar(3.0);
		System.out.println(c2.cantidad);
		System.out.println(c2);
	}
	
	
}
