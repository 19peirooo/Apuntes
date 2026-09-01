package tema7;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class WordCountFile {
	public static void main(String[] args) throws Exception {
		
		File currentDir = new File(System.getProperty("user.dir"));
		File ejemplo1File = new File(currentDir.getCanonicalPath() + "\\files\\countries");
		
		BufferedReader br = new BufferedReader(new FileReader(ejemplo1File));
		String lineaDeFichero;
		Integer numeroLineas = 0;
		Integer numeroPalabras = 0;
		
		
		while((lineaDeFichero = br.readLine()) != null) {
			//split --> divide un string en substrings separados por el caracter especificado como parámetros
			String[] palabras = lineaDeFichero.split(",");
			numeroPalabras += palabras.length;
			numeroLineas++;
			
		}
		
		br.close();
		System.out.println("El fichero " + ejemplo1File.getName() + " tiene: ");
		System.out.printf("(%d) líneas, con (%d) palabras", numeroLineas, numeroPalabras);
	}
}
