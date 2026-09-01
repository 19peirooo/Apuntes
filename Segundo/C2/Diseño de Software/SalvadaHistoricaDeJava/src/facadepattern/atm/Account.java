package facadepattern.atm;

public class Account {
	
	private Double balance;
	private String card;
	private Boolean accActive;
	
	public Account() {
		this.balance = 10000.0;
		this.card = "0000";
		this.setAccActive(true);
	}
	
	public Boolean checkAvailableBalance(Double amount) {
		System.out.println("[Account] Checking Balance...");
		return this.balance - amount >= 0;
	}
	
	public void blockAccount() {
		System.out.println("[Account] Blocking Account");
		this.setAccActive(false);
	}
	
	public void unblockAccount() {
		System.out.println("[Account] Unblocking account");
		this.setAccActive(true);
	}
	
	public void extractAmount(Double amount) {
		System.out.println("[Account] Extracting amount...");
		this.balance -= amount;
	}
	
	public void addAmount(Double amount) {
		System.out.println("[Account] Adding money...");
		this.balance += amount;
	}
	
	public void updateAmount() {
		System.out.println("[Account] Updating Account...");
	}
	
	public void errorProcess() {
		System.out.println("[Account] An error has occured");
	}

	public Boolean getAccActive() {
		return this.accActive;
	}

	public void setAccActive(Boolean accActive) {
		this.accActive = accActive;
	}
	
	public Double getBalance() {
		return this.balance;
	}

	public void setBalance(Double balance) {
		this.balance = balance;
	}

	public String getCard() {
		return this.card;
	}

	public void setCard(String card) {
		this.card = card;
	}
}
