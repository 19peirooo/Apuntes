package tema2.sesion3;

import java.util.Comparator;

public class DescendingOrdenComparator implements Comparator<GeometricArea>{
	public int compare(GeometricArea geometricFigure1, GeometricArea geometricFigure2) {
		return geometricFigure2.getArea().compareTo(geometricFigure1.getArea());
	}
}

