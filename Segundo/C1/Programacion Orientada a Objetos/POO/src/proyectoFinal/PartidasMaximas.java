package proyectoFinal;

import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

//Clase para crear partidas
public class PartidasMaximas {
	
	//Atributos
	private List<Tipo> tipos;
	private List<Habilidad> habilidades;
	private List<Personaje> personajes;
	private List<Jugador> jugadores;
	private List <Jugador> muertos;
	private Integer numHumanos;
	private Integer numMaquinas;
	private Boolean evolucionUsada;
	
	//Constructor de la partida
	public PartidasMaximas() {
		//Primero creo los tipos, luego las habilidades disponibles y finalmente los personajes
		this.tipos = this.crearTipos();
		this.habilidades = this.crearHabilidades();
		this.personajes = this.crearPersonajes();
		this.muertos = new ArrayList<Jugador>();
		
		this.numMaquinas = 0;
		boolean numJugadoresValido = false;
		
		//Pido a usuario en numero de jugadores humano y maquinas asegurandome que siempre haya un humano y por lo menos 2 jugadores
		System.out.print("Introduce numero jugadores humanos(Max 10): ");
		this.numHumanos = Utils.pedirNumero(1,10);
		while (!numJugadoresValido) {
			System.out.print("Introduce numero jugadores maquina(Max 10): ");
			this.numMaquinas = Utils.pedirNumero(0,10);
			if (this.numHumanos + this.numMaquinas < 2) {
				System.out.println("No hay suficiente jugadores para hacer una partida. Añade mas Jugadores Maquina");
			} else {
				numJugadoresValido = true;
			}
		}
		
		//Creo los jugadores y les asigno un orden aleatorio
		this.jugadores = this.crearJugadores();
		this.asignarPosiciones();
		Collections.sort(this.jugadores);
		
		this.evolucionUsada = false;
	}
	
	//Asigna posiciones aletorias a cada jugador
	private void asignarPosiciones() {
		List<Integer> posicionesOcupadas = new ArrayList<Integer>();
		Integer numAleatorio = 0;
		for (int i = 0; i < this.jugadores.size(); i++) {
			do {
				numAleatorio = Utils.generarNumeroAleatorio(this.jugadores.size());
			} while(posicionesOcupadas.contains(numAleatorio));
			posicionesOcupadas.add(numAleatorio);
			this.jugadores.get(i).setOrdenEnRonda(numAleatorio);
		}
	}
	
	//Crea cada tipo junto sus debilidades y fortalezas
	private List<Tipo> crearTipos() {
		//Creo todos los tipos
		//Añado sus debilidades y fortalezas
		
		Tipo normal = new Tipo(Tipos.NORMAL);
		normal.debilidades.addAll(List.of(Tipos.LUCHA,Tipos.ACERO));
		normal.fortalezas.add(Tipos.PLANTA);
		
		Tipo agua = new Tipo(Tipos.AGUA);
		agua.debilidades.addAll(List.of(Tipos.PLANTA,Tipos.ELECTRICO));
		agua.fortalezas.addAll(List.of(Tipos.FUEGO,Tipos.ROCA));
		
		Tipo fuego = new Tipo(Tipos.FUEGO);
		fuego.debilidades.addAll(List.of(Tipos.AGUA,Tipos.AIRE));
		fuego.fortalezas.addAll(List.of(Tipos.PLANTA,Tipos.ACERO));
		
		Tipo planta = new Tipo(Tipos.PLANTA);
		planta.debilidades.addAll(List.of(Tipos.FUEGO,Tipos.ACERO,Tipos.NORMAL));
		planta.fortalezas.addAll(List.of(Tipos.AGUA,Tipos.ROCA,Tipos.AIRE));
		
		Tipo roca = new Tipo(Tipos.ROCA);
		roca.debilidades.addAll(List.of(Tipos.ACERO,Tipos.PLANTA,Tipos.AGUA));
		roca.fortalezas.addAll(List.of(Tipos.LUCHA,Tipos.ELECTRICO,Tipos.AIRE));
		
		Tipo acero = new Tipo(Tipos.ACERO);
		acero.debilidades.addAll(List.of(Tipos.FUEGO,Tipos.ELECTRICO,Tipos.LUCHA));
		acero.fortalezas.addAll(List.of(Tipos.PLANTA,Tipos.ROCA, Tipos.NORMAL));
		
		Tipo electrico = new Tipo(Tipos.ELECTRICO);
		electrico.debilidades.addAll(List.of(Tipos.ROCA,Tipos.AIRE));
		electrico.fortalezas.addAll(List.of(Tipos.AGUA,Tipos.ACERO));
		
		Tipo aire = new Tipo(Tipos.AIRE);
		aire.debilidades.addAll(List.of(Tipos.ROCA,Tipos.ELECTRICO));
		aire.fortalezas.addAll(List.of(Tipos.PLANTA,Tipos.LUCHA));
		
		Tipo lucha = new Tipo(Tipos.LUCHA);
		lucha.debilidades.addAll(List.of(Tipos.ROCA,Tipos.AIRE));
		lucha.fortalezas.addAll(List.of(Tipos.ACERO,Tipos.NORMAL));
		
		List<Tipo> tipos = new ArrayList<Tipo>(List.of(normal,agua,fuego,planta,roca,acero,electrico,aire,lucha));
		
		return tipos;
		
	}
	
	//Creo todas las habilidades
	private List<Habilidad> crearHabilidades() {
		Habilidad danyox3 = new HabilidadDanyo("Dañox3",30,3.0);
		Habilidad danyox2 = new HabilidadDanyo("Dañox2",45,2.0);
		Habilidad danyox01 = new HabilidadDanyo("Dañox0.1",50,0.1);
		Habilidad saltoTurno = new HabilidadTurno("SaltaTurno", 35);
		Habilidad revivir = new HabilidadRevive("Revivir",25);
		Habilidad resistencia2 = new HabilidadResistencia("Resistencia x2",60,2.0);
		Habilidad resistencia05 = new HabilidadResistencia("Resistencia x0.5",50,0.5);
		Habilidad curarse = new HabilidadSalud("Sanacion",50,2.0);
		Habilidad paralizacion = new HabilidadTurno("Paralización",20);
		List<Habilidad> habilidades = new ArrayList<Habilidad>(List.of(danyox3,danyox2,danyox01,resistencia05,saltoTurno,revivir,resistencia2,curarse,paralizacion));

		return habilidades;
	}
	
	//Creo los jugadores en funcion de el numero de humanos y maquinas
	private List<Jugador> crearJugadores() {
		
		List<Jugador> jugadores = new ArrayList<Jugador>();
		String nombre = "";
		Personaje p = null;
		
		for (int i = 0; i < this.numHumanos; i++) {
			System.out.println("Introduce nombre del Jugador " + (i+1));
			nombre = Utils.pedirCadena();
			System.out.println("Introduce el numero del personaje que quieras jugar: ");
			for (int j = 0; j < this.personajes.size(); j++) {
				System.out.println(j +  " --> " + this.personajes.get(j));
			}
			p = this.personajes.get(Utils.pedirNumero(0, 8));
			jugadores.add(new Humano(nombre, p));
		}
		
		for (int i = 0; i < this.numMaquinas; i++) {
			nombre = Maquina.DEFAULT_NOMBRE+Integer.toString(i+1);
			p = this.personajes.get((int)(Math.random() * 9));
			jugadores.add(new Maquina(nombre,p));
		}
		
		return jugadores;
	}
	
	//Creo todos los tipos de Personajes --> Asigno tipo aleatorio y no se pueden repetir. Si se puede repetir habilidades
	private List<Personaje> crearPersonajes() {
		List<Personaje> personajes = new ArrayList<Personaje>();
	
		int posTipos=0;
		int posHab=0;	
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje camaleon = new Camaleon(this.tipos.get(posTipos), this.habilidades.get(posHab));
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje druida = new Druida(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		
		Personaje golem = new Golem(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje guerrero = new Guerrero(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje mago = new Mago(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje topo = new Topo(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje sirena = new Sirena(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje thor = new Thor(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		posTipos = Utils.generarNumeroAleatorio(this.tipos.size());
		posHab = Utils.generarNumeroAleatorio(this.habilidades.size());
		
		Personaje dragon = new Dragon(this.tipos.get(posTipos), this.habilidades.get(posHab)); 
		this.tipos.remove(posTipos);
		
		personajes.addAll(List.of(camaleon,druida,golem,guerrero,mago,topo,sirena,thor,dragon));
		return personajes;
	}
	
	//Simula una ronda
	public void jugarRonda(Integer numRonda) {
		List <Jugador> jugadoresMuertosRonda = new ArrayList<Jugador>();
		//Cicla por todos lo jugadores vivos
		for (Jugador jugador : this.jugadores) {
			//Imprime sus detalles
			System.out.println("Turno de " + jugador.nombre);
			System.out.println("Estado: " + jugador.personaje.estadoPersonaje);
			System.out.println(jugador.personaje.imprimirDetalles());
			//Comprueba si esta quemado el personaje y si lo esta le quita vida
			if (jugador.personaje.estadoPersonaje == Estados.QUEMADO) {
				jugador.personaje.salud -= 5;
				if (jugador.personaje.salud < 0) {
					jugador.personaje.salud = 0;
				}
				System.out.println("Te has quemado.\n Nueva Salud: " + jugador.personaje.salud);
				//Permite salir de la quemadura
				if (Utils.generarNumeroAleatorio(4) == 1) {
					jugador.personaje.estadoPersonaje = Estados.NORMAL;
					System.out.println("Ya no estas quemado");
				}
				//Comprueba si la quemadura a matado al jugador permitiendole revivir
				jugador.comprobarMuerto();
			}
			
			//Solo pueden usar su turno los jugadores que lo tengan permitido
			if (jugador.turnoActivo) {
				jugador.turno(numRonda,this.jugadores,this.habilidades, this.evolucionUsada);
				//Comprueba si ha habido una evolucion
				for (Jugador j : this.jugadores) {
					if (j.getPersonaje().getTipo().getNombre() == Tipos.ETEREO){
						this.evolucionUsada = true;
					}
				}
			//Intenta salir del bloqueo de turno si esta bloqueado
			} else if (!jugador.turnoActivo && jugador.personaje.estadoPersonaje != Estados.MUERTO){
				if (Utils.generarNumeroAleatorio(4) == 1) {
					jugador.turnoActivo = true;
					System.out.println("Ya no estas saltado. Podras jugar al siguiente turno");
				}
			}
		}
		
		//Busca que personajes han muerto es ronda y los elimina
		for (Jugador jugador : this.jugadores) {
		    if (jugador.personaje.getEstadoPersonaje() == Estados.MUERTO) {
		    	jugador.setPosPartida(this.jugadores.size());
		        this.muertos.add(jugador);
		    	jugadoresMuertosRonda.add(jugador);
		    }
		}
		this.jugadores.removeAll(jugadoresMuertosRonda);
	}
	
	//Simula todas las rondas hasta que solo quede un jugador
	public void jugarPartida() {
		Integer numRonda = 0;
		while (this.jugadores.size() != 1) {
			System.out.println("Ronda: " + numRonda);
			this.jugarRonda(numRonda);
			numRonda++;
		}
		this.jugadores.get(0).setPosPartida(1);
		this.muertos.add(this.jugadores.get(0));
		
		this.imprimirResultados();
		
	}
	
	//Imprime los resultados de la partida
	private void imprimirResultados() {
		System.out.println("Ganador: " + this.jugadores.get(0).imprimirDetalles());
		
		System.out.println("Resultados: ");
		for (Jugador jugador: this.muertos) {
			System.out.println(jugador.imprimirDetalles());
		}
		
	}
	
	//Se juega la partida
	public static void main(String[] args) {
		PartidasMaximas p = new PartidasMaximas();
		p.jugarPartida();
	}
}





