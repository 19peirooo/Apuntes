package composicion;

public class ContenedorAgregacion {
	private Contenido contenido;
	
	public ContenedorAgregacion(Contenido contenido) {
		this.contenido = contenido;
	}
	
	public void print() {
		this.contenido.print();
	}
}
