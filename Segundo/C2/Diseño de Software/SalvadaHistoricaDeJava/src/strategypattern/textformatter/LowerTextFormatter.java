package strategypattern.textformatter;

public class LowerTextFormatter implements TextFormatterStrategy{

	@Override
	public void format(String cadena) {
		System.out.println("[LowerTextFormatter]: " + cadena.toLowerCase());
	}

}
