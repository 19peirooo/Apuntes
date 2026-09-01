package composicion;

public class ContenedorComposicion {
	
	private Contenido contenido;
	
	public ContenedorComposicion() {
		this.contenido = new Contenido();
	}
	
	public void print() {
		this.contenido.print();
	}
}
