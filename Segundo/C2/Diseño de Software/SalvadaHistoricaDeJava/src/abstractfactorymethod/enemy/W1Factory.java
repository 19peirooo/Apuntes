package abstractfactorymethod.enemy;

public class W1Factory implements AbstractEnemyFactory{

	@Override
	public Enemy createDaemon() {
		return new W1Daemon();
	}

	@Override
	public Enemy createWitch() {
		return new W1Witch();
	}

}
