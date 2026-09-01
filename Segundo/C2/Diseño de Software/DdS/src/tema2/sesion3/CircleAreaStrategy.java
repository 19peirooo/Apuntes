package tema2.sesion3;

public class CircleAreaStrategy implements AreaStrategy{
	@Override
	public Double calcularArea(Double radio) {
		return Math.PI * Math.pow(radio, 2);
	}

}
