package proyectoFinal;

public class Mago extends Personaje{
	
	public static final String DEFAULT_NAME = "Mago";
	public static final Integer DEFAULT_HEALTH = 120;
	public static final Integer DEFAULT_DMG = 10;
	
	//Tiene un nombre, daño y vida por defecto
	public Mago(Tipo tipo, Habilidad habilidad) {
		super(Mago.DEFAULT_NAME, Mago.DEFAULT_HEALTH, Mago.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Sus ataques queman
	@Override
	public void atacar(Personaje receptor) {
		super.atacar(receptor);
		receptor.estadoPersonaje = Estados.QUEMADO;
	}

	public String toString() {
		return super.toString();
	}
	
}
