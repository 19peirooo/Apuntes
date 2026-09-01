package tema7;

public class Country implements Comparable<Country>{
	public static final Integer POBLACION_DEFAULT = -1;
	
	private String nombre;
	private String isoCode;
	private String continente;
	private Integer poblacionEnMillones;
	
	public Country(String nombre, String isoCode, String continente) {
		this(nombre,isoCode,continente,Country.POBLACION_DEFAULT);
	}
	
	public Country(String nombre, String isoCode, String continente, String poblacionEnMillones) {
		this(nombre,isoCode,continente,Country.POBLACION_DEFAULT);
	}
	
	public Country(String nombre, String isoCode, String continente, Integer poblacionEnMillones) {
		this.nombre = nombre;
		this.isoCode = isoCode;
		this.continente = continente;
		this.poblacionEnMillones = poblacionEnMillones;
	}
	
	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getIsoCode() {
		return this.isoCode;
	}

	public void setIsoCode(String isoCode) {
		this.isoCode = isoCode;
	}

	public String getContinente() {
		return this.continente;
	}

	public void setContinente(String continente) {
		this.continente = continente;
	}

	public Integer getPoblacionEnMillones() {
		return this.poblacionEnMillones;
	}

	public void setPoblacionEnMillones(Integer poblacionEnMillones) {
		this.poblacionEnMillones = poblacionEnMillones;
	}
	
	@Override
	public String toString() {
		return "Country [nombre=" + nombre + ", isoCode=" + isoCode + ", continente=" + continente
				+ ", poblacionEnMillones=" + poblacionEnMillones + "]";
	}

	public int compareTo(Country o) {
		return this.poblacionEnMillones.compareTo(o.poblacionEnMillones);
	}
	
}
