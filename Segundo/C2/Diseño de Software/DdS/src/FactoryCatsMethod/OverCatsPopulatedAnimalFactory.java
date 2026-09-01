package FactoryCatsMethod;

public class OverCatsPopulatedAnimalFactory implements AnimalFactory{

	@Override
	public Animal factoryAnimalMethod() {
		Animal randomAnimal;
		
		double experimentoAleatorio = RandomAnimalFactory.getRandomDouble(0, 100);
		
		if (experimentoAleatorio <= 30) {
			randomAnimal = new Dog();
		} else {
			randomAnimal = new Cat();
		}
		
		return randomAnimal;
	}
}
