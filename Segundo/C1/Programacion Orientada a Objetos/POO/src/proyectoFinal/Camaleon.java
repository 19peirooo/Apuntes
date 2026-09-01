package proyectoFinal;


public class Camaleon extends Personaje{
	
	public static final String DEFAULT_NAME = "Camaleon";
	public static final Integer DEFAULT_HEALTH = 80;
	public static final Integer DEFAULT_DMG = 14;
	
	//Tiene un nombre, daño y vida por defecto
	public Camaleon(Tipo tipo, Habilidad habilidad) {
		super(Camaleon.DEFAULT_NAME, Camaleon.DEFAULT_HEALTH, Camaleon.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Cuando ataca, cambia su tipo a el de la persona a la que ataca
	@Override
	public void atacar(Personaje receptor) {
		super.atacar(receptor);
		this.tipo = receptor.tipo;
	}
	
	public String toString() {
		return super.toString();
	}
	
}
