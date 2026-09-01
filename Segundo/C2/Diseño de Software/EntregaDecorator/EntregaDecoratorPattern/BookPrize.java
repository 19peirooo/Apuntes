package EntregaDecoratorPattern;

import EntregaObserverPattern.Libro;

//Decorador concreto del libro
public class BookPrize extends PrizeComponent{
	
	//Atributo
	private Libro book;
	
	//Constructor con libro por defecto. En este caso es el Quijote
	public BookPrize(RewardComponent reward) {
		this(reward,new Libro());
	}
	
	//Constructor
	public BookPrize(RewardComponent reward,Libro book) {
		super(reward);
		this.book = book;
	}
	
	//Devuelve la descripcion del premio por ser niño/a de la semana
	@Override
	public String getPrize() {
		return " es niño/a de la semana con libro: " + this.book.toString();
	}
	
	//Getters y Setters
	public Libro getBook() {
		return book;
	}

	public void setBook(Libro book) {
		this.book = book;
	}
	
	

}
