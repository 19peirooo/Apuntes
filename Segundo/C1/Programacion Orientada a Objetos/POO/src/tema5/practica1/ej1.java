package tema5.practica1;

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class ej1 {
	public static void main(String[] args) {
		Integer numero = (int)(Math.random()*500) + 1;
		Integer numIntentos = 0;
		Integer intento = 0;
		Boolean intentoValido = false;
		Scanner input = new Scanner(System.in);
		
		while (!intentoValido && intento != numero) {
			try {
				System.out.println("Intento: " + (numIntentos+1));
				System.out.println("Introduce un numero del 1 al 500: ");
				intento = input.nextInt();
				numIntentos++;
				if (intento >= 1 && intento <= 500) {
					intentoValido = true;
				} else {
					System.out.println("ERROR: Numero ha de estar entre 1 y 500");
				}
			} catch (Exception e) {
				System.out.println("ERROR: Entrada no valida");
				intentoValido = false;
				input.nextLine();
			} finally {
				if (intento > numero) {
					System.out.println("El numero es menor que " + intento);
					intentoValido = false;
				} else if (intento < numero){
					System.out.println("El numero es mayor que " + intento);
					intentoValido = false;
				} else {
					System.out.println("Has acertado en " + numIntentos + " intentos");
				}
			}
		}
		
	}
}
