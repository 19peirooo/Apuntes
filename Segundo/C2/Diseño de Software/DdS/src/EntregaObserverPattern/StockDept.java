package EntregaObserverPattern;

//Observador
public class StockDept implements PullPushObserver{

	public void update(PullPushObservable observable, Object state) {
		//Primero comprueba si ha recibido el estado
		//Protocol Push
		if (state instanceof Libro) {
			System.out.println("[StockDept Push] se ha devuelto el libro en mal estado"
					+ (Libro)state);
		//Protocolo Pull
		} else if (observable instanceof BookAlarm) {
			System.out.println("[StockDept Pull] se ha devuelto el libro en mal estado" 
					+ ((BookAlarm)observable).getBook());
		}
		
		
	}

}
