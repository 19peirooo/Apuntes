package EntregaDecoratorPattern;

public class KinderGartenTest {
	public static void main(String[] args) {
		Kindergarten kinderGarten = new Kindergarten();
		
		//Creamis los bebes
		KinderGartenBaby ines = new KinderGartenBaby("Ines", 1);
		KinderGartenBaby kike = new KinderGartenBaby("Kike", 2);
		
		//Añadimos los bebes a la guarderia
		kinderGarten.addBaby(ines);
		kinderGarten.addBaby(kike);
		
		//Pasamos lista
		kinderGarten.checkBabies();
		
		//Le damos una certificado a Ines
		ines.setReward(new CertificatePrize(ines.getReward()));
		
		//Pasamos lista
		kinderGarten.checkBabies();
		
		//Ines es la niña de la semana por ello recibe un libro
		BookPrize premioLibro = new BookPrize(ines.getReward()); //Libro por defecto = El quijote
		ines.setReward(premioLibro);
		
		//Pasamos lista
		kinderGarten.checkBabies();
		
		//Imprime el nombre del libro de Ines
		System.out.println(ines.getNombre() + " tiene el libro: " + premioLibro.getBook().getNombre());
	}
}
