package tema4.practica2;

//Hereda de la clase GeometricFigure
public class Rectangle extends GeometricFigure{
	
	//Parametros
	private Integer base;
	private Integer altura;
	
	//Constructor Principal
	public Rectangle(String tag, Integer base, Integer altura) {
		super(tag); //Constructor del padre
		this.base = base;
		this.altura = altura;
	}
	
	//Getters y setters
	public Integer getBase() {
		return this.base;
	}

	public void setBase(Integer base) {
		this.base = base;
	}

	public Integer getAltura() {
		return this.altura;
	}

	public void setAltura(Integer altura) {
		this.altura = altura;
	}

	public String getFigureType() {
		return "Rectangle";
	}
	
	//Calcula el area
	@Override
	public Double area() {
		return (double)(this.base*this.altura);
	}
	
	//Dibuja el rectangulo con asteriscos
	@Override
	public void drawTxt() {
		for (int i = 0; i < this.altura; i++) {
			for (int j = 0; j < this.base; j++) {
				System.out.print("* ");
			}
			System.out.println();
		}
	}
	
	
	
}
