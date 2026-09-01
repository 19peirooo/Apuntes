package proyectoFinal;

import java.util.List;

public class Maquina extends Jugador{

	public Maquina(String nombre,Personaje personaje) {
		super(nombre,personaje);
	}
	
	public String toString() {
		return "Maquina " + super.toString();
	}
	
	//Define el turno de la maquina. Todas las elecciones son aleatorias
	@Override
	public void turno(Integer numRonda, List<Jugador> jugadores, List<Habilidad> habilidades, Boolean evolucionUsada) {
		//Cogemos 2 receptores ya que el dragon ataca a 2 jugadores
		Jugador receptor = null;
		Jugador receptor2 = null;
		
		Integer opcion = -1;
		Boolean opcionValida = false;
		Boolean receptorValido = false;

		//Comprobamos que la maquina haya elegido bien
		while (!opcionValida) {
			//Vemos si esta la evolucion disponible y si la hay, añadimos la opcion de evolucionar
			if (numRonda > 5 && !evolucionUsada) {
				opcion = Utils.generarNumeroAleatorio(4);
			} else {
				opcion = Utils.generarNumeroAleatorio(3);
			}
			
			//En funcion de la opcion, se hace una cosa
			switch (opcion) {
			//Ataque
			case 0:{
				//Comprueba si esta confundido el personaje
				//Si lo esta hay una probilidad del 50% de que se ataque a si mismo
				if (this.personaje.estadoPersonaje == Estados.CONFUNDIDO) {
					Integer numAleatorio = Utils.generarNumeroAleatorio(2);
					if (numAleatorio == 1) {
						receptor = this;
						System.out.println(this.getNombre() + " esta confundido, te has atacado a ti mismo");
						numAleatorio = Utils.generarNumeroAleatorio(4);
						if (numAleatorio == 1) {
							System.out.println(this.getNombre() + " se te ha quitado la confusion.");
							this.personaje.estadoPersonaje = Estados.NORMAL;
						}
					//Thor ataca a todos los enemigos asi que no hay un receptor
					} else if (!(this.personaje instanceof Thor)){
						receptor = jugadores.get(this.escogerReceptor(jugadores));
					}
				} else if (!(this.personaje instanceof Thor)){
					receptor = jugadores.get(this.escogerReceptor(jugadores));
				}
				
				//Como el Dragon ataca a 2 enemigos --> Se elige a otro receptor
				if (this.personaje instanceof Dragon) {
					Boolean receptor2Valido = false;
					receptor2 = receptor;
					//Solo puede atacar a un jugador 2 veces si solo quedan el y otro jugador
					if (jugadores.size() > 2) {
						while (!receptor2Valido) {
							receptor2 = jugadores.get(this.escogerReceptor(jugadores));
							receptor2Valido = !(receptor2.equals(receptor));
						}
						receptor2 = jugadores.get(this.escogerReceptor(jugadores));
						((Dragon) this.personaje).atacar(receptor.personaje, receptor2.personaje);
						System.out.println(this.getNombre() + " ha atacado a " + receptor.getNombre() + " y a " + receptor2.getNombre());
						receptor.comprobarMuerto();
						receptor2.comprobarMuerto();
					}
				} else if (this.personaje instanceof Thor) {
					((Thor) this.personaje).atacar(jugadores);
				} else {
					this.personaje.atacar(receptor.personaje);
					System.out.println(this.getNombre() + " ha atacado " + receptor.getNombre());
					receptor.comprobarMuerto();
				}
				opcionValida = true;
			}break;
			//Usa la hablidad si posee una
			case 1:{
				if (this.personaje.getHabilidad() != null) {
					System.out.println(this.getNombre() + " ha usado su habilidad " + this.getPersonaje().getHabilidad());
					if (this.personaje.getHabilidad() instanceof HabilidadTurno) {
						receptor = jugadores.get(this.escogerReceptor(jugadores));
					} else if (this.personaje.getHabilidad() instanceof HabilidadDanyo && this.personaje.getHabilidad().getMultiplicador() < 1.0) {
						receptor = jugadores.get(this.escogerReceptor(jugadores));
					} else if (this.personaje.getHabilidad() instanceof HabilidadResistencia && this.personaje.getHabilidad().getMultiplicador() < 1.0) {
						receptor = jugadores.get(this.escogerReceptor(jugadores));
					}
					this.usarHabilidad(receptor);
					opcionValida = true;
				}
			}break;
			//Obtiene una hablidad aleatoria si no tiene ninguna habilidad
			case 2:{
				if (this.personaje.getHabilidad() == null) {
					this.personaje.setHabilidad(habilidades.get(Utils.generarNumeroAleatorio(habilidades.size())));
					opcionValida = true;
					System.out.println(this.getNombre() + " ha cogido un nueva habilidad " + this.getPersonaje().getHabilidad());
				}
				
			}break;
			//Si esta permitida la evolucion evoluciona
			case 3:{
				this.personaje.modificar(jugadores, numRonda);
				opcionValida = true;
				this.comprobarMuerto();
			};
			}
		}
	}
	
	//Escoge un receptor aleatorio
	@Override
	public Integer escogerReceptor(List<Jugador> jugadores) {
		Integer posReceptor = 0;
		Boolean receptorValido = false;
		
		while (!receptorValido) {
			posReceptor = Utils.generarNumeroAleatorio(jugadores.size());
			if (!this.equals(jugadores.get(posReceptor)) && jugadores.get(posReceptor).personaje.estadoPersonaje != Estados.MUERTO) {
				receptorValido = true;
			} 
		}
		
		return posReceptor;
	}
	
}
