package EntregaStatePattern;

//Implementacion del patron singleton para creacion de enumerados con constructor
public enum UserType {
	STUDENT(15),PROFESSOR(10); //Cada objeto del enumerado tiene un valor por defecto de dias
	
	//Atributo
	private Integer loanDays;
	
	//Constructor privado del enumerado para poder asignarle el numero de dias a cada tipo de usuario
	private UserType(Integer loanDays) {
		this.loanDays = loanDays;
	}
	
	//Getter y Setter
	public Integer getLoanDays() {
		return this.loanDays;
	}
	
	public void setLoanDays(Integer loanDays) {
		this.loanDays = loanDays;
	}
}
