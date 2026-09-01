package t3_practica3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Mazo {
	
	//Constantes
	public static final Integer MAX_CARTAS = 40;
	public static final Integer DEFAULT_POS = 1;
	public static final List<Carta> DEFAULT_MAZO= new ArrayList<Carta>();
	
	//Atributos
	private Integer posActual;
	private List<Carta> mazo;
	
	//Constructor Principal
	public Mazo() {
		//Establecer la posicion a 1 y creacion de la lista de cartas
		this.posActual = Mazo.DEFAULT_POS;
		this.mazo = new ArrayList<Carta>();
		//Se añaden todas las cartas de cada palo
		this.crearPalo(Palo.OROS,this.posActual);
		this.crearPalo(Palo.COPAS,this.mazo.size()+1);
		this.crearPalo(Palo.ESPADAS,this.mazo.size()+1);
		this.crearPalo(Palo.BASTOS,this.mazo.size()+1);
	}
	
	//Getter y Setters
	public Integer getPosActual() {
		return this.posActual;
	}

	public void setPosActual(Integer posActual) {
		this.posActual = posActual;
	}

	public List<Carta> getMazo() {
		return this.mazo;
	}

	public void setMazo(List<Carta> mazo) {
		this.mazo = mazo;
	}
	
	//Metodo toString
	@Override
	public String toString() {
		return "Mazo [mazo=" + mazo + "]";
	}
	
	//Crea todas las cartas de un palo
	private void crearPalo(Palo palo, Integer posicionEnMazo) {
		int i = 1;
		
		while (i <= 12) {
			Carta carta = new Carta(i,palo,posicionEnMazo);
			this.mazo.add(carta);
			i++;
			posicionEnMazo++;
			//Como no hay 8 ni 9. Hay un salto cuando llegue al 8 para que vaya al 10
			if (i == 8) {
				i += 2;
			}
		}
	}
	
	//Asigna una posicion aleatoria a una carta
	private Integer asignaPosicion() {
		Integer posicion = 0;
		int numAleatorio = 0;
		boolean repetido = true;
		
		//Comprueba que no metamos 2 cartas en la misma posicion
		while (repetido) {
			numAleatorio = (int)((Math.random() * Mazo.MAX_CARTAS)+1);
			//Si la posicion no esta ocupada, se establece posicion y se termina el bucle
			if (!(this.posicionOcupada(numAleatorio))) {
				posicion = numAleatorio;
				repetido = false;
			}
		}
		
		return posicion;
	}
	
	//Baraja las cartas dandoles posiciones aleatorias
	public void barajar() {
		
		//Establece todas las posiciones a 0 ya las posiciones van de 1 a 40
		for (int i = 0; i < this.mazo.size(); i++) {
			this.mazo.get(i).setPosicionMazo(Carta.DEFAULT_POS-1);
		}
		
		//Asigna las posiciones aleatorias
		for (int i = 0; i < this.mazo.size(); i++) {
			this.mazo.get(i).setPosicionMazo(this.asignaPosicion());
		}
		
		//Ordena el mazo por sus nuevas posiciones y establece la posicion actual al inicio de mazo
		Collections.sort(this.mazo);
		this.posActual = Mazo.DEFAULT_POS;
	}
	
	//Comprueba si una posicion esta ya ocupada en el mazo
	private boolean posicionOcupada(Integer posicion) {
		boolean res = false;
		//Busco por todas las cartas del mazo si alguna tiene la misma posicion.
		for (int i = 0; i < this.mazo.size(); i++) {
			if (this.mazo.get(i).getPosicionMazo().equals(posicion)) {
				res = true;
			}
		}
		return res;
	}
	
	//Veo cuantas cartas hay disponibles
	public Integer cartasDisponibles() {
		return Mazo.MAX_CARTAS - this.posActual + 1;
	}
	
	//Devuelve la siguente carta
	public Carta siguienteCarta() {
		Carta siguiente = null;
		if (this.posActual >= 0 && this.posActual <= mazo.size()) {
			siguiente = this.mazo.get(this.posActual-1); //-1 porque es 1 a 40
		}
		
		return siguiente;
	}
	
	//Reparte n cartas
	public List<Carta> darCartas(Integer numCartas){
		List<Carta> cartasSolicitadas = new ArrayList<Carta>();
		for (int i = 0; i < numCartas; i++) {
			cartasSolicitadas.add(this.siguienteCarta());
			this.posActual++;
		}
		
		return cartasSolicitadas;
	}
	
	//Imprime las cartas ya repartidas
	public void cartasMonton() {
		for (int i = 0; i < this.posActual-1; i++) {
			System.out.println(this.mazo.get(i));
		}
	}

	//Muestras las cartas por repartir
	public void mostrarBaraja() {
		if (this.posActual <= this.mazo.size()) {
			for (int i = this.posActual-1; i < this.mazo.size(); i++) {
				System.out.println(this.mazo.get(i));
			}
		}
		
		
	}
	
	//Metodo para probar
	public void testMazo() {
		this.mostrarBaraja();
		System.out.println("Barajamos las cartas");
		this.barajar();
		this.mostrarBaraja();
		System.out.println("Cartas disponibles: " +
		this.cartasDisponibles());
		System.out.println("Damos 5 cartas a un jugador");
		List<Carta> reparto1 = this.darCartas(5);
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
	
	//Main
	public static void main(String[] args) {
		Mazo mazo = new Mazo();
		mazo.testMazo();
	}
}
