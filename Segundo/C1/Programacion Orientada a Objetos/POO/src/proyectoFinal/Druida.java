package proyectoFinal;

public class Druida extends Personaje {
	
	public static final String DEFAULT_NAME = "Druida";
	public static final Integer DEFAULT_HEALTH = 75;
	public static final Integer DEFAULT_DMG = 11;
	
	//Tiene un nombre, daño y vida por defecto
	public Druida(Tipo tipo, Habilidad habilidad) {
		super(Druida.DEFAULT_NAME, Druida.DEFAULT_HEALTH, Druida.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Cuando ataca, se cura 5 de vida
	public void atacar(Personaje receptor) {
		super.atacar(receptor);
		this.salud += 5;
		if (this.salud > this.saludMax) {
			this.salud = this.saludMax;
		}
	}
	
	public String toString() {
		return super.toString();
	}
	
}
