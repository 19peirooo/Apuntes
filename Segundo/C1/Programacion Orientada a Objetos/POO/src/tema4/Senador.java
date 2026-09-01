package tema4;

public class Senador extends Legislador{

	public Senador(String provincia, Integer edad, String formacion) {
		super(provincia, edad, formacion);
		// TODO Auto-generated constructor stub
	}

	@Override
	public String getCamaraEnQueTrabaja() {
		return "Senado";
	}

}
