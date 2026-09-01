package strategypattern.textformatter;

public class TextEditorContext implements TextFormatterStrategy{
	
	private TextFormatterStrategy textFormatter;
	
	public TextEditorContext() {
		this(new EchoTextFormatter());
	}
	
	public TextEditorContext(TextFormatterStrategy textFormatter) {
		this.textFormatter = textFormatter;
	}
	
	public void format(String cadena) {
		this.textFormatter.format(cadena); //Delegacion por agregacion
	}

	public TextFormatterStrategy getTextFormatter() {
		return this.textFormatter;
	}

	public void setTextFormatter(TextFormatterStrategy textFormatter) {
		this.textFormatter = textFormatter;
	}
	
	
}
