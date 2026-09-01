package EntregaObserverPattern;

import java.util.ArrayList;
import java.util.List;

public class Library {
	
	//Atributos
	private List<Libro> libros; 
	private BookAlarm alarm;
	
	//Constructor sin parametros
	public Library() {
		this(new BookAlarm());
	}
	
	//Constructor con 1 parametros
	public Library(BookAlarm alarm) {
		this(new ArrayList<Libro>(),alarm);
	}
	
	//Constructor con 2 parametros
	public Library (List<Libro> libros,BookAlarm alarm) {
		this.libros = libros;
		this.alarm = alarm;
	}
	
	//Devuelve libros en mal estado
	void returnBook(Libro book) {
		if (book.getEstado().equals(BookState.BAD)) {
			alarm.setBook(book);
		}
		this.libros.add(book);
	}

	//Getters y Setters
	public List<Libro> getLibros() {
		return this.libros;
	}

	public void setLibros(List<Libro> libros) {
		this.libros = libros;
	}

	public BookAlarm getAlarm() {
		return this.alarm;
	}

	public void setAlarm(BookAlarm alarm) {
		this.alarm = alarm;
	}
	
	
	
}
