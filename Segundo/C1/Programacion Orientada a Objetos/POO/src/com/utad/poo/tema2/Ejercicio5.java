package com.utad.poo.tema2;

public class Ejercicio5 {
	public static final int MAX_ITEMS = 10;
	public static void main(String[] args) {
		int [] items = { 2, 4, 6, 8, 10, 9, 7, 5, 3, 1};
		boolean found = false;
		int find = 10;
		int i;
		
		for (i = 0; i < MAX_ITEMS && !found; i++) {
			found = (items[i] == find);
		}
		System.out.println(i-1);

	}

}
