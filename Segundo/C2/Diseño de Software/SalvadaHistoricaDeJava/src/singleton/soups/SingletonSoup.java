package singleton.soups;

public class SingletonSoup {
	
	private static SingletonSoup singletonSoup = new SingletonSoup();
	
	private SingletonSoup() {}
	
	public static SingletonSoup getInstance() {
		return singletonSoup;
	}
	
	public void ready() {
		System.out.println("Singleton Soup is ready");
	}
	
}
