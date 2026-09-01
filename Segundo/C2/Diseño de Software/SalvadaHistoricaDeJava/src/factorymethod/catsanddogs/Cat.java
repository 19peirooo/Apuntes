package factorymethod.catsanddogs;

public class Cat implements Animal{

	@Override
	public Integer getNumLegs() {
		return 4;
	}

	@Override
	public void makeNoise() {
		System.out.println("Meow");
	}
	
}
