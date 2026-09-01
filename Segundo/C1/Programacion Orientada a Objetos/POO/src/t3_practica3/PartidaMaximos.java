package t3_practica3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PartidaMaximos {
	
	//Atributos
	private List<Jugador> jugadores;
	private Mazo baraja;
	
	//Constructor Principal
	public PartidaMaximos(List<Jugador> jugadores) {
		this.jugadores = jugadores;
		//Crea el mazo y lo baraja
		this.baraja = new Mazo();
		this.baraja.barajar();
		
		//Asigna un orden de turno a cada jugador
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).setTurno(i);
		}
		
		//Reparte las cartas equitativamemnte
		this.repartirCartas();
	}
	
	//Reparte las cartas
	private void repartirCartas() {
		Integer cartasPorJugador = this.baraja.getMazo().size() / this.jugadores.size(); //Calcula cuantas cartas se dan por jugador
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).setCartas(this.baraja.darCartas(cartasPorJugador));
		}
	}
	
	//Simula un ronda
	private void jugarRonda() {
		List<Carta> cartasEchadas = new ArrayList<Carta>();
		for(int i = 0; i < this.jugadores.size(); i++) {
			cartasEchadas.add(this.jugadores.get(i).echarCarta());
		}
		this.establecerGanadorRonda(cartasEchadas);
	}
	
	//Simula todas las rondas
	public void jugarPartida() {
		Integer numRonda = 0;
		//Hasta que el primer jugador se quede sin cartas --> Se sigue jugando
		while (this.jugadores.get(0).getCartas().size() > 0) {
			numRonda++;
			System.out.println("Ronda: " + numRonda);
			this.jugarRonda(); //Se juega la ronda
			this.calcularMarcador(); //Se calcula en marcador
			this.cambiarOrdenTurno(); //Se cambia en orden de los turnos
		}
		//Imprime el ganador
		System.out.println("Partida Terminada: ");
		System.out.println("El ganador es: " + this.buscarGanador().getNombre());
	}
	
	//Calcular Marcador
	private void calcularMarcador() {
		System.out.println("Resultado: ");
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).calcularPuntosTotal();
			System.out.println(this.jugadores.get(i).getNombre() + " --> " + this.jugadores.get(i).getPuntosTotal());
		}
	}
	
	//Se busca el ganador 
	public Jugador buscarGanador() {
		Jugador ganador = this.jugadores.get(0);
		
		for (int i = 0; i < this.jugadores.size(); i++) {
			if (this.jugadores.get(i).getPuntosTotal() > ganador.getPuntosTotal()) {
				ganador = this.jugadores.get(i);
			}
		}
		
		return ganador;
	}
	
	//Ve quien a ganado la ronda y le da un punto
	private void establecerGanadorRonda(List<Carta> cartasEchadas) {
	    Integer posCartaGanadora = Carta.cartaMasAlta(cartasEchadas); //Comprueba la carta mas alta
	    //Imprime el resultado
	    System.out.println("La carta ganadora es: " + cartasEchadas.get(posCartaGanadora));
	    System.out.println("Ganador: " + this.jugadores.get(posCartaGanadora).getNombre());
	    this.jugadores.get(posCartaGanadora).establecerPuntuacion(1);
	}

	//Cambia el orden de los turnos --> el segundo pasa a primero, tercero a segundo, etc..
	private void cambiarOrdenTurno() {
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).setTurno((i-1));
			if (i-1 < 0) {
				this.jugadores.get(i).setTurno((this.jugadores.size()-1));
			}
		}
		//Ordena a los jugadores en funcion de su nuevo turno
		Collections.sort(this.jugadores);
	}
	
	//Main
	public static void main(String[] args) {
		Jugador jugador1 = new Jugador("Laura");
		Jugador jugador2 = new Jugador("Sergio");
		Jugador jugador3 = new Jugador("Adrián");
		Jugador jugador4 = new Jugador("Saray");
		
		List<Jugador> jugadores = new ArrayList<Jugador>();
		jugadores.add(jugador1);
		jugadores.add(jugador2);
		jugadores.add(jugador3);
		jugadores.add(jugador4);
		
		PartidaMaximos partida = new PartidaMaximos(jugadores);
		partida.jugarPartida();
	}
}
