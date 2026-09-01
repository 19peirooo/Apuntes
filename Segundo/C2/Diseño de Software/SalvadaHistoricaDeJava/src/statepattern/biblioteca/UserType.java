package statepattern.biblioteca;

public enum UserType {
	
	STUDENT(15),TEACHER(10);
	
	private Integer loanDays;
	
	private UserType(Integer loanDays) {
		this.loanDays = loanDays;
	}
	
	public Integer getLoanDays() {
		return this.loanDays;
	}
	
}
