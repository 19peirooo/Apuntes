package tema6;

import javax.swing.JOptionPane;

public class HelloSwing {
	
	public static void main(String[] args) {
		JOptionPane.showMessageDialog(null,"Hello My Broski");
		
		String yourName = JOptionPane.showInputDialog("Tu name: ");
			System.out.println("Hola, " + yourName + " eres my broski");
	}
	
}
