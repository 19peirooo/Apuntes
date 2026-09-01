package tema2.sesion3;

public class Circle implements GeometricArea{
	public static final Double DEFAULT_RADIO = 0.0;
	
	private Double radius;
	private Double area;
	
	public Circle() {
		this(Circle.DEFAULT_RADIO);
	}
	
	public Circle(Double radius) {
		this.radius = radius;
		this.area = this.getArea();
	}
	
	public Double getRadius() {
		return this.radius;
	}
	
	public Double getArea() {
		return new ContextAreaStrategy(new CircleAreaStrategy()).calcularArea(this.radius);
	}
	
	public String toString() {
		return "Circle [side (" + this.radius + "), area (" + this.area + ")]";
	}
	
	public static void main(String[] args) {
		Circle circleExample = new Circle(1.0);
		System.out.println(circleExample);
	}
}
