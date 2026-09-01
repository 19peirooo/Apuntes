package EntregaStatePattern;

//Estado Finalizado
public class LibraryLoanFinishedState implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext; //Contexto
	
	//Constructor
	public LibraryLoanFinishedState(LibraryLoanRequestContext context) {
		this.libraryLoanRequestContext = context;
	}
	
	//Como la peticion esta finalizada no se procesa nada
	@Override
	public void process() {
		
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

	@Override
	public void returnBook() {
		// TODO Auto-generated method stub
		
	}
}


