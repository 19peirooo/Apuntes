package proyectoFinal;

public class Guerrero extends Personaje{
	
	//Tiene un nombre, daño y vida por defecto
	//Tiene vida y daño aleatorios
	public Guerrero(Tipo tipo, Habilidad habilidad) {
		super("Guerrero",Utils.generarNumeroAleatorio(150) + 50,Utils.generarNumeroAleatorio(15) + 5,tipo,habilidad); 
	}
	
	public String toString() {
		return super.toString();
	}
	
}
