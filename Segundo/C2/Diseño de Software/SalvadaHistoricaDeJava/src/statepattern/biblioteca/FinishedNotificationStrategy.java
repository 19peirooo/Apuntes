package statepattern.biblioteca;

import java.time.LocalDate;

public class FinishedNotificationStrategy extends LibraryPushNotificationStrategy{
	
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to User: " + libraryUser.getName() + 
				". Loan returned on " + LocalDate.now() +
				". Book Returned: " + libraryLoanRequestContext.getBook(); 
		super.update(libraryUser, super.notification);
	}
	
}
