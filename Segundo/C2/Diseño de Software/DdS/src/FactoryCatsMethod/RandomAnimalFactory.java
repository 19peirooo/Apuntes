package FactoryCatsMethod;

public class RandomAnimalFactory implements AnimalFactory {
	
	public static double getRandomDouble(int min, int max) {
		return (Math.random()*(max-min))+min;
	}
	
	public Animal factoryAnimalMethod() {
		Animal randomAnimal;
		double experimentoAleatorio = RandomAnimalFactory.getRandomDouble(0, 100);
		if (experimentoAleatorio >= 50) {
			randomAnimal = new Cat();
		} else {
			randomAnimal = new Dog();
		}
		return randomAnimal;
	}

}
