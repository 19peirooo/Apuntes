package tema6;

import java.awt.FlowLayout;

import javax.swing.JButton;

public class FlowLayoutFrame extends BasicSwingFrame {
	
	public FlowLayoutFrame(String titulo) {
		super(titulo);
		this.setLayout(new FlowLayout(FlowLayout.RIGHT)); 
		JButton button1 = new JButton("Button 1");
		JButton button2 = new JButton("Button 2");
		JButton button3 = new JButton("Button 3");
		JButton button4 = new JButton("Button 4");        
		this.add(button1);
		this.add(button2);
		this.add(button3);
		this.add(button4);
		    
	}
}