package com.utad.poo.tema3.test;

import java.util.ArrayList;
import java.util.List;

public class Jugador2 implements Comparable<Jugador2>{
	
	public static final String DEFAULT_NAME = "Jugador";
	public static final Integer DEFAULT_PUNTOS_TOTAL = 0;
	public static final Integer DEFAULT_TURNO = 0;
	
	private String nombre;
	private List<Carta2> cartas;
	private List<Integer> puntosPorRonda;
	private Integer puntosTotal;
	private Integer turno;
	
	public Jugador2() {
		this(Jugador2.DEFAULT_NAME);
	}
	public Jugador2(String nombre) {
		this(nombre, new ArrayList<Integer>());
	}
	public Jugador2(List<Integer> puntosPorRonda) {
		this(Jugador2.DEFAULT_NAME, puntosPorRonda);
	}
	public Jugador2(String nombre, List<Integer> puntosPorRonda) {
		this(nombre,puntosPorRonda,Jugador2.DEFAULT_TURNO);
	}
	public Jugador2(String nombre, List<Integer> puntosPorRonda, Integer turno) {
		this.nombre = nombre;
		this.puntosPorRonda = puntosPorRonda;
		this.turno = turno;
		this.puntosTotal = Jugador2.DEFAULT_PUNTOS_TOTAL;
		this.cartas = new ArrayList<Carta2>();
	}
	public String getNombre() {
		return this.nombre;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	
	public List<Carta2> getCartas() {
		return this.cartas;
	}
	
	public void setCartas(List<Carta2> cartas) {
		this.cartas = cartas;
	}
	
	public List<Integer> getPuntosPorRonda() {
		return this.puntosPorRonda;
	}
	
	public void setPuntosPorRonda(List<Integer> puntosPorRonda) {
		this.puntosPorRonda = puntosPorRonda;
	}
	
	public Integer getPuntosTotal() {
		return this.puntosTotal;
	}
	
	public void setPuntosTotal(Integer puntosTotal) {
		this.puntosTotal = puntosTotal;
	}
	
	public Integer getTurno() {
		return this.turno;
	}
	
	public void setTurno(Integer turno) {
		this.turno = turno;
	}

	
	public String toString() {
		return "Jugador [nombre=" + nombre + ", cartas=" + cartas + ", puntosPorRonda=" + puntosPorRonda
				+ ", puntosTotal=" + puntosTotal + ", turno=" + turno + "]";
	}
	
	//Compara 2 jugadores por su orden
	public int compareTo(Jugador2 jugador2) {
		int res = 0;
		
		if (this.turno > jugador2.getTurno()) {
			res = 1;
		} else if (this.turno < jugador2.getTurno()){
			res = -1;
		}
		return res;
	}
	
	//Escoge una carta de las cartas de jugador y la devuelve eliminandola de la lista
	public Carta2 echarCartas() {
		int posCarta = (int)(Math.random() * this.cartas.size());
		Carta2 cartaElegida = this.cartas.get(posCarta);
		this.cartas.remove(posCarta);
		return cartaElegida;
	}
	
	public void meterCarta(Carta2 cartaNueva) {
		this.cartas.add(cartaNueva);
	}
	
	public void establecerPuntuacion(Integer puntuacion) {
		this.puntosPorRonda.add(puntuacion);
	}
	
	public void calcularPuntuacionPartida() {
		this.puntosTotal = 0;
		for (int i = 0; i < this.puntosPorRonda.size(); i++) {
			this.puntosTotal += this.puntosPorRonda.get(i);
		}
	}
	
	public static void main(String[] args) {
		Mazo2 m = new Mazo2();
		Jugador2 j = new Jugador2();
		j.setCartas(m.getBaraja());
		System.out.println(j.cartas.size());
		j.echarCartas();
		System.out.println(j.cartas.size());
	}
}
