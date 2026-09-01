package tema4.practica1;

public class BackGroundProgram extends Process{
	
	public BackGroundProgram(String name) {
		super(name);
	}
	
	public String toString() {
		return "BackGroundProgram [pid=" + super.pid + ", prioridad=" + super.prioridad + ", name=" + super.name + "]";
	}
	
}
