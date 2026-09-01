package decoratorpattern.kindergarden;

import observerpattern.biblioteca.Libro;

public class BookComponentDecorator extends PrizeComponentDecorator{
	
	private Libro book;
	
	public BookComponentDecorator(PrizeComponent prize) {
		this(new Libro(),prize);
	}
	
	public BookComponentDecorator(Libro book,PrizeComponent prize) {
		super(prize);
		this.book = book;
	}

	@Override
	public String getPrize() {
		return "es el/la niño/a de la semana ha ganado el libro: " + this.book.toString();
	}

}
