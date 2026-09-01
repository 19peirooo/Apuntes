package tema3;

public class Punto {
	
	public static final Integer DEFAULT_X = 0;
	public static final Integer DEFAULT_Y = 0;
	private Integer x;
	private Integer y;
	private boolean desplazado;
	
	//Constructor Sin Parametros
	public Punto() {
		this(Punto.DEFAULT_X);
	}
	
	//Constructor Con Un Parametro
	public Punto(Integer x) {
		this(x, Punto.DEFAULT_Y);
	}
	
	//Constructor Principal
	public Punto(Integer x, Integer y) {
		this.x = x;
		this.y = y;
		this.desplazado = false;
	}
	
	//getter
	public Integer getX() {
		return this.x;
	}
	
	//setter
	public void setX(Integer x) {
		this.x = x;
	}
	
	public Integer getY() {
		return this.x;
	}
	
	public void setY(Integer y) {
		this.y = y;
	}
	
	public boolean getDesplazado() {
		return this.desplazado;
	}
	
	public void setDesplazado(boolean newDesplazado) {
		this.desplazado = newDesplazado;
	}
	
	@Override
	public String toString() {
		return "Punto [x=" + this.x + ", y=" + this.y + ", desplazado= "+ this.desplazado + "]";
	}
	
	public void deplazaHastaPunto(Punto p) {
		this.x = p.x;
		this.y = p.y;
	}
	
	public static void main(String[] args) {
		Punto punto = new Punto();
		Punto punto2 = new Punto(2);
		Punto punto3 = new Punto(3,4);
		System.out.println(punto);
		System.out.println(punto2);
		System.out.println(punto3);
		
		punto.deplazaHastaPunto(punto3);
		System.out.println("Se ha movido hasta el punto 3: " + punto);
	}
}