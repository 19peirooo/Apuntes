package t3_practica3;

import java.util.List;

public class Carta implements Comparable<Carta>{
	
	//Constantes
	public static Integer DEFAULT_NUMERO = 1;
	public static Palo DEFAULT_PALO = Palo.OROS;
	public static Integer DEFAULT_POS = 1;
	
	//Atributos
	private Integer numero;
	private Palo palo;
	private Integer posicionMazo;
	
	//Constructores
	//Constructor con 0 atributos
	public Carta() {
		this(Carta.DEFAULT_NUMERO);
	}
	
	//Constructor con 1 atributos
	public Carta(Integer numero) {
		this(numero,Carta.DEFAULT_PALO);
	}
	
	//Constructor con 2 atributos
	public Carta (Integer numero, Palo palo) {
		this(numero,palo,Carta.DEFAULT_POS);
	}
	
	//Constructor Principal
	public Carta(Integer numero, Palo palo, Integer posicionMazo) {
		this.numero = numero;
		this.palo = palo;
		this.posicionMazo = posicionMazo;
	}

	//Getters y Setters
	public Integer getNumero() {
		return this.numero;
	}

	public void setNumero(Integer numero) {
		this.numero = numero;
	}

	public Palo getPalo() {
		return this.palo;
	}

	public void setPalo(Palo palo) {
		this.palo = palo;
	}

	public Integer getPosicionMazo() {
		return this.posicionMazo;
	}

	public void setPosicionMazo(Integer posicionMazo) {
		this.posicionMazo = posicionMazo;
	}
	
	//Metodo toString
	public String toString() {
		return "Carta [numero=" + numero + ", palo=" + palo + ", posicionEnMazo=" + posicionMazo + "]";
	}

	//Compara 2 cartas en funcion de su posicion en el mazo. 1 si es mayor la primera, -1 si es menor, 0 si es la misma carta
	public int compareTo(Carta carta) {
		int res = 0;
		
		if (this.posicionMazo > carta.posicionMazo) {
			res = 1;
		} else if (this.posicionMazo < carta.posicionMazo) {
			res = -1;
		}
		return res;
	}
	
	//Dada un lista de cartas, devuelve la posicion de la carta con el numero mas alto
	public static Integer cartaMasAlta (List<Carta> cartas) {
		Integer indiceCartaAlta=0;
		
		//Comprueba que la lista no este vacia
		if (cartas == null || cartas.isEmpty()) {
			indiceCartaAlta = -1;
		} else {
			//Compara carta por carta
			for (int i = 0; i < cartas.size(); i++) {
				if (cartas.get(i).getNumero() > cartas.get(indiceCartaAlta).getNumero()) {
					indiceCartaAlta = i;
				}
			}
		}
		
		return indiceCartaAlta;
	}
}
