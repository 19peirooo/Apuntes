package com.utad.poo.tema2;

public class Ahorcado {
	public int fallos;
	public static final String[] palabras = {"Paco", "Pilar", "Eva", "Vanessa", "Rafael","Javier", "Samuel", "Laura"};
	public String palabra;
	public char[] palabraVisible;
	public char[] palabraOculta;
	public String letrasIntroducidas;
	
	public void escogerPalabra() {
		int elegida = (int)(Math.random()*Ejercicio12.PALABRAS.length);
		this.palabra = this.palabras[elegida];
		
	}
	
	public void rellenarArrays() {
		for (int i = 0; i < this.palabra.length(); i++) {
			this.palabraVisible[i] = this.palabra.toLowerCase().charAt(i);
			this.palabraOculta[i] = '-';
		}
	}
	
	public void imprimirArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
	}
	
	public void pedirLetra() {
		char letra = '\0';
		boolean letraRepetida = true;
	}
	
	public Ahorcado() {
		this.fallos = 0;
		this.letrasIntroducidas = "";
		this.escogerPalabra();
		this.rellenarArrays();
	}
}
