package ejerciciosTema4;

public class ProductoComida extends Producto{
	
	private Integer calorias;
	
	public ProductoComida(String nombre, Double precio, Integer calorias) {
		super(nombre, precio);
		this.calorias = calorias;
	}

	public Integer getCalorias() {
		return calorias;
	}

	public void setCalorias(Integer calorias) {
		this.calorias = calorias;
	}

	@Override
	public String toString() {
		return super.toString() + " ProductoComida [calorias=" + calorias + "]";
	}
	
	

}
