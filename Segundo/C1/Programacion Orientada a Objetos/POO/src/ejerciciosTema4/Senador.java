package ejerciciosTema4;

public class Senador extends Legislador{

	public Senador(String provincia) {
		super(provincia);
	}

	@Override
	public String getCamaraEnLaQueTrabaja() {
		return "Senado";
	}
	
	
}
