package proyectoFinal;

public class Golem extends Personaje{
	
	public static final String DEFAULT_NAME = "Golem";
	public static final Integer DEFAULT_HEALTH = 200;
	public static final Integer DEFAULT_DMG = 10;
	
	//Tiene un nombre, daño y vida por defecto
	public Golem(Tipo tipo, Habilidad habilidad) {
		super(Golem.DEFAULT_NAME, Golem.DEFAULT_HEALTH, Golem.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Baja la resistencia del enemigo con cada ataque
	@Override
	public void atacar(Personaje receptor) {
		super.atacar(receptor);
		receptor.resistencia -= 0.05;
		if (receptor.resistencia <= 0) {
			receptor.resistencia = 0.000001;
		}
	}
	
	public String toString() {
		return super.toString();
	}
}
