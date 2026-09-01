package Sesion2;

public class Car {
	
	private String marca;
	private String modelo;
	private String color;
	private Engine motor;
	
	public Car(String marca, String modelo, String color, Engine motor) {
		this.marca = marca;
		this.modelo = modelo;
		this.color = color;
		this.motor = motor;
	}
	
	//Delegacion por agregacion
	public void encender() {
		this.motor.encender(); 
		System.out.println("Coche arrancado");
	}
	
	public void avanzar() {
		if (this.motor.getEncendido().equals(true)) {
			System.out.println("Avanzando...");
		} else {
			System.out.println("Debes arrancar el coche");
		}
	}
	
	public static void main(String[] args) {
		Engine electricEngine = new Engine("Electric");
		Car coche = new Car("Tesla", "Model3","rojo",electricEngine);
		
		coche.encender();
		coche.avanzar();
	}
	
	
}
