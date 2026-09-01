package tema4.practica1;

public class Process implements Comparable<Process>{
	
	public static final Integer DEFAULT_PRIORIDAD = 2;
	
	protected Integer pid;
	protected Integer prioridad;
	protected String name;
	
	private static Integer counter;
	
	static {
		Process.counter = 0;
	}
	
	public Process(String name) {
		this(name,Process.DEFAULT_PRIORIDAD);
	}
	
	public Process (String name, Integer prioridad) {
		this.name = name;
		this.prioridad = prioridad;
		this.pid = ++Process.counter;
	}

	public Integer getPid() {
		return pid;
	}

	public void setPid(Integer pid) {
		this.pid = pid;
	}

	public Integer getPrioridad() {
		return prioridad;
	}

	public void setPrioridad(Integer prioridad) {
		this.prioridad = prioridad;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public String toString() {
		return "Process [pid=" + pid + ", prioridad=" + prioridad + ", name=" + name + "]";
	}

	@Override
	public int compareTo(Process proceso) {
		return this.prioridad.compareTo(proceso.prioridad);
	}
	
}
