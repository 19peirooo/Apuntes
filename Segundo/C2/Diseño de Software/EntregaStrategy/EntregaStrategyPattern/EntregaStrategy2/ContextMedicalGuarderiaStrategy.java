package EntregaStrategy2;

//Contexto que contiene la agregacion
public class ContextMedicalGuarderiaStrategy implements MedicalStrategy{
	
	private MedicalStrategy medicalStrategy;
	
	public ContextMedicalGuarderiaStrategy() {
		this(new OculistaMedicalGuarderiaStrategy());
	}
	
	public ContextMedicalGuarderiaStrategy(MedicalStrategy medicalStrategy) {
		this.medicalStrategy = medicalStrategy;
	}
	
	public void setMedicalStrategy(MedicalStrategy medicalStrategy) {
		this.medicalStrategy = medicalStrategy;
	}
	
	//Aplica la estrategia
	public void applyMedicalStrategy() {
		this.medicalStrategy.applyMedicalStrategy();
	}
	
}
