package EntregaStatePattern;

//Estado Rechazado
public class LibraryLoanRejectedState implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext; //Todo estado tiene que tener acceso al contexto
	
	//Constructor
	public LibraryLoanRejectedState(LibraryLoanRequestContext context) {
		this.libraryLoanRequestContext = context;
	}
	
	//No se procesa nada ya que la peticion ha sido rechazada
	@Override
	public void process() {
		
	}
	
	//Getter del contexto
	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}
	
	//No hay transiciones del estado rechazado
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

	@Override
	public void returnBook() {
		// TODO Auto-generated method stub
		
	}
}


