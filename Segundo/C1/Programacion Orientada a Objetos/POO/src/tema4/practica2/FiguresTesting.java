package tema4.practica2;

import java.util.ArrayList;
import java.util.List;

public class FiguresTesting {
	
	//Crea una lista de figuras geometricas y las muestra
	public static void main(String[] args) {
		List<GeometricFigure> figurasGeometricas = new ArrayList<GeometricFigure>();
		
		GeometricFigure rectangulo = new Rectangle("R-4x5",4,5);
		GeometricFigure cuadrado = new Square("C-5",5);
		
		figurasGeometricas.add(rectangulo);
		figurasGeometricas.add(cuadrado);
		
		for (Figure figura: figurasGeometricas) {
			figura.drawTxt();
			figura.printDescription();
			
			if (figura instanceof Square) {
				System.out.println(((Square)figura).getBase());
			}
		}
	}
}
