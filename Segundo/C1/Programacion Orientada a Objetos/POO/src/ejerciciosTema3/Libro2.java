package ejerciciosTema3;

public class Libro2 {
	private String titulo;
	private String autor;
	private Integer anyo;
	
	public Libro2 (String titulo, String autor, Integer anyo) {
		this.titulo = titulo;
		this.autor = autor;
		this.anyo = anyo;
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

	public Integer getAnyo() {
		return this.anyo;
	}

	public void setAnyo(Integer anyo) {
		this.anyo = anyo;
	}
	
	public String toString() {
		return "Libro2 [titulo= " + this.titulo + ", autor= " + this.autor + ", anyo= " + this.anyo + "]";
	}
	
	public static void main(String[] args) {
		Libro2 libro = new Libro2("Pacoventuras","Paco",2005);
		System.out.println(libro);
	}
	
	
}
