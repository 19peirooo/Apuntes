package proyectoFinal;

public class Dragon extends Personaje{
	
	public static final String DEFAULT_NAME = "Dragon";
	public static final Integer DEFAULT_HEALTH = 100;
	public static final Integer DEFAULT_DMG = 16;
	
	//Tiene un nombre, daño y vida por defecto
	public Dragon(Tipo tipo, Habilidad habilidad) {
		super(Dragon.DEFAULT_NAME, Dragon.DEFAULT_HEALTH, Dragon.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Ataca a 2 enemigos
	public void atacar(Personaje receptor1, Personaje receptor2) {
		super.atacar(receptor1);
		super.atacar(receptor2);
	}

	public String toString() {
		return super.toString();
	}
	
	
	
}
