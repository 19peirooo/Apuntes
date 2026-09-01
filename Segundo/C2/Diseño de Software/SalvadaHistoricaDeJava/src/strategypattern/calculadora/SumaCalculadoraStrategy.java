package strategypattern.calculadora;

public class SumaCalculadoraStrategy implements CalculadoraStrategy {

	@Override
	public Integer calcular(Integer num1, Integer num2) {
		return num1 + num2;
	}

}
