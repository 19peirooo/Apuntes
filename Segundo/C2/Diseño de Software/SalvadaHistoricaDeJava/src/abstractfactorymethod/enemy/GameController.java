package abstractfactorymethod.enemy;

public class GameController implements AbstractEnemyFactory{
	
	private static GameController gameController = new GameController(new W1Factory());
	private AbstractEnemyFactory enemyFactory;
	
	public static GameController getInstance() {
		return gameController;
	}
	
	private GameController(AbstractEnemyFactory enemyFactory) {
		this.enemyFactory = enemyFactory;
	}

	public AbstractEnemyFactory getEnemyFactory() {
		return this.enemyFactory;
	}

	public void setEnemyFactory(AbstractEnemyFactory enemyFactory) {
		this.enemyFactory = enemyFactory;
	}

	@Override
	public Enemy createDaemon() {
		return this.enemyFactory.createDaemon(); //Delegacion por agregacion
	}

	@Override
	public Enemy createWitch() {
		return this.enemyFactory.createWitch(); //Delegacion por agregacion
	}
	
	public void play() {
		System.out.println("***World 1***");
		this.setEnemyFactory(new W1Factory());
		System.out.println("Aparece un: " + this.createDaemon());
		System.out.println("Aparece un: " + this.createWitch());
		System.out.println("***World 2***");
		this.setEnemyFactory(new W2Factory());
		System.out.println("Aparece un: " + this.createDaemon());
		System.out.println("Aparece un: " + this.createWitch());
	}
	
	
	
}
