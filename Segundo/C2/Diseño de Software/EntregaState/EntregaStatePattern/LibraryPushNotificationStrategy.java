package EntregaStatePattern;

//Clase Abstracta que define las notificaciones --> Estrategia mas concreta
public abstract class LibraryPushNotificationStrategy extends PushNotificationStrategy{
	
	protected String notification; //Atributo
	
	//Constructor para notificacion por defecto
	public LibraryPushNotificationStrategy() {
		this("N/A");
	}
	
	//Constructor
	public LibraryPushNotificationStrategy(String notification) {
		this.notification = notification;
	}
	
	//Metodo abstracto --> Se define en estrategias concretas
	public abstract void update(LibraryUser libraryUser, LibraryLoanRequestContext libraryLoanRequestContext);
	
}
