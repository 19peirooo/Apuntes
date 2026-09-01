package strategypattern.calculadora;

public class ContextCalculadoraStrategy {
	
	private CalculadoraStrategy calculadoraStrategy;
	
	public ContextCalculadoraStrategy(CalculadoraStrategy calculadoraStrategy) {
		this.calculadoraStrategy = calculadoraStrategy;
	}

	public CalculadoraStrategy getCalculadoraStrategy() {
		return this.calculadoraStrategy;
	}

	public void setCalculadoraStrategy(CalculadoraStrategy calculadoraStrategy) {
		this.calculadoraStrategy = calculadoraStrategy;
	}
	
	public Integer calcular(Integer num1, Integer num2) {
		return this.calculadoraStrategy.calcular(num1, num2);
	}
	
}
