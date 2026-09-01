package ejerciciosTema5;

public class ej2 {
	
	public void procesarNumero (Integer numero) throws Exception {
		if (numero % 2 == 0) {
			throw new ParException("El numero es par", numero);
		} else {
			throw new ImparException("El numero es impar", numero);
		}
	}
	
	public static void main(String[] args) {
		Integer numero = (int)(Math.random() * 100) + 1;
		ej2 x = new ej2();
		
		try {
			
			x.procesarNumero(numero);
			
		} catch (ParException e) {
			System.out.println(e.getMessage() + " Numero: " + e.getNumError());
		} catch (ImparException e) {
			System.out.println(e.getMessage() + "Numero: " + e.getNumError());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}
