package AbstractFactoryEnemy;

public class DaemonGameTest {
	public static void main(String[] args) {
		GameController gameController = GameController.getInstance();
		gameController.play();
	}
}
