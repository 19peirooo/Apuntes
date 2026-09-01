package decoratorpattern.kindergarden;

public class StickerPrizeBaseComponent implements PrizeComponent{
	
	private String description;
	
	public StickerPrizeBaseComponent() {
		this("");
	}
	
	public StickerPrizeBaseComponent(String description) {
		this.description = description;
	}

	@Override
	public String getDescription() {
		return this.description;
	}
	
}
