package decoratorpattern.kindergarden;

public class CertificateComponentDecorator extends PrizeComponentDecorator {

	public CertificateComponentDecorator(PrizeComponent prize) {
		super(prize);
	}

	@Override
	public String getPrize() {
		return "con certificado por ir al baño";
	}
	
}
