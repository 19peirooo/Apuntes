package statepattern.biblioteca;

public class CreatedNotificationStrategy extends LibraryPushNotificationStrategy{

	@Override
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to User: " + libraryUser.getName() + 
				". Loan admitted on " + libraryLoanRequestContext.getCreatedDate() +
				", due date to pickup " + libraryLoanRequestContext.getPickupDate();
		super.update(libraryUser, super.notification);
	}

}
