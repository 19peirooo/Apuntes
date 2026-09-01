package tema4;

import java.util.ArrayList;
import java.util.List;

public class TestEdificio {
	
	public static void main(String[] args) {
		
		List<Edificio> listaEdificios= new ArrayList<Edificio>();
		
		Edificio oficinas = new EdificioOficinas(3000.0);
		Edificio pistaAtletismo = new Polideportivo(100.0, "Atletismo");
		Polideportivo piscina = new Polideportivo(5000.0, "Piscina");
		
		listaEdificios.add(oficinas);
		listaEdificios.add(pistaAtletismo);
		listaEdificios.add(piscina);
		
		for (Edificio edificio : listaEdificios) {
			System.out.println(edificio.superficieEdificio());
			if (edificio instanceof InstalacionDeportiva) {
				//System.out.println(((InstalacionDeportiva)edificio).principalUsoDeportivo());
				InstalacionDeportiva instalacion = (InstalacionDeportiva)edificio;
				System.out.println(instalacion.principalUsoDeportivo());
			} 
				
		}
	}
	
}
