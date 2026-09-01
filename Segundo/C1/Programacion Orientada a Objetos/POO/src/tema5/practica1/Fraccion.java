package tema5.practica1;

public class Fraccion {
	
	private Integer numerador;
	private Integer denominador;
	
	public Fraccion (Integer numerador, Integer denominador) throws FraccionException {
		if (denominador.equals(0)) {
			throw new FraccionException("Denominador no puede ser 0");
		}
		this.numerador = numerador;
		this.denominador = denominador;
	}
	
	public Integer getNumerador() {
		return numerador;
	}

	public void setNumerador(Integer numerador) {
		this.numerador = numerador;
	}

	public Integer getDenominador() {
		return denominador;
	}

	public void setDenominador(Integer denominador) {
		this.denominador = denominador;
	}
	
	public String toString() {
		return "Fraccion: " + this.numerador + "/" + this.denominador; 
	}

	public Fraccion sumar (Fraccion otraFraccion) throws FraccionException {
		Integer numeradorSuma = (this.numerador*otraFraccion.denominador) + (this.denominador*otraFraccion.numerador);
		Integer denominadorSuma = this.denominador * otraFraccion.denominador;
		return new Fraccion(numeradorSuma,denominadorSuma);
	}; 
	
	public Fraccion restar (Fraccion otraFraccion) throws FraccionException {
		Integer numeradorResta = (this.numerador*otraFraccion.denominador) - (this.denominador*otraFraccion.numerador);
		Integer denominadorResta = this.denominador * otraFraccion.denominador;
		return new Fraccion(numeradorResta,denominadorResta);
	}; 
	
	public Fraccion multiplicar (Fraccion otraFraccion) throws FraccionException {
		Integer numeradorMult = this.numerador * otraFraccion.numerador;
		Integer denominadorMult = this.denominador * otraFraccion.denominador;
		return new Fraccion(numeradorMult,denominadorMult);
	}; 
	
	public Fraccion dividir (Fraccion otraFraccion) throws FraccionException {
		if (this.denominador.equals(0) || otraFraccion.numerador.equals(0)) {
			throw new FraccionException("El resultado de la division da 0 en el denominador");
		}
		Integer numeradorDiv = this.numerador * otraFraccion.denominador;
		Integer denominadorDiv = this.denominador * otraFraccion.numerador;
		return new Fraccion(numeradorDiv,denominadorDiv);
	}
	
	public static void main(String[] args) {
		 try {
	            Fraccion f1 = new Fraccion(3, 4);
	            Fraccion f2 = new Fraccion(2, 5);
	            
	            Fraccion suma = f1.sumar(f2);
	            System.out.println("Suma: " + suma);

	            Fraccion resta = f1.restar(f2);
	            System.out.println("Resta: " + resta);

	            Fraccion multiplicacion = f1.multiplicar(f2);
	            System.out.println("Multiplicación: " + multiplicacion);

	            Fraccion division = f1.dividir(f2);
	            System.out.println("División: " + division);
	        } catch (FraccionException e) {
	            System.out.println("ERROR: " + e.getMessage());
	        }
	}
	
}
