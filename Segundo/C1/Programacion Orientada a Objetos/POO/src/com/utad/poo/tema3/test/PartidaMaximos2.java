package com.utad.poo.tema3.test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PartidaMaximos2 {
	
	private List<Jugador2> jugadores;
	private Mazo2 baraja;
	
	public PartidaMaximos2(List<Jugador2> jugadores) {
		this.jugadores = jugadores;
		this.baraja = new Mazo2();
		this.baraja.barajar();
		
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).setTurno(i);
		}
		
		this.repartirCartas();
	}
	
	private void repartirCartas() {
		Integer cartasPorJugador = this.baraja.getBaraja().size() / this.jugadores.size();
		
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).setCartas(this.baraja.darCartas(cartasPorJugador));
		}
	}
	
	private void jugarRonda() {
		List<Carta2> cartasEchadas = new ArrayList<Carta2>();
		for(int i = 0; i < this.jugadores.size(); i++) {
			cartasEchadas.add(this.jugadores.get(i).echarCartas());
		}
		this.establecerGanadorRonda(cartasEchadas);
	}
	
	public void jugarPartida() {
		Integer numRonda = 0;
		while (this.jugadores.get(0).getCartas().size() > 0) {
			numRonda++;
			System.out.println("Ronda: " + numRonda);
			this.jugarRonda();
			this.calcularMarcador();
			this.cambiarOrdenTurno();
		}
		System.out.println("Partida Terminada: ");
		System.out.println("El ganador es: " + this.buscarGanador().getNombre());
	}
	
	private void calcularMarcador() {
		System.out.println("Resultado: ");
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).calcularPuntuacionPartida();
			System.out.println(this.jugadores.get(i).getNombre() + " --> " + this.jugadores.get(i).getPuntosTotal());
		}
	}
	
	public Jugador2 buscarGanador() {
		Jugador2 ganador = this.jugadores.get(0);
		
		for (int i = 0; i < this.jugadores.size(); i++) {
			if (this.jugadores.get(i).getPuntosTotal() > ganador.getPuntosTotal()) {
				ganador = this.jugadores.get(i);
			}
		}
		
		return ganador;
	}
	
	private void establecerGanadorRonda(List<Carta2> cartasEchadas) {
		Integer posCartaGanadora = Carta2.cartaMasAlta(cartasEchadas);
		
		System.out.println("La carta ganadora es: " + cartasEchadas.get(posCartaGanadora));
		
		for (int i = 0; i < this.jugadores.size(); i++) {
			if (i == posCartaGanadora) {
				this.jugadores.get(i).establecerPuntuacion(1);
				System.out.println("El ganador es : " + this.jugadores.get(i).getNombre());
			} else {
				this.jugadores.get(i).establecerPuntuacion(0);
			}
		}
	}
	
	private void cambiarOrdenTurno() {
		for (int i = 0; i < this.jugadores.size(); i++) {
			this.jugadores.get(i).setTurno((i-1));
			if (i-1 < 0) {
				this.jugadores.get(i).setTurno((this.jugadores.size()-1));
			}
		}
		Collections.sort(this.jugadores);
	}
	
	
	
	public static void main(String[] args) {
		Jugador2 jugador1 = new Jugador2("Laura");
		Jugador2 jugador2 = new Jugador2("Sergio");
		Jugador2 jugador3 = new Jugador2("Adrián");
		Jugador2 jugador4 = new Jugador2("Saray");
		
		List<Jugador2> jugadores = new ArrayList<Jugador2>();
		jugadores.add(jugador1);
		jugadores.add(jugador2);
		jugadores.add(jugador3);
		jugadores.add(jugador4);
		
		PartidaMaximos2 partida = new PartidaMaximos2(jugadores);
		partida.jugarPartida();
	}
}