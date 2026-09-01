package FactoryCatsMethod;

public class Cat implements Animal {

	@Override
	public Integer getNumLegs() {
		return 4;
	}

	@Override
	public void noise() {
		System.out.println("Miau");
	}
	
}
