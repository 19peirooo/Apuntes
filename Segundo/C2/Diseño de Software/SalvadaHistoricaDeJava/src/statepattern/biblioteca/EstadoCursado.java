package statepattern.biblioteca;

public class EstadoCursado implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext;
	
	public EstadoCursado(LibraryLoanRequestContext libraryLoanRequestContext) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
	}
	
	@Override
	public void aceptar() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void rechazar() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void devolver() {
		this.libraryLoanRequestContext.setLibraryLoanState(this.libraryLoanRequestContext.getEstadoFinalizado());
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new FinishedNotificationStrategy());
	}

	@Override
	public void recoger() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void process() {
		this.devolver();
	}

	@Override
	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}
	
}
