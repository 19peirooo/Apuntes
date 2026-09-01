package tema2.sesion3;

public class LowerTextFormatter implements TextFormatterStrategy{
	public void format(String text) {
		System.out.println("[LowerTextFormatter]: " + text.toLowerCase());
	}
}
