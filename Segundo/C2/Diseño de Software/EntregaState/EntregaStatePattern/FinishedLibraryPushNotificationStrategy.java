package EntregaStatePattern;

import java.time.LocalDate;

//Estrategia Concreta para notificaciones de peticiones finalizadas
public class FinishedLibraryPushNotificationStrategy extends LibraryPushNotificationStrategy{
	
	public FinishedLibraryPushNotificationStrategy() {
		super();
	}
	
	//Definicion del metodo update --> Asigna un valor al atributo de la clase abstracta y actualiza la estrategia
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to user: " + libraryUser.getName() + 
				". Book: " + libraryLoanRequestContext.getBook() +
				" returned on " + LocalDate.now();
		super.update(libraryUser, super.notification);
		
	}

}
