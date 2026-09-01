package EntregaStatePattern;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

//Estado admitido
public class LibraryLoanAdmittedState implements LibraryLoanState,LibraryLoanStateTransition{
	
	private LibraryLoanRequestContext libraryLoanRequestContext; //Contexto
	
	//Constructor
	public LibraryLoanAdmittedState(LibraryLoanRequestContext context) {
		this.libraryLoanRequestContext = context;
	}

	//Si el usuario no pasado con los fias entre la fecha de recogida y la fecha de creacion, se puede recoger, sino se rechaza
	@Override
	public void process() {
		if (ChronoUnit.DAYS.between(LocalDate.now(), this.libraryLoanRequestContext.getPickupDate()) >= 0) {
			this.pickUpBook();
		} else {
			this.rejectRequest();
		}
	}

	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}

	@Override
	public void acceptRequest() {
		// TODO Auto-generated method stub
		
	}
	
	//Pasa a estado rechazado y lanza una notificacion
	@Override
	public void rejectRequest() {
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new RejectedLibraryPushNotificationStrategy());
		this.libraryLoanRequestContext.setCurrentState(this.libraryLoanRequestContext.getRejectedState());
		
	}
	
	//Pasa a estado procesado y lanza una notificacion
	@Override
	public void pickUpBook() {
		this.libraryLoanRequestContext.getLibraryLoanNotification().setLibraryPushNotificationStrategy(new PickupLibraryPushNotificationStrategy());
		this.libraryLoanRequestContext.setCurrentState(this.libraryLoanRequestContext.getProcessedState());
		
	}

	@Override
	public void returnBook() {
		// TODO Auto-generated method stub
		
	}
}


