package tema4;

public abstract class Legislador {
	
	protected String provinciaQueRepresenta;
	protected Integer edad;
	protected String formacion;
	
	
	public Legislador(String provincia, Integer edad, String formacion) {
		this.provinciaQueRepresenta = provincia;
		this.edad = edad;
		this.formacion = formacion;
	}
	
	public abstract String getCamaraEnQueTrabaja();
}
