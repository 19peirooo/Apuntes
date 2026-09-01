package tema4.practica3;

import tema3.Fecha;

public class CuentaCheque extends CuentaPersonal{
	
	//Atributos y Constantes
	public static final Double DEFAULT_COMISION_CHEQUERA = 0.5;
	public static final Double DEFAULT_COMISION_SALDO_INDEPENDIENTE = 0.05;
	
	private Boolean numerosRojos;
	private Double comisionChequera;
	private Double comisionSaldoInsuficiente;
	
	//Constructores
	//Constructor de 2 parametros
	public CuentaCheque(Integer numeroCuenta, String nombreCliente) {
		this(numeroCuenta,nombreCliente, CuentaPersonal.DEFAULT_SALDO, CuentaCheque.DEFAULT_COMISION_CHEQUERA, CuentaCheque.DEFAULT_COMISION_SALDO_INDEPENDIENTE);
	}
	
	//Constructor Principal
	public CuentaCheque(Integer numeroCuenta,String nombreCliente ,Double saldo,Double comisionChequera, Double comisionSaldoInsuficiente) {
		super(numeroCuenta,nombreCliente,saldo); //Constructor para la clase padre
		this.comisionChequera = comisionChequera;
		this.comisionSaldoInsuficiente = comisionSaldoInsuficiente;
		this.numerosRojos = super.saldo < 0; //El valor de numeros rojos depende del estado del saldo
	}
	
	//Getters y setters
	public Boolean getNumerosRojos() {
		return numerosRojos;
	}

	public void setNumerosRojos(Boolean numerosRojos) {
		this.numerosRojos = numerosRojos;
	}

	public Double getComisionChequera() {
		return comisionChequera;
	}

	public void setComisionChequera(Double comisionChequera) {
		this.comisionChequera = comisionChequera;
	}

	public Double getComisionSaldoInsuficiente() {
		return comisionSaldoInsuficiente;
	}

	public void setComisionSaldoInsuficiente(Double comisionSaldoInsuficiente) {
		this.comisionSaldoInsuficiente = comisionSaldoInsuficiente;
	}

	//Metodo toString
	public String toString() {
		return super.toString() + "CuentaCheque [numerosRojos=" + numerosRojos + ", comisionChequera=" + comisionChequera
				+ ", comisionSaldoInsuficiente=" + comisionSaldoInsuficiente + "]";
	}

	//Resta dinero al saldo por tener una comision chequera
	public void comisionChequera() {
		if (new Fecha().getDia().equals(1)) {
			super.saldo -= super.saldo*this.comisionChequera;
		}
	}
	
	//Sobreescribe el metodo retirar para que pueda retirar sin importar que puede tener numeros rojos
	@Override
	public void retirar(Double cantidad) {
		super.saldo -= cantidad;
		if (super.saldo < cantidad) {
			super.saldo -= super.saldo * this.comisionSaldoInsuficiente;
			this.numerosRojos = true;
		}
		super.saldo -= cantidad;
		
	}
	
	//Sobreescribe el metodo depositar para que actualice el atributo de numeros rojos
	@Override
	public void depositar(Double cantidad) {
			super.depositar(cantidad);
			this.numerosRojos = super.saldo < 0;
	}
	
}
