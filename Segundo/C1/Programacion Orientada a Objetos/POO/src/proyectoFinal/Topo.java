package proyectoFinal;

public class Topo extends Personaje{
	
	public static final String DEFAULT_NAME = "Topo";
	public static final Integer DEFAULT_HEALTH = 40;
	public static final Integer DEFAULT_DMG = 30;
	
	//Tiene un nombre, daño y vida por defecto
	public Topo(Tipo tipo, Habilidad habilidad) {
		super(Thor.DEFAULT_NAME, Thor.DEFAULT_HEALTH, Thor.DEFAULT_DMG, tipo, habilidad);
	}	
	
	//Puede fallar el ataque pero tiene mucho daño
	@Override
	public void atacar(Personaje receptor) {
		if (Utils.generarNumeroAleatorio(2) == 1) {
			super.atacar(receptor);
		}
		
	}
	
	public String toString() {
		return super.toString();
	}
	
}
