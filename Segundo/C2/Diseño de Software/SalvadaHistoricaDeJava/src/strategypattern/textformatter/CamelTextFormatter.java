package strategypattern.textformatter;

public class CamelTextFormatter implements TextFormatterStrategy{

	@Override
	public void format(String cadena) {
		StringBuilder camelText = new StringBuilder("");
		for (int i = 0; i < cadena.length(); i++) {
			if (i%2 == 0) {
				camelText.append(Character.toUpperCase(cadena.charAt(i)));
			} else {
				camelText.append(Character.toLowerCase(cadena.charAt(i)));
			}
		}
		System.out.println("[CamelTextFormatter]: " + camelText.toString());		
	}
}