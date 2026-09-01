package strategypattern.textformatter;

public class EditorStrategyPatternTest {
	public static void main(String[] args) {
		TextEditorContext textEditor = new TextEditorContext();
		String cadena = "Hello World";
		textEditor.format(cadena);
		textEditor.setTextFormatter(new CamelTextFormatter());
		textEditor.format(cadena);
		textEditor.setTextFormatter(new CapTextFormatter());
		textEditor.format(cadena);
		textEditor.setTextFormatter(new LowerTextFormatter());
		textEditor.format(cadena);
	}
}
