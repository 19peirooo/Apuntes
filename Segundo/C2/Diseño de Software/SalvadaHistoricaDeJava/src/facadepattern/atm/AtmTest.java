package facadepattern.atm;

public class AtmTest {
	public static void main(String[] args) {
		AtmFacade facade = new AtmFacade();
		facade.getPersonalData();
		facade.extractMoney();
	}
}
