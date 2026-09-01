package singleton.soups;

public class QuickSoup {
	private QuickSoup() {}
	
	public static QuickSoup getInstance() {
		return new QuickSoup();
	}
	
	public void ready() {
		System.out.println("QuickSoup is ready");
	}
}
