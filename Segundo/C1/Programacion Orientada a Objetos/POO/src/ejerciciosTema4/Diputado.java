package ejerciciosTema4;

public class Diputado extends Legislador{

	public Diputado(String provincia) {
		super(provincia);
	}

	@Override
	public String getCamaraEnLaQueTrabaja() {
		return "Congreso";
	}
	
	public static void main(String[] args) {
		
	}
	

}
