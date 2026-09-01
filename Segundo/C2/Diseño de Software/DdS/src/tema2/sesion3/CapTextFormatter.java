package tema2.sesion3;

public class CapTextFormatter implements TextFormatterStrategy{
	public void format(String text) {
		System.out.println("[CapTextFormatter]: " + text.toUpperCase());	
	}

}
