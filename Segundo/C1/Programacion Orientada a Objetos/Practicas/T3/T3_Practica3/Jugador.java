package t3_practica3;

import java.util.ArrayList;
import java.util.List;

public class Jugador implements Comparable<Jugador>{
	
	//Constantes
	public static final String DEFAULT_NAME = "Jugador";
	
	public static final Integer DEFAULT_PUNTOS_TOTAL = 0;
	public static final Integer DEFAULT_TURNO = 0;
	
	//Atributos
	private String nombre;
	private List<Carta> cartas;
	private List<Integer> puntosPorRonda;
	private Integer puntosTotal;
	private Integer turno;
	
	//Constructores
	//Constructor con 0 atributos
	public Jugador() {
		this(Jugador.DEFAULT_NAME);
	}
	
	//Constructor con 1 atributo
	public Jugador(String nombre) {
		this(nombre,new ArrayList<Integer>());
	}
	
	//Constructor con 2 atributos
	public Jugador(List<Integer> puntosPorRonda) {
		this(Jugador.DEFAULT_NAME,puntosPorRonda);
	}
	
	//Constructor con 3 atributos
	public Jugador(String nombre, List<Integer> puntosPorRonda) {
		this(nombre,puntosPorRonda,Jugador.DEFAULT_TURNO);
	}
	
	//Constructor Principal
	public Jugador(String nombre, List<Integer> puntosPorRonda, Integer turno) {
		this.nombre = nombre;
		this.puntosPorRonda = puntosPorRonda;
		this.turno = turno;
		this.puntosTotal = Jugador.DEFAULT_PUNTOS_TOTAL;
		this.cartas = new ArrayList<Carta>();
	}
	
	//Getters y Setters
	public String getNombre() {
		return this.nombre;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	
	public List<Carta> getCartas() {
		return this.cartas;
	}
	
	public void setCartas(List<Carta> cartas) {
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

	//Metodo toString
	public String toString() {
		return "Jugador [nombre=" + nombre + ", cartas=" + cartas + ", puntosPorRonda=" + puntosPorRonda
				+ ", puntosTotal=" + puntosTotal + ", turno=" + turno + "]";
	}
	
	//Compara 2 jugadores por su orden
	public int compareTo(Jugador jugador2) {
		int res = 0;
		
		if (this.turno > jugador2.getTurno()) {
			res = 1;
		} else if (this.turno < jugador2.getTurno()){
			res = -1;
		}
		return res;
	}
	
	//Escoge una carta de las cartas de jugador y la devuelve eliminandola de la lista
	public Carta echarCarta(){
		Integer posCarta = (int)(Math.random() * this.cartas.size());
		Carta cartaElegida = this.cartas.get(posCarta);
		this.cartas.remove(cartaElegida);
		return cartaElegida;
	}
	
	//Añade una carta a las cartas del jugador
	public void meterCarta(Carta cartaNueva) {
		this.cartas.add(cartaNueva);
	}
	
	//Añade la puntuacion de esa ronda 
	public void establecerPuntuacion(Integer puntuacion) {
		this.puntosPorRonda.add(puntuacion);
	}
	
	//Suma las puntuaciones de todas las rondas
	public void calcularPuntosTotal() {
		this.puntosTotal = 0;
		for (int i = 0; i < this.puntosPorRonda.size(); i++) {
			this.puntosTotal += this.puntosPorRonda.get(i);
		}
	}
}
