package observerpattern.biblioteca;

public class LibraryTest {
	public static void main(String[] args) {
		Library library = new Library();
			
		StockDept stockDept = new StockDept();
		AdminDept adminDept = new AdminDept();
		SalesDept salesDept = new SalesDept();
		
		library.attach(stockDept);
		library.attach(adminDept);
		library.attach(salesDept);
		
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
