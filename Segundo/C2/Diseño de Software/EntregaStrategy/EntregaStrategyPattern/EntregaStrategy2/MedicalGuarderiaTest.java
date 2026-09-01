package EntregaStrategy2;

public class MedicalGuarderiaTest {
	public static void main(String[] args) {
		ContextMedicalGuarderiaStrategy guarderia = new ContextMedicalGuarderiaStrategy();
		System.out.println("Dia 15:");
		System.out.println("Dr. Wang: ");
		guarderia.setMedicalStrategy(new OculistaMedicalGuarderiaStrategy());
		guarderia.applyMedicalStrategy();
		
		System.out.println("Dia 28: ");
		System.out.println("Dr. Fong");
		guarderia.setMedicalStrategy(new LogopedaMedicalGuarderiaStrategy());
		guarderia.applyMedicalStrategy();
	}
}
