package com.utad.poo.tema2;

public class Ejemplo {

	public static void main(String[] args) {
		String shortMsg = "Short Message";
		String longMsg = "Looooooooooooong Message";
		boolean printShort = true;
		int j = 0;
		int counter; //Da error ya que no esta inicializada
		//System.out.printf("Valor Inicial de Counter: %d\n", counter);
		if (printShort) {
			System.out.println(shortMsg);
		}
		else {
			System.out.println(longMsg);
		}
		
		System.out.println("This message is always printed");
		
		for (int i = 0; i < 10 ; i++) {
			System.out.println("i: "+ i +" Are we there yet?");
		}
		
		while (j < 7) {
			System.out.println("j: " + j +" I'm going to pass this course");
			j++;
		}
	}

}
