package tema4;

public class TarjetaDeVisita {
	
	public static final String DEFAULT_NOMBRE = "Victor";
	public static final String DEFAULT_EMPRESA = "Apple";
	public static final String DEFAULT_PUESTO = "Director de Marketing";
	public static final String DEFAULT_DIRECCION = "Calle Ficus Nº2";
	public static final String DEFAULT_TELEFONO = "674 32 59 57";
	
	private String nombre;
	private String empresa;
	private String puesto;
	private String direccion;
	private String telefono;
	
	
	
	public TarjetaDeVisita(String nombre, String empresa, String puesto, String direccion, String telefono) {
		super();
		this.nombre = nombre;
		this.empresa = empresa;
		this.puesto = puesto;
		this.direccion = direccion;
		this.telefono = telefono;
	}
	
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getEmpresa() {
		return empresa;
	}
	public void setEmpresa(String empresa) {
		this.empresa = empresa;
	}
	public String getPuesto() {
		return puesto;
	}
	public void setPuesto(String puesto) {
		this.puesto = puesto;
	}
	public String getDireccion() {
		return direccion;
	}
	public void setDireccion(String direccion) {
		this.direccion = direccion;
	}
	public String getTelefono() {
		return telefono;
	}
	public void setTelefono(String telefono) {
		this.telefono = telefono;
	}
	
	
}
