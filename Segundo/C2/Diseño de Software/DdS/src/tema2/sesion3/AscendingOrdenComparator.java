package tema2.sesion3;

import java.util.Comparator;

public class AscendingOrdenComparator implements Comparator<GeometricArea>{
	public int compare(GeometricArea geometricFigure1, GeometricArea geometricFigure2) {
		return geometricFigure1.getArea().compareTo(geometricFigure2.getArea());
	}
}
