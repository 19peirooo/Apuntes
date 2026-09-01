package tema4;

import java.util.ArrayList;
import java.util.List;

public class Diputado extends Legislador{
	
	
	
	public Diputado(String provincia, Integer edad, String formacion) {
		super(provincia, edad, formacion);
		
	}

	@Override
	public String getCamaraEnQueTrabaja() {
		return "Congreso De Los Diputados";
	}
	
	public static void main(String[] args) {
		Legislador kevin = new Diputado("California", 33, "MIT");
		Legislador ted = new Senador("Texas", 35, "Columbia University");
		
		List<Legislador> legisladores= new ArrayList<Legislador>();
		legisladores.add(kevin);
		legisladores.add(ted);
		
		for (Legislador L: legisladores) {
			System.out.println(L.getCamaraEnQueTrabaja());
		}
	}
}
