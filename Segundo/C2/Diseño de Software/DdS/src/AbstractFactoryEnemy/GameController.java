package AbstractFactoryEnemy;

public class GameController {
	
	private EnemyAbstractFactory enemyAbstractFactory;
	
	private static GameController gameController = new GameController(new World1AbstractFactory());
	
	public static GameController getInstance() {
		return gameController;
	}
	
	private GameController (EnemyAbstractFactory enemyAbstractFactory) {
		this.enemyAbstractFactory = enemyAbstractFactory;
	}

	public EnemyAbstractFactory getEnemyAbstractFactory() {
		return enemyAbstractFactory;
	}

	public void setEnemyAbstractFactory(EnemyAbstractFactory enemyAbstractFactory) {
		this.enemyAbstractFactory = enemyAbstractFactory;
	}
	
	public void play() {
		System.out.println("Mundo 1: ");
		Daemon demonio = this.gameController.enemyAbstractFactory.createDaemon();
		System.out.println("Te ataca un demonio: " + demonio);
		Witch bruja = this.gameController.enemyAbstractFactory.createWitch();
		System.out.println("Te ataca una bruja: " + bruja);
		
		System.out.println("Mundo 2: ");
		this.gameController.setEnemyAbstractFactory(new World2AbstractFactory());
		demonio = this.gameController.enemyAbstractFactory.createDaemon();
		System.out.println("Te ataca un demonio: " + demonio);
		bruja = this.gameController.enemyAbstractFactory.createWitch();
		System.out.println("Te ataca una bruja: " + bruja);
		System.out.println("Fin del Juego");
	}
	
}
