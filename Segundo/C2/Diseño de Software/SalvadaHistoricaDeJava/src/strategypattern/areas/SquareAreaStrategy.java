package strategypattern.areas;

public class SquareAreaStrategy implements AreaStrategy {

	@Override
	public Double calcularArea(Double parametro) {
		return Math.pow(parametro, 2);
	}
	

}
