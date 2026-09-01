package observerpattern.biblioteca;

public class SalesDept implements PullPushObserver{
	
	public void update(PullPushObservable observable, Object object) {
		if (object instanceof Libro) {
			System.out.println("[SalesDept Push Protocol] Se ha devuelto un libro en mal estado. Libro: " + ((Libro)object).getNombre());
		} else if (observable instanceof BookAlarm) {
			System.out.println("[SalesDept Pull Protocol] Se ha devuelto un libro en mal estado. Libro: " + ((BookAlarm)observable).getBook().getNombre());
		}
	}
	
}
