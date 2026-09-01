package proyectoFinal;

import java.util.List;
import java.util.ArrayList;

public class Tipo implements Comparable<Tipo>{
	
	public static final Tipos DEFAULT_TIPO = Tipos.NORMAL;
	
	protected Tipos nombre;
	protected List<Tipos> debilidades;
	protected List<Tipos> fortalezas;
	
	public Tipo() {
		this(Tipo.DEFAULT_TIPO);
	}
	
	public Tipo (Tipos nombre) {
		this.nombre = nombre;
		this.debilidades = new ArrayList<Tipos>();
		this.fortalezas = new ArrayList<Tipos>();
	}

	public Tipos getNombre() {
		return this.nombre;
	}

	public void setNombre(Tipos nombre) {
		this.nombre = nombre;
	}

	public List<Tipos> getDebilidades() {
		return this.debilidades;
	}

	public void setDebilidades(List<Tipos> debilidades) {
		this.debilidades = debilidades;
	}

	public List<Tipos> getFortalezas() {
		return this.fortalezas;
	}

	public void setFortalezas(List<Tipos> fortalezas) {
		this.fortalezas = fortalezas;
	}
	
	
	
	@Override
	public String toString() {
		return "Tipo [nombre=" + this.nombre + ", debilidades=" + this.debilidades + ", fortalezas="
				+ this.fortalezas + "]";
	}

	public boolean esDebil(Tipo tipo) {
		return this.debilidades.contains(tipo.nombre);
	}
	
	public boolean esFuerte(Tipo tipo) {
		return this.fortalezas.contains(tipo.nombre);
	
	}
	
	@Override
	public int compareTo(Tipo tipo) {
		int comparacion = 0;
		
		if (this.esDebil(tipo)) {
			comparacion = -1;
		} else if (this.esFuerte(tipo)) {
			comparacion = 1;
		}
		return comparacion;
	}
	
}
