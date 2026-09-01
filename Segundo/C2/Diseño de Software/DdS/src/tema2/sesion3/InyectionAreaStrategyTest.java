package tema2.sesion3;

import java.util.ArrayList;
import java.util.List;

public class InyectionAreaStrategyTest {
	public static void main(String[] args) {
		List<GeometricArea> geometricFigures = new ArrayList<GeometricArea>();
		
		for (int i = 0; i < 10; i++) {
			geometricFigures.add(new Square(InyectionContextAreaStrategy.getRandomDoubleBetweenRange(1d, 10d)));
			geometricFigures.add(new Circle(InyectionContextAreaStrategy.getRandomDoubleBetweenRange(1d, 10d)));
		}
		
		InyectionContextAreaStrategy inyection = new InyectionContextAreaStrategy(geometricFigures);
		inyection.sort(new AscendingOrdenComparator());
		inyection.print();
		inyection.sort(new DescendingOrdenComparator());
		inyection.print();
		
	}
}
