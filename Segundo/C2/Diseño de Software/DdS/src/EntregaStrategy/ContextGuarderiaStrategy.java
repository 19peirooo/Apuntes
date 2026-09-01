package EntregaStrategy;

//Contexto que utiliza el patron
public class ContextGuarderiaStrategy implements GuarderiaStrategy{
	
	private GuarderiaStrategy guarderiaStrategy; //Relacion de Agregacion
	
	//Constructor por defecto --> Asigna al Oculista como Estrategia por Defecto
	public ContextGuarderiaStrategy() {
		this(new OculistaGuarderiaStrategy());
	}
	
	//Constructor principal 
	public ContextGuarderiaStrategy(GuarderiaStrategy guarderiaStrategy) {
		this.guarderiaStrategy = guarderiaStrategy;
	}
	
	//Setter --> Permite cambiar de estrategia
	public void setGuarderiaStrategy(GuarderiaStrategy guarderiaStrategy) {
		this.guarderiaStrategy = guarderiaStrategy;
	}
	
	//Metodos definidos en la estrategia --> Permite su ejecucion
	public void examinarNinyos() {
		this.guarderiaStrategy.examinarNinyos();
		
	}
	
	public void enviarFacturas() {
		this.guarderiaStrategy.enviarFacturas();
	}

	public void enviarResultados() {
		this.guarderiaStrategy.enviarResultados();
	}

}
