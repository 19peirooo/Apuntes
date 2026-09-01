package factorymethod.catsanddogs;

import java.util.ArrayList;
import java.util.List;

public class AnimalFactoryTest {
	public static void main(String[] args) {
		Integer numDogs = 0;
		Integer numCats = 0;
		Integer maxAnimals = 100;
		List<Animal> animals = new ArrayList<Animal>();
		
		AnimalFactory factory = new OverCatsPopulatedAnimalFactory();
		
		for (int i = 0; i < maxAnimals; i++) {
			Animal animal = factory.createAnimal();
			animals.add(animal);
			if (animal instanceof Dog) {
				numDogs++;
			} else {
				numCats++;
			}
		}
		
		System.out.println("Dogs("+numDogs+") Cats("+numCats+")");
		
	}
}
