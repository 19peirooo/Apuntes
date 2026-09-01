package proyectoFinal;

import java.util.List;

//Clase Padre para el jugador --> Se divide en 2 hijos para maquina y humano
public abstract class Jugador implements Comparable<Jugador>{
	
	public static final String DEFAULT_NOMBRE = "Maquina";
	public static final Integer DEFAULT_ORDENENRONDA = -1;
	public static final Integer DEFAULT_POSPARTIDA = -1;
	
	protected String nombre;
	protected Integer ordenEnRonda;
	protected Personaje personaje;
	protected Integer posPartida;
	protected Boolean turnoActivo;
	
	public Jugador(Personaje personaje) {
		this(Jugador.DEFAULT_NOMBRE,personaje);
	}
	
	public Jugador(String nombre,Personaje personaje) {
		this(nombre,Jugador.DEFAULT_ORDENENRONDA,personaje);
	}
	
	public Jugador(String nombre, Integer ordenEnRonda, Personaje personaje) {
		this.nombre = nombre;
		this.ordenEnRonda = ordenEnRonda;
		this.personaje = personaje;
		this.turnoActivo = true;
		this.posPartida = Jugador.DEFAULT_POSPARTIDA;
	}

	
	
	@Override
	public String toString() {
		return "Jugador [nombre=" + this.nombre + ", ordenEnRonda=" + this.ordenEnRonda + ", personaje=" + this.personaje
				+ ", posPartida=" + this.posPartida + ", turnoActivo=" + this.turnoActivo + "]";
	}

	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Integer getOrdenEnRonda() {
		return this.ordenEnRonda;
	}

	public void setOrdenEnRonda(Integer ordenEnRonda) {
		this.ordenEnRonda = ordenEnRonda;
	}

	public Personaje getPersonaje() {
		return this.personaje;
	}

	public void setPersonaje(Personaje personaje) {
		this.personaje = personaje;
	}

	public Integer getPosPartida() {
		return this.posPartida;
	}

	public void setPosPartida(Integer posPartida) {
		this.posPartida = posPartida;
	}

	public Boolean getTurnoActivo() {
		return this.turnoActivo;
	}

	public void setTurnoActivo(Boolean turnoActivo) {
		this.turnoActivo = turnoActivo;
	}
	
	//En funcion del tipo de habilidad, tiene un efecto sobre el jugador
	public void usarHabilidad(Jugador receptor) {
		
		if (this.personaje.habilidad instanceof HabilidadDanyo) {
			if (this.personaje.habilidad.multiplicador >= 1.0) {
				this.personaje.danyo = (Integer) this.personaje.habilidad.usarHabilidad(this.personaje.danyo);
			} else {
				receptor.personaje.danyo = (Integer) this.personaje.habilidad.usarHabilidad(receptor.personaje.danyo);
			}
		} else if (this.personaje.habilidad instanceof HabilidadSalud) {
			Integer curacion = (Integer) this.personaje.habilidad.usarHabilidad(this.personaje.salud);
			if ((this.personaje.salud + curacion) > this.personaje.saludMax) {
				this.personaje.salud = this.personaje.saludMax;
			} else {
				this.personaje.salud += curacion;
			}
		} else if (this.personaje.habilidad instanceof HabilidadResistencia){
			if (this.personaje.habilidad.multiplicador >= 1.0) {
				this.personaje.resistencia = (Double) this.personaje.habilidad.usarHabilidad(this.personaje.resistencia);
			} else {
				receptor.personaje.resistencia = (Double) this.personaje.habilidad.usarHabilidad(receptor.personaje.resistencia);
			}
		} else if (this.personaje.habilidad instanceof HabilidadTurno) {
			receptor.turnoActivo = (Boolean) this.personaje.habilidad.usarHabilidad(this.turnoActivo);
		} else if (this.personaje.habilidad instanceof HabilidadRevive){
			this.personaje.puedeRevivir = true;
		} else {
			System.out.println("ERROR: No tienes ninguna habilidad");
		}
		
		this.personaje.habilidad = null;
	}
	
	
	//Comprueba si el personaje ha muerto o puede revivir
	public void comprobarMuerto() {
		if (this.personaje.salud == 0 && this.personaje.puedeRevivir) {
			this.personaje.puedeRevivir = false;
			Habilidad revive = new HabilidadRevive("Revivir",25);
			this.personaje.salud = (Integer) revive.usarHabilidad(this.personaje.saludMax);
			if (this.personaje.salud != 0) {
				System.out.println(this.getNombre() + " ha revivido");
			}
		}
	
		if (this.personaje.salud == 0) {
			this.turnoActivo = false;
			System.out.println(this.getNombre() +  " ha muerto");
			this.personaje.estadoPersonaje = Estados.MUERTO;
		}
	}
	
	//Metodos abstractos para sus hijos --> Define como va a ser un turno de ese jugador y como escoge al receptor de su ataque
	public abstract void turno(Integer numRonda, List<Jugador> jugadores, List<Habilidad> habilidades, Boolean evolucionUsada); 
	
	public abstract Integer escogerReceptor(List<Jugador> jugadores);
	
	//Compara a los jugadores por su orden en ronda
	public int compareTo(Jugador jugador) {
		return this.ordenEnRonda.compareTo(jugador.ordenEnRonda);
	}
	
	//Ve si 2 jugadores son el mismo
	public boolean equals (Object object) {
		boolean iguales = false;
		
		if (object instanceof Jugador) {
			Jugador otroJugador = (Jugador)object;
			iguales = this.ordenEnRonda.equals(otroJugador.ordenEnRonda);
		}
		return iguales;
	}
	
	//Imprime los relevantes de el jugador. Simplifica el toString
	public String imprimirDetalles() {
		return "Nombre: " + this.nombre + ", Posición: " + this.posPartida + ", Orden en Ronda: "+ this.ordenEnRonda+"\n" 
				+ "Personaje: " + this.personaje.imprimirDetalles();
	}
	
}
