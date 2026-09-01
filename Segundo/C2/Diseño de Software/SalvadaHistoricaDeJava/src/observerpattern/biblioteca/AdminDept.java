package observerpattern.biblioteca;

public class AdminDept implements PullPushObserver{

	@Override
	public void update(PullPushObservable observable, Object object) {
		if (object instanceof Libro) {
			System.out.println("[AdminDept Push Protocol] Se ha devuelto un libro en mal estado. Libro: " + ((Libro)object).getNombre());
		} else if (observable instanceof BookAlarm) {
			System.out.println("[AdminDept Pull Protocol] Se ha devuelto un libro en mal estado. Libro: " + ((BookAlarm)observable).getBook().getNombre());
		}
	}

}
