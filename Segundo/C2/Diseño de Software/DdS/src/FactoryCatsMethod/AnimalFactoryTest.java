package FactoryCatsMethod;

public class AnimalFactoryTest {
	public static void main(String[] args) {
		Integer maxAnimals = 100;
		Animal[] animals = new Animal[maxAnimals];
		AnimalFactory animalFactory = new RandomAnimalFactory();
		Integer dogs = 0;
		Integer cats = 0;
		for (int i = 0; i < maxAnimals; i++) {
			animals[i] = animalFactory.factoryAnimalMethod();
			if (animals[i] instanceof Dog) {
				dogs++;
			} else {
				cats++;
			}
		}
		System.out.println("Perros: " + dogs + ". Gatos: " + cats + ". Proprocion de Perros: " + Math.round(dogs*100/maxAnimals));
	}
}

