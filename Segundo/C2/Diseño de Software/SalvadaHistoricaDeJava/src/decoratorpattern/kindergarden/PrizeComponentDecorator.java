package decoratorpattern.kindergarden;

public abstract class PrizeComponentDecorator implements PrizeComponent{
	
	private PrizeComponent prize;
	
	public PrizeComponentDecorator(PrizeComponent prize) {
		this.prize = prize;
	}

	@Override
	public String getDescription() {
		String description = "";
		
		if (this.prize != null) {
			description = this.prize.getDescription();
		}
		
		description += " " + this.getPrize();
		return description;
	}
	
	public abstract String getPrize();
	
}
