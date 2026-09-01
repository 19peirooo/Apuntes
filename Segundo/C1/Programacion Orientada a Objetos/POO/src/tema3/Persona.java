package tema3;

public class Persona implements Comparable{
	//Atributos y Constantes
	public static final Integer DEFAULT_EDAD = 18;
	public static final String DEFAULT_NOMBRE = "Pablito Gonzalez";
	private String nombre;
	private Integer edad;
	
	
	//Constructores
	//Constructor Con 0 parametros
	public Persona() {
		this(Persona.DEFAULT_NOMBRE, Persona.DEFAULT_EDAD);
	}
	
	//Constructor con 1 parametro
	public Persona(String nombre) {
		this(nombre,Persona.DEFAULT_EDAD);
	}
	
	//Constructor Principal
	public Persona(String nombre, Integer edad) {
		this.nombre = nombre;
		this.edad = edad;
	}
	
	//Getters y Setters
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public Integer getEdad() {
		return edad;
	}
	public void setEdad(Integer edad) {
		this.edad = edad;
	}
	
	//Metodo toString
	public String toString() {
		return "Persona [nombre=" + nombre + ", edad=" + edad + "]";
	}

	//Compara 2 personas por su edad
	public int compareTo(Persona persona1) {
		int result = 0;
		if (this.edad >  persona1.edad) {
			result = 1;
		} else if (this.edad < persona1.edad) {
			result = -1;
		}
		
		return result;
	}
	
	//Compara dos personas y devuelve la que es mayor
	public static Persona compararEdad(Persona persona1,Persona persona2) {
		Persona personaMayor = persona2;
		if (persona1.esMayor(persona2)) {
			personaMayor = persona1;
		}
		
		return personaMayor;
	}
	
	//Comprueba si una persona es mayor que la otra
	public boolean esMayor(Persona persona2) {
		return this.compareTo(persona2) == 1;
	}
	//Comprueba si una persona es menor que la otra
	public boolean esMenor(Persona persona2) {
		return this.compareTo(persona2) == -1;
	}
	
	public static void main(String[] args) {
		Persona persona = new Persona();
		Persona persona2 = new Persona("Dieguin",25);
		
		System.out.println("Entre " + persona.getNombre() + " y " + persona2.getNombre() + " " + Persona.compararEdad(persona, persona2) + " es el mayor");
	}
	
	
}
