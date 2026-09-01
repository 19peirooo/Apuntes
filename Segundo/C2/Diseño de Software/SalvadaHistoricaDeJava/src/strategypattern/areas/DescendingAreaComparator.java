package strategypattern.areas;

import java.util.Comparator;

public class DescendingAreaComparator implements Comparator<GeometricArea>{

	@Override
	public int compare(GeometricArea figure1, GeometricArea figure2) {
		return figure2.getArea().compareTo(figure1.getArea());
	}

}
