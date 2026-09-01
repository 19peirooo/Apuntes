package tema7;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class OpenCountryPopulationCSVFile {
	public static void main(String[] args) throws IOException {
		File currentDir = new File(System.getProperty ("user.dir") );
		File ejemplo1File = new File(currentDir.getCanonicalPath()+"\\files\\countries");
		
		List<Country> paises = new ArrayList<Country>();
		
		BufferedReader br  = new BufferedReader(new FileReader(ejemplo1File));
		String lineaDeFichero;
		Integer numLinea = 0;
		while ((lineaDeFichero = br.readLine()) != null) {
			if (numLinea > 0) {
				String[] campos = lineaDeFichero.split(",");
				Scanner scannerLine = new Scanner(lineaDeFichero);
				scannerLine.useDelimiter(",");
				String countryName = scannerLine.next();
				String countryIsoCode = scannerLine.next();
				String countryContinente = scannerLine.next();
				String countryPoblacionEnMillones = scannerLine.next();
				Integer countryPoblacion = null;
				try {
					countryPoblacion = Integer.parseInt(countryPoblacionEnMillones);
					paises.add(new Country(countryName,countryIsoCode, countryContinente,countryPoblacion));
				} catch(Exception e) {
					paises.add(new Country(countryName,countryIsoCode, countryContinente,countryPoblacionEnMillones));
				}
				
				System.out.print("Nombre: "+countryName);
				System.out.print(" IsoCode: "+countryIsoCode);
				System.out.println(" Continente: "+countryContinente);
				for (int i = 0; i < campos.length; i++) {
					System.out.print(i+"["+campos[i]+"];");
				}
				System.out.println();
			}
			numLinea++;
		}
		br.close();
		Collections.sort(paises);
		
		for (Country pais: paises) {
			System.out.println(pais);
		}
		
		System.out.println(paises.get(0).getNombre());
	}
}
