package abstractfactorymethod.enemy;

public class W2Factory implements AbstractEnemyFactory{

	@Override
	public Enemy createDaemon() {
		return new W2Daemon();
	}

	@Override
	public Enemy createWitch() {
		return new W2Witch();
	}

}
