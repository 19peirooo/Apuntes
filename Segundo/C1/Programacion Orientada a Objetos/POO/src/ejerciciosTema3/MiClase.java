package ejerciciosTema3;

public class MiClase {
	
	public static final Integer DEFAULT_NUMERO = 0;
	
	private Integer numero;
	
	public MiClase (Integer numero1 , Integer numero2) {
		this(numero1 * numero2);
	}
	
	public MiClase () {
		this(MiClase.DEFAULT_NUMERO);
	}
	
	public MiClase (Double numero) {
		this(numero.intValue());
	}
	
	public MiClase(Integer numero) {
		this.numero = numero;
	}

	public Integer getNumero() {
		return numero;
	}

	public void setNumero(Integer numero) {
		this.numero = numero;
	}
	
	public String toString() {
		return "MiClase [numero= " + this.numero + "] ";
	}
	
	public static void main(String[] args) {
		MiClase clase1 = new MiClase();
		MiClase clase2 = new MiClase(2);
		MiClase clase3 = new MiClase(2.6);
		MiClase clase4 = new MiClase(2,5);
		System.out.println(clase1 + "" + clase2 + clase3 + clase4);
	}
	
}
