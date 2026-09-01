package strategypattern.areas;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class InyectionContextAreaStrategy extends ContextAreaStrategy{
	
	private List<GeometricArea> geometricFigures;
	
	public static Double getRandomDoubleBetweenRange(Double min, Double max) {
		return (Math.random()*(max-min))+min;
	}
	
	public InyectionContextAreaStrategy() {
		this(new ArrayList<GeometricArea>());
	}
	
	public InyectionContextAreaStrategy(List<GeometricArea> figures) {
		this(figures,new CircleAreaStrategy());
	}
	
	public InyectionContextAreaStrategy(List<GeometricArea> figures, AreaStrategy strategy) {
		super(strategy);
		this.geometricFigures = figures;
	}
	
	public void sort(Comparator<GeometricArea> comparator) {
		Collections.sort(this.geometricFigures,comparator);
	}
	
	public void print() {
		for (GeometricArea figure : this.geometricFigures) {
			System.out.println(figure.toString());
		}
	}
}
