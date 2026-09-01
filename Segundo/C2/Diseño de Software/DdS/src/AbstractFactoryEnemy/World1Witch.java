package AbstractFactoryEnemy;

public class World1Witch implements Witch{
	
	private String name;
	private Integer power;
	private Integer lives;
	private String magicPower;
	
	public World1Witch(String name) {
		this(name,"Varita Magica");
	}
	
	public World1Witch(String name, String magicPower) {
		this.name = name;
		this.power = 5 * World.LEVEL1.getComplexFactor();
		this.lives = 2 * World.LEVEL1.getComplexFactor();
		this.magicPower = magicPower;
	}

	@Override
	public String getName() {
		return this.name;
	}

	@Override
	public Integer getPower() {
		return this.power;
	}

	@Override
	public Integer getLives() {
		return this.lives;
	}

	@Override
	public String getMagicPower() {
		return this.magicPower;
	}

	@Override
	public String toString() {
		return "World1Witch [name=" + this.name + ", power=" + this.power + ", lives=" + this.lives + ", magicPower=" + this.magicPower
				+ "]";
	}
	
	
}
