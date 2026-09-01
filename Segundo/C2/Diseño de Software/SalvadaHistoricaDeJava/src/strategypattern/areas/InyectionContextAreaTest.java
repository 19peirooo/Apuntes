package strategypattern.areas;

import java.util.ArrayList;
import java.util.List;

public class InyectionContextAreaTest {
	public static void main(String[] args) {
		List<GeometricArea> geometricFigures = new ArrayList<GeometricArea>();
		
		for (int i = 0; i < 10; i++) {
			geometricFigures.add(new Square(InyectionContextAreaStrategy.getRandomDoubleBetweenRange(1d, 10d)));
			geometricFigures.add(new Circle(InyectionContextAreaStrategy.getRandomDoubleBetweenRange(1d, 10d)));
		}
		
		InyectionContextAreaStrategy inyection = new InyectionContextAreaStrategy(geometricFigures);
		System.out.println("En orden ascendente:");
		inyection.sort(new AscendingAreaComparator());
		inyection.print();
		System.out.println("");
		System.out.println("En orden descendente: ");
		inyection.sort(new DescendingAreaComparator());
		inyection.print();
		
	}
}
