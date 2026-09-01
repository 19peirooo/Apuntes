package EntregaStatePattern;

import java.util.List;
import java.util.ArrayList;

//Contexto del Patron Strategy y Observable
public class LibraryLoanNotification implements PullPushObservable{
	//Atributos
	LibraryPushNotificationStrategy libraryPushNotificationStrategy; //Variable Observada
	LibraryLoanRequestContext libraryLoanRequestContext;
	List<PullPushObserver> observers;
	
	//Constructores
	public LibraryLoanNotification(LibraryLoanRequestContext libraryLoanRequestContext) {
		this(libraryLoanRequestContext, new CreatedLibraryPushNotificationStrategy());
	}
	
	public LibraryLoanNotification(LibraryLoanRequestContext libraryLoanRequestContext, LibraryPushNotificationStrategy pushNotificationStrategy) {
		this(libraryLoanRequestContext, pushNotificationStrategy, new ArrayList<PullPushObserver>());
	}
	
	public LibraryLoanNotification(LibraryLoanRequestContext libraryLoanRequestContext, LibraryPushNotificationStrategy pushNotificationStrategy, List<PullPushObserver> observers) {
		this.libraryLoanRequestContext = libraryLoanRequestContext;
		this.libraryPushNotificationStrategy = pushNotificationStrategy;
		this.observers = observers;
	}


	//Añade Observadores a la lista de observadores
	public void attach(PullPushObserver observer) {
		this.observers.add(observer);
	}
	
	//Elimina un observador de la lista de observadores
	public void detach(PullPushObserver observer) {
		this.observers.remove(observer);
	}

	//Notifica a todos los observadores sobre una cambio en la variable de estado
	public void notifyObservers() {
		for (PullPushObserver observer : observers) {
			this.libraryPushNotificationStrategy.update((LibraryUser)observer, this.libraryLoanRequestContext); //Delegacion por agregacion
		}
	}
	
	//Getters y Setters
	public LibraryPushNotificationStrategy getLibraryPushNotificationStrategy() {
		return this.libraryPushNotificationStrategy;
	}
	
	//Cuando hay una cambio en la variable de estado, se notifica a los observadores
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
	
	
}
