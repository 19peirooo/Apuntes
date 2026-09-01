package ejerciciosTema5;

public class ImparException extends Exception{
	
	private Integer numError;
	
	public ImparException(String message,Integer numError) {
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