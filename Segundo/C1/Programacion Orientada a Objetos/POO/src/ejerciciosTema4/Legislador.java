package ejerciciosTema4;

public abstract class Legislador {
	
	protected String provinciaQueRepresenta;
	
	public Legislador(String provincia) {
		this.provinciaQueRepresenta = provincia;
	}
	
	public String getProvinciaQueRepresenta() {
		return provinciaQueRepresenta;
	}

	public void setProvinciaQueRepresenta(String provinciaQueRepresenta) {
		this.provinciaQueRepresenta = provinciaQueRepresenta;
	}

	@Override
	public String toString() {
		return "Legislador [provinciaQueRepresenta=" + provinciaQueRepresenta + "]";
	}

	public abstract String getCamaraEnLaQueTrabaja();
	
}
