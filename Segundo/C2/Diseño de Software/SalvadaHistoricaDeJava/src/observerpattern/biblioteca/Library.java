package observerpattern.biblioteca;

import java.util.ArrayList;
import java.util.List;

public class Library {
	
	private List<Libro> libros;
	private BookAlarm alarm;
	
	public Library() {
		this(new BookAlarm());
	}
	
	public Library(BookAlarm alarm) {
		this.alarm = alarm;
		this.libros = new ArrayList<Libro>();
	}
	
	public void returnBook(Libro book) {
		alarm.setBook(book);
		this.libros.add(book);
	}
	
	public void attach(PullPushObserver observer) {
		this.alarm.attach(observer); //Delegacion por agregacion
	}
	
	public void detach(PullPushObserver observer) {
		this.alarm.detach(observer); //Delegacion por agregacion
	}
	
}
