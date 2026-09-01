package tema6;

import java.awt.GridLayout;

import javax.swing.JButton;

public class GridLayoutFrame extends BasicSwingFrame {
	/*
	 * Este gestor permite construir una tabla de componentes, a medida
	 * que los aÃ±adimos, los componentes se colocan de izquierda a 
	 * derecha y de arriba a abajo dentro de la cuadrÃ­cula o rejilla.
	 * En el constructor se indica el nÃºmero de filas y columnas 
	 */
	
	public GridLayoutFrame(String titulo) {
		super(titulo);
		this.setLayout(new GridLayout(7,3)); //filas x columnas
		for (int i = 0; i < 20; i++) {
			this.add(new JButton("Button "+i));
		}
		    
	}
}
