package Sesion2;

public class HerencyElectricCar extends Car{
	
	public HerencyElectricCar(String marca, String modelo, String color) {
		super(marca,modelo,color, new Engine("Electric"));
	}
	
	public static void main(String[] args) {
		Car coche = new HerencyElectricCar("Tesla", "Model3","rojo");
		coche.encender();
		coche.avanzar();
	}
	
}
