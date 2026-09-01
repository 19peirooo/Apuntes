package factorymethod.catsanddogs;

public class OverCatsPopulatedAnimalFactory implements AnimalFactory{

	@Override
	public Animal createAnimal() {
		Animal animal;
		Double randomNum = RandomAnimalFactory.getRandomBetweenRange(0, 100);
		
		if (randomNum <= 30) {
			animal = new Dog();
		} else {
			animal = new Cat();
		}
		
		return animal;
	}

}
