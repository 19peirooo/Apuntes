package statepattern.biblioteca;

import observerpattern.biblioteca.Library;
import observerpattern.biblioteca.Libro;

public class LoansLibrary extends Library{
	
	private static LoansLibrary loansLibrary = new LoansLibrary();
	
	private LoansLibrary() {
		super();
	}
	
	public static LoansLibrary getInstance() {
		return loansLibrary;
	}
	
	public void processLibraryLoan(LibraryLoanRequestContext libraryLoanRequestContext) {
		libraryLoanRequestContext.process();
	}
	
	public void returnBook(Libro book,LibraryLoanRequestContext libraryLoanRequestContext) {
		super.returnBook(book);
		libraryLoanRequestContext.process();
	}
}
