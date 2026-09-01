package EntregaStatePattern;

import EntregaObserverPattern.Libro;
import EntregaObserverPattern.Library;

//Implementa el patron singleton
public class LoansLibrary extends Library {
	
	private static LoansLibrary loansLibrary = new LoansLibrary(); //Asegura que solo se cree una instancia del objeto
	
	//Devuelve la instancia unica
	public static LoansLibrary getInstance() {
		return LoansLibrary.loansLibrary;
	}
	
	//Constructor privado
	private LoansLibrary() {
		super();
	}
	
	//Devuelve un libro y procesa la devolucion
	public void returnBook(Libro book, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.returnBook(book);
		libraryLoanRequestContext.process();
	}
	
	//Procesa una prestamp
	public void processLibraryLoan(LibraryLoanRequestContext libraryLoanRequestContext) {
		libraryLoanRequestContext.process();
	}
	
}
