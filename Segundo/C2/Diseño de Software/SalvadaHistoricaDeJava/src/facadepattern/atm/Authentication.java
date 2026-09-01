package facadepattern.atm;

import java.util.Scanner;

public class Authentication {
	
	private String key = "0000";
	
	public Boolean readCard() {
		System.out.println("[Authentication] Reading card...");
		return true;
	}
	
	public String readKey() {
		String key = "";
		Scanner scanner = new Scanner(System.in);
		System.out.print("Clave: ");
		key = scanner.next();
		return key;
	}
	
	public Boolean checkKey(String key) {
		System.out.println("[Authentication] Checking key...");
		return this.key.equals(key);
	}
	
	public Account getPersonalAccount() {
		return new Account();
	}
	
	public void errorProcess() {
		System.out.println("[Authentication] An error has occurred");
	}
	
}
