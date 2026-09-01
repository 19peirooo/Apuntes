package SingletonSoup;

public class QuickSoup {
	private QuickSoup() {}
	
	public static QuickSoup makeSoup() {
		return new QuickSoup();
	}
	
	public void ready() {
		System.out.println("Quick Soup is ready");
	}
}
