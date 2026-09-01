package ejerciciosTema8;

import java.util.LinkedList;

public class LinkedListGenerica<T> {
	private LinkedList<T> lista;
	
	public LinkedListGenerica() {
		this.lista = new LinkedList<T>();
	}
	
	public Boolean estaVacia() {
		return this.lista.isEmpty();
	}
	
	public T extraer() {
		T elemento = null;
		if (!this.estaVacia()) {
			elemento = this.lista.removeFirst();
		} 
		return elemento;
	}
	
	public void añadir (T elemento) {
		this.lista.addLast(elemento);
	} 
	
	public String toString() {
		return this.lista.toString();
	}
	
	public static void main(String[] args) {
		LinkedListGenerica<Integer> listaEnteros = new LinkedListGenerica<Integer>();
		LinkedListGenerica<String> listaCadenas = new LinkedListGenerica<String>();
		
		listaEnteros.añadir(1);
		listaEnteros.añadir(4);
		listaEnteros.añadir(3);
		
		System.out.println(listaCadenas.estaVacia());
		System.out.println(listaEnteros.estaVacia());
		
		listaCadenas.añadir("Hola");
		listaCadenas.añadir("Cara");
		listaCadenas.añadir("Cola");
		
		System.out.println(listaEnteros);
		System.out.println(listaCadenas);
		
		listaEnteros.extraer();
		System.out.println(listaEnteros);
		System.out.println(listaCadenas);
		
		
	}
}
