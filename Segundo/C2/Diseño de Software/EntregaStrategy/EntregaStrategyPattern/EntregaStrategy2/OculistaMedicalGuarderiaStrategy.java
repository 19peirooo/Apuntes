package EntregaStrategy2;

//Estrategia Concreta para un Oculista
public class OculistaMedicalGuarderiaStrategy implements GuarderiaMedicalStrategy{
	
	public void examinarNinyos() {
		System.out.println("El Oculista esta examindando a la vision niños");
	}

	public void enviarFacturas() {
		System.out.println("El Oculista envia las facturas");
	}

	public void enviarResultados() {
		System.out.println("El Oculista te ha enviado los resultados del examen");
	}

	public void applyMedicalStrategy() {
		this.examinarNinyos();
		this.enviarResultados();
		this.enviarFacturas();
	}

}

