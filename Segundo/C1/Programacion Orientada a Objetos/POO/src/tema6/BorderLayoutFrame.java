package tema6;


import java.awt.BorderLayout;
import javax.swing.JButton;

public class BorderLayoutFrame extends BasicSwingFrame {
	/*
	 * BorderLayout se basa en la existencia de cuatro regiones de borde
	 * y un Ã¡rea central. 
	 */

	public BorderLayoutFrame(String title, int frameWidth, int frameHeight) {
		super(title, frameWidth, frameHeight);
		this.setLayout(new BorderLayout());
		this.add(BorderLayout.NORTH, new JButton("Estoy en el Norte"));
		this.add(BorderLayout.SOUTH, new JButton("Estoy en el Sur"));
		this.add(BorderLayout.EAST, new JButton("Estoy en el Este"));
		this.add(BorderLayout.WEST, new JButton("Estoy en el Oeste"));
		this.add(BorderLayout.CENTER, new JButton("Estoy en el Centro"));
	}
	
	
	

}