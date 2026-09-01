package AbstractFactoryEnemy;

public class World1AbstractFactory implements EnemyAbstractFactory{

	@Override
	public Daemon createDaemon() {
		return new World1Daemon("W1Deamon");
	}

	@Override
	public Witch createWitch() {
		return new World1Witch("W1Witch");
	}
	
}
