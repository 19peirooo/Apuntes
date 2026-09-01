package ejerciciosTema8;

import java.util.Random;

public class Barajador<T> {
	
	public void barajar(T[] array, Random random) {
		for (int i = array.length - 1; i >= 0; i--) {
			Integer j = random.nextInt(i+1);
			T temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	
	public static void main(String[] args) {
		Barajador<Integer> barajador = new Barajador<Integer>();
		Integer[] enteros = {1,2,4,5,6,7,12,34};
		
		Random generador = new Random();
		
		barajador.barajar(enteros, generador);
		
		for (Integer ent : enteros) {
			System.out.print(ent + " ");
		}
		
	}
	
}
