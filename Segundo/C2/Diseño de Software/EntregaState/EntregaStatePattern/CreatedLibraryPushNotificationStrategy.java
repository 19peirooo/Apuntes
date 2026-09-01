package EntregaStatePattern;

//Estrategia Concreta para notificaciones de peticiones creadas
public class CreatedLibraryPushNotificationStrategy extends LibraryPushNotificationStrategy{
	
	//Constructor
	public CreatedLibraryPushNotificationStrategy() {
		super();
	}
	
	//Definicion del metodo update --> Asigna un valor al atributo de la clase abstracta y actualiza la estrategia
	public void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext) {
		super.notification = "Notification to user: " + libraryUser.getName() + 
				". Loan admitten on " + libraryLoanRequestContext.getCreatedDate() +
				"to pickup on: " + libraryLoanRequestContext.getPickupDate();
		super.update(libraryUser, super.notification);
	}

}
