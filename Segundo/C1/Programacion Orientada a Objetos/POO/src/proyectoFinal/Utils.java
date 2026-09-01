package proyectoFinal;

import java.util.InputMismatchException;
import java.util.Scanner;

//Clases con funciones utiles que se utilizan frecuentemente
public class Utils {
	
	//Pide al usuario un numero que tiene que estar dentro de un rango. Comprueba tambien si la entrada es un entero
	public static Integer pedirNumero(int numMin, int numMax) {
		Integer numero = 0;
		Boolean entradaValida = false;
		Scanner entrada = new Scanner(System.in);
		
		while (!entradaValida) {
			try {
				numero = entrada.nextInt();
				if (numero >= numMin && numero <= numMax) {
					entradaValida = true;
				} else {
					System.out.println("ERROR: Numero ha de estar entre " + numMin + " y " + numMax);
				}
			} catch (InputMismatchException e){
				entradaValida = false;
				System.out.println("Entrada no es numerica");
				entrada.nextLine(); //Limpia en buffer de entrada
			}
		}
		return numero;
	}
	
	//Pide una cadena de carateres
	public static String pedirCadena(){
		String cadena = "";
		Boolean entradaValida = false;
		Scanner entrada = new Scanner(System.in);
		
		while (!entradaValida) {
			try {
				cadena = entrada.nextLine();
				entradaValida = true;
			} catch (InputMismatchException e){
				entradaValida = false;
				System.out.println("Entrada no es una cadena");
			}
		}
		
		return cadena;
	}
	
	//Genera un numeroAleatorio del 0 a un numero que decidas
	public static Integer generarNumeroAleatorio(Integer num) {
		return (int)(Math.random()*num);
	}
	
}
