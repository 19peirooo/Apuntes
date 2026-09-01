package observerpattern.biblioteca;

import java.util.ArrayList;
import java.util.List;

public class BookAlarm implements PullPushObservable{
	private List<PullPushObserver> observers;
	private Libro book;
	
	public BookAlarm() {
		this(new Libro());
	}
	
	public BookAlarm(Libro book) {
		this.book = book;
		this.observers = new ArrayList<PullPushObserver>();
	}
	
	

	public Libro getBook() {
		return this.book;
	}

	public void setBook(Libro book) {
		this.book = book;
		if (this.book.getEstado().equals(BookState.BAD)) {
			this.notifyObservers();
		}
	}

	@Override
	public void attach(PullPushObserver observer) {
		this.observers.add(observer);
	}

	@Override
	public void detach(PullPushObserver observer) {
		this.observers.remove(observer);
	}

	@Override
	public void notifyObservers() {
		for (PullPushObserver observer : this.observers) {
			observer.update(this, this.book);
		}
	}
	
}
