package factorymethod.catsanddogs;

public class RandomAnimalFactory implements AnimalFactory{
	
	public static Double getRandomBetweenRange(Integer min, Integer max) {
		return (Math.random()*(max-min))+min;
	}
	
	
	@Override
	public Animal createAnimal() {
		Animal animal;
		Double randomNum = RandomAnimalFactory.getRandomBetweenRange(0, 100);
		
		if (randomNum >= 50) {
			animal = new Dog();
		} else {
			animal = new Cat();
		}
		
		return animal;
	}

}
