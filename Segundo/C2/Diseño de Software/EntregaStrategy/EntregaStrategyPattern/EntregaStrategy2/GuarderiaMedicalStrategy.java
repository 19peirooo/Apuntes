package EntregaStrategy2;

//Estrategia principal que contiene el nuevo metodo
public interface GuarderiaMedicalStrategy extends MedicalStrategy {
	public abstract void applyMedicalStrategy();
	public abstract void examinarNinyos();
	public abstract void enviarResultados();
	public abstract void enviarFacturas();
}
