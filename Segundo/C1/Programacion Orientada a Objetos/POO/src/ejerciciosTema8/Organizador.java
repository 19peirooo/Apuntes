package ejerciciosTema8;

import java.util.ArrayList;
import java.util.List;

public class Organizador<T> {
	
	public Boolean buscarElemento (List<T> lista, T elementoABuscar) {
		
		Boolean encontrado = false;
		for (T elementoLista : lista) {
			if (elementoLista.equals(elementoABuscar)) {
				encontrado = true;
			}
		}
		return encontrado;
	}
	
	public static void main(String[] args) {
		List<Integer> lista = new ArrayList<Integer>();
		Organizador<Integer> buscadorEnteros = new Organizador();
		
		lista.add(1);
		lista.add(3);
		lista.add(4);
		
		System.out.println(buscadorEnteros.buscarElemento(lista, 6));
	}
	
}
