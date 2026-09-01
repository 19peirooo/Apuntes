package tema4.practica1;

public class ProcesoNulo extends Process{
	
	public static final Integer DEFAULT_PRIORIDAD = 0;
	
	public ProcesoNulo() {
		super("Proceso Nulo", ProcesoNulo.DEFAULT_PRIORIDAD);
	}
	
}
