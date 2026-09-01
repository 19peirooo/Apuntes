package strategypattern.areas;

public class Square implements GeometricArea{
	
	public static final Double DEFAULT_LADO = 1.0;
	
	private Double lado;
	private Double area;
	
	public Square() {
		this(Square.DEFAULT_LADO);
	}
	
	public Square(Double lado) {
		this.lado = lado;
		this.area = this.getArea();
	}
	
	@Override
	public Double getArea() {
		return new ContextAreaStrategy(new SquareAreaStrategy()).calcularArea(this.lado);
	}
	
	public Double getLado() {
		return this.lado;
	}
	
	public void setLado(Double lado) {
		this.lado = lado;
		this.area = this.getArea();
	}
	
	public String toString() {
		return "Square [ lado (" + this.lado + "), area (" + this.area + ") ]";
	}
	
}
