package strategypattern.areas;

import java.util.Comparator;

public class AscendingAreaComparator implements Comparator<GeometricArea>{

	@Override
	public int compare(GeometricArea figure1, GeometricArea figure2) {
		return figure1.getArea().compareTo(figure2.getArea());
	}
	
}
