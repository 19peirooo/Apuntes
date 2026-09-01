package factorymethod.shapes;

public class SquareFactory implements ShapeFactory{

	@Override
	public Shape createShape(Double side, Double uselessParam) {
		return new Square(side);
	}

}
