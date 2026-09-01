package ejerciciosTema3;

public class Punto {
	
	public static final Double DEFAULT_NUM = 0.0;
	
	private Double x;
	private Double y;
	
	public Punto() {
		this(Punto.DEFAULT_NUM,Punto.DEFAULT_NUM);
	}
	
	public Punto(Double x, Double y) {
		this.x = x;
		this.y = y;
	}
	
	public Double getX() {
		return this.x;
	}
	
	public void setX(Double x) {
		this.x = x;
	}
	
	public Double getY() {
		return this.y;
	}
	
	public void setY(Double y) {
		this.y = y;
	}
	
	public String toString() {
		return "Punto (" + this.x +","+this.y+")";
	}
}
