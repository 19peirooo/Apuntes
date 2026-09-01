package tema7;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Scanner;

public class OpenCsvFile  {
	public static void main(String[] args) throws Exception {
		File currentDir = new File(System.getProperty ("user.dir") );
		File ejemplo1File = new File(currentDir.getCanonicalPath()+"\\files\\countries");
		
		BufferedReader br  = new BufferedReader(new FileReader(ejemplo1File));
		String lineaDeFichero;
		Integer numLineas = 0;
		while ((lineaDeFichero = br.readLine()) != null) {
			if (numLineas != 0) {
				String[] campos = lineaDeFichero.split(",");
				Scanner scannerLine = new Scanner(lineaDeFichero);
				scannerLine.useDelimiter(",");
				String countryName = scannerLine.next();
				String countryIsoCode = scannerLine.next();
				String countryContinente = scannerLine.next();
				System.out.print("Nombre: "+countryName);
				System.out.print(" IsoCode: "+countryIsoCode);
				System.out.println(" Continente: "+countryContinente);
				for (int i = 0; i < campos.length; i++) {
					System.out.print(i+"["+campos[i]+"];");
				}
				System.out.println();
			}
			numLineas++;
		}
		br.close();
	}
}
