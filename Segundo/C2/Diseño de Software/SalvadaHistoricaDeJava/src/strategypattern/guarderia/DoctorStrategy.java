package strategypattern.guarderia;

public interface DoctorStrategy extends MedicalStrategy{
	public void examineKids();
	public void sendBills();
	public void sendResults();
}
