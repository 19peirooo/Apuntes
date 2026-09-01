package EntregaStatePattern;

import java.time.LocalDate;

//Estrategia Concreta para notificaciones de peticiones rechazadas
public class RejectedLibraryPushNotificationStrategy extends LibraryPushNotificationStrategy{
	
	public RejectedLibraryPushNotificationStrategy() {
		super();
	}
	
	//Definicion del metodo update --> Asigna un valor al atributo de la clase abstracta y actualiza la estrategia
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to user: " + libraryUser.getName() +
				". Loan rejected on " + LocalDate.now();
		super.update(libraryUser, super.notification);
	}
	
	
	
}
