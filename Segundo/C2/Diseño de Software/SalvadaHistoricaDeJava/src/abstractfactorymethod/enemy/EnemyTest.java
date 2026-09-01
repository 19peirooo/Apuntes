package abstractfactorymethod.enemy;

public class EnemyTest {
	public static void main(String[] args) {
		GameController game = GameController.getInstance();
		game.play();
	}
}
