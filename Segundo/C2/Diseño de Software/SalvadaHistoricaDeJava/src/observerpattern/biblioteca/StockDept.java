package observerpattern.biblioteca;

public class StockDept implements PullPushObserver{

	@Override
	public void update(PullPushObservable observable, Object object) {
		if (object instanceof Libro) {
			System.out.println("[StockDept Push Protocol] Se ha devuelto un libro en mal estado. Libro: " + ((Libro)object).getNombre());
		} else if (observable instanceof BookAlarm) {
			System.out.println("[StockDept Pull Protocol] Se ha devuelto un libro en mal estado. Libro: " + ((BookAlarm)observable).getBook().getNombre());
		}
	}

}
