package tema6;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JLabel;
import javax.swing.JTextField;
public class ListenerTextFieldFrame extends BasicSwingFrame{

	private JTextField northTextField = new JTextField("Escriba aquí el texto del Norte");
	private JTextField southTextField = new JTextField("Escriba aquí el texto del Sur");
	private JLabel labelNorthText = new JLabel("Texto del Norte");
	private JLabel labelSouthText = new JLabel("Texto del Sur");
	
	public ListenerTextFieldFrame(String title, int frameWidth, int frameHeight) {
		super(title, frameWidth, frameHeight);
		this.northTextField.addActionListener( new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				labelNorthText.setText(((JTextField) e.getSource()).getText().toUpperCase() );
			}
		});
		this.southTextField.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				labelSouthText.setText(((JTextField)e.getSource()).getText().toLowerCase() );
			}
		});
		this.add(BorderLayout.NORTH, this.northTextField);
		this.add(BorderLayout.SOUTH, this.southTextField);
		this.add(BorderLayout.WEST,this.labelNorthText);
		this.add(BorderLayout.EAST,this.labelSouthText);
	}
}
