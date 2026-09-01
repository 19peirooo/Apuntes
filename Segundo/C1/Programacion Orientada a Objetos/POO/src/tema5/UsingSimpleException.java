package tema5;



public class UsingSimpleException {
	public void method() throws SimpleException{
		System.out.println("Theow SimpleException from method()");
		throw new SimpleException("No Disponible manito");
	}
	
	public static void main(String[] args) {
		UsingSimpleException use = new UsingSimpleException();
		try {
			use.method();
		} catch (SimpleException e){
			System.out.println("Capturando error!! " + e.getMessage());
		}
	}
}
