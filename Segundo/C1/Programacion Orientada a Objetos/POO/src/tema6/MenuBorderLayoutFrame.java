package tema6;


import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

public class MenuBorderLayoutFrame extends BasicSwingFrame {

	protected JMenuBar	menuBar;
	protected JMenu		menuArchivo;
	protected JMenu		menuAyuda;
	protected JMenuItem menuItemAbrir;
	protected JMenuItem	menuItemGuardarComo;
	protected JMenuItem menuSalir;
	
	protected JMenuItem menuAcercaDe;

	public MenuBorderLayoutFrame(String title, int frameWidth, int frameHeight) {
		super(title, frameWidth, frameHeight);
		this.setLayout(new BorderLayout());
		
		 this.menuBar = new JMenuBar();       
	     this.menuArchivo = new JMenu("Archivo");       
	     this.menuAyuda = new JMenu("Ayuda");       
	     this.menuBar.add(this.menuArchivo);       
	     this.menuBar.add(this.menuAyuda);      
	     this.menuAcercaDe = new JMenuItem("Acerca de...");
	     this.menuAcercaDe.addActionListener( new ActionListener() {
	    	 
	    	 public void actionPerformed(ActionEvent e) {
	    		 JOptionPane.showMessageDialog(null, "Text Viewer MAIS & FIIS");

	    	 }
	    	 
	     });
	     this.menuItemAbrir = new JMenuItem("Abrir");       
	     this.menuItemGuardarComo = new JMenuItem("Guardar como"); 
	     this.menuSalir = new JMenuItem("Salir");
	     this.menuSalir.addActionListener(new ActionListener() {		
			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
	     this.menuArchivo.add(this.menuItemAbrir);       
	     this.menuArchivo.add(this.menuItemGuardarComo);  
	     this.menuArchivo.add(this.menuSalir);
	     this.menuAyuda.add(this.menuAcercaDe);

		
		this.add(BorderLayout.NORTH, this.menuBar);

	}
	
	
	

}