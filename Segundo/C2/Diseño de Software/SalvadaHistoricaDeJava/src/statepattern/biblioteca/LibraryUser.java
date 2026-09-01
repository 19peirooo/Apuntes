package statepattern.biblioteca;

public class LibraryUser implements PullPushObserver{
	
	private String name;
	private String address;
	private UserType userType;
	private Boolean activeAccount;
	
	public LibraryUser(String name, String address, UserType userType) {
		this.name = name;
		this.address = address;
		this.userType = userType;
		this.activeAccount = true;
	}
	
	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAddress() {
		return this.address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public UserType getUserType() {
		return this.userType;
	}

	public void setUserType(UserType userType) {
		this.userType = userType;
	}

	public Boolean getActiveAccount() {
		return this.activeAccount;
	}

	public void setActiveAccount(Boolean activeAccount) {
		this.activeAccount = activeAccount;
	}

	@Override
	public void update(PullPushObservable observable, Object state) {
		System.out.println(state);
		
	}
	
	
	
}
