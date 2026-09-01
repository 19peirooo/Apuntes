package Sesion2;

public class FormaDeJuego {
	
	public void muestraFigura() {
		System.out.println("Mostrando forma");
	}
	
	public static void muestraFigura(FormaDeJuego forma) {
		forma.muestraFigura();
	}
	
	public static void main(String[] args) {
		FormaDeJuego figura = new PiezaDeJuego();
		figura.muestraFigura();
		if (figura instanceof PiezaDeJuego) {
			((PiezaDeJuego)figura).muevePieza(); //Downcastica
		}
		
		PiezaDama dama = new PiezaDama();
		
		muestraFigura(figura);
		muestraFigura(dama);
	}
	
}
