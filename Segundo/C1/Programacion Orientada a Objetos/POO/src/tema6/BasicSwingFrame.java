package tema6;

import java.awt.HeadlessException;
import javax.swing.JFrame;

public class BasicSwingFrame extends JFrame {
	private final static int FRAME_WIDTH = 300;
	private final static int FRAME_HEIGHT = 200;
	private final static int FRAME_X_ORIGIN = 150;
	private final static int FRAME_Y_ORIGIN = 250;
	
	public BasicSwingFrame(String title) throws HeadlessException {
		this(title,FRAME_WIDTH,FRAME_HEIGHT);
	}
	public BasicSwingFrame(String title, int frameWidth, int frameHeight) {
		this(title,frameWidth,frameHeight, FRAME_X_ORIGIN, FRAME_Y_ORIGIN);
	}
	public BasicSwingFrame(String title, 
			int frameWidth, int frameHeight,
			int originFrameX, int originFrameY ) {
		super(title);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(frameWidth,frameHeight);
		this.setLocation(originFrameX, originFrameY);
	}

	
}
