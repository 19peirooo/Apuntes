package tema5;

public class ExcepcionImpares extends Exception{
	private Integer numError;
	
	public ExcepcionImpares (String message, Integer numError) {
		super(message);
		this.numError = numError;
	}
	
	public Integer getNumError() {
		return this.numError;
	}
	
	public void setNumError(Integer numError) {
		this.numError = numError;
	}
	
	public String toString() {
		return super.toString() + "ExcepcionImpares[numError= " + this.numError +"]";
	}
}
