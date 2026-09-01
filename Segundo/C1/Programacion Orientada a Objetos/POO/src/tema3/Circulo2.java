package tema3;

import java.util.Objects;
import java.util.Scanner;

public class Circulo2 {
	//Atributos y constantes
	public static final Double PI = 3.1416;
	public static final Double DEFAULT_RADIO = 0.0;
	private Double radio;

	//Constructores
	//Constructor sin parametros
	public Circulo2() {
		this(Circulo2.DEFAULT_RADIO);
	}
	
	//Constructor principal
	public Circulo2(Double radio) {
		this.radio = radio;
	}
	
	//Getter y Setter
	public Double getRadio() {
		return radio;
	}

	public void setRadio(Double radio) {
		this.radio = radio;
	}
	
	//Metodo toString
	public String toString() {
		return "Circulo [radio=" + radio + "]";
	}
	
	//Calcula el area
	public Double calcularArea() {
		return Circulo2.PI * Math.pow(this.radio, 2); 
	}
	
	//Calcula la Circumferencia
	public Double calcularLongitud() {
		return 2 * Circulo2.PI * this.radio;
	}
	

	//Ve si dos circulos son iguales si su radio es el mismo
	public boolean equals(Object object) {
		boolean iguales = false;
		
		if (object instanceof Circulo2) {
			//Downcasting
			Circulo2 otroCirculo = (Circulo2)object;
			iguales = this.radio.equals(otroCirculo.radio);
		}
		
		return iguales;
	}

	//Main
	public static void main(String[] args) {
		//Instancio 2 circulos
		Circulo2 circulo1 = new Circulo2();
		Circulo2 otroCirculo = new Circulo2(4.5);
		Scanner input = new Scanner(System.in);
		
		//Pido por pantalla el radio del primer circulo
		System.out.print("Introduce el radio: ");
		circulo1.setRadio(input.nextDouble());
		input.close();
		
		//Veo los datos del primer circulo
		System.out.println(circulo1 + " tiene un area de "+ circulo1.calcularArea()+" y una circumferencia de " + circulo1.calcularLongitud());
		
		//Comparo los 2 circulos
		if (circulo1.equals(otroCirculo)) {
			System.out.println("Los circulos son iguales");
		}
		else {
			System.out.println("Los circulos no son iguales");
		}
		
	}
	
	
}
