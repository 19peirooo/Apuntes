package tema4.practica3;

import java.util.ArrayList;
import java.util.List;

public class RegistroCuentas {
	
	//Atributo
	private List<CuentaPersonal> registro;
	
	//Constructor
	public RegistroCuentas() {
		this.registro = new ArrayList<CuentaPersonal>();
	}
	
	//Añade una cuenta a su lista
	public Boolean insertarCuenta(CuentaPersonal cuenta) {
		return this.registro.add(cuenta);
	}
	
	//Elimina una cuenta de su lista y devuelve si ha conseguido eliminarla
	public Boolean borrarCuenta(CuentaPersonal cuenta) {
		Boolean encontrado = false;
		for (CuentaPersonal acc: this.registro) {
			if (acc.equals(cuenta)) {
				this.registro.remove(cuenta);
				encontrado = true;
			}
		}
		return encontrado;
	}
	
	//Busca una cuenta y la devuelve si la encuentra, sino devuelve null
	public CuentaPersonal buscarCuenta (Integer numCuenta) {
		
		CuentaPersonal cuenta = null;
		
		for (CuentaPersonal acc : this.registro) {
			if (acc.getNumeroCuenta().equals(numCuenta)) {
				cuenta = acc;
			}
		}
		
		return cuenta;
		
	}
	
}
