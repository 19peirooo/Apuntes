package tema6;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;

public class SwingProgram extends BasicSwingFrame {
	private JLabel  label;
	private JButton button;
	
	public JLabel getLabel() {
		return label;
	}

	public JButton getButton() {
		return button;
	}

	public void setButton(JButton button) {
		this.button = button;
	}

	public void setLabel(JLabel label) {
		this.label = label;
	}
	public SwingProgram() {
		this("Hello Swing","I am a label");
	}
	public SwingProgram(String titulo, String etiqueta) {
		super(titulo);
		this.label = new JLabel(etiqueta);
		this.add(this.label);
		
		  this.button = new JButton("Salir"); 
		  this.button.setSize(100, 100);
		  this.button.addActionListener(new ActionListener() {
			  public void actionPerformed(ActionEvent e) { 
			  			System.exit(0);
		  	  } 
		  	}
		  ); 
		  this.add(button);
		 
	}
	
}