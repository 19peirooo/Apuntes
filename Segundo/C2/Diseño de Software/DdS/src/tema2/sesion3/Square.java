package tema2.sesion3;

public class Square implements GeometricArea{
	
	public static final Double DEFAULT_SIDE = 0.0;
	
	private Double side;
	private Double area;
	
	public Square() {
		this(Square.DEFAULT_SIDE);
	}
	
	public Square(Double side) {
		this.side = side;
		this.area = this.getArea();
	}
	
	public Double getSide() {
		return this.side;
	}
	
	public Double getArea() {
		return new ContextAreaStrategy(new SquareAreaStrategy()).calcularArea(this.side);
	}
	
	public String toString() {
		return "Square [side (" + this.side + "), area (" + this.area + ")]";
	}
}
