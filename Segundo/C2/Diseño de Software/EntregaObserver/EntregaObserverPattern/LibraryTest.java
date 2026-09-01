package EntregaObserverPattern;

public class LibraryTest {
	public static void main(String[] args) {
		//Crear una biblioteca
		Library library = new Library();
		
		//Creo los observadores y los añado a la lista de observadores
		StockDept stock = new StockDept();
		AdminDept admin = new AdminDept();
		ComprasDept compras = new ComprasDept();
		
		library.getAlarm().attach(stock);
		library.getAlarm().attach(admin);
		library.getAlarm().attach(compras);
		
		//Creo un libro en buen estado y en mal estado e intento devolverlos
		Libro quijote = new Libro();
		quijote.setEstado(BookState.BAD);
		
		Libro buenLibro = new Libro("Gang of 4 Design Pattern", "Erich Gamma, Richard Helm", 288, BookState.GOOD);
		
		System.out.println("Alarma notifica bajo protocolo PULL-PUSH");
		library.returnBook(buenLibro);
		library.returnBook(quijote);
		
		//Creo libro en mal estado e intento devolverlo
		System.out.println("Alarma vuelve a notificar bajo protocolo PULL-PUSH");
		Libro malLibro = new Libro("Programar sin patrones", "Golfito Martinez", 10, BookState.BAD);
		
		library.returnBook(malLibro);
	}
}
