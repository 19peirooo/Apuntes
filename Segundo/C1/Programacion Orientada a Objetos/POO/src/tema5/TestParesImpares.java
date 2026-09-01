package tema5;

import java.util.Random;

public class TestParesImpares {
	
	public Integer procesarNumerosPositivos(Integer numero) throws Exception {
		if (numero < 0) {
			throw new ExcepcionNegativo("es un numero negativo!!!", numero);
		}
		
		return numero;
	}
	
	public void procesarNumero(Integer numero) throws Exception{
		if(numero % 2 == 0) {
			throw new ExcepcionPares("es numero es par!!! ", numero);
		} else {
			throw new ExcepcionImpares("es numero es impar!!! ", numero);
		}
	}
	
	public static void main(String[] args) {
		Random gen = new Random();
		Integer num = gen.nextInt();
		
		TestParesImpares test = new TestParesImpares();
		try {
			Integer numeroPositivo = test.procesarNumerosPositivos(num);
			System.out.println(numeroPositivo + " es un numero positivo");
			test.procesarNumero(num);
		} catch (ExcepcionImpares e) { 
			System.out.println(e.getNumError() + " " + e.getMessage());
		} catch (ExcepcionPares e) {
			System.out.println(e.getNumError() + " " + e.getMessage());
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println(e.getMessage());
			if (e instanceof ExcepcionNegativo) {
				ExcepcionNegativo excepcion = (ExcepcionNegativo) e;
				System.out.println(excepcion.getNumError());
			}
		}
		
	}
	
	
	
}
