package proyectoFinal;

import java.util.List;

public class Thor extends Personaje{
	
	public static final String DEFAULT_NAME = "Thor";
	public static final Integer DEFAULT_HEALTH = 110;
	public static final Integer DEFAULT_DMG = 12;
	
	//Tiene un nombre, daño y vida por defecto
	public Thor(Tipo tipo, Habilidad habilidad) {
		super(Thor.DEFAULT_NAME, Thor.DEFAULT_HEALTH, Thor.DEFAULT_DMG, tipo, habilidad);
	}
	
	//Ataca a todos los enemigos, lanza un rayo y por cada enemigo hace uno de daño menos
	public void atacar(List<Jugador> receptores) {
		for (Jugador receptor : receptores) {
			if (!(receptor.personaje instanceof Thor)) {
				Double multiplicador = 1.0;
				if (receptor.personaje.tipo.esDebil(this.tipo)) {
					multiplicador = 2.0;
				} else if (receptor.personaje.tipo.esFuerte(this.tipo)){
					multiplicador = 0.5;
				}
				receptor.personaje.salud = (int) ((receptor.personaje.salud) - ((1/receptor.personaje.resistencia)*this.danyo*multiplicador));
				System.out.println("Haces " + this.danyo + " de daño ha " + receptor.nombre);
				if (receptor.personaje.salud < 0) {
					receptor.personaje.salud = 0;
				}
				if (this.danyo > 1) {
					this.danyo -= 1;
				}
				receptor.comprobarMuerto();
				
			}
		}
	}
	
	public String toString() {
		return super.toString();
	}
}
