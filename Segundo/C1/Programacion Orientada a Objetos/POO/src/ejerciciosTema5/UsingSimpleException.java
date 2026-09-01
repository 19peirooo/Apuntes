package ejerciciosTema5;

public class UsingSimpleException {
	
	public void method() throws SimpleException {
		throw new SimpleException("Throwing SimpleException from method()");
	}
	
	public static void main(String[] args) {
		UsingSimpleException use = new UsingSimpleException();
		
		try {
			use.method();
		} catch (SimpleException e) {
			System.out.println(e.getMessage());
		}
	}
	
}
