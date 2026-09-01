package ejerciciosTema5;

public class ParException extends Exception{
	
	private Integer numError;
	
	public ParException(String message,Integer numError) {
		super(message);
		this.numError = numError;
	}

	public Integer getNumError() {
		return numError;
	}

	public void setNumError(Integer numError) {
		this.numError = numError;
	}

}
