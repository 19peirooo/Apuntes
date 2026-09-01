package tema6;

import java.util.concurrent.TimeUnit;

import javax.swing.JButton;
import javax.swing.JFrame;


public class HelloButton {
	public static void main(String[] args) throws InterruptedException {
		JFrame frame = new JFrame("Hello Swing");
		JButton button = new JButton("I am a button");
		button.setBounds(150, 125, 180, 30);
		frame.setLayout(null);
		frame.add(button);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500, 500);
		frame.setVisible(true);
		TimeUnit.SECONDS.sleep(3);
		button.setText("Hey, click here!!!!");
	}
}