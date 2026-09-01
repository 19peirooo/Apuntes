package tema2.sesion3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class InyectionContextAreaStrategy extends ContextAreaStrategy{
	
	List<GeometricArea> geometricAreaList;
	
	public static Double getRandomDoubleBetweenRange(Double min, Double max) {
		return (Math.random() * (max-min))+min;
	}
	
	public InyectionContextAreaStrategy() {
		this(new ArrayList<GeometricArea>());
	}
	
	public InyectionContextAreaStrategy(List<GeometricArea> geometricFigures) {
		this(new CircleAreaStrategy(),geometricFigures);
	}
	
	public InyectionContextAreaStrategy(AreaStrategy areaStrategy, List<GeometricArea> geometricAreaList) {
		super(areaStrategy);
		this.geometricAreaList = geometricAreaList;
	}
	
	public void sort(Comparator<GeometricArea> comparator) {
		Collections.sort(geometricAreaList, comparator);
	}
	
	public void print() {
		for (GeometricArea geometricFigure : geometricAreaList) {
			System.out.println(geometricFigure);
		}
	}

}
