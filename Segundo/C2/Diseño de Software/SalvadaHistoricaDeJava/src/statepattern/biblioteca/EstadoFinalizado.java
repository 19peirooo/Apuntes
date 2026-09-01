package statepattern.biblioteca;

public class EstadoFinalizado implements LibraryLoanState {
	
	private LibraryLoanRequestContext libraryLoanRequestContext;
	
	public EstadoFinalizado(LibraryLoanRequestContext libraryLoanRequestContext) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
	}
	
	@Override
	public void process() {
		
	}

	@Override
	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}

}
