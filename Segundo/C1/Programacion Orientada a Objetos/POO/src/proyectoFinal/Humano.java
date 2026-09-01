package proyectoFinal;

import java.util.List;
import java.util.Scanner;

public class Humano extends Jugador{

	public Humano(String nombre, Personaje personaje) {
		super(nombre, personaje);
	}

	@Override
	public String toString() {
		return "Humano " + super.toString();
	}
	
	//Igual que en maquina solo que los escoge un usuario
	@Override
	public void turno(Integer numRonda, List<Jugador> jugadores, List<Habilidad> habilidades, Boolean evolucionUsada) {
		Jugador receptor = null;

		Jugador receptor2 = null;

		Integer opcion = -1;
		Boolean opcionValida = false;
		Boolean receptorValido = false;

		while (!opcionValida) {
			System.out.println("\tOpciones:");
			System.out.println("0. Atacar");
			System.out.println("1. Usar Habilidad " + this.getPersonaje().getHabilidad());
			System.out.println("2. Nueva Habilidad");
			if (numRonda > 5 && !evolucionUsada) {
				System.out.println("3. Evolucion");
				System.out.print("Opcion: ");
				opcion = Utils.pedirNumero(0, 3);
			} else {
				System.out.print("Opcion: ");
				opcion = Utils.pedirNumero(0, 2);
			}

			switch (opcion) {
			case 0:{
				if (this.personaje.estadoPersonaje == Estados.CONFUNDIDO) {
					Integer numAleatorio = Utils.generarNumeroAleatorio(2);
					if (numAleatorio == 1) {
						receptor = this;
						System.out.println("Estas Confundido, te has atacado a ti mismo");
						numAleatorio = Utils.generarNumeroAleatorio(4);
						if (numAleatorio == 1) {
							System.out.println("Se te ha quitado la confusion.");
							this.personaje.estadoPersonaje = Estados.NORMAL;
						}
					} else if (!(this.personaje instanceof Thor)){;
						receptor = jugadores.get(this.escogerReceptor(jugadores));
					}
				} else if (!(this.personaje instanceof Thor)){
					receptor = jugadores.get(this.escogerReceptor(jugadores));
				}

				if (this.personaje instanceof Dragon) {
					Boolean receptor2Valido = false;
					receptor2 = receptor;
					if (jugadores.size() > 2) {
						while (!receptor2Valido) {
							receptor2 = jugadores.get(this.escogerReceptor(jugadores));
							receptor2Valido = !(receptor2.equals(receptor));
							if (!receptor2Valido) {
								System.out.println("No puedes atacar a la misma persona");
							}
						}
					}
						((Dragon) this.personaje).atacar(receptor.personaje, receptor2.personaje);
						System.out.println(this.getNombre() + " ha atacado a " + receptor.getNombre() + " y a " + receptor2.getNombre());
						receptor.comprobarMuerto();
				} else if (this.personaje instanceof Thor) {
					((Thor) this.personaje).atacar(jugadores);
				} else {
					this.personaje.atacar(receptor.personaje);
					System.out.println(this.getNombre() + " ha atacado " + receptor.getNombre());
					receptor.comprobarMuerto();
				}
				opcionValida = true;
				
			}break;
			case 1:{
				if (this.personaje.getHabilidad() == null) {
					System.out.println("No tiene habilidad equipada");
				} else {
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
			case 2:{
				if (this.personaje.getHabilidad() != null) {
					System.out.println("Ya tienes una habilidad equipada");
				} else {
					this.personaje.setHabilidad(habilidades.get(Utils.generarNumeroAleatorio(habilidades.size())));
					opcionValida = true;
				}
			}break;
			case 3:{
				this.personaje.modificar(jugadores, numRonda);
				opcionValida = true;
				this.comprobarMuerto();
			}break;
			}
		}

	}

	public Integer escogerReceptor(List<Jugador> jugadores) {
		Integer posReceptor = 0;
		Boolean receptorValido = false;

		while (!receptorValido) {
			System.out.println("A quien quieres atacar (Numero): ");
			for (int j = 0; j < jugadores.size(); j++) {
				System.out.println(j +  " --> " + jugadores.get(j).imprimirDetalles());
			}
			posReceptor = Utils.pedirNumero(0,jugadores.size());
			if (!this.equals(jugadores.get(posReceptor)) && jugadores.get(posReceptor).personaje.estadoPersonaje != Estados.MUERTO) {
				receptorValido = true;
			} else if (jugadores.get(posReceptor).personaje.estadoPersonaje == Estados.MUERTO) {
				System.out.println("No puedes atacar a un jugador muerto");
			} else {
				System.out.println("No te puedes atacar a ti mismo!!");
			}
		}

		return posReceptor;

	}



}
