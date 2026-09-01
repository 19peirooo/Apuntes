package EntregaStrategy;

//Estrategia Concreta para el Logopeda --> Se define los metodos de la estrategia
public class LogopedaGuarderiaStrategy implements GuarderiaStrategy{

	public void examinarNinyos() {
		System.out.println("El Logopeda esta examinando el habla de los niños");
	}

	public void enviarFacturas() {
		System.out.println("El Logopeda te envia las facturas");
	}

	public void enviarResultados() {
		System.out.println("El Logopeda te envia los resultados del examen");
	}

}
