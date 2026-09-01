package AbstractFactoryEnemy;

public class World2Witch implements Witch{
	private String name;
	private Integer power;
	private Integer lives;
	private String magicPower;
	
	public World2Witch(String name) {
		this(name,"Varita y Escoba Magica");
	}
	
	public World2Witch(String name, String magicPower) {
		this.name = name;
		this.power = 5 * World.LEVEL2.getComplexFactor();
		this.lives = 2 * World.LEVEL2.getComplexFactor();
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
		return "World2Witch [name=" + this.name + ", power=" + this.power + ", lives=" + this.lives + ", magicPower=" + this.magicPower
				+ "]";
	}
	
	
	
}
