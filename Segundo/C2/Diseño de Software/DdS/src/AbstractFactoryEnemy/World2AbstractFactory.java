package AbstractFactoryEnemy;

public class World2AbstractFactory implements EnemyAbstractFactory{
	
	public Daemon createDaemon() {
		return new World2Daemon("W2Daemon");
	}

	public Witch createWitch() {
		return new World2Witch("W2Witch");
	}
}
