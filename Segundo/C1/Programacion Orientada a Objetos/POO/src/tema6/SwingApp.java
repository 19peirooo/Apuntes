package tema6;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class SwingApp {
	private JFrame jframe;
    public SwingApp(String[] args) {
        // initialization .
    	//this.jframe = new SwingProgram("Hello World", "This is my first gui");
    	//this.jframe = new FlowLayoutFrame("Hello World!, this is my second gui");
    	//this.jframe = new BorderLayoutFrame("Border Layout location",600,550);
    	//this.jframe = new GridLayoutFrame("Grid Layout distribution");
    	//this.jframe = new AnonymousListenerButtonFrame("Button Listener", 400, 400);
    	//this.jframe = new ListenerButtonFrame("Button Listener", 400, 400);
    	//this.jframe = new ListenerTextFieldFrame("Text Field Listener",500,500);
    	//this.jframe = new TextViewerFrame("Text viewer", 400, 400);
    	//this.jframe = new PanelsLayoutFrame2("Varios componentes", 450, 550);
    	this.jframe = new MenuBorderLayoutFrame("Menu", 450,550);
    	
    }

    public void show() {
        	this.jframe.setVisible(true);// Show the gui.
    }

    public static void main(final String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new SwingApp(args).show();
            }
        });
    }
}
