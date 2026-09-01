package com.utad.poo.tema3.test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Mazo2 {
	
	public static final Integer MAX_CARTAS = 40;
	public static final Integer DEFAULT_POS = 0;
	public static final List<Carta2> DEFAULT_BARAJA= new ArrayList<Carta2>();
	
	private Integer posActual;
	private List<Carta2> baraja;
	
	public Mazo2() {
		this.posActual = Mazo2.DEFAULT_POS;
		this.baraja = new ArrayList<Carta2>();
		this.crearPalo(Palo2.OROS,this.posActual);
		this.crearPalo(Palo2.COPAS,this.baraja.size());
		this.crearPalo(Palo2.ESPADAS,this.baraja.size());
		this.crearPalo(Palo2.BASTOS,this.baraja.size());
	}
	
	public Integer getPosActual() {
		return this.posActual;
	}


	public void setPosActual(Integer posActual) {
		this.posActual = posActual;
	}


	public List<Carta2> getBaraja() {
		return this.baraja;
	}

	public void setBaraja(List<Carta2> baraja) {
		this.baraja = baraja;
	}
	

	@Override
	public String toString() {
		return "Mazo [baraja=" + baraja + "]";
	}

	private void crearPalo(Palo2 palo, Integer posicionEnMazo) {
		int i = 1;
		
		while (i <= 12) {
			Carta2 carta = new Carta2(i,palo,posicionEnMazo);
			this.baraja.add(carta);
			i++;
			posicionEnMazo++;
			if (i == 8) {
				i += 2;
			}
		}
	}
	
	private Integer asignaPosicion() {
		Integer posicion = 0;
		do {
			posicion = (int)(Math.random() * Mazo2.MAX_CARTAS);
		}while (this.posicionOcupada(posicion));
		return posicion;
	}
	
	public void barajar() {
		
		for (int i = 0; i < this.baraja.size(); i++) {
			this.baraja.get(i).setPosicionMazo(Carta2.DEFAULT_POS-1);
		}
		
		
		for (int i = 0; i < this.baraja.size(); i++) {
			this.baraja.get(i).setPosicionMazo(this.asignaPosicion());
		}
		
		Collections.sort(this.baraja);
		this.posActual = Mazo2.DEFAULT_POS;
	}
	
	private boolean posicionOcupada(Integer posicion) {
		boolean res = false;
		for (int i = 0; i < this.baraja.size(); i++) {
			if (this.baraja.get(i).getPosicionMazo().equals(posicion)) {
				res = true;
			}
		}
		return res;
	}
	
	public Integer cartasDisponibles() {
		return Mazo2.MAX_CARTAS - this.posActual;
	}
	
	public Carta2 siguienteCarta() {
		Carta2 siguiente = null;
		if (this.posActual >= 0 && this.posActual < baraja.size()) {
			siguiente = this.baraja.get(this.posActual);
		}
		
		return siguiente;
	}

	public List<Carta2> darCartas(Integer numCartas){
		List<Carta2> cartasSolicitadas = new ArrayList<Carta2>();
		for (int i = 0; i < numCartas; i++) {
			cartasSolicitadas.add(this.siguienteCarta());
			this.posActual++;
		}
		
		return cartasSolicitadas;
	}

	public void cartasMonton() {
		for (int i = 0; i < this.posActual; i++) {
			System.out.println(this.baraja.get(i));
		}
	}

	public void mostrarBaraja() {
		if (this.posActual <= this.baraja.size()) {
			for (int i = this.posActual; i < this.baraja.size(); i++) {
				System.out.println(this.baraja.get(i));
			}
		}
		
		
	}
	
	public void testMazo() {
		this.mostrarBaraja();
		System.out.println("Barajamos las cartas");
		this.barajar();
		this.mostrarBaraja();
		System.out.println("Cartas disponibles: " +
		this.cartasDisponibles());
		System.out.println("Damos 5 cartas a un jugador");
		List<Carta2> reparto1 = this.darCartas(5);
		for(int i=0; i<reparto1.size(); i++) {
		System.out.println(reparto1.get(i));
		}
		System.out.println("Cartas disponibles: " +
		this.cartasDisponibles());
		System.out.println("Mostramos las cartas no repartidas");
		this.mostrarBaraja();
		System.out.println("Sacamos una carta para un jugador" +
		this.darCartas(1));
		System.out.println("Mostramos las 6 cartas que ya han salido");
		this.cartasMonton();
		this.darCartas(this.cartasDisponibles());
		this.mostrarBaraja();
	}
	public static void main(String[] args) {
		Mazo2 mazo = new Mazo2();
		mazo.testMazo();
	}
}