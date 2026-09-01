package strategypattern.calculadora;

public class CalculadoraTest {
	public static void main(String[] args) {
		ContextCalculadoraStrategy calculadora = new ContextCalculadoraStrategy(null);
		Integer num1 = 6;
		Integer num2 = 3;
		
		calculadora.setCalculadoraStrategy(new SumaCalculadoraStrategy());
		System.out.println("[Suma] El resultado es: " + calculadora.calcular(num1, num2));
		calculadora.setCalculadoraStrategy(new RestaCalculadoraStrategy());
		System.out.println("[Resta] El resultado es: " + calculadora.calcular(num1, num2));
		calculadora.setCalculadoraStrategy(new MultiplicarCalculadoraStrategy());
		System.out.println("[Multiplicar] El resultado es: " + calculadora.calcular(num1, num2));
		calculadora.setCalculadoraStrategy(new DividirCalculadoraStrategy());
		System.out.println("[Dividir] El resultado es: " + calculadora.calcular(num1, num2));
		
	}
}
