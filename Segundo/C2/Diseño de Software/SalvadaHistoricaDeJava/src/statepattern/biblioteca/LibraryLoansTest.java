package statepattern.biblioteca;

import observerpattern.biblioteca.*;

public class LibraryLoansTest {
	public static void main(String[] args) {
		LoansLibrary library = LoansLibrary.getInstance(); // singleton
        Libro bookGood= new Libro("Gang of four Design patterns", "Gang of four",450, BookState.GOOD);
        LibraryUser professor = new LibraryUser("MA","miguel.mesas@u-tad.com", UserType.TEACHER);
        LibraryUser student = new LibraryUser("Inés","ines@live.u-tad.com", UserType.STUDENT);
        LibraryLoanRequestContext professorLoanRequest = new LibraryLoanRequestContext(library, bookGood,professor);
        LibraryLoanRequestContext studentLoanRequest = new LibraryLoanRequestContext(library, bookGood,professor);
        //La biblioteca gestiona las reservas recién creadas
        library.processLibraryLoan(studentLoanRequest);
        library.processLibraryLoan(professorLoanRequest);
        //La biblioteca gestiona la recogida del libro del docente.
        library.processLibraryLoan(professorLoanRequest);
        //La biblioteca gestiona la recogida del libro del alumno.
        library.processLibraryLoan(studentLoanRequest);
        //La biblioteca gestiona la devolución del libro del alumno.
        library.returnBook(studentLoanRequest.getBook(), studentLoanRequest);
        //La biblioteca gestiona la devolución del libro del docente.
        library.returnBook(professorLoanRequest.getBook(), professorLoanRequest);
	}
}