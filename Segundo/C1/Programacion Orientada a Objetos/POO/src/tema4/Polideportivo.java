package tema4;

public class Polideportivo implements InstalacionDeportiva, Edificio{
	
	private Double superficie;
	private String usoPrincipal;
	
	public Polideportivo(Double superficie, String usoPrincipal) {
		this.superficie = superficie;
		this.usoPrincipal = usoPrincipal;
	}
	
	@Override
	public Double superficieEdificio() {
		return this.superficie;
	}

	@Override
	public String principalUsoDeportivo() {
		return this.usoPrincipal;
	}

}
