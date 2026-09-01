package EntregaStatePattern;

//Estado de Peticion Procesada
public class LibraryLoanProcessedState implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext; //Contexto
	
	//Constructor
	public LibraryLoanProcessedState(LibraryLoanRequestContext context) {
		this.libraryLoanRequestContext = context;
	}
	
	//Solo se puede devolver el libro
	@Override
	public void process() {
		this.returnBook();
	}

	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}

	@Override
	public void acceptRequest() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void rejectRequest() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void pickUpBook() {
		// TODO Auto-generated method stub
		
	}
	
	//Devuelve el libro --> Pasa al estado finalizado y lanza una notificacion
	@Override
	public void returnBook() {
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new FinishedLibraryPushNotificationStrategy());
		this.libraryLoanRequestContext.setCurrentState(this.libraryLoanRequestContext.getFinishedState());
		
	}
}


