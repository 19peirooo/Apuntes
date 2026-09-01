package tema5.practica1;

public class DividePorCero {
	public static void main(String[] args) {
		try {
			Integer div = 10/0;
		} catch (ArithmeticException e) {
			throw new ArithmeticException("ERROR: No se puede dividir entre 0");
		}
	}
}
