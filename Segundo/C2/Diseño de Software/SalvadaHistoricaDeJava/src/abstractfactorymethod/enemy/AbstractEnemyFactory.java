package abstractfactorymethod.enemy;

public interface AbstractEnemyFactory {
	public Enemy createDaemon();
	public Enemy createWitch();
}
