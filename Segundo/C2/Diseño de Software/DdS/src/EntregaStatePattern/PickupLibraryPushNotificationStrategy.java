package EntregaStatePattern;

import java.time.LocalDate;

//Estrategia Concreta para notificaciones de peticiones de recogida
public class PickupLibraryPushNotificationStrategy extends LibraryPushNotificationStrategy{
	
	public PickupLibraryPushNotificationStrategy() {
		super();
	}
	
	//Definicion del metodo update --> Asigna un valor al atributo de la clase abstracta y actualiza la estrategia
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to user: " + libraryUser.getName() + 
				". Loan picked up on " + LocalDate.now() +
				" due " + LocalDate.now().plusDays(libraryUser.getUserType().getLoanDays()) +
				" days ("+ libraryUser.getUserType().getLoanDays() +")";
		super.update(libraryUser, super.notification);
		
	}
	
}
