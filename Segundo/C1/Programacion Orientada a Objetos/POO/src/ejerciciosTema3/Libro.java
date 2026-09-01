package ejerciciosTema3;

public class Libro implements Comparable<Libro>{
	
	public static final String DEFAULT_ISBN = "000000000000X";
	public static final String DEFAULT_TITULO = "Paquito el Chocolatero";
	public static final String DEFAULT_AUTOR = "Victor";
	public static final Integer DEFAULT_NUMPAGINAS = 0;
	
	private String isbn;
	private String titulo;
	private String autor;
	private Integer numPaginas;
	
	public Libro() {
		this(Libro.DEFAULT_ISBN, Libro.DEFAULT_TITULO);
	}
	
	public Libro(String isbn, String titulo) {
		this(isbn,titulo,Libro.DEFAULT_AUTOR);
	}
	
	public Libro(String isbn, String titulo, String autor) {
		this(isbn,titulo,autor,Libro.DEFAULT_NUMPAGINAS);
	}
	
	public Libro (String isbn, String titulo, String autor, Integer numPaginas) {
		this.isbn = isbn;
		this.titulo = titulo;
		this.autor = autor;
		this.numPaginas = numPaginas;
	}

	public String getIsbn() {
		return this.isbn;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	public String getTitulo() {
		return this.titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
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
	
	public String toString() {
		return "El libro " + this.titulo + " con ISBN " + this.isbn + " creado por el autor " + this.autor + " tiene " 
	+ this.numPaginas + " paginas.";
	}

	@Override
	public int compareTo(Libro libro2) {
		return this.numPaginas.compareTo(libro2.numPaginas);
	}
	
	public static void main(String[] args) {
		Libro libro1 = new Libro("9871223X", "Nboys","Jason Mamoa", 45);
		Libro libro2 = new Libro ("4352658J", "BoliviaPranks", "Capi Peru", 10);
		
		Integer comparacion = libro1.compareTo(libro2);
		if (comparacion == 1) {
			System.out.println(libro1 + " tiene mas paginas que " + libro2);
		}
		
	}
}
