package EntregaStrategy2;

//Estrategia Concreta para el Logopeda
public class LogopedaMedicalGuarderiaStrategy implements GuarderiaMedicalStrategy{
	
	public void examinarNinyos() {
		System.out.println("El Logopeda esta examindando el habla de los niños");
	}

	public void enviarFacturas() {
		System.out.println("El Logopeda envia las facturas");
	}

	public void enviarResultados() {
		System.out.println("El Logopeda te ha enviado los resultados del examen");
	}

	public void applyMedicalStrategy() {
		this.examinarNinyos();
		this.enviarResultados();
		this.enviarFacturas();
	}

}
