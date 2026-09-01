package strategypattern.textformatter;

public class CapTextFormatter implements TextFormatterStrategy{

	@Override
	public void format(String cadena) {
		System.out.println("[CapTextFormatter]: " + cadena.toUpperCase());
	}

}
