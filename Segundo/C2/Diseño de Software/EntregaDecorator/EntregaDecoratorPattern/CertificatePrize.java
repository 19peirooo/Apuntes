package EntregaDecoratorPattern;

//Decorador Concreto para certificado
public class CertificatePrize extends PrizeComponent{
	
	//Constructor
	public CertificatePrize(RewardComponent reward) {
		super(reward);
	}

	//Devuelve la descripcion de premio
	@Override
	public String getPrize() {
		return " con premio de buena conducta pañal";
	}

}
