package tema6;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
public class ListenerButtonFrame extends BasicSwingFrame {
	private JButton northButton = new JButton("Botón del Norte");
	private JButton southButton = new JButton("Botón del Sur");
	private JLabel label = new JLabel("Entre el Norte y el Sur");
	private ButtonListener buttonListener = new ButtonListener();
	
	//Clase interna
	class ButtonListener implements ActionListener {

		private Integer contador;
		
		public ButtonListener() {
			this(0);
		}
		
		public ButtonListener(Integer contador) {
			this.contador = contador;
		}
		
		public void actionPerformed(ActionEvent e) {
			label.setText( "Se ha pulsado el "+((JButton) e.getSource() ).getText() + " y se ha pulsado " + this.contador++ + " veces");
		}
	}
	
	
	public ListenerButtonFrame(String title, int frameWidth, int frameHeight) {
		super(title, frameWidth, frameHeight);
		this.northButton.addActionListener(this.buttonListener);
		
		//TODO cambiar la instancia Listener de southButton por una clase anónima
		this.southButton.addActionListener(new ActionListener() {
			private int contador = 0;

			public void actionPerformed(ActionEvent e) {
				label.setText( "Se ha pulsado el "+((JButton) e.getSource() ).getText() + " y se ha pulsado " + contador++ + " veces");
			}
		});
		this.add(BorderLayout.NORTH, this.northButton);
		this.add(BorderLayout.SOUTH, this.southButton);
		this.add(this.label);
	}
}
