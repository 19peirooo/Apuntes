package EntregaDecoratorPattern;

//Decorador Abstracto
public abstract class PrizeComponent implements RewardComponent{
	
	//Atributo --> Componente a decorar
	protected RewardComponent reward;
	
	//Constructor
	public PrizeComponent(RewardComponent reward) {
		this.reward = reward;
	}
	
	public abstract String getPrize(); //Metodo abstracto a definir en decoradores concretos
	
	public String getDescription() {
		String descripcion = "";
		
		//Si el niño ya tiene premios, hemos de concatenar las nuevas cadenas a para que se vea que tiene mas de un premio
		if (this.reward != null) {
			descripcion = this.reward.getDescription();
		}
		
		//Añado el nuevo premio
		descripcion += this.getPrize();
		
		return descripcion;
	}
	
}
