package strategypattern.areas;

public class Circle implements GeometricArea{
	
	public static final Double DEFAULT_RADIO = 1.0;
	
	private Double radio;
	private Double area;
	
	public Circle() {
		this(Circle.DEFAULT_RADIO);
	}
	
	public Circle(Double radio) {
		this.radio = radio;
		this.area = this.getArea();
	}
	
	@Override
	public Double getArea() {
		return new ContextAreaStrategy(new CircleAreaStrategy()).calcularArea(this.radio);
	}
	
	public Double getRadio() {
		return this.radio;
	}
	
	public void setLado(Double lado) {
		this.radio = lado;
		this.area = this.getArea();
	}
	
	public String toString() {
		return "Circle [ radio (" + this.radio + "), area (" + this.area + ") ]";
	}
	
}
