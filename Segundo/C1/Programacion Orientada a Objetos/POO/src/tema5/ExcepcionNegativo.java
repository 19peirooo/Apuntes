package tema5;

public class ExcepcionNegativo extends Exception{

	private Integer numError;
	
	public ExcepcionNegativo (String message, Integer numError) {
		super(message);
		this.numError = numError;
	}
	
	public Integer getNumError() {
		return this.numError;
	}
	
	public void setNumError(Integer numError) {
		this.numError = numError;
	}
	
	
}
