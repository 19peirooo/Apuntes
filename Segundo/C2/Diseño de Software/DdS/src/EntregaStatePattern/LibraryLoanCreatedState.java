package EntregaStatePattern;

//Estado De Peticion Creada
public class LibraryLoanCreatedState implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext; //Contexto
	
	//Constructor
	public LibraryLoanCreatedState(LibraryLoanRequestContext context) {
		this.libraryLoanRequestContext = context;
	}
	
	//Si el usuario tiene una cuenta activa acepta la peticion, sino la rechaza
	@Override
	public void process() {
		if (libraryLoanRequestContext.getLibraryUser().getActiveAccount()) {
			this.acceptRequest();
		} else {
			this.rejectRequest();
		}
	}

	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}
	
	//Pasa al estado admitido y lanza una notificacion
	@Override
	public void acceptRequest() {
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new CreatedLibraryPushNotificationStrategy());
		this.libraryLoanRequestContext.setCurrentState(this.libraryLoanRequestContext.getAdmittedState());
	}
	
	//Pasa al estado rechazado y lanza una notificacion
	@Override
	public void rejectRequest() {
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new RejectedLibraryPushNotificationStrategy());
		this.libraryLoanRequestContext.setCurrentState(this.libraryLoanRequestContext.getRejectedState());
	}

	@Override
	public void pickUpBook() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void returnBook() {
		// TODO Auto-generated method stub
		
	}
}

