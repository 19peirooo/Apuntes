package Sesion2;

public class Engine {
	private String nombre;
	private Boolean encendido;
	
	public Engine(String nombre) {
		this.nombre = nombre;
		this.encendido = false;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Boolean getEncendido() {
		return encendido;
	}

	public void setEncendido(Boolean encendido) {
		this.encendido = encendido;
	}

	@Override
	public String toString() {
		return "Engine [nombre=" + nombre + ", encendido=" + encendido + "]";
	}
	
	public void encender() {
		this.encendido = true;
		System.out.println("Motor Encendido");
	}
	
	public static void main(String[] args) {
		Engine motorElectrico = new Engine("Electrico");
		motorElectrico.encender();
		
	}
}
