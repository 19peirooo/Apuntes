package tema2.sesion3;

public class TextEditor implements TextFormatterStrategy{
	TextFormatterStrategy textFormatter;
	
	public TextEditor(TextFormatterStrategy textFormatter) {
		this.textFormatter = textFormatter;
	}

	public void format(String text) {
		this.textFormatter.format(text);		
	}
	
	public void setTextFormatter(TextFormatterStrategy textFormatter) {
		this.textFormatter = textFormatter;
	}
}
