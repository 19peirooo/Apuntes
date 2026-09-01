package decoratorpattern.kindergarden;

public class KinderGardenBaby {
	
	private String name;
	private Integer age;
	private PrizeComponent prize;
	
	public KinderGardenBaby(String name, Integer age) {
		this.name = name;
		this.age = age;
		this.prize = new StickerPrizeBaseComponent(name);
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Integer getAge() {
		return this.age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public PrizeComponent getPrize() {
		return this.prize;
	}

	public void setPrize(PrizeComponent prize) {
		this.prize = prize;
	}
	
	public String getDescription() {
		return this.prize.getDescription();
	}
	
	public void showRewards() {
		System.out.println(this.getDescription());
	}
	
}
