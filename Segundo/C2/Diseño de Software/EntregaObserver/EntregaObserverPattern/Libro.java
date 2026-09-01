package EntregaObserverPattern;

public class Libro {
	
	//Constantes
	public static final String DEFAULT_NOMBRE = "El Quijote De La Mancha";
	public static final String DEFAULT_AUTOR = "Miguel de Cervantes";
	public static final Integer DEFAULT_NUMPAGINAS = 844;
	public static final BookState DEFAULT_ESTADO = BookState.UNKNOWN;
	
	//Atributos
	private String nombre;
	private String autor;
	private Integer numPaginas;
	private BookState estado;
	
	//Constructor por defecto --> Crea el Quijote
	public Libro() {
		this(Libro.DEFAULT_NOMBRE,Libro.DEFAULT_AUTOR,Libro.DEFAULT_NUMPAGINAS, Libro.DEFAULT_ESTADO);
	}
	
	//Constructor principal
	public Libro (String nombre, String autor, Integer numPaginas, BookState estado) {
		this.nombre = nombre;
		this.autor = autor;
		this.numPaginas = numPaginas;
		this.estado = estado;
	}
	
	//Getters y Setters
	public String getNombre() {
		return this.nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getAutor() {
		return this.autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public Integer getNumPaginas() {
		return this.numPaginas;
	}

	public void setNumPaginas(Integer numPaginas) {
		this.numPaginas = numPaginas;
	}

	public BookState getEstado() {
		return this.estado;
	}

	public void setEstado(BookState estado) {
		this.estado = estado;
	}

	//Metodo toString
	public String toString() {
		return "Libro [nombre=" + this.nombre + ", autor=" + this.autor + ", numPaginas=" 
				+ this.numPaginas + ", estado=" + this.estado + "]";
	}
	
	
}
