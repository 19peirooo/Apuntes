package EntregaStatePattern;

//El usuario es un observer
public class LibraryUser implements PullPushObserver{
	
	//Atributos
	private String name;
	private String address;
	private UserType userType;
	private Boolean activeAccount;
	
	//Constructor
	public LibraryUser(String name, String address, UserType userType, Boolean activeAccount) {
		this.name = name;
		this.address = address;
		this.userType = userType;
		this.activeAccount = activeAccount;
	}
	
	//Getters y Setters
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
	
	//Actualizacion del estadp
	public void update(PullPushObservable observable, Object state) {
		System.out.println(state);
		
	}

}
