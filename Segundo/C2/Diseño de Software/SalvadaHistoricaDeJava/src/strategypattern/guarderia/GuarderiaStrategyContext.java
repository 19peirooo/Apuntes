package strategypattern.guarderia;

public class GuarderiaStrategyContext implements MedicalStrategy {
	
	private MedicalStrategy medicalStrategy; //Relacion de Composicion Blanda
	
	public GuarderiaStrategyContext() {
		this(new OculistStrategy());
	}
	
	public GuarderiaStrategyContext (MedicalStrategy medicalStrategy) {
		this.medicalStrategy = medicalStrategy;
	}
	
	
	public MedicalStrategy getMedicalStrategy() {
		return this.medicalStrategy;
	}

	public void setMedicalStrategy(MedicalStrategy medicalStrategy) {
		this.medicalStrategy = medicalStrategy;
	}

	@Override
	public void applyMedicalStrategy() {
		this.medicalStrategy.applyMedicalStrategy(); //Delegacion por agregacion
	}

}
