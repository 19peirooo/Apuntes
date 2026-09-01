package statepattern.biblioteca;

import java.util.ArrayList;
import java.util.List;

public class LibraryLoanNotification implements PullPushObservable{
	
	private LibraryPushNotificationStrategy libraryPushNotificationStrategy;
	private LibraryLoanRequestContext libraryLoanRequestContext;
	private List<PullPushObserver> observers;
	
	public LibraryLoanNotification(LibraryLoanRequestContext libraryLoanRequestContext) {
		this(libraryLoanRequestContext, new CreatedNotificationStrategy());
	}
	
	public LibraryLoanNotification(LibraryLoanRequestContext libraryLoanRequestContext, LibraryPushNotificationStrategy pushNotificationStrategy) {
		this(libraryLoanRequestContext, pushNotificationStrategy, new ArrayList<PullPushObserver>());
	}
	
	public LibraryLoanNotification(LibraryLoanRequestContext libraryLoanRequestContext, LibraryPushNotificationStrategy pushNotificationStrategy, List<PullPushObserver> observers) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
		this.libraryPushNotificationStrategy = pushNotificationStrategy;
		this.observers = observers;
	}

	@Override
	public void attach(PullPushObserver observer) {
		this.observers.add(observer);
	}

	@Override
	public void detach(PullPushObserver observer) {
		this.observers.remove(observer);
	}

	@Override
	public void notifyObservers() {
		for (PullPushObserver observer : observers) {
			this.libraryPushNotificationStrategy.update((LibraryUser)observer, this.libraryLoanRequestContext);
		}
	}

	public LibraryPushNotificationStrategy getLibraryPushNotificationStrategy() {
		return this.libraryPushNotificationStrategy;
	}

	public void setLibraryPushNotificationStrategy(LibraryPushNotificationStrategy libraryPushNotificationStrategy) {
		this.libraryPushNotificationStrategy = libraryPushNotificationStrategy;
		this.notifyObservers();
	}

	public LibraryLoanRequestContext getLibraryLoanRequestContext() {
		return this.libraryLoanRequestContext;
	}

	public void setLibraryLoanRequestContext(LibraryLoanRequestContext libraryLoanRequestContext) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
	}

	public List<PullPushObserver> getObservers() {
		return this.observers;
	}

	public void setObservers(List<PullPushObserver> observers) {
		this.observers = observers;
	}
	
	
	
}
