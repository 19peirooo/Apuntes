package EntregaStrategy;

//Estrategia Concreta para el Oculista --> Se define los metodos de la estrategia
class OculistaGuarderiaStrategy implements GuarderiaStrategy{
	
	public void examinarNinyos() {
		System.out.println("El Oculista esta examindando a la vision niños");
	}

	public void enviarFacturas() {
		System.out.println("El Oculista envia las facturas");
	}

	public void enviarResultados() {
		System.out.println("El Oculista te ha enviado los resultados del examen");
	}

}
