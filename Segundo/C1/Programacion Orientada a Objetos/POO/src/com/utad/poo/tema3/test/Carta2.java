package com.utad.poo.tema3.test;

import java.util.List;
public class Carta2 implements Comparable<Carta2>{
		
		public static Integer MIN_NUM = 1;
		public static Integer MAX_NUM = 7;
		public static Integer MIN_NUM_FIG = 10;
		public static Integer MAX_NUM_FIG = 12;
		public static Integer DEFAULT_NUMERO = 1;
		public static Palo2 DEFAULT_PALO = Palo2.OROS;
		public static Integer DEFAULT_POS = 0;
		
		private Integer numero;
		private Palo2 palo;
		private Integer posicionMazo;
		
		public Carta2() {
			this(Carta2.DEFAULT_NUMERO);
		}
		
		public Carta2(Integer numero) {
			this(numero,Carta2.DEFAULT_PALO);
		}
		
		public Carta2 (Integer numero, Palo2 palo) {
			this(numero,palo,Carta2.DEFAULT_POS);
		}
		
		public Carta2(Integer numero, Palo2 palo, Integer posicionMazo) {
			this.numero = numero;
			this.palo = palo;
			this.posicionMazo = posicionMazo;
		}

		
		public Integer getNumero() {
			return this.numero;
		}

		public void setNumero(Integer numero) {
			this.numero = numero;
		}

		public Palo2 getPalo() {
			return this.palo;
		}

		public void setPalo(Palo2 palo) {
			this.palo = palo;
		}

		public Integer getPosicionMazo() {
			return this.posicionMazo;
		}

		public void setPosicionMazo(Integer posicionMazo) {
			this.posicionMazo = posicionMazo;
		}
		
		public String toString() {
			return "Carta [numero=" + numero + ", palo=" + palo + ", posicionEnMazo=" + posicionMazo + "]";
		}

		public int compareTo(Carta2 carta) {
			int res = 0;
			
			if (this.posicionMazo > carta.posicionMazo) {
				res = 1;
			} else if (this.posicionMazo < carta.posicionMazo) {
				res = -1;
			}
			return res;
		}
		
		public static Integer cartaMasAlta (List<Carta2> cartas) {
			Integer indiceCartaAlta=0;
			
			if (cartas == null || cartas.isEmpty()) {
				indiceCartaAlta = -1;
			} else {
				for (int i = 0; i < cartas.size(); i++) {
					if (cartas.get(i).getNumero() > cartas.get(indiceCartaAlta).getNumero()) {
						indiceCartaAlta = i;
					}
				}
			}
			
			return indiceCartaAlta;
		}
	}
