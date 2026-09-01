package decoratorpattern.kindergarden;

import observerpattern.biblioteca.Libro;

public class KinderGardenTest {
	public static void main(String[] args) {
		KinderGarden kindergarden = new KinderGarden();
		Libro book = new Libro();
		KinderGardenBaby ines = new KinderGardenBaby("ines", 1);
		KinderGardenBaby kike = new KinderGardenBaby("kike", 2);
		
		kindergarden.add(ines);
		kindergarden.add(kike);
		
		kindergarden.checkBabies();
		ines.setPrize(new CertificateComponentDecorator(ines.getPrize()));
		kindergarden.checkBabies();
		ines.setPrize(new BookComponentDecorator(book,ines.getPrize()));
		kindergarden.checkBabies();
	}
}
