package ejerciciosTema4;

public class ProductoLimpieza extends Producto{
	
	private Integer ph;
	
	public ProductoLimpieza(String nombre, Double precio, Integer ph) {
		super(nombre, precio);
		this.ph = ph;
	}

	public Integer getPh() {
		return ph;
	}

	public void setPh(Integer ph) {
		this.ph = ph;
	}

	@Override
	public String toString() {
		return super.toString() + " ProductoLimpieza [ph=" + ph + "]";
	}
	
	public void verSuperficie() {
		if (this.ph > 7) {
			System.out.println("Para ventanas");
		} else {
			System.out.println("Para el suelo");
		}
	}
	

}
