package statepattern.biblioteca;

import java.time.LocalDate;

import observerpattern.biblioteca.Libro;

public class LibraryLoanRequestContext {
	
	private LibraryLoanState libraryLoanState;
	private EstadoCreado estadoCreado;
	private EstadoAdmitido estadoAdmitido;
	private EstadoRechazado estadoRechazado;
	private EstadoCursado estadoCursado;
	private EstadoFinalizado estadoFinalizado;
	
	private LibraryLoanNotification libraryLoanNotification;
	private Libro book;
	private LibraryUser user;
	private LoansLibrary loansLibrary;
	private LocalDate createdDate;
	private LocalDate pickupDate;
	
	public LibraryLoanRequestContext(LoansLibrary loansLibrary, Libro book, LibraryUser libraryUser) {
		this.estadoCreado = new EstadoCreado(this);
		this.estadoAdmitido = new EstadoAdmitido(this);
		this.estadoCursado = new EstadoCursado(this);
		this.estadoRechazado = new EstadoRechazado(this);
		this.estadoFinalizado = new EstadoFinalizado(this);
		this.libraryLoanState = this.estadoCreado;
		
		this.libraryLoanNotification = new LibraryLoanNotification(this);
		this.loansLibrary = loansLibrary;
		this.book = book;
		this.user = libraryUser;
		libraryLoanNotification.attach(libraryUser);
		this.createdDate = LocalDate.now();
		this.pickupDate = LocalDate.now().plusDays(2);
	}

	public LibraryLoanState getLibraryLoanState() {
		return libraryLoanState;
	}

	public void setLibraryLoanState(LibraryLoanState libraryLoanState) {
		this.libraryLoanState = libraryLoanState;
	}
	
	public Libro getBook() {
		return this.book;
	}

	public void setBook(Libro book) {
		this.book = book;
	}

	public LibraryUser getUser() {
		return this.user;
	}

	public void setUser(LibraryUser user) {
		this.user = user;
	}

	public LoansLibrary getLoansLibrary() {
		return this.loansLibrary;
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
	
	public EstadoCreado getEstadoCreado() {
		return this.estadoCreado;
	}

	public EstadoAdmitido getEstadoAdmitido() {
		return this.estadoAdmitido;
	}

	public EstadoRechazado getEstadoRechazado() {
		return this.estadoRechazado;
	}

	public EstadoCursado getEstadoCursado() {
		return this.estadoCursado;
	}

	public EstadoFinalizado getEstadoFinalizado() {
		return this.estadoFinalizado;
	}
	
	public LibraryLoanNotification getLibraryLoanNotification() {
		return libraryLoanNotification;
	}

	public void process() {
		this.libraryLoanState.process();
	}
	
	
}
