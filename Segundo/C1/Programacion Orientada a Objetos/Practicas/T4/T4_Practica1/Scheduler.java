package tema4.practica1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Scheduler {
	
	private List<Process> procesos;
	private Integer maxProcesos;
	
	public Scheduler(Integer maxProcesos) {
		this.maxProcesos = maxProcesos;
		this.procesos = new ArrayList<Process>();
	}
	
	public void add(Process p) {
		if (this.procesos.size() < this.maxProcesos) {
			procesos.add(p);
			Collections.sort(procesos);
		} else {
			System.out.println("No caben mas procesos");
		}
	}
	
	public Process next() {
		Process proceso = new ProcesoNulo();
		if (this.procesos.size() != 0) {
			proceso = procesos.remove(procesos.size() - 1);
		} else {
			System.out.println("Cola Vacia");
		}
		return proceso;
	}
	
	public static void main(String[] args) {
		Process programa1 = new Process("programaNormal", 2);
		Process programa2 = new RealTimeProgram("tiempoReal");
		Process programa3 = new BackGroundProgram("segundoPlano");
		Scheduler planificador = new Scheduler(3);
		
		planificador.add(programa1);
		planificador.add(programa2);
		planificador.add(programa3);
		
		System.out.println(planificador.next());
		System.out.println(planificador.next());
		planificador.add(programa3);
		System.out.println(planificador.next());
		planificador.add(programa2);
		System.out.println(planificador.next());
		System.out.println(planificador.next());
		//Se devuelve el proceso nulo en caso de no tener procesos
		System.out.println(planificador.next());
	}
}
