package proyectoFinal;

//Clase Generica abstracta Padre --> Habilidades Capaces de Modificar Atributos del Personaje y Jugador
public abstract class Habilidad<T>{
	
	public static final Double DEFAULT_MULTIPLICADOR = 0.0;
	
	//Atributos
	protected String nombre;
	protected Integer probabilidadUso;
	protected Double multiplicador;
	
	//Constructor de 2 parametros --> Util cuando una habilidad no tiene multiplicador como puede ser el revivir
	public Habilidad (String nombre, Integer probablidadDeUso) {
		this(nombre,probablidadDeUso,Habilidad.DEFAULT_MULTIPLICADOR);
	}
	
	//Constructor Principal
	public Habilidad(String nombre, Integer probabilidadUso, Double multiplicador) {
		this.nombre = nombre;
		this.probabilidadUso = probabilidadUso;
		this.multiplicador = multiplicador;
	}
	
	//Getters y Setters
	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Integer getProbabilidadUso() {
		return this.probabilidadUso;
	}

	public void setProbabilidadUso(Integer probabilidadUso) {
		this.probabilidadUso = probabilidadUso;
	}

	public Double getMultiplicador() {
		return this.multiplicador;
	}

	public void setMultiplicador(Double multiplicador) {
		this.multiplicador = multiplicador;
	}
	
	
	//Metodo toString
	public String toString() {
		return "Habilidad [nombre=" + this.nombre + ", probabilidadUso=" + this.probabilidadUso + ", multiplicador="
				+ this.multiplicador + "]";
	}
	
	//Metodo abstracto --> Todos sus hijos estan obligados a tener este metodo
	public abstract T usarHabilidad(T valor);
	
}
