package tema2.sesion3;

public class SquareAreaStrategy implements AreaStrategy{
	@Override
	public Double calcularArea(Double longitud) {
		return Math.pow(longitud, 2);
	}

}
