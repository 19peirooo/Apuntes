package ejerciciosTema4;

public class Producto {
	
	public static final Integer DEFAULT_CONTADOR = 0;
	
	private static Integer contador;
	protected Integer idProducto;
	protected String nombre;
	protected Double precio;
	
	static {
		Producto.contador = Producto.DEFAULT_CONTADOR;
	}
	
	public Producto(String nombre, Double precio) {
		this.idProducto = this.contador++;
		this.nombre = nombre;
		this.precio = precio;
	}
	
	public Integer getIdProducto() {
		return idProducto;
	}

	public void setIdProducto(Integer idProducto) {
		this.idProducto = idProducto;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Double getPrecio() {
		return precio;
	}

	public void setPrecio(Double precio) {
		this.precio = precio;
	}

	@Override
	public String toString() {
		return "Producto [idProducto=" + idProducto + ", nombre=" + nombre + ", precio=" + precio + "]";
	}
	
	public boolean equals(Object producto) {
		boolean iguales = false;
		
		if (producto instanceof Producto) {
			Producto otroProducto = (Producto) producto;
			iguales = this.idProducto.equals(otroProducto.idProducto);
		}
		
		return iguales;
	}
}
