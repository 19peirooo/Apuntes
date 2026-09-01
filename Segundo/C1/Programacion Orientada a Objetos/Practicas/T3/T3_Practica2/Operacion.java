package tema3;

public class Operacion {
	/*
	public static final Double DEFAULT_NUM= 0.0;
	private Double num1;
	private Double num2;
	
	public Operacion() {
		this(DEFAULT_NUM, DEFAULT_NUM);
	}
	
	public Operacion(Double num1) {
		this(num1,DEFAULT_NUM)
	}
	
	public Operacion(Double num1, Double num2) {
		this.num1 = num1;
		this.num2 = num2;
	}

	public Double getNum1() {
		return num1;
	}

	public void setNum1(Double num1) {
		this.num1 = num1;
	}

	public Double getNum2() {
		return num2;
	}

	public void setNum2(Double num2) {
		this.num2 = num2;
	}
	*/
	
	//Suma 2 numeros
	public static Double suma(Double num1, Double num2) {
		return num1 + num2;
	}
	
	//Resta 2 numeros
	public static Double resta(Double num1, Double num2) {
		return num1 - num2;
	}
	
	public static void main(String[] args) {
		System.out.println(Operacion.suma(2.2, 4.5));
		System.out.println(Operacion.resta(4.2, 3.5));
	}
}
