package strategypattern.calculadora;

public class RestaCalculadoraStrategy implements CalculadoraStrategy{

	@Override
	public Integer calcular(Integer num1, Integer num2) {
		return num1 - num2;
	}

}
