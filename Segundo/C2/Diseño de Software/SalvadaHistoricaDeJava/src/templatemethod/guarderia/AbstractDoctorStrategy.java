package templatemethod.guarderia;

//Template para las estrategias concretas
public abstract class AbstractDoctorStrategy implements DoctorStrategy{
	
	protected String name;
	
	public AbstractDoctorStrategy(String name) {
		this.name = name;
	}
	
	@Override
	public void applyMedicalStrategy() {
		this.examineKids();
		this.sendResults();
		this.sendBills();
	}

	public abstract void examineKids();
	public abstract void sendBills();
	public abstract void sendResults();

}
