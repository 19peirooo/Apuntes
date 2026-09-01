package EntregaDecoratorPattern;

//Componente Base
public class StickerComponent implements RewardComponent{
	
	//Atributo --> Descripcion del premio
	private String description;
	
	//Constructor
	public StickerComponent(String description) {
		this.description = description;
	}
	
	//Devuelve la descripcion del premio
	@Override
	public String getDescription() {
		return this.description;
	}

}
