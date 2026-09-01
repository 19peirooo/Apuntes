package EntregaObserverPattern;

import java.util.ArrayList;
import java.util.List;

public class BookAlarm implements PullPushObservable{
	
	//Atributos
	private Libro book; //Estado del que se informa
	private List<PullPushObserver> observers;
	
	//Constructor sin parametros
	public BookAlarm() {
		this(new Libro());
	}
	
	//Constructor de 1 parametro
	public BookAlarm(Libro book) {
		this(book,new ArrayList<PullPushObserver>());
	}
	
	//Constructor principal
	public BookAlarm(Libro book, List<PullPushObserver> observers) {
		this.book = book;
		this.observers = observers;
	}
	
	//Getters y Setter del libros
	public Libro getBook() {
		return this.book;
	}

	public void setBook(Libro book) {
		this.book = book;
		this.notifyObservers(); //Al cambiar el estado, se notifica a todo observador
	}

	//Añade a un observador
	public void attach(PullPushObserver observer) {
		this.observers.add(observer);
	}

	//Elimina a un observador
	public void detach(PullPushObserver observer) {
		this.observers.remove(observer);
	}
	
	//Notifica de cambio de estado a todos los observadores
	public void notifyObservers() {
		for (PullPushObserver observer : observers) {
			observer.update(this, this.book);
		}
	}
}
