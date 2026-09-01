package statepattern.biblioteca;

import java.time.LocalDate;

public class PickupNotificationStrategy extends LibraryPushNotificationStrategy{
	
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to User: " + libraryUser.getName() + 
				". Loan pickup on " + LocalDate.now() +
				", due date to return " + LocalDate.now().plusDays(libraryUser.getUserType().getLoanDays()) +
				" days " + libraryUser.getUserType().getLoanDays();
		super.update(libraryUser, super.notification);
	}
	
}
