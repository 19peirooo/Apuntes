package EntregaObserverPattern;

//Observador
public class ComprasDept implements PullPushObserver{

	public void update(PullPushObservable observable, Object state) {
		//Primero comprueba si ha recibido el estado
		//Protocol Push
		if (state instanceof Libro) {
			System.out.println("[ComprasDept Push] se ha devuelto el libro en mal estado"
					+ (Libro)state);
		//Protocolo Pull
		} else if (observable instanceof BookAlarm) {
			System.out.println("[ComprasDept Pull] se ha devuelto el libro en mal estado" 
					+ ((BookAlarm)observable).getBook());
		}
		
		
	}

}
