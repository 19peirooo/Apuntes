package tema1;

public class ElectricCar {
	private String marca;
	private String modelo;
	private String color;
	private Engine motor;
	
	public ElectricCar(String marca, String modelo, String color) {
		this.marca = marca;
		this.modelo = modelo;
		this.color = color;
		this.motor = new Engine("Electrico");
	}
	
	public void avanzar() {
		System.out.println("El coche esta avanzando");
	}
	
	public void parar() {
		System.out.println("El Coche se ha parado");
	}
	
	public void encender() {
		this.motor.encender();
	}
	
	public static void main(String[] args) {
		ElectricCar cocheElectrico = new ElectricCar("Tesla","Roadster","Negro");
		cocheElectrico.encender();
	}
	
	
}
