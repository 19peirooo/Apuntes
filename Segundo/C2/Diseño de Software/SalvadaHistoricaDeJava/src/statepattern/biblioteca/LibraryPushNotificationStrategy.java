package statepattern.biblioteca;

public abstract class LibraryPushNotificationStrategy extends PushNotificationStrategy {
	
	protected String notification;
	
	public LibraryPushNotificationStrategy() {
		this("N/A");
	}
	
	public LibraryPushNotificationStrategy(String notification) {
		this.notification = notification;
	}
	
	public abstract void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext);

}