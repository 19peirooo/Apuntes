package ejerciciosTema7;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Escritura {
	public static void main(String[] args) {
		
		String fileName = "\\files\\Fich.txt";
		File currentDir = new File(System.getProperty("user.dir"));
		Integer numLineasEscritas = 0;
		Scanner inputConsola = new Scanner(System.in);
		
		try {
			File fichero = new File(currentDir.getCanonicalPath()+fileName);
			FileWriter fw = new FileWriter(fichero);
			BufferedWriter bw = new BufferedWriter(fw);
			
			while (numLineasEscritas < 5) {
				System.out.println("Introduce una linea: ");
				bw.write(inputConsola.nextLine());
				bw.newLine();
				numLineasEscritas++;
			}
			bw.flush();
			fw.close();
		} catch (IOException e) {
			System.out.println("ERROR: Fichero no se pudo escribir");
		} finally {
			inputConsola.close();
		}
	}
}
