package facadepattern.atm;

public class AtmFacade {
	
	private Atm atm = new Atm();
	private Authentication auth = new Authentication();
	private Account account;
	
	public void getPersonalData() {
		Boolean correctCard = this.auth.readCard();
		if (correctCard) {
			String personalKey = this.auth.readKey();
			Boolean correctKey = this.auth.checkKey(personalKey);
			if (correctKey) {
				this.account = this.auth.getPersonalAccount();
			} else {
				this.auth.errorProcess();
			}
		} else {
			this.auth.errorProcess();
		}
	}
	
	public void extractMoney() {
		if (this.account != null) {
			Double amount = this.atm.readAmount();
			Boolean hasAvailableMoney = this.atm.hasAvailableMoney(amount);
			if (hasAvailableMoney) {
				Boolean hasAvailableBalance = this.account.checkAvailableBalance(amount);
				if (hasAvailableBalance) {
					this.account.blockAccount();
					this.account.extractAmount(amount);
					this.account.updateAmount();
					this.account.unblockAccount();
					this.atm.extractMoney(amount);
					this.atm.printTicket();
				} else {
					this.account.errorProcess();
				}
			} else {
				this.account.errorProcess();
			}
		}
	}
	
}
