package tema4.practica2;

//Clase de Figura Geometrica que implementa el interfaz Figure
public abstract class GeometricFigure implements Figure{
	
	//Atributo
	protected String tag;
	
	//Constructor
	public GeometricFigure(String tag) {
		this.tag = tag;
	}
	
	//Getters y Setters
	@Override
	public String getTag() {
		return this.tag;
	}
	
	public void setTag(String tag) {
		this.tag = tag;
	}
	
	//Se pueden eliminar los siguientes 3 metodos ya que no los modifico
	public abstract String getFigureType();

	public abstract Double area();

	public abstract void drawTxt();
	
	//Imprime la informacion de la figura geometrica
	public final void printDescription() {
		System.out.println("Tag: " + this.tag);
		System.out.println("Figure Type:" + this.getFigureType());
		System.out.println("Area: " + this.area());
		
	}
	
}
