package EntregaStatePattern;

import java.time.LocalDate;
import EntregaObserverPattern.Libro;

//Contexto del patron state
public class LibraryLoanRequestContext {
	private LibraryLoanState currentState; //Estado actual
	
	//Estados internos
	private LibraryLoanCreatedState createdState;
	private LibraryLoanAdmittedState admittedState;
	private LibraryLoanProcessedState processedState;
	private LibraryLoanRejectedState rejectedState;
	private LibraryLoanFinishedState finishedState;
	
	//Atributos
	private LibraryLoanNotification libraryLoanNotification;
	private LibraryUser libraryUser;
	private LoansLibrary loansLibrary;
	private Libro book;
	private LocalDate createdDate;
	private LocalDate pickupDate;
	
	//Constructor
	public LibraryLoanRequestContext(LibraryUser libraryUser,LoansLibrary loansLibrary, Libro book) {
		
		this.createdState = new LibraryLoanCreatedState(this);
		this.admittedState = new LibraryLoanAdmittedState(this);
		this.processedState = new LibraryLoanProcessedState(this);
		this.rejectedState = new LibraryLoanRejectedState(this);
		this.finishedState = new LibraryLoanFinishedState(this);
		this.currentState = this.createdState;
		
		this.libraryLoanNotification = new LibraryLoanNotification(this);
		this.libraryUser = libraryUser;
		this.loansLibrary = loansLibrary;
		this.book = book;
		this.libraryLoanNotification.attach(libraryUser); //Mete al usuario como observador
		this.createdDate = LocalDate.now();
		this.pickupDate = LocalDate.now().plusDays(2);
		
		
	}
	
	//Getters y Setters
	public LibraryLoanState getCurrentState() {
		return this.currentState;
	}

	public void setCurrentState(LibraryLoanState currentState) {
		this.currentState = currentState;
	}

	public LibraryLoanCreatedState getCreatedState() {
		return this.createdState;
	}

	public void setCreatedState(LibraryLoanCreatedState createdState) {
		this.createdState = createdState;
	}

	public LibraryLoanAdmittedState getAdmittedState() {
		return this.admittedState;
	}

	public void setAdmittedState(LibraryLoanAdmittedState admittedState) {
		this.admittedState = admittedState;
	}

	public LibraryLoanProcessedState getProcessedState() {
		return this.processedState;
	}

	public void setProcessedState(LibraryLoanProcessedState processedState) {
		this.processedState = processedState;
	}

	public LibraryLoanRejectedState getRejectedState() {
		return this.rejectedState;
	}

	public void setRejectedState(LibraryLoanRejectedState rejectedState) {
		this.rejectedState = rejectedState;
	}

	public LibraryLoanFinishedState getFinishedState() {
		return this.finishedState;
	}

	public void setFinishedState(LibraryLoanFinishedState finishedState) {
		this.finishedState = finishedState;
	}

	public LibraryLoanNotification getLibraryLoanNotification() {
		return this.libraryLoanNotification;
	}

	public void setLibraryLoanNotification(LibraryLoanNotification libraryLoanNotification) {
		this.libraryLoanNotification = libraryLoanNotification;
	}

	public LibraryUser getLibraryUser() {
		return this.libraryUser;
	}

	public void setLibraryUser(LibraryUser libraryUser) {
		this.libraryUser = libraryUser;
	}

	public LoansLibrary getLoansLibrary() {
		return this.loansLibrary;
	}

	public void setLoansLibrary(LoansLibrary loansLibrary) {
		this.loansLibrary = loansLibrary;
	}

	public Libro getBook() {
		return this.book;
	}

	public void setBook(Libro book) {
		this.book = book;
	}

	public LocalDate getCreatedDate() {
		return this.createdDate;
	}

	public void setCreatedDate(LocalDate createdDate) {
		this.createdDate = createdDate;
	}

	public LocalDate getPickupDate() {
		return this.pickupDate;
	}

	public void setPickupDate(LocalDate pickupDate) {
		this.pickupDate = pickupDate;
	}
	
	//Procesa el estado actual
	public void process() {
		this.currentState.process(); //Delegacion por composicion
	}
	
}
