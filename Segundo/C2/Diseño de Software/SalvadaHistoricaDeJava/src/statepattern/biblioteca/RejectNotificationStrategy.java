package statepattern.biblioteca;

import java.time.LocalDate;

public class RejectNotificationStrategy extends LibraryPushNotificationStrategy{
	
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to User: " + libraryUser.getName() + 
				". Loan rejected on " + LocalDate.now();
		super.update(libraryUser, super.notification);
	}
	
}
