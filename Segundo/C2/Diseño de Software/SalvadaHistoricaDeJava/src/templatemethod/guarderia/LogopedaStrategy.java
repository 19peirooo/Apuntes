package templatemethod.guarderia;

public class LogopedaStrategy extends AbstractDoctorStrategy {
	
	public LogopedaStrategy() {
		this("Dr. Fong");
	}
	
	public LogopedaStrategy(String name) {
		super(name);
	}
	
	@Override
	public void examineKids() {
		System.out.println("[Logopeda] " + this.name + " examinando a los niños.");
	}

	@Override
	public void sendBills() {
		System.out.println("[Logopeda] " + this.name + " enviando facturas.");
		
	}

	@Override
	public void sendResults() {
		System.out.println("[Logopeda] " + this.name + " enviando resultados.");
		
	}
}
