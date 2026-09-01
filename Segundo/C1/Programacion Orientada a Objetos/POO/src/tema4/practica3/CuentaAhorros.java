package tema4.practica3;

import tema3.Fecha;

//Hereda de CuentaPersonal
public class CuentaAhorros extends CuentaPersonal{
	
	//Atributos
	private Fecha fechaVencimiento;
	private Double interesMensual;
	
	//Constructor
	public CuentaAhorros(Fecha fechaVencimiento, Double interesMensual ,Integer numeroCuenta, String nombreCliente, Double saldo) {
		super(numeroCuenta, nombreCliente,saldo);
		this.fechaVencimiento = fechaVencimiento;
		this.interesMensual = interesMensual;
	}
	
	//Getters y Setters
	public Fecha getFechaVencimiento() {
		return fechaVencimiento;
	}

	public void setFechaVencimiento(Fecha fechaVencimiento) {
		this.fechaVencimiento = fechaVencimiento;
	}

	public Double getInteresMensual() {
		return interesMensual;
	}

	public void setInteresMensual(Double interesMensual) {
		this.interesMensual = interesMensual;
	}

	//Metodo toString
	public String toString() {
		return super.toString() + "[" + this.fechaVencimiento + ", " + this.interesMensual + "]";
	}
	
	//Inserta intereses solo si es el primer dia del mes
	public void insertarIntereses() {
		if (new Fecha().getDia().equals(1)) {
			super.depositar(super.saldo * this.interesMensual);
		}
	}
	
	//Sobrescritura del metodo retirar solo para que se pueda retirar el ultimo dia del mes
	public void retirar(Double cantidad, Fecha fechaOperacion) {
		if(fechaOperacion.equals(fechaVencimiento)) {
			super.retirar(cantidad);
		} else {
			System.out.println("ERROR: Solo se puede retirar dinero el dia de la fecha de vencimiento");
		}
	}	
}
