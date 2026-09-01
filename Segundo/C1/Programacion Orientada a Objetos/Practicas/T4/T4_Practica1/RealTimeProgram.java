package tema4.practica1;

public class RealTimeProgram extends Process{
	
	public RealTimeProgram(String name) {
		super(name, Process.DEFAULT_PRIORIDAD);
	}

	@Override
	public String toString() {
		return "RealTimeProgram [pid=" + super.pid + ", prioridad=" + super.prioridad + ", name=" + super.name + "]";
	}
}
