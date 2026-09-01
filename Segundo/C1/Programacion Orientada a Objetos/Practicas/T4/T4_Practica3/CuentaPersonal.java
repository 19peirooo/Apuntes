package tema4.practica3;

public class CuentaPersonal {
	
	// Atributos y  Constantes
	public static final Double DEFAULT_SALDO = 0.0;
	
	protected Integer numeroCuenta;
	protected String nombreCliente;
	protected Double saldo;
	
	
	//Constructores
	
	//Constructor con 2 parametros
	public CuentaPersonal(Integer numeroCuenta,String nombreCliente) {
		this(numeroCuenta, nombreCliente, CuentaPersonal.DEFAULT_SALDO);
	}
	
	//Constructor Principal
	public CuentaPersonal(Integer numeroCuenta, String nombreCliente, Double saldo) {
		this.numeroCuenta = numeroCuenta;
		this.nombreCliente = nombreCliente;
		this.saldo = saldo;
	}
	
	//Getters y Setters
	public Integer getNumeroCuenta() {
		return this.numeroCuenta;
	}

	public void setNumeroCuenta(Integer numeroCuenta) {
		this.numeroCuenta = numeroCuenta;
	}

	public String getNombreCliente() {
		return this.nombreCliente;
	}

	public void setNombreCliente(String nombreCliente) {
		this.nombreCliente = nombreCliente;
	}

	public Double getSaldo() {
		return this.saldo;
	}

	public void setSaldo(Double saldo) {
		this.saldo = saldo;
	}

	//To string
	public String toString() {
		return "CuentaPersonal [numeroCuenta=" + this.numeroCuenta + ", nombreCliente=" + this.nombreCliente + ", saldo=" + this.saldo+ "]";
	}
	
	//Imprime el toString
	public void consultarDatos() {
		System.out.println(this.toString());
	}
	
	//Añade un cantidad al saldo
	public void depositar(Double cantidad) {
		this.saldo += cantidad;
	}
	
	
	//Retirar cantidad de tu saldo
	public void retirar(Double cantidad) {
		//Solo puedes retirar si posees esa cantidad de dinero
		if (this.saldo >= cantidad) {
			this.saldo -= cantidad;
		} else {
			System.out.println("ERROR: No tienes tanto dinero");
		}
	}
	
	//Compara 2 cuentas personalas
	public boolean equals(Object object) {
		boolean iguales = false;
		//Veo si mi objeto a comparar es una cuenta personal
		if (object instanceof CuentaPersonal) {
			CuentaPersonal cuenta1 = (CuentaPersonal)object; //Hago downcasting
			iguales = this.numeroCuenta.equals(cuenta1.numeroCuenta); //Veo si son iguales
		}
		
		return iguales;
	}
	
}
