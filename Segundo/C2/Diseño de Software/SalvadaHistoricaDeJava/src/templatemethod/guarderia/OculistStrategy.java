package templatemethod.guarderia;

public class OculistStrategy extends AbstractDoctorStrategy{
	
	public OculistStrategy() {
		this("Dr. Wang");
	}
	
	public OculistStrategy(String name) {
		super(name);
	}
	
	@Override
	public void examineKids() {
		System.out.println("[Oculista] " + this.name + " examinando a los niños.");
	}

	@Override
	public void sendBills() {
		System.out.println("[Oculista] " + this.name + " enviando facturas.");
		
	}

	@Override
	public void sendResults() {
		System.out.println("[Oculista] " + this.name + " enviando resultados.");
		
	}

}
