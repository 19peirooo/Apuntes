package com.utad.poo.tema2;

import java.util.Arrays;
import java.util.Scanner;

public class Ejercicio12 {
	//Constante con las palabras
	public static final String[] PALABRAS = {"Paco", "Pilar", "Eva", "Vanessa", "Rafael","Javier", "Samuel", "Laura"};
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//Indice aleatorio
		int elegida = (int)(Math.random()*Ejercicio12.PALABRAS.length);
		//Coge la palabra correspondiente al indice aleatorio
		String palabra = Ejercicio12.PALABRAS[elegida];
		char letra = '\0';
		char[] letrasIntroducidas = new char[27];
		char[] palabraArray = new char[palabra.length()];
		char[] palabraOculta = new char[palabra.length()];
		int numLetrasIntroducidas = 0;
		int fallos = 0;
		boolean letraIntroducida = true;
		boolean acierto = false;
		boolean juegoTerminado = false;
		
		//Creo los arrays de la palabra y la palabra oculta
		for (int i = 0; i < palabra.length(); i++) {
			palabraArray[i] = palabra.toLowerCase().charAt(i);
			palabraOculta[i] = '-';
		}
		
		//Mientras que el juego siga corriendo
		while (!juegoTerminado) {
			//Reinicio variables necesarias
			letraIntroducida = true;
			acierto = false;
			//Imprimo el estado de la palabra oculta con las letras ya encontradas y el numero de fallos
			for (int i = 0; i < palabraOculta.length; i++) {
				System.out.print(palabraOculta[i] + " ");
			}
			System.out.println("\tFallos: " + fallos);
			//Mientras que la letra introducida no este repetida
			while (letraIntroducida) {
				letraIntroducida = false;
				//Imprime las letras ya introducidas
				System.out.print("Letras Introducidas: ");
				for (int i = 0; i < letrasIntroducidas.length; i++) {
					System.out.print(letrasIntroducidas[i]+ " ");
				}
				//Pide la nueva letra por pantalla
				System.out.print("\nIntroduce la letra: ");
				letra = input.next().toLowerCase().charAt(0);
				
				//Comprueba si la letra ya ha sido escrita
				for (int i = 0; i < letrasIntroducidas.length && !letraIntroducida; i++) {
					if (letrasIntroducidas[i] == letra) {
						System.out.println("ERROR: Letra ya introducida");
						letraIntroducida = true;
					}
				}
				//Sino no ha sido introducida la introduce en el array
				if (!letraIntroducida) {
					letrasIntroducidas[numLetrasIntroducidas++] = letra;
				}
			}
			//Busca la letra introducida en la palabra
			for (int i = 0; i < palabraArray.length; i++) {
				//Si la encuentra, añade la letra en su posicion/posiciones correspondientes
				if (letra == palabraArray[i]) {
					palabraOculta[i] = palabraArray[i];
					acierto = true;
				}
			}
			//Si no la encuentra, añade un fallo
			if (!acierto) {
				System.out.println("Has Fallado!!!");
				fallos++;
			}
			//Si se llega al numero maximo de fallos, se termina el juego
			if (fallos == 6) {
				System.out.println("Has perdido. La palabra era: "+ palabra);
				juegoTerminado = true;
			}
			//Si los 2 arrays son iguales, se acaba el juego
			if (Arrays.equals(palabraArray, palabraOculta)) {
				System.out.println("Has Ganado. La Palabra era: "+ palabra);
				juegoTerminado = true;
			}

		}
		//Cerramos la entrada
		input.close();
	}

}
