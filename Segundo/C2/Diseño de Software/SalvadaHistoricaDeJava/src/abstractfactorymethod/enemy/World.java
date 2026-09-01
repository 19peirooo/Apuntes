package abstractfactorymethod.enemy;

public enum World {
	World1(1),World2(2);
	
	private Integer complexFactor;
	
	private World(int complexFactor) {
		this.complexFactor = complexFactor;
	}
	
	public Integer getComplexFactor() {
		return this.complexFactor;
	}
}
