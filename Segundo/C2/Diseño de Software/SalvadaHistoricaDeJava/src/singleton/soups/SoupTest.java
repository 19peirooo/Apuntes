package singleton.soups;

public class SoupTest {
	public static void main(String[] args) {
		QuickSoup quickSoup = QuickSoup.getInstance();
		quickSoup.ready();
		
		SoupOnDemand soupOnDemand = SoupOnDemand.getInstance();
		soupOnDemand.ready();
		
		SingletonSoup singletonSoup = SingletonSoup.getInstance();
		singletonSoup.ready();
	}
}
