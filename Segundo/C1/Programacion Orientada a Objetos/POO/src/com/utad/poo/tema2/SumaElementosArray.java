package com.utad.poo.tema2;

import java.util.Scanner;

public class SumaElementosArray {
	public static final int NUM_ELEMENTOS_POR_DEFECTO = 10;
	private int numeros [];
	private int numElementos;
	private int sumaElementos;
	
	public void sumarArray() {
		for (int i = 0; i < this.numElementos; i++) {
			this.sumaElementos += this.numeros[i];
		}
	}
	
	public void rellenarArray() {
		Scanner input = new Scanner(System.in);
		for (int i = 0; i < this.numElementos; i++) {
			System.out.print("Introduce un numero: ");
			this.numeros[i] = input.nextInt();
		}
		input.close();
	}
	
	public SumaElementosArray() {
		this(SumaElementosArray.NUM_ELEMENTOS_POR_DEFECTO);
	}
	
	
	
	public SumaElementosArray(int num) {
		this.numeros = new int[num];
		this.numElementos = num;
		this.rellenarArray();
		this.sumarArray();
		
	}

	public int getSumaElementos() {
		return this.sumaElementos;
	}
}