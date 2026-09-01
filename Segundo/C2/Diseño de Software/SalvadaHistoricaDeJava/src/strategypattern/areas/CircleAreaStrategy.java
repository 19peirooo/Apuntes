package strategypattern.areas;

public class CircleAreaStrategy implements AreaStrategy{

	@Override
	public Double calcularArea(Double parametro) {
		return Math.PI * Math.pow(parametro, 2);
	}
	
}
