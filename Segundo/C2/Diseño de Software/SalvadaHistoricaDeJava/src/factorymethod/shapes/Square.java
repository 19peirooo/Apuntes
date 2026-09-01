package factorymethod.shapes;

public class Square implements Shape{
	
	private Double side;
	
	public Square() {
		this(4.0);
	}
	
	public Square(Double side) {
		this.side = side;
	}
	
	public Double getSide() {
		return this.side;
	}

	public void setSide(Double side) {
		this.side = side;
	}

	@Override
	public Double calcularArea() {
		return Math.pow(this.side, 2);
	}

	@Override
	public String toString() {
		return "Square [side=" + side + ", area=" + this.calcularArea() + "]";
	}
	
	

}
