package statepattern.biblioteca;

public class EstadoCreado implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext;
	
	public EstadoCreado(LibraryLoanRequestContext libraryLoanRequestContext) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
	}
	
	@Override
	public void aceptar() {
		this.libraryLoanRequestContext.setLibraryLoanState(this.libraryLoanRequestContext.getEstadoAdmitido());
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new CreatedNotificationStrategy());
	}

	@Override
	public void rechazar() {
		this.libraryLoanRequestContext.setLibraryLoanState(this.libraryLoanRequestContext.getEstadoRechazado());
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new RejectNotificationStrategy());
	}

	@Override
	public void devolver() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void recoger() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void process() {
		if (this.libraryLoanRequestContext.getUser().getActiveAccount()) {
			this.aceptar();
		} else {
			this.rechazar();
		}
		
	}

	@Override
	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}
	
}

