package AbstractFactoryEnemy;

public enum World {
	LEVEL1(1),LEVEL2(2);
	
	private Integer complexFactor;
	
	private World(Integer complexFactor) {
		this.complexFactor = complexFactor;
	}
	
	public Integer getComplexFactor() {
		return this.complexFactor;
	}
	
}
