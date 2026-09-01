package tema3;

import java.util.Calendar; //Libreria Con los datos actuales para la fecha

public class Fecha implements Comparable<Fecha>{
	
	//Array que contiene todos los dias de la semana
	public static final String[] MESES = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	public static final Integer DEFAULT_DIA = java.util.Calendar.getInstance().get(Calendar.DAY_OF_MONTH);
	public static final Integer DEFAULT_MES = java.util.Calendar.getInstance().get(Calendar.MONTH)+1; //Añado 1 ya que en calendar, enero es el indice 0
	public static final Integer DEFAULT_ANYO = java.util.Calendar.getInstance().get(Calendar.YEAR);
	
	//Atributos
	private Integer dia;
	private Integer mes;
	private Integer anyo;
	
	//Constructores
	//Constructor 1 --> No se introducen atributos
	public Fecha() {
		this(DEFAULT_DIA,DEFAULT_MES, DEFAULT_ANYO);
	}
	
	//Constructor 2 --> El usuario introduce el dia como cadena
	public Fecha(String dia) {
		this(Integer.parseInt(dia),DEFAULT_MES,DEFAULT_ANYO);
	}
	
	//Constructor 3 --> El usuario introduce solo el dia
	public Fecha(Integer dia) {
		this(dia,DEFAULT_MES,DEFAULT_ANYO);
	}
	
	//Constructor 4 --> El usuario introduce el dia y el mes
	public Fecha(Integer dia, Integer mes) {
		this(dia,mes,DEFAULT_ANYO);
	}
	
	//Constructor Principal --> El usuario introduce todos los datos
	public Fecha(Integer dia, Integer mes, Integer anyo) {
		this.dia = dia;
		this.mes = mes;
		this.anyo = anyo;
	}
	
	
	//Getters y Setters de cada atributo
	public Integer getDia() {
		return dia;
	}

	public void setDia(Integer dia) {
		this.dia = dia;
	}

	public Integer getMes() {
		return mes;
	}

	public void setMes(Integer mes) {
		this.mes = mes;
	}

	public Integer getAnyo() {
		return anyo;
	}

	public void setAnyo(Integer anyo) {
		this.anyo = anyo;
	}
	
	//Convierte el valor numerico del mes a su nombre. Ej. 10 = Octubre
	public String mesANombre(Integer mes) {
		return MESES[mes-1];
	}
	
	//Metodo toString --> Imprime la informacion de la clase
	public String toString() {
		return "dia " + this.dia + " de " + this.mesANombre(this.mes) + " de " + this.anyo;
	}
	
	//Compara 2 fechas --> Si la fecha es mayor, devuelve 1. Si es menor, devuelve -1. Si son iguales, devuelve 0
	//Primero compara por años, luego compara por mes y finalmente por dia
	public int compareTo(Fecha f) {
		int comparacion = 0;
		if (this.anyo > f.getAnyo()) {
			comparacion = 1;
		}
		else if(this.anyo < f.getAnyo()) {
			comparacion = -1;
		}
		else if (this.mes > f.getMes()) {
			comparacion = 1;
		}
		else if (this.mes < f.getMes()) {
			comparacion = -1;
		}
		else if (this.dia > f.getDia()) {
			comparacion = 1;
		}
		else if (this.dia < f.getDia()) {
			comparacion = -1;
		}
		
		return comparacion;
	}
	
	//Ve cuantos dias tiene cada mes comprobando si el año es bisiesto
	public Integer diaMes(Integer anyo, Integer mes) {
		if (mes == 2 && anyo % 4 == 0 && (anyo % 100 != 0 || anyo % 400 == 0)) {
			return 29;
		}
		else if (mes == 2 && anyo % 4 != 0 || (anyo % 100 == 0 && anyo % 400 != 0)) {
			return 28;
		}
		else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
			return 31;
		}
		else {
			return 30;
		}
	}
	
	//Metodo sobrecargado de diaMes
	public Integer diaMes() {
		return diaMes(this.anyo,this.mes);
	}
	
	//Ve si dos fechas son iguales
	public boolean equals(Object o) {
		boolean iguales = false;
		
		if (o instanceof Fecha) {
			Fecha otraFecha = (Fecha)o; //Downcasting
			iguales = this.compareTo(otraFecha)==0;
		}
		return iguales;
	}
	
	//Compara las dos fechas y ve si esta es anterior  
	public boolean esAnterior(Fecha fecha2) {
		return this.compareTo(fecha2) == -1;
	}
	
	//Main
	public static void main(String[] args) {
		//Instanciacion de objetos
		//Fecha de hoy --> Imprime cuantos dias tiene este mes
		Fecha hoy = new Fecha();
		System.out.println(hoy + " cuyo mes tiene " + hoy.diaMes()+ " dias");
		
		//Dia 9 del mes actual --> En este caso octubre
		Fecha octubre9 = new Fecha(9);
		System.out.println(octubre9);
		
		//Diez de Octubre
		Fecha octubre10 = new Fecha(10,10);
		System.out.println(octubre10);
		
		//Diez de Octubre de 2003
		Fecha octubre102003 = new Fecha(10,10,2003);
		System.out.println(octubre102003);
		
		//Veo si el 9 de octubre de este año es anterior al 10 de ocutubre de este año. Si lo es, imprimo que los es.
		if (octubre9.esAnterior(octubre10)) {
			System.out.println("La fecha " + octubre9 + " es anterior a " + octubre10);
		}
	}
}
