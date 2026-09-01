package EntregaStatePattern;

//Define las transiciones entre distintos estados
public interface LibraryLoanStateTransition {
	public void acceptRequest();
	public void rejectRequest();
	public void pickUpBook();
	public void returnBook();
}
