package proyectoFinal;

import java.util.List;

//Implementa el Intefaz Modifacable para poder evolucionar
public class Personaje implements Modificable{
	
	public static String DEFAULT_NOMBRE = "Mago";
	public static Integer DEFAULT_SALUD = 100;
	public static Integer DEFAULT_DANYO = 10;
	public static Double DEFAULT_RESISTENCIA = 1.0;
	public static Tipo DEFAULT_TIPO = new Tipo();
	public static Habilidad DEFAULT_HABILIDAD = new HabilidadSalud("Curacion",50,0.33);
	
	protected String nombre;
	protected Integer saludMax;
	protected Integer danyoInicial;
	protected Integer salud;
	protected Integer danyo;
	protected Double resistencia;
	protected Tipo tipo;
	protected Habilidad habilidad;
	protected Estados estadoPersonaje;
	protected Boolean puedeRevivir;
	
	public Personaje(String nombre, Integer salud, Integer danyo, Tipo tipo, Habilidad habilidad) {
		this.nombre = nombre;
		this.saludMax = salud;
		this.danyoInicial = danyo;
		this.salud = salud;
		this.danyo = danyo;
		this.resistencia = Personaje.DEFAULT_RESISTENCIA;
		this.tipo = tipo;
		this.habilidad = habilidad;
		this.estadoPersonaje = Estados.NORMAL;
		this.puedeRevivir = false;
	}
	
	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Integer getSalud() {
		return this.salud;
	}

	public void setSalud(Integer salud) {
		this.salud = salud;
	}

	public Integer getDanyo() {
		return this.danyo;
	}

	public void setDanyo(Integer danyo) {
		this.danyo = danyo;
	}

	public Double getResistencia() {
		return this.resistencia;
	}

	public void setResistencia(Double resistencia) {
		this.resistencia = resistencia;
	}

	public Tipo getTipo() {
		return this.tipo;
	}

	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}

	public Habilidad getHabilidad() {
		return this.habilidad;
	}

	public void setHabilidad(Habilidad habilidad) {
		this.habilidad = habilidad;
	}

	public Estados getEstadoPersonaje() {
		return this.estadoPersonaje;
	}

	public void setEstadoPersonaje(Estados estadoPersonaje) {
		this.estadoPersonaje = estadoPersonaje;
	}

	public Boolean getPuedeRevivir() {
		return this.puedeRevivir;
	}

	public void setPuedeRevivir(Boolean puedeRevivir) {
		this.puedeRevivir = puedeRevivir;
	}
	
	//Trazo en comun que tiene todos los ataque para no repetir codigo
	public void atacar(Personaje receptor) {
		Double multiplicador = 1.0;
		//Compruebo si el receptor es debil o fuerte a mi. Si debil inflingo el doble de daño, si fuerte la mitad
		if (receptor.tipo.esDebil(this.tipo)) {
			multiplicador = 2.0;
		} else if (receptor.tipo.esFuerte(this.tipo)){
			multiplicador = 0.5;
		}
		//Formula para calcular la nueva salud
		receptor.salud = (int) ((receptor.salud) - ((1/receptor.resistencia)*this.danyo*multiplicador));
		if (receptor.salud < 0) {
			receptor.salud = 0;
		}
		
		//Restablece el daño por si se ha usado un habilidad de multiplicacion de daño
		this.danyo = this.danyoInicial;
	}
	
	public String toString() {
		return "Personaje [nombre=" + this.nombre+ ", saludMax=" + this.saludMax + ", salud=" + this.salud + ", danyo=" + this.danyo + ", danyoInicial=" + this.danyoInicial + ", resistencia="
				+ this.resistencia + ", tipo=" + this.tipo + ", habilidad=" + this.habilidad + "]";
	}
	
	//Imprime los detalles importantes del personaje
	public String imprimirDetalles() {
		return "Nombre: " + this.nombre 
				+ ", Salud: " + this.salud 
				+ ", Daño: " + this.danyo 
				+ ", Resistencia: " + this.resistencia
				+ ", Tipo: " + this.tipo.getNombre();
	}
	
	//Comprueba si se puede evolucionar al personaje
	@Override
	public Boolean comprobarModificacion(List<Jugador> jugadores, Integer numRondas) {
		Boolean esModificable = true;
		//Solo me puedo modificar si soy el jugador cuyo personaje tiene menos vida y estamos en la ronda 5 o mas
		for (Jugador jugador : jugadores) {
			if (this.salud > jugador.getPersonaje().getSalud()) {
				esModificable = false;
			}
		}
		
		if (numRondas < 5) {
			esModificable = false;
		}
		
		return esModificable;
	}
	
	//Evolucion del personaje
	@Override
	public void modificar(List<Jugador> jugadores, Integer numRondas) {
		//Veo si puedo modificarme
		//Si puedo, mejoro a un tipo etereo. No tiene debilidades y ahora inflinge dañox2. Solo ocurre un 10% de la veces y si fallas pierdes 15 de vida
		Integer numAleatorio = 0;
		if (this.comprobarModificacion(jugadores, numRondas)) {
			if (Utils.generarNumeroAleatorio(10) == 1) {
				this.tipo = new Tipo(Tipos.ETEREO);
				this.danyo = this.danyo * 2;
				this.danyoInicial = this.danyo;
				this.salud += 100;
				this.saludMax += 100;
				System.out.println("Ha ocurrido una evolución");
			} else {
				this.salud -= 15;
				System.out.println("Tu sacrificio ha sido en vano");
				if (this.salud < 0) {
					this.salud = 0;
				}
				
			}
		}
	}
	
}
