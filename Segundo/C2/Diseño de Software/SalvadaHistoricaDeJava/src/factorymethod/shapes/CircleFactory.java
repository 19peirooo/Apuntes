package factorymethod.shapes;

public class CircleFactory implements ShapeFactory{

	@Override
	public Shape createShape(Double radius, Double uselessParam) {
		return new Circle(radius);
	}

}
