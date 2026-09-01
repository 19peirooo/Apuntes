package strategypattern.textformatter;

public class EchoTextFormatter implements TextFormatterStrategy{

	@Override
	public void format(String cadena) {
		System.out.println("[EchoTextFormatter]: " + cadena);
	}

}
