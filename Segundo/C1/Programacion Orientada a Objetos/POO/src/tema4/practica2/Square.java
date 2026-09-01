package tema4.practica2;

//Hereda de rectangulo
public class Square extends Rectangle{
	
	//Crea un rectangulo de dimensiones uiguales
	public Square(String tag, Integer lado) {
		super(tag, lado, lado);
	}
	
	//Cambia el metodo getFigureType para cambiar el tipo de figura a cuadrado
	@Override
	public String getFigureType() {
		return "Square";
	}

}
