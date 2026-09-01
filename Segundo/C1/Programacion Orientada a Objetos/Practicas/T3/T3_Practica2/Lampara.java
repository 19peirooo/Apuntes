package tema3;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Lampara implements Comparable<Lampara>{
	
	//Atributos --> contador es un atributo estatico
	public static final Integer MAX_LAMPARAS = 5;
	public static final Integer DEFAULT_CONTADOR = 0;
	private static Integer contador;
	private Integer numLamps;
	
	//Constructores --> Todos los constructores incrementan el valor del contador
	//Constructor estatico
	static{
		Lampara.contador = Lampara.DEFAULT_CONTADOR;
	}
	
	
	public Lampara() {
		this(Lampara.contador+1);
	}
	
	//Constructor Principal
	public Lampara(Integer cont) {
		this.numLamps = cont;
		this.contador++;
	}
	
	//Getter y Setter
	
	public Integer getContador() {
		return contador;
	}

	
	public Integer getNumLamps() {
		return numLamps;
	}

	public void setNumLamps(Integer numLamps) {
		this.numLamps = numLamps;
	}
	
	//Metodo toString
	public String toString() {
		return "Lampara [numLamps=" + numLamps + "]";
	}
	
	//Compara lamparas por su numero de lamparas --> 1 si mas lamparas, -1 si menos, 0 si tienen las mismas
	public int compareTo(Lampara lamp) {
		if (this.numLamps > lamp.numLamps) {
			return 1;
		}
		else if (this.numLamps < lamp.numLamps) {
			return -1;
		}
		else {
			return 0;
		}
	}
	
	//Ve si 2 lamparas son iguales
	public boolean equals(Object o) {
		boolean res = false;
		//Comprueba si el objeto es un lampara
		if (o instanceof Lampara) {
			Lampara l = (Lampara)o; //Downcasting
			if(compareTo(l) == 0) {
				res = true;
			}
		}
		return res;
	}
	
	//Main
	public static void main(String[] args) {
		//Lista de Lamparas
		List<Lampara> lamparas = new ArrayList<Lampara>();
		
		//Creo 5 lamparas en orden descendiente y las añado a la lista
		for (int i = Lampara.MAX_LAMPARAS; i > 0; i--) {
			Lampara l = new Lampara(i); 
			System.out.println(l);
			lamparas.add(l);
		}
		
		//Ordeno la lista
		Collections.sort(lamparas);
		
		//Varias comparaciones
		Lampara l4 = new Lampara(4);
		Lampara l8 = new Lampara(8);
		
		if (l4.compareTo(l8) == 1) {
			System.out.println(l4 + " es mayor que " + l8);
		}
		else if (l4.compareTo(l8) == -1) {
			System.out.println(l4 + " es menor que " + l8);
		}
		else {
			System.out.println(l4 + " y " + l8 + " son iguales");
		}
		
		System.out.println(lamparas);
		
		System.out.println("El resultado de comparar el ultimo elemento y el primer de la lista es: " + lamparas.get(4).compareTo(lamparas.get(1)));

	}
}
