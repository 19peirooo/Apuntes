package proyectoFinal;

public class Sirena extends Personaje{
	
	public static final String DEFAULT_NAME = "Sirena";
	public static final Integer DEFAULT_HEALTH = 90;
	public static final Integer DEFAULT_DMG = 11;
	
	//Tiene un nombre, daño y vida por defecto
	public Sirena(Tipo tipo, Habilidad habilidad) {
		super(Sirena.DEFAULT_NAME, Sirena.DEFAULT_HEALTH, Sirena.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Confunde a quien ataca
	public void atacar(Personaje receptor) {
		super.atacar(receptor);
		receptor.estadoPersonaje = Estados.CONFUNDIDO;
	}
	
	public String toString() {
		return super.toString();
	}
	
}
