package EntregaStrategy;

public class GuarderiaTest {
	public static void main(String[] args) {
		ContextGuarderiaStrategy guarderia = new ContextGuarderiaStrategy();
		System.out.println("Dia 15:");
		System.out.println("Doctor Wang (Oculista): ");
		guarderia.setGuarderiaStrategy(new OculistaGuarderiaStrategy());
		guarderia.examinarNinyos();
		guarderia.enviarFacturas();
		guarderia.enviarResultados();
		
		System.out.println("Dia 28:");
		System.out.println("Doctor Fong (Logopeda): ");
		guarderia.setGuarderiaStrategy(new LogopedaGuarderiaStrategy());
		guarderia.examinarNinyos();
		guarderia.enviarFacturas();
		guarderia.enviarResultados();
		
	}
}
