package singleton.soups;

import java.util.Objects;

public class SoupOnDemand {
	public static SoupOnDemand soupOnDemand;
	
	private SoupOnDemand() {}
	
	public static SoupOnDemand getInstance() {
		if (Objects.isNull(soupOnDemand)) {
			soupOnDemand = new SoupOnDemand();
		}
		return soupOnDemand;
	}
	
	public void ready() {
		System.out.println("Soup On Demand is ready");
	}
}
