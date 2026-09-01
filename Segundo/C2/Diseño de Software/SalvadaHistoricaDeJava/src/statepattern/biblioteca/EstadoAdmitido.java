package statepattern.biblioteca;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class EstadoAdmitido implements LibraryLoanState,LibraryLoanStateTransition {
	
	private LibraryLoanRequestContext libraryLoanRequestContext;
	
	public EstadoAdmitido(LibraryLoanRequestContext libraryLoanRequestContext) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
	}
	
	@Override
	public void aceptar() {
		// TODO Auto-generated method stub
		
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
		this.libraryLoanRequestContext.setLibraryLoanState(this.libraryLoanRequestContext.getEstadoCursado());
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new PickupNotificationStrategy());
		
	}

	@Override
	public void process() {
		if (ChronoUnit.DAYS.between(LocalDate.now(), this.libraryLoanRequestContext.getPickupDate()) >= 0) {
			this.recoger();
		} else {
			this.rechazar();
		}
	}

	@Override
	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}
	
}
